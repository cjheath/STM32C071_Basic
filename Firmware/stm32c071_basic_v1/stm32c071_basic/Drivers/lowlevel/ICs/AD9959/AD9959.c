/*
 * AD9959.c
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */


#include "AD9959.h"
#include "SPI.h"
#include "NSS.h"
#include "delay.h"

// send raw SPI command: [7-bit addr<<1 | write = 0], then 32-bit data MSB first
static bool AD9959_WriteRaw(uint8_t addr, uint32_t data) {
    uint8_t instr = (addr << 1) & 0xFE;  // write mode
    AD9959_Select();
    SPI_TransmitByte(instr);
    SPI_TransmitByte((data >> 24) & 0xFF);
    SPI_TransmitByte((data >> 16) & 0xFF);
    SPI_TransmitByte((data >>  8) & 0xFF);
    SPI_TransmitByte((data      ) & 0xFF);
    AD9959_Deselect();
    delay_ms(1);
    return true;
}
// Initialize AD9959: reset and enable I/O update, profile control
bool AD9959_Init(void) {
    // CFR0: bit0 = IO_UPDATE enable , bit1 = profile enable
    return AD9959_WriteRaw(AD9959_REG_CFR0, 0x00000003);
}

// write a 32-bit value to a given register (0..7)
bool AD9959_WriteReg(uint8_t addr, uint32_t data) {
    if (addr > 7) return false;
    return AD9959_WriteRaw(addr, data);
}
// set output frequency for channel (0..3) via FIW caculation
bool AD9959_SetFreq(uint8_t channel, uint32_t freq_Hz) {
    if (channel > 3) return false;
    //FIW = freq_hz * 2^32 / SYCLK(e.g,500 MHZ)
    uint64_t ftw = ((uint64_t)freq_Hz << 32) / 500000000ULL;
    uint8_t reg = 8 + channel; // FTWO starts at reg 8
    return AD9959_WriteRaw(reg, (uint32_t)ftw);
}
