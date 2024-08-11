//
// Created by asus on 2024-07-02.
//

#include "delay_ms.h"

#include <time.h>

void delay_ms(unsigned long long ms) {
    volatile clock_t start_t;
    unsigned long long clkRequired;

    start_t = clock();
    clkRequired = (unsigned long long) ((float) (ms * CLOCKS_PER_SEC) / 1000.0f);

    while (clock() - start_t < clkRequired) {
        //wait
    }
}