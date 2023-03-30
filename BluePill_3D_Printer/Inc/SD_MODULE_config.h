/*========================================================================================
===========================   - SD_MODULE                 =============================
===========================   - SD_MODULE_config.h        =============================
===========================   - Created: 3/3/2023	      =============================
===========================   - Author: Hussein Mohamed   =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
========================================================================================*/

#ifndef SD_MODULE_CONFIG_H
#define SD_MODULE_CONFIG_H

/*===========  INCLUDE MCAL  ===========*/
#include "GPIO_interface.h"
/*======================================*/

#define SD_PORT           _GPIOA_PORT
#define SD_CS_PIN         GPIO_PIN_0            /* PA0 : CHIP SELECT PIN 							*/
#define SD_MOSI_PIN       GPIO_PIN_7       		/* PA7 : MOSI  MASTER OUTPUT SLAVE INPUT 	*/
#define SD_MISO_PIN       GPIO_PIN_6       		/* PA6 : MISO  MASTER INPUT SLAVE OUTPUT 	*/
#define SD_SCK_PIN        GPIO_PIN_5       		/* PA5 : SCK   Clock 						*/

#endif /* SD_MODULE_CONFIG_H */
