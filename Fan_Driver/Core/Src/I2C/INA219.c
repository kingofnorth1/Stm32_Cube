/*
 * INA219.c
 *
 *  Created on: Aug 26, 2024
 *      Author: king
 */
#include "INA219.h"

uint8_t R_Address = 0x81;
uint8_t W_Address = 0x80;

uint16_t INA219_ReadDataForRegister_16Bits(uint8_t RegAddress)
{
	uint16_t Data;

	I2C_Start();
	I2C_SendByte(W_Address);
	I2C_ReceiveAck();
	I2C_I2C_SendByte(RegAddress);
	I2C_ReceiveAck();

	I2C_Start();
	I2C_SendByte(R_Address);
	I2C_ReceiveAck();
	Data = I2C_ReceiveByte()&0xFF;
	I2C_SendAck(1);
	Data = I2C_ReceiveByte()<<8;
	I2C_SendAck(1);
	I2C_End();

	return Data;
}

void INA219_WriteDataForRegister_16Bits(uint8_t RegAddress, uint16_t Data)
{
	I2C_Start();
	I2C_SendByte(W_Address);
	I2C_ReceiveAck();
	I2C_I2C_SendByte(Data>>8);
	I2C_ReceiveAck();
	I2C_I2C_SendByte(Data&0xFF00);
	I2C_ReceiveAck();
	I2C_End();
}