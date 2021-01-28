/*
 * LCD_4bit_driver.c
 *
 *  Created on: Nov 27, 2020
 *      Author: aliaa
 */
#include <stdlib.h>
#include <avr/io.h>

#include "BitMath.h"
#include "LCD_cfg_4bit.h"
#define F_CPU 16000000UL

#include <util/delay.h>

static char flag=0;




void LCD_enable(void){

	SetBit(LCD_CONTROL_PORT,LCD_E_PIN);

}

void LCD_disable(void){

	ClearBit(LCD_CONTROL_PORT,LCD_E_PIN);

}

void lcd_cmd (char cmd)
{
	// CMD 0000 0000
	ClearBit(LCD_CONTROL_PORT,LCD_RW_PIN);
	ClearBit(LCD_CONTROL_PORT,LCD_RS_PIN);
	LCD_DATA_PORT = cmd; // UPPER CMD
	LCD_enable();
	_delay_ms(1);
	LCD_disable();
	if (flag){
		LCD_DATA_PORT =((cmd<<4) & 0xF0);// LOWER
		LCD_enable();
		_delay_ms(1);
		LCD_disable();
	}
	_delay_ms(2);
}
void lcd_WriteChar(char c)
{
	// CMD 0000 0000
	ClearBit(LCD_CONTROL_PORT,LCD_RW_PIN);
	SetBit(LCD_CONTROL_PORT,LCD_RS_PIN);
	LCD_DATA_PORT = c; // UPPER CMD
	LCD_enable();
	_delay_ms(1);
	LCD_disable();

	LCD_DATA_PORT =((c<<4) & 0xF0);// LOWER
	LCD_enable();
	_delay_ms(1);
	LCD_disable();

	_delay_ms(2);
}

void lcd_String (char *str)		/* Send string to LCD function */
{
	int i=0;
	while(str[i] != '\0')		/* Send each char of string till the NULL */
	{
		lcd_WriteChar (str[i]);
		i++;
	}
}
void lcd_SendStringPos(char* string,unsigned char line ,unsigned char pos){
	lcd_cmd((0x02|0x04));
	switch (line)
	{
		case 1:
		lcd_cmd((0x80 | (pos&0x0F)));
		lcd_String(string);
		break;
		case 2:
		lcd_cmd((0xC0 | (pos&0x0F)));
		lcd_String(string);
		break;
	}
}
void LCD_init(void){
	LCD_DATA_DIRECTION=0xFF;
	LCD_CONTROL_DIRECTION=0xFF;
	LCD_DATA_PORT = 0x00 ;
	_delay_ms(20);

	lcd_cmd(0x20);
	lcd_cmd(0x20);
	lcd_cmd(0x80);
	_delay_ms(1);
	lcd_cmd(0x00);
	lcd_cmd(0xC0);
	_delay_ms(1);
	lcd_cmd(0x00);
	lcd_cmd(0x10);

	_delay_ms(2);
	flag=1;
}
