/*
 * BitMath.h
 *
 *  Created on: Dec 11, 2020
 *      Author: aliaa
 */

#ifndef BITMATH_H_
#define BITMATH_H_


#define SetBit(reg,bit) (reg|= (1<<bit))
#define ClearBit(reg,bit) (reg&= ~(1<<bit))
#define ToggleBit(reg,bit) (reg^= (1<<bit))
#define GetBit(reg,bit) ((reg>>bit)&1)

#endif /* BITMATH_H_ */
