#include "i2c.h"

void I2C_Init()
{
	rcu_periph_clock_enable(RCU_GPIOC);
	
	gpio_mode_set(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_8 | GPIO_PIN_9);
	gpio_output_options_set(GPIOC, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, GPIO_PIN_8 | GPIO_PIN_9);
}

void I2C_Start()
{
	SDA(1);
	SCL(1);
	delay_1us(10);
	
	SDA(0);
	delay_1us(10);
	
	SCL(0);
	delay_1us(10);
}

void I2C_Stop()
{
	SCL(0);
	SDA(0);
	delay_1us(10);
	
	SCL(1);
	delay_1us(10);
	
	SDA(1);
	delay_1us(10);
}

void I2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	
	for(i=0; i<8; i++)
	{
		SDA((Byte & (0x80>>i)));
		delay_1us(10);
		
		SCL(1);
		delay_1us(10);
		
		SCL(0);
		delay_1us(10);
	}
}

uint8_t I2C_ReceiveACK()
{
	uint8_t ack;
	
	SDA(1); //释放总线
	delay_1us(10);
	
	SCL(1);
	delay_1us(10);
	ack = SDA_READ;
	
	SCL(0);
	delay_1us(10);

	if(!ack)
		return 1;
	else
		return 0;
}

uint8_t I2C_ReceiveByte()
{
	uint8_t rec=0, i;
	
	for(i=0; i<8; i++)
	{
		SCL(1);
		delay_1us(10);
		
		if(SDA_READ)
			rec |= 0x80>>i;
		
		SCL(0);
		delay_1us(10);
	}
	return rec;
}

void I2C_SendACK()
{
	SCL(0);
	SDA(0);
	delay_1us(10);
	
	SCL(1);
	delay_1us(10);
	
	SCL(0);
	delay_1us(10);
}

void I2C_SendNACK()
{
	SCL(0);
	SDA(1);
	delay_1us(10);
	
	SCL(1);
	delay_1us(10);
	
	SCL(0);
	delay_1us(10);
}


void I2C_Test()
{
	uint8_t ack, read;
	
	I2C_Init();
	
	// 写入读取寄存器地址
	I2C_Start();
	I2C_SendByte(0xD0);
	ack = I2C_ReceiveACK();
	I2C_SendByte(0x75);
	ack = I2C_ReceiveACK();
	I2C_Stop();
	// 读取寄存器值
	I2C_Start();
	I2C_SendByte(0xD1);
	ack = I2C_ReceiveACK();
	read = I2C_ReceiveByte();
	I2C_SendNACK();
	I2C_Stop();
	
	if(ack);
	
	printf("找到设备: %X \n", read);
}

