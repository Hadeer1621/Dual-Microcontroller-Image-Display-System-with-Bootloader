/*==================================================================================================
 * 	@ File: TFT_Private.h
 *  @ Created on: Jun 18, 2023
 *  @ Author: HaDeeR
 *  @ Version : _1_
 ==================================================================================================*/


/*=====================================================================================
 * ===================    guard of file will call on time in .c	    ===================
 * =======================================================================================*/
#ifndef HAL_TFT_TFT_PRIVATE_H_
#define HAL_TFT_TFT_PRIVATE_H_
#include "STD_TYPES.h"

static void HTFT_vTFTWriteCommand(u16 Copy_u8Command);
static void HTFT_vTFTWriteData(u16 Copy_u8Data);


#endif /* HAL_TFT_TFT_PRIVATE_H_ */
