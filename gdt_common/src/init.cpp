
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

__attribute__((constructor)) void init(void) {
  spdlog::set_level(spdlog::level::debug); // Set global log level to debug
  // change log pattern
  spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$][thread %t] %v");

  auto file_logger = spdlog::basic_logger_mt("egl", "log.txt");
  spdlog::set_default_logger(file_logger);

	spdlog::info("gdt initialized");
}
