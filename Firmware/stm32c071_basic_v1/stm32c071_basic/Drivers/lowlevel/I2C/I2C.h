/*
 * I2C.h
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#ifndef I2C_LOWLEVEL_H
#define I2C_LOWLEVEL_H

#include "stm32c0xx.h"

#include<stdint.h>
#include <stdbool.h>
void I2C_LowLevel_Init(void);

bool I2C_Start(uint8_t address,bool read);
bool I2C_Write(uint8_t data); // send data
uint8_t I2C_Read(bool ack); //receive data
void I2C_Stop(void); //send stop

#endif
