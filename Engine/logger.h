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
		bool initialize_logging();
		void shutdown_logging();

		ENGINE_API void log_output(log_level level, const char* message, ...);

		#define ENGINE_FATAL(message,...) log_output(LOG_FATAL,__VA_ARGS__);
		#define ENGINE_ERROR(message,...) log_output(LOG_ERROR,__VA_ARGS__);
		#ifdef INFO_MESSAGES
		#define ENGINE_INFO(message,...) log_output(LOG_ERROR,__VA_ARGS__);
		#endif 

		#ifdef DEBUG_MODE
		#define ENGINE_TRACE(message,...) log_output(LOG_ERROR,__VA_ARGS__);
		#endif

		#ifdef WARNINGS
		#define ENGINE_WARN(message,...) log_output(LOG_ERROR,__VA_ARGS__);
		#endif 

		
	
}

