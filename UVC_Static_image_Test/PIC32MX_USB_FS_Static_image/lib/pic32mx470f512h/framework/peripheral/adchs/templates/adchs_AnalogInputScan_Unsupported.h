/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_AnalogInputScan_Unsupported.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : AnalogInputScan
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCHS_AnalogInputScanIsComplete
        PLIB_ADCHS_AnalogInputScanSelect
        PLIB_ADCHS_AnalogInputScanRemove
        PLIB_ADCHS_AnalogInputScanIsSelected
        PLIB_ADCHS_AnalogInputScanSetup
        PLIB_ADCHS_ScanCompleteInterruptEnable
        PLIB_ADCHS_ScanCompleteInterruptDisable
        PLIB_ADCHS_ExistsAnalogInputScan

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

#ifndef _ADCHS_ANALOGINPUTSCAN_UNSUPPORTED_H
#define _ADCHS_ANALOGINPUTSCAN_UNSUPPORTED_H

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
/* Function :  ADCHS_AnalogInputScanIsComplete_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputScanIsComplete 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputScanIsComplete function.
*/

PLIB_TEMPLATE bool ADCHS_AnalogInputScanIsComplete_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputScanIsComplete");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputScanSelect_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputScanSelect 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputScanSelect function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputScanSelect_Unsupported( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputScanSelect");
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputScanRemove_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputScanRemove 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputScanRemove function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputScanRemove_Unsupported( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputScanRemove");
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputScanIsSelected_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputScanIsSelected 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputScanIsSelected function.
*/

PLIB_TEMPLATE bool ADCHS_AnalogInputScanIsSelected_Unsupported( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputScanIsSelected");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputScanSetup_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputScanSetup 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputScanSetup function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputScanSetup_Unsupported( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput	ADCHS_SCAN_TRIGGER_SENSITIVE trgSensitive , ADCHS_SCAN_TRIGGER_SOURCE triggerSource )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputScanSetup");
}


//******************************************************************************
/* Function :  ADCHS_ScanCompleteInterruptEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ScanCompleteInterruptEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ScanCompleteInterruptEnable function.
*/

PLIB_TEMPLATE void ADCHS_ScanCompleteInterruptEnable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_ScanCompleteInterruptEnable");
}


//******************************************************************************
/* Function :  ADCHS_ScanCompleteInterruptDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ScanCompleteInterruptDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ScanCompleteInterruptDisable function.
*/

PLIB_TEMPLATE void ADCHS_ScanCompleteInterruptDisable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_ScanCompleteInterruptDisable");
}


//******************************************************************************
/* Function :  ADCHS_ExistsAnalogInputScan_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ExistsAnalogInputScan

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ExistsAnalogInputScan function.
*/

PLIB_TEMPLATE bool ADCHS_ExistsAnalogInputScan_Unsupported( ADCHS_MODULE_ID index )
{
    return false;
}


#endif /*_ADCHS_ANALOGINPUTSCAN_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

