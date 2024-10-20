/*
 * MAX30102.c
 *
 *  Created on: Jun 25, 2024
 *      Author: king
 */

#include "MAX30102.h"

#define ADDRESS 0xAE
#define ID 0xFF


uint8_t MAX_State(void)
{
	return MAX_Read_Byte(ID);
}

uint8_t MAX_Read_Byte(uint8_t reg)
{
	uint8_t data;
	HAL_I2C_Mem_Read(&hi2c1, ADDRESS, reg, I2C_MEMADD_SIZE_8BIT, &data, 1, HAL_MAX_DELAY);
	return data;
}

void MAX_Write_Byte(uint8_t reg, uint8_t value)
{
	HAL_I2C_Mem_Write(&hi2c1, ADDRESS, reg, I2C_MEMADD_SIZE_8BIT, &value, 1, HAL_MAX_DELAY);
}

void MAX_Init(void)
{

//	return 1;
}
