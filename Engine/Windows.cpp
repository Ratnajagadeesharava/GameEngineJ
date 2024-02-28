#include "platform.hpp"
#include "pch.h"
#ifdef WINDOWS_64_PLATFORM
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
namespace engine {
	class internal_state {
	public:
		HINSTANCE hInstance;
		HWND hWnd;
	};

	LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
	static f64 clock_frequency;
	static LARGE_INTEGER start_time;
	
	char platform_pump_messages(platform_state* plat_state) {
		MSG message;
		while (PeekMessageA(&message, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessageA(&message);
		}

		return TRUE;
	}

	char platform_startup(
		platform_state* platformState,
		signed int  x,
		signed int y,
		unsigned int height,
		unsigned int width
	) {
		platformState->internal_state = new internal_state();
		internal_state* i_state = (internal_state*)platformState->internal_state;
		i_state->hInstance = GetModuleHandleA(0);
		WNDCLASSEX wClass;
		const TCHAR className[] = _T("GAME ENGINE J");
		const TCHAR title[] = _T("GAME ENGINE J");

		wClass.cbSize = sizeof(WNDCLASSEX);
		wClass.style = CS_HREDRAW | CS_VREDRAW;
		wClass.lpfnWndProc = WindowProcedure;
		wClass.hInstance = i_state->hInstance;
		wClass.hIcon = LoadIcon(i_state->hInstance, IDI_APPLICATION);
		wClass.cbClsExtra = 0;
		wClass.cbWndExtra = 0;
		wClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wClass.lpszClassName = className;
		wClass.lpszMenuName = NULL;
		wClass.hIconSm = LoadIcon(wClass.hInstance, IDI_APPLICATION);

		
		if (!RegisterClassEx(&wClass))
		{
			DWORD error = GetLastError();
			MessageBox(NULL,
				L"Call to RegisterClassEx failed!",
				L"Windows Desktop Guided Tour",
				NULL);

			return 0;
		}
		u32 window_style = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION;
		u32 window_ex_style = WS_EX_APPWINDOW;

		window_style |= WS_MAXIMIZEBOX;
		window_style |= WS_MINIMIZEBOX;
		window_style |= WS_THICKFRAME;

		HWND hWnd = CreateWindowEx(
			WS_EX_OVERLAPPEDWINDOW,
			className,
			title,
			window_style,
			x, y,
			width, height,
			0,
			0,
			i_state->hInstance,
			0
		);

		if (!hWnd)
		{
			MessageBox(NULL,
				L"Call to CreateWindow failed!",
				L"Windows Desktop Guided Tour",
				NULL);

			return 0;
		}
		int should_activate = 1;
		int show_window_command_flags = should_activate ? SW_SHOW : SW_SHOWNOACTIVATE;
		ShowWindow(hWnd,
			show_window_command_flags);
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		clock_frequency = 1.0 / (f64)frequency.QuadPart;
		QueryPerformanceCounter(&start_time);
		//UpdateWindow(hWnd);
		return 1;
	}

	LRESULT CALLBACK WindowProcedure(HWND hwnd, u32 msg, WPARAM w_param, LPARAM l_param) {
		TCHAR greeting[] = _T("Hello Arava Ratna Jagadeesh!!");
		PAINTSTRUCT ps;
		HDC hdc;
		switch (msg) {
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);
			TextOut(hdc,
				5, 5,
				greeting, _tcslen(greeting));
			// End application-specific layout section.

			EndPaint(hwnd, &ps);
			break;
		case WM_ERASEBKGND:
			// Notify the OS that erasing will be handled by the application to prevent flicker.
			return 1;
		case WM_CLOSE:
			// TODO: Fire an event for the application to quit.
			std::cout << "trying to close";
			return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_SIZE: {
			// Get the updated size.
			// RECT r;
			// GetClientRect(hwnd, &r);
			// u32 width = r.right - r.left;
			// u32 height = r.bottom - r.top;

			// TODO: Fire an event for window resize.
		} break;
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYUP: {
			// Key pressed/released
			//b8 pressed = (msg == WM_KEYDOWN || msg == WM_SYSKEYDOWN);
			// TODO: input processing

		} break;
		case WM_MOUSEMOVE: {
			// Mouse move
			//i32 x_position = GET_X_LPARAM(l_param);
			//i32 y_position = GET_Y_LPARAM(l_param);
			// TODO: input processing.
		} break;
		case WM_MOUSEWHEEL: {
			// i32 z_delta = GET_WHEEL_DELTA_WPARAM(w_param);
			// if (z_delta != 0) {
			//     // Flatten the input to an OS-independent (-1, 1)
			//     z_delta = (z_delta < 0) ? -1 : 1;
			//     // TODO: input processing.
			// }
		} break;
		case WM_LBUTTONDOWN:
		case WM_MBUTTONDOWN:
		case WM_RBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_MBUTTONUP:
		case WM_RBUTTONUP: {
			//b8 pressed = msg == WM_LBUTTONDOWN || msg == WM_RBUTTONDOWN || msg == WM_MBUTTONDOWN;
			// TODO: input processing.
		} break;
		}

		return DefWindowProcA(hwnd, msg, w_param, l_param);
	}
}
#endif // WINDOWS_64_PLATFORM