/*============================================================================================
 * 	@ File: TFT_Interface.h
 *  @ Created on: Jun 8, 2023
 *  @ Author: HaDeeR
 *  @ Version : _1_
 *  @ Note :
 *  ==================================================================================================*/
/*------------------------------------------------------------------------
 *	What i sell To Customer
 *		  The Archictect Give The API
 *						- The Name Of Function
 *						- What is The Input
 *						- What Is The Output
 *						- Macro
 *-------------------------------------------------------------------------------*/

/*================================================================================================
                       guard of file will call one time in .c
==================================================================================================*/

#ifndef HAL_TFT_TFT_INTERFCAE_H_
#define HAL_TFT_TFT_INTERFCAE_H_
/*======================MACROS============================================*/

#include "STD_TYPES.h"

#define SOFTWARE_RESET_COMMAND			 0X01  // software reset
#define SLEEP_OUT_COMMAND		 		 0X11  // sleep out
#define DISPLAY_OFF_COMMAND				 0X28  // display off
#define DISPLAY_ON_COMMAND			 	 0X29  // display on
#define ROW_ADDRESS_X_COMMAND	 	 	 0X2A  // row address set
#define COLUMN_ADDRESS_Y_COMMAND		 0X2B  // column address set
#define RAM_WRITE_COMMAND 				 0X2C  // RAM write
#define MADCTL_COMMAND 					 0X36  // axis control
#define COLOR_MODE_COMMAND				 0X3A  // color mode
//----------STANDARD_COLORS-----------------------
#define RGB444_DATA 		 0x03
#define RGB565_DATA 		 0x05
#define RGB666_DATA 		 0x06
/*-------1.8" TFT display constants------------------------*/
#define X_SIZE		 128U
#define Y_SIZE		 160U
/*-----Color constants---------------*/
#define BLACK			 	0x0000
#define BLUE 				0x001F
#define RED				 	0xF800
#define GREEN 				0x0400
#define LIME 				0x07E0
#define CYAN			    0x07FF
#define MAGENTA 			0xF81F
#define YELLOW 				0xFFE0
#define WHITE 				0xFFFF

/*==========================================================================*/
/*=============================DECLARATION_FUNCTION=========================*/
void HTFT_vTFTInit(void);
void HTFT_vTFTSetCursorPosition(u16 X_Start, u16 X_End ,u16 Y_Start,u16 Y_End);
void HTFT_vTFTDisplayImage(const u16* Copy_Image);
void HTFT_voidDisplayImage(const u16* Copy_ptrImage);

#endif /* HAL_TFT_TFT_INTERFCAE_H_ */
