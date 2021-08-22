/**
 * @file GPIO_private.h
 * @author Adham Eid (adhameid0@gmail.com)
 * @brief 
 * @version 0.1
 * @date 22-08-2021
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/* GPIO registers definitions */
typedef struct
{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
}GPIO_t;

#define GPIOA 			((volatile GPIO_t*)0x40010800)
#define GPIOB 			((volatile GPIO_t*)0x40010C00)
#define GPIOC 			((volatile GPIO_t*)0x40011000)



#endif
