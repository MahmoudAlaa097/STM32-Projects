/*
 * main.c
 *
 *  Created on: Jan 20, 2022
 *      Author: Mahmoud Alaa
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

void PingPong(u8 Copy_u8Times)
{
	for(u8 i=0;i<Copy_u8Times;i++)
		{
			for(u8 PIN=PIN0;PIN<8;PIN++)
			{
				MGPIO_voidSetPinValue(MGPIOA,PIN,HIGH);
				MSTK_voidSetBusyWait(199999);
				MGPIO_voidSetPinValue(MGPIOA,PIN,LOW);
			}
			for(u8 PIN=PIN6;PIN>0;PIN--)
			{
				MGPIO_voidSetPinValue(MGPIOA,PIN,HIGH);
				MSTK_voidSetBusyWait(199999);
				MGPIO_voidSetPinValue(MGPIOA,PIN,LOW);
			}
		}
}

void In_Out(n)
{
	for(u8 i=0;i<n;i++)
		{
			for(u8 PIN=0;PIN<4;PIN++)
			{
				MGPIO_voidSetPinValue(MGPIOA,PIN3-PIN,HIGH);
				MGPIO_voidSetPinValue(MGPIOA,PIN4+PIN,HIGH);
				MSTK_voidSetBusyWait(199999);
			}
			for(u8 PIN=0;PIN<4;PIN++)
			{
				MGPIO_voidSetPinValue(MGPIOA,PIN0+PIN,LOW);
				MGPIO_voidSetPinValue(MGPIOA,PIN7-PIN,LOW);
				MSTK_voidSetBusyWait(199999);
			}
		}
}

void Flashing(u8 Copy_u8Times)
{
	for(u8 i=0;i<Copy_u8Times;i++)
	{
		MSTK_voidSetBusyWait(499999);
		for(u8 Loc_u8Index=0;Loc_u8Index<8;Loc_u8Index++)
		{
			MGPIO_voidSetPinValue(MGPIOA,Loc_u8Index,HIGH);
		}
		MSTK_voidSetBusyWait(499999);
		for(u8 Loc_u8Index=0;Loc_u8Index<8;Loc_u8Index++)
		{
			MGPIO_voidSetPinValue(MGPIOA,Loc_u8Index,LOW);
		}
	}
}

void main(void)
{
	/* Initialize System Clock */
	MRCC_voidInitSysClock();
	/* Initialize SysTick */
	MSTK_voidInit();
	/* Enable GPIOA Clock */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_APB2_GPIOA);
	/* Pins Modes */
	for(u8 Loc_u8Index=PIN0;Loc_u8Index<8;Loc_u8Index++)
	{
		MGPIO_voidSetPinDirection(MGPIOA,Loc_u8Index,OUTPUT_SPEED_10MHZ_PP);
	}
	/* Clearing All PINS */
	for(u8 Loc_u8Index=0;Loc_u8Index<8;Loc_u8Index++)
	{
		MGPIO_voidSetPinValue(MGPIOA,Loc_u8Index,LOW);
	}
	while(1)
	{	/* PingPong Animation */
		PingPong(4);
		/* In Out Animation */
		In_Out(4);
		/* Flashing Animation */
		Flashing(8);
	}
}
