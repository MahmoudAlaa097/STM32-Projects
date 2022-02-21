/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	13 JAN 2022                                            */
/* Version	:	V01													   */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidEnableInerrrupt(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		NVIC_ISER1 = (1 << (Copy_u8IntNumber-32));
	}
	else
	{
		/* Return Error */
	}
}

void MNVIC_voidDisnableInerrrupt(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		NVIC_ICER1 = (1 << (Copy_u8IntNumber-32));
	}
	else
	{
		/* Return Error */
	}
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		NVIC_ISPR1 = (1 << (Copy_u8IntNumber-32));
	}
	else
	{
		/* Return Error */
	}
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		NVIC_ICPR1 = (1 << (Copy_u8IntNumber-32));
	}
	else
	{
		/* Return Error */
	}
}

u8 MNVIC_u8GetPendingFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result = 0;
	if(Copy_u8IntNumber <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
	return Local_u8Result;
}

void MNVIC_voidSetPriorityFlag(s8 Copy_s8IntId,u8 Copy_u8GroupPriority,u8 Copy_u8SubGroupPriority,u32 Copy_u8Group)
{
	u32 Local_u8Priority = Copy_u8SubGroupPriority|(Copy_u8GroupPriority<<((Copy_u8Group - 0x05FA0300)/256));
	/* Core Peripheral */
	
	/* External Peripheral */
	if(Copy_s8IntId >= 0)
	{
		NVIC_IPR[Copy_s8IntId] = Local_u8Priority << 4;
	}
	SCB_AIRCR = Copy_u8Group;
}
