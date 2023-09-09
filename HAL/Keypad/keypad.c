/*
 * KEYPAD.c
 *
 * Created: 3/13/2023 4:35:26 PM
 *  Author: salah
 */ 
#include "STD_TYPES.h"
#include "DIO.h"
#include "KEYPAD.h"
void KEYPAD_VINIT(void)
{
	/* set low nibble port direction as output */ 
	DIO_set_vPinDir(keypad_port,PIN0,output);
	DIO_set_vPinDir(keypad_port,PIN1,output);
	DIO_set_vPinDir(keypad_port,PIN2,output);
	DIO_set_vPinDir(keypad_port,PIN3,output);
	
	/* set high nibble port direction as input */
	DIO_set_vPinDir(keypad_port,PIN4,input);
	DIO_set_vPinDir(keypad_port,PIN5,input);
	DIO_set_vPinDir(keypad_port,PIN6,input);
	DIO_set_vPinDir(keypad_port,PIN7,input);
	
	/* set internal pullup for the high nibble port */
	INTERNAL_VPULLUP(keypad_port,PIN4);
	INTERNAL_VPULLUP(keypad_port,PIN5);
	INTERNAL_VPULLUP(keypad_port,PIN6);
	INTERNAL_VPULLUP(keypad_port,PIN7);
}
u8 KEYPAD_VREAD(void)
{
	u8 row_count,coulmn_count,check,ret=NOT_PRESSED;
	u8 keypad_value [4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	
	for(row_count=0;row_count<row_size;row_count++)
	{
		DIO_SET_VPinVal(keypad_port,PIN0,high);
		DIO_SET_VPinVal(keypad_port,PIN1,high);
		DIO_SET_VPinVal(keypad_port,PIN2,high);
		DIO_SET_VPinVal(keypad_port,PIN3,high);
		DIO_SET_VPinVal(keypad_port,row_count,low);
		for(coulmn_count=0;coulmn_count<coulmn_size;coulmn_count++)
		{
			check=DIO_READ_u8Pin(keypad_port,coulmn_count+4);
			if(check==low)
			{
				ret=keypad_value[row_count][coulmn_count];
				break;
			}
		}
		if(check==low)
		{
			break;
		}
	}
	return ret;
}
