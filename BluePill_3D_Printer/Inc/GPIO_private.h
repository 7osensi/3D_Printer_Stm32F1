/*==============================================================================================
===============================   - GPIO				     ===============================
===============================   - GPIO_private.h		     ===============================
===============================   - Created: 24/2/2023		 ===============================
===============================   - Author: Hussein Mohamed  ===============================
===============================   - Version : _1_		     ===============================
===============================   - Note :
									     *-
									     *-
=================================================================================================*/ 

#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

/*=================================================================================
	-----> Macros
			*  Base_Address GPI0x				
=================================================================================*/

#define  GPIOA_BASE_ADDRESS         0x40010800   /*!<  Base_Address GPI0A    */
#define  GPIOB_BASE_ADDRESS         0x40010C00	 /*!<  Base_Address GPI0B    */
#define  GPIOC_BASE_ADDRESS         0x40011000   /*!<  Base_Address GPI0C    */

/*=================================================================================
	-----> Macros
			  *  Register Map	 GPIO_A		
===================================================================================*/

#define GPIOA_CRL              (*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x00)))	/*!<  Address offset: 0x00      */
#define GPIOA_CRH              (*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x04)))   /*!<  Address offset: 0x04      */
#define GPIOA_IDR              (*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x08)))   /*!<  Address offset: 0x08      */
#define GPIOA_ODR              (*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x0C)))   /*!<  Address offset: 0x0C      */
#define GPIOA_BSRR             (*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x10)))   /*!<  Address offset: 0x10      */
#define GPIOA_BRR              (*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x14)))   /*!<  Address offset: 0x14      */
#define GPIOA_LCKR             (*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x18)))   /*!<  Address offset: 0x18      */

/*=================================================================================
	-----> Macros
			  *  Register Map	 GPIO_B	
=================================================================================*/

#define GPIOB_CRL              (*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x00)))	/*!<  Address offset: 0x00      */
#define GPIOB_CRH              (*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x04)))   /*!<  Address offset: 0x04      */
#define GPIOB_IDR              (*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x08)))   /*!<  Address offset: 0x08      */
#define GPIOB_ODR              (*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x0C)))   /*!<  Address offset: 0x0C      */
#define GPIOB_BSRR             (*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x10)))   /*!<  Address offset: 0x10      */
#define GPIOB_BRR              (*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x14)))   /*!<  Address offset: 0x14      */
#define GPIOB_LCKR             (*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x18)))   /*!<  Address offset: 0x18      */

/*=================================================================================
	-----> Macros
			  *  Register Map	 GPIO_C
=================================================================================*/

#define GPIOC_CRL              (*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x00)))	/*!<  Address offset: 0x00      */
#define GPIOC_CRH              (*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x04)))   /*!<  Address offset: 0x04      */
#define GPIOC_IDR              (*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x08)))   /*!<  Address offset: 0x08      */
#define GPIOC_ODR              (*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x0C)))   /*!<  Address offset: 0x0C      */
#define GPIOC_BSRR             (*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x10)))   /*!<  Address offset: 0x10      */
#define GPIOC_BRR              (*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x14)))   /*!<  Address offset: 0x14      */
#define GPIOC_LCKR             (*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x18)))   /*!<  Address offset: 0x18      */

/*=================================================================================*/

/*================================================================
	-)Struct : General Purpose I/O				
=================================================================*/
typedef struct{
	 volatile u32 CR[2];  /*!<   CRL : Address offset: 0x00 & CRH : Address offset: 0x04     */
	 volatile u32 IDR  ;  /*!<   Address offset: 0x08      				*/
	 volatile u32 ODR  ;  /*!<   Address offset: 0x0C      				*/
	 volatile u32 BSRR ;  /*!<   Address offset: 0x10      				*/
	 volatile u32 BRR  ;  /*!<   Address offset: 0x14      				*/
	 volatile u32 LCKR ;  /*!<   Address offset: 0x1C      				*/
}GPIOx_t;

/*================================================================
	-)Struct Macros :
			*  Base_Address GPIOA
=================================================================*/
#define MGPIOA        ((GPIOx_t *) GPIOA_BASE_ADDRESS )
/*================================================================
	-)Struct Macros :
			*  Base_Address GPIOB				
=================================================================*/       
#define MGPIOB        ((GPIOx_t *) GPIOB_BASE_ADDRESS )
/*================================================================
	-)Struct Macros :
			*  Base_Address GPIOC 				
=================================================================*/  
#define MGPIOC        ((GPIOx_t *) GPIOC_BASE_ADDRESS )

#endif //_GPIO_PRIVATE_H

