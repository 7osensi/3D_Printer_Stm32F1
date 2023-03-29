/*========================================================================================
===========================   - SPI                       =============================
===========================   - SPI_config.h              =============================
===========================   - Created: 3/3/2023	      =============================
===========================   - Author: Hussein Mohamed   =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
========================================================================================*/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#include "GPIO_interface.h"

#define ENABLE																1U
#define DISABLE																0U

#define SPI1_PORT															_GPIOA_PORT
#define SPI1_MOSI															GPIO_PIN_7
#define SPI1_MISO															GPIO_PIN_6
#define SPI1_SCK														    GPIO_PIN_5
#define SPI1_SS																GPIO_PIN_0

/* SPI1 Status */
#define SPI1_ENABLE															1U
#define SPI1_DISABLE														0U
/* Options : SPI1_ENABLE , SPI1_DISABLE */
#define SPI1_STATUS															SPI1_ENABLE

/* Master or Slave */
#define SPI1_MASTER_MODE													1U
#define SPI1_SLAVE_MODE														0U
/* Options : SPI1_MASTER_MODE , SPI1_SLAVE_MODE */
#define SPI1_MODE															SPI1_MASTER_MODE

/* Clock Phase */
#define SPI1_SAMPLE_LEADING_EDGE											0U
#define SPI1_SAMPLE_TRAILLING_EDGE											1U
/* Options : SPI1_SAMPLE_LEADING_EDGE , SPI1_SAMPLE_TRAILLING_EDGE */
#define SPI1_CLOCK_PHASE													SPI1_SAMPLE_LEADING_EDGE

/* Clock Polarity */
#define SPI1_CLK_IDLE_0														0U
#define SPI1_CLK_IDLE_1														1U

#define SPI1_CLOCK_POLARITY													SPI1_CLK_IDLE_0

/* Baud Rate */
#define SPI1_FPCLK_2														0U
#define SPI1_FPCLK_4														1U
#define SPI1_FPCLK_8														2U
#define SPI1_FPCLK_16														3U
#define SPI1_FPCLK_32														4U
#define SPI1_FPCLK_64														5U
#define SPI1_FPCLK_128														6U
#define SPI1_FPCLK_256														7U

#define SPI1_BAUD_RATE														SPI1_FPCLK_2

/* Frame Format */
#define	SPI1_MSB_FIRST														0U
#define	SPI1_LSB_FIRST														1U
/*  Options : SPI1_MSB_FIRST , SPI1_LSB_FIRST */
#define	SPI1_FRAME_FORMAT													SPI1_MSB_FIRST

/* Data Frame Format */
#define	SPI1_8BIT															0U
#define	SPI1_16BIT															1U
/* Options : SPI1_8BIT , SPI1_16BIT */
#define	SPI1_DATA_FRAME_FORMAT												SPI1_8BIT

/* Software Slave Management
 * Options : ENABLE , DISABLE */
#define	SPI1_SOFTWARE_SELECT_MANAGEMENT 									DISABLE

/* Internal Slave Select */
#define SPI_SSI_GROUND														0U
#define SPI_SSI_VCC															1U
/* Options : SPI_SSI_GROUND , SPI_SSI_VCC */
#define SPI1_SSI_MODE														SPI_SSI_GROUND

/* Interrupt Status */
#define SPI_INT_DISABLE														0U
#define SPI_TXE_INT_ENABLE													1U
#define SPI_RXE_INT_ENABLE													1U
/* Options : SPI_INT_DISABLE , SPI_TXE_INT_ENABLE , SPI_RXE_INT_ENABLE */
#define SPI1_INT_STATUS														SPI_INT_DISABLE

#endif /* SPI_CONFIG_H_ */
