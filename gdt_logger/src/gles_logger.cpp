

#include <GLES3/gl3.h>
#include <hook/hook.hpp>

#include "spdlog/spdlog.h"

// TODO: Let's try without static f variables to see how much it affects
// performace.

// ------------------------- WARN ----------------------------------//
// WARN Level
// glClear glBlitFrameBuffer glInvalidateFramebuffer glDrawArrays glDrawElements

GL_APICALL void GL_APIENTRY glClear(GLbitfield mask) {
  static auto f = hook_load(glClear);
  auto dur = hook_invoke_d(f, mask);
  spdlog::warn("[{1:>9}ns] {0}", hook_format(glClear, mask), dur.count());
  return;
}

GL_APICALL void GL_APIENTRY glBlitFramebuffer(GLint srcX0, GLint srcY0,
					      GLint srcX1, GLint srcY1,
					      GLint dstX0, GLint dstY0,
					      GLint dstX1, GLint dstY1,
					      GLbitfield mask, GLenum filter) {
  static auto f = hook_load(glBlitFramebuffer);
  auto dur = hook_invoke_d(f, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1,
			   dstY1, mask, filter);
  spdlog::warn("[{1:>9}ns] {0}",
	       hook_format(glBlitFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0,
			   dstY0, dstX1, dstY1, mask, filter),
	       dur.count());
  return;
}

GL_APICALL void GL_APIENTRY glInvalidateFramebuffer(GLenum target,
						    GLsizei numAttachments,
						    const GLenum *attachments) {
  static auto f = hook_load(glInvalidateFramebuffer);
  auto dur = hook_invoke_d(f, target, numAttachments, attachments);
  spdlog::warn("[{1:>9}ns] {0}", hook_format(glInvalidateFramebuffer, target,
					     numAttachments, attachments),
	       dur.count());
  return;
}

GL_APICALL void GL_APIENTRY glDrawArrays(GLenum mode, GLint first,
					 GLsizei count) {
  static auto f = hook_load(glDrawArrays);
  auto dur = hook_invoke_d(f, mode, first, count);
  spdlog::warn("[{1:>9}ns] {0}", hook_format(glDrawArrays, mode, first, count),
	       dur.count());
  return;
}
GL_APICALL void GL_APIENTRY glDrawElements(GLenum mode, GLsizei count,
					   GLenum type, const void *indices) {
  static auto f = hook_load(glDrawElements);
  auto dur = hook_invoke_d(f, mode, count, type, indices);
  spdlog::warn("[{1:>9}ns] {0}",
	       hook_format(glDrawElements, mode, count, type, indices),
	       dur.count());
  return;
}

GL_APICALL void GL_APIENTRY glBindFramebuffer(GLenum target,
					      GLuint framebuffer) {
  static auto f = hook_load(glBindFramebuffer);
  auto dur = hook_invoke_d(f, target, framebuffer);
  spdlog::warn("[{1:>9}ns] {0}",
	       hook_format(glBindFramebuffer, target, framebuffer),
	       dur.count());
  return;
}

/// ------------- TRACE LEVEL -------------------------------//

GL_APICALL void GL_APIENTRY glBindBuffer(GLenum target, GLuint buffer) {
  // XXX: We have a static f for its performace.
  static auto f = hook_load(glBindBuffer);
  auto dur = hook_invoke_d(f, target, buffer);
  spdlog::trace("[{1:>9}ns] {0}", hook_format(glBindBuffer, target, buffer),
		dur.count());
  return;
}

GL_APICALL void GL_APIENTRY glBindTexture(GLenum target, GLuint texture) {
  static auto f = hook_load(glBindTexture);
  auto dur = hook_invoke_d(f, target, texture);
  spdlog::trace("[{1:>9}ns] {0}", hook_format(glBindTexture, target, texture),
		dur.count());
  return;
}

GL_APICALL void GL_APIENTRY glGenBuffers(GLsizei n, GLuint *buffers) {
  static auto f = hook_load(glGenBuffers);
  auto dur = hook_invoke_d(f, n, buffers);
  spdlog::trace("[{1:>9}ns] {0}", hook_format(glGenBuffers, n, buffers),
		dur.count());
  return;
}
