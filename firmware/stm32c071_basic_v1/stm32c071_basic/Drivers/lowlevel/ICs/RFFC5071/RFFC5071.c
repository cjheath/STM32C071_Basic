/*
 * RFFC5071.c
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */
#include "RFFC5071.h"
#include "SPI.h"
#include "NSS.h"
#include "delay.h"

// Build a 16-bit write packet: 1 | addr[5:0] | data [9:0]
static uint16_t pack_write(uint8_t addr, uint16_t data) {
    return (uint16_t)(0x8000U | ((addr & 0x3F) << 10) | (data & 0x03FF));
}

// Build a 16-bit read packet: 0|addr[5:0]|0
static uint16_t pack_read(uint8_t addr) {
    return (uint16_t)(((addr & 0x3F) << 10));
}

void RFFC5071_Init(void) {
    // optional startup delay
    delay_ms(10);
    // Example default register writes
    RFFC5071_WriteReg(0x05, 0x03FF);
    RFFC5071_WriteReg(0x07, 0x0100);
}

bool RFFC5071_WriteReg(uint8_t addr, uint16_t data) {
    uint16_t pkt = pack_write(addr, data);
    RFFC5071_Select();
    SPI_Transmit16(pkt);
    RFFC5071_Deselect();
    delay_ms(1);
    return true;
}

uint16_t RFFC5071_ReadReg(uint8_t addr) {
    uint16_t pkt = pack_read(addr);
    uint16_t resp;
    RFFC5071_Select();
    SPI_Transmit16(pkt);
    resp = SPI_Receive16();
    RFFC5071_Deselect();
    return (uint16_t)(resp & 0x03FF);
}

bool RFFC5071_SetLO(uint32_t freq_hz) {
    // placeholder caculation : user should implement VCO & divider math
	//Here we simply pack the MHZ value in to register 0x0B as an example
    uint16_t word = (uint16_t)((freq_hz / 1000000U) & 0x03FF);
    return RFFC5071_WriteReg(0x0B, word);
}
