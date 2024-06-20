
/*******************************************************************************************************/
/* Author            : Hadeer                                                                          */
/* Version           : V0.0.0                                                                          */
/* Data              : 30 jul 2022                                                                     */
/* Description       :  * MRCC_Private.h   
/*******************************************************************************************************/
/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/
#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_

#include "STD_TYPES.h"
/*******************************************************************************************************/
/*                                       Register Definitions                                          */
/*-----------------------------------------------------------------------------------------------------*/



/*******************************************************************************************************/
/*                                    Macros Base Address Of RCC Registers                             */
/*******************************************************************************************************/

#define RCC_BASE_ADDRESS 			   0x40023800

/*******************************************************************************************************/
/*                                    Macro Of RCC Security PIN                                        */
/*******************************************************************************************************/
//#define CSSON   PIN19

/*******************************************************************************************************/

/*******************************************************************************************************/
/*                            MRCC registers														   */
/*******************************************************************************************************/
/*MRCC registers*/
typedef struct
{
  volatile u32 CR;            /*   RCC clock control register,                                  Address offset: 0x00 */
  volatile u32 PLLCFGR;       /*   RCC PLL configuration register,                              Address offset: 0x04 */
  volatile u32 CFGR;          /*   RCC clock configuration register,                            Address offset: 0x08 */
  volatile u32 CIR;           /*   RCC clock interrupt register,                                Address offset: 0x0C */
  volatile u32 AHB1RSTR;      /*   RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  volatile u32 AHB2RSTR;      /*   RCC AHB2 peripheral reset register,                          Address offset: 0x14 */

  volatile u32 RESERVED0[2];  /*   Reserved, 0x1C                                                                 */
  volatile u32 APB1RSTR;      /*   RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  volatile u32 APB2RSTR;      /*   RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  volatile u32 RESERVED1[2];  /*   Reserved, 0x28-0x2C                                                               */
  volatile u32 AHB1ENR;       /*   RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  volatile u32 AHB2ENR;       /*   RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  volatile u32 RESERVED2[2];

  volatile u32 APB1ENR;       /*   RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  volatile u32 APB2ENR;       /*   RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  volatile u32 RESERVED4[2];  /*   Reserved, 0x48-0x4C                                                               */
  volatile u32 AHB1LPENR;     /*   RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  volatile u32 AHB2LPENR;     /*   RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  volatile u32 RESERVED5[2];

  volatile u32 APB1LPENR;     /*   RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  volatile u32 APB2LPENR;     /*   RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  volatile u32 RESERVED6[2];  /*   Reserved, 0x68-0x6C                                                               */

  volatile u32 BDCR;          /*   RCC Backup domain control register,                          Address offset: 0x70 */
  volatile u32 CSR;           /*   RCC clock control & status register,                         Address offset: 0x74 */
  volatile u32 RESERVED7[2];  /*   Reserved, 0x78-0x7C                                                               */

  volatile u32 SSCGR;         /*   RCC spread spectrum clock generation register,               Address offset: 0x80 */
  volatile u32 PLLI2SCFGR;    /*   RCC PLLI2S configuration register,                           Address offset: 0x84 */
  volatile u32 RESERVED8;     /*   Reserved, 0x88                                                                    */

  volatile u32 DCKCFGR;       /*   RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
}RCC_t;

/*================================================================
	-)Struct Macros :*  Base_Address RRC
=================================================================*/
#define    RCC     ((volatile RCC_t *) (RCC_BASE_ADDRESS))





#endif /* MRCC_PRAVATE_H_ */


