/*
 * DC_motor_with_LCD.c
 *
 * Created: 9/6/2023 2:36:56 PM
 *  Author: salah
 */ 


#include <avr/io.h>
#include "LCD.h"
#include "switch.h"
#include "DCMotor.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	LCD_VINT('A');
	SWITCH_VINIT('A',0);
	SWITCH_VINIT('C',0);
	
    while(1)
    {
		unsigned char read1 = SWITCH_u8Read('A',0);
		unsigned char read2 = SWITCH_u8Read('C',0);
         if(read1==1)
		 {
			 LCD_VCLR_SCREEN('A');
			 LCD_VMOVE_CURSOR(1,1);
			 LCD_VSEND_STRING('A',"clock wise");
			 DC_Motor_Clockwise('D');
			_delay_ms(150);
		 }			
		 
		 if(read2==1)
		 {
			 LCD_VCLR_SCREEN('A');
			 LCD_VMOVE_CURSOR(1,1);
			 LCD_VSEND_STRING('A',"Anti clock wise");
			DC_Motor_AntiClockwise('D');
			_delay_ms(150);
				
		 } 
		 
		
		 }		 		 
}
