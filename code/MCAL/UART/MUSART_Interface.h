/*******************************************************************************************************/
/* Author            : Hadeer                                                                          */
/* Version           : V0.0.0                                                                          */
/* Data              :16 July 2022	                                                                    */
/* Description       : MUSART_Interface.c --> implementations                                          */
/* Module  Features  :                                                                                 */
/*      01- MSUART_voidInit                                                                            */
/*      02- MUSART_voidEnable                                                                          */
/*      03- MUSART_voidDisable                                                                         */
/*      04- MSUART_u8SendData                                                                          */
/*      05- MUSART_u8ReadData                                                                          */
/*      06- MUSART_GetHandler                                                                          */
/*******************************************************************************************************/


/*******************************************************************************************************/
/*                                      guard of file will call on time in .c                          */
/*******************************************************************************************************/

#ifndef MUSART_INTERFACE_H
#define MUSART_INTERFACE_H


/************************************************************************************************************* */
/*                                        Essential macros                                                 */
/************************************************************************************************************* */

/*enable & disable */
#define U_ENABLE                  1
#define U_DISABLE                 0

/*barity */
#define U_EVEN_PARITY             0
#define U_ODD_PARITY              0

/*data */
#define U_DATA_8                  0
#define U_DATA_9                  1

/*U_OVER_SAMPLING */
#define U_OVER_SAMPLING_16        0
#define U_OVER_SAMPLING_8         1

#define STOP_1                    1
#define STOP_05                   2
#define STOP_2                    3





/************************************************************************************************************* */
/*                                       UART_BUAD_RATE                                                        */
/************************************************************************************************************* */

#define   B_1200                  0x44505400
#define   B_2400                  0x43d05800
#define   B_9600                  0x00000683
#define   B_19200                 0x42504000
#define   B_38400                 0x41d08000
#define   B_57600                 0x418b0000
#define   B_115200                0x410b0000




/************************************************************************************************************* */
/*                                        Functions prototypes                                                 */
/************************************************************************************************************* */



void MSUART_voidInit(void);

void MUSART_voidEnable(u8 copy_u8Index);

void MUSART_voidDisable(u8 copy_u8Index);

void MUSART_u8SendData(u8 copy_u8Index, u8* copy_u8Data, u8 copy_u8Len);

u8 MUSART_u8ReadData(u8 copy_u8Index);

void MUSART1_voidSendCharSynch( u8 Copy_u8Char ) ;

void MUSART1_voidSendSrtingSynch( u8 *  Copy_u8String ) ;
u8 MUSART1_u8ReceiveCharSync( u8* Copy_u8DataCome ) ;






#endif //MUSART_INTERFACE_H_
