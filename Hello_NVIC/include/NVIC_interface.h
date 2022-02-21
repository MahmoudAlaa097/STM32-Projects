/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	13 JAN 2022                                            */
/* Version	:	V01													   */
/***********************************************************************/

#ifndef NVIC_INTERFACE_H
#define	NVIC_INTERFACE_H

/* Functions Prototypes */
void MNVIC_voidInit(void);
void MNVIC_voidEnableInerrrupt	(u8 Copy_u8IntNumber);
void MNVIC_voidDisnableInerrrupt(u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag	(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag	(u8 Copy_u8IntNumber);
u8 MNVIC_u8GetPendingFlag		(u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx,u8 Copy_u8Priority);
void MNVIC_voidSetPriorityFlag(s8 Copy_s8IntId,u8 Copy_u8GroupPriority,u8 Copy_u8SubGroupPriority,u32 Copy_u8Group);

#endif