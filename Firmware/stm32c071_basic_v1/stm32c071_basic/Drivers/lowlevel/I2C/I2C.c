/*
 * I2C.c
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#include "stm32c0xx.h"
#include "I2C.h"

#define I2C_PORT I2C1

void I2C_LowLevel_Init(void) {
    RCC->IOPENR   |= RCC_IOPENR_GPIOBEN;
    RCC->APBENR1  |= RCC_APBENR1_I2C1EN;

    // Configure PB6 (SCL) and PB7 (SDA) as alternate function AF6
    GPIOB->MODER   &= ~((3U << (6 * 2)) | (3U << (7 * 2)));
    GPIOB->MODER   |=  ((2U << (6 * 2)) | (2U << (7 * 2)));  // AF mode
    GPIOB->AFR[0]  &= ~((0xFU << (6 * 4)) | (0xFU << (7 * 4)));
    GPIOB->AFR[0]  |=  ((6U << (6 * 4)) | (6U << (7 * 4)));  // AF6 = I2C1
    GPIOB->OTYPER  |=  (1U << 6) | (1U << 7);               // Open-drain
    GPIOB->PUPDR   |=  (1U << (6 * 2)) | (1U << (7 * 2));   // Pull-up

    I2C_PORT->CR1   &= ~I2C_CR1_PE;  // Disable before config
    I2C_PORT->TIMINGR = 0x00303D5B;  // 400 kHz (example)
    I2C_PORT->CR1   |= I2C_CR1_PE;   // Enable I2C
}

bool I2C_Start(uint8_t address, bool read) {
    I2C_PORT->CR2 = (address << 1) |
                    (read ? I2C_CR2_RD_WRN : 0) |
                    (1U << 16);  // 1 byte
    I2C_PORT->CR2 |= I2C_CR2_START;

    while (!(I2C_PORT->ISR & (read ? I2C_ISR_RXNE : I2C_ISR_TXIS)) &&
           !(I2C_PORT->ISR & I2C_ISR_NACKF));

    return !(I2C_PORT->ISR & I2C_ISR_NACKF);
}

bool I2C_Write(uint8_t data) {
    I2C_PORT->TXDR = data;
    while (!(I2C_PORT->ISR & I2C_ISR_TXE));
    return true;
}

uint8_t I2C_Read(bool ack) {
    if (ack)
        I2C_PORT->CR2 &= ~I2C_CR2_NACK;
    else
        I2C_PORT->CR2 |= I2C_CR2_NACK;

    while (!(I2C_PORT->ISR & I2C_ISR_RXNE));
    return (uint8_t)I2C_PORT->RXDR;
}

void I2C_Stop(void) {
    I2C_PORT->CR2 |= I2C_CR2_STOP;
    while (I2C_PORT->CR2 & I2C_CR2_STOP);  // Wait for stop to clear
}
