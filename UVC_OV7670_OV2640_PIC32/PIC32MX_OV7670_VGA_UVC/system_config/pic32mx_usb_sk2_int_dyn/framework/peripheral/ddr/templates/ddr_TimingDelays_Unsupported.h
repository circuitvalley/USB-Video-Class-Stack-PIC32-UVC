/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_TimingDelays_Unsupported.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : TimingDelays
    and its Variant : Unsupported
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

#ifndef _DDR_TIMINGDELAYS_UNSUPPORTED_H
#define _DDR_TIMINGDELAYS_UNSUPPORTED_H

//******************************************************************************
/* Function :  DDR_ReadWriteDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_ReadWriteDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_ReadWriteDelaySet function.
*/

PLIB_TEMPLATE void DDR_ReadWriteDelaySet_Unsupported( DDR_MODULE_ID index , uint8_t bLen , uint8_t wLat , uint8_t rLat )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_ReadWriteDelaySet");
}


//******************************************************************************
/* Function :  DDR_WriteReadDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_WriteReadDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_WriteReadDelaySet function.
*/

PLIB_TEMPLATE void DDR_WriteReadDelaySet_Unsupported( DDR_MODULE_ID index , uint32_t tWTR , uint8_t bLen , uint8_t wLat , uint32_t ctrlClkPer )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_WriteReadDelaySet");
}


//******************************************************************************
/* Function :  DDR_ReadReadDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_ReadReadDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_ReadReadDelaySet function.
*/

PLIB_TEMPLATE void DDR_ReadReadDelaySet_Unsupported( DDR_MODULE_ID index , uint8_t bLen )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_ReadReadDelaySet");
}


//******************************************************************************
/* Function :  DDR_WriteWriteDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_WriteWriteDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_WriteWriteDelaySet function.
*/

PLIB_TEMPLATE void DDR_WriteWriteDelaySet_Unsupported( DDR_MODULE_ID index , uint8_t bLen )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_WriteWriteDelaySet");
}


//******************************************************************************
/* Function :  DDR_SelfRefreshDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_SelfRefreshDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_SelfRefreshDelaySet function.
*/

PLIB_TEMPLATE void DDR_SelfRefreshDelaySet_Unsupported( DDR_MODULE_ID index , uint32_t slfRefDly , uint32_t tCKE , uint32_t tDLLK )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_SelfRefreshDelaySet");
}


//******************************************************************************
/* Function :  DDR_PowerDownDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PowerDownDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PowerDownDelaySet function.
*/

PLIB_TEMPLATE void DDR_PowerDownDelaySet_Unsupported( DDR_MODULE_ID index , uint32_t pwrDnDly , uint32_t tCKE , uint32_t tXP )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PowerDownDelaySet");
}


//******************************************************************************
/* Function :  DDR_PrechargAllBanksSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PrechargAllBanksSet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PrechargAllBanksSet function.
*/

PLIB_TEMPLATE void DDR_PrechargAllBanksSet_Unsupported( DDR_MODULE_ID index , uint32_t tRP , uint32_t ctrlClkPer )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PrechargAllBanksSet");
}


//******************************************************************************
/* Function :  DDR_ReadToPrechargeDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_ReadToPrechargeDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_ReadToPrechargeDelaySet function.
*/

PLIB_TEMPLATE void DDR_ReadToPrechargeDelaySet_Unsupported( DDR_MODULE_ID index , uint32_t tRTP , uint8_t bLen , uint32_t ctrlClkPer )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_ReadToPrechargeDelaySet");
}


//******************************************************************************
/* Function :  DDR_WriteToPrechargeDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_WriteToPrechargeDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_WriteToPrechargeDelaySet function.
*/

PLIB_TEMPLATE void DDR_WriteToPrechargeDelaySet_Unsupported( DDR_MODULE_ID index , uint32_t tWR , uint8_t bLen , uint8_t wLat , uint32_t ctrlClkPer )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_WriteToPrechargeDelaySet");
}


//******************************************************************************
/* Function :  DDR_PrechargeToRASDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PrechargeToRASDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PrechargeToRASDelaySet function.
*/

PLIB_TEMPLATE void DDR_PrechargeToRASDelaySet_Unsupported( DDR_MODULE_ID index , uint32_t tRP , uint32_t ctrlClkPer )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PrechargeToRASDelaySet");
}


//******************************************************************************
/* Function :  DDR_RASToPrechargeDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_RASToPrechargeDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_RASToPrechargeDelaySet function.
*/

PLIB_TEMPLATE void DDR_RASToPrechargeDelaySet_Unsupported( DDR_MODULE_ID index , uint32_t tRAS , uint32_t ctrlClkPer )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_RASToPrechargeDelaySet");
}


//******************************************************************************
/* Function :  DDR_RASToRASBankDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_RASToRASBankDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_RASToRASBankDelaySet function.
*/

PLIB_TEMPLATE void DDR_RASToRASBankDelaySet_Unsupported( DDR_MODULE_ID index , uint32_t tRC , uint32_t ctrlClkPer )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_RASToRASBankDelaySet");
}


//******************************************************************************
/* Function :  DDR_RASToRASDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_RASToRASDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_RASToRASDelaySet function.
*/

PLIB_TEMPLATE void DDR_RASToRASDelaySet_Unsupported( DDR_MODULE_ID index , uint32_t tRRD , uint32_t ctrlClkPer )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_RASToRASDelaySet");
}


//******************************************************************************
/* Function :  DDR_RASToCASDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_RASToCASDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_RASToCASDelaySet function.
*/

PLIB_TEMPLATE void DDR_RASToCASDelaySet_Unsupported( DDR_MODULE_ID index , uint32_t tRCD , uint32_t ctrlClkPer )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_RASToCASDelaySet");
}


//******************************************************************************
/* Function :  DDR_DataDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_DataDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_DataDelaySet function.
*/

PLIB_TEMPLATE void DDR_DataDelaySet_Unsupported( DDR_MODULE_ID index , uint8_t rLat , uint8_t wLat )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_DataDelaySet");
}


//******************************************************************************
/* Function :  DDR_TfawDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_TfawDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_TfawDelaySet function.
*/

PLIB_TEMPLATE void DDR_TfawDelaySet_Unsupported( DDR_MODULE_ID index , uint8_t tFaw , uint32_t ctrlClkPer )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_TfawDelaySet");
}


//******************************************************************************
/* Function :  DDR_ExistsTimingDelays_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_ExistsTimingDelays

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_ExistsTimingDelays function.
*/

PLIB_TEMPLATE bool DDR_ExistsTimingDelays_Unsupported( DDR_MODULE_ID index )
{
    return false;
}


#endif /*_DDR_TIMINGDELAYS_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

