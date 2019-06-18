/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_AnalogInputModeControl_Unsupported.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : AnalogInputModeControl
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCHS_AnalogInputModeSelect
        PLIB_ADCHS_AnalogInputModeGet
        PLIB_ADCHS_ExistsAnalogInputModeControl

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

#ifndef _ADCHS_ANALOGINPUTMODECONTROL_UNSUPPORTED_H
#define _ADCHS_ANALOGINPUTMODECONTROL_UNSUPPORTED_H

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
/* Function :  ADCHS_AnalogInputModeSelect_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputModeSelect 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputModeSelect function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputModeSelect_Unsupported( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput , ADCHS_INPUT_MODE mode )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputModeSelect");
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputModeGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputModeGet 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputModeGet function.
*/

PLIB_TEMPLATE ADCHS_INPUT_MODE ADCHS_AnalogInputModeGet_Unsupported( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputModeGet");

    return 0;
}


//******************************************************************************
/* Function :  ADCHS_ExistsAnalogInputModeControl_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ExistsAnalogInputModeControl

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ExistsAnalogInputModeControl function.
*/

PLIB_TEMPLATE bool ADCHS_ExistsAnalogInputModeControl_Unsupported( ADCHS_MODULE_ID index )
{
    return false;
}


#endif /*_ADCHS_ANALOGINPUTMODECONTROL_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

