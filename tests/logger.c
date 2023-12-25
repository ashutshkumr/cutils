
#include <time.h>
#include <unistd.h>

#include "logger.h"

void sum_func() {
    timer_start();
    sleep(0);
    timer_stop();
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

    return 0;
}
