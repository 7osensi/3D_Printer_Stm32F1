/****************************** *********************************************************
============================    - GPIO						 ============================
============================    - GPIO_program.c			 ============================
============================   - Created: 24/2/2022			 ============================
============================   - Author: Hussein Mohamed     ============================
============================   - Version : _1_				 ============================
============================   - Note :						 ============================
									*-
									*-
 **************************************************************************************/

/*===========  INCLUDE MCAL  ===========*/
		#include "GPIO_interface.h"
/*======================================*/	

/*============================================   Start_Function   ============================================*/

void MGIO_vResetCR(u8 Copy_u8PortName, u8 Copy_u8PinNum)
{
	switch (Copy_u8PortName)
	{
	case _GPIOA_PORT:
		if (Copy_u8PinNum <= 7)
		{
		GPIOA_CRL = 0;
		}
		else if(Copy_u8PinNum >= 8)
		{
		GPIOA_CRH = 0;
		}
		else
		{
			/* No Action  */
		}
	break;
	case _GPIOB_PORT:
		if (Copy_u8PinNum <= 7)
		{
		GPIOB_CRL = 0;
		}
		else if(Copy_u8PinNum >= 8)
		{
		GPIOB_CRH = 0;
		}
		else
		{
			/* No Action  */
		}
	break;
	case _GPIOC_PORT:
		if ( Copy_u8PinNum <= 7)
		{
		GPIOC_CRL = 0;
		}
		else if(Copy_u8PinNum >= 8)
		{
		GPIOC_CRH = 0;
		}
		else
		{ /* No Action */

		}
	break;
	default: 					        break;
	}
}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

void MGPIO_vSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8Mode, u8 Copy_u8Config)
{
	/* Used To Select Between CRL and CRH Registers */
	u8 L_u8Index = 0;

	/* Calculate the index of CRL and CRH
	 * Pins <= 7 configured using CR[0]
	 * Pins >= 8 configured using CR [1] */
	if( Copy_u8PinNum <= 7)
	{
		L_u8Index = 0;
	}
	else if(Copy_u8PinNum >= 8)
	{
		L_u8Index = 1;
	}
	/* if condition to get the right pin for CRH or CR[1] register */
	if(Copy_u8PinNum >= 8)
	{
		Copy_u8PinNum -= 8;
	}

	switch(Copy_u8PortName)
	{
	case _GPIOA_PORT:
		if(Copy_u8Mode == _MODE_INPUT)
		{
			/* In input mode (MODE[1:0]=00)  */
			MGPIOA->CR[L_u8Index] &= ~(1 << (4 * Copy_u8PinNum));
			/* 00: Analog mode */
			if (Copy_u8Config == _MODE_ANALOG)
			{
				MGPIOA->CR[L_u8Index] &= ~(1 << ((4 * Copy_u8PinNum) + 2 ));
			}
			/* 01: Floating input (reset state) */
			else if ( Copy_u8Config == _MODE_FLOATING)
			{
				MGPIOA->CR[L_u8Index] |= (1 << ((4 * Copy_u8PinNum) + 2));
			}
			/* 10: Input with pull-up / pull-down */
			else if ( Copy_u8Config == _MODE_IN_PU_PD)
			{
				MGPIOA->CR[L_u8Index] |= (2 << ((4 * Copy_u8PinNum) + 2));
			}
		}
		else if (Copy_u8Mode == _MODE_OUTPUT)
		{
			/* In output mode (MODE[1:0] > 00) , max speed 10 MHz */
			MGPIOA->CR[L_u8Index] |= (1 << (4 * Copy_u8PinNum));
			/* 00: General purpose output push-pull */
			if ( Copy_u8Config == _MODE_GP_OUT_PUSH_PULL)
			{
				MGPIOA->CR[L_u8Index] &= ~(1 << ((4 * Copy_u8PinNum) + 2));
			}
			/* 01: General purpose output Open-drain */
			else if (Copy_u8Config == _MODE_GP_OUT_OPEN_DR)
			{
				MGPIOA->CR[L_u8Index] |= (1 << ((4 * Copy_u8PinNum) + 2));
			}
			/* 10: Alternate function output Push-pull */
			else if (Copy_u8Config == _MODE_GP_OUT_ALT_PUSH_PULL)
			{
				MGPIOA->CR[L_u8Index] |= (2 << (( 4 * Copy_u8PinNum) + 2));

			}
			/* 11: Alternate function output Open-drain */
			else if (Copy_u8Config == _MODE_GP_OUT_ALT_OPEN_DR)
			{
				MGPIOA->CR[L_u8Index] |= (3 << ((4 * Copy_u8PinNum) + 2));

			}
		}
		break;
	case _GPIOB_PORT:
		if (Copy_u8Mode == _MODE_INPUT)
		{
			/* In input mode (MODE[1:0]=00) */
			MGPIOB->CR[L_u8Index] &= ~(1 << (4 * Copy_u8PinNum));
			/* 00: Analog mode */
			if (Copy_u8Config == _MODE_ANALOG)
			{
				MGPIOB->CR[L_u8Index] &= ~(1 << ((4 * Copy_u8PinNum) + 2));
			}
			/* 01: Floating input (reset state) */
			else if (Copy_u8Config == _MODE_FLOATING)
			{
				MGPIOB->CR[L_u8Index] |= ( 1 << ((4 * Copy_u8PinNum ) + 2));
			}
			/* 10: Input with pull-up / pull-down */
			else if (Copy_u8Config == _MODE_IN_PU_PD) {
				MGPIOB->CR[L_u8Index] |= ( 2 << ((4 * Copy_u8PinNum ) + 2));
			}
		}
		else if (Copy_u8Mode == _MODE_OUTPUT)
		{
			/* In output mode (MODE[1:0] > 00) , max speed 10 MHz */
			MGPIOB->CR[L_u8Index] |= (1 << (4 * Copy_u8PinNum));
			//GPIOB_CRL = ( 1 << ( 4 * Copy_u8PinNum ) );
			/* 00: General purpose output push-pull */
			if ( Copy_u8Config == _MODE_GP_OUT_PUSH_PULL)
			{
				MGPIOB->CR[L_u8Index] &= ~(1 << ((4 * Copy_u8PinNum) + 2));
			}
			/* 01: General purpose output Open-drain */
			else if (Copy_u8Config == _MODE_GP_OUT_OPEN_DR)
			{
				MGPIOB->CR[L_u8Index] = (1 << ((4 * Copy_u8PinNum) + 2));
			}
			/* 10: Alternate function output Push-pull */
			else if (Copy_u8Config == _MODE_GP_OUT_ALT_PUSH_PULL)
			{
				MGPIOB->CR[L_u8Index] = (2 << ((4 * Copy_u8PinNum) + 2));

			}
			/* 11: Alternate function output Open-drain */
			else if (Copy_u8Config == _MODE_GP_OUT_ALT_OPEN_DR)
			{
				MGPIOB->CR[L_u8Index] = (3 << ((4 * Copy_u8PinNum) + 2));

			}
		}
		break;
	case _GPIOC_PORT:
		if (Copy_u8Mode == _MODE_INPUT)
		{
			/* In input mode (MODE[1:0]=00) */
			MGPIOC->CR[L_u8Index] &= ~(1 << (4 * Copy_u8PinNum));
			/* 00: Analog mode */
			if (Copy_u8Config == _MODE_ANALOG)
			{
				MGPIOC->CR[L_u8Index] &= ~(1 << ((4 * Copy_u8PinNum) + 2));
			}
			/* 01: Floating input (reset state) */
			else if (Copy_u8Config == _MODE_FLOATING)
			{
				MGPIOC->CR[L_u8Index] |= (1 << ((4 * Copy_u8PinNum) + 2));
			}
			/* 10: Input with pull-up / pull-down */
			else if (Copy_u8Config == _MODE_IN_PU_PD)
			{
				MGPIOC->CR[L_u8Index] |= (2 << ((4 * Copy_u8PinNum) + 2));
			}
		}
		else if (Copy_u8Mode == _MODE_OUTPUT)
		{
			/* In output mode (MODE[1:0] > 00) , max speed 10 MHz */
			MGPIOC->CR[L_u8Index] |= (1 << (4 * Copy_u8PinNum));
			/* 00: General purpose output push-pull */
			if (Copy_u8Config == _MODE_GP_OUT_PUSH_PULL )
			{
				MGPIOC->CR[L_u8Index] &= ~(1 << ((4 * Copy_u8PinNum) + 2));
			}
			/* 01: General purpose output Open-drain */
			else if (Copy_u8Config == _MODE_GP_OUT_OPEN_DR )
			{
				MGPIOC->CR[L_u8Index] |= (1 << ((4 * Copy_u8PinNum) + 2));
			}
			/* 10: Alternate function output Push-pull */
			else if (Copy_u8Config == _MODE_GP_OUT_ALT_PUSH_PULL)
			{
				MGPIOC->CR[L_u8Index] |= (2 << ((4 * Copy_u8PinNum) + 2));
			}
			/* 11: Alternate function output Open-drain */
			else if (Copy_u8Config == _MODE_GP_OUT_ALT_OPEN_DR)
			{
				MGPIOC->CR[L_u8Index] |= (3 << ((4 * Copy_u8PinNum) + 2));
			}
		}
		break;
	default:		break;
	}
}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

u8 MGPIO_u8ReadData(u8 Copy_u8PORT ,u8 Copy_u8PIN)
{
	u8 L_u8Data = 0 ;
	switch(Copy_u8PORT)
	{ 
	  case _GPIOA_PORT :L_u8Data = GET_BIT(GPIOA_IDR,Copy_u8PIN); break;
	  case _GPIOB_PORT :L_u8Data = GET_BIT(GPIOB_IDR,Copy_u8PIN); break;
	  case _GPIOC_PORT :L_u8Data = GET_BIT(GPIOC_IDR,Copy_u8PIN); break;
	  default : /* No Action */ 								  break ;
	}
	return L_u8Data;
}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

void MGPIO_vWriteData(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State)
{
	if(Copy_u8State == HIGH)
	{
		switch(Copy_u8PortName)
		{
		case _GPIOA_PORT:MGPIOA->ODR |= (1U << Copy_u8PinNum);		break;
		case _GPIOB_PORT:MGPIOB->ODR |= (1U << Copy_u8PinNum);		break;
		case _GPIOC_PORT:MGPIOC->ODR |= (1U << Copy_u8PinNum);		break;
		default:													break;
		}
	}
	else
	{
		switch(Copy_u8PortName)
		{
		case _GPIOA_PORT:MGPIOA->ODR &= ~(1U << Copy_u8PinNum);		break;
		case _GPIOB_PORT:MGPIOB->ODR &= ~(1U << Copy_u8PinNum);		break;
		case _GPIOC_PORT:MGPIOC->ODR &= ~(1U << Copy_u8PinNum);		break;
		default:													break;
		}
	}
}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

void MGPIO_vWriteDataDIR(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State)
{
	if(Copy_u8State == HIGH)
	{
		switch(Copy_u8PortName)
		{
		case _GPIOA_PORT :  MGPIOA ->BSRR = (1U << Copy_u8PinNum); break;
		case _GPIOB_PORT :  MGPIOB ->BSRR = (1U << Copy_u8PinNum); break;
		case _GPIOC_PORT :  MGPIOC ->BSRR = (1U << Copy_u8PinNum); break;
		default : /* No Action  */ 							   	   break;
		}
	}
	else{
		Copy_u8PinNum += 16U;
		switch(Copy_u8PortName)
		{
		case _GPIOA_PORT : MGPIOA ->BSRR = (1U << Copy_u8PinNum); break;
		case _GPIOB_PORT : MGPIOB ->BSRR = (1U << Copy_u8PinNum); break;
		case _GPIOC_PORT : MGPIOC ->BSRR = (1U << Copy_u8PinNum); break;
		default : /* No Action */ 								  break;
		}
	}
}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

void MGPIO_vPortOutputOneByte(u8 Copy_u8Port, u8 Copy_u8Data, u8 Copy_u8StartBit)
{
	switch( Copy_u8Port ){
		case _GPIOA_PORT :
			/* In ODR  shift ( 0000 0000 ) to the Start bit & Shift data to the Start Bit  */
			MGPIOA->ODR = (MGPIOA->ODR & ~(0xff << (Copy_u8StartBit))) | (Copy_u8Data << (Copy_u8StartBit));  break;
		case _GPIOB_PORT :
			MGPIOB->ODR = (MGPIOB->ODR & ~(0xff << (Copy_u8StartBit))) | (Copy_u8Data << (Copy_u8StartBit));  break;
		case _GPIOC_PORT :
			MGPIOC->ODR = (MGPIOC->ODR & ~(0xff << (Copy_u8StartBit))) | (Copy_u8Data << (Copy_u8StartBit));  break;
		default: 																							  break;
	}

}
/*============================================   End_Function     ============================================*/


/*
 *
 *
 *
 *
 *
 *
 *
void MGPIO_vPortOutputByte(port_t Copy_u8PortName, u32 Copy_u32Data, u8 Copy_u8StartBit,u8 Copy_u8EndBit)
{
	 u8 i;
	 u32 Copy_32DataBit=1;
	 Copy_u8EndBit-=Copy_u8StartBit;
	for (i=0;i<Copy_u8EndBit;i++)
	{
		Copy_32DataBit=(Copy_32DataBit<<1) +1;
	}
	MGPIO(Copy_u8PortName) ->ODR = (MGPIO(Copy_u8PortName) ->ODR & ~(Copy_32DataBit <<Copy_u8StartBit))|(Copy_u32Data<<Copy_u8StartBit);
}
 *
 */
