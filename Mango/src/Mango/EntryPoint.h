#pragma once
#include "Core.h"
#include "Application.h"
#include "Logger.h"
#ifdef  MG_PLATFORM_WINDOWS


namespace Mango {
	extern Application* CreateNewApplication();
	
}
int main() {
	Mango::Logger::Init();

	//testing logger
	MG_CORE_WARN("testing trace logger");
	MG_CLIENT_TRACE("testing trace logger");
	auto app = Mango::CreateNewApplication();
	app->Run();
	delete app;
	return 0;
}
#endif //  MG_PLATFORM_WINDOWS