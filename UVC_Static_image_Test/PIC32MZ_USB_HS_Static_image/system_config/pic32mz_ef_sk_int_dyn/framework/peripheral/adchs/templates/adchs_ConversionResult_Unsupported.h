/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_ConversionResult_Unsupported.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ConversionResult
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCHS_AnalogInputDataReadyInterruptEnable
        PLIB_ADCHS_AnalogInputDataReadyInterruptDisable
        PLIB_ADCHS_AnalogInputDataIsReady
        PLIB_ADCHS_AnalogInputResultGet
        PLIB_ADCHS_ExistsConversionResults

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

#ifndef _ADCHS_CONVERSIONRESULT_UNSUPPORTED_H
#define _ADCHS_CONVERSIONRESULT_UNSUPPORTED_H

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
/* Function :  ADCHS_AnalogInputDataReadyInterruptEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputDataReadyInterruptEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputDataReadyInterruptEnable function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputDataReadyInterruptEnable_Unsupported( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputDataReadyInterruptEnable");
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputDataReadyInterruptDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputDataReadyInterruptDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputDataReadyInterruptDisable function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputDataReadyInterruptDisable_Unsupported( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputDataReadyInterruptDisable");
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputDataIsReady_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputDataIsReady 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputDataIsReady function.
*/

PLIB_TEMPLATE bool ADCHS_AnalogInputDataIsReady_Unsupported( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputDataIsReady");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputResultGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_AnalogInputResultGet 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_AnalogInputResultGet function.
*/

PLIB_TEMPLATE uint32_t ADCHS_AnalogInputResultGet_Unsupported( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_AnalogInputResultGet");

    return 0;
}


//******************************************************************************
/* Function :  ADCHS_ExistsConversionResults_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ExistsConversionResults

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ExistsConversionResults function.
*/

PLIB_TEMPLATE bool ADCHS_ExistsConversionResults_Unsupported( ADCHS_MODULE_ID index )
{
    return false;
}


#endif /*_ADCHS_CONVERSIONRESULT_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

