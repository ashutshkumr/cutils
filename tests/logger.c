
#include <time.h>
#include <unistd.h>

#include "logger.h"

int test_timer() {
    timer_start();
    
    uint64_t sum = 0;
    for (uint64_t i = 0; i < 1000000; i++) {
        sum += i;
    }
    timer_stop();

    return 0;
}

int test_logger() {
    init_log_level();
    
    log_trc("Trace log without args");
    log_trc("Trace log with args: %d %s", 5, "str");

    log_dbg("Debug log without args");
    log_dbg("Debug log with args: %d %s", 4, "str");

    log_inf("Info log without args");
    log_inf("Info log with args: %d %s", 3, "str");

    log_wrn("Warning log without args");
    log_wrn("Warning log with args: %d %s", 2, "str");

    log_err("Error log without args");
    log_err("Error log with args: %d %s", 1, "str");

    test_timer();

    return 0;
}
