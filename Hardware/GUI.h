#ifndef _GUI_H
#define _GUI_H

#include "gd32f4xx.h"
#include "systick.h"


#define COLOR_GOLDEN   (0XFEA0)
#define COLOR_SILVER   (0XC618)
#define COLOR_BRONZE   (0XBB86)
#define COLOR_WHITE   (0xFFFF)
#define COLOR_BLACK   (0x0000)
#define COLOR_BLUE    (0x001F)
#define COLOR_BRED    (0XF81F)
#define COLOR_GRED    (0XFFE0)
#define COLOR_GBLUE   (0X07FF)
#define COLOR_RED     (0xF800)
#define COLOR_MAGENTA (0xF81F)
#define COLOR_GREEN   (0x07E0)
#define COLOR_CYAN    (0x7FFF)
#define COLOR_YELLOW  (0xFFE0)
#define COLOR_BROWN   (0XBC40)     
#define COLOR_BRRED   (0XFC07)    
#define COLOR_GRAY    (0X8430)    
#define COLOR_DARKBLUE (0X01CF) 
#define COLOR_LIGHTBLUE (0X7D7C)  
#define COLOR_GRAYBLUE (0X5458) 
#define COLOR_LIGHTGREEN (0X841F) 
#define COLOR_LGRAY (0XC618)     
#define COLOR_LGRAYBLUE (0XA651)  
#define COLOR_LBBLUE (0X2B12)    

void LCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t color);//指定区域填充颜色
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t color);//指定位置画点
void LCD_DrawLine(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color);//指定位置画线
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint16_t color);//指定位置画矩形
void Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r,uint16_t color);//指定位置画圆

void LCD_ShowChinese(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);//显示汉字串
void LCD_ShowChinese12x12(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);//显示汉字12x12
void LCD_ShowChinese16x16(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);//显示汉字16x16
void LCD_ShowChinese24x24(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);//显示汉字24x24
void LCD_ShowChinese32x32(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);//显示汉字32x32

void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);//显示一个字符
void LCD_ShowString(uint16_t x,uint16_t y,const uint8_t *p,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);//显示字符串
uint32_t mypow(uint8_t m,uint8_t n);//求幂
void LCD_ShowIntNum(uint16_t x,uint16_t y,uint16_t num,uint8_t len,uint16_t fc,uint16_t bc,uint8_t sizey);//显示整数变量
void LCD_ShowFloatNum1(uint16_t x,uint16_t y,float num,uint8_t len,uint16_t fc,uint16_t bc,uint8_t sizey);//显示两位小数变量

void LCD_ShowPicture(uint16_t x,uint16_t y,uint16_t length,uint16_t width,const uint8_t pic[]);//显示图片


void DrawEclipsePoint(uint16_t x0, uint16_t y0,uint16_t x,uint16_t y,uint16_t color);
void MiddlePiontEclipse(uint16_t x0,uint16_t y0,uint16_t a,uint16_t b,uint16_t color);
void Draw_Solid_Circle(uint16_t x, uint16_t y, uint16_t  r,uint16_t color);


#endif




