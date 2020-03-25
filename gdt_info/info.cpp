#include <sstream>
#include <iostream>
#include <vector>
#include <EGL/egl.h>
#include <spdlog/spdlog.h>

std::vector<std::string> split(const char *str) {
  // read file line by line
  std::vector<std::string> strs;
  std::istringstream f(str);
  std::string s;
  while (std::getline(f, s, ' ')) {
    strs.push_back(s);
  }
  return strs;
}

int main() {
  auto display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
  if (display == EGL_NO_DISPLAY) {
    spdlog::error("failed to get display");
    return -1;
  }
  auto success = eglInitialize(display, nullptr, nullptr);
  if (!success) {
    spdlog::error("failed to init egl");
    return -1;
  }

  spdlog::info("GLES Debug Toolkit - Information");
  spdlog::info("--------------");
  spdlog::info("Version: {} - {}", eglQueryString(display, EGL_CLIENT_APIS),
	       eglQueryString(display, EGL_VERSION));

  spdlog::info("--------------");
  spdlog::info("Extensions:  ");
  auto exts = split(eglQueryString(display, EGL_EXTENSIONS));
  for (auto ext : exts) {
    spdlog::info("{}", ext);
  }
}

