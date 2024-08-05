#include "main.h"
#include <iostream>

using namespace std;

int main() {    
    stdio_init_all();
    set_sys_clock_khz(133000, true);    
    uart_init(uart0, 921600);
    uart_set_fifo_enabled(uart0, true);
    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART); 
    // SECOND CORE MAIN FUNCTION LAUNCH
    multicore_launch_core1(second_core_main);
    // MAIN CORE LOOP
    while (true) {    
        if (uart_is_readable(uart0)) {
            uint32_t command  = (uint32_t)uart_getc(uart0); // Blocking
            multicore_fifo_push_blocking(command); 
        }
          
    }

    return 0;
}