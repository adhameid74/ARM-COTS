/**
 * @file RCC_config.h
 * @author Adham Eid (adhameid0@gmail.com)
 * @brief 
 * @version 0.1
 * @date 21-08-2021
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/**
 * Options:
 * HSI
 * HSE_CRYSTAL
 * HSE_RC
 * PLL
 */
#define SYSTEM_CLOCK            HSI

/**
 * Options:
 * ENABLED
 * DISABLED
 */
#define CLOCK_SECURITY          ENABLED

/**
 * @brief Consider the following only the case of choosing PLL as the system clock
 * 
 */
#if SYSTEM_CLOCK == PLL
    /**
     * Options:
     * HSI_OVER_2
     * HSE
     * HSE_OVER_2
     */
    #define PLL_SOURCE          HSI_OVER_2

    /**
     * Options:
     * From 2 to 16
     */
    #define PLL_MUL_FACTOR      4
#endif

#endif
