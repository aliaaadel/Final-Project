/*
 * SPI.h
 *
 * Created: 1/8/2021 5:00:41 PM
 *  Author: aliaa
 */ 


#ifndef SPI_H_
#define SPI_H_
#include <avr/io.h>
#define MOSI 5
#define MISO 6
#define SCK 7
#define SS 4
#define SlaveEn() (PORTB &=~ (1<< SS) )
#define SlaveDis() (PORTB |= (1<<SS) )
typedef enum{
	Master=0,
	Slave
}SPI_StatusTypes;

void SPI_Init(SPI_StatusTypes status);
unsigned char SPI_TxRx(unsigned char data);


#endif /* SPI_H_ */