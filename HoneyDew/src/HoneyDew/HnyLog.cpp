#include "HnyLog.h"

namespace Honey {
	
	std::shared_ptr<spdlog::logger> HnyLog::s_CoreLogger;
	std::shared_ptr<spdlog::logger> HnyLog::s_ClientLogger;
	
	void HnyLog::Init() {
		//spdlog::set_pattern("");

		s_CoreLogger = spdlog::stdout_color_mt("HONEY");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}