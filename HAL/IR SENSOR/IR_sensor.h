/*
 * IR_sensor.h
 *
 *  Created on: Dec 13, 2024
 *      Author: AHMED
 */

#ifndef HAL_IR_SENSOR_IR_SENSOR_H_
#define HAL_IR_SENSOR_IR_SENSOR_H_


#include "../../LIB/std_types.h"



/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define IR1_PORTIA				PORTA_ID
#define IR1_PINIA				PIN4_ID

#define IR2_PORTIA				PORTA_ID
#define IR2_PINIA				PIN5_ID


/*
 * Description :
 * 1. The Function responsible for setup the IN
 */
void IR_sensor_Init(void);


uint8 IR1_READ(void);


uint8 IR2_READ(void);



#endif /* HAL_IR_SENSOR_IR_SENSOR_H_ */
