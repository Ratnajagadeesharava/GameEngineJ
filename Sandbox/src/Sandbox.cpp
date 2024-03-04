#pragma once
#include<Mango.h>
class Sandbox :public Mango::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox() {

	}

};

Mango::Application* Mango::CreateNewApplication() {
	return new Sandbox();
}