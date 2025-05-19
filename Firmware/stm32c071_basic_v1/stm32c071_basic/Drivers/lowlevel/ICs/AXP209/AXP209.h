/*
 * AXP209.h
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */


#ifndef AXP209_H
#define AXP209_H

#include <stdint.h>
#include <stdbool.h>
#include "I2C.h"
#include "delay.h"

// 7-bit I2C address for the AXP209 power management IC
#define AXP209_I2C_ADDR   0x34


bool AXP209_Init(void);
bool AXP209_WriteReg(uint8_t reg, uint8_t data);
bool AXP209_ReadReg(uint8_t reg, uint8_t *data);

#endif // AXP209_H
