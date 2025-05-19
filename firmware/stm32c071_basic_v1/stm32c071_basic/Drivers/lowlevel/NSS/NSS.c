/*
 * NSS.c
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#include "NSS.h"

void NSS_LowLevel_Init(void) {
    // 1) active clock for GPIOA, GPIOB و GPIOC
    RCC->IOPENR |= RCC_IOPENR_GPIOAEN
                 | RCC_IOPENR_GPIOBEN
                 | RCC_IOPENR_GPIOCEN;

    // 2) Initialize all NSS pins one by one
    INIT_NSS_PIN(MAX5712_NSS_PORT, MAX5712_NSS_PIN);
    INIT_NSS_PIN(AD9834_NSS_PORT,  AD9834_NSS_PIN);
    INIT_NSS_PIN(ADF4351_NSS_PORT, ADF4351_NSS_PIN);
    INIT_NSS_PIN(AD9959_NSS_PORT,  AD9959_NSS_PIN);
    INIT_NSS_PIN(RFFC5071_NSS_PORT,RFFC5071_NSS_PIN);
}

//Assert (drive low) or deassert (drive high) each chip-select
void MAX5712_Select(void)   { MAX5712_NSS_PORT->BSRR = (1U << (MAX5712_NSS_PIN + 16)); }
void MAX5712_Deselect(void) { MAX5712_NSS_PORT->BSRR = (1U <<  MAX5712_NSS_PIN   ); }

void AD9834_Select(void)    { AD9834_NSS_PORT->BSRR  = (1U << (AD9834_NSS_PIN + 16)); }
void AD9834_Deselect(void)  { AD9834_NSS_PORT->BSRR  = (1U <<  AD9834_NSS_PIN   ); }

void ADF4351_Select(void)   { ADF4351_NSS_PORT->BSRR = (1U << (ADF4351_NSS_PIN + 16)); }
void ADF4351_Deselect(void) { ADF4351_NSS_PORT->BSRR = (1U <<  ADF4351_NSS_PIN  ); }

void AD9959_Select(void)    { AD9959_NSS_PORT->BSRR  = (1U << (AD9959_NSS_PIN + 16)); }
void AD9959_Deselect(void)  { AD9959_NSS_PORT->BSRR  = (1U <<  AD9959_NSS_PIN   ); }

void RFFC5071_Select(void)  { RFFC5071_NSS_PORT->BSRR= (1U << (RFFC5071_NSS_PIN + 16)); }
void RFFC5071_Deselect(void){ RFFC5071_NSS_PORT->BSRR= (1U <<  RFFC5071_NSS_PIN);    }
