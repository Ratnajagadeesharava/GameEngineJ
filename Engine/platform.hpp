#pragma once
#include "TypeDefs.h"
namespace engine {
	class platform_state {
	public:
		void* internal_state;
	
	};
	
	
	char platform_startup(
		platform_state* platformSate, 
		signed int  x,
		signed int y,
		unsigned int height,
		unsigned int width
	);
	char platfom_shutdown(platform_state* platformState);

	 char platform_pump_messages(platform_state* platformState
	);
}

