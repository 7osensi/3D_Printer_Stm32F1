/*========================================================================================
===========================   - Stepper                   =============================
===========================   - Stepper_interface.h       =============================
===========================   - Created: 28/3/2023	      =============================
===========================   - Author: Hussein Mohamed   =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
========================================================================================*/

/*===========  INCLUDE LIB   ===========*/
#include <Std_Types.h>
#include "BIT_MATH.h"
#include "Delay_interface.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
#include "GPIO_interface.h"
/*======================================*/
/*===========  INCLUDE HAL  ============*/
#include "Stepper_config.h"
#include "Stepper_private.h"
/*======================================*/

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

extern void HAL_StepperInit(void);

extern void HAL_StepperRotateCCWFullStep(void);

extern void HAL_StepperRotateCWFullStep(void);

extern void HAL_StepperRotateCCWHalfStep(void);

extern void HAL_StepperRotateCWHalfStep(void);

#endif /* STEPPER_INTERFACE_H_ */
