/*
 * MAX5712.c
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#include "MAX5712.h"

// optional init give the DAC time to power up
void MAX5712_Init(void) {
    delay_ms(1);
}

// write a 12-bit value to the DAC via SPI

bool MAX5712_SetValue(uint16_t value) {
    uint16_t word = MAX5712_CMD_WRITE_DAC | (value & 0x0FFF);
    MAX5712_Select(); //Assert CS
    SPI_Transmit16(word); //send 16-bit command
    MAX5712_Deselect(); // Deassert CS
    delay_ms(1); // small settle delay
    return true;
}


