#ifndef CUTILS_LOGGER_H
#define CUTILS_LOGGER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>

// supported log levels - all the messages are logged to stderr
enum LogLevel {
    // log messages for irrecoverable errors; exit with error code 1
    // after logging
    LOG_LEVEL_FAT = 0,
    // log messages for recoverable errors
    LOG_LEVEL_ERR = 1,
    // log warning messages; this is the default log level
    LOG_LEVEL_WRN = 2,
    // log messages pertaining to important information; e.g. state changes,
    // operation completion, etc.
    LOG_LEVEL_INF = 3,
    // log messages for diagnostic purposes
    LOG_LEVEL_DBG = 4,
    // log messages consisting of function durations and traces
    LOG_LEVEL_TRC = 5
};

// disallow log level to be modified by the user
extern const enum LogLevel* LOG_LEVEL_PTR;

void init_log_level(void);

uint64_t get_monotonic_ns(void);
uint64_t get_monotonic_ns_since(uint64_t ns);

#define can_log(level) *LOG_LEVEL_PTR >= level

#define log_print(level_enum, level_str, msg) if (can_log(level_enum)) {    \
    struct timespec log_time;                                               \
    clock_gettime(CLOCK_MONOTONIC, &log_time);                              \
    fprintf(stderr, "[%10ld.%ld " level_str "]: " msg "\n", log_time.tv_sec, log_time.tv_nsec); \
}

#define log_printf(level_enum, level_str, fmt, ...) if (can_log(level_enum)) {  \
    struct timespec log_time;                                                   \
    clock_gettime(CLOCK_MONOTONIC, &log_time);                                  \
    fprintf(stderr, "[%10ld.%ld " level_str "]: " fmt "\n", log_time.tv_sec, log_time.tv_nsec, __VA_ARGS__);    \
}

#define log_debug(msg) log_print(LOG_LEVEL_DBG, "DBG", msg) NULL
#define log_debugf(msg, ...) log_printf(LOG_LEVEL_DBG, "DBG", msg, __VA_ARGS__) NULL

#define log_info(msg) log_print(LOG_LEVEL_INF, "INF", msg) NULL
#define log_infof(msg, ...) log_printf(LOG_LEVEL_INF, "INF", msg, __VA_ARGS__) NULL

#define log_warn(msg) log_print(LOG_LEVEL_WRN, "WRN", msg) NULL
#define log_warnf(msg, ...) log_printf(LOG_LEVEL_WRN, "WRN", msg, __VA_ARGS__) NULL

#define log_error(msg) log_print(LOG_LEVEL_ERR, "ERR", msg) NULL
#define log_errorf(msg, ...) log_printf(LOG_LEVEL_ERR, "ERR", msg, __VA_ARGS__) NULL

#define log_fatal(msg) log_print(LOG_LEVEL_FAT, "FAT", msg) exit(1)
#define log_fatalf(msg, ...) log_printf(LOG_LEVEL_FAT, "FAT", msg, __VA_ARGS__) exit(1)

#define log_trace(msg) if (can_log(LOG_LEVEL_TRC)) {  \
    struct timespec log_time;                       \
    clock_gettime(CLOCK_MONOTONIC, &log_time);      \
    fprintf(stderr, "[%10ld.%ld TRC]: %s:%d:%s(): " msg "\n", log_time.tv_sec, log_time.tv_nsec, __FILE__, __LINE__, __func__); \
} NULL

#define log_tracef(fmt, ...) if (can_log(LOG_LEVEL_TRC)) {    \
    struct timespec log_time;                               \
    clock_gettime(CLOCK_MONOTONIC, &log_time);              \
    fprintf(stderr, "[%10ld.%ld TRC]: %s:%d:%s(): " fmt "\n", log_time.tv_sec, log_time.tv_nsec, __FILE__, __LINE__, __func__, __VA_ARGS__);    \
} NULL

#define timer_start() uint64_t start_ns = 0; if (can_log(LOG_LEVEL_TRC)) {  \
    start_ns = get_monotonic_ns();                                          \
} NULL

#define timer_stop() if (can_log(LOG_LEVEL_TRC)) {                  \
    log_tracef("Elapsed ns: %ld", get_monotonic_ns_since(start_ns));   \
} NULL


#endif
