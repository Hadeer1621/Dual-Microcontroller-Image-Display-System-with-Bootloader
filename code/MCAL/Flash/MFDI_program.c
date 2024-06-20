/************************************************************/
/*		Author : Hadeer									*/
/*		Version: V01										*/
/*		Date   : 18 June 2023								*/
/* Description       : MFDI_program.c --> implementations   */
/* Module  Features  :                      				*/
/*      01- MFDI_voidEraseSector                 			*/
/*      02- MFDI_voidProgramFlash            				*/
/*      03- MFDI_voidEraseMass      						*/
/************************************************************/

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/
#include <BIT_MATH.h>
#include <STD_TYPES.h>

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

#include "MFDI_interface.h"
#include "MFDI_private.h"
#include "MFDI_config.h"

/***********************************************************************************************************/
/*                                      01- MFDI_voidEraseSector                                           */
/*---------------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Erase a specific sector in the flash memory.	   		   					   */
/* 2- Function Input       -> Copy_u8SectorNumber                                         				   */
/*		-Copy_u8SectorNumber: Number of sector that will be erased										   */
/* 3- Function Return      -> Nothing                                                                 	   */
/***********************************************************************************************************/
void MFDI_voidEraseSector(Sector_IDS Copy_u8SectorNumber )
{
	/*Step 1: Check BSY flag */
	while(GET_BIT(FDI->SR,BSY)==1);

	/*Step 2: If flash is locked, unlock it*/
	if(GET_BIT(FDI->SR,LOCK)==1){
		FDI->KEYR = FLASH_ACCESS_KEY1;
		FDI->KEYR = FLASH_ACCESS_KEY2;
	}
	else{
		//Do nothing
	}

	/*Step 3: Choose sector number*/
	FDI->CR &= FLASH_CLEAR_SECTOR_BITS;
	FDI->CR |= Copy_u8SectorNumber<<3  ;

	/*Step 4: Activate sector erase*/
	SET_BIT(FDI->CR,SER);

	/*Step 5: Start erase operation */
	SET_BIT(FDI->CR,STRT);

	/*Step 6: Check BSY flag */
	while(GET_BIT(FDI->SR,BSY)==1);

	/*Step 7: Clear the EOP flag */
	SET_BIT(FDI->SR,EOP) ;

	/*Step 8: Deactivate sector erase*/
	CLR_BIT(FDI->CR,SER) ;
}

void MFDI_voidEraseMass(void)
{
	u8 Local_u8Iterator;
	for( Local_u8Iterator=SECTOR_1;Local_u8Iterator<=SECTOR_5;Local_u8Iterator++){
		MFDI_voidEraseSector(Local_u8Iterator);
	}
}

void MFDI_voidProgramFlash(u32 Copy_u32DataAddress,u32 *Copy_u32Data,u32 Copy_u32DataSize)
{
	u8 Local_u8Iterator;//To iterate over data array and send half a word each time

	/*Step 1: Check BSY flag */
	while(GET_BIT(FDI->SR,BSY)==1);

	/*Step 2: If flash is locked, unlock it*/
	if(GET_BIT(FDI->SR,LOCK)==1){
		FDI->KEYR = FLASH_ACCESS_KEY1;
		FDI->KEYR = FLASH_ACCESS_KEY2;
	}
	else{
		//Do nothing
	}

	/*Step 3: Select PSIZE --> half word (x16)*/
	/* Program size options
	 * 00 program x8
	   01 program x16
	   10 program x32
	   11 program x64*/
	SET_BIT(FDI->CR,PSIZE0);
	CLR_BIT(FDI->CR,PSIZE1);

	for(Local_u8Iterator =0; Local_u8Iterator<Copy_u32DataSize;Local_u8Iterator++){
		/*Step 4: Enable programming (i.e. writing)*/
		SET_BIT(FDI->CR,PG);

		/*Step 5: Place data in passed address after casting for half word access */
		*((volatile u16 *) Copy_u32DataAddress) = Copy_u32Data[Local_u8Iterator];
		Copy_u32DataAddress+=2; /* Increase address by two to write in the next 16 bits (move by 2 bytes)*/

		/*Step 6: Check BSY flag */
		while(GET_BIT(FDI->SR,BSY)==1);

		/*Step 7: Clear the EOP flag */
		SET_BIT(FDI->SR,EOP) ;

		/*Step 8: Deactivate sector program*/
		CLR_BIT(FDI->CR,PG) ;
	}
}


