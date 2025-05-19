/*
 * SI5351.c
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#include "SI5351.h"


#define SI_REG_CRYSTAL_LOAD     183
#define SI_REG_OUTPUT_ENABLE    3
#define SI_REG_CLK0_CTRL        16
#define SI_REG_PLLA             26
#define SI_REG_MULTISYNTH0      42

static bool SI_WriteReg(uint8_t reg, uint8_t val) {
    if (!I2C_Start(SI5351_I2C_ADDR, false)) return false;
    I2C_Write(reg);
    I2C_Write(val);
    I2C_Stop();
    return true;
}

bool SI5351_Init(void) {

    if (!SI_WriteReg(SI_REG_CRYSTAL_LOAD, 0b11010010)) return false;

    if (!SI_WriteReg(SI_REG_OUTPUT_ENABLE, 0xFF)) return false;


    for (uint8_t n = 0; n < 3; n++) {

        if (!SI_WriteReg(SI_REG_CLK0_CTRL + n, (1 << 7))) return false;
    }

    delay_ms(10);
    return true;
}

bool SI5351_SetFreq(uint8_t output_n, uint32_t freq_Hz) {

    uint8_t reg = SI_REG_CLK0_CTRL + output_n;

    uint8_t val = (0 << 7);
    return SI_WriteReg(reg, val);
}

bool SI5351_EnableOutput(uint8_t output_n, bool enable) {
    uint8_t mask = (1 << output_n);

    uint8_t cur = 0;
    if (!SI5351_ReadReg(SI_REG_OUTPUT_ENABLE, &cur)) return false;
    if (enable) cur &= ~mask;
    else        cur |= mask;
    return SI_WriteReg(SI_REG_OUTPUT_ENABLE, cur);
}


bool SI5351_ReadReg(uint8_t reg, uint8_t *data) {
    if (!I2C_Start(SI5351_I2C_ADDR, false)) return false;
    I2C_Write(reg);
    if (!I2C_Start(SI5351_I2C_ADDR, true)) return false;
    *data = I2C_Read(false);
    I2C_Stop();
    return true;
}
