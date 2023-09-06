/*
 * LCD.c
 *
 * Created: 3/2/2023 5:14:02 PM
 *  Author: salah
 */ 
#include "DIO.h"
#include "STD_TYPES.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#define FOUR_BIT_MODE
void LCD_VINT(u8 port_name)
{
	#if defined EIGHT_BIT_MODE
	_delay_ms(200); 
	DIO_VSetPortDir(port_name,0xff);
	DIO_set_vPinDir('B',RW,output);
	DIO_set_vPinDir('B',RS,output);
	DIO_set_vPinDir('B',EN,output);
	DIO_SET_VPinVal('B',RW,low);
	LCD_VSEND_CMD(port_name,EIGHT_bits);
	_delay_ms(1);
	LCD_VSEND_CMD(port_name,CURSOR_ON_DISPLAY_ON);
	_delay_ms(5);
	LCD_VSEND_CMD(port_name,CLR_SCREEN);
	_delay_ms(10);
	LCD_VSEND_CMD(port_name,ENTRY_MODE); 
	
	#elif defined FOUR_BIT_MODE
	_delay_ms(200);
	DIO_set_vPinDir(port_name,PIN4,output);
	DIO_set_vPinDir(port_name,PIN5,output);
	DIO_set_vPinDir(port_name,PIN6,output);
	DIO_set_vPinDir(port_name,PIN7,output);
	DIO_set_vPinDir('B',RW,output);
	DIO_set_vPinDir('B',RS,output);
	DIO_set_vPinDir('B',EN,output);
	DIO_SET_VPinVal('B',RW,low);
	LCD_VSEND_CMD(port_name,RETURN_HOME);
	_delay_ms(10);
	LCD_VSEND_CMD(port_name,FOUR_bits);
	_delay_ms(1);
	LCD_VSEND_CMD(port_name,CURSOR_ON_DISPLAY_ON);
	_delay_ms(5);
	LCD_VSEND_CMD(port_name,CLR_SCREEN);
	_delay_ms(10);
	LCD_VSEND_CMD(port_name,ENTRY_MODE);
	#endif
}
void LCD_VSEND_CHAR(u8 port_name,u8 data)
{
	#if defined EIGHT_BIT_MODE
	DIO_SET_VPinVal('B',RS,high);
	DIO_VSetPortVal(port_name,data);
	SET_VPULSE('B',EN);
	
	#elif defined FOUR_BIT_MODE
	DIO_SET_VPinVal('B',RS,high);
	WRITE_VHIGH_NIBBLE(port_name,data>>4);
	SET_VPULSE('B',EN);
	WRITE_VHIGH_NIBBLE(port_name,data);
	SET_VPULSE('B',EN);
	#endif
}
void LCD_VSEND_CMD(u8 port_name,u8 cmd)
{
	#if defined EIGHT_BIT_MODE
	DIO_SET_VPinVal('B',RS,low);
	DIO_VSetPortVal(port_name,cmd);
	SET_VPULSE('B',EN);
	
	#elif defined FOUR_BIT_MODE
	DIO_SET_VPinVal('B',RS,low);
	WRITE_VHIGH_NIBBLE(port_name,cmd>>4);
	SET_VPULSE('B',EN);
	WRITE_VHIGH_NIBBLE(port_name,cmd);
	SET_VPULSE('B',EN);
	#endif
	_delay_ms(1);
}
void LCD_VCLR_SCREEN(u8 port_name)
{
	LCD_VSEND_CMD(port_name,CLR_SCREEN);
}
void LCD_VMOVE_CURSOR(u8 row,u8 coulmn)
{
	if((row>2)||(row<1)||(coulmn>16)||(coulmn<1))
	{
		LCD_VSEND_CMD('A',ADRESS_ROW1);
	}
	else if(row==1)
	{
		LCD_VSEND_CMD('A',ADRESS_ROW1+coulmn-1);
	}
	else if(row==2)
	{
		LCD_VSEND_CMD('A',ADRESS_ROW2+coulmn-1);
	}
}
void LCD_VSEND_STRING(u8 port_name,u8* ptr)
{
	while(*ptr!=0)
	{
		LCD_VSEND_CHAR(port_name,*ptr);
		ptr++;
	}
}
