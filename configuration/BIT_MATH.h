/*
 * BIT_MATH.h
 *
 * Created: 2/23/2023 2:35:41 PM
 *  Author: salah
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)     reg|=(1<<bit)
#define CLR_BIT(reg,bit)     reg&=~(1<<bit)
#define READ_BIT(reg,bit)    ((reg&(1<<bit))>>bit)
#define TOGG_BIT(reg,bit)    reg^=(1<<bit)


#endif /* BIT_MATH_H_ */