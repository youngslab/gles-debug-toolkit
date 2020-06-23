
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

__attribute__((constructor)) void init(void) {
  spdlog::set_level(spdlog::level::info);  // Set global log level to debug
  // change log pattern
  spdlog::set_pattern("[%H:%M:%S:%F] [%n] [tid:%t] %v");
  // [15:33:12 +00:00] [egl] [---I---][thread 3603] glBindBuffer(34962, 1)

  auto file_logger = spdlog::basic_logger_mt("egl", "log.txt");
  spdlog::set_default_logger(file_logger);

  spdlog::info("gdt initialized");
}
