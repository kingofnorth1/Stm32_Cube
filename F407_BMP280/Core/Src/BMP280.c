/*
 * BMP280.c
 *
 *  Created on: Jun 17, 2024
 *      Author: bzah
 */
#include "BMP280.h"

uint8_t BMP280_ReadID(void)
{
	uint8_t data;
	HAL_I2C_Mem_Read(&hi2c1, (BMP280_ADDRESS<<1)|0, Id, I2C_MEMADD_SIZE_8BIT, &data, 1, HAL_MAX_DELAY);
	return data;
}

uint8_t BMP280_Read_Byte(uint8_t reg)
{
	uint8_t data;
	HAL_I2C_Mem_Read(&hi2c1, (BMP280_ADDRESS<<1)|0, reg, I2C_MEMADD_SIZE_8BIT, &data, 1, HAL_MAX_DELAY);
	return data;
}

void BMP280_Write_Byte(uint8_t reg, uint8_t value)
{
	HAL_I2C_Mem_Read(&hi2c1, (BMP280_ADDRESS<<1)|0, reg, I2C_MEMADD_SIZE_8BIT, &value, 1, HAL_MAX_DELAY);
}

void BMP280_Init()
{

}

void BMP280_RESET()
{
	uint8_t Send[1] = {Reset};
	HAL_I2C_Master_Transmit(&hi2c1, (BMP280_ADDRESS<<1)|0, Send, sizeof(Send), HAL_MAX_DELAY);
}