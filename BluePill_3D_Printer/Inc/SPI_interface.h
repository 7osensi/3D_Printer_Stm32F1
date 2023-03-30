/*========================================================================================
===========================   - SPI                       =============================
===========================   - SPI_interface.h           =============================
===========================   - Created: 3/3/2023	      =============================
===========================   - Author: Hussein Mohamed   =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
========================================================================================*/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/*===========  INCLUDE LIB  ============*/
#include <Std_Types.h>
#include "BIT_MATH.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
#include "SPI_config.h"
#include "SPI_private.h"
#include "GPIO_interface.h"
/*======================================*/

/*============================================ API PROTOTYPES ============================================*/

/*
*   Name 			: M_SPI1_vInit
*
*   Description	    : API To Initialize SPI1
*
*   Sync/Async      : Async
*
*   Reentrancy		:
*
*/
extern void M_SPI1_vInit(void);

/*
*   Name 				: M_SPI1_u8Transceive
*
*   Description	   	 	: API To Send and Receive Data Using SPI1
*
*   Sync/Async     	 	: Sync
*
*   Reentrancy			:
*
*   u8 Copy_u8Data     	:
*
*/
extern u8 M_SPI1_u8Transceive(u8 Copy_u8Data);

/*
*   Name 				: M_SPI1_vReceive
*
*   Description	    	: API To Receive Data
*
*   Sync/Async      	: Sync
*
*   Reentrancy			:
*
*	u8 Copy_Pu8Data		:
*
*	u8 Copy_u8Size		:
*/
extern void M_SPI1_vReceive(u8 *Copy_Pu8Data, u8 Copy_u8Size);

/*
*   Name 				: M_SPI1_vSetCallBack
*
*   Description	    	: API To Set Call Back Function
*
*   Sync/Async      	: Async
*
*   void (*ptr) (void)  : Pointer to Function That Takes void and Returns void
*
*   Reentrancy			:
*
*/
extern void M_SPI1_vSetCallBack(void (*ptr) (void));

#endif /* SPI_INTERFACE_H_ */
