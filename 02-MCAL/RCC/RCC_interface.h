/**
 * @file RCC_interface.h
 * @author Adham Eid (adhameid0@gmail.com)
 * @brief 
 * @version 0.1
 * @date 21-08-2021
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define RCC_AHB                 0
#define RCC_APB1                1
#define RCC_APB2                2

#define RCC_DMA1_AHB            0
#define RCC_DMA2_AHB            1
#define RCC_SRAM_AHB            2
#define RCC_FLITF_AHB           4
#define RCC_CRC_AHB             6
#define RCC_FSMC_AHB            8
#define RCC_SDIO_AHB            10

#define RCC_AFIO_APB2           0
#define RCC_IOPA_APB2           2
#define RCC_IOPB_APB2           3
#define RCC_IOPC_APB2           4
#define RCC_ADC1_APB2           9
#define RCC_ADC2_APB2           10
#define RCC_TIM1_APB2           11
#define RCC_SPI1_APB2           12
#define RCC_TIM8_APB2           13
#define RCC_USART1_APB2         14
#define RCC_ADC3_APB2           15
#define RCC_TIM9_APB2           19
#define RCC_TIM10_APB2          20
#define RCC_TIM11_APB2          21

#define RCC_TIM2_APB1           0
#define RCC_TIM3_APB1           1
#define RCC_TIM4_APB1           2
#define RCC_TIM5_APB1           3
#define RCC_TIM6_APB1           4
#define RCC_TIM7_APB1           5
#define RCC_TIM12_APB1          6
#define RCC_TIM13_APB1          7
#define RCC_TIM14_APB1          8
#define RCC_WWDG_APB1           11
#define RCC_SPI2_APB1           14
#define RCC_SPI3_APB1           15
#define RCC_USART2_APB1         17
#define RCC_USART3_APB1         18
#define RCC_USART4_APB1         19
#define RCC_USART5_APB1         20
#define RCC_I2C1_APB1           21
#define RCC_I2C2_APB1           22
#define RCC_CAN_APB1            25
#define RCC_BKP_APB1            27
#define RCC_PWR_APB1            28
#define RCC_DAC_APB1            29

#define RCC_HSI                 0
#define RCC_HSE                 1
#define RCC_PLL                 2
#define RCC_SYSCLK              3
#define RCC_NO_CLOCK            4

void RCC_voidInit();
ERROR_STATE_t RCC_u8EnablePeripheral(u8 Copy_u8BusID, u8 Copy_u8PerID);
ERROR_STATE_t RCC_u8DisablePeripheral(u8 Copy_u8BusID, u8 Copy_u8PerID);
ERROR_STATE_t RCC_u8TrimHSI(u8 Copy_u8HSITrimVal);
u8 RCC_u8ReadCalibrationValue();
u8 RCC_u8ReadSystemClockStatus();
ERROR_STATE_t RCC_u8OutputClock(u8 Copy_u8ClockSource);

#endif
