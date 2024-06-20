/*******************************************************************************************************/
/* Author            : Hadeer                                                                          */
/* Version           : V0.0.0                                                                          */
/*	Date   	   		: 16 June 2023							*/
/*  Description     : MSTK_program.c --> implementations    */
/*  Module Features :                 						*/
/*		1- MSTK_voidInit									*/
/*		2- MSTK_voidSetBusyWait								*/
/*		3- MSTK_voidSetIntervalSingle						*/
/*		4- MSTK_voidSetIntervalPeriodic						*/
/*		5- MSTK_voidStopInterval							*/
/*		6- MSTK_u32GetElapsedTime							*/
/*		7- MSTK_u32GetRemainingTime							*/
/************************************************************/



/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/
#include <BIT_MATH.h>
#include <STD_TYPES.h>

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/
#include "MSTK_interface.h"
#include "MSTK_private.h"
#include "MSTK_config.h"

/* Callback function pointer */
static void (*MSTK_Callback)(void)=0;



/***********************************************************************************************************/
/*                                      01- MSTK_voidInit                                              	   */
/*---------------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Apply Clock choice from configuration, disable interrupt and timer   		   */
/* 2- Function Input       -> Nothing                                         							   */
/* 3- Function Return      -> Nothing                                                                 	   */
/***********************************************************************************************************/
void MSTK_voidInit(void)
{
#if 	MSTK_CLOCK_SOURCE == MSTK_SRC_AHB
	/* Step 1: Apply clock choice */
	SET_BIT(MSTK->CTRL,CLKSOURCE);

	/* Step 2: Disable interrupt and counter */
	CLR_BIT(MSTK->CTRL,ENABLE);
	CLR_BIT(MSTK->CTRL,TICKINT);

#elif	MSTK_CLOCK_SOURCE == MSTK_SRC_AHB_8
	/* Step 1: Apply clock choice */
	CLR_BIT(MSTK->CTRL,CLKSOURCE);

	/* Step 2: Disable interrupt and counter */
	CLR_BIT(MSTK->CTRL,ENABLE);
	CLR_BIT(MSTK->CTRL,TICKINT);

#else
	/* Disable interrupt and counter */
	CLR_BIT(MSTK->CTRL,ENABLE);
	CLR_BIT(MSTK->CTRL,TICKINT);
#endif
}


/***********************************************************************************************************/
/*                                      02- MSTK_voidSetBusyWait                                            	   */
/*---------------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Loads desired number of ticks to LOAD register & start timer	   			   */
/* 2- Function Input       -> Copy_u32Ticks																   */
/* 		-Copy_u32Ticks: Number of desired ticks to wait for before an interrupt occurs  			       */
/* 3- Function Return      -> Nothing                                                                      */
/***********************************************************************************************************/

void MSTK_voidSetBusyWait( u32 Copy_u32Ticks )
{
	/* Step 1: Clear previous values in VAL and LOAD registers */
	MSTK->VAL &= CLEAR_LOAD_VAL;
	MSTK->LOAD &= CLEAR_LOAD_VAL;

	/* Step 2: Load desired number of ticks in LOAD register */
	MSTK->LOAD = Copy_u32Ticks;

	/* Step 3: Enable timer interrupt*/
	SET_BIT(MSTK->CTRL,TICKINT);

	/* Step 4: Start timer */
	SET_BIT(MSTK->CTRL,ENABLE);

	/*Step 5: Wait for flag to be raised */
	while(GET_BIT(MSTK->CTRL,COUNTFLAG)==0);

	/* Step 6: Disable Timer*/
	MSTK_voidStopInterval();
}

/***********************************************************************************************************/
/*                                      03- MSTK_voidSetIntervalSingle                                     */
/*---------------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Loads desired number of ticks to LOAD register & callback ,then start timer  */
/* 2- Function Input       -> Copy_u32Ticks	, Copy_ptr													   */
/* 		-Copy_u32Ticks: Number of desired ticks to wait for before an interrupt occurs  			       */
/*		-Copy_ptr: 		Callback function address														   */
/* 3- Function Return      -> Nothing                                                                      */
/***********************************************************************************************************/
void MSTK_voidSetIntervalSingle( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Step 1: Clear previous values in VAL and LOAD registers */
	MSTK->VAL &= CLEAR_LOAD_VAL;
	MSTK->LOAD &= CLEAR_LOAD_VAL;

	/* Step 2: Load desired number of ticks in LOAD register */
	MSTK->LOAD = Copy_u32Ticks;

	/*Step 3: Set callback */
	MSTK_Callback = Copy_ptr;

	/* Step 4: Enable timer interrupt*/
	SET_BIT(MSTK->CTRL,TICKINT);

	/* Step 5: Start timer */
	SET_BIT(MSTK->CTRL,ENABLE);
}

/***********************************************************************************************************/
/*                                      04- MSTK_voidSetIntervalPeriodic                                     */
/*---------------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Loads desired number of ticks to LOAD register & callback ,then start timer. */
/*								 This process is repeated and Copy_ptr-function is called at each interrupt*/

/* 2- Function Input       -> Copy_u32Ticks	, Copy_ptr													   */
/* 		-Copy_u32Ticks: Number of desired ticks to wait for before an interrupt occurs  			       */
/*		-Copy_ptr: 		Callback function address														   */
/* 3- Function Return      -> Nothing                                                                      */
/***********************************************************************************************************/
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Step 1: Clear previous values in VAL and LOAD registers */
	MSTK->VAL &= CLEAR_LOAD_VAL;
	MSTK->LOAD &= CLEAR_LOAD_VAL;

	/* Step 2: Load desired number of ticks in LOAD register */
	MSTK->LOAD = Copy_u32Ticks;

	/*Step 3: Set callback */
	MSTK_Callback = Copy_ptr;

	/* Step 4: Enable timer interrupt*/
	SET_BIT(MSTK->CTRL,TICKINT);

	/* Step 5: Start timer */
	SET_BIT(MSTK->CTRL,ENABLE);
}

/********************************************************************************************************************/
/*                                      05- MSTK_voidStopInterval                                            	    */
/*------------------------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Disable timer and its interrupt ,then clear values in  VAL and LOAD registers 		*/
/* 2- Function Input       -> Nothing																   				*/
/* 3- Function Return      -> Nothing                                                                      			*/
/********************************************************************************************************************/
void MSTK_voidStopInterval(void)
{
	/*Step 1: Stop Timer */
	CLR_BIT(MSTK->CTRL,ENABLE);

	/*Step 2: Disable timer interrupt */
	CLR_BIT(MSTK->CTRL,TICKINT);

	/*Step 3: Clear VAL and LOAD registers' values */
	MSTK->VAL &= CLEAR_LOAD_VAL;
	MSTK->LOAD &= CLEAR_LOAD_VAL;
}

/***********************************************************************************************************/
/*                                      06- MSTK_u32GetElapsedTime                                         */
/*---------------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Returns the time that passed since timer started 		   	   			   	   */
/* 2- Function Input       -> Nothing                                          	   						   */
/* 3- Function Return      -> No Thing                                                                     */
/***********************************************************************************************************/
u32  MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ValReg , Local_u32ElapsedTime;
	Local_u32ValReg = MSTK->VAL;
	Local_u32ElapsedTime = MSTK->LOAD - Local_u32ValReg;
	return Local_u32ElapsedTime;
}

/***********************************************************************************************************/
/*                                      07- MSTK_u32GetRemainingTime                                         */
/*---------------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Returns the remaining time for an interrupt to occur 		   	   			   */
/* 2- Function Input       -> Nothing                                          	   						   */
/* 3- Function Return      -> No Thing                                                                     */
/***********************************************************************************************************/
u32  MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32ValReg;
	Local_u32ValReg = MSTK->VAL;
	return Local_u32ValReg;
}

/***********************************************************************************************************/
/*                                      00- SysTick_Handler                                            	   */
/*---------------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->  Called by HW when an interrupt is fired and executes the callback function  */
/* 2- Function Input       -> Nothing                                          	   						   */
/* 3- Function Return      -> No Thing                                                                     */
/***********************************************************************************************************/
void SysTick_Handler(void){

	/*Step 1: Execute callback function*/
	MSTK_Callback();

	/*Step 2: Clear interrupt flag by reading it*/
	GET_BIT(MSTK->CTRL,COUNTFLAG);
}

