#pragma once

#include "types.h"

// Fatal and error levels are always logged
#define F_LOG_WARN_ENABLED 1
#define F_LOG_INFO_ENABLED 1
#define F_LOG_DEBUG_ENABLED 1
#define F_LOG_TRACE_ENABLED 1

// Disable debug and trace logging in release builds
#if F_RELEASE == 1
#define F_LOG_DEBUG_ENABLED 0
#define F_LOG_TRACE_ENABLED 0
#endif

// Logging levels
typedef enum log_level
{
    F_LOG_LEVEL_FATAL = 0,
    F_LOG_LEVEL_ERROR = 1,
    F_LOG_LEVEL_WARN = 2,
    F_LOG_LEVEL_INFO = 3,
    F_LOG_LEVEL_DEBUG = 4,
    F_LOG_LEVEL_TRACE = 5,
} log_level;

// Initialize/shutdown logger
b8 init_logger();
void shutdown_logger();

// Funnel for all logging
F_API void log_output(log_level level, const char *message, ...);

// Logging macros
#define F_FATAL(message, ...) log_output(F_LOG_LEVEL_FATAL, message, ##__VA_ARGS__)

#define F_ERROR(message, ...) log_output(F_LOG_LEVEL_ERROR, message, ##__VA_ARGS__)

#if F_LOG_WARN_ENABLED == 1
#define F_WARN(message, ...) log_output(F_LOG_LEVEL_WARN, message, ##__VA_ARGS__)
#else
#define F_WARN(message, ...) // Do nothing
#endif

#if F_LOG_INFO_ENABLED == 1
#define F_INFO(message, ...) log_output(F_LOG_LEVEL_INFO, message, ##__VA_ARGS__)
#else
#define F_INFO(message, ...) // Do nothing
#endif

#if F_LOG_DEBUG_ENABLED == 1
#define F_DEBUG(message, ...) log_output(F_LOG_LEVEL_DEBUG, message, ##__VA_ARGS__)
#else
#define F_DEBUG(message, ...) // Do nothing
#endif

#if F_LOG_TRACE_ENABLED == 1
#define F_TRACE(message, ...) log_output(F_LOG_LEVEL_TRACE, message, ##__VA_ARGS__)
#else
#define F_TRACE(message, ...) // Do nothing
#endif
