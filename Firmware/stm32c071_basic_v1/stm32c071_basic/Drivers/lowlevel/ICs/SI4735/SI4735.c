/*
 * SI4735.c
 *
 *  Created on: May 6, 2025
 *      Author: IrBO25
 */

#include "SI4735.h"



bool SI4735_PowerUpFM(void) {
    // PowerUp: دستور 0x01 + ARG1, ARG2, ARG3
    if (!I2C_Start(SI4735_I2C_ADDR, false)) return false;
    I2C_Write(SI_CMD_POWER_UP);
    I2C_Write(SI_POWERUP_ARG1_FM);   // ARG1 = FM receiver
    I2C_Write(0x00);                 // ARG2 = no soft mute, no analog audio
    I2C_Write(SI_POWERUP_GPO2_HIGH);// ARG3 = GPO2 hi (optional)
    I2C_Stop();

    // Datasheet: up to 110 ms startup
    delay_ms(120);
    return true;
}

bool SI4735_PowerDown(void) {
    if (!I2C_Start(SI4735_I2C_ADDR, false)) return false;
    I2C_Write(SI_CMD_POWER_DOWN);
    I2C_Stop();
    delay_ms(10);
    return true;
}

bool SI4735_TuneFM(uint16_t freq_khz) {

    // ARG1–2: frequency (16-bit, MSB first)
    // ARG3: space for future (0)
    // ARG4: GPO2 drive (0)
    if (!I2C_Start(SI4735_I2C_ADDR, false)) return false;
    I2C_Write(SI_CMD_FM_TUNE_FREQ);
    I2C_Write((uint8_t)(freq_khz >> 8));
    I2C_Write((uint8_t)(freq_khz & 0xFF));
    I2C_Write(0x00);
    I2C_Write(0x00);
    I2C_Stop();

    // Datasheet : up to 60 ms to complete tune
    delay_ms(70);
    return true;
}

bool SI4735_GetStatus(uint8_t *rssi, bool *ready) {
    uint8_t resp[5];

    // 1) send GET_STATUS
    if (!I2C_Start(SI4735_I2C_ADDR, false)) return false;
    I2C_Write(SI_CMD_GET_STATUS);
    I2C_Stop();

    //Datasheet : wait 50 ms for response
    delay_ms(60);

    // 2) read 5-bit response
    if (!I2C_Start(SI4735_I2C_ADDR, true)) return false;
    for (int i = 0; i < 5; i++) {
        resp[i] = I2C_Read(i < 4);  // ACK all but the last byte
    }
    I2C_Stop();


    // resp[0]: status, resp[1]: tune_status, resp[2]: RSSI, ...
    *ready = (resp[1] & 0x80) != 0;      // resp[1] bit7 = STCINT (Seek/Tune complete)
    *rssi  = resp[2];                    //resp[2] = RSSI

    return true;
}
