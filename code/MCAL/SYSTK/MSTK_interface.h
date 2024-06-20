/************************************************************/
/*******************************************************************************************************/
/* Author            : Hadeer                                                                          */
/* Version           : V0.0.0                                                                          */
/* Data              :16 June 2023	                                                                    */
/* Description       : MSTK_program.c --> implementations   */
/* Module  Features  :                      				*/
/*      01- MSTK_voidInit                   				*/
/*      02- MSTK_voidSetBusyWait            				*/
/*      03- MSTK_voidSetIntervalSingle      				*/
/*      04- MSTK_voidSetIntervalPeriodic    				*/
/*      05- MSTK_voidStopInterval           				*/
/*      06- MSTK_u32GetElapsedTime          				*/
/*      07- MSTK_u32GetRemainingTime        				*/
/************************************************************/


/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/
#ifndef MSTK_INTERFACE_H_
#define MSTK_INTERFACE_H_

/*******************************************************************************************************/
/*                                   		Pins definitions                            			   */
/*******************************************************************************************************/

#define ENABLE		0U
#define	TICKINT		1U
#define CLKSOURCE 	2U
#define COUNTFLAG	16U

/*******************************************************************************************************/
/*                                   		Constant Values                            			   	   */
/*******************************************************************************************************/

#define CLEAR_LOAD_VAL	0xFF000000

/*******************************************************************************************************/
/*                                   		Functions Prototypes                            			   */
/*******************************************************************************************************/
void MSTK_voidInit(void);

void MSTK_voidSetBusyWait( u32 Copy_u32Ticks );

void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );

void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );

void MSTK_voidStopInterval(void);

u32  MSTK_u32GetElapsedTime(void);

u32  MSTK_u32GetRemainingTime(void);


#endif
