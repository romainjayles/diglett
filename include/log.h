#ifndef _log_h_
#define _log_h_

#include "../include/error.h"

typedef enum{
	none = 0,
	error = 1,
	info = 2,
	debug = 3
}log_level;

void set_log_level(log_level level);

void print_log_error(log_level level, const char* format, int error_code);

void print_log(log_level level, const char* format);


#endif
