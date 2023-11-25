#include<lpc17xx.h>
#include "lcd.h"
#include "delay.h"
#include "uart.h"
int main()
{
	  unsigned char CMD[5]={0x38,0x0E,0x06,0x01,0x80};
    unsigned char MSG[]="KATTA PRATHIBA";
		unsigned int i;
  unsigned char UartMsg[]="RAJU TECHNOLOGIES";

		LPC_PINCON->PINSEL0=0x00000000;
		LPC_PINCON->PINSEL1=0x00000000;
  	LPC_GPIO0->FIODIR=0x007F8C00;
		for(i=0 ; i<5; i++)
	  {
				LCD_CMD(CMD[i]);
			  Delay(500);
		}
		for(i=0 ; MSG[i]!='\0'; i++)
	  {
				LCD_DATA(MSG[i]);
				Delay(500);
		}
		while(1)
		{
			
			
			for(i=0;UartMsg[i] != '\0';i++)  //transmit a predefined string
        UartTxChar(UartMsg[i]);
				
		}
		

}
