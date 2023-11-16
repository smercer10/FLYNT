#include "logger.h"
#include "asserts.h"

// TODO: platform optimized logging
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

b8 init_logger()
{
    // TODO: create log file
    return F_TRUE;
}

void shutdown_logger()
{
    // TODO: perform cleanup and write queued logs
}

void log_output(log_level level, const char *message, ...)
{

    const char *level_strings[6] = {
        "[FATAL]: ",
        "[ERROR]: ",
        "[WARN]: ",
        "[INFO]: ",
        "[DEBUG]: ",
        "[TRACE]: "};

    // b8 is_error = level <= F_LOG_LEVEL_ERROR;

    // Allocate zeroed memory for message to avoid slow dynamic allocation
    char buffer[32768];
    memset(buffer, 0, sizeof(buffer));

    // Format message with compiler built-ins to avoid potential clash with Microsoft headers
    __builtin_va_list arg_ptr;
    __builtin_va_start(arg_ptr, message);
    vsnprintf(buffer, sizeof(buffer), message, arg_ptr);
    __builtin_va_end(arg_ptr);

    // TODO: better fix for buffer overwrite
    char buffer2[32768];

    // Prepend log level to message
    sprintf(buffer2, "%s%s\n", level_strings[level], buffer);

    printf("%s", buffer2);
}

// Implementation for asserts.h
void report_assert_fail(const char *expression, const char *message, const char *file, i32 line)
{
    F_FATAL("Assert failed: %s, message: %s, file: %s, line: %d", expression, message, file, line);
}
