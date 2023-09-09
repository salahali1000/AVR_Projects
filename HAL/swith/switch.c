*
 * switch.c
 *
 * Created: 2/23/2023 7:46:21 PM
 *  Author: salah
 */ 
#include "STD_TYPES.h"
#include "DIO.h"
#include "switch.h"
void SWITCH_VINIT(u8 port_name,u8 pin_num)
{
		
	DIO_set_vPinDir(port_name,pin_num,low);
		
}	
u8 SWITCH_u8Read(u8 port_name,u8 pin_num)
{
	u8 val_read;

	val_read=DIO_READ_u8Pin( port_name,pin_num);
			
	return val_read;		
}
