/*
 * BMP280.h
 *
 *  Created on: Jun 17, 2024
 *      Author: bzah
 */

#ifndef INC_BMP280_H_
#define INC_BMP280_H_

#include "i2c.h"
#include "string.h"


#define BMP280_ADDRESS 0x76
#define temp_xlsb      0xFC
#define temp_lsb       0xFB
#define temp_msb       0xFA
#define press_xlsb     0xF9
#define press_lsb      0xF8
#define press_msb      0xF7
#define config         0xF5
#define ctrl_means     0xF4
#define State          0xF3
#define Reset          0xE0
#define Id             0xD0


void BMP280_Init();
void BMP280_RESET();
void BMP280_ReadReg(float *Temperture, float *Humidity);

#endif /* INC_BMP280_H_ */