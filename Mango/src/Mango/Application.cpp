#include "Application.h"
#include <iostream>
namespace Mango {
	Application::Application()
	{
	}
	Application::~Application() {

	}
	void Application::Run()
	{
		std::cout << "Mango is Running" << std::endl;
	}
}
