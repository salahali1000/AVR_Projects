/*
 * clock_time.c
 *
 * Created: 5/8/2023 9:34:17 PM
 *  Author: salah
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "timer.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#define F_CPU 8000000UL
u8 read, counter_hour=0,counter_minute=0,val,first_digit,second_digit;
volatile u8 counter_second=0;
int main(void)
{
	KEYPAD_VINIT();
	LCD_VINT('A');
	seven_seg_vinit('B');
	SET_BIT(DDRC,0);
	SET_BIT(DDRC,1);
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,3);
	SET_BIT(DDRC,4);
	SET_BIT(DDRC,5);
	LCD_VSEND_STRING('A',"press 1 to");
	LCD_VMOVE_CURSOR(2,1);
	LCD_VSEND_STRING('A',"set clock");
	timer2_overflow_init_interrupt();
	
	while(1)
	{
		read=KEYPAD_VREAD();
		if (read!=NOT_PRESSED)
		{
			if (read=='1')
			{
				
				LCD_VCLR_SCREEN('A');
				LCD_VSEND_STRING('A',"hours=--");
				LCD_VMOVE_CURSOR(1,7);
				_delay_ms(1600);
				do
				{
					first_digit=KEYPAD_VREAD();
					
				} while (first_digit==NOT_PRESSED);
				LCD_VSEND_CHAR('A',first_digit);
				_delay_ms(1600);
				do
				{
					second_digit=KEYPAD_VREAD();
					
				} while (second_digit==NOT_PRESSED);
				LCD_VSEND_CHAR('A',second_digit);
				_delay_ms(1600);
				counter_hour=(second_digit-48)+10*(first_digit-48);
				LCD_VCLR_SCREEN('A');;
				
				LCD_VSEND_STRING('A',"minutes=--");
				LCD_VMOVE_CURSOR(1,9);
				do
				{
					first_digit=KEYPAD_VREAD();
					
				} while (first_digit==NOT_PRESSED);
				LCD_VSEND_CHAR('A',first_digit);
				_delay_ms(1600);
				do
				{
					second_digit=KEYPAD_VREAD();
					
				} while (second_digit==NOT_PRESSED);
				LCD_VSEND_CHAR('A',second_digit);
				_delay_ms(1600);
				counter_minute=(second_digit-48)+10*(first_digit-48);
				LCD_VCLR_SCREEN('A');
				
				LCD_VSEND_STRING('A',"seconds=--");
				LCD_VMOVE_CURSOR(1,9);
				
				do
				{
					first_digit=KEYPAD_VREAD();
					
				} while (first_digit==NOT_PRESSED);
				LCD_VSEND_CHAR('A',first_digit);
				_delay_ms(1600);
				do
				{
					second_digit=KEYPAD_VREAD();
					
				} while (second_digit==NOT_PRESSED);
				LCD_VSEND_CHAR('A',second_digit);
				_delay_ms(1600);
				counter_second=(second_digit-48)+10*(first_digit-48);
				LCD_VCLR_SCREEN('A');
				LCD_VSEND_STRING('A',"press 1 to");
				LCD_VMOVE_CURSOR(2,1);
				LCD_VSEND_STRING('A',"set clock");
			}
			else
			{
				LCD_VCLR_SCREEN('A');
				LCD_VSEND_STRING('A',"wrong choice");
				_delay_ms(1000);
				LCD_VCLR_SCREEN('A');
				LCD_VSEND_STRING('A',"press 1 to");
				LCD_VMOVE_CURSOR(2,1);
				LCD_VSEND_STRING('A',"set clock");
			}
		}
		
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,0);
		seven_seg_write('B',counter_second%10);
		_delay_ms(5);
		
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,1);
		seven_seg_write('B',counter_second/10);
		_delay_ms(5);
		
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,2);
		seven_seg_write('B',counter_minute%10);
		_delay_ms(5);
		
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,3);
		seven_seg_write('B',counter_minute/10);
		_delay_ms(5);
		
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,4);
		seven_seg_write('B',counter_hour%10);
		_delay_ms(5);
		
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		CLR_BIT(PORTC,5);
		seven_seg_write('B',counter_hour/10);
		_delay_ms(5);
		
		if (counter_second==60)
		{
			counter_second=0;
			counter_minute++;
		}
		if (counter_minute==60)
		{
			counter_minute=0;
			counter_hour++;
		}
		if (counter_hour==24)
		{
			counter_hour=0;
		}
	}
	
}

ISR(TIMER2_OVF_vect)
{
	counter_second++;
	
}

