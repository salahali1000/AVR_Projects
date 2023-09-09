/*
 * DIO.c
 *
 * Created: 2/23/2023 2:34:40 PM
 *  Author: salah
 */ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "REGISTERS.h"
#include "DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>
void DIO_set_vPinDir(u8 port_name,u8 pin_num,u8 dir)
{
	switch(port_name)
	{
		case PORTA_DIO :
		if(dir==output)
		{
			SET_BIT(DDRA,pin_num);
		}
		else 
		{
			CLR_BIT(DDRA,pin_num);
		}
		break;
		case PORTB_DIO :
		if(dir==output)
		{
			SET_BIT(DDRB,pin_num);
		}
		else
		{
			CLR_BIT(DDRB,pin_num);
		}
		break;
		case PORTC_DIO :
		if(dir==output)
		{
			SET_BIT(DDRC,pin_num);
		}
		else
		{
			CLR_BIT(DDRC,pin_num);
		}
		break;
		case PORTD_DIO :
		if(dir==output)
		{
			SET_BIT(DDRD,pin_num);
		}
		else
		{
			CLR_BIT(DDRD,pin_num);
		}
		break;
	}
}
void DIO_SET_VPinVal(u8 port_name,u8 pin_num,u8 pin_val)
{
	switch(port_name)
	{
		case PORTA_DIO :
		if (pin_val==high)
		{
			SET_BIT(PORTA,pin_num);
		}
		else
		{
			CLR_BIT(PORTA,pin_num);
		}
		break;
		case PORTB_DIO :
		if (pin_val==high)
		{
			SET_BIT(PORTB,pin_num);
		}
		else
		{
			CLR_BIT(PORTB,pin_num);
		}
		break;
		case PORTC_DIO :
		if (pin_val==high)
		{
			SET_BIT(PORTC,pin_num);
		}
		else
		{
			CLR_BIT(PORTC,pin_num);
		}
		break;
		case PORTD_DIO :
		if (pin_val==high)
		{
			SET_BIT(PORTD,pin_num);
		}
		else
		{
			CLR_BIT(PORTD,pin_num);
		}
		break;
	}
}
u8 DIO_READ_u8Pin(u8 port_name,u8 pin_num)
{
	u8 val_Read;
	switch(port_name)
	{
		case PORTA_DIO :
		val_Read=READ_BIT(PINA,pin_num);
		break;
		case PORTB_DIO :
		val_Read=READ_BIT(PINB,pin_num);
		break;
		case PORTC_DIO :
		val_Read=READ_BIT(PINC,pin_num);
		break;
		case PORTD_DIO :
		val_Read=READ_BIT(PIND,pin_num);
		break;
	}
	return val_Read;
}
void DIO_VTogglePin(u8 port_name,u8 pin_number)
{
	switch(port_name)
	{
		case PORTA_DIO :
		TOGG_BIT(PORTA,pin_number);
		break;
		case PORTB_DIO :
		TOGG_BIT(PORTB,pin_number);
		break;
		case PORTC_DIO :
		TOGG_BIT(PORTC,pin_number);
		break;
		case PORTD_DIO :
		TOGG_BIT(PORTD,pin_number);
		break;
	}
}
void DIO_VSetPortDir(u8 port_name,u8 dir)
{
	switch(port_name)
	{
		case PORTA_DIO:
		DDRA=dir;
		break;
		case PORTB_DIO:
		DDRB=dir;
		break;
		case PORTC_DIO:
		DDRC=dir;
		break;
		case PORTD_DIO:
		DDRD=dir;
		break;
	}
}
void DIO_VSetPortVal(u8 port_name,u8 port_val)
{
	switch(port_name)
	{
		case PORTA_DIO:
		PORTA=port_val;
		break;
		case PORTB_DIO:
		PORTB=port_val;
		break;
		case PORTC_DIO:
		PORTC=port_val;
		break;
		case PORTD_DIO:
		PORTD=port_val;
		break;
		
	}
}
u8 DIO_u8ReadPort(u8 port_name)
{
	u8 val_read;
	switch(port_name)
	{
		case PORTA_DIO:
		val_read=PINA;
		break;
		case PORTB_DIO:
		val_read=PINB;
		break;
		case PORTC_DIO:
		val_read=PINC;
		break;
		case PORTD_DIO:
		val_read=PIND;
		break;
	}
	return val_read;
}
void INTERNAL_VPULLUP(u8 port_name,u8 pin_num)
{
	switch(port_name)
	{
		case PORTA_DIO:
		SET_BIT(PORTA,pin_num);
		break;
		case PORTB_DIO:
		SET_BIT(PORTB,pin_num);
		break;
		case PORTC_DIO:
		SET_BIT(PORTC,pin_num);
		break;
		case PORTD_DIO:
		SET_BIT(PORTD,pin_num);
		break;
		
	}
}
void SET_VPULSE(u8 port_name,u8 pin_num)
{
	switch(port_name)
	{
		case PORTA_DIO:
		SET_BIT(PORTA,pin_num);
		_delay_ms(2);
		CLR_BIT(PORTA,pin_num);
		_delay_ms(2);
		break;
		case PORTB_DIO:
		SET_BIT(PORTB,pin_num);
		_delay_ms(2);
		CLR_BIT(PORTB,pin_num);
		_delay_ms(2);
		break;
		case PORTC_DIO:

		SET_BIT(PORTC,pin_num);
		_delay_ms(2);
		CLR_BIT(PORTC,pin_num);
		_delay_ms(2);
		break;
		case PORTD_DIO:
		SET_BIT(PORTD,pin_num);
		_delay_ms(2);
		CLR_BIT(PORTD,pin_num);
		_delay_ms(2);
		break;
		
	}
	
}
void WRITE_VLOW_NIBBLE(u8 port_name,u8 value)
{
	u8 i;
	switch(port_name)
	{
		case PORTA_DIO:
		for(i=0;i<=3;i++)
		{
			if(READ_BIT(value,i)==1)
			{
				SET_BIT(PORTA,i);
			}
			else
			{
				CLR_BIT(PORTA,i);
			}
		}
		case PORTB_DIO:
		for(i=0;i<=3;i++)
		{
			if(READ_BIT(value,i)==1)
			{
				SET_BIT(PORTB,i);
			}
			else
			{
				CLR_BIT(PORTB,i);
			}
		}
		case PORTC_DIO:
		for(i=0;i<=3;i++)
		{
			if(READ_BIT(value,i)==1)
			{
				SET_BIT(PORTC,i);
			}
			else
			{
				CLR_BIT(PORTC,i);
			}
		}
		case PORTD_DIO:
		for(i=0;i<=3;i++)
		{
			if(READ_BIT(value,i)==1)
			{
				SET_BIT(PORTD,i);
			}
			else
			{
				CLR_BIT(PORTD,i);
			}
		}
		
	}
}
void WRITE_VHIGH_NIBBLE(u8 port_name,u8 value)
{
	u8 i;
	switch(port_name)
	{
		case PORTA_DIO:
		for(i=0;i<=3;i++)
		{
			if(READ_BIT(value,i)==1)
			{
				SET_BIT(PORTA,(i+4));
			}
			else
			{
				CLR_BIT(PORTA,(i+4));
			}
		}
		case PORTB_DIO:
		for(i=0;i<=3;i++)
		{
			if(READ_BIT(value,i)==1)
			{
				SET_BIT(PORTB,(i+4));
			}
			else
			{
				CLR_BIT(PORTB,(i+4));
			}
		}
		case PORTC_DIO:
		for(i=0;i<=3;i++)
		{
			if(READ_BIT(value,i)==1)
			{
				SET_BIT(PORTC,(i+4));
			}
			else
			{
				CLR_BIT(PORTC,(i+4));
			}
		}
		case PORTD_DIO:
		for(i=0;i<=3;i++)
		{
			if(READ_BIT(value,i)==1)
			{
				SET_BIT(PORTD,(i+4));
			}
			else
			{
				CLR_BIT(PORTD,(i+4));
			}
		}
		
	}
}
