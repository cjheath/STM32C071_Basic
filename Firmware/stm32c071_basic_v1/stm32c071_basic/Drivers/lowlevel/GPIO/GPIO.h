/*
 * GPIO.h
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#ifndef GPIO_LOWLEVEL_H
#define GPIO_LOWLEVEL_H

#include "stm32c0xx.h"       //CMSIS


//device header //
#include <stdint.h>        //uint16_t
#include <stdbool.h>      //bool

void GPIO_LowLevel_Init(void);
void GPIO_WritePin(GPIO_TypeDef*port , uint16_t pin, bool );    // write on a pin: state = true -> HIGH , false -> LOW
bool GPIO_ReadPin(GPIO_TypeDef*port, uint16_t pin);

#endif
