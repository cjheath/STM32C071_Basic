/*
 * ADF4351.h
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#ifndef ADF4351_H
#define ADF4351_H

#include <stdint.h>
#include <stdbool.h>
#include "SPI.h"
#include "NSS.h"
#include "delay.h"
//Register addresses for 0-5 for ADF4351
#define ADF4351_REG0   0
#define ADF4351_REG1   1
#define ADF4351_REG2   2
#define ADF4351_REG3   3
#define ADF4351_REG4   4
#define ADF4351_REG5   5

// Initia;ize the ADF4351 (e.g,load default Reg5)

void ADF4351_Init(void);

// write a 28-bit value into register 'reg' (0-5)
bool ADF4351_WriteReg(uint8_t reg, uint32_t data);

// Stub for setting output frequency (to be implemented per device PLL/MS scheme)
bool ADF4351_SetFreq(uint32_t freq_hz);

#endif // ADF4351_H
