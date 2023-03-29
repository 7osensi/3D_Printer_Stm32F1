/*=====================================================================================
===========================   - LCD                  	  =============================
===========================   - LCD_config.h    		      =============================
===========================   - Created: 12/3/2023	      =============================
===========================   - Author: Hussein Mohamed   =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
========================================================================================*/

#ifndef HAL_LCD_LCDCFG_H_
#define HAL_LCD_LCDCFG_H_


/*=============== SELECT_LCD_MODE ===============*/

#define _8_BIT_MODE      8
#define _4_BIT_MODE      4
/* OPTION_1 -> [ _8_BIT_MODE ]   */
/* OPTION_2 -> [ _4_BIT_MODE ]   */
#define LCD_MODE                      _4_BIT_MODE
/*=============== SELECT_LCD_PINS ===============*/
#if   LCD_MODE   ==   _8_BIT_MODE
#define LCD_DATA0_PIN                   GPIO_PIN_0
#define LCD_DATA1_PIN                   GPIO_PIN_1
#define LCD_DATA2_PIN                   GPIO_PIN_2
#define LCD_DATA3_PIN                   GPIO_PIN_3
#define LCD_DATA4_PIN                   GPIO_PIN_4
#define LCD_DATA5_PIN                   GPIO_PIN_5
#define LCD_DATA6_PIN                   GPIO_PIN_6
#define LCD_DATA7_PIN                   GPIO_PIN_7
#define LCD_EN_PIN                      GPIO_PIN_8
#define LCD_RS_PIN                      GPIO_PIN_9
#elif LCD_MODE   ==   _4_BIT_MODE

#define LCD_DATA4_PIN                   GPIO_PIN_0
#define LCD_DATA5_PIN                   GPIO_PIN_1
#define LCD_DATA6_PIN                   GPIO_PIN_2
#define LCD_DATA7_PIN                   GPIO_PIN_3
#define LCD_EN_PIN                      GPIO_PIN_8
#define LCD_RS_PIN                      GPIO_PIN_9
#endif

/*===============SELECT_LCD_DATA_PORT ===============*/
#define LCD_DATA_PORT                   GPIOA_PORT

#endif /* HAL_LCD_LCDCFG_H_ */
