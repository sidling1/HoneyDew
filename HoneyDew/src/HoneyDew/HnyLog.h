#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

// Wrapper for using spdlog
namespace Honey
{
	class HNY_API HnyLog
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define HNY_CORE_TRACE(...) ::Honey::HnyLog::GetCoreLogger()->trace(__VA_ARGS__)
#define HNY_CORE_ERROR(...) ::Honey::HnyLog::GetCoreLogger()->error(__VA_ARGS__)
#define HNY_CORE_WARN(...) ::Honey::HnyLog::GetCoreLogger()->warn(__VA_ARGS__)
#define HNY_CORE_INFO(...) ::Honey::HnyLog::GetCoreLogger()->info(__VA_ARGS__)
#define HNY_CORE_FATAL(...) ::Honey::HnyLog::GetCoreLogger()->fatal(__VA_ARGS__)


//Client log macros
#define HNY_CLIENT_TRACE(...) ::Honey::HnyLog::GetClientLogger()->trace(__VA_ARGS__)
#define HNY_CLIENT_ERROR(...) ::Honey::HnyLog::GetClientLogger()->error(__VA_ARGS__)
#define HNY_CLIENT_WARN(...) ::Honey::HnyLog::GetClientLogger()->warn(__VA_ARGS__)
#define HNY_CLIENT_INFO(...) ::Honey::HnyLog::GetClientLogger()->info(__VA_ARGS__)
#define HNY_CLIENT_FATAL(...) ::Honey::HnyLog::GetClientLogger()->fatal(__VA_ARGS__)

