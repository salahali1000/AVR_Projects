/*
 * REGISTERS.h
 *
 * Created: 2/23/2023 2:35:01 PM
 *  Author: salah
 */ 

#include "STD_TYPES.h"

#ifndef REGISTERS_H_
#define REGISTERS_H_

/* GROUP A */
#define DDRA   *(volatile u8*)(0x3A)
#define PORTA  *(volatile u8*)(0x3B)
#define PINA   *(volatile u8*)(0x39)

/* GROUP B*/
#define DDRB   *(volatile u8*)(0x37)
#define PORTB  *(volatile u8*)(0x38)
#define PINB   *(volatile u8*)(0x36)

/*GROUP C */
#define DDRC   *(volatile u8*)(0x34)
#define PORTC  *(volatile u8*)(0x35)
#define PINC   *(volatile u8*)(0x33)

/* GROUP D */
#define DDRD  *(volatile u8*)(0x31)
#define PORTD  *(volatile u8*)(0x32)
#define PIND  *(volatile u8*)(0x30)

/* ADC REGISTERS */
#define ADMUX  *(volatile u8*)(0x27)
#define ADCSRA *(volatile u8*)(0x26)
#define ADCH   *(volatile u8*)(0x25)
#define ADCL   *(volatile u8*)(0x24)

/* ADC BITS */
#define MUX0   0
#define MUX1   1
#define MUX2   2
#define MUX3   3
#define MUX4   4
#define REFS0  6
#define REFS1  7
#define ADPS0  0
#define ADPS1  1
#define ADPS2  2
#define ADIE   3
#define ADIF   4
#define ADATE  5
#define ADSC   6
#define ADEN   7
#endif /* REGISTERS_H_ */
