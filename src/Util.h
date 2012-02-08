
#ifndef __UTIL_H
#define __UTIL_H

/**
 * Utility functions.
 */

#include <cstdio>

/**
 * Defines
 */
#define	VERSION_MAJOR		1
#define	VERSION_MINOR		0
#define	VERSION_PATCH		0

#define WINDOW_WIDTH		320
#define WINDOW_HEIGHT		240

/**
 * RR_RESULT
 * @brief Describes a result.
 */

enum RR_RESULT
{
	RR_RESULT_OK			= 0,
	RR_RESULT_WARNING		= -1,
	RR_RESULT_ERROR			= -2,
	RR_RESULT_ERROR_MINOR	= -3,
	RR_RESULT_ERROR_MAJOR	= -4,
	RR_RESULT_FATAL			= -5,

	RR_RESULT_COUNT
};

/**
 * LOG
 * @brief Logs a message to the console.
 */
#ifndef LOG
#	define LOG(str) printf("%s", str);
#endif

#endif
