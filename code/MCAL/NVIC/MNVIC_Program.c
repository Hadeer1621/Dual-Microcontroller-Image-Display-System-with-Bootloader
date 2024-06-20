/*******************************************************************************************************/
/* Author            : Hadeer                                                                 */
/* Version           : V0.0.0                                                                          */
/* Data              : 30 jul 2022                                                                     */
/* Description       : NVIC_Program.c --> implementations                                              */
/* Module  Features  :                                                                                 */
/*      01- MNVIC_voidEnableInterrupt                                                                  */
/*      02- MNVIC_voidDisableInterrupt                                                                 */
/*      03- MNVIC_voidEnableInterruptPending                                                           */
/*      04- MNVIC_voidDisableInterruptPinding                                                          */
/*      05- MNVIC_u8IsInterruptActive                                                                  */
/*      06- MNVIC_voidInitInterruptGroup                                                               */
/*      07- MNVIC_voidSetInterruptPriority                                                             */
/*      08- MNVIC_voidGenerateSoftwareInterrupt                                                        */
/*******************************************************************************************************/



/*******************************************************************************************************/
/************************************   STD LIB DIRECTIVES  ********************************************/
/*******************************************************************************************************/


#include      "STD_TYPES.h"
#include      "BIT_MATH.h"
#include      "ERROR_STATUS.h"

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

#include "MNVIC_Private.h"
#include "MNVIC_Interface.h"
#include "MNVIC_Config.h"


/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/
/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01- MNVIC_voidEnableInterrupt                                  */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_u8PerNum                                                            */
/*   - Copy_u8PerName :  The Order Of Peripheral On The Selected Register                              */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
/*
* Function: Set The enable for any peripheral
* Range :	copy_u8IntNum -> 84 "Refer to data sheet" */

void MNVIC_voidEnableInterrupt(u8 copy_u8IntNum)
{
	MNVIC_REG->ISER[copy_u8IntNum / 32] = (1U << copy_u8IntNum % 32);

}

/*******************************************************************************************************/
/*                                      02- MNVIC_voidDisableInterrupt                                 */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Disable Peripheral Clock                                                 */
/* 2- Function Input       -> Copy_u8PerNum                                                            */
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

/*
* Function: Set The enable for any prefiral
* Range :	copy_u8IntNum -> 84 "Refer to data sheet" */

void MNVIC_voidDisableInterrupt(u8 copy_u8IntNum)
{
	MNVIC_REG->ICER[copy_u8IntNum / 32] = (1U << copy_u8IntNum % 32);

}


/*******************************************************************************************************/
/*                                      03- MNVIC_voidEnableInterruptPending                           */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->Enable Peripheral Interrupt Pending                                       */
/* 2- Function Input       ->  Copy_u8PerNum                                                           */
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/


void MNVIC_voidEnableInterruptPending(u8 copy_u8PeripheralInterruptNum)
{
	MNVIC_REG->ISPR[copy_u8PeripheralInterruptNum / 32] = (1U << copy_u8PeripheralInterruptNum % 32);

}

/*******************************************************************************************************/
/*                                      04- MNVIC_voidDisableInterruptPending                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> disable Peripheral Interrupt Pending                                     */
/* 2- Function Input       -> Copy_u8PerNum                                                            */
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MNVIC_voidDisableInterruptPending(u8 copy_u8PeripheralInterruptNum)
{
	MNVIC_REG->ICPR[copy_u8PeripheralInterruptNum / 32] = (1U << copy_u8PeripheralInterruptNum % 32);

}

/*******************************************************************************************************/
/*                                      05- MNVIC_u8IsInterruptActive                                  */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       ->   Copy_u8PerNum                                                          */
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

u8 MNVICE_u8IsInterruptActive(u8 copy_u8PeripheralInterruptNum)
{
	return GET_BIT(MNVIC_REG->IABR[copy_u8PeripheralInterruptNum / 32], copy_u8PeripheralInterruptNum);
}

/*******************************************************************************************************/
/*                                      06- MNVIC_voidInitInterruptGroup                               */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Initiate Interrupt Group                                                 */
/* 2- Function Input       ->  copy_GropMode                                                           */
/*   - copy_GropMode :  The group mode  On The Selected Reg                                            */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/


void MNVIC_voidInitInterruptGroup(MNVIC_GroupMode_t copy_GropMode)
{
	MSCB_AIRCR = (MNVIC_VECTKEY << 16);	//reset the regester first
	MSCB_AIRCR = (MNVIC_VECTKEY << 16) | (copy_GropMode << 8);
}

/*******************************************************************************************************/
/*                                      07- MNVIC_voidSetInterruptPriority                             */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Set Interrupt Priority                                                  */
/* 2- Function Input       ->  Copy_u8PerNum                                                           */
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MNVIC_voidSetInterruptPriority(u8 copy_u8PeripheralInterruptNum , MNVIC_GroupMode_t copy_GropMode, u8 copy_u8IntGroup, u8 copy_u8IntSubPriority)
{
	u8 Local_u8PrioValue = 0;

	switch(copy_GropMode)
	{
		case MNVIC_GroupMode_g16s0 : Local_u8PrioValue =  copy_u8IntGroup; break;
		case MNVIC_GroupMode_g8s2  : Local_u8PrioValue = (copy_u8IntGroup << 1) | copy_u8IntSubPriority ; break;
		case MNVIC_GroupMode_g4s4  : Local_u8PrioValue = (copy_u8IntGroup << 2) | copy_u8IntSubPriority ; break;
		case MNVIC_GroupMode_g2s8  : Local_u8PrioValue = (copy_u8IntGroup << 3) | copy_u8IntSubPriority ; break;
		case MNVIC_GroupMode_g0s16 : Local_u8PrioValue =  copy_u8IntSubPriority; break;
	}
  /* */
	MNVIC_REG->IPR[copy_u8PeripheralInterruptNum] = Local_u8PrioValue << 4;
}

/*******************************************************************************************************/
/*                               08- MNVIC_voidGenerateSoftwareInterrupt                               */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Generate Software Interrupt                                              */
/* 2- Function Input       -> Copy_u8PerNum                                                            */
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MNVIC_voidGenerateSoftwareInterrupt(u8 copy_u8PeripheralInterruptNum)
{
	MNVIC_REG->STIR = (copy_u8PeripheralInterruptNum << 4);
}
