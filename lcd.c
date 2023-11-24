

#include "lcd.h"
#include "delay.h"

void LCD_CMD(unsigned char val)
{
			LPC_GPIO0->FIOPIN=(val<<15);
	    LPC_GPIO0->FIOCLR=(1<< LCD_RS);
			LPC_GPIO0->FIOSET=(1<<LCD_EN);
			Delay(100);
			LPC_GPIO0->FIOCLR=(1<<LCD_EN);
			Delay(500);
}

void LCD_DATA(unsigned char val)
{
		  LPC_GPIO0->FIOPIN=(val<<15);		
	    LPC_GPIO0->FIOSET=(1<< LCD_RS);
	  	LPC_GPIO0->FIOSET=(1<<LCD_EN);
			Delay(100);
			LPC_GPIO0->FIOCLR=(1<<LCD_EN);
			Delay(500);
}



