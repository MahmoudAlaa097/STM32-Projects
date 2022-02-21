/*
 * main.c
 *
 *  Created on: Feb 2, 2022
 *      Author: Mahmoud Alaa
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h"

void main(void)
{
	/* System Clock = 8 MHz */
	MRCC_voidInitSysClock();
	/* Enable GPIOA */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_APB2_GPIOA);
	/* Enable UART1 */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_APB2_USART1);

	/* Pin Direction */
	/* TX  : A9  => Output @ 50 MHz */
	MGPIO_voidSetPinDirection(MGPIOA,PIN9,OUTPUT_SPEED_50MHZ_AFPP);
	/* RX  : A10 => Input           */
	MGPIO_voidSetPinDirection(MGPIOA,PIN10,INPUT_FLOATING);
	/* LED : A0  => Output @ 2 MHZ  */
	MGPIO_voidSetPinDirection(MGPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);

	/* Initialize USART1 */
	MUSART1_voidInit();

	u8 Local_u8Data = 0;

	while(1)
	{
		MUSART1_voidTransmit("97");
		Local_u8Data = MUSART1_voidRecveive();
		if(Local_u8Data == '5')
		{
			MGPIO_voidSetPinValue(MGPIOA,PIN0,HIGH);
		}
		else if(Local_u8Data == '0')
		{
			MGPIO_voidSetPinValue(MGPIOA,PIN0,LOW);
		}
	}
}
