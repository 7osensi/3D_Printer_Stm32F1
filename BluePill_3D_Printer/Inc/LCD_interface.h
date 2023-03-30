/*======================================================================================
===========================   - LCD	   				         ===========================
===========================   - LCD_interface.h			     ===========================
===========================   - Created: 14/3/2022			 ===========================
===========================   - Author: Hussein Mohamed      ===========================
===========================   - Version : _1_				 ===========================
===========================   - Note :
									  *-
									  *-
=======================================================================================*/

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_


/*===========  INCLUDE LIB   ===========*/
#include <LCD_config.h>
#include "Std_Types.h"
#include "BIT_MATH.h"
#include "Delay_interface.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
#include "GPIO_interface.h"
/*======================================*/

/*====================================== MACROS ======================================*/
#define LCD_RETURN_HOME                        0x02
#define LCD_CLEAR                              0x01
#define DISPLAY_ON_CURSOR_OFF                  0x0C
#define _8_BIT_MODE_COMAND                     0x38
#define _4_BIT_MODE_COMAND                     0x33
#define _4_BIT_MODE_COMAND_1                   0x33
#define _4_BIT_MODE_COMAND_2                   0x32
#define _4_BIT_MODE_COMAND_3                   0x28
#define LCD_R0_C0_COMAND                       0x80
#define LCD_R1_C0_COMAND                       0xC0

/*====================================== PROTOTYPES ======================================*/
extern void HAL_LCD_Void_LcdInit(void);
extern void HAL_LCD_Void_LcdWriteCharacter(u8);
extern void HAL_LCD_Void_LcdWriteString(u8*);
extern void HAL_LCD_Void_LcdWriteNumber(s32);
extern void HAL_LCD_Void_LcdGoTo(u8,u8);
void HAL_LCD_Void_LcdWriteCommand(u8 Local_u8_Command);
extern void HAL_LCD_Void_LcdClr(void);

#endif /* HAL_LCD_LCD_H_ */
