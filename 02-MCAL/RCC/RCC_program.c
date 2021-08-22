/**
 * @file RCC_program.c
 * @author Adham Eid (adhameid0@gmail.com)
 * @brief 
 * @version 0.1
 * @date 21-08-2021
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInit()
{
	#if CLOCK_SECURITY == ENABLED
		SET_BIT(RCC->CR, CR_CSSON);
	#elif CLOCK_SECURITY == DISABLED
		CLR_BIT(RCC->CR, CR_CSSON);
	#else
		#error ("Wrong Configuration of CLOCK_SECURITY")
	#endif

	#if SYSTEM_CLOCK == HSI
		SET_BIT(RCC->CR, CR_HSION);
		CLR_BIT(RCC->CFGR, CFGR_SW0);
		CLR_BIT(RCC->CFGR, CFGR_SW1);
		while(GET_BIT(RCC->CR, CR_HSIRDY)==0);

	#elif SYSTEM_CLOCK == HSE_RC
		SET_BIT(RCC->CR, CR_HSEON);
		SET_BIT(RCC->CR, CR_HSEBYP);
		SET_BIT(RCC->CFGR, CFGR_SW0);
		CLR_BIT(RCC->CFGR, CFGR_SW1);
		while(GET_BIT(RCC->CR, CR_HSERDY)==0);

	#elif SYSTEM_CLOCK == HSE_CRYSTAL
		SET_BIT(RCC->CR, CR_HSEON);
		CLR_BIT(RCC->CR, CR_HSEBYP);
		SET_BIT(RCC->CFGR, CFGR_SW0);
		CLR_BIT(RCC->CFGR, CFGR_SW1);
		while(GET_BIT(RCC->CR, CR_HSERDY)==0);

	#elif SYSTEM_CLOCK == PLL
		SET_BIT(RCC->CR, CR_PLLON);
		#if PLL_SOURCE == HSI_OVER_2
			CLR_BIT(RCC->CFGR, CFGR_PLLSRC);
		#elif PLL_SOURCE == HSE
			SET_BIT(RCC->CFGR, CFGR_PLLSRC);
			CLR_BIT(RCC->CFGR, CFGR_PLLXTPRE);
		#elif PLL_SOURCE == HSE_OVER_2
			SET_BIT(RCC->CFGR, CFGR_PLLSRC);
			SET_BIT(RCC->CFGR, CFGR_PLLXTPRE);
		#else
			#error ("Wrong Configuration of PLL_SOURCE)
		#endif
		#if PLL_MUL_FACTOR >=2 && PLL_MUL_FACTOR <= 16
			RCC->CFGR &= ~(( 0b1111 )<<18);
			RCC->CFGR |= PLL_MUL_FACTOR<<18;
		#else
			#error ("Wrong Configuration of PLL_MUL_FACTOR")
		#endif
		SET_BIT(RCC->CFGR, CFGR_SW1);
		CLR_BIT(RCC->CFGR, CFGR_SW0);
		while(GET_BIT(RCC->CR, CR_PLLRDY)==0);

	#else
		#error ("Wrong Configuration of SYSTEM_CLOCK")
	#endif
}

ERROR_STATE_t RCC_u8EnablePeripheral(u8 Copy_u8BusID, u8 Copy_u8PerID)
{
	if (Copy_u8BusID <= 31)
	{
		switch (Copy_u8BusID)
		{
			case RCC_AHB:
				SET_BIT(RCC->AHBENR, Copy_u8PerID);
				break;
			case RCC_APB1:
				SET_BIT(RCC->APB1ENR, Copy_u8PerID);
				break;
			case RCC_APB2:
				SET_BIT(RCC->APB2ENR, Copy_u8PerID);
				break;
			default:
				return PARAMETER_ERROR;
				break;
		}
		return NO_ERROR;
	}

	return PARAMETER_ERROR;

}

ERROR_STATE_t RCC_u8DisablePeripheral(u8 Copy_u8BusID, u8 Copy_u8PerID)
{
	if (Copy_u8BusID <= 31)
	{
		switch (Copy_u8BusID)
		{
			case RCC_AHB:
				CLR_BIT(RCC->AHBENR, Copy_u8PerID);
				break;
			case RCC_APB1:
				CLR_BIT(RCC->APB1ENR, Copy_u8PerID);
				break;
			case RCC_APB2:
				CLR_BIT(RCC->APB2ENR, Copy_u8PerID);
				break;
			default:
				return PARAMETER_ERROR;
				break;
		}
		return NO_ERROR;
	}

	return PARAMETER_ERROR;
}

ERROR_STATE_t RCC_u8TrimHSI(u8 Copy_u8HSITrimVal)
{
	if ( (Copy_u8HSITrimVal >= 0) && (Copy_u8HSITrimVal <= 31) )
	{
		RCC->CR &= ~((0b11111)<<3);
		RCC->CR |= Copy_u8HSITrimVal<<3;
		return NO_ERROR;
	}
	return PARAMETER_ERROR;
}

u8 RCC_u8ReadCalibrationValue()
{
	return ((u8)(RCC->CR>>8));
}

u8 RCC_u8ReadSystemClockStatus()
{
	return ((RCC->CFGR>>2)&(0b11));
}

ERROR_STATE_t RCC_u8OutputClock(u8 Copy_u8ClockSource)
{
	switch (Copy_u8ClockSource)
	{
		case RCC_HSI:
			SET_BIT(RCC->CFGR, CFGR_MCO2);
			CLR_BIT(RCC->CFGR, CFGR_MCO1);
			SET_BIT(RCC->CFGR, CFGR_MCO0);
			break;
		case RCC_HSE:
			SET_BIT(RCC->CFGR, CFGR_MCO2);
			SET_BIT(RCC->CFGR, CFGR_MCO1);
			CLR_BIT(RCC->CFGR, CFGR_MCO0);
			break;
		case RCC_PLL:
			SET_BIT(RCC->CFGR, CFGR_MCO2);
			SET_BIT(RCC->CFGR, CFGR_MCO1);
			SET_BIT(RCC->CFGR, CFGR_MCO0);
			break;
		case RCC_SYSCLK:
			SET_BIT(RCC->CFGR, CFGR_MCO2);
			CLR_BIT(RCC->CFGR, CFGR_MCO1);
			CLR_BIT(RCC->CFGR, CFGR_MCO0);
			break;
		case RCC_NO_CLOCK:
			CLR_BIT(RCC->CFGR, CFGR_MCO2);
			break;
		default:
			return PARAMETER_ERROR;
			break;
	}
	return NO_ERROR;
}
