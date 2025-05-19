/*
 * NSS.h
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */
#ifndef NSS_CONTROL_H
#define NSS_CONTROL_H

#include "stm32c0xx.h"
#include <stdint.h>
#include <stdbool.h>
//  SPI-CS pins
#define MAX5712_NSS_PORT   GPIOB
#define MAX5712_NSS_PIN    9

#define AD9834_NSS_PORT    GPIOB
#define AD9834_NSS_PIN     8

#define ADF4351_NSS_PORT   GPIOB
#define ADF4351_NSS_PIN    4

#define AD9959_NSS_PORT    GPIOA
#define AD9959_NSS_PIN     4

#define RFFC5071_NSS_PORT  GPIOB
#define RFFC5071_NSS_PIN   0

// configure each CS pin individually
#define INIT_NSS_PIN(port, pin)       \
  do {                                \
    (port)->MODER &= ~(3U << (pin*2));\
    (port)->MODER |=  (1U << (pin*2));/* output */ \
    (port)->OTYPER &= ~(1U << pin);   /* push-pull */ \
    (port)->OSPEEDR |= (3U << (pin*2));/* high speed */\
    (port)->PUPDR &= ~(3U << (pin*2)); /* no pull */   \
    (port)->BSRR   =  (1U << (pin));   /* set HIGH */  \
  } while(0)

// global CS initialization (enable clock for each port here)
void NSS_LowLevel_Init(void);

// select/deselect functions for each chip
void MAX5712_Select(void);   void MAX5712_Deselect(void);
void AD9834_Select(void);    void AD9834_Deselect(void);
void ADF4351_Select(void);   void ADF4351_Deselect(void);
void AD9959_Select(void);    void AD9959_Deselect(void);
void RFFC5071_Select(void);  void RFFC5071_Deselect(void);

#endif // NSS_CONTROL_H
