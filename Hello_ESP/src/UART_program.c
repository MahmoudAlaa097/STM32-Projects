/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	5 FEB 2022                                             */
/* Version	:	V01											           */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void MUSART1_voidInit(void)
{
	/* Baud Rate */
	#if MUSART1_BAUD == MUSART1_4800
		MUSART1 -> BRR = 0x683;
	#elif MUSART1_BAUD == MUSART1_9600
		MUSART1 -> BRR = 0x341;
	#elif MUSART1_BAUD == MUSART1_115200
		MUSART1 -> BRR = 0x45;
	#else
		#error ("Wrong Baud Rate")
	#endif
	
	/* Word Length */
	#if MUSART1_WORD == MUSART1_8BIT
		CLR_BIT(MUSART1 -> CR1,12);
	#elif MUSART1_WORD == MUSART1_9BIT
		SET_BIT(MUSART1 -> CR1,12);
	#else
		#error("Wrong Word Length")
	#endif

	/* Parity Enable */
	#if MUSART1_PARITY == MUSART1_PARITY_DISABLE
		CLR_BIT(MUSART1 -> CR1,10);
	#elif MUSART1_PARITY == MUSART1_PARITY_ENABLE
		SET_BIT(MUSART1 -> CR1,10);
		#if MUSART1_PARITY_TYPE == MUSART1_PARITY_EVEN
			CLR_BIT(MUSART1 -> CR1,9);
		#elif MUSART1_PARITY_TYPE == MUSART1_PARITY_ODD
			SET_BIT(MUSART1 -> CR1,9);
		#else
			#error ("Wrong Parity Type")
		#endif
	#else
		#error ("Wrong Parity Selection")
	#endif

	/* Transmitter Enable */
	#if MUSART1_TX == MUSART1_DISABLE
		CLR_BIT(MUSART1 -> CR1, 3);
	#elif MUSART1_TX == MUSART1_ENABLE
		SET_BIT(MUSART1 -> CR1, 3);
	#else
		#error ("Wrong Transmitter Enable ")
	#endif

	/* Transmitter Enable */
		#if MUSART1_RX == MUSART1_DISABLE
			CLR_BIT(MUSART1 -> CR1, 2);
		#elif MUSART1_RX == MUSART1_ENABLE
			SET_BIT(MUSART1 -> CR1, 2);
		#else
			#error ("Wrong Receiver Enable ")
		#endif
	
	/* USART1 Enable */
	SET_BIT(MUSART1 -> CR1,13);

	/* Clear Status Register */
	MUSART1 -> SR = 0;
}

void MUSART1_voidTransmit(u8* Copy_u8DataToTransmit)
{
	u8 i = 0;
	while(Copy_u8DataToTransmit[i] != '\0')
	{
		MUSART1 -> DR = Copy_u8DataToTransmit[i];
		/* Wait till transmission complete */
		while(((MUSART1 -> SR) & 0x40)== 0);
		i++;
	}
}

u8	 MUSART1_u8Receive(u32 Copy_u32Timout)
{
	u32 Local_u32Timeout = 0;
	u8 Local_u8ReceiveData = 0;
	
	while( (GET_BIT((MUSART1 -> SR), 5)) == 0)
	{
		Local_u32Timeout++;
		
		if(Local_u32Timeout == Copy_u32Timout)
		{
			Local_u8ReceiveData = 255;
			break;
		}
	}
	
	if(Local_u8ReceiveData == 0)
	{
		Local_u8ReceiveData = MUSART1 -> DR;
	}
	
	return Local_u8ReceiveData;
}


u8 MUSART1_u8RecCharSynch ( void ){

	u8  LOC_u8Data  = 0 ;
	u32 LOC_TimeOut = 0 ;

	CLR_BIT ( MUSART1 -> SR, 5);

	while( ( GET_BIT ( MUSART1 -> SR, 5) == 0 ) && ( LOC_TimeOut < 10000 ) )
	{
		LOC_TimeOut++;
	}

	if( LOC_TimeOut == 10000 )
	{
		LOC_u8Data = 255;
	}
	else
	{

		LOC_u8Data = MUSART1 -> DR;
	}

	return LOC_u8Data;

}

u8 String[20];
u8 * MUSART1_PtrReadStringSynch ( void ){

	u8 LOC_Iterator = 0 , LOC_u8DataCome ;

	while( ( LOC_u8DataCome = MUSART1_u8RecCharSynch() ) != 13 ){

		String[ LOC_Iterator ] = LOC_u8DataCome ;
		LOC_Iterator++;
	}

	String[LOC_Iterator] = '\0';

	return ( String );

}
