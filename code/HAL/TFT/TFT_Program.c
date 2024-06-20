/*==================================================================================================
 * 	@ File: TFT_Program.c
 *  @ Created on: Jun 18, 2023
 *  @ Author: HaDeeR
 *  @ Version : _1_
 ==================================================================================================*/

/*--------------------------------------------------------------------------
 -----------------------------LIB_INCLUDES-----------------------------
---------------------------------------------------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*--------------------------------------------------------------------------
 -----------------------------MCAL_INCLUDES-----------------------------
---------------------------------------------------------------------------*/
#include "SPI_Interface.h"
#include "GPIO_Interface.h"
#include "MSTK_interface.h"
/*--------------------------------------------------------------------------
 -----------------------------MCAL_INCLUDES-----------------------------
---------------------------------------------------------------------------*/
#include "TFT_Private.h"
#include "TFT_Interfcae.h"
#include "TFT_Config.h"
/*--------------------------------------------------------------------------
 --------------------------GLOBAL_DECLARATION----------------------------
---------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
 -----------------------------Functions Implementations-----------
---------------------------------------------------------------------------*/
/*--------------------------------START_FUNCTION---------------------------*/
void HTFT_vTFTInit(void)
{


	    MGPIO_voidSetPinMode(TFT_A0_PORT,TFT_A0_PIN,OUTPUT);//CONT
		MGPIO_voidSetPinOutPutType(TFT_A0_PORT,TFT_A0_PIN,PUSH_PULL);
		MGPIO_voidSetPinOutPutSpeed(TFT_A0_PORT,TFT_A0_PIN,MEDIUM_SPEED);


		MGPIO_voidSetPinMode(TFT_RST_PORT,TFT_RST_PIN,OUTPUT);//RES
		MGPIO_voidSetPinOutPutType(TFT_RST_PORT,TFT_RST_PIN,PUSH_PULL);
		MGPIO_voidSetPinOutPutSpeed(TFT_RST_PORT,TFT_RST_PIN,MEDIUM_SPEED);



		MGPIO_voidSetPinMode(TFT_PORT,SCK_PIN,ALTF);//SCK
		MGPIO_voidSetPinAltFn(TFT_PORT,SCK_PIN,ALTFN_5);
		MGPIO_voidSetPinOutPutType(TFT_PORT,SCK_PIN,PUSH_PULL);
		MGPIO_voidSetPinOutPutSpeed(TFT_PORT,SCK_PIN,VERY_HIGH_SPEED);


		MGPIO_voidSetPinMode(TFT_PORT,MOSI_PIN,ALTF);//MOSI
		MGPIO_voidSetPinAltFn(TFT_PORT,MOSI_PIN,ALTFN_5);
		MGPIO_voidSetPinOutPutType(TFT_PORT,MOSI_PIN,PUSH_PULL);
		MGPIO_voidSetPinOutPutSpeed(TFT_PORT,MOSI_PIN,VERY_HIGH_SPEED);


	/* 1- Reset Pulse*/
	/*MGPIO_voidWriteData(TFT_RST_PORT,TFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(100); 					// busy wait 100 us
	MGPIO_voidWriteData(TFT_RST_PORT,TFT_RST_PIN,LOW);
	MSTK_voidSetBusyWait(1);					// busy wait 1 us
	MGPIO_voidWriteData(TFT_RST_PORT,TFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(100);					// busy wait 100 us
	MGPIO_voidWriteData(TFT_RST_PORT,TFT_RST_PIN,LOW);
	MSTK_voidSetBusyWait(100);					// busy wait 100 us
	MGPIO_voidWriteData(TFT_RST_PORT,TFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(120000);	*/			// busy wait 120 ms

	MGPIO_voidSetPinValue(TFT_PORT,TFT_RST_PIN,LOW);
	MSTK_voidSetBusyWait(10*2000);
	MGPIO_voidSetPinValue(TFT_PORT,TFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(2000*120);

	/* 2- Sleep Out Mode */
	HTFT_vTFTWriteCommand(SLEEP_OUT_COMMAND);
	/* 3- Waiting 150 mili sec */
	MSTK_voidSetBusyWait(150000);
	/* 4- Color Mode */
	HTFT_vTFTWriteCommand(COLOR_MODE_COMMAND);
	HTFT_vTFTWriteCommand(RGB565_DATA); // To Select the standard color
	/* 5- Display On */
	HTFT_vTFTWriteCommand(DISPLAY_ON_COMMAND);
}


void HTFT_vTFTSetCursorPosition(u16 X_Start, u16 X_End ,u16 Y_Start,u16 Y_End)
{
	/* Set the X "ROW" Address*/
	HTFT_vTFTWriteCommand(ROW_ADDRESS_X_COMMAND);
	/* Set the start position */
	HTFT_vTFTWriteData(0);			  /*send higher byte*/
	HTFT_vTFTWriteData(X_Start); //0  /*send lower Byte */
	/* Set the End position   */
	HTFT_vTFTWriteData(0);
	HTFT_vTFTWriteData(X_End); //127


	/* Set the Y "COLUMN" Address*/
	HTFT_vTFTWriteCommand(COLUMN_ADDRESS_Y_COMMAND);
	/* Set the start position */
	HTFT_vTFTWriteData(0);
	HTFT_vTFTWriteData(Y_Start); //0
	/* Set the End position   */
	HTFT_vTFTWriteData(0);
	HTFT_vTFTWriteData(Y_End); //159
}

void HTFT_vTFTDisplayImage(const u16* Copy_Image)
{
	u32 Local_u32Counter = 0;
	u32 Local_u32Size = (X_SIZE) * (Y_SIZE); 	/*calculate image element numbers*/
	HTFT_vTFTSetCursorPosition(0,127,0,159);    /*set addresses of x and y */
	/* RAM Write Command Every thing is coming After This Command Display on TFT*/
	HTFT_vTFTWriteCommand(RAM_WRITE_COMMAND);
	for(Local_u32Counter = 0 ; Local_u32Counter < Local_u32Size; Local_u32Counter ++)
	{
		HTFT_vTFTWriteData(Copy_Image[Local_u32Counter] >> 8);		/* Write The High Byte */
		HTFT_vTFTWriteData(Copy_Image[Local_u32Counter] & 0x00ff);	/* Write The LOW  Byte */
	}

}



static void HTFT_vTFTWriteCommand(u16 Copy_u8Command)
{
	/* Set Data Pin To LOW A0 */
	MGPIO_voidSetPinValue(TFT_A0_PORT,TFT_A0_PIN,LOW);
	/*Send Command Over SPI*/
	MSPI_u8SPISendRecive(Copy_u8Command);
}

static void HTFT_vTFTWriteData(u16 Copy_u8Data)
{
	/* Set Data Pin To LOW A0 */
	MGPIO_voidSetPinValue(TFT_A0_PORT,TFT_A0_PIN,HIGH);
	/*Send Command Over SPI*/
	MSPI_u8SPISendRecive(Copy_u8Data);
}


void HTFT_voidDisplayImage(const u16* Copy_ptrImage)
{
	u16 counter ;
		u8 Data ;
		/*Set X Address*/
		HTFT_vTFTWriteCommand(0x2A) ;
		/*start*/
		HTFT_vTFTWriteData(0) ;
		HTFT_vTFTWriteData(0) ;
		/*stop*/
		HTFT_vTFTWriteData(0) ;
		HTFT_vTFTWriteData(127) ;
		/*Set y Address*/
		HTFT_vTFTWriteCommand(0x2B) ;
		/*start*/
		HTFT_vTFTWriteData(0) ;
		HTFT_vTFTWriteData(0) ;
		/*stop*/
		HTFT_vTFTWriteData(0) ;
		HTFT_vTFTWriteData(159) ;
		/*RAM Write Command*/
		HTFT_vTFTWriteCommand(0x2C) ;
		/*Display Image*/
		for(counter = 0 ; counter < 20480 ; counter++)
		{
			Data  = Copy_ptrImage[counter] >> 8 ;
			/*write for high byte -->MSB*/
			HTFT_vTFTWriteData(Data) ;
			Data  = Copy_ptrImage[counter] & 0x00FF ;
			/*write for high Low*/
			HTFT_vTFTWriteData(Data) ;
		}
}
