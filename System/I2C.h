#ifndef _I2C_H
#define _I2C_H

#include "gd32f4xx.h"                   // Device header
#include "systick.h"
#include "stdio.h"

#define SDA_READ  gpio_input_bit_get(GPIOC, GPIO_PIN_8)

#define SDA(x)   gpio_bit_write(GPIOC, GPIO_PIN_8, (bit_status)x)
#define SCL(x)   gpio_bit_write(GPIOC, GPIO_PIN_9, (bit_status)x)


void I2C_Init(void);
void I2C_Test(void);

#endif



