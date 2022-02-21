/**********************************************************************/
/* Author	:	Mahmoud AlLaa                                           */
/* Date		:	27 JAN 2022                                            */
/* Version	:	V02											           */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

u8 LEDMRX_u8Rows[8][2] = {LEDMRX_ROW0,LEDMRX_ROW1,LEDMRX_ROW2,LEDMRX_ROW3,LEDMRX_ROW4,LEDMRX_ROW5,LEDMRX_ROW6,LEDMRX_ROW7};
u8 LEDMRX_u8Cols[8][2] = {LEDMRX_COL0,LEDMRX_COL1,LEDMRX_COL2,LEDMRX_COL3,LEDMRX_COL4,LEDMRX_COL5,LEDMRX_COL6,LEDMRX_COL7};

void HLEDMRX_voidInit(void)
{
	/* Initialize Rows Pins */
	for(u8 Local_u8Index=0;Local_u8Index<8;Local_u8Index++)
	{
		MGPIO_voidSetPinDirection(LEDMRX_u8Rows[Local_u8Index][0],LEDMRX_u8Rows[Local_u8Index][1],OUTPUT_SPEED_2MHZ_PP);
	}
	
	/* Initialize Columns Pins */
	for(u8 Local_u8Index=0;Local_u8Index<8;Local_u8Index++)
	{
		MGPIO_voidSetPinDirection(LEDMRX_u8Cols[Local_u8Index][0],LEDMRX_u8Cols[Local_u8Index][1],OUTPUT_SPEED_2MHZ_PP);
	}
}

void HLEDMRX_voidDisplay(u8* Copy_u8Data)
{
	for(u8 Local_u8Index=0;Local_u8Index<LEDMRX_SIZE;Local_u8Index++)
	{
		/* Disable All Columns */
		HLEDMRX_voidDisableAllColumns();
		/* Set Rows Value */
		HLEDMRX_voidSetRowsValue(Copy_u8Data[Local_u8Index]);
		/* Enable Column  */
		MGPIO_voidSetPinValue(LEDMRX_u8Cols[Local_u8Index][0],LEDMRX_u8Cols[Local_u8Index][1],LOW);
		/* Delay: 2.5 msec */
		MSTK_voidSetBusyWait(2500);
	}
}

static void HLEDMRX_voidDisableAllColumns(void)
{
	for(u8 Local_u8Index=0;Local_u8Index<LEDMRX_SIZE;Local_u8Index++)
	{
		MGPIO_voidSetPinValue(LEDMRX_u8Cols[Local_u8Index][0],LEDMRX_u8Cols[Local_u8Index][1],HIGH);
	}
}

static void HLEDMRX_voidSetRowsValue(u8 Copy_u8Data)
{
	for(u8 Local_u8Index=0;Local_u8Index<LEDMRX_SIZE;Local_u8Index++)
	{
		MGPIO_voidSetPinValue(LEDMRX_u8Rows[Local_u8Index][0],LEDMRX_u8Rows[Local_u8Index][1],GET_BIT(Copy_u8Data,Local_u8Index));
	}
}

void HLEDMRX_voidShiftLeft(u8* Copy_u8Data, u8 Copy_u8InputCols)
{
	for(u8 Local_u8Iteration=0;Local_u8Iteration<=Copy_u8InputCols;Local_u8Iteration++)
	{
		HLEDMRX_voidDisplay(Copy_u8Data+Local_u8Iteration);
		MSTK_voidSetBusyWait(40000);
	}
}
