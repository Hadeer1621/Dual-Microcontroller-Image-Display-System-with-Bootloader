/*
 * MRCC_Config.h
 *
 *  Created on: Jun 16, 2023
 *      Author: amira
 */

#ifndef MRCC_CONFIG_H_
#define MRCC_CONFIG_H_


/*
	- CLKSRC option :
			         1) RCC_HSI
			         2) RCC_HSE
			         3) RCC_PLL
*/
       #define RCC_CLOCK_TYPE  RCC_HSI




/*
   - HSE option :
                 1)_HSE_CRYSTAL
                 2)_HSE_RC
*/

       #define HSE_SRC  HSE_CRYSTAL




/*
   - PLL option :
	            1) _HSE_PLL
                2) _HSI_PLL
 */
      #define PLL_SRC   HSE_PLL





#endif /* MRCC_CONFIG_H_ */
