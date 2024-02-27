#pragma once
#include "TypeDefs.h"
#ifdef WINDOWS_64_PLTFORM
#include<Windows.h>
#include <windowsx.h>
#include "logger.h"

ENGINE_API char platform_startup(
	char* application_name,
	signed int  x,
	signed int y,
	unsigned int height,
	unsigned int width
	);
#endif

