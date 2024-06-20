/*******************************************************************************************************/
/* Author            : Hadeer                                                                 */
/* Version           : V0.0.0                                                                          */
/* Data              : 30 jul 2022                                                                     */
/* Description       : MRCC_Interface.h                                                                  */
/*******************************************************************************************************/
#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_


/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"



/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

#include "MRCC_Private.h"
#include "MRCC_Config.h"



/************************************************************************************************************* */
/* PINS macros */
/************************************************************************************************************* */


/************************************************************************************************************* */
/* RCC_RC PINS macros */
/************************************************************************************************************* */
#define			 HSION						0U
#define 		 HSIRDY						1U
#define 		 HSITRIM0					3U
#define 		 HSITRIM1					4U
#define 		 HSITRIM2					5U
#define 		 HSITRIM3					6U
#define 		 HSITRIM4					7U
#define 		 HSICAL0					8U
#define 		 HSICAL1					9U
#define 		 HSICAL2					10U
#define 		 HSICAL3					11U
#define 		 HSICAL4					12U
#define 		 HSICAL5					13U
#define 		 HSICAL6					14U
#define 		 HSICAL7					15U
#define 		 HSEON					    16U
#define 		 HSERDY					    17U
#define 		 HSEBYP					    18U
#define 		 CSSON					    19U
#define 		 PLLON					    24U
#define 		 PLLRDY					    25U
#define 		 PLLI2SON					26U
#define 		 PLLI2SRDY				    27U


/************************************************************************************************************* */
/* RCC_CFGR PINS macros */
/************************************************************************************************************* */
#define          SW0					    0U
#define 		 SW1						1U

/************************************************************************************************************* */
/*RCC_PLLCFGR PINS macros */
/************************************************************************************************************* */
#define         PLLSRC						22U


/************************************************************************************************************* */
/* Essential RCC macros */
/************************************************************************************************************* */

/* System CLOCK source */
#define	RCC_HSI								0U
#define	RCC_HSE								1U
#define	RCC_PLL								2U


/*PLL configuration structure*/
#define HSE_PLL      					    0U
#define HSI_PLL       					    1U

/*RCC Clock state*/
#define	RCC_DISABLE_PERIPHERAL				0U
#define	RCC_ENABLE_PERIPHERAL				1U

/* RCC Buses*/
#define  RCC_AHB1_BUS     					0U
#define  RCC_AHB2_BUS     					1U
#define  RCC_APB1_BUS     					2U
#define  RCC_APB2_BUS     					3U


/* RCC_HSE Types*/
#define HSE_CRYSTAL  						0U
#define HSE_RC       						1U


/************************************************************************************************************* */
/*PLL MUL factor macros*/
/************************************************************************************************************* */

#define PLL_INPUT_CLOCK_x_2            					                   (0x0)
#define PLL_INPUT_CLOCK_x_3            					                   (0x1)
#define PLL_INPUT_CLOCK_x_4            					                   (0x2)
#define PLL_INPUT_CLOCK_x_5            					                   (0x3)
#define PLL_INPUT_CLOCK_x_6            					                   (0x4)
#define PLL_INPUT_CLOCK_x_7            					                   (0x5)
#define PLL_INPUT_CLOCK_x_8            					                   (0x6)
#define PLL_INPUT_CLOCK_x_9            					                   (0x7)
#define PLL_INPUT_CLOCK_x_10            						           (0x8)
#define PLL_INPUT_CLOCK_x_11            						           (0x9)
#define PLL_INPUT_CLOCK_x_12            						           (0xA)
#define PLL_INPUT_CLOCK_x_13            						           (0xB)
#define PLL_INPUT_CLOCK_x_14            						           (0xC)
#define PLL_INPUT_CLOCK_x_15            						           (0xD)
#define PLL_INPUT_CLOCK_x_16            						           (0xE)




/************************************************************************************************************* */
/*											Prescalers macros												   */
/************************************************************************************************************* */
/* AHB Prescaler */
#define AHB_NOT_DEVIDED                                                    (0x0)
#define AHB_DIVIDED_BY_2                                                   (0x8)
#define AHB_DIVIDED_BY_4                                                   (0x9)
#define AHB_DIVIDED_BY_8                                                   (0xA)
#define AHB_DIVIDED_BY_16                                                  (0xB)
#define AHB_DIVIDED_BY_64                                                  (0xC)
#define AHB_DIVIDED_BY_128                                                 (0xD)
#define AHB_DIVIDED_BY_256                                                 (0xE)
#define AHB_DIVIDED_BY_512                                                 (0xF)
/* APB1 Prescaler */
#define APB1_NOT_DEVIDED                                                   (0x0)
#define APB1_DIVIDED_BY_2                                                  (0x4)
#define APB1_DIVIDED_BY_4                                                  (0x5)
#define APB1_DIVIDED_BY_8                                                  (0x6)
#define APB1_DIVIDED_BY_16                                                 (0x7)
/* APB2 Prescaler */
#define APB2_NOT_DEVIDED                                                   (0x0)
#define APB2_DIVIDED_BY_2                                                  (0x4)
#define APB2_DIVIDED_BY_4                                                  (0x5)
#define APB2_DIVIDED_BY_8                                                  (0x6)
#define APB2_DIVIDED_BY_16                                                 (0x7)



/*  Macros of RCC AHB1 CLK Enable  */

#define GPIOA_EN_RCC 	 0U
#define GPIOB_EN_RCC 	 1U
#define GPIOC_EN_RCC 	 2U
#define GPIOD_EN_RCC 	 3U
#define GPIOE_EN_RCC 	 4U
#define GPIOH_EN_RCC 	 7U
#define CRC_EN_RCC 		12U
#define DMA1_EN_RCC     21U
#define DMA2_EN_RCC     22U


/*  Macros of RCC APB1 CLK Enable  */

#define TIM2_EN_RCC 	 0U
#define TIM3_EN_RCC 	 1U
#define TIM4_EN_RCC 	 2U
#define TIM5_EN_RCC 	 3U
#define WWDG_EN_RCC 	11U
#define SPI2_EN_RCC 	14U
#define SPI3_EN_RCC 	15U
#define USART2_EN_RCC   17U
#define I2C1_EN_RCC     21U
#define I2C2_EN_RCC     22U
#define I2C3_EN_RCC     23U
#define PWR_EN_RCC      28U

/*  Macros of RCC APB2 CLK Enable  */

#define TIM0_EN_RCC 	 0U
#define USART1_EN_RCC 	 4U
#define USART6_EN_RCC 	 5U
#define ADC1_EN_RCC 	 8U
#define SDIO_EN_RCC 	11U
#define SPI1_EN_RCC 	12U
#define SPI4_EN_RCC 	13U
#define SYSCF_EN_RCC    14U
#define TIM9_EN_RCC     16U
#define TIM10_EN_RCC    17U
#define TIM11_EN_RCC    18U

/*-----------------------------------------------*/

/************************************************************************************************************* */
/*Functions prototypes*/
/************************************************************************************************************* */


/*******************************************************************************************************/
/*                                      05- MRCC_voidInitSystemClk                                     */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Initialize system clock                                                  */
/*    - CLK		: HSE | HSI |PLL	                                                                   */
/*    - PLLSrc	:PLL_HSE | PLL_HSI                                                                     */
/*    - HSESrc  :HSE_Crystal ,HSE_RC                                                                   */
/* 2- Function Input       -> No Thing                                                                 */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MRCC_voidInitSysclock(void);

/*******************************************************************************************************/
/*                                      01- MRCC_voidEnableClock                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Peripheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One              */
/*                      Detect Which REG To Choice Peripheral From It                                  */
/*   - Copy_u8PerName :  The Order Of Peripheral On The Selected Register                              */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
void MRCC_voidEnablePeripheralClock(u8 Copy_u8BusName , u8 Copy_u8PerNum );

/*******************************************************************************************************/
/*                                      02- MRCC_voidDisableClock                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Disable Peripheral Clock                                                 */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Peripheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One              */
/*                      Detect Which REG To Choice Peripheral From It                                  */
/*   - Copy_u8PerName :  The Order Of Peripheral On The Selected Register                              */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
void MRCC_voidDisablePeripheralClock(u8 Copy_u8BusName , u8 Copy_u8PerNum );

/*******************************************************************************************************/
/*                                      03- MRCC_voidEnableSecuritySystem                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Security System                                                   */
/* 2- Function Input       -> No Thing                                                                 */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
void MRCC_voidEnableSecuritySystem(void);

/*******************************************************************************************************/
/*                                      04- MRCC_voidDisableSecuritySystem                             */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Disable Security System                                                  */
/* 2- Function Input       -> No Thing                                                                 */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
void MRCC_voidDisableSecuritySystem(void);



#endif /* MRCC_INTERFACE_H_ */
