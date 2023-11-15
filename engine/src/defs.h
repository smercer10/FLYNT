#pragma once

// Type shorthands
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

typedef float f32;
typedef double f64;

typedef char b8;
typedef int b32;

// Make static assert portable
#if defined(__clang__) || defined(__GNUC__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Confirm type sizes
STATIC_ASSERT(sizeof(u8) == 1, "u8 is not 1 byte");
STATIC_ASSERT(sizeof(u16) == 2, "u16 is not 2 bytes");
STATIC_ASSERT(sizeof(u32) == 4, "u32 is not 4 bytes");
STATIC_ASSERT(sizeof(u64) == 8, "u64 is not 8 bytes");

STATIC_ASSERT(sizeof(i8) == 1, "i8 is not 1 byte");
STATIC_ASSERT(sizeof(i16) == 2, "i16 is not 2 bytes");
STATIC_ASSERT(sizeof(i32) == 4, "i32 is not 4 bytes");
STATIC_ASSERT(sizeof(i64) == 8, "i64 is not 8 bytes");

STATIC_ASSERT(sizeof(f32) == 4, "f32 is not 4 bytes");
STATIC_ASSERT(sizeof(f64) == 8, "f64 is not 8 bytes");

STATIC_ASSERT(sizeof(b8) == 1, "b8 is not 1 byte");
STATIC_ASSERT(sizeof(b32) == 4, "b32 is not 4 bytes");

// Detect platform
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define PLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit Windows is required"
#endif

#elif defined(__linux__) || defined(__gnu_linux__)
#define PLATFORM_LINUX 1
#ifndef __x86_64__
#error "64-bit Linux is required"
#endif

#else
#error "Unsupported platform"
#endif

// Control library export/import
#ifdef F_EXPORT
#ifdef _MSC_VER
#define F_API __declspec(dllexport)
#else
#define F_API __attribute__((visibility("default")))
#endif

#else
#ifdef _MSC_VER
#define F_API __declspec(dllimport)
#else
#define F_API
#endif
#endif
