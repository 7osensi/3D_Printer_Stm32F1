/*=====================================================================================
===========================   - Stepper                   =============================
===========================   - Stepper_prog.c            =============================
===========================   - Created: 28/3/2023	      =============================
===========================   - Author: Hussein Mohamed   =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
=======================================================================================*/

/*======================================*/
/*===========  INCLUDE HAL   ===========*/
#include "Stepper_interface.h"
/*======================================*/

/*==========================================   Start_Function   ==========================================*/
extern void HAL_StepperInit(void)
{
	MGPIO_vSetPinMode(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN , _MODE_OUTPUT, _MODE_GP_OUT_PUSH_PULL);
	MGPIO_vSetPinMode(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN , _MODE_OUTPUT, _MODE_GP_OUT_PUSH_PULL);
	MGPIO_vSetPinMode(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN , _MODE_OUTPUT, _MODE_GP_OUT_PUSH_PULL);
	MGPIO_vSetPinMode(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN , _MODE_OUTPUT, _MODE_GP_OUT_PUSH_PULL);
}
/*==========================================   End_Function     ==========================================*/
/*==========================================   Start_Function   ==========================================*/
extern void HAL_StepperRotateCCWFullStep(void)
{
	u8 L_u8Counter = 0;
	u8 L_u8Coil = 0;
	for(L_u8Counter = 0; L_u8Counter < STEPPER_MOTOR_STEPS; L_u8Counter++)
	{
		L_u8Coil = ((L_u8Counter % 4) + 3);
		if(L_u8Coil == 3)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, HIGH);
		}
		else if(L_u8Coil == 4)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, LOW);
		}
		else if(L_u8Coil == 5)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, LOW);
		}
		else if(L_u8Coil == 6)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, HIGH);
		}
		Delay_vMsIn16MHz(500);
	}
}
/*==========================================   End_Function     ==========================================*/
/*==========================================   Start_Function   ==========================================*/
extern void HAL_StepperRotateCWFullStep(void)
{
	u8 L_u8Counter = 0;
	u8 L_u8Coil = 0;
	for(L_u8Counter = 0; L_u8Counter < STEPPER_MOTOR_STEPS; L_u8Counter++)
	{
		L_u8Coil = ((L_u8Counter % 4) + 3);
		if(L_u8Coil == 3)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, HIGH);
		}
		else if(L_u8Coil == 4)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, LOW);
		}
		else if(L_u8Coil == 5)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, LOW);
		}
		else if(L_u8Coil == 6)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, HIGH);
		}
		Delay_vMsIn16MHz(500);
	}
}
/*==========================================   End_Function     ==========================================*/
/*==========================================   Start_Function   ==========================================*/
extern void HAL_StepperRotateCCWHalfStep(void)
{
	u8 L_u8Counter = 0;
	u8 L_u8Coil    = 0;
	u8 L_u8Flag1   = 0;
	u8 L_u8Flag2   = 0;
	u8 L_u8Flag3   = 0;
	u8 L_u8Flag4   = 0;
	for(L_u8Counter = 0; L_u8Counter < STEPPER_MOTOR_STEPS; L_u8Counter++)
	{
		L_u8Coil = ((L_u8Counter % 4) + 3);

		/* 1st */
		if(L_u8Coil == 3 && L_u8Flag1 == 0)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, HIGH);
		L_u8Counter--;
		L_u8Flag1 = 1;
		}
		else if(L_u8Coil == 3 && L_u8Flag1 == 1)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, LOW);
		L_u8Flag1 = 0;
		}

		/* 2nd */
		else if(L_u8Coil == 4 && L_u8Flag2 == 0)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, LOW);
		L_u8Counter--;
		L_u8Flag2 = 1;
		}
		else if(L_u8Coil == 4 && L_u8Flag2 == 1)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, LOW);
		L_u8Flag2 = 0;
		}

		/* 3rd */
		else if(L_u8Coil == 5 && L_u8Flag3 == 0)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, LOW);
		L_u8Counter--;
		L_u8Flag3 = 1;
		}
		else if(L_u8Coil == 5 && L_u8Flag3 == 1)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, LOW);
		L_u8Flag3 = 1;
		}

		/* 4th */
		else if(L_u8Coil == 6 && L_u8Flag4 == 0)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, HIGH);
		L_u8Counter--;
		L_u8Flag4 = 1;
		}
		else if(L_u8Coil == 6 && L_u8Flag4 == 1)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, HIGH);
		L_u8Flag4 = 1;
		}
		Delay_vMsIn16MHz(100);
	}
}
/*==========================================   End_Function     ==========================================*/
/*==========================================   Start_Function   ==========================================*/
extern void HAL_StepperRotateCWHalfStep(void)
{
	u8 L_u8Counter = 0;
	u8 L_u8Coil    = 0;
	u8 L_u8Flag1   = 0;
	u8 L_u8Flag2   = 0;
	u8 L_u8Flag3   = 0;
	u8 L_u8Flag4   = 0;

	for(L_u8Counter = 0; L_u8Counter < STEPPER_MOTOR_STEPS; L_u8Counter++)
	{
		L_u8Coil = ((L_u8Counter % 4) + 3);

		/* 1st */
		if(L_u8Coil == 3 && L_u8Flag1 == 0)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, HIGH);
		L_u8Flag1 = 1;
		L_u8Counter--;
		}
		else if(L_u8Coil == 3 && L_u8Flag1 == 1)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, HIGH);
		L_u8Flag1 = 0;
		}

		/* 2nd */
		else if(L_u8Coil == 4 && L_u8Flag2 == 0)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, LOW);
		L_u8Flag2 = 1;
		L_u8Counter--;
		}
		else if(L_u8Coil == 4 && L_u8Flag2 == 1)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, LOW);
		L_u8Flag2 = 0;
		}

		/* 3rd */
		else if(L_u8Coil == 5 && L_u8Flag3 == 0)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, LOW);
		L_u8Flag3 = 1;
		L_u8Counter--;
		}
		else if(L_u8Coil == 5 && L_u8Flag3 == 1)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, LOW);
		L_u8Flag3 = 0;
		}

		/* 4th */
		else if(L_u8Coil == 6 && L_u8Flag4 == 0)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, LOW);
		L_u8Flag4 = 1;
		L_u8Counter--;
		}
		else if(L_u8Coil == 6 && L_u8Flag4 == 1)
		{
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_1_PIN, HIGH);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_2_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_3_PIN, LOW);
		MGPIO_vWriteData(STEPPER_MOTOR_PORT , STEPPER_MOTOR_COIL_4_PIN, HIGH);
		L_u8Flag4 = 0;
		}
		Delay_vMsIn16MHz(25);
	}
}
/*==========================================   End_Function     ==========================================*/
