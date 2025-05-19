/*
 * RFFC5071.h
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */
#ifndef RFFC5071_H
#define RFFC5071_H

#include <stdint.h>
#include <stdbool.h>

// Initialize the RFFC5071
void RFFC5071_Init(void);

// write packet : bit15 =1 , bits 14-10 = register addr (6bits), bits9-0 = data (10 bits)
bool RFFC5071_WriteReg(uint8_t addr, uint16_t data);

// read packet : bit15 = 0, bits14-10 = register sddr , bits 9-0 ignored
uint16_t RFFC5071_ReadReg(uint8_t addr);

// Example : set the local oscillator (LO) frequency in HZ
bool RFFC5071_SetLO(uint32_t freq_hz);

#endif // RFFC5071_H
