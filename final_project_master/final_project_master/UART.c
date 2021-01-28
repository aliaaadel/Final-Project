/*
 * UART.c
 *
 * Created: 1/1/2021 5:37:56 PM
 *  Author: aliaa
 */ 
#include "UART.h"


void UART_Init(){
	UCSRB |=((1<<RXEN)|(1<<TXEN)|(1<<RXCIE));
	UCSRC |=((1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1));
	UBRRL = MyUBRR;
	UBRRH = (MyUBRR>>8);
}
void UART_TxChar( char data){
	while(!((UCSRA>>UDRE)&1));
	UDR = data;
}
char UART_RxChar(){
	while(!((UCSRA>>RXC)&1));
	return UDR;
	
}
void UART_TxString(char* string){
	unsigned char i=0;
	while (string[i] != '\0'){
		UART_TxChar(string[i]);
		i++;
	}
	
}
