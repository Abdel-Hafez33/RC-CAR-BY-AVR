/*
 ============================================================================
 Name        : bluetooth.h
 Module Name : BLUETOOTH
 Author      : Ragab
 Description : Source file for the bluetooth driver
 ============================================================================
 */

#include "bluetooth.h"
#include "../../MCAL/UART/MURT_private.h"

/*
 * Description :
 * The Function responsible for setup the bluetooth module with suitable baud rate.
 */
void bluetooth_init()
{
	UART_init(9600);
}

/*
 * Description :
 * The Function responsible for receive data from bluetooth module.
 */
uint8 bluetooth_recieveByte()
{
	return UART_recieveByte();
}

/*
 * Description :
 * The Function responsible for send data through bluetooth module.
 */
void bluetooth_sendByte(uint8 data)
{
	UART_sendByte(data);
}
