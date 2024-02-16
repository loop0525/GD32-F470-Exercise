#include "spi.h"

void SPI_Init()
{
	rcu_periph_clock_enable(RCU_GPIOF);
	
	gpio_mode_set(GPIOF, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_9);
	gpio_output_options_set(GPIOF, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_9);

	gpio_mode_set(GPIOF, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO_PIN_8);
}

void SPI_Start()
{
	CS(0);
}

void SPI_Stop()
{
	CS(1);
}

uint8_t SPI_Shift(uint8_t Byte)
{
	uint8_t rec=0, i;
	CLK(0);
	for(i=0; i<8; i++)
	{
		MOSI((Byte & (0x80>>i)));
		CLK(1);
		
		if(MISO_READ)
		{
			rec |= (0x80>>i);
		}
		
		CLK(0);
	}
	return rec;
}

void SPI_Test()
{
	uint8_t rec,rec1,rec2;
	
	SPI_Init();
	
	SPI_Start();
	
	rec = SPI_Shift(0x9F);
	rec1 = SPI_Shift(0x00);
	rec2 = SPI_Shift(0x00);
	
	SPI_Stop();
	
	printf("接收数据:%X \n", rec);
	printf("接收制造商ID:%X \n", rec1);
	printf("接收设备ID:%X \n", rec2);
}



