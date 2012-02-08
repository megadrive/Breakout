
#ifndef __UTIL_H
#define __UTIL_H

/**
 * Utility functions.
 */ 

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
	RR_RESULT_OK = 0,
	RR_RESULT_WARNING,
	RR_RESULT_ERROR,
	RR_RESULT_ERROR_MINOR,
	RR_RESULT_ERROR_MAJOR,

	RR_RESULT_COUNT
};

#endif
