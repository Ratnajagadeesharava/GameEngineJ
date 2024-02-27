#include "pch.h"
#include "logger.h"
#include <vector>
#include <cstdarg>

bool engine::initialize_logging()
{
    //TODO: create a log file
	return false;
}

void engine::shutdown_logging()
{
    //TODO: save the log file
}

void engine::log_output(log_level level, const char* message, ...)
{
	char output_message[3200];

    // Declare va_list variable
    va_list arg_ptr;

    // Initialize arg_ptr to point to the first variable argument
    va_start(arg_ptr, message);

    // Format the message using vsnprintf
    std::vsnprintf(output_message, 32000, message, arg_ptr);

    // Clean up the variable argument list
    va_end(arg_ptr);
    std::cout << output_message << std::endl;
}
