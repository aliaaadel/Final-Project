/*
 * LCD.h
 *
 * Created: 12/11/2020 4:20:44 PM
 *  Author: aliaa
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#define LCDDataPort PORTA_reg

#define RS DIO_ChannelB1
#define RW DIO_ChannelB2
#define E DIO_ChannelB3

void LCD_Init(void);
void LCD_Cmd(Unit8 cmd);
void LCD_SendChar(Unit8 data);
void LCD_SendString(Sint8* string);
void LCD_SendStringPos(Sint8* string,Unit8 line ,Unit8 pos);
void LCD_CustomeChar(Unit8 loc ,Unit8 * msg);




#endif /* LCD_H_ */