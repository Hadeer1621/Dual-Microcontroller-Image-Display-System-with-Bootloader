/*
***************************************************
*    Author  : hadeer
*    Data    : 18-6-2023
*    Brief   :
*    Version :
*************************************************** 
*/


 			/*Includes*/
/*************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
/*-----------------------------------------------*/

			/*Macros*/
/*************************************************/

/*-----------------------------------------------*/

		 /*Global Declaration*/
/*************************************************/

/*-----------------------------------------------*/




void MGPIO_voidSetPinMode	(PortName_t copy_ePORT , PinNum_t copy_ePIN , PinMode_t copy_eMode )
{
	if (copy_ePIN <= 15)
	{
	switch(copy_ePORT)
	{
		case GPIOA_PORT :  MGPIOA->MODER |=   ((copy_eMode)<< ( 2U * copy_ePIN ));  break ;
		case GPIOB_PORT :  MGPIOB->MODER |=   ((copy_eMode)<< ( 2U * copy_ePIN ));  break ;
		case GPIOC_PORT :  MGPIOC->MODER |=   ((copy_eMode)<< ( 2U * copy_ePIN ));	break ;
		default:  /*ERROR*/ break ;	
	}
	}
	else
	{
		
		/*Return Error*/
	}
}	


void MGPIO_voidSetPinOutPutType (PortName_t copy_ePORT , PinNum_t copy_ePIN , OutPutType_t  copy_eOutPutType)
{
	if (copy_ePIN <= 15)
	{
		if (copy_eOutPutType==PUSH_PULL)
		{
			switch(copy_ePORT)
			{
			case GPIOA_PORT : CLR_BIT(MGPIOA->OTYPER,copy_ePIN); break;
			case GPIOB_PORT : CLR_BIT(MGPIOB->OTYPER,copy_ePIN); break;
			case GPIOC_PORT : CLR_BIT(MGPIOC->OTYPER,copy_ePIN); break;
			default: /*ERROR*/								    break;
			}
		}
		else if (copy_eOutPutType==OPEN_DRAIN)
		{
			switch(copy_ePORT)
			{
			case GPIOA_PORT : SET_BIT(MGPIOA->OTYPER,copy_ePIN); break;
			case GPIOB_PORT : SET_BIT(MGPIOB->OTYPER,copy_ePIN); break;
			case GPIOC_PORT : SET_BIT(MGPIOC->OTYPER,copy_ePIN); break;
			default: /*ERROR*/								    break;
			}
		}
		else
	    {
		
		/*Return Error*/
	    }
	}
	else
	{
		
		/*Return Error*/
	}
}	



void MGPIO_voidSetPinOutPutSpeed (PortName_t copy_ePORT , PinNum_t copy_ePIN , OutPutSpeed_t  copy_eOutPutSpeed)
{
	
	if (copy_ePIN <= 15)
	{
	switch(copy_ePORT)
	{
		case GPIOA_PORT : MGPIOA->OSPEEDR |=   ((copy_eOutPutSpeed)<< ( 2U * copy_ePIN )); break ;
		case GPIOB_PORT : MGPIOB->OSPEEDR |=   ((copy_eOutPutSpeed)<< ( 2U * copy_ePIN )); break ;
		case GPIOC_PORT : MGPIOC->OSPEEDR |=   ((copy_eOutPutSpeed)<< ( 2U * copy_ePIN )); break ;
		default:  /*ERROR*/ break ;
		
	}
	}
	else
	{
		
		/*Return Error*/
	}
}	




void MGPIO_voidSetPullType (PortName_t copy_ePORT , PinNum_t copy_ePIN , PullType_t  copy_ePullType)
{
	if (copy_ePIN <= 15)
	{
	switch(copy_ePORT)
	{
		case GPIOA_PORT : MGPIOA->PUPDR |=   ((copy_ePullType)<< ( 2U * copy_ePIN )); break ;
		case GPIOB_PORT : MGPIOB->PUPDR |=   ((copy_ePullType)<< ( 2U * copy_ePIN )); break ;
		case GPIOC_PORT : MGPIOC->PUPDR |=   ((copy_ePullType)<< ( 2U * copy_ePIN )); break ;
		default:  /*ERROR*/ break ;
		
	}
	}
	else
	{
		
		/*Return Error*/
	}
}		
	
	

void MGPIO_voidSetPinValue	(PortName_t copy_ePORT , PinNum_t copy_ePIN , PinValue_t copy_eValue )
{
 if (copy_ePIN <= 15)
 {
	if(copy_eValue==HIGH)
	{
		switch(copy_ePORT)
		{
		case GPIOA_PORT :  SET_BIT(MGPIOA->ODR,copy_ePIN); break;
		case GPIOB_PORT :  SET_BIT(MGPIOB->ODR,copy_ePIN); break;
		case GPIOC_PORT :  SET_BIT(MGPIOC->ODR,copy_ePIN); break;
		default : /*ERROR*/ break ;
		}
	}
	else if (copy_eValue==LOW)
	{
		switch(copy_ePORT)
		{
		case GPIOA_PORT :  CLR_BIT(MGPIOA->ODR,copy_ePIN); break;
		case GPIOB_PORT :  CLR_BIT(MGPIOB->ODR,copy_ePIN); break;
		case GPIOC_PORT :  CLR_BIT(MGPIOC->ODR,copy_ePIN); break;
		default : /*ERROR*/ break ;
		}
	}
	else
    {
		
		/*Return Error*/	
    }	
		
} 
 else
 {
		
		/*Return Error*/	
 }	
}

void MGPIO_voidSetPinValueDirect (PortName_t copy_ePORT , PinNum_t copy_ePIN , PinValue_t copy_eValue )
{
	if (copy_ePIN <=15)
	{
		if (copy_eValue == HIGH)
		{
			switch(copy_ePORT)
			{
				case GPIOA_PORT : MGPIOA->BSRR |= ( 1U <<copy_ePIN ); break ;
				case GPIOB_PORT : MGPIOB->BSRR |= ( 1U <<copy_ePIN ); break ;
				case GPIOC_PORT : MGPIOC->BSRR |= ( 1U <<copy_ePIN ); break ;
				default : /*ERROR*/                                   break ;
			}
		}
		else if (copy_eValue == LOW)
		{
			copy_ePIN += 16U;
			switch(copy_ePORT)
			{
				case GPIOA_PORT : MGPIOA->BSRR |= ( 1U <<copy_ePIN ); break ;
				case GPIOB_PORT : MGPIOB->BSRR |= ( 1U <<copy_ePIN ); break ;
				case GPIOC_PORT : MGPIOC->BSRR |= ( 1U <<copy_ePIN ); break ;
				default : /*ERROR*/                                   break ;
			}
			
		}
		else
		{
			/*Return ERROR*/
		}
		
	}
	
	else 
	{
		/*Return ERROR*/
	}

}



void MGPIO_voidTogValue		 (PortName_t copy_ePORT , PinNum_t copy_ePIN)
{
	 if (copy_ePIN <= 15)
 {
		switch(copy_ePORT)
		{
		case GPIOA_PORT :  TOG_BIT(MGPIOA->ODR,copy_ePIN); break;
		case GPIOB_PORT :  TOG_BIT(MGPIOB->ODR,copy_ePIN); break;
		case GPIOC_PORT :  TOG_BIT(MGPIOC->ODR,copy_ePIN); break;
		default : /*ERROR*/ break ;
		}
} 
 else
 {
		
		/*Return Error*/	
 }
	
	
}


u8 MGPIO_u8GetPinValue	(PortName_t copy_ePORT , PinNum_t copy_ePIN  )
{
	u8 Local_u8Result=0;
	if (copy_ePIN <= 15)
 {
	switch(copy_ePORT)
		{
		case GPIOA_PORT : Local_u8Result = GET_BIT(MGPIOA->IDR,copy_ePIN); break;
		case GPIOB_PORT : Local_u8Result = GET_BIT(MGPIOB->IDR,copy_ePIN); break;
		case GPIOC_PORT : Local_u8Result = GET_BIT(MGPIOC->IDR,copy_ePIN); break;
		default : /*ERROR*/ break ;
		}
}
 else
 {
		
		/*Return Error*/	
 }	
 
return Local_u8Result;
}


void MGPIO_voidLockPin (PortName_t copy_ePORT , PinNum_t copy_ePIN  )
{
	
	if (copy_ePIN <=15)
	{
		switch (copy_ePORT)
		{
			case GPIOA_PORT : 
				SET_BIT(MGPIOA->LCKR,copy_ePIN);       /*Select PIN*/
				SET_BIT(MGPIOA->LCKR,16U);             /*Set PIN LCK*/
				while(!(GET_BIT(MGPIOA->LCKR,16U)));   /*wait to lock*/
				break ;
			case GPIOB_PORT : 
				SET_BIT(MGPIOB->LCKR,copy_ePIN);
				SET_BIT(MGPIOB->LCKR,16U);
				while(!(GET_BIT(MGPIOB->LCKR,16U))); 
				break ;
			case GPIOC_PORT : 
				SET_BIT(MGPIOC->LCKR,copy_ePIN); 
				SET_BIT(MGPIOC->LCKR,16U);
				while(!(GET_BIT(MGPIOC->LCKR,16U))); 
				break ;
			default : /*ERROR*/                                break ;
		}
	}
	else
	{
		/*Return ERROR*/
 	}
	
	
}


void MGPIO_voidSetPinAltFn (PortName_t copy_ePORT , PinNum_t copy_ePIN , ALTFN_t copy_eALF)
{
	if(copy_ePIN <=7U)
	{
		switch(copy_ePORT)
		{
			case GPIOA_PORT : MGPIOA->AFRL |=   ((copy_eALF)<< ( 4U * copy_ePIN )); break ;                                                                     
			case GPIOB_PORT : MGPIOB->AFRL |=   ((copy_eALF)<< ( 4U * copy_ePIN )); break ;                                                                     
			case GPIOC_PORT : MGPIOC->AFRL |=   ((copy_eALF)<< ( 4U * copy_ePIN )); break ;                                                                    
			default:  /*ERROR*/ break ;	
		}
		
		
	}
	else if (8U <= copy_ePIN && copy_ePIN <=15U )
	{
		copy_ePIN %=8U;     
		switch(copy_ePORT)
		{
			case GPIOA_PORT : MGPIOA->AFRH |=   ((copy_eALF)<< ( 4U * copy_ePIN )); break ;                                                                     
			case GPIOB_PORT : MGPIOB->AFRH |=   ((copy_eALF)<< ( 4U * copy_ePIN )); break ;                                                                     
			case GPIOC_PORT : MGPIOC->AFRH |=   ((copy_eALF)<< ( 4U * copy_ePIN )); break ;                                                                    
			default:  /*ERROR*/ break ;	
		}
		
		
	}
	else 
	{
		/*Return ERROR*/
	}
	
}

void MGPIO_vPortOutputOneByte(PortName_t Copy_ePortName, u8 Copy_u8Data, u8 Copy_u8StartBit)
{
	switch(Copy_ePortName)
	{
	  case GPIOA_PORT :
	  MGPIOA->ODR = (MGPIOA->ODR & ~(0xff << (Copy_u8StartBit)))| (Copy_u8Data << (Copy_u8StartBit)) ;
	  break;
	  case GPIOB_PORT :
	  MGPIOB->ODR = (MGPIOB->ODR & ~(0xff << (Copy_u8StartBit)))| (Copy_u8Data << (Copy_u8StartBit)) ;
	  break;
	  case GPIOC_PORT :
	  MGPIOC->ODR = (MGPIOC->ODR & ~(0xff << (Copy_u8StartBit)))| (Copy_u8Data << (Copy_u8StartBit)) ;
	  break;
	  default : /*ERROR*/ break ;
    }
}
