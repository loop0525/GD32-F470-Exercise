#ifndef _HW_SPI_H
#define _HW_SPI_H

#include "gd32f4xx.h"                   // Device header
#include "stdio.h" 

void HW_SPI_Init(void);
uint8_t HW_SPI_Exchange(uint8_t dat);

void HW_SPI_Test(void);

#endif




