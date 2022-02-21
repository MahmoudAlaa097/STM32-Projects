/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	07 JAN 2022                                            */
/* Version	:	V01											           */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidInitSysClock(void)
{
	#if 	MRCC_CLOCK_TYPE == MRCC_HSE_CRYSTAL
		MRCC_CR   = 0x00010000;	/* Enable HSE_CRYSTAL 		 		*/
		MRCC_CFGR = 0x00000001; 	/* Select HSE as input clock source */
	#elif	MRCC_CLOCK_TYPE == MRCC_HSE_RC
		MRCC_CR   = 0x00050000;	/* Enable HSE_RC 	  		 		*/
		MRCC_CFGR = 0x00000001;	/* Select HSE as input clock source */
	#elif	MRCC_CLOCK_TYPE == MRCC_HSI
		MRCC_CR   = 0x00000081;	/* Enable HSI + Trimming = 0        */
		MRCC_CFGR = 0x00000000;	/* Select HSI as input clock source */
	#elif	MRCC_CLOCK_TYPE == MRCC_PLL
		#if   MRCC_PLL_INPUT == MRCC_PLL_IN_HSI_DIV_2
			MRCC_CR   = 0x01000001;	/* Enable HSI & PLL */
			MRCC_CFGR = 0x00000002;	/* Select PLL as input clock source + HSI as PLL input clock source   */
		#elif MRCC_PLL_INPUT == MRCC_PLL_IN_HSE_DIV_2
			MRCC_CFGR = 0x00010002;	/* Select PLL as input clock source + HSE/2 as PLL input clock source */
			#if   MRCC_PLL_HSE == MRCC_PLL_HSE_CRYSTAL
				MRCC_CR   = 0x01010000;	/* Enable HSE_CRYSTAL & PLL */
			#elif MRCC_PLL_HSE == MRCC_PLL_HSE_RC
				MRCC_CR   = 0x01050000;	/* Enable HSE_RC & PLL      */
			#else
				#error("You chose wrong HSE type")
			#endif
		#elif MRCC_PLL_INPUT == MRCC_PLL_IN_HSE
			MRCC_CFGR = 0x00020002;	/* Select PLL as input clock source + HSE as PLL input clock source */
			#if   MRCC_PLL_HSE == MRCC_PLL_HSE_CRYSTAL
				MRCC_CR   = 0x01010000;	/* Enable HSE_CRYSTAL & PLL */
			#elif MRCC_PLL_HSE == MRCC_PLL_HSE_RC
				MRCC_CR   = 0x01050000;	/* Enable HSE_RC & PLL      */
			#else
				#error("You chosed wrong HSE type")
			#endif
		#else
			#error("You chosed wrong PLL clock source type")
		#endif
	#else
		#error("You chosed wrong Clock type")
	#endif
}

void MRCC_voidEnableClock(u8 Copy_u8Bus, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch (Copy_u8Bus)
		{
			case MRCC_AHB	: SET_BIT(MRCC_AHBENR ,Copy_u8PerId);	break;
			case MRCC_APB1	: SET_BIT(MRCC_APB1ENR,Copy_u8PerId);    break;
			case MRCC_APB2	: SET_BIT(MRCC_APB2ENR,Copy_u8PerId);    break;
		}
	}
	else
	{
		/* Return Error */
	}
}

void MRCC_voidDisableClock(u8 Copy_u8Bus, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch (Copy_u8Bus)
		{
			case MRCC_AHB	: CLR_BIT(MRCC_AHBENR ,Copy_u8PerId);	break;
			case MRCC_APB1	: CLR_BIT(MRCC_APB1ENR,Copy_u8PerId);    break;
			case MRCC_APB2	: CLR_BIT(MRCC_APB2ENR,Copy_u8PerId);    break;
		}
	}
	else
	{
		/* Return Error */
	}
}
