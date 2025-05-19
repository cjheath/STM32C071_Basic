/*
 * SI5351.h
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#ifndef SI5351_H
#define SI5351_H

#include <stdint.h>
#include <stdbool.h>
#include "I2C.h"
#include "delay.h"

#define SI5351_I2C_ADDR   0x60


bool SI5351_Init(void);

// (optional) set frequency of ouyput 'n' to 'freq_hz'
//-placeholder : requires full PLL + Multisynth math
bool SI5351_SetFreq(uint8_t output_n, uint32_t freq_Hz);

// Enable or disable output 'n' (0..2)
bool SI5351_EnableOutput(uint8_t output_n, bool enable);
bool SI5351_ReadReg(uint8_t reg, uint8_t *data);

#endif // SI5351_H
