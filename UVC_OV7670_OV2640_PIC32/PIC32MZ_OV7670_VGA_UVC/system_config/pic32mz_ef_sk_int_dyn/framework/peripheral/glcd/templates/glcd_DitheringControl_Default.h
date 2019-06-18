/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_DitheringControl_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DitheringControl
    and its Variant : Default
    For following APIs :
        PLIB_GLCD_ExistsDithering
        PLIB_GLCD_DitheringEnable
        PLIB_GLCD_DitheringDisable
        PLIB_GLCD_DitheringIsEnabled

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

#ifndef _GLCD_DITHERINGCONTROL_DEFAULT_H
#define _GLCD_DITHERINGCONTROL_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsDithering_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsDithering

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsDithering function.
*/
#define PLIB_GLCD_ExistsDithering PLIB_GLCD_ExistsDithering
PLIB_TEMPLATE bool GLCD_ExistsDithering_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_DitheringEnable_Default

  Summary:
    Implements Default variant of PLIB_GLCD_DitheringEnable 

  Description:
    This template implements the Default variant of the PLIB_GLCD_DitheringEnable function.
*/
PLIB_TEMPLATE void GLCD_DitheringEnable_Default( GLCD_MODULE_ID index )
{
    GLCDMODEbits.DITHER = 1;
}

//******************************************************************************
/* Function :  GLCD_DitheringDisable_Default

  Summary:
    Implements Default variant of PLIB_GLCD_DitheringDisable 

  Description:
    This template implements the Default variant of the PLIB_GLCD_DitheringDisable function.
*/
PLIB_TEMPLATE void GLCD_DitheringDisable_Default( GLCD_MODULE_ID index )
{
    GLCDMODEbits.DITHER = 0;
}

//******************************************************************************
/* Function :  GLCD_DitheringIsEnabled_Default

  Summary:
    Implements Default variant of PLIB_GLCD_DitheringIsEnabled 

  Description:
    This template implements the Default variant of the PLIB_GLCD_DitheringIsEnabled function.
*/
PLIB_TEMPLATE bool GLCD_DitheringIsEnabled_Default( GLCD_MODULE_ID index )
{
    return GLCDMODEbits.DITHER;
}

#endif /*_GLCD_DITHERINGCONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

