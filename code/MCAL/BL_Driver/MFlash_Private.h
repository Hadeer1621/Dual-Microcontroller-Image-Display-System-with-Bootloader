/**********************************************************/
/***********  Author       :Hadeer	               ********/
/***********  Version      :V01                    ********/
/***********  Date         :21/5/2020              ********/
/***********  Description  :FLASH registers file   ********/
/**********************************************************/


/******************************************************/
/*** guard of file will call one time in .c    ********/
/******************************************************/

#ifndef MFDI_PRIVATE_H_
#define MFDI_PRIVATE_H_


           /* STRUCT HOLD ALL FLASH REGISTERS */
typedef struct
{
	 volatile u32 ACR ;
	 volatile u32 KEYR ;
	 volatile u32 OPTKEYR ;
	 volatile u32 SR ;
	 volatile u32 CR ;
	 volatile u32 OPTCR ;

}FLASH_T;

/* POINTER TO STRUCT FLASHregisters_T*/

#define    MFLASH_BASE_ADDRESS      0x40023C00
#define    FLASH      ( ( volatile FLASH_T* )  MFLASH_BASE_ADDRESS )


/******************  Bit definition for FLASH_KEYR register  ******************/

#define  FLASH_KEY1_FKEYR                    ((u32)0x45670123)        /*!< FPEC Key1 */
#define  FLASH_KEY2_FKEYR                    ((u32)0xCDEF89AB)        /*!< FPEC Key2 */

#define  LOCK           31
#define  BSY            16
#define  EOP            0
#define  SER            1
#define  STRT           16
#define  PG             0



#define WRITE_HALF_WORD   0b01


#endif /* MFDI_PRIVATE_H_ */
