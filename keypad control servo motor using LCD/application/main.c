*
 * serco_with_keypad_and_lcd.c
 *
 * Created: 9/6/2023 4:54:32 PM
 *  Author: salah
 */ 


#include <avr/io.h>
#include "LCD.h"
#include "KEYPAD.h"
#include "timer.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	
	double degree;
	double degree1;
	LCD_VINT('A');
	KEYPAD_VINIT();
	
    while(1)
    {
		LCD_VCLR_SCREEN('A');
		LCD_VMOVE_CURSOR(1,1);
        LCD_VSEND_STRING('A',"enter the degree :");
		while(KEYPAD_VREAD()==NOT_PRESSED);
		degree = KEYPAD_VREAD() ;
		degree1=((degree-48)*100);
		LCD_VCLR_SCREEN('A');
		LCD_VSEND_CHAR('A',degree);
		_delay_ms(50);
		while(KEYPAD_VREAD()==NOT_PRESSED);
		degree = KEYPAD_VREAD() ;
		degree1+=((degree-48)*10);
		LCD_VSEND_CHAR('A',degree);
		_delay_ms(50);
		while(KEYPAD_VREAD()==NOT_PRESSED);
		degree = KEYPAD_VREAD() ;
		degree1+=(degree-48);
		LCD_VSEND_CHAR('A',degree);
		_delay_ms(30);
		
		timer1_wave_fastPWM(degree1);
    }
}
