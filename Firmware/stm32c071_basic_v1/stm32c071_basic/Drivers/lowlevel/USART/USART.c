/*
 * USART.c
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */
#include "stm32c0xx.h"
#include "USART.h"


// --------------------------------------------------
// Assign PA9 (TX) and PA10 (RX) to USART1 peripheral
// --------------------------------------------------
void USARTx_LowLevel_Init(uint32_t baudrate)
{
    // 1) Enable clocks for GPIOA and USART1
    USARTx_GPIO_CLK_EN();
    USARTx_CLK_EN();

    // 2)configure PA9 and PA10 to alternate function 1 (USART1)
    // set mode to AF
    USARTx_GPIO_PORT->MODER &= ~((3 << (USARTx_TX_PIN * 2)) | (3 << (USARTx_RX_PIN * 2)));
    USARTx_GPIO_PORT->MODER |=  ((2 << (USARTx_TX_PIN * 2)) | (2 << (USARTx_RX_PIN * 2)));
    // select AF1
    USARTx_GPIO_PORT->AFR[0] &= ~((0xF << ((USARTx_TX_PIN & 7)*4)) | (0xF << ((USARTx_RX_PIN & 7)*4)));
    USARTx_GPIO_PORT->AFR[0] |=  ((1 << ((USARTx_TX_PIN & 7)*4)) | (1 << ((USARTx_RX_PIN & 7)*4)));

    // 3) Disable USART while configuring
    USARTx->CR1 = 0;

    // 4) Set baud rate: BRR = FCLK / baudrate ( assume FCLK = 48 MHZ)
    USARTx->BRR = SystemCoreClock / baudrate;

    // 5) Enable USART1 transmitter, receiver , and the peripheral
    USARTx->CR1 = USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;

    // 6) we don't wait for flags here-only clock and baud setup
}

  //Transmit a single byte (blocking)
  bool USARTx_SendByte(uint8_t b)
   {
    // wait until Transmit FIFO Empty flag is set
    while (!(USARTx->ISR & USART_ISR_TXFE));
    USARTx->TDR = b & 0xFF;
    // wait until Transmission Complete flag is set
    while (!(USARTx->ISR & USART_ISR_TC));
    return true;
}

// receive a single byte (blocking)
bool USARTx_RecvByte(uint8_t *out)
{
    // wait until receive FIFO Full flag is set (data ready)
    while (!(USARTx->ISR & USART_ISR_RXFF));
    *out = (uint8_t)(USARTx->RDR & 0xFF);
    return true;
}
