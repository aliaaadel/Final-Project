/*
 * SPI.c
 *
 * Created: 1/8/2021 5:00:26 PM
 *  Author: aliaa
 */ 
#include "SPI.h"

void SPI_Init(SPI_StatusTypes status){
	switch(status){
		case Master:
		DDRB|=((1<<SCK)|(1<<MOSI)|(1<<SS));
		DDRB &= ~(1<<MISO);
		SPCR =((1<<SPE)|(1<<MSTR));
		break;
		case Slave:
		DDRB |=(1<<MISO);
		DDRB &=~((1<<MOSI)|(1<<SCK)|(1<<SS));
		SPCR =((1<<SPE));
		break;
	}
}
unsigned char SPI_TxRx(unsigned char data){
	SPDR =data;
	while(!((SPSR>>SPIF)&1));
	return SPDR;
}