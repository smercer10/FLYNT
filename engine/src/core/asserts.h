#pragma once

#include "types.h"

// Comment following line to disable assertions
#define F_ASSERTIONS_ENABLED

#ifdef F_ASSERTIONS_ENABLED

F_API void report_assert_fail(const char *expression, const char *message, const char *file, i32 line);

// Assert without message
#define F_ASSERT(expr)                                            \
    {                                                             \
        if (expr)                                                 \
        {                                                         \
        }                                                         \
        else /* Just evaluating !expr may not always work */      \
        {                                                         \
            report_assert_fail(#expr, "N/A", __FILE__, __LINE__); \
            __debugbreak();                                       \
        }                                                         \
    }

// Assert with message
#define F_ASSERT_MSG(expr, msg)                                 \
    {                                                           \
        if (expr)                                               \
        {                                                       \
        }                                                       \
        else /* Just evaluating !expr may not always work */    \
        {                                                       \
            report_assert_fail(#expr, msg, __FILE__, __LINE__); \
            __debugbreak();                                     \
        }                                                       \
    }

// Assert only in debug mode
#ifdef _DEBUG
#define F_ASSERT_DEBUG(expr)                                      \
    {                                                             \
        if (expr)                                                 \
        {                                                         \
        }                                                         \
        else /* Just evaluating !expr may not always work */      \
        {                                                         \
            report_assert_fail(#expr, "N/A", __FILE__, __LINE__); \
            __debugbreak();                                       \
        }                                                         \
    }
#else
#define F_ASSERT_DEBUG(expr) // Do nothing
#endif

#else
#define F_ASSERT(expr)          // Do nothing
#define F_ASSERT_MSG(expr, msg) // Do nothing
#define F_ASSERT_DEBUG(expr)    // Do nothing

#endif
