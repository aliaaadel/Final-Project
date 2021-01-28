/*
 * LCD_cfg_4bit.h
 *
 *  Created on: Nov 27, 2020
 *      Author: aliaa
 */

#ifndef LCD_CFG_4BIT_H_
#define LCD_CFG_4BIT_H_



#define LCD_DATA_DIRECTION DDRA
#define LCD_CONTROL_DIRECTION DDRB

#define LCD_DATA_PORT PORTA
#define LCD_CONTROL_PORT PORTB

#define LCD_RS_PIN 1
#define LCD_RW_PIN 2
#define LCD_E_PIN  0

#define LCD_DB4_PIN 4
#define LCD_DB5_PIN 5
#define LCD_DB6_PIN 6
#define LCD_DB7_PIN 7

#endif /* LCD_CFG_4BIT_H_ */