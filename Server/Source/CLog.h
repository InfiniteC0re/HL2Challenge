#pragma once
#include <spdlog/spdlog.h>
#include <memory>

class CLog
{
public:
	static void Create();

	static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };

private:
	inline static std::shared_ptr<spdlog::logger> s_CoreLogger;
};

// App log macros
#define LOG_INFO(...) CLog::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_WARN(...) CLog::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) CLog::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_TRACE(...) CLog::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CRITICAL(...) CLog::GetCoreLogger()->critical(__VA_ARGS__)
#define ASSERT(X) if (!(X)) { LOG_ERROR("ASSERT: {0} ({1}, at line {2})", #X, __FILE__, __LINE__); __debugbreak(); }
