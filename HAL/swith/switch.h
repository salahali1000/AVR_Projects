/*
 * switch.h
 *
 * Created: 2/23/2023 7:46:37 PM
 *  Author: salah
 */ 

#include "STD_TYPES.h"
#ifndef SWITCH_H_
#define SWITCH_H_


void SWITCH_VINIT(u8 port_name,u8 pin_num);
u8 SWITCH_u8Read(u8 port_name,u8 pin_num);



#endif /* SWITCH_H_ */