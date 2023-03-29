/*========================================================================================
===========================   - ADC                   	  =============================
===========================   - ADC_config.h		      =============================
===========================   - Created: 13/3/2023	      =============================
===========================   - Author: Hussein Mohamed   =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
========================================================================================*/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ENABLE								0x1
#define DISABLE								0x0
/*=============== ADC_ON/OFF ===============*/
#define ADC_ENABLE							ENABLE          	/* Options : ENABLE , DISABLE */

/*============= ADC_CONVERSION =============*/
#define SINGLE_CONVERSION					DISABLE
#define CONT_CONVERSION						ENABLE
#define ADC_CONVERSION					    CONT_CONVERSION 	/* Options : SINGLE_CONVERSION , CONT_CONVERSION */

/*============= ADC_INTERRUPT ==============*/
#define ADC_END_CONVERSION_INTERRUPT		DISABLE				/* Options : ENABLE , DISABLE */

/*============ ADC_CALIBRATION =============*/
#define CALIBRATION_COMPLETED				DISABLE
#define CALIBRATION_ENABLE					ENABLE
#define ADC_CALIBRATION						CALIBRATION_ENABLE 	/* Options : CALIBRATION_COMPLETED , CALIBRATION_ENABLE */

/*============= ADC_ALIGNMENT ==============*/
#define RIGHT_ALIGNMENT						DISABLE
#define LEFT_ALIGNMENT 						ENABLE
#define ADC_DATA_ALIGNMENT					RIGHT_ALIGNMENT 	/* Options : RIGHT_ALIGNMENT , LEFT_ALIGNMENT */

/*============ ADC_SAMPLE_TIME =============*/
#define _1_5_CYCLES							0U
#define _7_5_CYCLES							1U
#define _13_5_CYCLES						2U
#define _28_5_CYCLES						3U
#define _41_5_CYCLES						4U
#define _55_5_CYCLES						5U
#define _71_5_CYCLES						6U
#define _293_5_CYCLES						7U
#define ADC_PROGRAMMABLE_SAMPLE_TIME		_1_5_CYCLES			/* Options : _1_5_CYCLES , _7_5_CYCLES,
																			 _13_5_CYCLES, _28_5_CYCLES,
																			 _41_5_CYCLES, _55_5_CYCLES,
																			 _71_5_CYCLES, _293_5_CYCLES
																*/

/*====== ADC_NUMBERS_OF_CONVERSIONS =======*/
#define ONE_CONV							0b0000
#define TWO_CONV							0b0001
#define THREE_CONV							0b0010
#define FOUR_CONV							0b0011
#define FIVE_CONV							0b0100
#define SIX_CONV							0b0101
#define SEVEN_CONV							0b0110
#define EIGHT_CONV							0b0111
#define NINE_CONV							0b1000
#define TEN_CONV							0b1001
#define ELEVEN_CONV							0b1010
#define TWELVE_CONV							0b1011
#define THIRTEEN_CONV						0b1100
#define FOURTEEN_CONV						0b1101
#define FIFTEEN_CONV						0b1110
#define SIXTEEN_CONV						0b1111

#define ADC_NUMBER_CONVERSIONS				ONE_CONV			/* Options : ONE_CONV      , TWO_CONV      , THREE_CONV   ,
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 FOUR_CONV     , FIVE_CONV     , SIX_CONV     ,
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 SEVEN_CONV    , EIGHT_CONV    , NINE_CONV    ,
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 TEN_CONV      , ELEVEN_CONV   , TWELVE_CONV  ,
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 THIRTEEN_CONV , FOURTEEN_CONV , FIFTEEN_CONV ,
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 SIXTEEN_CONV */

#endif /* ADC_CONFIG_H_ */
