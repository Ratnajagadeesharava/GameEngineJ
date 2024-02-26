#pragma once
#include "TypeDefs.h"
namespace engine{
	enum  log_level {

		//fatal and error should be enabled for every mode
		LOG_FATAL =0,
		LOG_ERROR=1,
		
		LOG_WARN=2,
		LOG_INFO=3,

		//only in debug build
		LOG_DEBUG=4,
		LOG_TRACE=5

	};
	class logger
	{
		public:
			bool initialize_logging();
			void shutdown_logging();

			ENGINE_API static void log_out(log_level level, const char* message,...);
			/*
			#define PRINT_VALUES(...) std::cout << #__VA_ARGS__ << std::endl

			int main() {
				PRINT_VALUES(1, 2, "hello", 3.14);
				return 0;
			}*/
		#define ENGINE_FATAL(message,...) log_out(LOG_FATAL,__VA_ARGS__);
		#define ENGINE_ERROR(message,...) log_out(LOG_ERROR,__VA_ARGS__);
	};
}

