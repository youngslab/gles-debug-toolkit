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
  if (display = EGL_NO_DISPLAY) {
    return -1;
  }
  auto success = eglInitialize(display, nullptr, nullptr);

  spdlog::info("** gdt-info **");
  spdlog::info("--------------");
  spdlog::info("  extensions  ");
  spdlog::info("--------------");
  auto exts = split(eglQueryString(display, EGL_EXTENSIONS));
  for (auto ext : exts) {
    spdlog::info(" - {}", ext);
  }
  spdlog::info("--------------");
}

