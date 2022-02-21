/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	27 JAN 2022                                            */
/* Version	:	V02											           */
/***********************************************************************/

#ifndef	LEDMRX_CONFIG_H
#define	LEDMRX_CONFIG_H

/* Assume Square LED Matrix */
#define	LEDMRX_SIZE		8

/* Please write pin pair PORT,PIN
   Example: {MGPIOA,PIN0}        */
/* Rows Pins */
#define	LEDMRX_ROW0		{MGPIOA,PIN0}
#define	LEDMRX_ROW1     {MGPIOA,PIN1}
#define	LEDMRX_ROW2     {MGPIOA,PIN2}
#define	LEDMRX_ROW3     {MGPIOA,PIN3}
#define	LEDMRX_ROW4     {MGPIOA,PIN4}
#define	LEDMRX_ROW5     {MGPIOA,PIN5}
#define	LEDMRX_ROW6     {MGPIOA,PIN6}
#define	LEDMRX_ROW7     {MGPIOA,PIN7}

/* Columns Pins */
#define	LEDMRX_COL0		{MGPIOB,PIN0}
#define	LEDMRX_COL1     {MGPIOB,PIN1}
#define	LEDMRX_COL2     {MGPIOB,PIN5}
#define	LEDMRX_COL3     {MGPIOB,PIN6}
#define	LEDMRX_COL4     {MGPIOB,PIN7}
#define	LEDMRX_COL5     {MGPIOB,PIN8}
#define	LEDMRX_COL6     {MGPIOB,PIN9}
#define	LEDMRX_COL7     {MGPIOB,PIN10}

#endif
