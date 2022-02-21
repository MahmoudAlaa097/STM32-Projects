/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	10 JAN 2022                                            */
/* Version	:	V02											           */
/***********************************************************************/

#ifndef GPIO_PRIVATE
#define GPIO_PRIVATE

/* MGPIO Base Addresses */
#define 	MGPIOA_BASE_ADDRESS		 0x40010800
#define 	MGPIOB_BASE_ADDRESS		 0x40010C00
#define 	MGPIOC_BASE_ADDRESS		 0x40011000

/* MGPIOA Registers */
#define 	MGPIOA_CRL				 *((u32*)(MGPIOA_BASE_ADDRESS + 0x00))
#define 	MGPIOA_CRH				 *((u32*)(MGPIOA_BASE_ADDRESS + 0x04))
#define 	MGPIOA_IDR               *((u32*)(MGPIOA_BASE_ADDRESS + 0x08))
#define 	MGPIOA_ODR               *((u32*)(MGPIOA_BASE_ADDRESS + 0x0C))
#define 	MGPIOA_BSRR               *((u32*)(MGPIOA_BASE_ADDRESS + 0x10))
#define 	MGPIOA_BRR               *((u32*)(MGPIOA_BASE_ADDRESS + 0x14))
#define 	MGPIOA_LCK               *((u32*)(MGPIOA_BASE_ADDRESS + 0x18))

/* MGPIOA Registers */
#define 	MGPIOB_CRL				 *((u32*)(MGPIOB_BASE_ADDRESS + 0x00))
#define 	MGPIOB_CRH				 *((u32*)(MGPIOB_BASE_ADDRESS + 0x04))
#define 	MGPIOB_IDR               *((u32*)(MGPIOB_BASE_ADDRESS + 0x08))
#define 	MGPIOB_ODR               *((u32*)(MGPIOB_BASE_ADDRESS + 0x0C))
#define 	MGPIOB_BSRR               *((u32*)(MGPIOB_BASE_ADDRESS + 0x10))
#define 	MGPIOB_BRR               *((u32*)(MGPIOB_BASE_ADDRESS + 0x14))
#define 	MGPIOB_LCK               *((u32*)(MGPIOB_BASE_ADDRESS + 0x18))

/* MGPIOA Registers */
#define 	MGPIOC_CRL				 *((u32*)(MGPIOC_BASE_ADDRESS + 0x00))
#define 	MGPIOC_CRH				 *((u32*)(MGPIOC_BASE_ADDRESS + 0x04))
#define 	MGPIOC_IDR               *((u32*)(MGPIOC_BASE_ADDRESS + 0x08))
#define 	MGPIOC_ODR               *((u32*)(MGPIOC_BASE_ADDRESS + 0x0C))
#define 	MGPIOC_BSRR               *((u32*)(MGPIOC_BASE_ADDRESS + 0x10))
#define 	MGPIOC_BRR               *((u32*)(MGPIOC_BASE_ADDRESS + 0x14))
#define 	MGPIOC_LCK               *((u32*)(MGPIOC_BASE_ADDRESS + 0x18))

#endif
