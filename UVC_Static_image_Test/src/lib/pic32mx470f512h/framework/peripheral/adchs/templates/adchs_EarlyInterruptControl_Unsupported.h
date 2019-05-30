/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_EarlyInterruptControl_Unsupported.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EarlyInterruptControl
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCHS_EarlyInterruptEnable
        PLIB_ADCHS_EarlyInterruptDisable
        PLIB_ADCHS_AnalogInputEarlyInterruptEnable
        PLIB_ADCHS_AnalogInputEarlyInterruptDisable
        PLIB_ADCHS_AnalogInputEarlyInterruptIsReady
        PLIB_ADCHS_ExistsEarlyInterruptControl

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

#ifndef _ADCHS_EARLYINTERRUPTCONTROL_UNSUPPORTED_H
#define _ADCHS_EARLYINTERRUPTCONTROL_UNSUPPORTED_H

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
/* Function :  ADCHS_EarlyInterruptEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_EarlyInterruptEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_EarlyInterruptEnable function.
*/

PLIB_TEMPLATE void ADCHS_EarlyInterruptEnable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_EarlyInterruptEnable");
}


//******************************************************************************
/* Function :  ADCHS_EarlyInterruptDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_EarlyInterruptDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_EarlyInterruptDisable function.
*/

PLIB_TEMPLATE void ADCHS_EarlyInterruptDisable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_EarlyInterruptDisable");
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputEarlyInterruptEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputEarlyInterruptEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputEarlyInterruptEnable function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputEarlyInterruptEnable_Unsupported( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputEarlyInterruptEnable");
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputEarlyInterruptDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputEarlyInterruptDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputEarlyInterruptDisable function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputEarlyInterruptDisable_Unsupported( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputEarlyInterruptDisable");
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputEarlyInterruptIsReady_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputEarlyInterruptIsReady 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputEarlyInterruptIsReady function.
*/

PLIB_TEMPLATE bool ADCHS_AnalogInputEarlyInterruptIsReady_Unsupported( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputEarlyInterruptIsReady");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_ExistsEarlyInterruptControl_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ExistsEarlyInterruptControl

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ExistsEarlyInterruptControl function.
*/

PLIB_TEMPLATE bool ADCHS_ExistsEarlyInterruptControl_Unsupported( ADCHS_MODULE_ID index )
{
    return false;
}


#endif /*_ADCHS_EARLYINTERRUPTCONTROL_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

