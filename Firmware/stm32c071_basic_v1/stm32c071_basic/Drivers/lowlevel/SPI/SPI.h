/*
 * SPI.h
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#ifndef SPI_LOWLEVEL_H
#define SPI_LOWLEVEL_H

#include "stm32c0xx.h"
#include <stdint.h>
#include <stdbool.h>

//pins for SPI1:
//   SCK  = PA5 (AF0)
//   MISO = PA6 (AF0)
//   MOSI = PA7 (AF0)
//   NSS  = PA4 (GPIO output)

void SPI_LowLevel_Init(void);

// software-based NSS (chip-select) control
void SPI_CS_Enable(void);
void SPI_CS_Disable(void);

// transmit/receive byte
void SPI_TransmitByte(uint8_t data);
uint8_t SPI_ReceiveByte(void);

// transmit/receive 16 byte
void SPI_Transmit16(uint16_t data);
uint16_t SPI_Receive16(void);

// transmit/receive 24byte
void SPI_Transmit24(uint32_t data);
uint32_t SPI_Receive24(void);

#endif // SPI_LOWLEVEL_H
