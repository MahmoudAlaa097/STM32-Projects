/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Mahmoud Alaa
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "UART_interface.h"
#include "FPEC_interface.h"

/* Parse Function Prototype */
void Parser_voidParseRecord(u8* Copy_u8BufData);

volatile u8  u8RecBuffer[100]   ;
volatile u8  u8RecCounter    = 0;
volatile u8  u8TimeOutFlag   = 0;
volatile u16 u16TimerCounter = 0;
volatile u8  u8BLWriteReq    = 1;
typedef void (*Function_t)(void);
Function_t addr_to_call = 0;

void JumpToApp(void)
{
#define SCB_VTOR   *((volatile u32*)0xE000ED08)

	SCB_VTOR = 0x08001000;

	addr_to_call = *(Function_t*)(0x08001004);
	addr_to_call();
}

void main(void)
{
	u8 Local_u8RecStatus;

	/* Initialize System Clock => HSI */
	MRCC_voidInitSysClock();
	/* Enable GPIOA Clock */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_APB2_GPIOA);
	/* Enable USART Clock */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_APB2_USART1);
	/* Enable FPEC Clock */
	MRCC_voidEnableClock(MRCC_AHB,MRCC_AHB_FPEC);

	/* Pin Direction */
	/* TX: Pin A9 => Alternative Function Push PUll @2MHz*/
	MGPIO_voidSetPinDirection(MGPIOA,PIN9,OUTPUT_SPEED_2MHZ_AFPP);
	/* RX: Pin A10 => Input Floating */
	MGPIO_voidSetPinDirection(MGPIOA,PIN10,INPUT_FLOATING);

	/* Initialize SysTick Clock => AHB/8 */
	MSTK_voidInit();

	/* Initialize USART1 */
	MUSART1_voidInit();

	/* Set Timer Interval to 15 s and jump to the APP */
	MSTK_voidSetIntervalPeriodic(15000000,JumpToApp);

	while(u8TimeOutFlag == 0)
	{
		Local_u8RecStatus = MUSART1_u8Receive( &(u8RecBuffer[u8RecCounter]) );
		/* Check if received data or not */
		if(Local_u8RecStatus == 1)
		{
			/* Stop Timer */
			MSTK_voidStopTimer();

			/* Check if it is the end of the record */
			if(u8RecBuffer[u8RecCounter] == '\n')
			{
				if (u8BLWriteReq == 1)
				{
					/* Erase APP Area */
					MFPEC_voidEraseAppArea();
					/* Update Flag */
					u8BLWriteReq = 0;
				}
				/* Parse the record */
				Parser_voidParseRecord(u8RecBuffer);
				/* Send "ok" */
				MUSART1_voidTransmit("ok");
				u8RecCounter = 0;
			}

			else
			{
				/* If not the end of the record => increment the counter */
				u8RecCounter++;
			}
		}
	}

}
