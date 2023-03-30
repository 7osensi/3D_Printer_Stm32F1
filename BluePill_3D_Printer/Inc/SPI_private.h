/*========================================================================================
===========================   - SPI                       =============================
===========================   - SPI_private.h             =============================
===========================   - Created: 3/3/2023	      =============================
===========================   - Author: Hussein Mohamed   =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
========================================================================================*/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/*********************************** INCLUDE LIB ***********************************/
#include <Std_Types.h>
/***********************************************************************************
	-----> Macros
			*  Base_Address SPI
************************************************************************************/
#define _SPI_1_BASE_ADDRESS          0x40013000 /* APB2 */
#define _SPI_2_BASE_ADDRESS          0x40003800 /* APB1 */
#define _SPI_3_BASE_ADDRESS          0x40003C00 /* APB1 */

/***********************************************************************************
----->	Struct
		*  Register Map :SPI
************************************************************************************/

typedef struct
{
	volatile u32 CR1     ;        	/* SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
	volatile u32 CR2     ;          /* SPI control register 2,                             Address offset: 0x04 */
	volatile u32 SR      ;          /* SPI status register,                                Address offset: 0x08 */
	volatile u32 DR      ;          /* SPI data register,                                  Address offset: 0x0C */
	volatile u32 CRCPR   ;          /* SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
	volatile u32 RXCRCR  ;          /* SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
	volatile u32 TXCRCR  ;          /* SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
	volatile u32 I2SCFGR ;          /* SPI_I2S configuration register,                     Address offset: 0x1C */
	volatile u32 I2SPR   ;          /* SPI_I2S prescaler register,                         Address offset: 0x20 */
}SPI_t;
/***********************************************************************************
*     --> Pointer To STRUCT From SPI_t
************************************************************************************/
#define MSPI_1          ((SPI_t*)(_SPI_1_BASE_ADDRESS))
#define MSPI_2          ((SPI_t*)(_SPI_2_BASE_ADDRESS))
#define MSPI_3          ((SPI_t*)(_SPI_3_BASE_ADDRESS))

/***********************************************************************************
----->	#define
		*  CR1 Register Bits
************************************************************************************/
#define CPHA					0
#define CPOL					1
#define MSTR					2
#define BR0						3
#define BR1						4
#define BR2						5
#define SPE						6
#define LSBFIRST				7
#define SSI						8
#define SSM						9
#define RXONLY					10
#define DFF						11
#define CRCNEXT					12
#define CRCEN					13
#define BIDIOE					14
#define BIDIMODE				15

/***********************************************************************************
----->	#define
		*  CR2 Register Bits
************************************************************************************/
#define RXDMAEN					0
#define TXDMAEN					1
#define SSOE					2
#define RESERVED0				3
#define RESERVED1				4
#define ERRIE					5
#define RXNEIE					6
#define TXEIE					7

/***********************************************************************************
----->	#define
		*  SR Register Bits
************************************************************************************/
#define RXNE					0
#define TXE						1
#define CHSIDE					2
#define UDR						3
#define CRCERR					4
#define MODF					5
#define OVR						6
#define BSY						7

#endif /* SPI_PRIVATE_H_ */
