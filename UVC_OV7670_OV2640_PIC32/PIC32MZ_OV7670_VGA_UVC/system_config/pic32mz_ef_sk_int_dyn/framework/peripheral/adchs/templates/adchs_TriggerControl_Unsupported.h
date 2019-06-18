/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_TriggerControl_Unsupported.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : TriggerControl
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCHS_AnalogInputLevelTriggerSet
        PLIB_ADCHS_AnalogInputEdgeTriggerSet
        PLIB_ADCHS_AnalogInputTriggerSourceSelect
        PLIB_ADCHS_GlobalSoftwareTriggerEnable
        PLIB_ADCHS_GlobalLevelSoftwareTriggerEnable
        PLIB_ADCHS_GlobalLevelSoftwareTriggerDisable
        PLIB_ADCHS_TriggerSuspendEnable
        PLIB_ADCHS_TriggerSuspendDisable
        PLIB_ADCHS_ExistsTriggerControl

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

#ifndef _ADCHS_TRIGGERCONTROL_UNSUPPORTED_H
#define _ADCHS_TRIGGERCONTROL_UNSUPPORTED_H

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
/* Function :  ADCHS_AnalogInputLevelTriggerSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputLevelTriggerSet 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputLevelTriggerSet function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputLevelTriggerSet_Unsupported( ADCHS_MODULE_ID index , ADCHS_CLASS12_AN_INPUT_ID analogInput )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputLevelTriggerSet");
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputEdgeTriggerSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputEdgeTriggerSet 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputEdgeTriggerSet function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputEdgeTriggerSet_Unsupported( ADCHS_MODULE_ID index , ADCHS_CLASS12_AN_INPUT_ID analogInput )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputEdgeTriggerSet");
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputTriggerSourceSelect_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputTriggerSourceSelect 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputTriggerSourceSelect function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputTriggerSourceSelect_Unsupported( ADCHS_MODULE_ID index , ADCHS_CLASS12_AN_INPUT_ID inputId , ADCHS_TRIGGER_SOURCE triggerSource )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputTriggerSourceSelect");
}


//******************************************************************************
/* Function :  ADCHS_GlobalSoftwareTriggerEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_GlobalSoftwareTriggerEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_GlobalSoftwareTriggerEnable function.
*/

PLIB_TEMPLATE void ADCHS_GlobalSoftwareTriggerEnable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_GlobalSoftwareTriggerEnable");
}


//******************************************************************************
/* Function :  ADCHS_GlobalLevelSoftwareTriggerEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_GlobalLevelSoftwareTriggerEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_GlobalLevelSoftwareTriggerEnable function.
*/

PLIB_TEMPLATE void ADCHS_GlobalLevelSoftwareTriggerEnable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_GlobalLevelSoftwareTriggerEnable");
}


//******************************************************************************
/* Function :  ADCHS_GlobalLevelSoftwareTriggerDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_GlobalLevelSoftwareTriggerDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_GlobalLevelSoftwareTriggerDisable function.
*/

PLIB_TEMPLATE void ADCHS_GlobalLevelSoftwareTriggerDisable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_GlobalLevelSoftwareTriggerDisable");
}


//******************************************************************************
/* Function :  ADCHS_TriggerSuspendEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_TriggerSuspendEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_TriggerSuspendEnable function.
*/

PLIB_TEMPLATE void ADCHS_TriggerSuspendEnable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_TriggerSuspendEnable");
}


//******************************************************************************
/* Function :  ADCHS_TriggerSuspendDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_TriggerSuspendDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_TriggerSuspendDisable function.
*/

PLIB_TEMPLATE void ADCHS_TriggerSuspendDisable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_TriggerSuspendDisable");
}


//******************************************************************************
/* Function :  ADCHS_ExistsTriggerControl_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ExistsTriggerControl

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ExistsTriggerControl function.
*/

PLIB_TEMPLATE bool ADCHS_ExistsTriggerControl_Unsupported( ADCHS_MODULE_ID index )
{
    return false;
}


#endif /*_ADCHS_TRIGGERCONTROL_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

