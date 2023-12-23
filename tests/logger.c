
#include "include/logger.h"

void sum_func() {
    timer_start();
    // log_inf("we are inside sum_func");
    timer_stop();
}

int main() {
    log_set_level(LOG_LEVEL_TRC);
    sum_func();
    log_err("This is just an error");


    log_trc("this is a macro %d", 5);
    return 0;
}