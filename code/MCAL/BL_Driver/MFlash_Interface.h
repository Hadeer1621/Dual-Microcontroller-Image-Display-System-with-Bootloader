/***********************************************************/
/***********  Author       :Hadeer                   ********/
/***********  Version      :V01                     ********/
/***********  Date         :21/5/2020               ********/
/***********  Description  :FLASH_interface file    ********/
/***********************************************************/


/******************************************************/
/*** guard of file will call one time in .c    ********/
/******************************************************/

#ifndef MFDI_INTERFACE_H_
#define MFDI_INTERFACE_H_


/****************************** sector num       ***********************************/
#define sector1      1
#define sector2      2
#define sector3      3
#define sector4      4
#define sector5      5
#define sector6      6
#define sector7      7

/***************************sector addresses **************************************/

#define sector1_add         0x08004000
#define Sector2_add         0x08008000
#define Sector3_add         0x0800C000
#define Sector4_add         0x08010000
#define Sector5_add         0x08020000
#define Sector6_add         0x08040000
#define Sector7_add         0x08060000

/****************************** FLASH prototypes ***********************************/

void FLASH_vidInit(void);

void FLASH_vidUnlock( void );

void FLASH_viduLock( void );

void FLASH_vidWaitFlashIfBusy( void );

void FLASH_vidEraseAppArea(void) ;

void FLASH_vidSectorErase   ( u8 Copy_u8SectorNumber ) ;

void FLASH_vidProgramHalfWord(u32 Copy_u32Address ,u16* Copy_PtrData, u8 Copy_u8DataLength);

#endif /* MFDI_INTERFACE_H_ */
