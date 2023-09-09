/*
 * DIO.h
 *
 * Created: 2/23/2023 2:34:27 PM
 *  Author: salah
 */ 
#include "STD_TYPES.h"

#ifndef DIO_H_
#define DIO_H_

void DIO_set_vPinDir(u8 port_name,u8 pin_num,u8 dir);
void DIO_SET_VPinVal(u8 port_name,u8 pin_num,u8 pin_val);
u8 DIO_READ_u8Pin(u8 port_name,u8 pin_num);
void DIO_VTogglePin(u8 port_name,u8 pin_number);
void DIO_VSetPortDir(u8 port_name,u8 dir);
void DIO_VSetPortVal(u8 port_name,u8 port_val);
u8 DIO_u8ReadPort(u8 port_name);
void SET_VPULSE(u8 port_name,u8 pin_num);
void WRITE_VLOW_NIBBLE(u8 port_name,u8 value);
void WRITE_VHIGH_NIBBLE(u8 port_name,u8 value);
void INTERNAL_VPULLUP(u8 port_name,u8 pin_num);


/* port names */
#define PORTA_DIO   'A'
#define PORTB_DIO   'B'
#define PORTC_DIO   'C'
#define PORTD_DIO   'D'


/* directions  */
#define input   0
#define output  1


/* pin values */
#define low   0
#define high  1

/* pins */
#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7





#endif /* DIO_H_ */