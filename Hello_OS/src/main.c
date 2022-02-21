/*
 * main.c
 *
 *  Created on: Jan 26, 2022
 *      Author: Mahmoud Alaa
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "OS_interface.h"

void LED1(void);
void LED2(void);
void LED3(void);

void main(void)
{
	/* Initialize System Clock */
	MRCC_voidInitSysClock();
	/* Enable GPIOA Clock */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_APB2_GPIOA);

	/* Pins Directions */
	MGPIO_voidSetPinDirection(MGPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(MGPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(MGPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);


	/* Create3 Tasks */
	SOS_voidCreateTask(0,1000,LED1,0,READY);
	SOS_voidCreateTask(1,2000,LED2,1,READY);
	SOS_voidCreateTask(2,3000,LED3,2,READY);

	SOS_voidStart();

	while(1);
}

void LED1(void)
{
	static u8 Local_u8LED = 0;
	TOG_BIT(Local_u8LED,0);
	MGPIO_voidSetPinValue(MGPIOA,PIN0,Local_u8LED);
}

void LED2(void)
{
	static u8 Local_u8LED = 0;
	TOG_BIT(Local_u8LED,0);
	MGPIO_voidSetPinValue(MGPIOA,PIN1,Local_u8LED);
}

void LED3(void)
{
	static u8 Local_u8LED = 0;
	TOG_BIT(Local_u8LED,0);
	MGPIO_voidSetPinValue(MGPIOA,PIN2,Local_u8LED);
}
