/*
 * aht20.c
 *
 *  Created on: Jun 12, 2024
 *      Author: bzah
 */

#include <sht30.h>

#define SHT30 0x44
#define SingleMSB 0x2C
#define SingleLSB 0x06
#define CycleMSB 0x21
#define CycleLSB 0x30

void SHT30_Init()
{
	uint8_t Cycle[2];
	Cycle[0] = CycleMSB;
	Cycle[1] = CycleLSB;
    HAL_I2C_Master_Transmit(&hi2c1, (SHT30<<1)|0, Cycle, 2, HAL_MAX_DELAY);
}

void SHT30_RepeatReadReg(float* temperture, float* huminess)
{
    uint32_t data;
    uint8_t buff[6];

    HAL_I2C_Master_Receive(&hi2c1, (SHT30<<1)|1, buff, 6, HAL_MAX_DELAY);

    data = ((uint32_t)buff[0] << 8) + (uint32_t)buff[1];
    *temperture = 175.0 * ((float)data / (65536-1)) - 45;

    data = ((uint32_t)buff[3] << 8) + (uint32_t)buff[4];
    *huminess = 100.0 * ((float)data / (65536-1));
}
