/*
 * Delay.c
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#include "delay.h"
#include "stm32c0xx.h"

__IO uint32_t uwTick;

/*void SysTick_Handler(void) {
    uwTick++;
}*/

void delay_init(void) {
    // SystemCoreClock =  48 MHz

    uwTick = 0;
    SysTick->LOAD  = (SystemCoreClock / 1000) - 1;
    SysTick->VAL   = 0;
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk
                   | SysTick_CTRL_TICKINT_Msk
                   | SysTick_CTRL_ENABLE_Msk;
}

void delay_ms(uint32_t ms) {
    uint32_t start = uwTick;
    while ((uwTick - start) < ms) {
        __WFE();  // wait for next tick
    }
}
