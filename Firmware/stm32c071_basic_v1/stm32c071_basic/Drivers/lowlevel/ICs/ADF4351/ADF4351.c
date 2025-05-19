/*
 * ADF4351.c
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */


#include "ADF4351.h"

// Helper: بسته‌بندی رجیستر 4 بایته
static uint32_t pack_reg(uint8_t reg, uint32_t data) {
    // هر رجیستر ADF4351: 28-bit داده <<4 | شماره رجیستر (4-bit)
    return ((data & 0x0FFFFFFF) << 4) | (reg & 0xF);
}

void ADF4351_Init(void) {
    // به عنوان مثال، فقط Reg5 را با default value 0x00580005 مقداردهی می‌کنیم
    // (بسته به نیازتان مقدار صحیح را انتخاب کنید)
    ADF4351_WriteReg(ADF4351_REG5, 0x00580005);
    delay_ms(1);
}

bool ADF4351_WriteReg(uint8_t reg, uint32_t data) {
    uint32_t w = pack_reg(reg, data);
    ADF4351_Select();
    // ارسال 4 بایت MSB-first
    SPI_TransmitByte((w >> 24) & 0xFF);
    SPI_TransmitByte((w >> 16) & 0xFF);
    SPI_TransmitByte((w >>  8) & 0xFF);
    SPI_TransmitByte((w      ) & 0xFF);
    ADF4351_Deselect();
    delay_ms(1);
    return true;
}

bool ADF4351_SetFreq(uint32_t freq_hz) {
    //Placeholder for setting frequency : implement PLL &  Multisynth math here
	//
    uint32_t ms0 = 0; // computed from freq_hz
    uint32_t pll = 0; //computed from feq_hz
    // write pll registers (Reg0 & Reg1)ا
    ADF4351_WriteReg(ADF4351_REG0, pll);
    ADF4351_WriteReg(ADF4351_REG1, pll >> 28);
    // write multisynth registers  (Reg2-Reg4)
    ADF4351_WriteReg(ADF4351_REG2, ms0);
    ADF4351_WriteReg(ADF4351_REG3, ms0 >> 28);
  //  ADF4351_WriteReg(ADF4351_REG4, ms0 >> 56);
    // Finalize with Reg5
    ADF4351_WriteReg(ADF4351_REG5, 0x00580005);
    return true;
}
