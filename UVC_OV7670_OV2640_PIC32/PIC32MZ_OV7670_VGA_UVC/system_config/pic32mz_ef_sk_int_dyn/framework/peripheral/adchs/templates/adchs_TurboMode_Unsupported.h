/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_TurboMode_Unsupported.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : TurboMode
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCHS_TurboModeEnable
        PLIB_ADCHS_TurboModeDisable
        PLIB_ADCHS_TurboModeErrorHasOccurred
        PLIB_ADCHS_TurboModeChannelSelect
        PLIB_ADCHS_ExistsTurboMode

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

#ifndef _ADCHS_TURBOMODE_UNSUPPORTED_H
#define _ADCHS_TURBOMODE_UNSUPPORTED_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    None.

  MASKs: 
    None.

  POSs: 
    None.

  LENs: 
    None.

*/


//******************************************************************************
/* Function :  ADCHS_TurboModeEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_TurboModeEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_TurboModeEnable function.
*/

PLIB_TEMPLATE void ADCHS_TurboModeEnable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_TurboModeEnable");
}


//******************************************************************************
/* Function :  ADCHS_TurboModeDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_TurboModeDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_TurboModeDisable function.
*/

PLIB_TEMPLATE void ADCHS_TurboModeDisable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_TurboModeDisable");
}


//******************************************************************************
/* Function :  ADCHS_TurboModeErrorHasOccurred_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_TurboModeErrorHasOccurred 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_TurboModeErrorHasOccurred function.
*/

PLIB_TEMPLATE bool ADCHS_TurboModeErrorHasOccurred_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_TurboModeErrorHasOccurred");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_TurboModeChannelSelect_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_TurboModeChannelSelect 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_TurboModeChannelSelect function.
*/

PLIB_TEMPLATE bool ADCHS_TurboModeChannelSelect_Unsupported( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID masterChannelID , ADCHS_CHANNEL_ID slaveChannelID )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_TurboModeChannelSelect");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_ExistsTurboMode_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ExistsTurboMode

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ExistsTurboMode function.
*/

PLIB_TEMPLATE bool ADCHS_ExistsTurboMode_Unsupported( ADCHS_MODULE_ID index )
{
    return false;
}


#endif /*_ADCHS_TURBOMODE_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

