/*
 * SPI.c
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#include "SPI.h"

// simple access alias for SPI1
#define SPIx      SPI1
#define SPI_CLK() (RCC->APBENR2 |= RCC_APBENR2_SPI1EN)

// Pins PA4...PA7 on port A
#define GPIOA_CLK()  (RCC->IOPENR |= RCC_IOPENR_GPIOAEN)
#define PIN_SCK      5
#define PIN_MISO     6
#define PIN_MOSI     7
#define PIN_NSS      4

void SPI_LowLevel_Init(void) {

    GPIOA_CLK();
    SPI_CLK();


    // PA5, PA6, PA7 → AF mode
    GPIOA->MODER &= ~((3U<<(PIN_SCK*2)) | (3U<<(PIN_MISO*2)) | (3U<<(PIN_MOSI*2)));
    GPIOA->MODER |=  ((2U<<(PIN_SCK*2)) | (2U<<(PIN_MISO*2)) | (2U<<(PIN_MOSI*2)));
    // AFR0
    GPIOA->AFR[0] &= ~((0xFU<<(PIN_SCK*4)) | (0xFU<<(PIN_MISO*4)) | (0xFU<<(PIN_MOSI*4)));
    // AF0 = SPI1


    // 3) Configure PA4 as general-purpose output for software NSS

    GPIOA->MODER &= ~(3U<<(PIN_NSS*2));
    GPIOA->MODER |=  (1U<<(PIN_NSS*2));      // General purpose output
    GPIOA->OTYPER &= ~(1U<<PIN_NSS);         // Push-pull
    GPIOA->OSPEEDR |=  (3U<<(PIN_NSS*2));    // High speed
    GPIOA->PUPDR &= ~(3U<<(PIN_NSS*2));      // No pull
    GPIOA->ODR |=   (1U<<PIN_NSS);           // NSS = HIGH (inactive)

    // 4) Configure and enable SPI1 :
    // Master mode , Baudrate PCLK/8, CPOL=0, CPHA=0, 8-bit, SSI/SSM
    SPIx->CR1 = SPI_CR1_MSTR |
                SPI_CR1_SSI |
                SPI_CR1_SSM |
                (2U << SPI_CR1_BR_Pos);  // BR = 2 → fPCLK/8
    SPIx->CR1 |= SPI_CR1_SPE;              // Enable SPI
}
//Assert NSS (chip-select low)
void SPI_CS_Enable(void) {
    GPIOA->ODR &= ~(1U<<PIN_NSS);  // NSS = 0
}
// Deassert NSS (chip-select high)
void SPI_CS_Disable(void) {
    GPIOA->ODR |=  (1U<<PIN_NSS);  // NSS = 1
}
// Transmit one byte over SPI (blocking)
void SPI_TransmitByte(uint8_t data) {
    while (!(SPIx->SR & SPI_SR_TXE)); // wait until TX buffer is empty
    SPIx->DR = data;
    while (!(SPIx->SR & SPI_SR_RXNE)); // wait until RX buffer has data
    (void)SPIx->DR;  // Clear RX
}
// Receive one byte over SPI (blocking)
uint8_t SPI_ReceiveByte(void) {
    SPIx->DR = 0xFF;  //  send Dummy byte
    while (!(SPIx->SR & SPI_SR_RXNE)); // wait until data arrives
    return (uint8_t)SPIx->DR;
}
// Trnsmit 16 bits (MSB first)
void SPI_Transmit16(uint16_t data) {
    SPI_TransmitByte((uint8_t)(data >> 8));
    SPI_TransmitByte((uint8_t)(data & 0xFF));
}
//Receive 16 bits (MSB first)
uint16_t SPI_Receive16(void) {
    uint16_t hi = (uint16_t)SPI_ReceiveByte() << 8;
    uint16_t lo = (uint16_t)SPI_ReceiveByte();
    return (hi | lo);
}
// Trnsmit 24 bits (MSB first)
void SPI_Transmit24(uint32_t data) {
    SPI_TransmitByte((uint8_t)(data >> 16));
    SPI_TransmitByte((uint8_t)(data >>  8));
    SPI_TransmitByte((uint8_t)(data       ));
}
// Receive 24 bits (MSB first)
uint32_t SPI_Receive24(void) {
    uint32_t b1 = (uint32_t)SPI_ReceiveByte() << 16;
    uint32_t b2 = (uint32_t)SPI_ReceiveByte() << 8;
    uint32_t b3 = (uint32_t)SPI_ReceiveByte();
    return (b1 | b2 | b3);
}

