/*
 * main.c
 *
 *  Created on: Jan 29, 2022
 *      Author: Mahmoud Alaa
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"

u8 arr[] = {0,0,0,0,0,0,0,0, 126, 4, 8, 8, 4, 126, 0, 0, 124, 10, 10, 10, 10, 124, 0, 0, 126, 8, 8, 8, 8, 126, 0, 0, 126, 4, 8, 8, 4, 126, 0, 0, 126, 66, 66, 66, 66, 126, 0, 0, 126, 64, 64, 64, 64, 126, 0, 0, 126, 66, 66, 66, 66, 60, 0, 0, 0, 0, 0, 0, 0, 0};

void main(void)
{
	/* Initialize System Clock as HSE Crystal : 8 MHz */
0	MRCC_voidInitSysClock();
	/* Enable GPIOA Clock */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_APB2_GPIOA);
	/* Enable GPIOB Clock */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_APB2_GPIOB);

	/* Initialize SysTick Clock as AHB/8 = 1 MHz */
	MSTK_voidInit();

	/* Initialize LEDMRX Pins as Output PP 2 MHz */
	HLEDMRX_voidInit();

	while(1)
	{
		HLEDMRX_voidShiftLeft(arr,56);
	}
}
