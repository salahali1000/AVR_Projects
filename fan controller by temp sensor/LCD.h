/*
 * LCD.h
 *
 * Created: 3/2/2023 5:14:16 PM
 *  Author: salah
 */ 
#include "STD_TYPES.h"

#ifndef LCD_H_
#define LCD_H_
#define CLR_SCREEN           0x01
#define RETURN_HOME          0x02
#define ENTRY_MODE           0x06
#define CURSOR_ON_DISPLAY_ON 0x0c
#define ADRESS_ROW1          0x80
#define ADRESS_ROW2          0xc0

#define EN 0
#define RS 1
#define RW 2

//#if defined 8_BIT_MODE
#define EIGHT_bits 0x38

//#elif defined 4_BIT_MODE 
#define FOUR_bits 0x28

void LCD_VINT(u8 port_name);
void LCD_VSEND_CHAR(u8 port_name,u8 data);
void LCD_VSEND_CMD(u8 port_name,u8 cmd);
void LCD_VCLR_SCREEN(u8 port_name);
void LCD_VMOVE_CURSOR(u8 row,u8 coulmn);
void LCD_VSEND_STRING(u8 port_name,u8* ptr);

#endif /* LCD_H_ */