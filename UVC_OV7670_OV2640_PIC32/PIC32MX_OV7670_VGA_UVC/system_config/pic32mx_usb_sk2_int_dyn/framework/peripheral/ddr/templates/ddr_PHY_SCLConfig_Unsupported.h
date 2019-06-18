/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_PHY_SCLConfig_Unsupported.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : PHY_SCLConfig
    and its Variant : Unsupported
    For following APIs :
        PLIB_DDR_PHY_SCLTestBurstModeSet
        PLIB_DDR_PHY_DDRTypeSet
        PLIB_DDR_PHY_ReadCASLatencySet
        PLIB_DDR_PHY_WriteCASLatencySet
        PLIB_DDR_PHY_OdtCSEnable
        PLIB_DDR_PHY_OdtCSDisable
        PLIB_DDR_PHY_SCLDelay
        PLIB_DDR_PHY_SCLEnable
        PLIB_DDR_PHY_SCLDDRClkDelaySet
        PLIB_DDR_PHY_SCLCapClkDelaySet
        PLIB_DDR_ExistsPHY_SCLConfig

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _DDR_PHY_SCLCONFIG_UNSUPPORTED_H
#define _DDR_PHY_SCLCONFIG_UNSUPPORTED_H

//******************************************************************************
/* Function :  DDR_PHY_SCLTestBurstModeSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_SCLTestBurstModeSet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_SCLTestBurstModeSet function.
*/

PLIB_TEMPLATE void DDR_PHY_SCLTestBurstModeSet_Unsupported( DDR_MODULE_ID index , DDR_PHY_SCL_BURST_MODE brstMode )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_SCLTestBurstModeSet");
}


//******************************************************************************
/* Function :  DDR_PHY_DDRTypeSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_DDRTypeSet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_DDRTypeSet function.
*/

PLIB_TEMPLATE void DDR_PHY_DDRTypeSet_Unsupported( DDR_MODULE_ID index , DDR_PHY_DDR_TYPE ddrType )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_DDRTypeSet");
}


//******************************************************************************
/* Function :  DDR_PHY_ReadCASLatencySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_ReadCASLatencySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_ReadCASLatencySet function.
*/

PLIB_TEMPLATE void DDR_PHY_ReadCASLatencySet_Unsupported( DDR_MODULE_ID index , uint8_t rLat )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_ReadCASLatencySet");
}


//******************************************************************************
/* Function :  DDR_PHY_WriteCASLatencySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_WriteCASLatencySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_WriteCASLatencySet function.
*/

PLIB_TEMPLATE void DDR_PHY_WriteCASLatencySet_Unsupported( DDR_MODULE_ID index , uint8_t wLat )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_WriteCASLatencySet");
}


//******************************************************************************
/* Function :  DDR_PHY_OdtCSEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_OdtCSEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_OdtCSEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_OdtCSEnable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_OdtCSEnable");
}


//******************************************************************************
/* Function :  DDR_PHY_OdtCSDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_OdtCSDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_OdtCSDisable function.
*/

PLIB_TEMPLATE void DDR_PHY_OdtCSDisable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_OdtCSDisable");
}


//******************************************************************************
/* Function :  DDR_PHY_SCLDelay_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_SCLDelay 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_SCLDelay function.
*/

PLIB_TEMPLATE void DDR_PHY_SCLDelay_Unsupported( DDR_MODULE_ID index , DDR_PHY_SCL_DELAY sclDly )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_SCLDelay");
}


//******************************************************************************
/* Function :  DDR_PHY_SCLEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_SCLEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_SCLEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_SCLEnable_Unsupported( DDR_MODULE_ID index , uint8_t cs )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_SCLEnable");
}


//******************************************************************************
/* Function :  DDR_PHY_SCLDDRClkDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_SCLDDRClkDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_SCLDDRClkDelaySet function.
*/

PLIB_TEMPLATE void DDR_PHY_SCLDDRClkDelaySet_Unsupported( DDR_MODULE_ID index , uint8_t ddrDly )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_SCLDDRClkDelaySet");
}


//******************************************************************************
/* Function :  DDR_PHY_SCLCapClkDelaySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_SCLCapClkDelaySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_SCLCapClkDelaySet function.
*/

PLIB_TEMPLATE void DDR_PHY_SCLCapClkDelaySet_Unsupported( DDR_MODULE_ID index , uint8_t capDly )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_SCLCapClkDelaySet");
}


//******************************************************************************
/* Function :  DDR_ExistsPHY_SCLConfig_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_ExistsPHY_SCLConfig

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_ExistsPHY_SCLConfig function.
*/

PLIB_TEMPLATE bool DDR_ExistsPHY_SCLConfig_Unsupported( DDR_MODULE_ID index )
{
    return false;
}


#endif /*_DDR_PHY_SCLCONFIG_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

