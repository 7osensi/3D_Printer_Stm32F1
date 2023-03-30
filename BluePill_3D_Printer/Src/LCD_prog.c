/*=====================================================================================
===========================   - LCD                  	  =============================
===========================   - LCD_prog.c   		      =============================
===========================   - Created: 30/3/2023	      =============================
===========================   - Author: Hussein Mohamed   =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
=======================================================================================*/

/*===========  INCLUDE HAL   ===========*/
#include "LCD_interface.h"
/*======================================*/

/*============================================   Start_Function   ============================================*/

extern void HAL_LCD_Void_LcdInit(void)
{
	u8 L_u8Counter = 0;
#if   LCD_MODE == _8_BIT_MODE
	for (L_u8Counter = 0; L_u8Counter <= 9; L_u8Counter++)
	{
		MGPIO_vSetPinMode(LCD_DATA_PORT, L_u8Counter, _MODE_OUTPUT, _MODE_GP_OUT_PUSH_PULL);
	}
	Delay_vMsIn16MHz(500);
	HAL_LCD_Void_LcdWriteCommand(_8_BIT_MODE_COMAND);
	HAL_LCD_Void_LcdWriteCommand(DISPLAY_ON_CURSOR_OFF);
	HAL_LCD_Void_LcdWriteCommand(LCD_RETURN_HOME);
	HAL_LCD_Void_LcdWriteCommand(LCD_CLEAR);

#elif LCD_MODE == _4_BIT_MODE

	for (L_u8Counter = 0; L_u8Counter <= 9; L_u8Counter++)
	{
		if (L_u8Counter == 4)
		{
			L_u8Counter=8;
		}
		MGPIO_vSetPinMode(LCD_DATA_PORT, L_u8Counter, _MODE_OUTPUT, _MODE_GP_OUT_PUSH_PULL);
	}
	Delay_vMsIn16MHz(500);
	HAL_LCD_Void_LcdWriteCommand(_4_BIT_MODE_COMAND_1);
	HAL_LCD_Void_LcdWriteCommand(_4_BIT_MODE_COMAND_2);
	HAL_LCD_Void_LcdWriteCommand(_4_BIT_MODE_COMAND_3);
	HAL_LCD_Void_LcdWriteCommand(DISPLAY_ON_CURSOR_OFF);
	HAL_LCD_Void_LcdWriteCommand(LCD_RETURN_HOME);
	HAL_LCD_Void_LcdWriteCommand(LCD_CLEAR);
#endif
}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

extern void HAL_LCD_Void_LcdWriteCharacter(u8 Local_u8_Character)
{
#if LCD_MODE ==_8_BIT_MODE
	MGPIO_vWriteData(LCD_DATA_PORT, LCD_RS_PIN, HIGH);
	MGPIO_vPortOutputByte(LCD_DATA_PORT, Local_u8_Character, 0, 8);
	MGPIO_vWriteData(LCD_DATA_PORT, LCD_EN_PIN, HIGH);
	Delay_vMsIn16MHz(1);
	MGPIO_vWriteData(LCD_DATA_PORT, LCD_EN_PIN, LOW);
#elif LCD_MODE ==_4_BIT_MODE
	MGPIO_vWriteData(LCD_DATA_PORT, LCD_RS_PIN, HIGH);
	MGPIO_vPortOutputByte(LCD_DATA_PORT, Local_u8_Character >> 4, 0, 4);
	MGPIO_vWriteData(LCD_DATA_PORT, LCD_EN_PIN, HIGH);

	Delay_vMsIn16MHz(1);

	MGPIO_vWriteData(LCD_DATA_PORT, LCD_EN_PIN, LOW);

	Delay_vMsIn16MHz(1);

	MGPIO_vPortOutputByte(LCD_DATA_PORT, Local_u8_Character, 0, 4);
	MGPIO_vWriteData(LCD_DATA_PORT, LCD_EN_PIN, HIGH);

	Delay_vMsIn16MHz(1);

	MGPIO_vWriteData(LCD_DATA_PORT, LCD_EN_PIN, LOW);
#endif
	Delay_vMsIn16MHz(5);
}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

void HAL_LCD_Void_LcdWriteCommand(u8 Local_u8_Command)
{
#if LCD_MODE ==_8_BIT_MODE
	MGPIO_vWriteData(LCD_DATA_PORT, LCD_RS_PIN, LOW);
	MGPIO_vPortOutputByte(LCD_DATA_PORT, Local_u8_Command, 0, 8);
	MGPIO_vWriteData(LCD_DATA_PORT, LCD_EN_PIN, HIGH);
	Delay_vMsIn16MHz(1);
	MGPIO_vWriteData(LCD_DATA_PORT, LCD_EN_PIN, LOW);
#elif LCD_MODE ==_4_BIT_MODE
	MGPIO_vWriteData(LCD_DATA_PORT, LCD_RS_PIN, LOW);
	MGPIO_vPortOutputByte(LCD_DATA_PORT, Local_u8_Command >> 4, 0, 4);
	MGPIO_vWriteData(LCD_DATA_PORT, LCD_EN_PIN, HIGH);

	Delay_vMsIn16MHz(1);

	MGPIO_vWriteData(LCD_DATA_PORT, LCD_EN_PIN, LOW);

	Delay_vMsIn16MHz(1);

	MGPIO_vPortOutputByte(LCD_DATA_PORT, Local_u8_Command, 0, 4);
	MGPIO_vWriteData(LCD_DATA_PORT, LCD_EN_PIN, HIGH);

	Delay_vMsIn16MHz(1);

	MGPIO_vWriteData(LCD_DATA_PORT, LCD_EN_PIN, LOW);
#endif
	Delay_vMsIn16MHz(5);

}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

extern void HAL_LCD_Void_LcdWriteString(u8* Local_u8_String)
{
	u8 Local_u8_Character;
	while(*Local_u8_String != '\0')
	{
		Local_u8_Character = *Local_u8_String;
		HAL_LCD_Void_LcdWriteCharacter(Local_u8_Character);
		Local_u8_String++;
	}
}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

extern void HAL_LCD_Void_LcdWriteNumber(s32 Local_f32_Number)
{
	u8 Local_u8_Arr [10] = {0};
	s8 Local_s8_Counter = 0;
	s8 Local_s8_Decimal_Point = 0;
	s32 Local_s32_Number;

	if(Local_f32_Number < 0)
	{
		Local_f32_Number *= -1;
		HAL_LCD_Void_LcdWriteCharacter('-');
	}

	Local_s32_Number=Local_f32_Number;

	if (Local_s32_Number == 0)
	{
		HAL_LCD_Void_LcdWriteCharacter(48);
	}

	while (Local_s32_Number != Local_f32_Number)
	{
		Local_f32_Number = Local_f32_Number * 10;
		Local_s32_Number = Local_f32_Number;
		Local_s8_Decimal_Point++;
	}


	while (Local_s32_Number != 0)
	{
		Local_u8_Arr[Local_s8_Counter] = Local_s32_Number % 10;
		Local_s32_Number = Local_s32_Number / 10;
		Local_s8_Counter++;
	}

	Local_s8_Counter--;

	while (Local_s8_Counter >= 0)
	{
		if((Local_s8_Decimal_Point > 0) && (Local_s8_Decimal_Point - 1 == Local_s8_Counter))
		{
			HAL_LCD_Void_LcdWriteCharacter('.');
		}
		HAL_LCD_Void_LcdWriteCharacter(Local_u8_Arr[Local_s8_Counter] + 48);
		Local_s8_Counter--;
	}


}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

extern void HAL_LCD_Void_LcdGoTo(u8 Local_u8_Row,u8 Local_u8_Col)
{
	u8 Local_u8_arr[2] = {LCD_R0_C0_COMAND, LCD_R1_C0_COMAND};
	HAL_LCD_Void_LcdWriteCommand(Local_u8_arr[Local_u8_Row] + Local_u8_Col);

}
/*============================================   End_Function     ============================================*/
/*============================================   Start_Function   ============================================*/

extern void HAL_LCD_Void_LcdClr(void)
{
	HAL_LCD_Void_LcdWriteCommand(LCD_CLEAR);
}
/*============================================   End_Function     ============================================*/
