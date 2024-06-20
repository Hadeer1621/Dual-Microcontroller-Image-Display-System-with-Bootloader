/*============================================================================================
 * 	@ File: SPI_Interface.h
 *  @ Created on: Jun 8, 2023
 *  @ Author: HaDeeR
 *  @ Version : _1_
 *  @ Note :
 *   			01- MSPI1_voidInit
 *      		02- MSPI1_voidSendDataU8
 *      		03- MSPI1_voidSetCallBack
 ==================================================================================================*/
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


#ifndef SPI_SPI_INTERFACE_H_
#define SPI_SPI_INTERFACE_H_
/*================================================================*/
/*==================MACROS================================*/
#define SPI_1_MODEL      1U
#define SPI_2_MODEL      2U
#define SPI_3_MODEL      3U
#define SPI_4_MODEL      4U
/*==================DECLARATIN_FUNCTIONS===============================*/
/* 1- Function to configure the SPI */
	void MSPI_vSPIInit(u8 Copy_u8SPIIndex);

	void MSPI_vSPIEnable(u8 Copy_u8SPIIndex);
	void MSPI_vSPIDisable(u8 Copy_u8SPIIndex);
/* 2- Function To send and recieve data in the same time */
	u16 MSPI_u8SPISendRecive(u16 Copy_u8DataToSend);
/*==========================================================*/
void MSPI1_vSPISetCallBack ( void (*ptr) (void) ) ;
/*==========================================================*/





#endif /* SPI_SPI_INTERFACE_H_ */
