// TestBed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Test.h>
#include <platform.hpp>
#include <Windows.cpp>
#include "TypeDefs.h"


#define PRINT_VALUES(...) std::cout << #__VA_ARGS__ << std::endl

int main()
{
    std::cout << "Hello World!\n";
    engine::Test::RunTest();
    /*PRINT_VALUES(1, 2, "hello", 3.14);*/
    engine:: platform_state state;

    const char* enginename = ENGINENAME;
    if (engine::platform_startup(&state, 100, 100, 720, 1280)) {
        while (true) {
            engine::platform_pump_messages(&state);
        }
    }
}

