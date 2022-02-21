/* Author	:	Mahmoud Alaa                                           */
/* Date		:	31 JAN 2022                                            */
/* Version	:	V01											           */
/***********************************************************************/
#ifndef	SPI_INTERFACE_H
#define	SPI_INTERFACE_H

/* Function Prototypes */
void MSPI1_voidInit(void);
void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8* Copy_u8DataToReceive);
void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*Copy_ptr) (u8));


/* Configurations Macros */
/* Clock Phase */
#define	MSPI_READ			0
#define	MSPI_WRITE			1

/* Clock Polarity */
#define MSPI_RISING			0
#define MSPI_FALLING		1

/* Device Type */
#define	MSPI_SLAVE			0
#define	MSPI_MASTER			1

/* Baud Rate PreScaler */
#define MSPI_FREQ_2			000
#define MSPI_FREQ_4			001
#define MSPI_FREQ_8     	010
#define MSPI_FREQ_16    	011
#define MSPI_FREQ_32		100
#define MSPI_FREQ_64    	101
#define MSPI_FREQ_128   	110
#define MSPI_FREQ_256   	111

/* Data Order */
#define MSPI_MSB		0
#define MSPI_LSB		1

#endif
