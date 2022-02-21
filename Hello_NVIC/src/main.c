/*
 * main.c
 *
 *  Created on: Jan 14, 2022
 *      Author: Mahmoud Alaa
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"

void main(void)
{
	/* Initialize Clock */
	MRCC_voidInitSysClock();
	/* Enable Clock for GPIO */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_APB2_GPIOA);
	/* PIN Modes */
	MGPIO_voidSetPinDirection(MGPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);	/*A0 Output PP 2 MHZ */
	MGPIO_voidSetPinDirection(MGPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);	/*A1 Output PP 2 MHZ */
	MGPIO_voidSetPinDirection(MGPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);	/*A2 Output PP 2 MHZ */
	/* Initialize NVIC */
	MNVIC_voidInit();

	/* Set EXTI0 Priority */
	MNVIC_voidSetPriority(6,0b01000000); /* EXTI0 Group 1 & Sub 0 */
	/* Set EXTI1 Priority */
	MNVIC_voidSetPriority(7,0b00110000); /* EXTI1 Group 0 & Sub 3 */
	/* Enable EXTI0 interrupt from NVIC */
	MNVIC_voidEnableInerrrupt(6);
	/* Enable EXTI1 interrupt from NVIC */
	MNVIC_voidEnableInerrrupt(7);
	/* Set Pending Flag for EXTI0 */
	MNVIC_voidSetPendingFlag(6);
	while(1);
}

void EXTI0_IRQHandler(void)
{
	/* Set PIN0 to HIGH */
	MGPIO_voidSetPinValue(MGPIOA,PIN0,HIGH);
	/* Set Pending Flag for EXTI0 */
	MNVIC_voidSetPendingFlag(7);
	/* Set PIN1 to HIGH */
	MGPIO_voidSetPinValue(MGPIOA,PIN1,HIGH);
}

void EXTI1_IRQHandler(void)
{
	/* Set PIN2 to HIGH */
	MGPIO_voidSetPinValue(MGPIOA,PIN2,HIGH);
}
