/*
 * traffic_light.c
 *
 * Created: 4/29/2023 7:28:35 PM
 *  Author: salah
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "BIT_MATH.h"
#include "LCD.h"
#include "LED.h"
volatile unsigned long counter0=0;
unsigned char flag1=10;
unsigned char flag2=7;
unsigned char flag3=5;
int main(void)
{
	Timer_VCTCInat(80);
	LED_VINAT('D',0);
	LED_VINAT('D',1);
	LED_VINAT('D',2);
	LCD_VINT('A');
    while(1)
    {
		flag1=10;
		flag2=7;
		flag3=5;
		LCD_VCLR_SCREEN('A');
		LCD_VSEND_STRING('A',"remaining 10 sec");
		LED_VON('D',0);
		while(flag1>0)
		{
			if(counter0>=100)
			{
				flag1--;
				LCD_VMOVE_CURSOR(1,11);
				LCD_VSEND_CHAR('A',32);
				LCD_VMOVE_CURSOR(1,12);
				LCD_VSEND_CHAR('A',flag1+48);
				counter0=0;
			}
		}
		LED_VOFF('D',0);
		LCD_VMOVE_CURSOR(1,1);
		LCD_VSEND_STRING('A',"remaining 7 sec");
		LED_VON('D',1);
		while(flag2>0)
		{
			if(counter0>=100)
			{
				flag2--;
				LCD_VMOVE_CURSOR(1,11);
				LCD_VSEND_CHAR('A',flag2+48);
				counter0=0;
			}
		}
		LED_VOFF('D',1);
		LCD_VMOVE_CURSOR(1,1);
		LCD_VSEND_STRING('A',"remaining 5 sec");
		LED_VON('D',2);
		while(flag3>0)
		{
			if(counter0>=100)
			{
				flag3--;
				LCD_VMOVE_CURSOR(1,11);
				LCD_VSEND_CHAR('A',flag3+48);
				counter0=0;
			}
		}
		LED_VOFF('D',2);
									   
	}
}	

ISR(TIMER0_COMP_vect)
{
	counter0++;
}
