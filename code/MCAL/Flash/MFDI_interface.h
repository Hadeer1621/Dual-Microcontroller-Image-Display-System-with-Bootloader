/************************************************************/
/*		Author : Hadeer									*/
/*		Version: V01										*/
/*		Date   : 18 June 2023								*/
/* Description       : MFDI_interface.h --> implementations */
/* Module  Features  :                      				*/
/*      01- MFDI_voidEraseSector                 			*/
/*      02- MFDI_voidProgramFlash            				*/
/*      03- MFDI_voidEraseMass      						*/
/************************************************************/

/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/
#ifndef MFDI_INTERFACE_H_
#define MFDI_INTERFACE_H_

/*******************************************************************************************************/
/*                                   Sector numbers for MFDI 					                       */
/*******************************************************************************************************/

typedef enum {
	SECTOR_0=0,
	SECTOR_1,
	SECTOR_2,
	SECTOR_3,
	SECTOR_4,
	SECTOR_5
}Sector_IDS;

/*******************************************************************************************************/
/*                                   		Pins definitions                            			   */
/*******************************************************************************************************/
	/*		SR Register flags			*/
#define BSY		16U	 /* Busy flag */
#define RDERR 	8U   /* Read protection error flag*/
#define PGSERR	7U   /* Programming sequence error flag*/
#define PGPERR  6U   /* Programming parallelism error flag*/
#define PGAERR	5U	 /* Programming alignment error flag*/
#define WRPERR	4U	 /* Write/Program protection error flag*/
#define OPERR	1U	 /* Operation (Erase/Program/Read) error flag*/
#define EOP	    0U   /* End of Operation flag*/

	/*		CR Register pins			*/
#define LOCK	31U /* Lock flag*/
#define ERRIE	25U /* Error interrupt enable*/
#define EOPIE	24U /* End of operation interrupt enable*/
#define STRT	16U /* Start erase operation*/
#define PSIZE0	8U	/* Program size (bit 0)*/
#define PSIZE1	9U  /* Program size (bit 1)*/
#define SNB0	3U  /* Sector number (bit 0)*/
#define SNB1	4U  /* Sector number (bit 1)*/
#define SNB2	5U  /* Sector number (bit 2)*/
#define SNB3	6U  /* Sector number (bit 3)*/
#define MER		2U  /* Mass erase activate*/
#define SER		1U  /* Sector erase activate*/
#define PG		0U  /* Programming activate*/

/*******************************************************************************************************/
/*                                   		Constant Values                            			   	   */
/*******************************************************************************************************/

#define FLASH_ACCESS_KEY1	0x45670123
#define FLASH_ACCESS_KEY2	0xCDEF89AB

#define FLASH_OPTION_KEY1	0x08192A3B
#define FLASH_OPTION_KEY2	0x4C5D6E7F

#define FLASH_CLEAR_SECTOR_BITS	0xFFFFFF87

/*******************************************************************************************************/
/*                                   		Functions Prototypes                            		   */
/*******************************************************************************************************/

void MFDI_voidEraseSector(Sector_IDS Copy_u8SectorNumber );

void MFDI_voidEraseMass(void);

void MFDI_voidProgramFlash(u32 Copy_u32DataAddress,u32 *Copy_u32Data,u32 Copy_u32DataSize);


#endif
