#pragma once
#include "Core.h"
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
//necessary readings
//smartpointers --> https://www.youtube.com/watch?v=e2LMAgoqY_k
namespace Mango {
	class MG_API Logger
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger> GetCoreLogger() {
			return s_CoreLogger;
		}
		inline static std::shared_ptr<spdlog::logger> GetClientLogger() {
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define MG_CORE_TRACE(...) Mango::Logger::GetCoreLogger()->trace(__VA_ARGS__)

#define MG_CORE_INFO(...) Mango::Logger::GetCoreLogger()->info(__VA_ARGS__)

#define MG_CORE_WARN(...) Mango::Logger::GetCoreLogger()->warn(__VA_ARGS__)

#define MG_CORE_FATAL(...) Mango::Logger::GetCoreLogger()->critical(__VA_ARGS__)

#define MG_CORE_ERROR(...) Mango::Logger::GetCoreLogger()->error(__VA_ARGS__)


#define MG_CLIENT_TRACE(...) Mango::Logger::GetClientLogger()->trace(__VA_ARGS__)

#define MG_CLIENT_INFO(...) Mango::Logger::GetClientLogger()->info(__VA_ARGS__)

#define MG_CLIENT_WARN(...) Mango::Logger::GetClientLogger()->warn(__VA_ARGS__)

#define MG_CLIENT_FATAL(...) Mango::Logger::GetClientLogger()->critical(__VA_ARGS__)

#define MG_CLIENT_ERROR(...) Mango::Logger::GetClientLogger()->error(__VA_ARGS__)