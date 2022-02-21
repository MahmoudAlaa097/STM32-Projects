/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	15 JAN 2022                                            */
/* Version	:	V01											           */
/***********************************************************************/

#ifndef	STK_INTERFACE_H
#define	STK_INTERFACE_H

/* Functions Prototypes */
void MSTK_voidInit();						/* Apply clock choice, Disable SysTick and Disable SysTick Interrupt */
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void));
void MSTK_voidStopTimer();
u32	MSTK_u32GetElapsedTime();
u32	MSTK_u32GetRemaningTime();

#endif
