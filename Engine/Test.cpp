#include "pch.h"
#include "Test.h"
#include "logger.h"
#include<Windows.h>
#include <windowsx.h>
namespace engine {
	//HWND hWnd: Handle to the window that received the message. This parameter identifies the window to which the message is directed.
	// message: message type WM_CREATE, WM_DESTROY, WM_PAINT,
	// wParam,lParam : Additional message specific information 
	//window procedure method to handle events in windows
	//LRESULT: represents the result of processing the message
	LRESULT CALLBACK window_process_message(HWND hWnd,
		UINT message,
		WPARAM wParam,
		LPARAM lParam) {
		switch (message) {
		case WM_CREATE: {
			//TODO: hande window creation
		}break;
		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;
		case WM_DESTROY:
		{
			//Handle Window Destruction
			//void PostQuitMessage(int nExitCode);
			PostQuitMessage(0);
			return 0;
		}break;
		
		}
		return DefWindowProcA(hWnd, message, wParam, lParam);
	}
	
	void Test::RunTest()
	{
	}
}
