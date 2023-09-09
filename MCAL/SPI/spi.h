/*
 * spi.h
 *
 * Created: 6/21/2023 7:28:52 PM
 *  Author: salah
 */ 


#ifndef SPI_H_
#define SPI_H_

void SPI_MasterInit(void);
void SPI_Slave_Init(void);
unsigned char SPI_Master_Transmit_Data(unsigned char data);
unsigned char SPI_Slave_Recieve_Data(unsigned char data);
void SPI_Master_Transmit_String(char *ptr1);

#endif /* SPI_H_ */