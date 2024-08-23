/*
 * I2C_Init.h
 *
 *  Created on: Aug 23, 2024
 *      Author: king
 */

#ifndef INC_I2C_I2C_INIT_H_
#define INC_I2C_I2C_INIT_H_


#include "stm32f1xx_hal.h"


#define SDA_Clr() HAL_GPIO_WritePin(GPIOB, SDA_Pin, GPIO_PIN_SET);
#define SDA_Set() HAL_GPIO_WritePin(GPIOB, SDA_Pin, GPIO_PIN_RESET);

#define SCL_Clr() HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_SET);
#define SCL_Set() HAL_GPIO_WritePin(GPIOB, SCL_Pin, GPIO_PIN_RESET);



void I2C_Start(void);
void I2C_End(void);
void I2C_SendByte(uint8_t Byte);
uint8_t I2C_ReceiveByte(void);
void I2C_SendAck(void);
uint8_t I2C_ReceiveAck(void);


#endif /* INC_I2C_I2C_INIT_H_ */