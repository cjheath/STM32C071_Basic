/*
 * MAX5712.h
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#ifndef MAX5712_H
#define MAX5712_H

#include <stdint.h>
#include <stdbool.h>
#include "SPI.h"
#include "NSS.h"
#include "delay.h"

// 12 bit  DAC write command : 0b0011xxxx xxxx xxxx
#define MAX5712_CMD_WRITE_DAC  (3U << 12)

//Optional initialization (e.g,reset delay)
void MAX5712_Init(void);

// set the DAC output value (0-0xFFF)
bool MAX5712_SetValue(uint16_t value);

#endif // MAX5712_H
