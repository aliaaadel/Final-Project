/*
 * final_project_master.c
 *
 * Created: 1/22/2021 1:27:45 AM
 * Author : aliaa
 */ 

#include <avr/io.h>
#include "SPI.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include "UART.h"
#include "LCD_4bit_driver.h"
int main(void)
{
	UART_Init();
	LCD_init();
    DDRC |=((1<<2)|(1<<3));
    SPI_Init(Master);
	SlaveEn();
    while (1)
    {
	    _delay_ms(2);
	    if(SPI_TxRx(0xAA)>= 70){
		    PORTC ^=(1<<2);
		    
			lcd_SendStringPos("FIRE!!",1,5);
			lcd_SendStringPos("Send1 for Buzzer",2,0);
			_delay_ms(100);
			if (UART_RxChar()=='1'){
				PORTC |=(1<<3);
				UART_TxString("FIRE\n\r");
				lcd_cmd(0x01);
			}
			
	    }
		
		lcd_SendStringPos("Normal",1,5);
	    
    }
}

