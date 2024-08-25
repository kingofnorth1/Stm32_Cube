/*
 * I2C_Init.c
 *
 *  Created on: Aug 23, 2024
 *      Author: king
 */
#include "I2C/I2C_Init.h"

void I2C_Start(void)
{
	SDA_Write(1);
	SCL_Write(1);
	SDA_Write(0);
	SCL_Write(0);
}

void I2C_End(void)
{
	SDA_Write(0);
	SCL_Write(1);
	SDA_Write(1);
}

void I2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	for (i=0;i<8;i++)
	{
		SDA_Write(Byte & (0x80>>i));
		SCL_Write(1);
		SCL_Write(0);
	}
}

uint8_t I2C_ReceiveByte(void)
{
	uint8_t i,data=0;
	SDA_Write(1);
	for(i=0;i<8;i++)
	{
		SCL_Write(1);
		if (SDA_Read()) {data |= (0x80>>i);}
		SCL_Write(0);
	}
	return data;
}

void I2C_SendAck(uint8_t AckBit)
{
	SDA_Write(AckBit);
	SCL_Write(1);
	SCL_Write(0);
}

uint8_t I2C_ReceiveAck(void)
{
	uint8_t AckBit;
	SDA_Write(1);
	SCL_Write(1);
	AckBit = SDA_Read();
	SCL_Write(0);
	return AckBit;
}

