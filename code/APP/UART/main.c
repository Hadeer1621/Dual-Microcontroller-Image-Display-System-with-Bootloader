/*==================================================================================================
 * 	@ File: Main.c
 *  @ Created on: Jun 18, 2023
 *  @ Author: HaDeeR
 *  @ Version : _1_
 ==================================================================================================*/

/**===========================INCLUDES===================================== */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_Interface.h"
#include "GPIO_interface.h"
#include "MNVIC_Interface.h"
#include "MUSART_Interface.h"
#include "OutputArray.h"

void App_voidTest(void);

void main(void)
{
	/*Step 1 : System Clock is 16 MHz From HSI*/
	MRCC_voidInitSysclock();

	/*Step 2 : Enable GPIO Peripherial Clock For Port A*/
	MRCC_voidEnableclock(RCC_AHB1,0);

	/*Step 3 : Enable USART1 Peripherial Clock */
	MRCC_voidEnableclock(RCC_APB2,4);

	/*Step 4 : Set Pin Direction ->> Output*/
	MGPIO_voidSetPinDirection(MGPIOA_PORT,MGPIO_PIN0,MGPIO_MODE_OUTPUT) ;
	/*Set Pin Speed*/
	MGPIO_voidSetOutputSpeed(MGPIOA_PORT,MGPIO_PIN0,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	/*Pull Output Type*/
	MGPIO_voidSetOutputType(MGPIOA_PORT,MGPIO_PIN0,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;


	/*Step 5 : Set Pin Mode For Pins 9 , 10 -> Alternative Function */
	MGPIO_voidSetPinDirection(MGPIOA_PORT,MGPIO_PIN9,MGPIO_MODE_ALTF) ;    //TX-> USART1
	MGPIO_voidSetPinDirection(MGPIOA_PORT,MGPIO_PIN10,MGPIO_MODE_ALTF) ;   //RX-> USART1


	/*Step 6 : Set Pin Alternative function For Pins 9 , 10  */
	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN9,7) ;    //TX-> USART1
	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN10,7) ;   //RX-> USART1


	/*Step 7 : Enable USART From MNVIC*/
	MNVIC_voidEnableInterrupt(37) ;

	/*Step 8 : MUSART Initialization*/
	MUSART_voidInit() ; /*9600bps , 1 stop bits  , no parity , 8  bit data*/

	/*Step 8 : Set Call Back Function*/
	MUSART_voidCallBack(App_voidTest) ;

	/*Step 9 : Enable MUSART */
	MUSART_voidEnable() ;

	/*Step 10: Send Data*/
	MUSART_voidSendData(Global_u8ArrOfHex , 47360) ;



	/* Loop forever */
	while(1)
	{
	}

}

void App_voidTest(void)
{
  static u8 LOCAL_u8Bit = 0 ;
  TOG_BIT(LOCAL_u8Bit,0) ;
  MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN0,LOCAL_u8Bit);
  u8 LOC_u8Msg = MUSART_u8ReadData() ;
  Local_u8MSG++;
  MUSART_voidSendData(&Local_u8MSG,1);

}