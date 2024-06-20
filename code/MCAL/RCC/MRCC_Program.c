/*
 * 
/*******************************************************************************************************/
/* Author            : Hadeer                                                                          */
/* Version           : V0.0.0                                                                          */
/* Data              : 30 jul 2022                                                                     */
/* Description       :  MRCC_Program.c 
/*******************************************************************************************************/
/*      Module  Features  :                                                                     */
/*      01- MRCC_voidEnablePeripheralClock                                                             */
/*      02- MRCC_voidDisablePeripheralClock                                                            */
/*      03- MRCC_voidEnableSecuritySystem                                                              */
/*      04- MRCC_voidDisableSecuritySystem                                                             */
/*      05- MRCC_voidInitSystemClk                                                                     */
/*      06- MRCC_voidInitClock
 *
 *
 */


/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/
#include "MRCC_Private.h"
#include "MRCC_Interface.h"
#include "MRCC_Config.h"


/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/


/*******************************************************************************************************/
/*                                      05- MRCC_voidInitSystemClk                                     */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Initialize system clock                                                   */
/*    - CLK		: HSE | HSI |PLL	                                                                   */
/*    - PLLSrc	:PLL_HSE | PLL_HSI                                                                     */
/*    - HSESrc  :HSE_Crystal ,HSE_RC                                                                   */
/* 2- Function Input       -> No Thing                                                                 */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MRCC_voidInitSysclock(void)
{
	/********** HSI **********/
#if RCC_CLOCK_TYPE == RCC_HSI
	/* 1- EN HSI */
	SET_BIT(RCC->CR , HSION);
	/* 2- CLK SYS --> HSI */
	CLR_BIT(RCC->CFGR, SW0);
	CLR_BIT(RCC->CFGR, SW1);
	/********** HSE **********/
#elif RCC_CLOCK_TYPE == RCC_HSE

	#if HSE_SRC == HSE_CRYSTAL
	/* 1- EN HSE */
		SET_BIT(RCC->CR , HSEON);
		/* 2- Disable BYP */
		CLR_BIT(RCC->CR,HSEBYP);
		/* 3- CLK SYS --> HSE */
		SET_BIT(RCC->CFGR, SW0);
		CLR_BIT(RCC->CFGR, SW1);

	#elif HSE_SRC == HSE_RC
		/* 1- EN HSE */
		SET_BIT(RCC->CR , HSEON);
		/* 2- Enable BYP */
		SET_BIT(RCC->CR,HSEBYP);
		/* 3- CLK SYS --> HSE */
		SET_BIT(RCC->CFGR, SW0);
		CLR_BIT(RCC->CFGR, SW1);
	#else
    /* Error*/
	#endif

	/********** PLL **********/
#elif RCC_CLOCK_TYPE == RCC_PLL

    #if PLL_SRC == HSE_PLL
     /*1-Enable HSE */
			SET_BIT(RCC->CR,HSEON);

			/*2- EN PLL*/
			SET_BIT(RCC->CR,PLLON);

			/* 3- PLL From HSE */
			SET_BIT(RCC->PLLCFGR, PLLSRC);
			/* 4- System Clk  PLL */
			CLR_BIT(RCC->CFGR,SW0);
			SET_BIT(RCC->CFGR,SW1);

    #elif PLL_SRC == HSI_PLL
            /*Enable HSI */
		     SET_BIT(RCC->CR,HSION);
			/*2- EN PLL*/
			SET_BIT(RCC->CR,PLLON);
			/* 3- PLL From HSI */
			CLR_BIT(RCC->PLLCFGR, PLLSRC);
			/* 4- System Clk  PLL */
			CLR_BIT(RCC->CFGR,SW0);
			SET_BIT(RCC->CFGR,SW1);
    #else
            /* Error*/
	#endif
/****************************************************/

#else
/* Error*/
#endif // The End Of Big IF
}


/*******************************************************************************************************/
/*                                      01- MRCC_voidEnableClock                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Peripheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Peripheral From It                                   */
/*   - Copy_u8PerName :  The Order Of Peripheral On The Selected Register                                    */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MRCC_voidEnablePeripheralClock(u8 Copy_u8BusName , u8 Copy_u8PerNum )
{

	switch(Copy_u8BusName)
	{
		case RCC_AHB1_BUS:  SET_BIT(RCC->AHB1ENR,Copy_u8PerNum );         break ;
		case RCC_AHB2_BUS:  SET_BIT(RCC->AHB2ENR,Copy_u8PerNum );         break ;
		case RCC_APB1_BUS:  SET_BIT(RCC->APB1ENR,Copy_u8PerNum );         break ;
		case RCC_APB2_BUS:  SET_BIT(RCC->APB2ENR,Copy_u8PerNum );         break ;
		default :     /*   ERROR   */          break ;

	}
}
/*******************************************************************************************************/
/*                                      02- MRCC_voidDisableClock                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Disable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Peripheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Peripheral From It                                   */
/*   - Copy_u8PerName :  The Order Of Peripheral On The Selected Register                                    */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MRCC_voidDisablePeripheralClock(u8 Copy_u8BusName , u8 Copy_u8PerNum )
{
	switch(Copy_u8BusName)
	{
		case RCC_AHB1_BUS:  CLR_BIT(RCC->AHB1ENR,Copy_u8PerNum );         break ;
		case RCC_AHB2_BUS:  CLR_BIT(RCC->AHB2ENR,Copy_u8PerNum );         break ;
		case RCC_APB1_BUS:  CLR_BIT(RCC->APB1ENR,Copy_u8PerNum );         break ;
		case RCC_APB2_BUS:  CLR_BIT(RCC->APB2ENR,Copy_u8PerNum );         break ;
		default :     /* ERROR */          break ;

	}
}




/*******************************************************************************************************/
/*                                      03- MRCC_voidEnableSecuritySystem                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Security System                                                   */
/* 2- Function Input       -> No Thing                                                                 */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MRCC_voidEnableSecuritySystem(void)
{
	SET_BIT( RCC->CR  , CSSON);

}
/*******************************************************************************************************/
/*                                      04- MRCC_voidDisableSecuritySystem                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Disable Security System                                                   */
/* 2- Function Input       -> No Thing                                                                 */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/


void MRCC_voidDisableSecuritySystem(void)
{
	CLR_BIT( RCC->CR  , CSSON);

}
/*******************************************************************************************************/











