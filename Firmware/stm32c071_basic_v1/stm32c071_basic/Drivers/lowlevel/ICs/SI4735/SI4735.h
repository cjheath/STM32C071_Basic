/*
 * SI4735.h
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#ifndef SI4735_H
#define SI4735_H

#include <stdint.h>
#include <stdbool.h>
#include "I2C.h"
#include "delay.h"

// 7-bit I2C address for SI4735
#define SI4735_I2C_ADDR   0x11

// command codes for  SI4735
#define SI_CMD_POWER_UP      0x01
#define SI_CMD_POWER_DOWN    0x11
#define SI_CMD_AM_TUNE_FREQ  0x03
#define SI_CMD_FM_TUNE_FREQ  0x20
#define SI_CMD_FM_SEARCH     0x21
#define SI_CMD_GET_STATUS    0x22

// power-up arguments for FM mode
#define SI_POWERUP_ARG1_FM   0x00  // ARG1: FM Receiver
#define SI_POWERUP_GPO2_HIGH 0x08  // ARG3: GPO2=High (optional)

// Power up the SI4735 in FMreceive mode
bool SI4735_PowerUpFM(void);

// power down the SI4735
bool SI4735_PowerDown(void);

// Tune FM to freq_khz
bool SI4735_TuneFM(uint16_t freq_khz);

//Read RSSI and tune-complete flag from SI4735
//*rssi = raw RSSI value (0-255)
//*ready = true if tune complete

bool SI4735_GetStatus(uint8_t *rssi, bool *ready);

#endif // SI4735_H
