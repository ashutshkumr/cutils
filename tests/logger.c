
#include <time.h>

#include "logger.h"

void sum_func() {
    timer_start();
    timer_stop();
}

int main() {
    log_set_level(LOG_LEVEL_TRC);
    sum_func();
    log_err("This is just an error");

    log_trc("this is a macro %d", 5);
    log_dbg("this is a debug");
    return 0;
}