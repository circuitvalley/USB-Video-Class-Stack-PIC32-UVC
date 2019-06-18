/*******************************************************************************
  ADC Peripheral Library Template Implementation

  File Name:
    adc_SamplingAutoStart_Unsupported.h

  Summary:
    ADC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : SamplingAutoStart
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADC_SampleAutoStartEnable
        PLIB_ADC_SampleAutoStartDisable
        PLIB_ADC_ExistsSamplingAutoStart

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

#ifndef _ADC_SAMPLINGAUTOSTART_UNSUPPORTED_H
#define _ADC_SAMPLINGAUTOSTART_UNSUPPORTED_H

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
/* Function :  ADC_SampleAutoStartEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADC_SampleAutoStartEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADC_SampleAutoStartEnable function.
*/

PLIB_TEMPLATE void ADC_SampleAutoStartEnable_Unsupported( ADC_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADC_SampleAutoStartEnable");
}


//******************************************************************************
/* Function :  ADC_SampleAutoStartDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADC_SampleAutoStartDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADC_SampleAutoStartDisable function.
*/

PLIB_TEMPLATE void ADC_SampleAutoStartDisable_Unsupported( ADC_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADC_SampleAutoStartDisable");
}


//******************************************************************************
/* Function :  ADC_ExistsSamplingAutoStart_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADC_ExistsSamplingAutoStart

  Description:
    This template implements the Unsupported variant of the PLIB_ADC_ExistsSamplingAutoStart function.
*/

PLIB_TEMPLATE bool ADC_ExistsSamplingAutoStart_Unsupported( ADC_MODULE_ID index )
{
    return false;
}


#endif /*_ADC_SAMPLINGAUTOSTART_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

