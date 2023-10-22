#include <avr/io.h>
#include "ADC_driver.h"
#include "timer.h"
#include "LCD.h"
int main(void)
{
	LCD_VINT('A') ;
	u64 temperatue ;
	u16 value;
	f32 voltage;
	f32 step=(2.65/1055);
	DIO_VSetPortDir('C',0xff) ;
	DIO_set_vPinDir('B',3,1) ;
	DIO_SET_VPinVal('B',3,1) ;
	DIO_SET_VPinVal('C',1,1) ;
	ADC_vinit();
    while(1)
    {
	   value=ADC_u16Read();
	   voltage=value*step*1000;
	   temperatue=voltage/10;
  
	    if(temperatue >= 1 && temperatue <= 30)
	   {
		   LCD_VMOVE_CURSOR(1,1);
		   LCD_VSEND_STRING('A',"FAN IS OFF") ;
		   timer1_wave_fastPWm(0) ;
		   LCD_VMOVE_CURSOR(2,1) ;
		   if (temperatue < 10)
		   {
			   LCD_VSEND_CHAR('A',temperatue+48);
		   }
		   else if (temperatue>=10)
		   {
			   LCD_VSEND_CHAR('A',(temperatue/10) + 48) ;
			   LCD_VSEND_CHAR('A',(temperatue%10) + 48)	;
			   LCD_VSEND_CHAR('A',0xDF)	;
			   LCD_VSEND_CHAR('A',0x43)	;
		   }
	   }
	   else if (temperatue > 30 && temperatue <=50)
	   {
		   LCD_VMOVE_CURSOR(1,1);
		   LCD_VSEND_STRING('A',"FAN IS ON") ;
		   LCD_VMOVE_CURSOR(1,10);
		   LCD_VSEND_CHAR('A',' ') ;
		   timer1_wave_fastPWm(50) ;
		   LCD_VMOVE_CURSOR(2,1) ;
		   LCD_VSEND_CHAR('A',(temperatue/10) + 48) ;
		   LCD_VSEND_CHAR('A',(temperatue%10) + 48)	;
		   LCD_VSEND_CHAR('A',0xDF)	;
		   LCD_VSEND_CHAR('A',0x43)	;
		   LCD_VMOVE_CURSOR(2,6) ;
		   LCD_VSEND_STRING('A',"FAN:50%");
	   }	
	   else if ( (temperatue > 50) && (temperatue <= 70) )
	   {
		   LCD_VMOVE_CURSOR(1,1);
		   LCD_VSEND_STRING('A',"FAN IS ON") ;
		   LCD_VMOVE_CURSOR(1,10);
		   LCD_VSEND_CHAR('A',' ') ;
		   timer1_wave_fastPWm(75) ;
		   LCD_VMOVE_CURSOR(2,1) ;
		   LCD_VSEND_CHAR('A',(temperatue/10) + 48) ;
		   LCD_VSEND_CHAR('A',(temperatue%10) + 48)	;
		   LCD_VSEND_CHAR('A',0xDF)	;
		   LCD_VSEND_CHAR('A',0x43)	;
		   LCD_VMOVE_CURSOR(2,6) ;
		   LCD_VSEND_STRING('A',"FAN:75%");
	   }
	   else if (temperatue > 70 && temperatue < 90)
	   {
		   LCD_VMOVE_CURSOR(1,1);
		   LCD_VSEND_STRING('A',"FAN IS ON") ;
		   LCD_VMOVE_CURSOR(1,10);
		   LCD_VSEND_CHAR('A',' ') ;
		   timer1_wave_fastPWm(100) ;
		   LCD_VMOVE_CURSOR(2,1) ;
		   LCD_VSEND_CHAR('A',(temperatue/10) + 48) ;
		   LCD_VSEND_CHAR('A',(temperatue%10) + 48)	;
		   LCD_VSEND_CHAR('A',0xDF)	;
		   LCD_VSEND_CHAR('A',0x43)	;
		   LCD_VMOVE_CURSOR(2,6) ;
		   LCD_VSEND_STRING('A',"FAN:100%");
	   }
	    
	   
    }
}
