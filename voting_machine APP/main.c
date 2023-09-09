/*
 * voting_machine.c
 *
 * Created: 3/16/2023 3:20:08 PM
 *  Author: salah
 */ 


//#include <avr/io.h>
#include "LCD.h"
#include "switch.h"
#include "DIO.h"
#include "STD_TYPES.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	u8 read,c1=48,c2=48,c3=48,c4=48;
	LCD_VINT(PORTA_DIO);
	SWITCH_VINIT(PORTB_DIO,PB3);
	SWITCH_VINIT(PORTB_DIO,PB4);
	SWITCH_VINIT(PORTB_DIO,PB5);
	SWITCH_VINIT(PORTB_DIO,PB6);
	SWITCH_VINIT(PORTB_DIO,PB7);
	LCD_VSEND_STRING(PORTA_DIO,"A=0");
	LCD_VMOVE_CURSOR(1,12);
	LCD_VSEND_STRING(PORTA_DIO,"B=0");
	LCD_VMOVE_CURSOR(2,1);
	LCD_VSEND_STRING(PORTA_DIO,"C=0");
	LCD_VMOVE_CURSOR(2,12);
	LCD_VSEND_STRING(PORTA_DIO,"D=0");
    while(1)
    {
		if(SWITCH_u8Read(PORTB_DIO,PB3)==high)
		{
			_delay_ms(250);
			LCD_VMOVE_CURSOR(1,3);
			c1++;
			LCD_VSEND_CHAR(PORTA_DIO,c1);
		} 
		else if(SWITCH_u8Read(PORTB_DIO,PB4)==high)
		{
			_delay_ms(250);
			LCD_VMOVE_CURSOR(1,14);
			c2++;
			LCD_VSEND_CHAR(PORTA_DIO,c2);
		}
		else if(SWITCH_u8Read(PORTB_DIO,PB5)==high)
		{
			_delay_ms(250);
			LCD_VMOVE_CURSOR(2,3);
			c3++;
			LCD_VSEND_CHAR(PORTA_DIO,c3);
		}
		else if(SWITCH_u8Read(PORTB_DIO,PB6)==high)
		{
			_delay_ms(250);
			LCD_VMOVE_CURSOR(2,14);
			c4++;
			LCD_VSEND_CHAR(PORTA_DIO,c4);
		}
		else if(SWITCH_u8Read(PORTB_DIO,PB7)==high)
		{
			_delay_ms(250);;
			c1=48;
			c2=48;
			c3=48;
			c4=48;
			LCD_VMOVE_CURSOR(1,3);
			LCD_VSEND_CHAR(PORTA_DIO,c1);
			LCD_VMOVE_CURSOR(1,14);
			LCD_VSEND_CHAR(PORTA_DIO,c2);
			LCD_VMOVE_CURSOR(2,3);
			LCD_VSEND_CHAR(PORTA_DIO,c3);
			LCD_VMOVE_CURSOR(2,14);
			LCD_VSEND_CHAR(PORTA_DIO,c4);
		}						
    }
}
