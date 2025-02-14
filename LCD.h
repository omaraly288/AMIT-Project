/*
 * LCD.h
 *
 *  Created on: Sep 20, 2019
 *      Author: breks
 */

#ifndef LCD_H_
#define LCD_H_
#define F_CPU 16000000ul


#include "DIO.h"
#include "STD_types.h"
#include "BitMath.h"


#include <util/delay.h>

#define LCD_Port ('a')
#define LCD_ControlPort ('b')



#define LCD_EN 3
#define LCD_RW 2
#define LCD_RS 1

#define	EIGHT_BIT_MODE
#define FOUR_BIT_MODE

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_RAW						(0x80)
#define LCD_BEGIN_AT_SECOND_RAW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)


void LCD_init();
void LCD_kick ();
void LCD_SendCommand(uint8 command);
void LCD_SendCharacter(uint8 character);
void LCD_SendString(uint8 *String);
void LCD_clearScreen ();
void LCD_GotoXY(uint8 x, uint8 y);
void LCD_SendNumber (uint16 Number);
void LCD_SendRealNumber (float32  Number );
void LCD_CreatChar(uint8 charnum,uint8 a_NewShape[] );

#endif /* LCD_H_ */
