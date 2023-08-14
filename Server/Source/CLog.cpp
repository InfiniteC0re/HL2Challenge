#include "CLog.h"

#include <spdlog/sinks/stdout_color_sinks.h>

void CLog::Create()
{
	spdlog::set_pattern("[%H:%M:%S] [%n] %v");

	s_CoreLogger = spdlog::stdout_color_mt("Core");
	s_CoreLogger->set_level(spdlog::level::level_enum::trace);
}
