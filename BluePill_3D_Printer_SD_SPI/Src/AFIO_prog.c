/*====================================================================================
===========================   - AFIO                      ============================
===========================   - AFIO_prog.c               ============================
===========================   - Created: 2/3/2023	      ============================
===========================   - Author: Hussein Mohamed   ============================
===========================   - Version : _1_		      ============================
===========================   - Note :
					*-
					*-
========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include <Std_Types.h>
#include "BIT_MATH.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "AFIO_interface.h"
/*======================================*/

/* Copy_u8Line : Pins ( 0 : 15 )
 * Copy_u8PortMap : Ports ( A : C ) */
void MAFIO_voidSetEXTIConfiguration( u8 Copy_u8Line, PortMap_t Copy_PortMap )
{
	u8 L_u8Index = 0;
	if( Copy_u8Line <= 3 )
	{
		L_u8Index = 0;
		MAFIO->EXTICR[L_u8Index] = ( Copy_PortMap << ( Copy_u8Line * 4 ) );
	}
	else if( Copy_u8Line <= 7 )
	{
		L_u8Index = 1;
		Copy_u8Line = Copy_u8Line - 4;
		MAFIO->EXTICR[L_u8Index] = ( Copy_PortMap << ( Copy_u8Line * 4 ) );
	}
	else if( Copy_u8Line <= 11 )
	{
		L_u8Index = 2;
		Copy_u8Line = Copy_u8Line - 8;
		MAFIO->EXTICR[L_u8Index] = ( Copy_PortMap << ( Copy_u8Line * 4 ) );
	}
	else if( Copy_u8Line <= 15 )
	{
		Copy_u8Line = Copy_u8Line - 12;
		MAFIO->EXTICR[L_u8Index] = ( Copy_PortMap << ( Copy_u8Line * 4 ) );
		L_u8Index = 3;
	}
}
