/**
 * @file RCC_private.h
 * @author Adham Eid (adhameid0@gmail.com)
 * @brief 
 * @version 0.1
 * @date 21-08-2021
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/* RCC registers definitions */
typedef struct
{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC_t;

#define RCC 			((volatile RCC_t*)0x40021000)

#define CR_HSION		0
#define CR_HSIRDY		1
#define CR_HSITRIM0		3
#define CR_HSITRIM1		4
#define CR_HSITRIM2		5
#define CR_HSITRIM3		6
#define CR_HSITRIM4		7
#define CR_HSICAL0		8
#define CR_HSICAL1		9
#define CR_HSICAL2		10
#define CR_HSICAL3		11
#define CR_HSICAL4		12
#define CR_HSICAL5		13
#define CR_HSICAL6		14
#define CR_HSICAL7		15
#define CR_HSEON		16
#define CR_HSERDY		17
#define CR_HSEBYP		18
#define CR_CSSON		19
#define CR_PLLON		24
#define CR_PLLRDY		25

#define CFGR_SW0		0
#define CFGR_SW1		1
#define CFGR_SWS0		2
#define CFGR_SWS1		3
#define CFGR_PLLSRC		16
#define CFGR_PLLXTPRE	17
#define CFGR_PLLMUL0	18
#define CFGR_PLLMUL1	19
#define CFGR_PLLMUL2	20
#define CFGR_PLLMUL3	21
#define CFGR_MCO0		24
#define CFGR_MCO1		25
#define CFGR_MCO2		26

#define HSI				1
#define HSE_CRYSTAL		2
#define HSE_RC			3
#define PLL				4
#define HSI_OVER_2		5
#define HSE				6
#define HSE_OVER_2		7
#define ENABLED			8
#define DISALED			9

#endif
