/*******************************************************************************
  CMP Peripheral Library Template Implementation

  File Name:
    cmp_ComparatorOutputDigitalFilter_Default.h

  Summary:
    CMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ComparatorOutputDigitalFilter
    and its Variant : Default
    For following APIs :
        PLIB_CMP_ExistsComparatorOutputDigitalFilter
        PLIB_CMP_ComparatorOutputDigitalFilterClkSetup
        PLIB_CMP_ComparatorOutputDigitalFilterEnable
        PLIB_CMP_ComparatorOutputDigitalFilterDisable

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

#ifndef _CMP_COMPARATOROUTPUTDIGITALFILTER_DEFAULT_H
#define _CMP_COMPARATOROUTPUTDIGITALFILTER_DEFAULT_H

#include "cmp_registers.h"

//******************************************************************************
/* Function :  CMP_ExistsComparatorOutputDigitalFilter_Default

  Summary:
    Implements Default variant of PLIB_CMP_ExistsComparatorOutputDigitalFilter

  Description:
    This template implements the Default variant of the PLIB_CMP_ExistsComparatorOutputDigitalFilter function.
*/

#define PLIB_CMP_ExistsComparatorOutputDigitalFilter PLIB_CMP_ExistsComparatorOutputDigitalFilter
PLIB_TEMPLATE bool CMP_ExistsComparatorOutputDigitalFilter_Default( CMP_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  CMP_ComparatorOutputDigitalFilterClkSetup_Default

  Summary:
    Implements Default variant of PLIB_CMP_ComparatorOutputDigitalFilterClkSetup 

  Description:
    This template implements the Default variant of the PLIB_CMP_ComparatorOutputDigitalFilterClkSetup function.
*/

PLIB_TEMPLATE void CMP_ComparatorOutputDigitalFilterClkSetup_Default( CMP_MODULE_ID index , CMP_OUTPUT_FILTER_CLK_SOURCE clkSource , CMP_OUTPUT_FILTER_CLK_DIV clkDivider )
{
	volatile cmp_registers_t *cmp = ((cmp_registers_t *)(index));
	cmp->CMxCON.CFSEL = clkSource;
	cmp->CMxCON.CFDIV = clkDivider;
}


//******************************************************************************
/* Function :  CMP_ComparatorOutputDigitalFilterEnable_Default

  Summary:
    Implements Default variant of PLIB_CMP_ComparatorOutputDigitalFilterEnable 

  Description:
    This template implements the Default variant of the PLIB_CMP_ComparatorOutputDigitalFilterEnable function.
*/

PLIB_TEMPLATE void CMP_ComparatorOutputDigitalFilterEnable_Default( CMP_MODULE_ID index )
{
	volatile cmp_registers_t *cmp = ((cmp_registers_t *)(index));
	cmp->CMxCONSET = CMxCON_CFLTREN_MASK;
}


//******************************************************************************
/* Function :  CMP_ComparatorOutputDigitalFilterDisable_Default

  Summary:
    Implements Default variant of PLIB_CMP_ComparatorOutputDigitalFilterDisable 

  Description:
    This template implements the Default variant of the PLIB_CMP_ComparatorOutputDigitalFilterDisable function.
*/

PLIB_TEMPLATE void CMP_ComparatorOutputDigitalFilterDisable_Default( CMP_MODULE_ID index )
{
	volatile cmp_registers_t *cmp = ((cmp_registers_t *)(index));
	cmp->CMxCONCLR = CMxCON_CFLTREN_MASK;
}


#endif /*_CMP_COMPARATOROUTPUTDIGITALFILTER_DEFAULT_H*/

/******************************************************************************
 End of File
*/

