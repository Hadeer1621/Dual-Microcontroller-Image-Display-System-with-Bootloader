/*
 * SPI_Program.c
 *
 *  Created on: Jun 8, 2023
 *      Author: HaDeeR
 */


/*--------------------------------------------------------------------------
 -----------------------------LIB_INCLUDES-----------------------------
---------------------------------------------------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*--------------------------------------------------------------------------
 -----------------------------MCAL_INCLUDES-----------------------------
---------------------------------------------------------------------------*/
#include "SPI_Private.h"
#include "SPI_Interface.h"
#include "SPI_Config.h"

/*--------------------------------------------------------------------------
 --------------------------GLOBAL_DECLARATION----------------------------
---------------------------------------------------------------------------*/
void (*MSPI1_CallBack) (void);


/*--------------------------------------------------------------------------
 -----------------------------Functions Implementations-----------
---------------------------------------------------------------------------*/

/* 1- Function to configure the SPI */
void MSPI_vSPIInit(u8 Copy_u8SPIIndex)
{
/* Create Var from CR1_REG */
	CR1_REG  CFG ;
		/* 1.SET PHASE */
		CFG.CPHA = SPI_PHASE ;
		/* 2.SET PLO */
		CFG.CPOL = SPI_POLARITY;
		/* 3.SET MASTER OR SLAVE */
		CFG.MSTR = SPI_MASTER_SLAVE;
		/* 4.SET BOUD RATE */
		CFG.BR = BUAD_RATE;
		/* 5.SET SSM */
		CFG.SSM = SSM_STATE;
		/* 6.SET SSI */
		CFG.SSI = SSI_STATE;
		/* 7.SET DATA ORDER */
		CFG.LSBFIRST = DATA_ORDER;
		/* 8.SET DATA FORMAT */
		CFG.DFF = DATA_FORMAT;

		switch (Copy_u8SPIIndex)
		{
		case SPI_1_MODEL : MSPI1 -> CR1 =CFG; break;
		case SPI_2_MODEL: MSPI2 -> CR1 =CFG; break;
		case SPI_3_MODEL : MSPI3 -> CR1 =CFG; break;
		case SPI_4_MODEL : MSPI4 -> CR1 =CFG; break;
		default      : /*  */ break;

		}
}

void MSPI_vSPIEnable(u8 Copy_u8SPIIndex)
{
	switch (Copy_u8SPIIndex)
		{
		    case SPI_1_MODEL : MSPI1 -> CR1 . SPE=1U; break;
			case SPI_2_MODEL : MSPI2 -> CR1 . SPE=1U; break;
			case SPI_3_MODEL : MSPI3 -> CR1 . SPE=1U; break;
			case SPI_4_MODEL : MSPI4 -> CR1 . SPE=1U; break;
			default      : /* Erorr */ break;
		}

}
void MSPI_vSPIDisable(u8 Copy_u8SPIIndex)
{
	switch (Copy_u8SPIIndex)
			{
			    case SPI_1_MODEL : MSPI1 -> CR1 . SPE=0U; break;
				case SPI_2_MODEL : MSPI2 -> CR1 . SPE=0U; break;
				case SPI_3_MODEL : MSPI3 -> CR1 . SPE=0U; break;
				case SPI_4_MODEL : MSPI4 -> CR1 . SPE=0U; break;
				default      : /* Erorr */ break;

			}
}
//===========================================================================
u16 MSPI_u8SPISendRecive(u16 Copy_u8DataToSend)
{
		u16 Local_u16Data =0;
		/* check firstly if the SPI is busy or not */
			while (GET_BIT(MSPI1 -> SR , BSY)); /*BSY==1*/
			/* Go to data register "DR" and write into it the send data */
			MSPI1 -> DR = Copy_u8DataToSend;
			/* check firstly if the SPI is busy or not */
			while (GET_BIT(MSPI1 -> SR , BSY));
			/* Assign the send data to the received data local variable */
			Local_u16Data = MSPI1 -> DR;
			return Local_u16Data;
}

//===========================================================================
void MSPI1_vSPISetCallBack( void (*ptr) (void) ){

	MSPI1_CallBack = ptr;

}
//===========================================================================
void SPI1_IRQHandler(void){

	MSPI1_CallBack();

}
//===========================================================================
