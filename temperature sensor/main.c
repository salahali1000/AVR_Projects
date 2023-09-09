/*
 * temperature_sensor.c
 *
 * Created: 4/19/2023 12:14:01 AM
 *  Author: salah
 */ 


//#include <avr/io.h>
#include "LCD.h"
#include "ADC.h"
#include "STD_TYPES.h"
int main(void)
{
	u8 temperatue;
	u16 value;
	u32 voltage;
	f32 step=(2.65/1024);
	LCD_VINT('D');
	ADC_INIT();
	LCD_VSEND_STRING('D',"temperature=");
    while(1)
    {
         value=ADC_U16READ();
		 voltage=value*step*1000;
		 temperatue=voltage/10;
		 if(temperatue<10)
		 {
			 LCD_VMOVE_CURSOR(1,13);
			 LCD_VSEND_CHAR('D',temperatue+48);
			 LCD_VSEND_CHAR('D',0xdf);
			 LCD_VSEND_CHAR('D','C');
			 LCD_VSEND_CHAR('D',0x20);
		 }
		 else if(temperatue>=10)
		 {
			 LCD_VMOVE_CURSOR(1,13);
			 LCD_VSEND_CHAR('D',(temperatue/10)+48);
			 LCD_VSEND_CHAR('D',(temperatue%10)+48);
			 LCD_VSEND_CHAR('D',0xdf);
			 LCD_VSEND_CHAR('D','C');
		 }
		 
    }
}
