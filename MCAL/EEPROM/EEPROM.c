/*
 * EEPROM.c
 *
 * Created: 3/9/2023 2:38:49 PM
 *  Author: salah
 */ 

#include "STD_TYPES.h"
#include "REGISTERS.h"
#include "BIT_MATH.h"

void WRITE_VEEPROM(u16 address_eeprom,u8 data)
{
	EEARL=address_eeprom;
	EEARH=(address_eeprom>>8);
	EEDR=data;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while(READ_BIT(EECR,EEWE)==1);
}
u8 READ_VEEPROM(u16 address_eeprom)
{
	u8 data;
	EEARL=address_eeprom;
	EEARH=(address_eeprom>>8);
	SET_BIT(EECR,EERE);
	data=EEDR;
	return data;
}
