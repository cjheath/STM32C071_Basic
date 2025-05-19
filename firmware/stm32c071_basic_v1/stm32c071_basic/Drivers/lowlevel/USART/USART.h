/*
 * USART.h
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */
#ifndef LOWLEVEL_USART_USART_H_
#define LOWLEVEL_USART_USART_H_

#include <stdint.h>
#include <stdbool.h>
#include "stm32c0xx.h"  // CMSIS core definitions

//GPIO port & pins for TX and RXا
#define USARTx                USART1
#define USARTx_CLK_EN()       (RCC->APBENR2 |= RCC_APBENR2_USART1EN)
#define USARTx_TX_PIN         9
#define USARTx_RX_PIN         10
#define USARTx_GPIO_PORT      GPIOA
#define USARTx_GPIO_CLK_EN()  (RCC->IOPENR |= RCC_IOPENR_GPIOAEN)


void USARTx_LowLevel_Init(uint32_t baudrate);  //Initialize USART1 at given baud rate
bool USARTx_SendByte(uint8_t b);              //Transmit a single byte (blocking)
bool USARTx_RecvByte(uint8_t *out);          //Receive a single byte (blocking)

#endif  // LOWLEVEL_USART_USART_H_
