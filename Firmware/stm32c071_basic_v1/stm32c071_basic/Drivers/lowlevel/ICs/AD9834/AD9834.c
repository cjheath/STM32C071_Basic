/*
 * AD9834.c
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */
#include "AD9834.h"
#include <stdint.h>
#include <stdbool.h>
// Define SPI1 and NSS pin
#define AD9834_SPI SPI1
#define AD9834_NSS_PORT GPIOA
#define AD9834_NSS_PIN  4

void AD9834_Delay(void) {
    for (volatile int i = 0; i < 1000; i++) __NOP();
}

void AD9834_Init(void) {
    // NSS pin high
    AD9834_NSS_PORT->BSRR = AD9834_NSS_PIN;
    AD9834_Delay();

    // Reset AD9834
    AD9834_WriteRegister(0x2100); // Control reg: RESET + SINE wave
    AD9834_WriteRegister(0x4000); // FREQ0 LSB
    AD9834_WriteRegister(0x4000); // FREQ0 MSB
    AD9834_WriteRegister(0xC000); // PHASE0
    AD9834_WriteRegister(0x2000); // Clear RESET bit
}

void AD9834_WriteRegister(uint16_t data) {
    // NSS low
    AD9834_NSS_PORT->BRR = AD9834_NSS_PIN;

    // Wait for TXE
    while (!(AD9834_SPI->SR & SPI_SR_TXE));
    AD9834_SPI->DR = (data >> 8) & 0xFF;

    while (!(AD9834_SPI->SR & SPI_SR_TXE));
    AD9834_SPI->DR = data & 0xFF;

    while (!(AD9834_SPI->SR & SPI_SR_RXNE));
    (void)AD9834_SPI->DR;

    // NSS high
    while (AD9834_SPI->SR & SPI_SR_BSY);
    AD9834_NSS_PORT->BSRR = AD9834_NSS_PIN;

    AD9834_Delay();
}

void AD9834_SetFrequency(uint32_t frequency) {
    uint32_t freq_word = (uint32_t)((frequency * 268435456.0) / 25000000.0); // assuming 25 MHz MCLK

    uint16_t lsb = 0x4000 | (freq_word & 0x3FFF);
    uint16_t msb = 0x4000 | ((freq_word >> 14) & 0x3FFF);

    AD9834_WriteRegister(0x2100); // RESET enabled
    AD9834_WriteRegister(lsb);
    AD9834_WriteRegister(msb);
    AD9834_WriteRegister(0x2000); // Clear RESET
}

// Mode select
void AD9834_SetSineWave(void) {
    AD9834_WriteRegister(0x2000);
}

void AD9834_SetSquareWave(void) {
    AD9834_WriteRegister(0x2028);
}

void AD9834_SetTriangleWave(void) {
    AD9834_WriteRegister(0x2002);
}



