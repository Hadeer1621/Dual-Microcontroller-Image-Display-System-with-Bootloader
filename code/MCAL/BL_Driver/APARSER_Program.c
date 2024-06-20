/*
***************************************************
*   file    :  APARSER_Program.c
*   Author   : Hadeer
*    Data    : 18-6-2023
*    Brief   : 
*    Version :  1.00.00
*************************************************** 
*/



/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/


#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

#include "MFlash_Interface.h"
#include "APARSER_Interface.h"



u32 GLB_u32Address  = 0x08000000;

u16 GLB_u16Data[100] ;

u8 APARSER_u8AsciiToHex(u8 Copy_u8Asci)
{

	u8 LOC_u8Result = 0 ;
     // for numbers from 0 to 9
	if((Copy_u8Asci >=48) && (Copy_u8Asci <=57) )
	{
		LOC_u8Result = Copy_u8Asci - 48 ;
	}
	else // for numbers from A to F
	{
		LOC_u8Result = Copy_u8Asci  - 55 ;
	}

	return LOC_u8Result ;

}



void APARSER_voidParseRecord(u8 * Copy_u8BufRecord)
{
	/* switching on record type */
	switch(Copy_u8BufRecord[8])
	{  // data
	case '0' : APARSE_voidParseData(Copy_u8BufRecord);  break ;
	case '4' : /*Set High Address part*/                break ;
	case '1' : /*End Of File*/                          break ;
	}

}


void APARSE_voidParseData(u8* Copy_u8BufData)
{
	/******************************************************************************************************/
	/*######################################## Local Variables ###########################################*/
	/******************************************************************************************************/

	/*For Character Count*/
	u8 LOC_u8CCDigitHigh ;
	u8 LOC_u8CCDigitLow ;
	u8 LOC_u8CharacterCount ;

	/*For Address 4 Digits*/
	u8 LOC_u8Digit0 ;
	u8 LOC_u8Digit1 ;
	u8 LOC_u8Digit2 ;
	u8 LOC_u8Digit3 ;

	/*Iterator For Data  Loop*/
	u8 LOC_u8Result = 0 ;


	/******************************************************************************************************/
	/*############################################### Parsing ############################################*/
	/******************************************************************************************************/
	/*Receive CC*/
	LOC_u8CCDigitHigh = APARSER_u8AsciiToHex(Copy_u8BufData[1]) ;
	LOC_u8CCDigitLow  = APARSER_u8AsciiToHex(Copy_u8BufData[2]);
	LOC_u8CharacterCount =  LOC_u8CCDigitHigh<<4 | LOC_u8CCDigitLow ; //merging u8
	/*Receive Low part Address Address*/
	LOC_u8Digit0 = APARSER_u8AsciiToHex(Copy_u8BufData[3]);//4
	LOC_u8Digit1 = APARSER_u8AsciiToHex(Copy_u8BufData[4]);//0
	LOC_u8Digit2 = APARSER_u8AsciiToHex(Copy_u8BufData[5]);//0
	LOC_u8Digit3 = APARSER_u8AsciiToHex(Copy_u8BufData[6]);//0

	GLB_u32Address &= 0xFFFF0000 ;  ///4000

	GLB_u32Address |= (LOC_u8Digit0<<12) | (LOC_u8Digit1<<8) | (LOC_u8Digit2<<4) |(LOC_u8Digit3)  ;


	for(LOC_u8Result = 0 ; LOC_u8Result < (LOC_u8CharacterCount / 2) ; LOC_u8Result++  )
	{
		/*Receive  Half Word Data [4 Digits]*/
		LOC_u8Digit0 = APARSER_u8AsciiToHex(Copy_u8BufData[(4 * LOC_u8Result) + 9]);//after record type
		LOC_u8Digit1 = APARSER_u8AsciiToHex(Copy_u8BufData[(4 * LOC_u8Result) + 10]);
		LOC_u8Digit2 = APARSER_u8AsciiToHex(Copy_u8BufData[(4 * LOC_u8Result) + 11]);
		LOC_u8Digit3 = APARSER_u8AsciiToHex(Copy_u8BufData[(4 * LOC_u8Result) + 12]);
		/*because little Endian*/
		GLB_u16Data[LOC_u8Result] = (LOC_u8Digit2<<12) | (LOC_u8Digit3<<8) | (LOC_u8Digit0<<4) |(LOC_u8Digit1)  ;
	}
	FLASH_vidProgramHalfWord(GLB_u32Address,GLB_u16Data,(LOC_u8CharacterCount / 2));
}
