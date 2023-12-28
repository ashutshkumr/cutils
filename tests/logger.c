
#include <time.h>
#include <unistd.h>

#include "logger.h"
#include "tests.h"

static int test_timer() {
    uint64_t sum;

    timer_start();

    sum = 0;
    for (uint64_t i = 0; i < 1000000; i++) {
        sum += i;
    }
    log_infof("answer is %ld", sum);

    timer_stop();

    return 0;
}

int test_logger() {
    init_log_level();

    log_trace("Trace log without args");
    log_tracef("Trace log with args: %d %s", 5, "str");

    log_debug("Debug log without args");
    log_debugf("Debug log with args: %d %s", 4, "str");

    log_info("Info log without args");
    log_infof("Info log with args: %d %s", 3, "str");

    log_warn("Warning log without args");
    log_warnf("Warning log with args: %d %s", 2, "str");

    log_error("Error log without args");
    log_errorf("Error log with args: %d %s", 1, "str");

    test_timer();

    return 0;
}
