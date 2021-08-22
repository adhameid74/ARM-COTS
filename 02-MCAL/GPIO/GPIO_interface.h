/**
 * @file GPIO_interface.h
 * @author Adham Eid (adhameid0@gmail.com)
 * @brief 
 * @version 0.1
 * @date 22-08-2021
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#define GPIO_PORTA              0
#define GPIO_PORTB              1
#define GPIO_PORTC              2

#define GPIO_PIN0               0
#define GPIO_PIN1               1
#define GPIO_PIN2               2
#define GPIO_PIN3               3
#define GPIO_PIN4               4
#define GPIO_PIN5               5
#define GPIO_PIN6               6
#define GPIO_PIN7               7
#define GPIO_PIN8               8
#define GPIO_PIN9               9
#define GPIO_PIN10              10
#define GPIO_PIN11              11
#define GPIO_PIN12              12
#define GPIO_PIN13              13
#define GPIO_PIN14              14
#define GPIO_PIN15              15

#define GPIO_IN_ANALOG          0b0000
#define GPIO_IN_FLOATING        0b0100
#define GPIO_IN_PULL_UPDOWN     0b1000

#define GPIO_OUT_GPPP_10MHZ     0b0001
#define GPIO_OUT_GPOD_10MHZ     0b0101
#define GPIO_OUT_AFPP_10MHZ     0b1001
#define GPIO_OUT_AFOD_10MHZ     0b1101

#define GPIO_OUT_GPPP_2MHZ      0b0010
#define GPIO_OUT_GPOD_2MHZ      0b0110
#define GPIO_OUT_AFPP_2MHZ      0b1010
#define GPIO_OUT_AFOD_2MHZ      0b1110

#define GPIO_OUT_GPPP_50MHZ     0b0011
#define GPIO_OUT_GPOD_50MHZ     0b0111
#define GPIO_OUT_AFPP_50MHZ     0b1011
#define GPIO_OUT_AFOD_50MHZ     0b1111

#define GPIO_LOW                0
#define GPIO_HIGH               1

ERROR_STATE_t GPIO_u8SetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
ERROR_STATE_t GPIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
ERROR_STATE_t GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value);
ERROR_STATE_t GPIO_u8SetPortValue(u8 Copy_u8Port, u16 Copy_u16Value);

#endif
