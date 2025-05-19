/*
 * GPIO.c
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#include "GPIO.h"
#include "stm32c0xx.h"
#include <stdbool.h>
#include <stdint.h>

void GPIO_LowLevel_Init(void) {
    // Enable clocks for GPIOA, GPIOB
    RCC->IOPENR |= RCC_IOPENR_GPIOAEN | RCC_IOPENR_GPIOBEN ;


}
void GPIO_WritePin(GPIO_TypeDef*port,uint16_t pin, bool state) {
	if (state){
		port->BSRR = (1U << pin); //BSRR[0..15] -> set
	}else{
		port->BSRR = (1U << (pin +16)); // BSRR[16..3] -> reset
	}
}

bool GPIO_ReadPin(GPIO_TypeDef*port,uint16_t pin) {
	return (port->IDR & (1U << pin)) != 0;
}
