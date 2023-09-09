/*
 * EEPROM.h
 *
 * Created: 3/9/2023 2:39:00 PM
 *  Author: salah
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void WRITE_VEEPROM(u16 address_eeprom,u8 data);
u8 READ_VEEPROM(u16 address_eeprom);



#endif /* EEPROM_H_ */