/*
 * ADC.c
 *
 * Created: 12/19/2020 6:13:12 PM
 *  Author: aliaa
 */ 
#include "ADC.h"
void ADC_Init(){
	ADMUX = (1<<REFS0)|(1<<REFS1);
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}
unsigned short ADC_Read(unsigned char channel){
	unsigned short data = 0;
	ADMUX |= (0b11100000 & ADMUX)|(channel & 0b00011111);
	ADCSRA |= (1<<ADSC);
	while(((ADCSRA>>ADIF)&1 ) == 0);
	ADCSRA |= (1<<ADIF);
	data = ADCL;
	data |= ADCH<<8;
	
	return data;
}
