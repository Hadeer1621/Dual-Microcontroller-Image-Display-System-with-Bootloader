
/*******************************************************************************************************/
/* Author            : Hadeer                                                                 */
/* Version           : V0.0.0                                                                          */
/* Data              : 30 jul 2022                                                                     */
/***********  Description  :MNVIC_interface file    ********/
/***********************************************************/

/*******************************************************************************************************/	
/*	* What i sell To Customer                                                                          */
/*		*  The Archictect Give The API	                                                               */
/*						- The Name Of Function                                                         */
/*						- What is The Input                                                            */
/*						- What Is The Output                                                           */
/*						- Macro                                                                        */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/


#ifndef _MNVIC_INTERFACE_H_
#define _MNVIC_INTERFACE_H_


/*******************************************   Peripherals ID   ****************************************/

#define        WWDG                  0          //Window Watchdog interrupt
#define        EXTI16                1          //EXTI Line 16 interrupt
#define        TAMP_STAMP            2
#define        RTC_WKUP              3
#define        FLASH                 4          //Flash global interrupt
#define        RCC                   5          // RCC global interrupt
#define        EXTI0                 6          //EXTI Line0 interrupt
#define        EXTI1                 7          // EXTI Line1 interrupt
#define        EXTI2                 8          // EXTI Line2 interrupt
#define        EXTI3                 9          // EXTI Line3 interrupt
#define        EXTI4                10          // EXTI Line4 interrupt
#define        DMA1_Stream0         11          // DMA1 Stream0 global interrupt
#define        DMA1_Stream1         12          // DMA1 Stream1 global interrupt
#define        DMA1_Stream2         13          // DMA1 Stream2 global interrupt
#define        DMA1_Stream3         14          // DMA1 Stream3 global interrupt
#define        DMA1_Stream4         15          // DMA1 Stream4 global interrupt
#define        DMA1_Stream5         16          // DMA1 Stream5 global interrupt
#define        DMA1_Stream6         17          // DMA1 Stream6 global interrupt
#define        ADC                  18          //ADC1 global interrupts
#define        EXTI9_5              23          //EXTI Line[9:5] interrupts
#define        TIM1_BRK_TIM9        24          //TIM1 Break interrupt and TIM9 global
#define        TIM1_UP_TIM10        25          //TIM1 Update interrupt and TIM10 global
#define        TIM1_TRG_COM_TIM11   26          //TIM1 Trigger and Commutation interrupts
#define        TIM1_CC              27          //TIM1 Capture Compare interrupt 0x0000 00AC
#define        TIM2                 28          //TIM2 global interrupt
#define        TIM3                 29          //TIM3 global interrupt
#define        TIM4                 30          //TIM4 global interrupt
#define        I2C1_EV              31          //I2C1 event interrupt
#define        I2C1_ER              32          //I2C1 error interrupt
#define        I2C2_EV              33          //I2C2 event interrupt
#define        I2C2_ER              34          //I2C2 error interrupt
#define        SPI1                 35          //SPI1 global interrupt
#define        SPI2                 36          //SPI2 global interrupt
#define        USART1               37          //USART1 global interrupt
#define        USART2               38          //USART2 global interrupt
#define        EXTI15_10            40          //EXTI Line[15:10] interrupts
#define        RTC_Alarm            41
#define        OTG_FS_WKUP          42
#define        DMA1_Stream7         47         //DMA1 Stream7 global interrupt
#define        SDIO                 49         //SDIO global interrupt
#define        TIM5                 50         //TIM5 global interrupt
#define        SPI3                 51         //SPI3 global interrupt
#define        DMA2_Stream0         56         // DMA2 Stream0 global interrupt
#define        DMA2_Stream1         57         // DMA2 Stream1 global interrupt
#define        DMA2_Stream2         58         // DMA2 Stream2 global interrupt
#define        DMA2_Stream3         59         // DMA2 Stream3 global interrupt
#define        DMA2_Stream4         60         // DMA2 Stream4 global interrupt
#define        OTG_FS               67         //USB On The Go FS global interrupt
#define        DMA2_Stream5         68         //DMA2 Stream5 global interrupt
#define        DMA2_Stream6         69         //DMA2 Stream6 global interrupt
#define        DMA2_Stream7         70         //DMA2 Stream7 global interrupt
#define        USART6               71         //USART6 global interrupt
#define        I2C3_EV              72         //I2C3 event interrupt
#define        I2C3_ER              73         //I2C3 error interrupt
#define        FPU                  81         //FPU global interrupt
#define        SPI4                 84         //SPI 4 global interrupt

/******************************************************************************************************/
typedef enum
{
    MNVIC_GroupMode_g16s0 = 3,
    MNVIC_GroupMode_g8s2,
    MNVIC_GroupMode_g4s4,
    MNVIC_GroupMode_g2s8,
    MNVIC_GroupMode_g0s16

}MNVIC_GroupMode_t;

/*******************************************************************************************************/
/*                                      Function Prototypes                                            */
/*******************************************************************************************************/

void MNVIC_voidEnableInterrupt(u8 copy_u8PeripheralInterruptNum);

void MNVIC_voidDisableInterrupt(u8 copy_u8PeripheralInterruptNum);

void MNVIC_voidEnableInterruptPending(u8 copy_u8PeripheralInterruptNum);

void MNVIC_voidDisableInterruptPending(u8 copy_u8PeripheralInterruptNum);

u8   MNVIC_u8IsInterruptActive(u8 copy_u8PeripheralInterruptNum);

void MNVIC_voidInitInterruptGroup(MNVIC_GroupMode_t copy_GropMode);

void MNVIC_voidSetInterruptPriority(u8 copy_u8PeripheralInterruptNum, MNVIC_GroupMode_t copy_GropMode, u8 copy_u8IntGroup, u8 copy_u8IntSubPriority);

void MNVIC_voidGenerateSoftwareInterrupt(u8 copy_u8PeripheralInterruptNum);

#endif //NVIC_INTERFACE_H
