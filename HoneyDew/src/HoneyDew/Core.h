#pragma once

//so that we dont need to import export dll everytime depending on where we are
//we can just use HNY_API instead

#ifdef HNY_PLATFORM_WINDOWS
#ifdef HNY_BLD_DLL
#define HNY_API __declspec(dllexport)
#else
#define HNY_API __declspec(dllimport)
#endif
#else
#error Only Windows Supported
#endif