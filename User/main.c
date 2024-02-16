#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include <string.h>
#include "main.h"

#include "usart.h"
#include "i2c.h"
#include "spi.h"
#include "hw_spi.h"

#include "lcd.h"
#include "gui.h"

#include "loop_img.h"

int main(void)
{
    systick_config();
	
	Usart_Init();

    Lcd_Init();

    LCD_Fill(0,0,LCD_W,LCD_H,COLOR_BLACK);
	
	LCD_ShowPicture(0, 0, 240, 240, gImage_loop_img);
   

    while(1) 
    {
    }
}

