/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/


#include "stm32c0xx.h"
#include "GPIO.h"
#include "delay.h"
#include "I2C.h"
#include "SPI.h"
#include "NSS.h"
#include "USART.h"

// IC drivers
#include "AXP209.h"
#include "SI5351.h"
#include "SI4735.h"
#include "AD9834.h"
#include "ADF4351.h"
#include "AD9959.h"
#include "RFFC5071.h"
#include "MAX5712.h"

int main(void) {
    // 1) Core & system clocks
    SystemInit();
    SystemCoreClockUpdate();

    // 2) Peripherals: GPIO, delay, buses, chip-select, UART
    GPIO_LowLevel_Init();        // configure PA5 LED, PAx… for SWD, etc.
    delay_init();                // SysTick → ms ticks
    I2C_LowLevel_Init();         // PB6=SCL, PB7=SDA
    NSS_LowLevel_Init();                  // all SPI‐CS pins
    SPI_LowLevel_Init();         // PA5=SCK, PA6=MISO, PA7=MOSI, PA4=NSS
    USARTx_LowLevel_Init(115200);// PA9=TX, PA10=RX, 115200 bps

    // 3) Initialize each device
    AXP209_Init();
    SI5351_Init();
    SI4735_PowerUpFM();
    AD9834_Init();
    ADF4351_Init();
    AD9959_Init();
    RFFC5071_Init();
    MAX5712_Init();

    // 4) Example: configure each in turn
    AXP209_WriteReg(0x10, 0x01);         // turn on LDO1
    SI5351_EnableOutput(0, true);        // enable CLK0
    SI4735_TuneFM(10110);               // tune to 101.100 MHz
    AD9834_SetFrequency(1000000);             // 1 MHz sine
    ADF4351_WriteReg(ADF4351_REG0, 0x1234567);
    AD9959_SetFreq(0, 10000000);         // 10 MHz DDS on channel 0
    RFFC5071_SetLO(100000000U);          // 100 MHz LO
    MAX5712_SetValue(0x800);             // mid-scale DAC

    // 5) Main loop: here you could parse commands over USART,
    //    or cycle through devices, or idle.
    while (1) {
        // e.g. poll status, blink LED, handle UART commands…
    }

    // (we never actually return)
    return 0;
}
