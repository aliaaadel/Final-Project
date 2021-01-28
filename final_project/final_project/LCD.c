/*
 * LCD.c
 *
 * Created: 12/11/2020 4:20:33 PM
 *  Author: aliaa
 */ 
#include "LCD.h"


void LCD_Init(void){
	_delay_ms(20);
	Write_DIO(RW,STD_Low);
	LCD_Cmd(0x33);
	_delay_us(150);
	LCD_Cmd(0x32);
	LCD_Cmd(0x28);
	LCD_Cmd(0x06);
	LCD_Cmd(0x0C);
	LCD_Cmd(0x01);
	_delay_ms(2);
	
	
}
void LCD_Cmd(Unit8 cmd){
	LCDDataPort =(LCDDataPort&0x0F)|(cmd&0xF0);
	Write_DIO(RS,STD_Low);
	Write_DIO(E,STD_High);
	_delay_us(100);
	Write_DIO(E,STD_Low);
	
	_delay_ms(5);
	
	LCDDataPort =(LCDDataPort&0x0F)|(cmd<<4);
	Write_DIO(RS,STD_Low);
	Write_DIO(E,STD_High);
	_delay_us(100);
	Write_DIO(E,STD_Low);
	_delay_ms(2);
}
void LCD_SendChar(Unit8 data){
	LCDDataPort =(LCDDataPort&0x0F)|(data &0xF0);
	Write_DIO(RS,STD_High);
	Write_DIO(E,STD_High);
	_delay_us(100);
	Write_DIO(E,STD_Low);
	
	_delay_ms(2);
	
	LCDDataPort =(LCDDataPort&0x0F)|(data<<4);
	//Write_DIO(RS,STD_High);
	Write_DIO(E,STD_High);
	_delay_us(100);
	Write_DIO(E,STD_Low);
	_delay_ms(2);
}
void LCD_SendString(Sint8* string){
	Unit8 i = 0;	
	while (string[i] != '\0')
	{
		LCD_SendChar(string[i]);
		i++;
	}
}
void LCD_SendStringPos(Sint8* string,Unit8 line ,Unit8 pos){
	switch (line)
	{
		case 1:
			LCD_Cmd((0x80 | (pos&0x0F)));
			LCD_SendString(string);
		break;
		case 2:
			LCD_Cmd((0xC0 | (pos&0x0F)));
			LCD_SendString(string);
		break;
	}
}
void LCD_CustomeChar(Unit8 loc ,Unit8 * msg){
	if(loc<8){
		LCD_Cmd((0x40 + loc*8));
		for (Unit8 i = 0; i<8 ;i++)
		{
			LCD_SendChar(msg[i]);
		}
	}
}