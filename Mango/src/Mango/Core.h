#pragma once
#ifdef MG_PLATFORM_WINDOWS
	#ifdef MG_BUILD_DLL
		#define MG_API __declspec(dllexport)
	#else
		#define MG_API __declspec(dllimport)
	#endif
		/*#error this is application is curretntly supported only on windows*/
#endif