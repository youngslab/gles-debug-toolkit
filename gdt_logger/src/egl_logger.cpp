
#include <EGL/egl.h>
#include <hook/hook.hpp>
#include <iostream>

#include <spdlog/spdlog.h>

EGLBoolean eglSwapBuffers(EGLDisplay display, EGLSurface surface) {
  static auto f = hook_load(eglSwapBuffers);
  spdlog::info("{}", hook_format(eglSwapBuffers, display, surface));
  return hook_invoke(f, display, surface);
}

