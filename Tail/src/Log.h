#pragma once

#include <memory>

#include <spdlog/spdlog.h>

class Log
{
public:
	static void Init();

	inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }

private:
	static std::shared_ptr<spdlog::logger> s_Logger;
};

#define TAIL_TRACE(...) Log::GetLogger()->trace(__VA_ARGS__)
#define TAIL_INFO(...) Log::GetLogger()->info(__VA_ARGS__)
#define TAIL_WARN(...) Log::GetLogger()->warn(__VA_ARGS__)
#define TAIL_ERROR(...) Log::GetLogger()->error(__VA_ARGS__)
#define TAIL_CRITICAL(...) Log::GetLogger()->critical(__VA_ARGS__)


#define TAIL_LEVEL(a) Log::GetLogger->set_level(a)
#define TAIL_LEVEL_TRACE spdlog::level::trace
#define TAIL_LEVEL_INFO spdlog::level::info
#define TAIL_LEVEL_WARN spdlog::level::warn
#define TAIL_LEVEL_ERROR spdlog::level::error
#define TAIL_LEVEL_CRITICAL spdlog::level::critical