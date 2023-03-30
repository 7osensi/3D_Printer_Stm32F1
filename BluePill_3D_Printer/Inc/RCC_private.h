/*==============================================================================================
===============================   - RCC	        				 ===============================
===============================   - RCC_private.h				 ===============================
===============================   - Created:24/2/2023			 ===============================
===============================   - Author: Hussein Mohamed      ===============================
===============================   - Version : _1_				 ===============================
===============================   - Note :
									     *-
									     *-
=================================================================================================*/ 

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#include <Std_Types.h>
/*================================================================
	-----> Macros
			*  Base_Address is				0x40021000
=================================================================*/

#define MRCC_BASE_ADDRESS     0x40021000
/*================================================================
	-----> Macros
			*  Register Map
=================================================================*/
#define RCC_CR                      (*(( volatile u32* )( MRCC_BASE_ADDRESS + 0x00 )))
#define RCC_CFGR                    (*(( volatile u32* )( MRCC_BASE_ADDRESS + 0x04 )))
#define RCC_CIR                     (*(( volatile u32* )( MRCC_BASE_ADDRESS + 0x08 )))
#define RCC_APB2RSTR                (*(( volatile u32* )( MRCC_BASE_ADDRESS + 0x0C )))
#define RCC_APB1RSTR                (*(( volatile u32* )( MRCC_BASE_ADDRESS + 0x10 )))
#define RCC_AHBENR                  (*(( volatile u32* )( MRCC_BASE_ADDRESS + 0x14 )))
#define RCC_APB2ENR                 (*(( volatile u32* )( MRCC_BASE_ADDRESS + 0x18 )))
#define RCC_APB1ENR                 (*(( volatile u32* )( MRCC_BASE_ADDRESS + 0x1C )))
#define RCC_BDCR                    (*(( volatile u32* )( MRCC_BASE_ADDRESS + 0x20 )))
#define RCC_CSR                  	(*(( volatile u32* )( MRCC_BASE_ADDRESS + 0x24 )))
#define RCC_AHBSTR                 	(*(( volatile u32* )( MRCC_BASE_ADDRESS + 0x28 )))
#define RCC_CFGR2                  	(*(( volatile u32* )( MRCC_BASE_ADDRESS + 0x2C )))


/**********************************************/
#define CSSON   19U
/**********************************************/

typedef struct
{
  volatile u32 CR;
  volatile u32 CFGR;
  volatile u32 CIR;
  volatile u32 APB2RSTR;
  volatile u32 APB1RSTR;
  volatile u32 AHBENR;
  volatile u32 APB2ENR;
  volatile u32 APB1ENR;
  volatile u32 BDCR;
  volatile u32 CSR;
  volatile u32 AHBSTR;
  volatile u32 CFGR2;
} RCC_t;

/*================================================================
	-)Struct Macros :
			*  Base_Address RRC 				
=================================================================*/
#define MRCC      ( ( RCC_t * )MRCC_BASE_ADDRESS )

#endif //RCC_PRIVATE_H
