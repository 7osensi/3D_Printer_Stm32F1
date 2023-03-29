/*=====================================================================================
===========================   - ADC                   	  =============================
===========================   - ADC_private.h		      =============================
===========================   - Created: 12/3/2023	      =============================
===========================   - Author: Hussein Mohamed   =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
========================================================================================*/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*********************************** INCLUDE LIB ***********************************/
#include <Std_Types.h>
/***********************************************************************************
	-----> Macros
			*  Base_Address SPI
************************************************************************************/
#define 	ADC1_BASE_ADDRESS          0x40012400  /* APB2 */
#define 	ADC2_BASE_ADDRESS          0x40012800  /* APB2 */
#define     ADC3_BASE_ADDRESS          0x40013C00  /* APB2 */

/***********************************************************************************
----->	Struct
		*  Register Map :SPI
************************************************************************************/

typedef struct
{
	volatile u32 SR     ;          /* ADC status register							,      	    Address offset: 0x00 */
	volatile u32 CR1    ;          /* ADC control register 1						,           Address offset: 0x04 */
	volatile u32 CR2    ;          /* ADC control register 2						,			Address offset: 0x08 */
	volatile u32 SMPR1  ;          /* ADC sample time register 1					,           Address offset: 0x0C */
	volatile u32 SMPR2  ;          /* ADC sample time register 2					, 			Address offset: 0x10 */
	volatile u32 JOFR1  ;          /* ADC injected channel data offset register 1	,         	Address offset: 0x14 */
	volatile u32 JOFR2  ;          /* ADC injected channel data offset register 2	,         	Address offset: 0x18 */
	volatile u32 JOFR3  ;          /* ADC injected channel data offset register 3	,           Address offset: 0x1C */
	volatile u32 JOFR4  ;          /* ADC injected channel data offset register 4	,           Address offset: 0x20 */
	volatile u32 HTR    ;          /* ADC watchdog high threshold register			,           Address offset: 0x20 */
	volatile u32 LTR    ;          /* ADC watchdog low threshold register			,           Address offset: 0x20 */
	volatile u32 SQR1   ;          /* ADC regular sequence register 1				,           Address offset: 0x20 */
	volatile u32 SQR2   ;          /* ADC regular sequence register 2				,           Address offset: 0x20 */
	volatile u32 SQR3   ;          /* ADC regular sequence register 3				,           Address offset: 0x20 */
	volatile u32 JSQR   ;          /* ADC injected sequence register				,           Address offset: 0x20 */
	volatile u32 JDR1   ;          /* ADC injected data register 1					,           Address offset: 0x20 */
	volatile u32 JDR2   ;          /* ADC injected data register 2					,           Address offset: 0x20 */
	volatile u32 JDR3   ;          /* ADC injected data register 3					,           Address offset: 0x20 */
	volatile u32 JDR4   ;          /* ADC injected data register 4					,           Address offset: 0x20 */
	volatile u32 DR     ;          /*ADC regular data register						,           Address offset: 0x20 */

}ADC_t;

/***********************************************************************************
*     --> Pointer To STRUCT From SPI_t
************************************************************************************/
#define 	MADC_1 		((ADC_t*)(ADC1_BASE_ADDRESS))
#define 	MADC_2 		((ADC_t*)(ADC2_BASE_ADDRESS))
#define 	MADC_3 		((ADC_t*)(ADC3_BASE_ADDRESS))


#endif /* ADC_PRIVATE_H_ */
