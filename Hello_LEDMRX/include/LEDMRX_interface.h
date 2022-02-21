/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	27 JAN 2022                                            */
/* Version	:	V02											           */
/***********************************************************************/

#ifndef	LEDMRX_INTERFACE_H
#define	LEDMRX_INTERFACE_H

/* Functions Prototypes */
void HLEDMRX_voidInit(void);
void HLEDMRX_voidDisplay(u8* Copy_u8Data);
void HLEDMRX_voidShiftLeft(u8* Copy_u8Data,u8 Copy_u8InputCols);

#endif
