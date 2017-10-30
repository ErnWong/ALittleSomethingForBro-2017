#pragma once

#include <cstdio>
#include <tchar.h>

#define LOG_ENABLE_INFO 1
#define LOG_ENABLE_WARNING 1
#define LOG_ENABLE_ERROR 1

extern bool LoggingDisabled;
void LoggingDisable();
void LoggingEnable();

#define LOG_INFO(...) \
	Sleep(50); \
	do { \
		if (LOG_ENABLE_INFO && !LoggingDisabled) {\
			_ftprintf(stderr, "   [INFO] ");\
			_ftprintf(stderr, __VA_ARGS__); }\
	} while (0)

#define LOG_WARNING(...) \
	Sleep(50); \
	do { \
		if (LOG_ENABLE_WARNING && !LoggingDisabled) { \
			_ftprintf(stderr, "[WARNING] ");\
			_ftprintf(stderr, __VA_ARGS__); }\
	} while (0)

#define LOG_ERROR(...) \
	Sleep(50); \
	do { \
		if (LOG_ENABLE_ERROR && !LoggingDisabled) { \
			_ftprintf(stderr, "  [ERROR] ");\
			_ftprintf(stderr, __VA_ARGS__); }\
	} while (0)