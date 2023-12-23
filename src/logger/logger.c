#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>

#include "logger.h"

enum LogLevel LOG_LEVEL =  LOG_LEVEL_ERR;

void log_set_level(enum LogLevel level) {
    LOG_LEVEL = level;
}

uint64_t get_monotonic_ns() {
    struct timespec tspec;
    if (clock_gettime(CLOCK_MONOTONIC, &tspec) != 0) {
        log_fat("Could not get current monotonic time");
    }

    return (tspec.tv_sec * 1000000000) + tspec.tv_nsec;
}

uint64_t get_monotonic_ns_since(uint64_t ns) {
    return get_monotonic_ns() - ns;
}
