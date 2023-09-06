/*
 * KEYPAD.h
 *
 * Created: 3/13/2023 4:35:43 PM
 *  Author: salah
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define keypad_port  'C'
#define row_size      4
#define coulmn_size   4
#define NOT_PRESSED   0xff

void KEYPAD_VINIT(void);
u8 KEYPAD_VREAD(void);


#endif /* KEYPAD_H_ */