#ifndef _SPI_H
#define _SPI_H

#include "gd32f4xx.h"                   // Device header
#include "stdio.h"

#define CS(x) gpio_bit_write(GPIOF, GPIO_PIN_6, (bit_status)x)
#define CLK(x) gpio_bit_write(GPIOF, GPIO_PIN_7, (bit_status)x)
#define MOSI(x) gpio_bit_write(GPIOF, GPIO_PIN_9, (bit_status)x)

#define MISO_READ gpio_input_bit_get(GPIOF, GPIO_PIN_8)

void SPI_Test(void);






#endif
