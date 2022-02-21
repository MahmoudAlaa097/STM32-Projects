/*
 * main.c
 *
 *  Created on: Jan 30, 2022
 *      Author: Mahmoud Alaa
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"

u8 arr[8] = {0, 126, 4, 8, 4, 126, 0, 0};

void main(void)
{
	/* System Clock Initialization */
	/* HSE Crystal */
	MRCC_voidInitSysClock();
	/* Enable GPIOA Clock */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_APB2_GPIOA);

	/* Pin Directions */
	/* Output PP 2 MHz */
	MGPIO_voidSetPinDirection(MGPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(MGPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(MGPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(MGPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(MGPIOA,PIN4,OUTPUT_SPEED_2MHZ_PP);

	/* SysTick Clock Initialization */
	/* AHB/8 = 1 MHz (1 usec per tick) */
	MSTK_voidInit();

	while(1)
	{
		Display(arr);
	}

}

void Display(u8* Data)
{
	for(u8 i=0;i<8;i++)
	{
		/* Disable All Columns */
		HSTP_voidSetData(0xFF);
		HSTP_voidSendSynchronus();
		/* Set Rows Values */
		HSTP_voidSetData(Data[i]);
		/* Enable Column 0 */
		HSTP_voidSetData(1<<i);
		HSTP_voidSendSynchronus();
		/* Delay 2.5 usec */
		MSTK_voidSetBusyWait(2500);
	}
}
