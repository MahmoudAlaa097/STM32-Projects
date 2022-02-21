/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	10 JAN 2022                                            */
/* Version	:	V02											           */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode)
{
	/* Switch on Port */
	switch(Copy_u8Port)
	{
		case MGPIOA:
			/* Check on pin */
			if(Copy_u8Pin <= 7)
			{
				MGPIOA_CRL &= ~((0b1111)<< (Copy_u8Pin*4));			/* Reset coresponding bits */
				MGPIOA_CRL |= ((Copy_u8Mode)<< (Copy_u8Pin*4));		/* Set coresponding bits   */
			}
			else if (Copy_u8Pin <= 15)
			{
				MGPIOA_CRH &= ~((0b1111)<< ((Copy_u8Pin-8)*4));		/* Reset coresponding bits */
				MGPIOA_CRH |= ((Copy_u8Mode)<< ((Copy_u8Pin-8)*4));  /* Set coresponding bits   */
			}
			else
			{
				/* Error: wrong pin */
			}
			break;
		case MGPIOB:
			/* Check on pin */
			if(Copy_u8Pin <= 7)
			{
				MGPIOB_CRL &= ~((0b1111)<< (Copy_u8Pin*4));			/* Reset coresponding bits */
				MGPIOB_CRL |= ((Copy_u8Mode)<< (Copy_u8Pin*4));  	/* Set coresponding bits   */
			}
			else if (Copy_u8Pin <= 15)
			{
				MGPIOB_CRH &= ~((0b1111)<< ((Copy_u8Pin-8)*4));		/* Reset coresponding bits */
				MGPIOB_CRH |= ((Copy_u8Mode)<< ((Copy_u8Pin-8)*4));  /* Set coresponding bits   */
			}
			else
			{
				/* Error: wrong pin */
			}
			break;
		case MGPIOC:
			/* Check on pin */
			if(Copy_u8Pin <= 7)
			{
				MGPIOC_CRL &= ~((0b1111)<< (Copy_u8Pin*4));			/* Reset coresponding bits */
				MGPIOC_CRL |= ((Copy_u8Mode)<< (Copy_u8Pin*4));  	/* Set coresponding bits   */
			}
			else if (Copy_u8Pin <= 15)
			{
				MGPIOC_CRH &= ~((0b1111)<< ((Copy_u8Pin-8)*4));		/* Reset coresponding bits */
				MGPIOC_CRH |= ((Copy_u8Mode)<< ((Copy_u8Pin-8)*4));  /* Set coresponding bits   */
			}
			else
			{
				/* Error: wrong pin */
			}
			break;
		default : 
			/* Error: Wrong Port */ 
			break;
	}
}

void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	/* Switch on Port */
	switch(Copy_u8Port)
	{
		case MGPIOA:
			/* Check on value */
			if(Copy_u8Value == HIGH)
			{
				MGPIOA_BSRR = (1 << Copy_u8Pin);				/* Set bit to high */
			}
			else if(Copy_u8Value == LOW)
			{
				MGPIOA_BRR = (1 << Copy_u8Pin);				    /* Set bit to low */
			}
			else
			{
				/* Error: Wrong value */
			}
			break;
		case MGPIOB:
			/* Check on value */
			if(Copy_u8Value == HIGH)
			{
				MGPIOB_BSRR = (1 << Copy_u8Pin);				/* Set bit to high */
			}
			else if(Copy_u8Value == LOW)
			{
				MGPIOB_BRR = (1 << Copy_u8Pin);				    /* Set bit to low */
			}
			else
			{
				/* Error: Wrong value */
			}
			break;
		case MGPIOC:
			/* Check on value */
			if(Copy_u8Value == HIGH)
			{
				MGPIOC_BSRR = (1 << Copy_u8Pin);				/* Set bit to high */
			}
			else if(Copy_u8Value == LOW)
			{
				MGPIOC_BRR = (1 << Copy_u8Pin);				    /* Set bit to low */
			}
			else
			{
				/* Error: Wrong value */
			}
			break;
		default : /* Error: Wrong Port */ break;
	}
}

u8 MGPIO_voidGetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 LOC_u8Result = 0;									/* Create a local variable to hold the pin value */
	/* Switch on Port */
	switch(Copy_u8Port)
	{
		case MGPIOA:
			LOC_u8Result = GET_BIT(MGPIOA_IDR,Copy_u8Pin); 	/* Get pin value */
			break;
		case MGPIOB:
			LOC_u8Result = GET_BIT(MGPIOB_IDR,Copy_u8Pin);	/* Get pin value */
			break;
		case MGPIOC:
			LOC_u8Result = GET_BIT(MGPIOC_IDR,Copy_u8Pin);	/* Get pin value */
			break;
		default :
			/* Error: Wrong Port */
			break;
	}
	return LOC_u8Result;									/* Return Pin value */
}

void MGPIO_voidSetPortValue(u8 Copy_u8Port, u32 Copy_u8Value)
{
	/* Switch on Port */
	switch(Copy_u8Port)
	{
		case MGPIOA:
			/* Check on value */
			if(Copy_u8Value < 0x00010000)
			{
				MGPIOA_ODR = Copy_u8Value;				/* Set Port Value */
			}
			else
			{
				/* Error: Wrong Value */
			}
			break;
		case MGPIOB:
			/* Check on value */
			if(Copy_u8Value < 0x00010000)
			{
				MGPIOB_ODR = Copy_u8Value;				/* Set Port Value */
			}
			else
			{
				/* Error: Wrong Value */
			}
			break;
		case MGPIOC:
			/* Check on value */
			if(Copy_u8Value < 0x00010000)
			{
				MGPIOC_ODR = Copy_u8Value;				/* Set Port Value */
			}
			else
			{
				/* Error: Wrong Value */
			}
			break;
		default:
			/* Error: Wrong Port */
			break;
	}
}
void MGPIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	/* Switch on Port */
	switch(Copy_u8Port)
	{
		case MGPIOA:
			/* Check on pin */
			if(Copy_u8Pin < 16)
			{
				SET_BIT(MGPIOA_LCK,Copy_u8Pin);			/* Lock Pin Direction */
			}
			else
			{
				/* Error: wrong pin */
			}
			break;
		case MGPIOB:
			/* Check on pin */
			if(Copy_u8Pin < 16)
			{
				SET_BIT(MGPIOB_LCK,Copy_u8Pin);			/* Lock Pin Direction */
			}
			else
			{
				/* Error: wrong pin */
			}
			break;
		case MGPIOC:
			/* Check on pin */
			if(Copy_u8Pin < 16)
			{
				SET_BIT(MGPIOC_LCK,Copy_u8Pin);			/* Lock Pin Direction */
			}
			else
			{
				/* Error: wrong pin */
			}
			break;
		default:
			/* Error: Wrong Port */
			break;
	}
}
