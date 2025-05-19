/*
 * AXP209.c
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#include "AXP209.h"

bool AXP209_Init(void) {
    // Example init :turn on LDO1 (register 0x10, bit 0)
    return AXP209_WriteReg(0x10, 0x01);
}

bool AXP209_WriteReg(uint8_t reg, uint8_t data) {
    if (!I2C_Start(AXP209_I2C_ADDR, false)) return false;
    I2C_Write(reg);
    I2C_Write(data);
    I2C_Stop();
    delay_ms(10);
    return true;
}

bool AXP209_ReadReg(uint8_t reg, uint8_t *data) {
    if (!I2C_Start(AXP209_I2C_ADDR, false)) return false;
    I2C_Write(reg);
    if (!I2C_Start(AXP209_I2C_ADDR, true)) return false;
    *data = I2C_Read(false);
    I2C_Stop();
    return true;
}
