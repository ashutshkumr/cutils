#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"

#define LOG_LEVEL_ENV "LOG_LEVEL"
#define LOG_LEVEL_DEFAULT LOG_LEVEL_WRN
#define LOG_LEVEL_INPUT_TRC "trace"
#define LOG_LEVEL_INPUT_DBG "debug"
#define LOG_LEVEL_INPUT_INF "info"
#define LOG_LEVEL_INPUT_WRN "warning"
#define LOG_LEVEL_INPUT_ERR "error"
#define LOG_LEVEL_INPUT_FAT "fatal"

static enum LogLevel LOG_LEVEL = LOG_LEVEL_DEFAULT;

void init_log_level() {
    const char* level = getenv(LOG_LEVEL_ENV);
    if (level != NULL) {
        if (strcmp(LOG_LEVEL_INPUT_TRC, level) == 0) {
            LOG_LEVEL = LOG_LEVEL_TRC;
            return;
        }
        if (strcmp(LOG_LEVEL_INPUT_DBG, level) == 0) {
            LOG_LEVEL = LOG_LEVEL_DBG;
            return;
        }
        if (strcmp(LOG_LEVEL_INPUT_TRC, level) == 0) {
            LOG_LEVEL = LOG_LEVEL_TRC;
            return;
        }
        if (strcmp(LOG_LEVEL_INPUT_TRC, level) == 0) {
            LOG_LEVEL = LOG_LEVEL_TRC;
            return;
        }
        if (strcmp(LOG_LEVEL_INPUT_TRC, level) == 0) {
            LOG_LEVEL = LOG_LEVEL_TRC;
            return;
        }

        log_err("Unsupported log level: '%s'", level);
    }
}

bool can_log(enum LogLevel level) {
    return LOG_LEVEL >= level;
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
