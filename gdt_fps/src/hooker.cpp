
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <spdlog/spdlog.h>
#include <chrono>
#include <hook/hook.hpp>
#include <iostream>
#include <map>
#include <set>

#include "ascii.hpp"
#include "shader.h"

std::map<EGLSurface, std::pair<GLint, GLint>> g_sizes;

using tp = std::chrono::time_point<std::chrono::high_resolution_clock>;
static GLuint g_curr_program = 0;

GL_APICALL void GL_APIENTRY glUseProgram(GLuint program) {
  static auto f = hook_load(glUseProgram);
  g_curr_program = program;
  hook_invoke(f, program);
  return;
};

EGLBoolean eglSwapBuffers(EGLDisplay display, EGLSurface surface) {
  static std::map<EGLSurface, ascii::renderer> renderers;
  static std::map<EGLSurface, tp> time_points;
  static std::map<EGLSurface, float> fpses;
  static std::map<EGLSurface, unsigned int> frames;
  static auto f = hook_load(eglSwapBuffers);

  auto prev = time_points.find(surface);
  if (prev == time_points.end()) {
    time_points[surface] = std::chrono::high_resolution_clock::now();
    fpses[surface] = 0;
    frames[surface] = 0;
    return hook_invoke(f, display, surface);
  }

  //// update current
  auto curr = std::chrono::high_resolution_clock::now();
  frames[surface]++;

  //// get fps
  //// TODO: calculate fps
  auto dur = curr - prev->second;
  // std::cout <<
  // std::chrono::duration_cast<std::chrono::nanoseconds>(dur).count()
  //<< "ns\n";

  auto cnt = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
  if (cnt >= 1000) {
    fpses[surface] =
	(float)frames[surface] * (float)1000 / (float)cnt;  // per seconds
    frames[surface] = 0;
    time_points[surface] = curr;
  }

  // auto fps = 60.0f;

  auto prev_program = g_curr_program;
  //// 1. get renderer
  auto renderer = renderers.find(surface);
  if (renderer == renderers.end()) {
    // TODO: query width and height
    auto width = 0;
    auto height = 0;
    eglQuerySurface(display, surface, EGL_WIDTH, &width);
    eglQuerySurface(display, surface, EGL_HEIGHT, &height);
    g_sizes[surface] = {width, height};
    // TODO: simplify shader code
    Shader shader("text.vs", "text.fs");
    auto r = ascii::init_renderer(shader.ID, width, height);
    renderers[surface] = r;
    renderer = renderers.find(surface);
  }

  // 3. render fps
  renderer->second.render(fmt::format("{:>10.3f} fps", fpses[surface]), 10,
			  std::get<1>(g_sizes[surface]) - 30, 0.4,
			  glm::vec3(0.3, 0.7f, 0.9f));
  glUseProgram(prev_program);

  return hook_invoke(f, display, surface);
}

