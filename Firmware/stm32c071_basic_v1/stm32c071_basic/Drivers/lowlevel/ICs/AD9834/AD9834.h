/*
 * AD9834.h
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#ifndef LOWLEVEL_ICS_AD9834_AD9834_H_
#define LOWLEVEL_ICS_AD9834_AD9834_H_


#include "stm32c0xx.h"
#include <stdint.h>
#include <stdbool.h>
void AD9834_Init(void);
void AD9834_WriteRegister(uint16_t data);
void AD9834_SetFrequency(uint32_t frequency);
void AD9834_SetSineWave(void);
void AD9834_SetSquareWave(void);
void AD9834_SetTriangleWave(void);

#endif /* LOWLEVEL_ICS_AD9834_AD9834_H_ */
