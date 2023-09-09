/*
 * uart.c
 *
 * Created: 6/17/2023 8:02:52 PM
 *  Author: salah
 */ 
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
void UART_VINIT(int baud)
{
	signed short ubrr=(F_CPU/(16*baud)-1);
	UBRRH=(unsigned char)(ubrr>>8);
	UBRRL=(unsigned char)ubrr;
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	UCSRC=(1<<UCSZ0)|(1<<UCSZ1)|(1<<URSEL);
}
void UART_VSEND(char data)
{
	while(READ_BIT(UCSRA,UDRE)==0);
	UDR=data;
}
unsigned char UART_U8RECIEVE(void)
{
	while(READ_BIT(UCSRA,RXC)==0);
	return UDR;
}
void UART_VSEND_STRING(char*ptr)
{
	while(*ptr!=0)
	{
		UART_VSEND(*ptr);
		ptr++;
		_delay_ms(100);
	}
}
