/**********************************************************/
/***********  Author       :Hadeer		         ********/
/***********  Version      :V01                    ********/
/***********  Date         :14/6/2020               ********/
/***********  Description  :FLASH_program function  *******/
/**********************************************************/



/*********************************************************/
/**************   STD LIB DIRECTIVES  ********************/
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*********************************************************/
/***************  Component DIRECTIVES  ******************/
/*********************************************************/

#include      "MFlash_Private.h"
#include      "MFlash_Interface.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   : This initialize FLASH                 */
/*                                                       */
/*                 Inputs : void                         */
/*                 return : void                         */
/*********************************************************/

void FLASH_vidInit(void)
{
	FLASH_vidUnlock();
}

/**********************************************************************************/
/*************************  FUNCTION Implementation  ******************************/
/**********************************************************************************/

/**********************************************************************************/
/*                                                                                *
 *                            UnLocking FLASH memory                              *
 *                                                                                *
 **********************************************************************************/

void FLASH_vidUnlock( void )
{
	/*Unlock flash if lock bit = 1*/
	if(GET_BIT(FLASH->CR , LOCK)==1)
	{
		FLASH->KEYR=FLASH_KEY1_FKEYR;
		FLASH->KEYR=FLASH_KEY2_FKEYR;
	}

}
/**********************************************************************************/
/*                                                                                *
 *                              Locking FLASH memory                              *
 *                                                                                *
 **********************************************************************************/

void FLASH_vidlock( void )
{
	/*wait if Busy == 1 in SR*/
	while(GET_BIT(FLASH->SR , BSY) ==1) ;

	/*Set EOP Bit in SR --> to Clear the Flag OF EOF */
	SET_BIT(FLASH->SR, EOP) ;

	SET_BIT(FLASH->CR , LOCK);
}

/**********************************************************************************/
/*************************  FUNCTION Implementation  ******************************/
/**********************************************************************************/
/**********************************************************************************/
/* Wait for the FLASH operation to complete by polling on BUSY flag to be reset.  *
 * Even if the FLASH operation fails, the BUSY flag will be reset and an error    *
 * flag will be set                                                               *
 **********************************************************************************/

void FLASH_vidWaitFlashIfBusy(void)
{

	// POLLING
	while(GET_BIT(FLASH->SR ,BSY));

	/* Check FLASH End of Operation flag  */
	if(GET_BIT(FLASH->SR , EOP))
	{
		/* Clear FLASH End of Operation pending bit by setting one  */
		SET_BIT(FLASH->SR , EOP);
	}

}
/**********************************************************************************/
/*************************  FUNCTION Implementation  ******************************/
/**********************************************************************************/
/* ********************************************************************************
 *                                                                                *
 *        Erase the specified FLASH memory sector by the sector num               *
 *                                                                                *
 * ********************************************************************************/

void FLASH_vidSectorErase(u32 Copy_u8SectorNumber)
{
	/*wait if Busy */
	// POLLING
	while(GET_BIT(FLASH->SR ,BSY));

	/*Unlock flash if lock bit = 1*/
	FLASH_vidUnlock();

	/*Set Number Of Sectors  in CR */
	FLASH->CR &= 0XFFFFFF87 ;     /*clear bits from bit3 to bit6*/
	FLASH->CR |= Copy_u8SectorNumber<<3  ;

	/*Set SER bit --> to Activate Sector Erase*/
	SET_BIT(FLASH->CR,SER) ;

	/*Set start Bit */
	SET_BIT(FLASH->CR,STRT) ;

	/*wait if Busy == 1 in SR*/
	FLASH_vidWaitFlashIfBusy;

	/*Clear SER bit --> to Deactivate Sector Erase*/
	CLR_BIT(FLASH->CR , SER) ;

}

/**********************************************************************************/
/*************************  FUNCTION Implementation  ******************************/
/**********************************************************************************/
/* ********************************************************************************
 *                                                                                *
 *        Erase the specified FLASH memory sectors for APP                        *
 *                                                                                *
 * ********************************************************************************/
void MFDI_vidEraseAppArea(void)
{
	u8 LOC_u8Iterator ;

	for( LOC_u8Iterator = 1 ; LOC_u8Iterator < 8 ; LOC_u8Iterator++)
	{
		FLASH_vidSectorErase(LOC_u8Iterator) ;
	}
}
/**********************************************************************************/
/*************************  FUNCTION Implementation  ******************************/
/**********************************************************************************/
/* ********************************************************************************
 *                                                                                *
 *               Program a half-word (16-bit) at a specified address              *
 *                                                                                *
 * ********************************************************************************/

void FLASH_vidProgramHalfWord(u32 Copy_u32Address ,u16* Copy_PtrData, u8 Copy_u8DataLength)
{
	u8 LOC_u8Iterator ;

	/*wait if Busy == 1 in SR*/
	// POLLING
	while(GET_BIT(FLASH->SR ,BSY));

	/*Unlock flash if lock bit = 1*/
	FLASH_vidUnlock();

	/*Select PSize in CR --> Half Word*/
	FLASH->CR &= 0XFFFFFCFF ;     /*clear bits from bit8 to bit9  -->[1100]*/ // FLASH OPERATION MASK
	FLASH->CR |= WRITE_HALF_WORD<<8  ; /* half word  */


	for(LOC_u8Iterator = 0 ; LOC_u8Iterator < Copy_u8DataLength ; LOC_u8Iterator++ )
	{
		/*Set PG Bit in CR --> to Activate Programming Flash*/
		SET_BIT(FLASH->CR,PG) ;

		*((volatile u16*)Copy_u32Address) = Copy_PtrData[LOC_u8Iterator]  ;
		Copy_u32Address +=2 ;


		/*wait if Busy in SR*/
		FLASH_vidWaitFlashIfBusy;

		/*Clear PG bit --> to Deactivate Programming*/
		CLR_BIT(FLASH->CR , PG) ;
	}

}


