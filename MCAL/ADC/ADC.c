/*
 * ADC.c
 *
 * Created: 4/17/2023 4:15:08 PM
 *  Author: salah
 */ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "REGISTERS.h"
void ADC_INIT(void)
{
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1); //SET THE REF VOLATAGE TO BE VCC VOLTAGE
	/* SET THE CLOCK */
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	// CONFIGE THE ENABLE OF CONVERSION
	SET_BIT(ADCSRA,ADEN);
	
}
u16 ADC_U16READ(void)
{
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADIF)==0);
	SET_BIT(ADCSRA,ADIF);
	u16 read_val=ADCL;
	read_val|=(ADCH<<8);
	return read_val;
}