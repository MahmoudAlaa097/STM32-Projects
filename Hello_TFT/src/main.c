/*
 * main.c
 *
 *  Created on: Feb 5, 2022
 *      Author: Mahmoud Alaa
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"

#include "image.h"

void main(void)
{
	/* Initialize RCC */
	MRCC_voidInitSysClock();
	/* Enable GPIOA Clock */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_APB2_GPIOA);
	/* Enable SPI1 Clock */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_APB2_SPI1);

	/* Pin Directions */
	MGPIO_voidSetPinDirection(MGPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP); 		/* RST  */
	MGPIO_voidSetPinDirection(MGPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP); 		/* A0   */
	MGPIO_voidSetPinDirection(MGPIOA,PIN5,OUTPUT_SPEED_10MHZ_AFPP);		/* CLK  */
	MGPIO_voidSetPinDirection(MGPIOA,PIN7,OUTPUT_SPEED_10MHZ_AFPP);		/* MOSI */

	/* Initialize STK */
	MSTK_voidInit();

	/* Initialize SPI */
	MSPI1_voidInit();

	/* Initialize TFT */
	HTFT_voidInit();

	/* Display Image */
	HTFT_voidDisplay(image);

	while(1);
}
