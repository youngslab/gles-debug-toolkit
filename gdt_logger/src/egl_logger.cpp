
#include <EGL/egl.h>
#include <hook/hook.hpp>
#include <iostream>

#include <spdlog/spdlog.h>

// log level: warn -> info(*) -> debug -> trace

EGLBoolean eglSwapBuffers(EGLDisplay display, EGLSurface surface) {
  static auto f = hook_load(eglSwapBuffers);
  auto[res, dur] = hook_invoke_d(f, display, surface);
  spdlog::level::level_enum a;
  spdlog::warn("[{1:>9}ns] {0}", hook_format(eglSwapBuffers, display, surface),
	       dur.count());
  return res;
}

