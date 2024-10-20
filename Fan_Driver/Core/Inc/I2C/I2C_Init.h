/*
 * I2C_Init.h
 *
 *  Created on: Aug 23, 2024
 *      Author: king
 */

#ifndef INC_I2C_I2C_INIT_H_
#define INC_I2C_I2C_INIT_H_


#include "stm32f1xx_hal.h"
#include "gpio.h"


//#define SDA_Write(BitValue) HAL_GPIO_WritePin(GPIOB, SDA_Pin, (GPIO_PinState)BitValue)
//#define SCL_Write(BitValue) HAL_GPIO_WritePin(GPIOB, SCL_Pin, (GPIO_PinState)BitValue)
//#define SDA_Read() HAL_GPIO_ReadPin(GPIOB, SDA_Pin)

void HAL_Delay_us(uint32_t us);
void I2C_Start(void);
void I2C_End(void);
void I2C_SendByte(uint8_t Byte);
uint8_t I2C_ReceiveByte(void);
void I2C_SendAck(uint8_t AckBit);
uint8_t I2C_ReceiveAck(void);


#endif /* INC_I2C_I2C_INIT_H_ */
