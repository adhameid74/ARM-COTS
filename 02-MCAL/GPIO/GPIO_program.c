/**
 * @file GPIO_program.c
 * @author Adham Eid (adhameid0@gmail.com)
 * @brief 
 * @version 0.1
 * @date 22-08-2021
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR.h"
//asdasdas
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

ERROR_STATE_t GPIO_u8SetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	if ( (Copy_u8Mode > 15) || (Copy_u8Mode == 12) || (Copy_u8Port > GPIO_PORTC) || (Copy_u8Pin > GPIO_PIN15) )
	{
		return PARAMETER_ERROR;
	}

	switch(Copy_u8Port)
	{
		case GPIO_PORTA:
			if (Copy_u8Pin <= 7)
			{
				GPIOA->CRL &= ~( (0b1111) << (4*Copy_u8Pin) );
				GPIOA->CRL |= (Copy_u8Mode << (4*Copy_u8Pin));
			}
			else
			{
				GPIOA->CRH &= ~( (0b1111) << (4*(Copy_u8Pin-8)) );
				GPIOA->CRH |= (Copy_u8Mode << (4*(Copy_u8Pin-8)));
			}
			break;
		case GPIO_PORTB:
			if (Copy_u8Pin <= 7)
			{
				GPIOB->CRL &= ~( (0b1111) << (4*Copy_u8Pin) );
				GPIOB->CRL |= (Copy_u8Mode << (4*Copy_u8Pin));
			}
			else
			{
				GPIOB->CRH &= ~( (0b1111) << (4*(Copy_u8Pin-8)) );
				GPIOB->CRH |= (Copy_u8Mode << (4*(Copy_u8Pin-8)));
			}
			break;
		case GPIO_PORTC:
			if (Copy_u8Pin <= 7)
			{
				GPIOC->CRL &= ~( (0b1111) << (4*Copy_u8Pin) );
				GPIOC->CRL |= (Copy_u8Mode << (4*Copy_u8Pin));
			}
			else
			{
				GPIOC->CRH &= ~( (0b1111) << (4*(Copy_u8Pin-8)) );
				GPIOC->CRH |= (Copy_u8Mode << (4*(Copy_u8Pin-8)));
			}
			break;
	}
	return NO_ERROR;
}

ERROR_STATE_t GPIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	if ( (Copy_u8Value > GPIO_HIGH) || (Copy_u8Port > GPIO_PORTC) || (Copy_u8Pin > GPIO_PIN15) )
	{
		return PARAMETER_ERROR;
	}

	switch(Copy_u8Port)
	{
		case GPIO_PORTA:
			if (Copy_u8Value == GPIO_HIGH)
			{
				SET_BIT(GPIOA->ODR, Copy_u8Pin);
			}
			else
			{
				CLR_BIT(GPIOA->ODR, Copy_u8Pin);
			}
			break;
		case GPIO_PORTB:
			if (Copy_u8Value == GPIO_HIGH)
			{
				SET_BIT(GPIOB->ODR, Copy_u8Pin);
			}
			else
			{
				CLR_BIT(GPIOB->ODR, Copy_u8Pin);
			}
			break;
		case GPIO_PORTC:
			if (Copy_u8Value == GPIO_HIGH)
			{
				SET_BIT(GPIOC->ODR, Copy_u8Pin);
			}
			else
			{
				CLR_BIT(GPIOC->ODR, Copy_u8Pin);
			}
			break;
	}
	return NO_ERROR;
}

ERROR_STATE_t GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value)
{
	if ( (Copy_u8Port > GPIO_PORTC) || (Copy_u8Pin > GPIO_PIN15) )
	{
		return PARAMETER_ERROR;
	}
	if (Copy_pu8Value == NULL)
	{
		return NULL_POINTER_ERROR;
	}

	switch(Copy_u8Port)
	{
		case GPIO_PORTA:
			*Copy_pu8Value = GET_BIT(GPIOA->IDR, Copy_u8Pin);
			break;
		case GPIO_PORTB:
			*Copy_pu8Value = GET_BIT(GPIOB->IDR, Copy_u8Pin);
			break;
		case GPIO_PORTC:
			*Copy_pu8Value = GET_BIT(GPIOC->IDR, Copy_u8Pin);
			break;
	}
	return NO_ERROR;
}
