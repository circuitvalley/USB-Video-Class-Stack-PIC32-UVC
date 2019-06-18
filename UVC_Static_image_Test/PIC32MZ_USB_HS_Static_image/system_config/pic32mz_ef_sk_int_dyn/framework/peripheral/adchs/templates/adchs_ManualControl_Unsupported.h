/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_ManualControl_Unsupported.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ManualControl
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCHS_SoftwareSamplingStart
        PLIB_ADCHS_SoftwareSamplingStop
        PLIB_ADCHS_SoftwareConversionStart
        PLIB_ADCHS_SoftwareConversionInputSelect
        PLIB_ADCHS_ExistsManualControl

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

#ifndef _ADCHS_MANUALCONTROL_UNSUPPORTED_H
#define _ADCHS_MANUALCONTROL_UNSUPPORTED_H

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
/* Function :  ADCHS_SoftwareSamplingStart_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_SoftwareSamplingStart 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_SoftwareSamplingStart function.
*/

PLIB_TEMPLATE void ADCHS_SoftwareSamplingStart_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_SoftwareSamplingStart");
}


//******************************************************************************
/* Function :  ADCHS_SoftwareSamplingStop_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_SoftwareSamplingStop 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_SoftwareSamplingStop function.
*/

PLIB_TEMPLATE void ADCHS_SoftwareSamplingStop_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_SoftwareSamplingStop");
}


//******************************************************************************
/* Function :  ADCHS_SoftwareConversionStart_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_SoftwareConversionStart 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_SoftwareConversionStart function.
*/

PLIB_TEMPLATE void ADCHS_SoftwareConversionStart_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_SoftwareConversionStart");
}


//******************************************************************************
/* Function :  ADCHS_SoftwareConversionInputSelect_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_SoftwareConversionInputSelect 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_SoftwareConversionInputSelect function.
*/

PLIB_TEMPLATE void ADCHS_SoftwareConversionInputSelect_Unsupported( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID anInput )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_SoftwareConversionInputSelect");
}


//******************************************************************************
/* Function :  ADCHS_ExistsManualControl_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ExistsManualControl

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ExistsManualControl function.
*/

PLIB_TEMPLATE bool ADCHS_ExistsManualControl_Unsupported( ADCHS_MODULE_ID index )
{
    return false;
}


#endif /*_ADCHS_MANUALCONTROL_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

