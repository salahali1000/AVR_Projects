/*
 * spi.c
 *
 * Created: 6/21/2023 7:28:40 PM
 *  Author: salah
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "DIO.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void SPI_MasterInit(void)
{
	/*Set SS / MOSI / SCK  as output pins for master*/
	DIO_set_vPinDir('B',4,1);
	DIO_set_vPinDir('B',5,1);
	DIO_set_vPinDir('B',7,1);
	/*Enable Master mode*/
	SET_BIT(SPCR,MSTR);
	/*Set clock to fosc/16*/
	SET_BIT(SPCR,SPR0);
	/*Enable SPI*/
	SET_BIT(SPCR,SPE);
	/*set SS to high */
	DIO_SET_VPinVal('B',4,1);
}

void SPI_SlaveInit(void)
{
	/*Enable SPI*/
	SET_BIT(SPCR,SPE);
	/*Set MISO as output*/
	DIO_set_vPinDir('B',6,1);
}

unsigned char SPI_Master_Transmit_Data(unsigned char Data)
{
	/*Clear SS to send data to slave*/
	DIO_SET_VPinVal('B',4,0);
	/*Put data on SPDR*/
	SPDR=Data;
	/*Wait until the transmission is finished*/
	while(READ_BIT(SPSR,SPIF)==0);
	/*read SPDR*/
	return SPDR ;
}

unsigned char SPI_Slave_Recieve_Data(unsigned char Data)
{
	/*Put data on SPDR*/
	SPDR=Data;
	/*Wait until data is received in SPI register*/
	while(READ_BIT(SPSR,SPIF)==0);
	/*read the received data*/
	return SPDR ;
}

void SPI_Master_Transmit_String(unsigned char *ptr)
{
	while((*ptr)!=0)
	{
		SPI_Master_Transmit_Data(*ptr);
		_delay_ms(300);
		ptr++;
	}
}




