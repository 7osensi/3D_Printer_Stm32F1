/*========================================================================================
===========================   - ADC                   	  =============================
===========================   - ADC_prog.c		          =============================
===========================   - Created: 12/3/2023	      =============================
===========================   - Author: Hussein Mohamed   =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
========================================================================================*/
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "ADC_interface.h"
/*======================================*/

void Adc1_Init(void)
{

	/* Enable Continuous Conversion >> CONT bit in ADC_CR2 */
#if ADC_CONVERSION == CONT_CONVERSION
	MADC_1->CR2 |= (1 << 1);
#elif ADC_CONVERSION == SINGLE_CONVERSION
	MADC_1->CR2 &= ~(1 << 1);
#else /* No Action */
#endif
	/* Enable ADC >> ADON Bit in ADC_CR2 */
#if ADC_ENABLE == ENABLE
	MADC_1->CR2 |= (1 << 0);
#elif ADC_ENABLE == DISABLE
	MADC_1->CR2 &= ~(1 << 0);
#else /* No Action */
#endif
	/* Before starting a calibration,
	 * the ADC must have been in power-on state (ADON bit = ‘1’) for at least two ADC clock cycles.
	 * Enable Calibration >> CAL bit in ADC_CR2
     */
#if ADC_CALIBRATION == CALIBRATION_ENABLE
	MADC_1->CR2 |= (1 << 2);
#elif ADC_CALIBRATION == CALIBRATION_COMPLETED
	MADC_1->CR2 &= ~(1 << 2);
#else /* No Action */
#endif
	/* Wait For Calibration Process To End */
	while(((MADC_1->CR2) & (1 << 2)) != 0){};

	/* Data Alignment >> ALIGN bit in ADC_CR2 */
#if ADC_DATA_ALIGNMENT == LEFT_ALIGNMENT
	MADC_1->CR2 |= (1 << 11);
#elif ADC_DATA_ALIGNMENT == RIGHT_ALIGNMENT
	MADC_1->CR2 &= ~(1 << 11);
#else /* No Action */
#endif

	/* Number of Conversions >> L[3:0] bits in ADC_SQR1 */
#if ADC_NUMBER_CONVERSIONS == ONE_CONV
	MADC_1->SQR1 &= ~(1 << 20);
#elif ADC_NUMBER_CONVERSIONS == TWO_CONV
	MADC_1->SQR1 |= (TWO_CONV << 20);
#elif ADC_NUMBER_CONVERSIONS == THREE_CONV
	MADC_1->SQR1 |= (THREE_CONV << 20);
#elif ADC_NUMBER_CONVERSIONS == FOUR_CONV
	MADC_1->SQR1 |= (FOUR_CONV << 20);
#elif ADC_NUMBER_CONVERSIONS == FIVE_CONV
	MADC_1->SQR1 |= (FIVE_CONV << 20);
#elif ADC_NUMBER_CONVERSIONS == SIX_CONV
	MADC_1->SQR1 |= (SIX_CONV << 20);
#elif ADC_NUMBER_CONVERSIONS == SEVEN_CONV
	MADC_1->SQR1 |= (SEVEN_CONV << 20);
#elif ADC_NUMBER_CONVERSIONS == EIGHT_CONV
	MADC_1->SQR1 |= (EIGHT_CONV << 20);
#elif ADC_NUMBER_CONVERSIONS == NINE_CONV
	MADC_1->SQR1 |= (NINE_CONV << 20);
#elif ADC_NUMBER_CONVERSIONS == TEN_CONV
	MADC_1->SQR1 |= (TEN_CONV << 20);
#elif ADC_NUMBER_CONVERSIONS == ELEVEN_CONV
	MADC_1->SQR1 |= (ELEVEN_CONV << 20);
#elif ADC_NUMBER_CONVERSIONS == TWELVE_CONV
	MADC_1->SQR1 |= (TWELVE_CONV << 20);
#elif ADC_NUMBER_CONVERSIONS == THIRTEEN_CONV
	MADC_1->SQR1 |= (THIRTEEN_CONV << 20);
#elif ADC_NUMBER_CONVERSIONS == FOURTEEN_CONV
	MADC_1->SQR1 |= (FOURTEEN_CONV << 20);
#elif ADC_NUMBER_CONVERSIONS == FIFTEEN_CONV
	MADC_1->SQR1 |= (FIFTEEN_CONV << 20);
#elif ADC_NUMBER_CONVERSIONS == SIXTEEN_CONV
	MADC_1->SQR1 |= (SIXTEEN_CONV << 20);
#else /* No Action */
#endif

	/* Start Conversion >> SWSTART bit in ADC_CR2 */
	MADC_1->CR2 |= (1 << 22);
}

void Adc1_Read(void)
{

}
