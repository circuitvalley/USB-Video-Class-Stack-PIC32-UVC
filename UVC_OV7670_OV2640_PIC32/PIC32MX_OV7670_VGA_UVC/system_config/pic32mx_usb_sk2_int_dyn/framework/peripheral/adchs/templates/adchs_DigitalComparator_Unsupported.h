/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_DigitalComparator_Unsupported.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DigitalComparator
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCHS_DigitalComparatorAnalogInputSelect
        PLIB_ADCHS_DigitalComparatorAnalogInputGet
        PLIB_ADCHS_DigitalComparatorEnable
        PLIB_ADCHS_DigitalComparatorDisable
        PLIB_ADCHS_DigitalComparatorInterruptEnable
        PLIB_ADCHS_DigitalComparatorInterruptDisable
        PLIB_ADCHS_DigitalComparatorSetup
        PLIB_ADCHS_DigitalComparatorEventHasOccurred
        PLIB_ADCHS_DigitalComparatorLimitSet
        PLIB_ADCHS_ExistsDigitalComparator

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

#ifndef _ADCHS_DIGITALCOMPARATOR_UNSUPPORTED_H
#define _ADCHS_DIGITALCOMPARATOR_UNSUPPORTED_H

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
/* Function :  ADCHS_DigitalComparatorAnalogInputSelect_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalComparatorAnalogInputSelect 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalComparatorAnalogInputSelect function.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorAnalogInputSelect_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator , ADCHS_AN_INPUT_ID analogInput )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalComparatorAnalogInputSelect");
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorAnalogInputGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalComparatorAnalogInputGet 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalComparatorAnalogInputGet function.
*/

PLIB_TEMPLATE ADCHS_AN_INPUT_ID ADCHS_DigitalComparatorAnalogInputGet_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalComparatorAnalogInputGet");

    return 0;
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalComparatorEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalComparatorEnable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorEnable_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalComparatorEnable");
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalComparatorDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalComparatorDisable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorDisable_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalComparatorDisable");
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorInterruptEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalComparatorInterruptEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalComparatorInterruptEnable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorInterruptEnable_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalComparatorInterruptEnable");
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorInterruptDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalComparatorInterruptDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalComparatorInterruptDisable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorInterruptDisable_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalComparatorInterruptDisable");
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorSetup_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalComparatorSetup 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalComparatorSetup function.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorSetup_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID id , bool globalIntEnable , bool inBetweenOrEqual , bool greaterEqualHi , bool lessThanHi , bool greaterEqualLo , bool lessThanLo , ADCHS_AN_INPUT_ID analogInput , int16_t  hiLimit , int16_t  loLimit )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalComparatorSetup");
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorEventHasOccurred_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalComparatorEventHasOccurred 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalComparatorEventHasOccurred function.
*/

PLIB_TEMPLATE bool ADCHS_DigitalComparatorEventHasOccurred_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID id )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalComparatorEventHasOccurred");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorLimitSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DigitalComparatorLimitSet 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DigitalComparatorLimitSet function.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorLimitSet_Unsupported( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID id , int16_t  hiLimit , int16_t  loLimit )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DigitalComparatorLimitSet");
}


//******************************************************************************
/* Function :  ADCHS_ExistsDigitalComparator_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ExistsDigitalComparator

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ExistsDigitalComparator function.
*/

PLIB_TEMPLATE bool ADCHS_ExistsDigitalComparator_Unsupported( ADCHS_MODULE_ID index )
{
    return false;
}


#endif /*_ADCHS_DIGITALCOMPARATOR_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

