/*========================================================================================
===========================   - SPI                       =============================
===========================   - SPI_prog.c           =============================
===========================   - Created: 3/3/2023	      =============================
===========================   - Author: Hussein Mohamed   =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
========================================================================================*/

/*=============== MCAL Includes ===============*/
#include "SPI_interface.h"
/*=============================================*/

/*============= Global Variables ==============*/
void (*M_SPI1_CallBack) (void);/* Pointer to Function */
/*=============================================*/
/************************************** START_ FUNCTION   **************************************/
void M_SPI1_vInit(void)
{
#if SPI1_STATUS == SPI1_ENABLE

	/*==================== SCK/PA5  ====================*/
	MGPIO_vSetPinMode(SPI1_PORT, SPI1_SCK, _MODE_OUTPUT, _MODE_GP_OUT_ALT_PUSH_PULL);

	/*=================== MISO/PA6  ====================*/
	MGPIO_vSetPinMode(SPI1_PORT, SPI1_MISO, _MODE_INPUT, _MODE_FLOATING);

	/*=================== MOSI/PA7  ====================*/
	MGPIO_vSetPinMode(SPI1_PORT, SPI1_MOSI, _MODE_OUTPUT, _MODE_GP_OUT_ALT_PUSH_PULL);

	/*==================== SS/PA4  =====================*/
	MGPIO_vSetPinMode(SPI1_PORT, SPI1_SS, _MODE_OUTPUT , _MODE_GP_OUT_PUSH_PULL);

	/*=========== SPI Mode ( Master, Slave ) ===========*/

	#if SPI1_MODE == SPI1_SLAVE_MODE
	MSPI_1->CR1 &= ~(1U << MSTR);
	#elif SPI1_MODE == SPI1_MASTER_MODE
	MSPI_1->CR1 |= (1U << MSTR);
	#else /* No Action */
	#endif

	/*=========== Software Slave Management ============*/

	#if   SPI1_SOFTWARE_SELECT_MANAGEMENT  == DISABLE
		MSPI_1->CR1 &= ~(1U << SSM);
	#elif MSPI1_SSM_MANAGE  == ENABLE
		MSPI_1->CR1 |= (1U << SSM);

	/*============== Internal Slave Select =============*/

		#if   MSPI_SSI_MODE  ==  SPI_SSI_GROUND
			MSPI_1->CR1 |= (0U << SSI);
		#elif MSPI_SSI_MODE  ==  SPI_SSI_VCC
			MSPI_1->CR1 |= (1U << SSI);
		#else /* No Action */
		#endif
	#else /* No Action */
	#endif

	/*=================== Clock Phase ==================*/

	#if	SPI1_CLOCK_PHASE == SPI1_SAMPLE_LEADING_EDGE
		MSPI_1->CR1 &= ~(1U << CPHA);
	#elif SPI1_CLOCK_PHASE == SPI1_SAMPLE_TRAILLING_EDGE
		MSPI_1->CR1 |= (1U << CPHA);
	#else /* No Action */
	#endif

	/*================= Clock Polarity =================*/

	#if	SPI1_CLOCK_POLARITY == SPI1_CLK_IDLE_0
		MSPI_1->CR1 &= ~(1U << CPOL);
	#elif SPI1_CLOCK_PHASE == SPI1_CLK_IDLE_1
		MSPI_1->CR1 |= (1U << CPOL);
	#else /* No Action */
	#endif

	/*================== Frame Format ==================*/

	#if	SPI1_FRAME_FORMAT == SPI1_MSB_FIRST
		MSPI_1->CR1 &= ~(1U << LSBFIRST);
	#elif SPI1_FRAME_FORMAT == SPI1_LSB_FIRST
		MSPI_1->CR1 |= (1U << LSBFIRST);
	#else /* No Action */
	#endif

	/*================ Data Frame Format ===============*/

	#if SPI1_DATA_FRAME_FORMAT == SPI1_8BIT
		MSPI_1->CR1 &= ~(1U << DFF);
	#elif SPI1_DATA_FRAME_FORMAT == SPI1_16BIT
		MSPI_1->CR1 |= (1U << DFF);
	#else /* No Action */
	#endif

	/*================ Interrupt Status ================*/
	#if   SPI1_INT_STATUS == SPI_INT_DISABLE
		MSPI_1->CR2 = 0U;
	#elif SPI1_INT_STATUS == SPI_TXE_INT_ENABLE
		MSPI_1->CR2 |= (1U << TXEIE);
	#elif SPI1_INT_STATUS == SPI_RXNE_INT_ENABLE
		MSPI_1->CR2 |= (1U << RXNEIE);
	#else /* No Action */
	#endif

	/*=================== BAUD_RATE ====================*/

	#if	SPI1_BAUD_RATE == SPI1_FPCLK_2
		MSPI_1->CR1 &= ~(1U << BR0);
	#elif SPI1_BAUD_RATE == SPI1_FPCLK_4
	MSPI_1->CR1 |= (1U << BR0);
	#elif SPI1_BAUD_RATE == SPI1_FPCLK_8
		MSPI_1->CR1 |= (2U << BR0);
	#elif SPI1_BAUD_RATE == SPI1_FPCLK_16
		MSPI_1->CR1 |= (3U << BR0);
	#elif SPI1_BAUD_RATE == SPI1_FPCLK_32
		MSPI_1->CR1 |= (4U << BR0);
	#elif SPI1_BAUD_RATE == SPI1_FPCLK_64
		MSPI_1->CR1 |= (5U << BR0);
	#elif SPI1_BAUD_RATE == SPI1_FPCLK_128
		MSPI_1->CR1 |= (6U << BR0);
	#elif SPI1_BAUD_RATE == SPI1_FPCLK_256
		MSPI_1->CR1 |= (7U << BR0);
	#else /* No Action */
	#endif

	/*=================== SPI1 Enable ==================*/
	MSPI_1->CR1 |= (1U << SPE);

#elif MSPI1_STATUS == _SPI1_DISABLE
	MSPI1->CR1 &= ~(1U << SPE);
#else /* No Action */
#endif
}
/***************************************  END_ FUNCTION   *************************************/
/*************************************** START_ FUNCTION   ************************************/
extern u8 M_SPI1_u8Transceive(u8 Copy_u8Data)
{
	/************** STEPS TO FOLLOW *****************
	1. Wait for the BSY bit to reset in Status Register
	2. Write Data to the Data Register
	3. Wait for the BSY bit to reset in Status Register
	4. Return Data
	************************************************/
	u8 L_u8Receive = 0U;
	/* Wait BSY Flag */
	while (GET_BIT(MSPI_1->SR, BSY) == 1U);
	/* Write Data */
	MSPI_1->DR = Copy_u8Data;
	/* Wait BSY Flag */
	while (GET_BIT( MSPI_1->SR, BSY) == 1U);
	/* Return data */
	L_u8Receive = (u8)MSPI_1->DR;
	return L_u8Receive;
}
/***************************************  END_ FUNCTION   ***************************************/

extern void M_SPI1_vReceive(u8 *Copy_Pu8Data, u8 Copy_u8Size)
{
	/************** STEPS TO FOLLOW *****************
	1. Wait for the BSY bit to reset in Status Register
	2. Send Dummy data before reading the DATA
	3. Wait for the RXNE bit to Set in the status Register
	4. Read data from Data Register
	************************************************/
	while (Copy_u8Size)
	{
		/* Wait BSY Flag
		 * This Will Indicate That SPI is Not Busy */
		while(GET_BIT(MSPI_1->SR, 7) == 1U);
		/* Send Dummy Data To Receive The Data */
		MSPI_1->DR = 0;
		/* Wait for RXNE to set
		 * This Will Indicate That The Rx Buffer is Not Empty */
		while(!(GET_BIT( MSPI_1->SR, 0 ) == 1U));
	    *Copy_Pu8Data++ = (MSPI_1->DR);
	    Copy_u8Size--;
	}
}
/****************************************  END_ FUNCTION   ***************************************/

/*************************************** START_ FUNCTION   ***************************************/
extern void M_SPI1_vSetCallBack(void (*ptr)(void)){

	M_SPI1_CallBack = ptr;
}
/***************************************  END_ FUNCTION   ****************************************/

/*************************************** START_ FUNCTION   ***************************************/
void SPI1_IRQHandler(void){

	M_SPI1_CallBack();
}
/****************************************  END_ FUNCTION *****************************************/
