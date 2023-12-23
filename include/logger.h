#ifndef CUTILS_LOGGER_H
#define CUTILS_LOGGER_H

#include <stdio.h>
#include <stdint.h>
#include <time.h>

enum LogLevel {
    LOG_LEVEL_FAT = 0,
    LOG_LEVEL_ERR = 1,
    LOG_LEVEL_WRN = 2,
    LOG_LEVEL_INF = 3,
    LOG_LEVEL_DBG = 4,
    LOG_LEVEL_TRC = 5
};

extern enum LogLevel LOG_LEVEL;

void log_set_level(enum LogLevel level);

uint64_t get_monotonic_ns();
uint64_t get_monotonic_ns_since(uint64_t ns);

#define log_trc(M, ...) if (LOG_LEVEL >= LOG_LEVEL_TRC) {                                       \
    struct timespec tspec;                                                                      \
    clock_gettime(CLOCK_MONOTONIC, &tspec);                                                     \
    fprintf(stderr, "[%10ld.%ld TRC]: %s(): " M "\n", tspec.tv_sec, tspec.tv_nsec, __func__, ##__VA_ARGS__); \
}

#define log_dbg(M, ...) if (LOG_LEVEL >= LOG_LEVEL_DBG) {                                       \
    struct timespec tspec;                                                                      \
    clock_gettime(CLOCK_MONOTONIC, &tspec);                                                     \
    fprintf(stderr, "[%10ld.%ld DBG]: " M "\n", tspec.tv_sec, tspec.tv_nsec, ##__VA_ARGS__);    \
}

#define log_inf(M, ...) if (LOG_LEVEL >= LOG_LEVEL_INF) {                                       \
    struct timespec tspec;                                                                      \
    clock_gettime(CLOCK_MONOTONIC, &tspec);                                                     \
    fprintf(stderr, "[%10ld.%ld INF]: " M "\n", tspec.tv_sec, tspec.tv_nsec, ##__VA_ARGS__);    \
}

#define log_wrn(M, ...) if (LOG_LEVEL >= LOG_LEVEL_WRN) {                                       \
    struct timespec tspec;                                                                      \
    clock_gettime(CLOCK_MONOTONIC, &tspec);                                                     \
    fprintf(stderr, "[%10ld.%ld WRN]: " M "\n", tspec.tv_sec, tspec.tv_nsec, ##__VA_ARGS__);    \
}

#define log_err(M, ...) if (LOG_LEVEL >= LOG_LEVEL_ERR) {                                       \
    struct timespec tspec;                                                                      \
    clock_gettime(CLOCK_MONOTONIC, &tspec);                                                     \
    fprintf(stderr, "[%10ld.%ld ERR]: " M "\n", tspec.tv_sec, tspec.tv_nsec, ##__VA_ARGS__);    \
}

#define log_fat(M, ...) if (LOG_LEVEL >= LOG_LEVEL_FAT) {                                       \
    struct timespec tspec;                                                                      \
    clock_gettime(CLOCK_MONOTONIC, &tspec);                                                     \
    fprintf(stderr, "[%10ld.%ld FAT]: " M "\n", tspec.tv_sec, tspec.tv_nsec, ##__VA_ARGS__);    \
    exit(1);                                                                                    \
}

#define timer_start() uint64_t __start_ns__; if (LOG_LEVEL >= LOG_LEVEL_TRC) {  \
    __start_ns__ = get_monotonic_ns();                                          \
}

#define timer_stop() if (LOG_LEVEL >= LOG_LEVEL_TRC) {                  \
    log_trc("Elapsed ns: %ld", get_monotonic_ns_since(__start_ns__));   \
}

#endif