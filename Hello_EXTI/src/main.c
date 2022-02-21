/*
 * main.c
 *
 *  Created on: Jan 21, 2022
 *      Author: Mahmoud Alaa
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "STK_interface.h"

void func(void);

void main(void)
{
	/* Initialize System Clock */
	MRCC_voidInitSysClock();
	/* Enable GPIOA Clock */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_APB2_GPIOA);

	/* Initialize NVIC */
	MNVIC_voidInit();
	/* Set EXTI priority to 2 */
	MNVIC_voidSetPriority(MNVIC_EXTI0,2);
	/* Enable EXTI */
	MNVIC_voidEnableInerrrupt(6);

	/* Pins Directions */
	/* PIN0 : Input & Pull up */
	MGPIO_voidSetPinDirection(MGPIOA,PIN0,INPUT_PULL_UP_DOWN);
	MGPIO_voidSetPinValue(MGPIOA,PIN0,HIGH);
	/* PIN2 : Output */
	MGPIO_voidSetPinDirection(MGPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);

	/* Initialize EXTI */
	MEXTI_voidInit();
	/* Set Callback */
	MEXTI_voidSetCallBack(func);
	/* Enable EXTI0 */
	MEXTI_voidEnableEXTI(EXTI_LINE0);
	while(1);
}

void func(void)
{
	MGPIO_voidSetPinValue(MGPIOA,PIN2,HIGH);
}
