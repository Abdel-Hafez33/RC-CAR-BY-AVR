/*
 ============================================================================
 Name        : main.c
 Module Name : APP
 Author      : ragab
 Description : The main function of project
 ============================================================================
 */
#include "MCAL/GPIO/Gpio_Interface.h"
#include "HAL/BLUETOOTH/bluetooth.h"
#include "HAL/MOTOR/motor.h"
#include "HAL/MOTOR_DRIVER/motorDriver.h"
#include "HAL/ULTRASONIC_SENSOR/ultrasonic_sensor.h"
#include "MCAL/GPIO/gpio_private.h"
#include "HAL/IR SENSOR/IR_sensor.h"

#include <util/delay.h>

uint8 HC5_input = 0;
uint8 Ultra_Distance = 0;
uint8 Left_Read =0;
uint8 Right_Read =0;


void RC_Desicion();
void ULTRA_Desicion();
void Desicion_Direction();
void IR_Desicion();

int main()
{
	/* Configuration and initialization functions */
	DcMotor_Init();
	bluetooth_init();
	Ultrasonic_init();
	IR_sensor_Init();




	SREG_REG.Bits.I_Bit = 1;


	while (1)
	{

		HC5_input = bluetooth_recieveByte();
		while (HC5_input == 'W') //RC mode
		{
			HC5_input = bluetooth_recieveByte();
			RC_Desicion();


			HC5_input = 'W';
		}
		while (HC5_input == 'U') //ultrasonic mode
		{
			Set_Speed(40);
			Ultra_Distance = Ultrasonic_readDistance();

			Desicion_Direction();

			ULTRA_Desicion();

			HC5_input = 'U';
		}
		while (HC5_input == 'I') //RC mode
		{
			//HC5_input = bluetooth_recieveByte();
			IR_Desicion();

			HC5_input = 'I';
		}


	}
}

void IR_Desicion()
{
	Left_Read =IR1_READ();
	Right_Read = IR2_READ();


	if (Left_Read==1 && Right_Read==1)
	{
		Move_Forward();
	}
	else if (Left_Read==0 && Right_Read==1)
	{
		Move_Backward();
		_delay_ms(200);
		Move_Left();
		_delay_ms(500);
		stop();
	}
	else if (Left_Read==1 && Right_Read==0)
	{
		Move_Backward();
		_delay_ms(200);
		Move_Right();
		_delay_ms(500);
		stop();
	}
	else if (Left_Read==1 & Right_Read==1) {
		Move_Backward();
		_delay_ms(400);
	}
	else {
		stop();
	}

}

void RC_Desicion()
{
	switch (HC5_input)
	{
	case 'F':

		Move_Forward();
		Set_Speed(90);
		break;
	case 'B':
		Move_Backward();
		Set_Speed(90);
		break;
	case 'L':
		Move_Left();
		Set_Speed(90);
		break;
	case 'R':
		Move_Right();
		Set_Speed(90);
		break;
	case 'S':
		stop();
		//Set_Speed(90);
		break;
	default:
		stop();
		break;
	}
}

void Desicion_Direction()
{
	if (Ultra_Distance > 50)
	{
		HC5_input = 'F';
	}
	else
	{
		uint8 Right_val = 0, Left_val = 0;

		HC5_input = 'R';
		ULTRA_Desicion();

		Right_val = Ultrasonic_readDistance();

		HC5_input = 'L';
		ULTRA_Desicion();
		ULTRA_Desicion();

		Left_val = Ultrasonic_readDistance();

		HC5_input = 'R';
		ULTRA_Desicion();

		if (Right_val >= Left_val && Right_val > 50)
		{
			HC5_input = 'R';
		}
		else if (Left_val >= Right_val && Left_val > 50)
		{
			HC5_input = 'L';
		}
		else
		{
			HC5_input = 'R';
			ULTRA_Desicion();
			ULTRA_Desicion();

			HC5_input = 'F';
		}

	}
}

void ULTRA_Desicion()
{

	switch (HC5_input)
	{
	case 'F':
		Move_Forward();
		break;
	case 'B':
		Move_Backward();
		break;
	case 'L':
		Move_Left();
		_delay_ms(500);
		break;
	case 'R':
		Move_Right();
		_delay_ms(500);
		break;
	default:
		stop();
		break;
	}

}
