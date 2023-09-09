/*
 * uart.h
 *
 * Created: 6/17/2023 8:03:05 PM
 *  Author: salah
 */ 


#ifndef UART_H_
#define UART_H_
void UART_VINIT(int baud);
void UART_VSEND(char data);
unsigned char UART_U8RECIEVE(void);
void UART_VSEND_STRING(char*ptr);

#endif /* UART_H_ */