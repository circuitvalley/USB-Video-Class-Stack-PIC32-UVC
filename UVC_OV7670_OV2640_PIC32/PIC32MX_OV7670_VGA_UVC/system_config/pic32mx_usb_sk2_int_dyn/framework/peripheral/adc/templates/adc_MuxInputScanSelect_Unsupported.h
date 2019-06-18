/*******************************************************************************
  ADC Peripheral Library Template Implementation

  File Name:
    adc_MuxInputScanSelect_Unsupported.h

  Summary:
    ADC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : MuxInputScanSelect
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADC_InputScanMaskAdd
        PLIB_ADC_InputScanMaskRemove
        PLIB_ADC_ExistsMuxInputScanSelect

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

#ifndef _ADC_MUXINPUTSCANSELECT_UNSUPPORTED_H
#define _ADC_MUXINPUTSCANSELECT_UNSUPPORTED_H

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
/* Function :  ADC_InputScanMaskAdd_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADC_InputScanMaskAdd 

  Description:
    This template implements the Unsupported variant of the PLIB_ADC_InputScanMaskAdd function.
*/

PLIB_TEMPLATE void ADC_InputScanMaskAdd_Unsupported( ADC_MODULE_ID index , ADC_INPUTS_SCAN scanInputs )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADC_InputScanMaskAdd");
}


//******************************************************************************
/* Function :  ADC_InputScanMaskRemove_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADC_InputScanMaskRemove 

  Description:
    This template implements the Unsupported variant of the PLIB_ADC_InputScanMaskRemove function.
*/

PLIB_TEMPLATE void ADC_InputScanMaskRemove_Unsupported( ADC_MODULE_ID index , ADC_INPUTS_SCAN scanInputs )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADC_InputScanMaskRemove");
}


//******************************************************************************
/* Function :  ADC_ExistsMuxInputScanSelect_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADC_ExistsMuxInputScanSelect

  Description:
    This template implements the Unsupported variant of the PLIB_ADC_ExistsMuxInputScanSelect function.
*/

PLIB_TEMPLATE bool ADC_ExistsMuxInputScanSelect_Unsupported( ADC_MODULE_ID index )
{
    return false;
}


#endif /*_ADC_MUXINPUTSCANSELECT_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

