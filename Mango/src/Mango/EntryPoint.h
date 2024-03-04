#pragma once
#include "Core.h"
#include "Application.h"
#ifdef  MG_PLATFORM_WINDOWS


namespace Mango {
	extern Application* CreateNewApplication();
	int main() {
		auto app = CreateNewApplication();
		app->Run();
		delete app;
		return 0;
	}
}
#endif //  MG_PLATFORM_WINDOWS