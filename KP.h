/*
 * KP.h
 *
 *  Created on: Sep 24, 2019
 *      Author: breks
 */

#ifndef KP_KP_H_
#define KP_KP_H_

#include "STD_types.h"
#include "BitMath.h"
#include "DIO.h"
#include "DIO_hw.h"

#define KP_PORT    'c'

uint8 KP_GetKey();
void KP_Init();


#endif /* KP_KP_H_ */
