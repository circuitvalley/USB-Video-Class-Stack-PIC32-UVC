/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_SingleCyclePerLineVsyncControl_Unsupported.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : SingleCyclePerLineVsyncControl
    and its Variant : Unsupported
    For following APIs :
        PLIB_GLCD_ExistsSingleCyclePerLineVsync
        PLIB_GLCD_SingleCyclePerLineVsyncEnable
        PLIB_GLCD_SingleCyclePerLineVsyncDisable
        PLIB_GLCD_SingleCyclePerLineVsyncIsEnabled

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

#ifndef _GLCD_SINGLECYCLEPERLINEVSYNCCONTROL_UNSUPPORTED_H
#define _GLCD_SINGLECYCLEPERLINEVSYNCCONTROL_UNSUPPORTED_H

//******************************************************************************
/* Function :  GLCD_ExistsSingleCyclePerLineVsync_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_ExistsSingleCyclePerLineVsync

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_ExistsSingleCyclePerLineVsync function.
*/
PLIB_TEMPLATE bool GLCD_ExistsSingleCyclePerLineVsync_Unsupported( GLCD_MODULE_ID index )
{
    return false;
}

//******************************************************************************
/* Function :  GLCD_SingleCyclePerLineVsyncEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_SingleCyclePerLineVsyncEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_SingleCyclePerLineVsyncEnable function.
*/
PLIB_TEMPLATE void GLCD_SingleCyclePerLineVsyncEnable_Unsupported( GLCD_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_SingleCyclePerLineVsyncEnable");
}

//******************************************************************************
/* Function :  GLCD_SingleCyclePerLineVsyncDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_SingleCyclePerLineVsyncDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_SingleCyclePerLineVsyncDisable function.
*/
PLIB_TEMPLATE void GLCD_SingleCyclePerLineVsyncDisable_Unsupported( GLCD_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_SingleCyclePerLineVsyncDisable");
}

//******************************************************************************
/* Function :  GLCD_SingleCyclePerLineVsyncIsEnabled_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_SingleCyclePerLineVsyncIsEnabled 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_SingleCyclePerLineVsyncIsEnabled function.
*/
PLIB_TEMPLATE bool GLCD_SingleCyclePerLineVsyncIsEnabled_Unsupported( GLCD_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_SingleCyclePerLineVsyncIsEnabled");

    return false;
}

#endif /*_GLCD_SINGLECYCLEPERLINEVSYNCCONTROL_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

