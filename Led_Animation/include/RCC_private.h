/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	07 JAN 2022                                            */
/* Version	:	V01											           */
/***********************************************************************/

#ifndef  RCC_PRIVATE_H
#define	 RCC_PRIVATE_H

/* Register Definitions */
#define	MRCC_CR        				*((u32*)0x40021000)
#define	MRCC_CFGR		  			*((u32*)0x40021004)
#define	MRCC_CIR			  		*((u32*)0x40021008)
#define	MRCC_APB2RSTR	   			*((u32*)0x4002100C)
#define	MRCC_APB1RSTR	    		*((u32*)0x40021010)
#define	MRCC_AHBENR		    		*((u32*)0x40021014)
#define	MRCC_APB2ENR		    	*((u32*)0x40021018)
#define	MRCC_APB1ENR		    	*((u32*)0x4002101C)
#define	MRCC_BDCR		    		*((u32*)0x40021020)
#define	MRCC_CSR			    	*((u32*)0x40021024)

/* Clock Types */
#define MRCC_HSE_CRYSTAL			0
#define MRCC_HSE_RC		  			1
#define MRCC_HSI				    2
#define MRCC_PLL					3

/* PLL Options */
#define	MRCC_PLL_IN_HSI_DIV_2		0
#define	MRCC_PLL_IN_HSE_DIV_2		1
#define	MRCC_PLL_IN_HSE				2

/* PLL HSE Options */
#define MRCC_PLL_HSE_CRYSTAL		0
#define MRCC_PLL_HSE_RC				1

#endif
