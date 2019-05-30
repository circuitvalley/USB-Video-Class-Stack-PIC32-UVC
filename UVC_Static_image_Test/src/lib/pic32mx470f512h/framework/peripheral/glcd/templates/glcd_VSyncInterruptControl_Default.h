/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_VSyncInterruptControl_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : VSyncInterruptControl
    and its Variant : Default
    For following APIs :
        PLIB_GLCD_ExistsVSyncInterruptEnable
        PLIB_GLCD_VSyncInterruptEnable
        PLIB_GLCD_VSyncInterruptDisable
        PLIB_GLCD_VSyncInterruptIsEnabled

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

#ifndef _GLCD_VSYNCINTERRUPTCONTROL_DEFAULT_H
#define _GLCD_VSYNCINTERRUPTCONTROL_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsVSyncInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsVSyncInterruptEnable

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsVSyncInterruptEnable function.
*/
#define PLIB_GLCD_ExistsVSyncInterruptEnable PLIB_GLCD_ExistsVSyncInterruptEnable
PLIB_TEMPLATE bool GLCD_ExistsVSyncInterruptEnable_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_VSyncInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_GLCD_VSyncInterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_GLCD_VSyncInterruptEnable function.
*/
PLIB_TEMPLATE void GLCD_VSyncInterruptEnable_Default( GLCD_MODULE_ID  index )
{
    GLCDINTbits.VSYNCINT = 1;
}

//******************************************************************************
/* Function :  GLCD_VSyncInterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_GLCD_VSyncInterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_GLCD_VSyncInterruptDisable function.
*/
PLIB_TEMPLATE void GLCD_VSyncInterruptDisable_Default( GLCD_MODULE_ID  index )
{
    GLCDINTbits.VSYNCINT = 0;
}

//******************************************************************************
/* Function :  GLCD_VSyncInterruptIsEnabled_Default

  Summary:
    Implements Default variant of PLIB_GLCD_VSyncInterruptIsEnabled 

  Description:
    This template implements the Default variant of the PLIB_GLCD_VSyncInterruptIsEnabled function.
*/

PLIB_TEMPLATE bool GLCD_VSyncInterruptIsEnabled_Default( GLCD_MODULE_ID index )
{
    return GLCDINTbits.VSYNCINT;
}

#endif /*_GLCD_VSYNCINTERRUPTCONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

