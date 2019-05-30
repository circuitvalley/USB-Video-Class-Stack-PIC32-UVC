/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_DigitalFilter_Unsupported.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DigitalFilter
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCHS_DigitalFilterEnable
        PLIB_ADCHS_DigitalFilterDisable
        PLIB_ADCHS_DigitalFilterOversamplingModeSetup
        PLIB_ADCHS_DigitalFilterAveragingModeSetup
        PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect
        PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect
        PLIB_ADCHS_DigitalFilterDataIsReady
        PLIB_ADCHS_DigitalFilterDataGet
        PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable
        PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable
        PLIB_ADCHS_ExistsDigitalFilter

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

#ifndef _ADCHS_DIGITALFILTER_UNSUPPORTED_H
#define _ADCHS_DIGITALFILTER_UNSUPPORTED_H

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
/* Function :  ADCHS_DigitalFilterEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalFilterEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalFilterEnable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterEnable_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalFilterEnable");
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalFilterDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalFilterDisable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterDisable_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalFilterDisable");
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterOversamplingModeSetup_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalFilterOversamplingModeSetup 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalFilterOversamplingModeSetup function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterOversamplingModeSetup_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id , ADCHS_AN_INPUT_ID analogInput , ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length , ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio , bool globalIntEnable )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalFilterOversamplingModeSetup");
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterAveragingModeSetup_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalFilterAveragingModeSetup 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalFilterAveragingModeSetup function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterAveragingModeSetup_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id , ADCHS_AN_INPUT_ID analogInput , ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length , ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count , bool globalIntEnable )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalFilterAveragingModeSetup");
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterOversamplingModeRatioSelect_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterOversamplingModeRatioSelect_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id , ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect");
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterAveragingModeSampleCountSelect_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterAveragingModeSampleCountSelect_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id , ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect");
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterDataIsReady_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalFilterDataIsReady 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalFilterDataIsReady function.
*/

PLIB_TEMPLATE bool ADCHS_DigitalFilterDataIsReady_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalFilterDataIsReady");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterDataGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalFilterDataGet 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalFilterDataGet function.
*/

PLIB_TEMPLATE int16_t ADCHS_DigitalFilterDataGet_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID dfltrID )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalFilterDataGet");

    return 0;
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterDataReadyInterruptEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterDataReadyInterruptEnable_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID digFilter )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable");
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterDataReadyInterruptDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterDataReadyInterruptDisable_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID digFilter )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable");
}


//******************************************************************************
/* Function :  ADCHS_ExistsDigitalFilter_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ExistsDigitalFilter

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ExistsDigitalFilter function.
*/

PLIB_TEMPLATE bool ADCHS_ExistsDigitalFilter_Unsupported( ADCHS_MODULE_ID index )
{
    return false;
}


#endif /*_ADCHS_DIGITALFILTER_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

