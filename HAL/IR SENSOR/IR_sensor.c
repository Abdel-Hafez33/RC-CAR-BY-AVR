/*
 * IR_SENSOR.c
 *
 *  Created on: Dec 13, 2024
 *      Author: AHMED
 */

#include "../../MCAL/TIMER0/timer0.h"
#include "IR_sensor.h"
#include "../../LIB/common_macros.h"
#include "../../MCAL/GPIO/Gpio_Interface.h"



void IR_sensor_Init(void)
{
	GPIO_setupPinDirection(IR1_PORTIA, IR1_PINIA, PIN_INPUT);
	GPIO_setupPinDirection(IR2_PORTIA, IR2_PINIA, PIN_INPUT);
}


uint8 IR1_READ(void)
{

	uint8 x = 1;


	x = GPIO_readPin(IR1_PORTIA, IR1_PINIA);
	if (x ==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

uint8 IR2_READ(void)
{
	uint8 y = 1;


	y = GPIO_readPin(IR1_PORTIA, IR2_PINIA);
	if (y ==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
