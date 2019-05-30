/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_ForceOutputBlankControl_Unsupported.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ForceOutputBlankControl
    and its Variant : Unsupported
    For following APIs :
        PLIB_GLCD_ExistsForceOutputBlank
        PLIB_GLCD_ForceOutputBlankEnable
        PLIB_GLCD_ForceOutputBlankDisable
        PLIB_GLCD_ForceOutputBlankIsEnabled

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

#ifndef _GLCD_FORCEOUTPUTBLANKCONTROL_UNSUPPORTED_H
#define _GLCD_FORCEOUTPUTBLANKCONTROL_UNSUPPORTED_H

//******************************************************************************
/* Function :  GLCD_ExistsForceOutputBlank_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_ExistsForceOutputBlank

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_ExistsForceOutputBlank function.
*/
PLIB_TEMPLATE bool GLCD_ExistsForceOutputBlank_Unsupported( GLCD_MODULE_ID index )
{
    return false;
}

//******************************************************************************
/* Function :  GLCD_ForceOutputBlankEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_ForceOutputBlankEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_ForceOutputBlankEnable function.
*/
PLIB_TEMPLATE void GLCD_ForceOutputBlankEnable_Unsupported( GLCD_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_ForceOutputBlankEnable");
}

//******************************************************************************
/* Function :  GLCD_ForceOutputBlankDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_ForceOutputBlankDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_ForceOutputBlankDisable function.
*/
PLIB_TEMPLATE void GLCD_ForceOutputBlankDisable_Unsupported( GLCD_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_ForceOutputBlankDisable");
}

//******************************************************************************
/* Function :  GLCD_ForceOutputBlankIsEnabled_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_ForceOutputBlankIsEnabled 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_ForceOutputBlankIsEnabled function.
*/
PLIB_TEMPLATE bool GLCD_ForceOutputBlankIsEnabled_Unsupported( GLCD_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_ForceOutputBlankIsEnabled");

    return false;
}

#endif /*_GLCD_FORCEOUTPUTBLANKCONTROL_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

