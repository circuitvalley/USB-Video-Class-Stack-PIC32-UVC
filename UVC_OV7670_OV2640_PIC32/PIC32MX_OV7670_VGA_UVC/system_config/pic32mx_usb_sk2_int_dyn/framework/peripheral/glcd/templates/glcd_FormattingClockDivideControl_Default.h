/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_FormattingClockDivideControl_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : FormattingClockDivideControl
    and its Variant : Default
    For following APIs :
        PLIB_GLCD_ExistsFormattingClockDivide
        PLIB_GLCD_FormattingClockDivideEnable
        PLIB_GLCD_FormattingClockDivideDisable
        PLIB_GLCD_FormattingClockDivideIsEnabled

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

#ifndef _GLCD_FORMATTINGCLOCKDIVIDECONTROL_DEFAULT_H
#define _GLCD_FORMATTINGCLOCKDIVIDECONTROL_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsFormattingClockDivide_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsFormattingClockDivide

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsFormattingClockDivide function.
*/
#define PLIB_GLCD_ExistsFormattingClockDivide PLIB_GLCD_ExistsFormattingClockDivide
PLIB_TEMPLATE bool GLCD_ExistsFormattingClockDivide_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_FormattingClockDivideEnable_Default

  Summary:
    Implements Default variant of PLIB_GLCD_FormattingClockDivideEnable 

  Description:
    This template implements the Default variant of the PLIB_GLCD_FormattingClockDivideEnable function.
*/
PLIB_TEMPLATE void GLCD_FormattingClockDivideEnable_Default( GLCD_MODULE_ID index )
{
    GLCDMODEbits.FORMATCLK = 1;
}

//******************************************************************************
/* Function :  GLCD_FormattingClockDivideDisable_Default

  Summary:
    Implements Default variant of PLIB_GLCD_FormattingClockDivideDisable 

  Description:
    This template implements the Default variant of the PLIB_GLCD_FormattingClockDivideDisable function.
*/
PLIB_TEMPLATE void GLCD_FormattingClockDivideDisable_Default( GLCD_MODULE_ID index )
{
    GLCDMODEbits.FORMATCLK = 0;
}

//******************************************************************************
/* Function :  GLCD_FormattingClockDivideIsEnabled_Default

  Summary:
    Implements Default variant of PLIB_GLCD_FormattingClockDivideIsEnabled 

  Description:
    This template implements the Default variant of the PLIB_GLCD_FormattingClockDivideIsEnabled function.
*/
PLIB_TEMPLATE bool GLCD_FormattingClockDivideIsEnabled_Default( GLCD_MODULE_ID index )
{
    return GLCDMODEbits.FORMATCLK;
}

#endif /*_GLCD_FORMATTINGCLOCKDIVIDECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

