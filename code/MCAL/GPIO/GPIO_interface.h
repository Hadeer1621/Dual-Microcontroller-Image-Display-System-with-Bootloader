/*
***************************************************
*    Author  : hadeer
*    Data    : 18-6-2023
*    Brief   :
*    Version :
*************************************************** 
*/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

			/*Includes*/
/*************************************************/

/*-----------------------------------------------*/

			/*Macros*/
/*************************************************/


/*======== ENUM For PORT ========*/
typedef enum{
	GPIOA_PORT =0 ,
	GPIOB_PORT    ,
	GPIOC_PORT    
}PortName_t;

/*======== ENUM For PIN ========*/
typedef enum{
	PIN_0 =0  ,
	PIN_1     ,
	PIN_2     ,
	PIN_3     ,
	PIN_4     ,
	PIN_5     ,
	PIN_6     ,
	PIN_7     ,
	PIN_8     ,
	PIN_9     ,
	PIN_10    ,
	PIN_11    ,
	PIN_12    ,
	PIN_13    ,
	PIN_14    ,
	PIN_15
}PinNum_t;

/*======== ENUM For MODS ========*/
typedef enum{         
	INPUT=0 ,          /*!< MODE ---> INPUT    (0b00)    */
	OUTPUT  ,          /*!< MODE ---> OUTPUT   (0b01)    */
	ALTF    ,          /*!< MODE ---> ALTF     (0b10)    */
	ANALOG	           /*!< MODE ---> ANALOG   (0b11)    */
}PinMode_t;

/*======== ENUM For VALUE ========*/
typedef enum{
	LOW = 0U,
	HIGH
}PinValue_t;

/*======== ENUM For VALUE ========*/
typedef enum{
	PUSH_PULL = 0U,
	OPEN_DRAIN
}OutPutType_t;

typedef enum{         
	LOW_SPEED=0      ,  /*!< IO works at 2 MHz, please refer to the product datasheet */
	MEDIUM_SPEED     ,  /*!< range 12,5 MHz to 50 MHz, please refer to the product datasheet */
	HIGH_SPEED       ,  /*!< range 25 MHz to 100 MHz, please refer to the product datasheet  */
	VERY_HIGH_SPEED	    /*!< range 50 MHz to 200 MHz, please refer to the product datasheet  */
}OutPutSpeed_t;

typedef enum{
    NORMAL = 0U,  
    PULL_UP,      
    PULL_DOWN     
}PullType_t;


typedef enum{
    ALTFN_0  = 0U,                           
	ALTFN_1      ,                            
	ALTFN_2      ,                            
	ALTFN_3      ,                            
	ALTFN_4      ,                            
	ALTFN_5      ,
    ALTFN_6      ,
    ALTFN_7      ,
    ALTFN_8      ,
    ALTFN_9      ,
    ALTFN_10     ,
    ALTFN_11     ,
    ALTFN_12     ,
    ALTFN_13     ,
    ALTFN_14     ,
    ALTFN_15 
}ALTFN_t;


/*-----------------------------------------------*/

		 /*Global Declaration*/
/*************************************************/

void MGPIO_voidSetPinMode	     (PortName_t copy_ePORT , PinNum_t copy_ePIN , PinMode_t copy_eMode  );
void MGPIO_voidSetPinOutPutType  (PortName_t copy_ePORT , PinNum_t copy_ePIN , OutPutType_t  copy_eOutPutType);
void MGPIO_voidSetPinOutPutSpeed (PortName_t copy_ePORT , PinNum_t copy_ePIN , OutPutSpeed_t  copy_eOutPutSpeed);
void MGPIO_voidSetPullType       (PortName_t copy_ePORT , PinNum_t copy_ePIN , PullType_t  copy_ePullType);
void MGPIO_voidSetPinValue		 (PortName_t copy_ePORT , PinNum_t copy_ePIN , PinValue_t copy_eValue );
void MGPIO_voidSetPinValueDirect (PortName_t copy_ePORT , PinNum_t copy_ePIN , PinValue_t copy_eValue );
void MGPIO_voidTogValue		     (PortName_t copy_ePORT , PinNum_t copy_ePIN );

u8 MGPIO_u8GetPinValue			 (PortName_t copy_ePORT , PinNum_t copy_ePIN  );

void MGPIO_voidLockPin (PortName_t copy_ePORT , PinNum_t copy_ePIN  );
void MGPIO_voidSetPinAltFn (PortName_t copy_ePORT , PinNum_t copy_ePIN , ALTFN_t copy_eALF);
 
void MGPIO_vPortOutputOneByte(PortName_t Copy_ePortName, u8 Copy_u8Data, u8 Copy_u8StartBit);

/*-----------------------------------------------*/

#endif /*GPIO_INTERFACE_H*/
