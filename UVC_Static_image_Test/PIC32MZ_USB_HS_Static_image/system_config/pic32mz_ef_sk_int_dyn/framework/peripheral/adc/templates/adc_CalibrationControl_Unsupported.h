/*******************************************************************************
  ADC Peripheral Library Template Implementation

  File Name:
    adc_CalibrationControl_Unsupported.h

  Summary:
    ADC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : CalibrationControl
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADC_CalibrationEnable
        PLIB_ADC_CalibrationDisable
        PLIB_ADC_ExistsCalibrationControl

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _ADC_CALIBRATIONCONTROL_UNSUPPORTED_H
#define _ADC_CALIBRATIONCONTROL_UNSUPPORTED_H

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
/* Function :  ADC_CalibrationEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADC_CalibrationEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADC_CalibrationEnable function.
*/

PLIB_TEMPLATE void ADC_CalibrationEnable_Unsupported( ADC_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADC_CalibrationEnable");
}


//******************************************************************************
/* Function :  ADC_CalibrationDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADC_CalibrationDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADC_CalibrationDisable function.
*/

PLIB_TEMPLATE void ADC_CalibrationDisable_Unsupported( ADC_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADC_CalibrationDisable");
}


//******************************************************************************
/* Function :  ADC_ExistsCalibrationControl_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADC_ExistsCalibrationControl

  Description:
    This template implements the Unsupported variant of the PLIB_ADC_ExistsCalibrationControl function.
*/

PLIB_TEMPLATE bool ADC_ExistsCalibrationControl_Unsupported( ADC_MODULE_ID index )
{
    return false;
}


#endif /*_ADC_CALIBRATIONCONTROL_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

