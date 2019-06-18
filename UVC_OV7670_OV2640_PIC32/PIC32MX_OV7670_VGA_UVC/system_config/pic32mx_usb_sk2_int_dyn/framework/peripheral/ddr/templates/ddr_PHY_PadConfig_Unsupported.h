/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_PHY_PadConfig_Unsupported.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : PHY_PadConfig
    and its Variant : Unsupported
    For following APIs :
        PLIB_DDR_PHY_OdtEnable
        PLIB_DDR_PHY_OdtDisable
        PLIB_DDR_PHY_DataDriveStrengthSet
        PLIB_DDR_PHY_AddCtlDriveStrengthSet
        PLIB_DDR_PHY_OdtCal
        PLIB_DDR_PHY_DrvStrgthCal
        PLIB_DDR_PHY_ExtraClockEnable
        PLIB_DDR_PHY_ExtraClockDisable
        PLIB_DDR_PHY_InternalDllEnable
        PLIB_DDR_PHY_ExternalDllEnable
        PLIB_DDR_PHY_PadReceiveEnable
        PLIB_DDR_PHY_PadReceiveDisable
        PLIB_DDR_PHY_PreambleDlySet
        PLIB_DDR_PHY_HalfRateSet
        PLIB_DDR_PHY_WriteCmdDelayEnable
        PLIB_DDR_PHY_WriteCmdDelayDisable
        PLIB_DDR_ExistsPHY_PadConfig

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

#ifndef _DDR_PHY_PADCONFIG_UNSUPPORTED_H
#define _DDR_PHY_PADCONFIG_UNSUPPORTED_H

//******************************************************************************
/* Function :  DDR_PHY_OdtEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_OdtEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_OdtEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_OdtEnable_Unsupported( DDR_MODULE_ID index , DDR_PHY_ODT odtVal )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_OdtEnable");
}


//******************************************************************************
/* Function :  DDR_PHY_OdtDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_OdtDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_OdtDisable function.
*/

PLIB_TEMPLATE void DDR_PHY_OdtDisable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_OdtDisable");
}


//******************************************************************************
/* Function :  DDR_PHY_DataDriveStrengthSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_DataDriveStrengthSet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_DataDriveStrengthSet function.
*/

PLIB_TEMPLATE void DDR_PHY_DataDriveStrengthSet_Unsupported( DDR_MODULE_ID index , DDR_PHY_DRIVE_STRENGTH drvStr )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_DataDriveStrengthSet");
}


//******************************************************************************
/* Function :  DDR_PHY_AddCtlDriveStrengthSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_AddCtlDriveStrengthSet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_AddCtlDriveStrengthSet function.
*/

PLIB_TEMPLATE void DDR_PHY_AddCtlDriveStrengthSet_Unsupported( DDR_MODULE_ID index , DDR_PHY_DRIVE_STRENGTH drvStr )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_AddCtlDriveStrengthSet");
}


//******************************************************************************
/* Function :  DDR_PHY_OdtCal_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_OdtCal 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_OdtCal function.
*/

PLIB_TEMPLATE void DDR_PHY_OdtCal_Unsupported( DDR_MODULE_ID index , uint8_t puCal , uint8_t pdCal )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_OdtCal");
}


//******************************************************************************
/* Function :  DDR_PHY_DrvStrgthCal_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_DrvStrgthCal 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_DrvStrgthCal function.
*/

PLIB_TEMPLATE void DDR_PHY_DrvStrgthCal_Unsupported( DDR_MODULE_ID index , uint8_t nFet , uint8_t pFet )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_DrvStrgthCal");
}


//******************************************************************************
/* Function :  DDR_PHY_ExtraClockEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_ExtraClockEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_ExtraClockEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_ExtraClockEnable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_ExtraClockEnable");
}


//******************************************************************************
/* Function :  DDR_PHY_ExtraClockDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_ExtraClockDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_ExtraClockDisable function.
*/

PLIB_TEMPLATE void DDR_PHY_ExtraClockDisable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_ExtraClockDisable");
}


//******************************************************************************
/* Function :  DDR_PHY_InternalDllEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_InternalDllEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_InternalDllEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_InternalDllEnable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_InternalDllEnable");
}


//******************************************************************************
/* Function :  DDR_PHY_ExternalDllEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_ExternalDllEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_ExternalDllEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_ExternalDllEnable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_ExternalDllEnable");
}


//******************************************************************************
/* Function :  DDR_PHY_PadReceiveEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_PadReceiveEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_PadReceiveEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_PadReceiveEnable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_PadReceiveEnable");
}


//******************************************************************************
/* Function :  DDR_PHY_PadReceiveDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_PadReceiveDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_PadReceiveDisable function.
*/

PLIB_TEMPLATE void DDR_PHY_PadReceiveDisable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_PadReceiveDisable");
}


//******************************************************************************
/* Function :  DDR_PHY_PreambleDlySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_PreambleDlySet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_PreambleDlySet function.
*/

PLIB_TEMPLATE void DDR_PHY_PreambleDlySet_Unsupported( DDR_MODULE_ID index , DDR_PHY_PREAMBLE_DLY preDly )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_PreambleDlySet");
}


//******************************************************************************
/* Function :  DDR_PHY_HalfRateSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_HalfRateSet 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_HalfRateSet function.
*/

PLIB_TEMPLATE void DDR_PHY_HalfRateSet_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_HalfRateSet");
}


//******************************************************************************
/* Function :  DDR_PHY_WriteCmdDelayEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_WriteCmdDelayEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_WriteCmdDelayEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_WriteCmdDelayEnable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_WriteCmdDelayEnable");
}


//******************************************************************************
/* Function :  DDR_PHY_WriteCmdDelayDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_PHY_WriteCmdDelayDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_PHY_WriteCmdDelayDisable function.
*/

PLIB_TEMPLATE void DDR_PHY_WriteCmdDelayDisable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_PHY_WriteCmdDelayDisable");
}


//******************************************************************************
/* Function :  DDR_ExistsPHY_PadConfig_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_ExistsPHY_PadConfig

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_ExistsPHY_PadConfig function.
*/

PLIB_TEMPLATE bool DDR_ExistsPHY_PadConfig_Unsupported( DDR_MODULE_ID index )
{
    return false;
}


#endif /*_DDR_PHY_PADCONFIG_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

