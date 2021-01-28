/*
 * LCD_4bit_driver.h
 *
 *  Created on: Nov 27, 2020
 *      Author: aliaa
 */

#ifndef LCD_4BIT_DRIVER_H_
#define LCD_4BIT_DRIVER_H_



void LCD_enable(void);
void LCD_disable(void);
void LCD_init(void);
void lcd_cmd (char cmd);
void lcd_WriteChar(char c);
void lcd_String (char *str)	;
void lcd_SendStringPos(char* string,unsigned char line ,unsigned char pos);

#endif /* LCD_4BIT_DRIVER_H_ */