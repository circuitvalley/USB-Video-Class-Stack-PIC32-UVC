/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_TimingDelays_Default.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : TimingDelays
    and its Variant : Default
    For following APIs :
        PLIB_DDR_ReadWriteDelaySet
        PLIB_DDR_WriteReadDelaySet
        PLIB_DDR_ReadReadDelaySet
        PLIB_DDR_WriteWriteDelaySet
        PLIB_DDR_SelfRefreshDelaySet
        PLIB_DDR_PowerDownDelaySet
        PLIB_DDR_PrechargAllBanksSet
        PLIB_DDR_ReadToPrechargeDelaySet
        PLIB_DDR_WriteToPrechargeDelaySet
        PLIB_DDR_PrechargeToRASDelaySet
        PLIB_DDR_RASToPrechargeDelaySet
        PLIB_DDR_RASToRASBankDelaySet
        PLIB_DDR_RASToRASDelaySet
        PLIB_DDR_RASToCASDelaySet
        PLIB_DDR_DataDelaySet
        PLIB_DDR_TfawDelaySet
        PLIB_DDR_ExistsTimingDelays

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/

//DOM-IGNORE-END

#ifndef _DDR_TIMINGDELAYS_DEFAULT_H
#define _DDR_TIMINGDELAYS_DEFAULT_H

#ifndef round_up
#define round_up(x,y) (((x) + (y) - 1) / (y))
#endif

//******************************************************************************
/* Function :  DDR_ReadWriteDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_ReadWriteDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_ReadWriteDelaySet function.
*/

PLIB_TEMPLATE void DDR_ReadWriteDelaySet_Default( DDR_MODULE_ID index , uint8_t bLen , uint8_t wLat , uint8_t rLat )
{
	DDRDLYCFG0bits.R2WDLY = bLen + 2u;
	DDRDLYCFG0bits.RMWDLY = rLat - wLat + 3u;
}


//******************************************************************************
/* Function :  DDR_WriteReadDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_WriteReadDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_WriteReadDelaySet function.
*/

PLIB_TEMPLATE void DDR_WriteReadDelaySet_Default( DDR_MODULE_ID index , uint32_t tWTR , uint8_t bLen , uint8_t wLat , uint32_t ctrlClkPer )
{
    uint32_t w2rdly, w2rcsdly;

    w2rdly = round_up(tWTR, ctrlClkPer) + wLat + bLen;
    w2rcsdly = ((w2rdly - 1u) > 3u) ? (w2rdly - 1u) : 3u;

	DDRDLYCFG0bits.W2RDLY = w2rdly & 0x0Fu;
	DDRDLYCFG1bits.W2RDLY4 = ((w2rdly & 0x10u) != 0) ? 1 : 0;

	DDRDLYCFG0bits.W2RCSDLY = w2rcsdly & 0x0Fu;
	DDRDLYCFG1bits.W2RCSDLY4 = ((w2rcsdly & 0x10u) != 0) ? 1 : 0;
}


//******************************************************************************
/* Function :  DDR_ReadReadDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_ReadReadDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_ReadReadDelaySet function.
*/

PLIB_TEMPLATE void DDR_ReadReadDelaySet_Default( DDR_MODULE_ID index , uint8_t bLen )
{
	DDRDLYCFG0bits.R2RDLY = bLen - 1u;
	DDRDLYCFG0bits.R2RCSDLY = bLen;
}


//******************************************************************************
/* Function :  DDR_WriteWriteDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_WriteWriteDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_WriteWriteDelaySet function.
*/

PLIB_TEMPLATE void DDR_WriteWriteDelaySet_Default( DDR_MODULE_ID index , uint8_t bLen )
{
	DDRDLYCFG0bits.W2WDLY = bLen - 1u;
	DDRDLYCFG0bits.W2WCSDLY = bLen - 1u;
}


//******************************************************************************
/* Function :  DDR_SelfRefreshDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_SelfRefreshDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_SelfRefreshDelaySet function.
*/

PLIB_TEMPLATE void DDR_SelfRefreshDelaySet_Default( DDR_MODULE_ID index , uint32_t slfRefDly , uint32_t tCKE , uint32_t tDLLK )
{
	DDRPWRCFGbits.SLFREFDLY =slfRefDly;
	DDRDLYCFG1bits.SLFREFMINDLY = tCKE - 1u;
	DDRDLYCFG1bits.SLFREFEXDLY = (round_up(tDLLK, 2u) - 2u) & 0xFFu;
	DDRDLYCFG1bits.SLFREFEXDLY8 = ((round_up(tDLLK, 2u) & 0x100u) != 0) ? 1u : 0;
}


//******************************************************************************
/* Function :  DDR_PowerDownDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_PowerDownDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_PowerDownDelaySet function.
*/

PLIB_TEMPLATE void DDR_PowerDownDelaySet_Default( DDR_MODULE_ID index , uint32_t pwrDnDly , uint32_t tCKE , uint32_t tXP )
{
	DDRPWRCFGbits.PWRDNDLY = pwrDnDly;
	DDRDLYCFG1bits.PWRDNMINDLY = tCKE - 1;
	DDRDLYCFG1bits.PWRDNEXDLY = (tCKE > tXP ? tCKE : tXP) - 1; 
}


//******************************************************************************
/* Function :  DDR_PrechargAllBanksSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_PrechargAllBanksSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_PrechargAllBanksSet function.
*/

PLIB_TEMPLATE void DDR_PrechargAllBanksSet_Default( DDR_MODULE_ID index , uint32_t tRP , uint32_t ctrlClkPer )
{
	DDRDLYCFG2bits.PCHRGALLDLY = round_up(tRP, ctrlClkPer); 
}


//******************************************************************************
/* Function :  DDR_ReadToPrechargeDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_ReadToPrechargeDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_ReadToPrechargeDelaySet function.
*/

PLIB_TEMPLATE void DDR_ReadToPrechargeDelaySet_Default( DDR_MODULE_ID index , uint32_t tRTP , uint8_t bLen , uint32_t ctrlClkPer )
{
	DDRDLYCFG2bits.R2PCHRGDLY = round_up(tRTP, ctrlClkPer) + bLen - 2; 
}


//******************************************************************************
/* Function :  DDR_WriteToPrechargeDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_WriteToPrechargeDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_WriteToPrechargeDelaySet function.
*/

PLIB_TEMPLATE void DDR_WriteToPrechargeDelaySet_Default( DDR_MODULE_ID index , uint32_t tWR , uint8_t bLen , uint8_t wLat , uint32_t ctrlClkPer )
{
	DDRDLYCFG2bits.W2PCHRGDLY = (round_up(tWR, ctrlClkPer) + wLat + bLen) & 0x0F;
	DDRDLYCFG1bits.W2PCHRGDLY4 = (((round_up(tWR, ctrlClkPer) + wLat + bLen) & 0x10u) != 0) ? 1 : 0;
}


//******************************************************************************
/* Function :  DDR_PrechargeToRASDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_PrechargeToRASDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_PrechargeToRASDelaySet function.
*/

PLIB_TEMPLATE void DDR_PrechargeToRASDelaySet_Default( DDR_MODULE_ID index , uint32_t tRP , uint32_t ctrlClkPer )
{
	DDRDLYCFG2bits.PCHRG2RASDLY = round_up(tRP, ctrlClkPer) - 1; 
}


//******************************************************************************
/* Function :  DDR_RASToPrechargeDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_RASToPrechargeDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_RASToPrechargeDelaySet function.
*/

PLIB_TEMPLATE void DDR_RASToPrechargeDelaySet_Default( DDR_MODULE_ID index , uint32_t tRAS , uint32_t ctrlClkPer )
{
	DDRDLYCFG3bits.RAS2PCHRGDLY = round_up(tRAS, ctrlClkPer) - 1;
}


//******************************************************************************
/* Function :  DDR_RASToRASBankDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_RASToRASBankDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_RASToRASBankDelaySet function.
*/

PLIB_TEMPLATE void DDR_RASToRASBankDelaySet_Default( DDR_MODULE_ID index , uint32_t tRC , uint32_t ctrlClkPer )
{
	DDRDLYCFG3bits.RAS2RASSBNKDLY = round_up(tRC, ctrlClkPer) - 1;
}


//******************************************************************************
/* Function :  DDR_RASToRASDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_RASToRASDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_RASToRASDelaySet function.
*/

PLIB_TEMPLATE void DDR_RASToRASDelaySet_Default( DDR_MODULE_ID index , uint32_t tRRD , uint32_t ctrlClkPer )
{
	DDRDLYCFG2bits.RAS2RASDLY = round_up(tRRD, ctrlClkPer) - 1;
}


//******************************************************************************
/* Function :  DDR_RASToCASDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_RASToCASDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_RASToCASDelaySet function.
*/

PLIB_TEMPLATE void DDR_RASToCASDelaySet_Default( DDR_MODULE_ID index , uint32_t tRCD , uint32_t ctrlClkPer )
{
	DDRDLYCFG2bits.RAS2CASDLY = round_up(tRCD, ctrlClkPer) - 1;
}


//******************************************************************************
/* Function :  DDR_DataDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_DataDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_DataDelaySet function.
*/

PLIB_TEMPLATE void DDR_DataDelaySet_Default( DDR_MODULE_ID index , uint8_t rLat , uint8_t wLat )
{
	DDRDLYCFG2bits.RBENDDLY = rLat + 3u;
	DDRXFERCFGbits.NXTDATRQDLY = 2;
	DDRXFERCFGbits.NXTDATAVDLY = 4;
	DDRDLYCFG1bits.NXTDATAVDLY4 = (((rLat + 5u) & 0x10u) != 0) ? 1 : 0;
	DDRXFERCFGbits.RDATENDLY = 2;/*rLat - 1*/
}


//******************************************************************************
/* Function :  DDR_TfawDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_TfawDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_TfawDelaySet function.
*/

PLIB_TEMPLATE void DDR_TfawDelaySet_Default( DDR_MODULE_ID index , uint32_t tFaw , uint32_t ctrlClkPer )
{
	DDRDLYCFG3bits.FAWTDLY = round_up(tFaw, ctrlClkPer) - 1;
}


//******************************************************************************
/* Function :  DDR_ExistsTimingDelays_Default

  Summary:
    Implements Default variant of PLIB_DDR_ExistsTimingDelays

  Description:
    This template implements the Default variant of the PLIB_DDR_ExistsTimingDelays function.
*/

#define PLIB_DDR_ExistsTimingDelays PLIB_DDR_ExistsTimingDelays
PLIB_TEMPLATE bool DDR_ExistsTimingDelays_Default( DDR_MODULE_ID index )
{
    return true;
}


#endif /*_DDR_TIMINGDELAYS_DEFAULT_H*/

/******************************************************************************
 End of File
*/

