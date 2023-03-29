/*========================================================================================
===========================   - SD_MODULE                 =============================
===========================   - SD_MODULE_interface.h     =============================
===========================   - Created: 3/3/2023	      =============================
===========================   - Author: Hussein Mohamed   =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
========================================================================================*/

#ifndef SD_MODULE_INTERFACE_H
#define SD_MODULE_INTERFACE_H

/*===========  INCLUDE LIB   ===========*/
#include <Std_Types.h>
#include "BIT_MATH.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
#include "GPIO_interface.h"
#include "SPI_interface.h"
/*======================================*/
/*===========  INCLUDE HAL  ============*/
#include "SD_MODULE_private.h"
#include "SD_MODULE_config.h"
/*======================================*/

/*============================================ API PROTOTYPES ============================================*/

/*
*	Name 				: 	H_SD_u8Init
*
*   Description	    	:    	1. Do the Power-Up Sequence
*   						 	2. Make Sure the Card is in The Idle State
*   						 	3. Send Interface Condition
*   						 	4. Send App Condition
*   						 	5. Send Op Condition
*   						 	6. Read OCR
*
*   Sync/Async      	: 	Sync
*
*   Reentrancy			: 	Reentrant
*
*   Parameters (in) 	:	None
*
*   Return Value		: 	u8
*/
extern u8 H_SD_u8Init();

/*
*	Name 				: 	H_SD_u8ReadSingleBlock
*
*   Description	    	: 	    1. Do the Power-Up Sequence
*   						 	2. Make Sure the Card is in The Idle State
*   						 	3. Send Interface Condition
*   						 	4. Send App Condition
*   						 	5. Send Op Condition
*   						 	6. Read OCR
*
*   Sync/Async      	: 	Sync
*
*   Reentrancy			: 	Reentrant
*
*   Parameters (in) 	:	Copy_u32Address		:	Address of The Block
*   												(0x00000000 is The Address of The First Block
*   												Bytes from 0 : 511 )
*
*   Return Value		: 	u8
*/
extern u8 H_SD_u8ReadSingleBlock(u32 Copy_u32Address, u8 *Copy_u8Buffer, u8 *Copy_u8Token);

#endif /* SD_MODULE_INTERFACE_H */
