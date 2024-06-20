/*==================================================================================================
 * 	@ File: SPI_Private.h
 *  @ Created on: Jun 8, 2023
 *  @ Author: HaDeeR
 *  @ Version : _1_
 ==================================================================================================*/


/*=====================================================================================
 * ===================    guard of file will call on time in .c	    ===================
 * =======================================================================================*/
#ifndef SPI_SPI_PRIVATE_H_
#define SPI_SPI_PRIVATE_H_

/*===============================================================================================
 *	 - Developer can't Edit in it
 *	  - Register _ Definition
 *	  - Design :
					- #define	:	YES
					- Union		:	NO
					- Struct	:	YES
===================================================================================================*/


/*----------------------------------------------------------------
 * 	-------> Macros
 * 						SPI base addresses
 * ---------------------------------------------------------------*/
#define SPI1_BASE_ADDRESS    0x40013000
#define SPI2_BASE_ADDRESS    0x40003800
#define SPI3_BASE_ADDRESS    0x40003C00
#define SPI4_BASE_ADDRESS    0x40013400
/*----------------------------------------------------------------
 * 			-------> CR1 register's bits
 ---------------------------------------------------------------*/
typedef struct
{
	volatile u32 CPHA	  :	1U 	;
	volatile u32 CPOL	  :	1U 	;
	volatile u32 MSTR	  :	1U 	;
	volatile u32 BR	 	  :	3U 	;
	volatile u32 SPE 	  :	1U 	;
	volatile u32 LSBFIRST :	1U 	;
	volatile u32 SSI	  :	1U 	;
	volatile u32 SSM	  :	1U 	;
	volatile u32 RXONLY	  :	1U 	;
	volatile u32 DFF	  :	1U 	;
	volatile u32 CRCNEXT  :	1U 	;
	volatile u32 CRCEN	  :	1U 	;
	volatile u32 BIDIOE	  :	1U 	;
	volatile u32 BIDIMODE :	1U 	;
	volatile u32 RESERVED :	16U	;
}CR1_REG;


/*----------------------------------------------------------------
 * 			------->  SR register's bits
 ---------------------------------------------------------------*/
/*typedef struct{
	volatile u32 RXNE		:	1U;
	volatile u32 TXE		:	1U;
	volatile u32 CHSIDE		:	1U;
	volatile u32 UDR		:	1U;
	volatile u32 CRCERR		:	1U;
	volatile u32 MODF		:	1U;
	volatile u32 OVR		:	1U;
	volatile u32 BSY		:	1U;
	volatile u32 FRE		:	1U;
	//-------------------------------------
	volatile u32 RESERVED 	:	23U;
}SR_t;
*/

/*----------------------------------------------------------------
 * ------->  SPI registers
 ---------------------------------------------------------------*/
typedef struct
{
	volatile CR1_REG	CR1;
	volatile u32	CR2;
	volatile u32	SR;
	volatile u32	DR;
	volatile u32	CRCPR;
	volatile u32	RXCRCR;
	volatile u32	TXCRCR;
	volatile u32	I2SCFGR;
	volatile u32	I2SPR;
}SPI_t;

/*================================================================
	-)Struct Macros :
			* SPI1_BASE_ADDRESS
=================================================================*/
#define 	MSPI1		((SPI_t * )(SPI1_BASE_ADDRESS))
/*================================================================
	-)Struct Macros :
			*  SPI2_BASE_ADDRESS
=================================================================*/
#define 	MSPI2		((SPI_t * )(SPI2_BASE_ADDRESS))
/*================================================================
	-)Struct Macros :
			*  SPI3_BASE_ADDRESS
=================================================================*/
#define 	MSPI3		((SPI_t * )(SPI3_BASE_ADDRESS))
/*================================================================
	-)Struct Macros :
			*  SPI4_BASE_ADDRESS
=================================================================*/
#define 	MSPI4		((SPI_t * )(SPI4_BASE_ADDRESS))

/*==================MACROS_PINS================================*/
#define RXNEIE         6U
#define TXEIE          7U
#define TXDMAEN        1U
#define RXDMAEN        0U
/*====================================*/
#define BSY          7U
#endif /* SPI_SPI_PRIVATE_H_ */
