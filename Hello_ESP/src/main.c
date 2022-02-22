/*
 * main.c
 *
 *  Created on: Feb 6, 2022
 *      Author: Mahmoud Alaa
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h"

#include "ESP_interface.h"

void main(void)
{
	/* RCC Initialization */
	MRCC_voidInitSysClock();
	/* Enable GPIOA */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_APB2_GPIOA);
	/* Enable USART1 */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_APB2_USART1);

	/* Pin Direction */
	/* TX  : A9  => Output @ 50 MHz */
	MGPIO_voidSetPinDirection(MGPIOA,PIN9,OUTPUT_SPEED_50MHZ_AFPP);
	/* RX  : A10 => Input           */
	MGPIO_voidSetPinDirection(MGPIOA,PIN10,INPUT_FLOATING);
	/* LED : A0  => Output @ 2 MHZ  */
	MGPIO_voidSetPinDirection(MGPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);

	/* USART1 Initialization */
	MUSART1_voidInit();

	/* ESP Initialization */
	HESP_voidInit();
	/* Connect to WiFi */
	HESP_voidConnectToWiFi((u8*)"7oDa",(u8*)"30111997");

	u8 Local_u8Data;
	u8 Local_u8Index = 0;
	u8 Local_u8Temp = 0;

	while(1)
	{
		/* Connect to Server */
		HESP_voidConnectToServerTcp((u8*)"162.253.155.226");

		/* Send File Link */
		Local_u8Data = HESP_u8ExecuteRequest((u8*)"46",(u8*)"http://simpleiot.freevar.com/status.txt");

		if(Local_u8Data == '0')
		{
			/* LED Off */
			MGPIO_voidSetPinValue(MGPIOA,PIN0,LOW);
		}
		else if(Local_u8Data == '1')
		{
			/* LED On */
			MGPIO_voidSetPinValue(MGPIOA,PIN0,HIGH);
		}
	}
}
