#include "../include/log.h"
#include "../include/error.h"

#include <stdio.h>

log_level current_level = info;

void set_log_level(log_level level) {
    current_level = level;
}

void print_log(log_level level, const char* format) {
    print_log_error(level, format, ERROR_OK);
}

void print_log_error(log_level level, const char* format, int error_code) {
    if(level <= current_level) {
        printf(format);
        if(error_code < 0) {
            printf(" error_code : %i\n", error_code);
        }
    }
}
