#pragma once
#include <iostream>
// Unsigned int types.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed int types.
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// Floating point types
typedef float f32;
typedef double f64;

// Boolean types
typedef int b32;
typedef char b8;

// Properly define static assertions.
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Ensure all types are of the correct size.
STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes.");
STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes.");
STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes.");

STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes.");
STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes.");
STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes.");

STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes.");
STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes.");

#if defined(_WIN32)
#if defined(_WIN64)
#define WINDOWS_64_PLATFORM 1
#else
#error "not a windows 64 platform"
#endif
#else
#error "not a windows machine"
#endif


#ifdef ENGINE_EXPORT
//// Check if the code is being compiled with Microsoft Visual C++
//#ifdef _MSC_VER
#define ENGINE_API __declspec(dllexport)
//#endif

#else
//#ifdef  __MSC_VER
#define ENGINE_API __declspec(dllimport)
//#endif //  __MSC_VER

#endif

#define DEBUG_MODE 1
#define RELEASE_MODE 1
#define INFO_MESSAGES 1
#define WARNINGS 1

#define ENGINENAME "GAME ENGINE J"