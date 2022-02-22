/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	5 FEB 2022                                             */
/* Version	:	V01											           */
/***********************************************************************/
#ifndef	UART_INTERFACE_H
#define	UART_INTERFACE_H

/* Functions Prototypes */
void MUSART1_voidInit(void);
void MUSART1_voidTransmit(u8* Copy_u8DataToTransmit);
u8	 MUSART1_u8Receive(u32 Copy_u32Timout);

u8 MUSART1_u8RecCharSynch ( void );
u8 * MUSART1_PtrReadStringSynch ( void );

#endif
