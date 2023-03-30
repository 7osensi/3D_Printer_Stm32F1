/*========================================================================================
===========================   - Stepper                   =============================
===========================   - Stepper_config.h          =============================
===========================   - Created: 28/3/2023	      =============================
===========================   - Author: Hussein Mohamed   =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
========================================================================================*/

/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
#include "GPIO_interface.h"
/*======================================*/

#ifndef STEPPER_CONFIG_H_
#define STEPPER_CONFIG_H_

#define STEPPER_MOTOR_PORT					_GPIOB_PORT
#define	STEPPER_MOTOR_COIL_1_PIN			GPIO_PIN_3
#define	STEPPER_MOTOR_COIL_2_PIN			GPIO_PIN_4
#define	STEPPER_MOTOR_COIL_3_PIN			GPIO_PIN_5
#define	STEPPER_MOTOR_COIL_4_PIN			GPIO_PIN_6


#endif /* STEPPER_CONFIG_H_ */
