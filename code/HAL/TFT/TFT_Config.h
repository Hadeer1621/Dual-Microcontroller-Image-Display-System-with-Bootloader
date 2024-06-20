/*===============================================================================================
 * 	@ File:TFT_Config.h --> Configuration
 *  @ Created on: Jun 18, 2023
 *  @ Author: HaDeeR
 *  @ Version : _1_
 *  @ Note :
 *  ===============================================================================================*/

/*================================================================================================
                       guard of file will call one time in .c
==================================================================================================*/

#ifndef HAL_TFT_TFT_CONFIG_H_
#define HAL_TFT_TFT_CONFIG_H_


#define X_SIZE		 128U
#define Y_SIZE		 160U


/* Write pin port and pin */
#define TFT_A0_PORT			GPIOA_PORT
#define TFT_A0_PIN			PIN_2



#define TFT_RST_PORT		GPIOA_PORT
#define TFT_RST_PIN			PIN_1


#define SCK_PIN       PIN_5
#define MOSI_PIN      PIN_7

#define TFT_PORT 		 GPIOA_PORT

#endif /* HAL_TFT_TFT_CONFIG_H_ */
