#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

std::shared_ptr<spdlog::logger> Log::s_Logger;

void Log::Init() {
	std::vector<spdlog::sink_ptr> sinks;
	sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
	sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("latest.log"));
	s_Logger = std::make_shared<spdlog::logger>("Main", sinks.begin(), sinks.end());
	s_Logger->set_level(spdlog::level::trace);
	s_Logger->set_pattern("(%H:%M:%S.%e) %^[%l]%$ %v"); // Example: "(13:46:32.465) [error] File not found
}