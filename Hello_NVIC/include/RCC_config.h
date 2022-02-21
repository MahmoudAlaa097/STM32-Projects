/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	07 JAN 2022                                            */
/* Version	:	V01											           */
/***********************************************************************/

#ifndef  RCC_CONFIG_H
#define	 RCC_CONFIG_H

/* Options:		MRCC_HSE_CRYSTAL
				MRCC_HSE_RC
				MRCC_HSI
				MRCC_PLL				*/
#define	MRCC_CLOCK_TYPE	MRCC_HSE_CRYSTAL

/* Note: Select value only if uou have PLL as input clock source */
#if MRCC_CLOCK_TYPE == MRCC_PLL
	/* Options:		MRCC_PLL_IN_HSI_DIV_2
					MRCC_PLL_IN_HSE_DIV_2
					MRCC_PLL_IN_HSE		*/
	#define	MRCC_PLL_INPUT	MRCC_PLL_IN_HSE_DIV_2

	#if (MRCC_PLL_INPUT == MRCC_PLL_IN_HSE_DIV_2) || (MRCC_PLL_INPUT == MRCC_PLL_IN_HSE)
		/* Options:		MRCC_PLL_HSE_CRYSTAL
						MRCC_PLL_HSE_RC		*/
		#define	MRCC_PLL_HSE		MRCC_PLL_HSE_CRYSTAL
	#endif

	/* Options 2 to 16 */
	#define MRCC_PLL_MUL_VAL	4

#endif

#endif
