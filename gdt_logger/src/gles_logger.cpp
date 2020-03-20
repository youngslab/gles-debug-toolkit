

#include <GLES3/gl3.h>
#include <hook/hook.hpp>
#include <iostream>

#include "spdlog/spdlog.h"

void glBindBuffer(GLenum target, GLuint buffer) {
  static auto f = hook_load(glBindBuffer);
  spdlog::info("{}", hook_format(glBindBuffer, target, buffer));
  return hook_invoke(f, target, buffer);
}

void glBindTexture(GLenum target, GLuint texture) {
  static auto f = hook_load(glBindTexture);
  spdlog::info("{}", hook_format(glBindTexture, target, texture));
  return hook_invoke(f, target, texture);
}

void glGenBuffers(GLsizei n, GLuint *buffers) {
  static auto f = hook_load(glGenBuffers);
  spdlog::info("{}", hook_format(glGenBuffers, n, buffers));
  return hook_invoke(f, n, buffers);
}
