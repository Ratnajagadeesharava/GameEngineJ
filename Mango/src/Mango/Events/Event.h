#pragma once

#include "../Core.h"

namespace Mango {
	enum EventType {
		MouseClick,MouseScroll,MouseMove,MouseRelease,
		KeyPress,KeyRelease
	};
	class MG_API Event {
		friend class EventDispatcher;
	public:

		virtual const char* GetName() const = 0;
		
	};
	class EventDispatcher {

	};
}