/*
 * KP.c
 *
 *  Created on: Sep 24, 2019
 *      Author: breks
 */

#include "KP.h"
#include <util/delay.h>
// array for displaying the Character you can edit it for you own Keypad

unsigned char Keys[4][4]={{'1','4','7','/'},{'2','5','8','0'},{'3','6','9','-'},{'c','0','=','+'}};

void KP_Init()
{
	Dio_WriteLowNibbleDir(KP_PORT, OUT);
	Dio_WriteHighNibbleDir(KP_PORT, IN);
}


uint8 KP_GetKey()
{
	volatile uint8 key = 0;
	// get key
	for (uint8 i = 0; i < 4; i++)
	{
		// turn on the pin in the low nibble
		Dio_WritePortLevel(KP_PORT, STD_high);
		Dio_WritePin(KP_PORT, i, STD_low);
		// read the pin from the high nibble
		for (uint8 j = 0; j < 4; j++) 
		{
			if (Dio_ReadPin(KP_PORT, (j + 4)) == STD_low)
			{
				_delay_ms(30);
				if (Dio_ReadPin(KP_PORT, (j + 4)) == STD_low)
				{
					key = Keys[i][j];
					return key;
				}
			}
		}
	}
	return key;
}