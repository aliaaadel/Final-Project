#include <avr/io.h>
#include <stdlib.h>
#include "ADC.h"
#include "LCD_4bit_driver.h"
#include "SPI.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#define MiniAngle 0
#define MaxAngle 180
#define MiniCount 250
#define MaxCount 500

void ServoAngle(short angle);
unsigned char Flag =0;

int main(void)
{
	ADC_Init();
	LCD_init();
	DDRC |= ((1<<4)|(1<<3)|(1<<2)|(1<<7));
	DDRD |= (1<<5);
	ICR1 = 4999;
	TCCR1A |= ((1<<COM1A1)|(1<<WGM11));
	TCCR1B |= ((1<<WGM12)|(1<<CS11)|(1<<CS10)|(1<<WGM13));// n=64 - FPWM 8-bit  - non inverting - channelA
	OCR1A =50;
	TCCR0 |= ((1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS00)|(1<<CS01));
	OCR0= ((45/100)*265)-1; // Duty
	SPI_Init(Slave);

	unsigned short temp;
	
	while (1)
	{
		temp = ADC_Read(1);
		temp /= 4;
		Flag=1;
		while (temp >= 70){
			
			temp = ADC_Read(1);
			temp /= 4;
			lcd_SendStringPos("FIRE!!",1,5);
			if(Flag==1){
				_delay_ms(5);
				if(SPI_TxRx(temp)==0xAA){
					PORTC^=(1<<7);
					_delay_ms(100);
				}
			}
		PORTC ^=(1<<2);
		ServoAngle(90);
		PORTC |= (1<<4);
		PORTC &=~ (1<<3);
		}
		Flag=0;
		lcd_SendStringPos("Normal",1,5);
		ServoAngle(0);
		PORTC &=~ (1<<3);
		PORTC &=~ (1<<4);
		PORTC &=~(1<<2);
		

	}
}
void ServoAngle( short angle){
	OCR1A = (long)(((MaxCount - MiniCount)*(angle-MiniAngle))/(MaxAngle-MiniAngle))+MiniCount-1;
}

