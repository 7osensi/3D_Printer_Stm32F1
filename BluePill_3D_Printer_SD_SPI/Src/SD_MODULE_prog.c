/*========================================================================================
===========================   - SD_MODULE                 =============================
===========================   - SD_MODULE_prog.h          =============================
===========================   - Created: 3/3/2023	      =============================
===========================   - Author: Hussein Mohamed   =============================
===========================   - Version : _1_		      =============================
===========================   - Note :
					*-
					*-
========================================================================================*/

/*===========  INCLUDE LIB  ============*/
#include "Delay_interface.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
#include "SD_MODULE_interface.h"
/*======================================*/

/* static */
static void CS_Enable(void)
{
	/* Reset CS Pin to Activate */
	MGPIO_vWriteData(SD_PORT, SD_CS_PIN, LOW);
}
/* static */
static void CS_Disable(void)
{
	/* Set CS Pin to Deactivate */
	MGPIO_vWriteData(SD_PORT, SD_CS_PIN, HIGH);
}

/* static unit testing : done  */
static void H_SD_vPowerupSeq(void)
{
	/* Make Sure the Card is Not Selected */
	CS_Disable();
	/* Delay until SD Card is Powered Up */
	Delay_vMsIn16MHz(1);
	CS_Enable();

	/* Send 80 Clock Cycles to Synchronize */
	for( u8 Local_u8Iterator = 0; Local_u8Iterator < 10 ; Local_u8Iterator++ )
	{
		M_SPI1_u8Transceive( 0xFF );
	}
	/* Deselect SD card */
	CS_Disable();
	M_SPI1_u8Transceive(0xFF);
}

static void H_SD_vSendCommand(u8 Copy_u8CommandIndex, u32 Copy_u32Argument, u8 Copy_u8CRC)
{
    /* Transmit Command to SD Card
     * Start Bit : '0' + Transmission Bit : '1' + Command Index */
	M_SPI1_u8Transceive(Copy_u8CommandIndex | 0x40);

    /* Transmit argument */
	M_SPI1_u8Transceive((u8)(Copy_u32Argument >> 24));
	M_SPI1_u8Transceive((u8)(Copy_u32Argument >> 16));
	M_SPI1_u8Transceive((u8)(Copy_u32Argument >> 8 ));
	M_SPI1_u8Transceive((u8)(Copy_u32Argument      ));

    /* Transmit CRC
     * CRC : 7 Bits & 1 End Bit */
	M_SPI1_u8Transceive(Copy_u8CRC | 0x01);
}

static u8 H_SD_u8ReadResponse1(void)
{
    u8 i = 0;
    u8 L_u8Response1;

    /* Keep Polling Until the Actual Data is Received */
    while((L_u8Response1 = M_SPI1_u8Transceive( 0xFF )) == 0xFF)
    {
        i++;
        /* If No Data is Received for 8 Bytes, Break */
        if( i > 8 )
        {
        	break;
        }
        else
        {
        	/* No Action */
        }
    }
    return L_u8Response1;
}

/* CMD0 : GO idle state */
static u8 H_SD_u8GoIdleState(void)
{
    /* Assert Chip Select */
	M_SPI1_u8Transceive(0xFF);
    CS_Enable();
    M_SPI1_u8Transceive(0xFF);

    /* Send CMD0 */
    H_SD_vSendCommand(CMD0_INDEX, CMD0_ARG, CMD0_CRC);

    /* Read Response */
    u8 L_u8Response1 = H_SD_u8ReadResponse1();

    /* De-assert Chip Select */
    M_SPI1_u8Transceive(0xFF);
    CS_Disable();
    M_SPI1_u8Transceive(0xFF);

    return L_u8Response1;
}

static void H_SD_vReadResponse3_7(u8 *Copy_u8Res)
{
    /* Read Response 1 in R7 */
	Copy_u8Res[0] = H_SD_u8ReadResponse1();

    /* If There is an Error reading R1, Return */
    if(Copy_u8Res[0] > 1)
    {
    	return;
   	}
    else
    {
    	/* No Action */
    }
    /* Read Remaining Bytes */
    Copy_u8Res[1] = M_SPI1_u8Transceive(0xFF);
    Copy_u8Res[2] = M_SPI1_u8Transceive(0xFF);
    Copy_u8Res[3] = M_SPI1_u8Transceive(0xFF);
    Copy_u8Res[4] = M_SPI1_u8Transceive(0xFF);
}

/* send command 8 */
static void H_SD_vSendIfCond(u8 *Copy_u8Res)
{
	/* Assert Chip Select */
	M_SPI1_u8Transceive(0xFF);
    CS_Enable();
    M_SPI1_u8Transceive(0xFF);

    /* Send CMD8 */
    H_SD_vSendCommand(CMD8_INDEX, CMD8_ARG, CMD8_CRC);

    /* Read Response */
    H_SD_vReadResponse3_7(Copy_u8Res);

    /* De-assert Chip Select */
    M_SPI1_u8Transceive(0xFF);
    CS_Disable();
    M_SPI1_u8Transceive(0xFF);
}

static void H_SD_vReadOCR(u8 *Copy_u8Res)
{
	/* Assert Chip Select */
	M_SPI1_u8Transceive(0xFF);
    CS_Enable();
    M_SPI1_u8Transceive(0xFF);

    /* Send CMD58 */
    H_SD_vSendCommand(CMD58_INDEX, CMD58_ARG, CMD58_CRC);

    /* Read Response */
    H_SD_vReadResponse3_7(Copy_u8Res);

    /* De-assert Chip Select */
    M_SPI1_u8Transceive(0xFF);
    CS_Disable();
    M_SPI1_u8Transceive(0xFF);
}

static u8 H_SD_u8SendApp()
{
	/* Assert Chip Select */
	M_SPI1_u8Transceive(0xFF);
	CS_Enable();
    M_SPI1_u8Transceive(0xFF);

    /* Send CMD55 */
    H_SD_vSendCommand(CMD55_INDEX, CMD55_ARG, CMD55_CRC);

    /* Read Response */
    u8 L_u8Response1 = H_SD_u8ReadResponse1();

    // deassert chip select
    M_SPI1_u8Transceive(0xFF);
    CS_Disable();
    M_SPI1_u8Transceive(0xFF);

    return L_u8Response1;
}

static u8 H_SD_u8SendOpCond()
{
	/* Assert Chip Select */
	M_SPI1_u8Transceive(0xFF);
	CS_Enable();
    M_SPI1_u8Transceive(0xFF);

    /* Send CMD41 */
    H_SD_vSendCommand(ACMD41_INDEX, ACMD41_ARG, ACMD41_CRC);

    /* Read Response */
    u8 L_u8Response1 = H_SD_u8ReadResponse1();

    // deassert chip select
    M_SPI1_u8Transceive(0xFF);
    CS_Disable();
    M_SPI1_u8Transceive(0xFF);

    return L_u8Response1;
}

extern u8 H_SD_u8Init()
{
    u8 L_u8Res[5];
    u8 L_u8CmdAttempts = 0;

    H_SD_vPowerupSeq();

    /* IDLE State */
    while((L_u8Res[0] = H_SD_u8GoIdleState()) != 0x01)
    {
    	L_u8CmdAttempts++;
        if(L_u8CmdAttempts > 10)
        {
        	return SD_ERROR;
        }
        else
        {
        	/* No Action */
        }
    }

    /* Send Interface Condition */
    H_SD_vSendIfCond(L_u8Res);
    if(L_u8Res[0] != 0x01)
    {
        return SD_ERROR;
    }
    else
    {
    	/* No Action */
    }

    /* Check Echo Pattern */
    if(L_u8Res[4] != 0xAA)
    {
        return SD_ERROR;
    }
    else
    {
    	/* No Action */
    }

    /* Attempts to Initialize Card */
    L_u8CmdAttempts = 0;
    do
    {
        if(L_u8CmdAttempts > 100)
        {
        	return SD_ERROR;
        }
        else
        {
        	/* No Action */
        }

        /* Send App Command */
        L_u8Res[0] = H_SD_u8SendApp();

        /* No Error */
        if(L_u8Res[0] < 2)
        {
        	L_u8Res[0] = H_SD_u8SendOpCond();
        }
        else
        {
        	/* No Action */
        }

        /* Wait */
        Delay_vMsIn16MHz(5);
        L_u8CmdAttempts++;
    }
    while(L_u8Res[0] != SD_READY);

    /* Read OCR */
    H_SD_vReadOCR(L_u8Res);

    /* Check if Card is Ready */
    if(!(L_u8Res[1] & 0x80))
    {
    	return SD_ERROR;
    }
    else
    {
    	/* No Action */
    }
    return SD_SUCCESS;
}

u8 H_SD_u8ReadSingleBlock(u32 Copy_u32Address, u8 *Copy_u8Buffer, u8 *Copy_u8Token)
{
    u8 L_u8Response1;
    u8 L_u8Read;
    u16 L_u16ReadAttempts;

    /* Set Token to None */
    *Copy_u8Token = 0xFF;

    /* Assert Chip Select */
    M_SPI1_u8Transceive(0xFF);
    CS_Enable();
    M_SPI1_u8Transceive(0xFF);

    /* Send CMD17 */
    H_SD_vSendCommand(CMD17_INDEX, Copy_u32Address, CMD17_CRC);

    /* Read R1 */
    L_u8Response1 = H_SD_u8ReadResponse1();

    /* If Response is Received from the Card */
    if(L_u8Response1 != 0xFF)
    {
        /* Wait for a Response Token (Timeout = 100ms) */
    	L_u16ReadAttempts = 0;
        while(++L_u16ReadAttempts != SD_MAX_READ_ATTEMPTS)
        {
            if((L_u8Read = M_SPI1_u8Transceive(0xFF)) != 0xFF)
            {
            	break;
            }
            else
            {
            	/* Do Nothing */
            }
        }

        /* If Response Token is 0xFE */
        if(L_u8Read == 0xFE)
        {
            /* Read 512 Byte Block */
            for(u16 i = 0; i < 512; i++)
            {
            	*Copy_u8Buffer++ = M_SPI1_u8Transceive(0xFF);
            }

            /* Read 16-bit CRC */
            M_SPI1_u8Transceive(0xFF);
            M_SPI1_u8Transceive(0xFF);
        }
        /* Set Token to Card Response */
        *Copy_u8Token = L_u8Read;
    }
    else
    {
    	/* No Action */
    }
    /* De-assert Chip Select */
    M_SPI1_u8Transceive(0xFF);
    CS_Disable();
    M_SPI1_u8Transceive(0xFF);

    return L_u8Response1;
}
