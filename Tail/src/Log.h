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
#define TAIL_FATAL(...) Log::GetLogger()->fatal(__VA_ARGS__)
