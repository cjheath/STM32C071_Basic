/*
 * AD9959.h
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#ifndef AD9959_H
#define AD9959_H

#include <stdint.h>
#include <stdbool.h>

// control Function Registers (CFR0-CFR7)
#define AD9959_REG_CFR0    0   // Control Function Register 0
#define AD9959_REG_CFR1    1   // Control Function Register 1
// … continue for CFR2-CFR7 as needed...

//Init and basic operations for AD9959 DDS
bool AD9959_Init(void);

bool AD9959_WriteReg(uint8_t addr, uint32_t data);

bool AD9959_SetFreq(uint8_t channel, uint32_t freq_Hz);

#endif // AD9959_H
