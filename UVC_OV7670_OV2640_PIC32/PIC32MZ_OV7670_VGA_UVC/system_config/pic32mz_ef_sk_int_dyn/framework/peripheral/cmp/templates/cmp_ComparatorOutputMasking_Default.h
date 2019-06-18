/*******************************************************************************
  CMP Peripheral Library Template Implementation

  File Name:
    cmp_ComparatorOutputMasking_Default.h

  Summary:
    CMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : Masking
    and its Variant : Default
    For following APIs :
        PLIB_CMP_ExistsComparatorOutputMasking
        PLIB_CMP_ComparatorOutputMaskingSetup

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

#ifndef _CMP_MASKING_DEFAULT_H
#define _CMP_MASKING_DEFAULT_H

//******************************************************************************
/* Function :  CMP_ExistsComparatorOutputMasking_Default

  Summary:
    Implements Default variant of PLIB_CMP_ExistsComparatorOutputMasking

  Description:
    This template implements the Default variant of the PLIB_CMP_ExistsComparatorOutputMasking function.
*/

#define PLIB_CMP_ExistsComparatorOutputMasking PLIB_CMP_ExistsComparatorOutputMasking
PLIB_TEMPLATE bool CMP_ExistsComparatorOutputMasking_Default( CMP_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  CMP_ComparatorOutputMaskingSetup_Default

  Summary:
    Implements Default variant of PLIB_CMP_ComparatorOutputMaskingSetup 

  Description:
    This template implements the Default variant of the PLIB_CMP_ComparatorOutputMaskingSetup function.
*/

PLIB_TEMPLATE void CMP_ComparatorOutputMaskingSetup_Default( CMP_MODULE_ID index , CMP_OUTPUT_MASK_SOURCE sourceA , 
															 CMP_OUTPUT_MASK_SOURCE sourceB , CMP_OUTPUT_MASK_SOURCE sourceC , 
															 uint32_t logicSettings ,
															 CMP_NON_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT andGatePositiveOutput,
															 CMP_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT andGateNegativeOutput,
														     CMP_OUTPUT_MASKING_LEVEL maskingLevels)
{
	
    volatile cmp_registers_t *cmp = ((cmp_registers_t *)(index));
	
	cmp->CMxMSKCONSET = ((sourceA << _CM1MSKCON_SELSRCA_POSITION) | (sourceB << _CM1MSKCON_SELSRCB_POSITION) | 
					  (sourceC << _CM1MSKCON_SELSRCC_POSITION) | logicSettings | 
					  (andGatePositiveOutput << _CM1MSKCON_PAGS_POSITION) | 
					  (andGateNegativeOutput << _CM2MSKCON_NAGS_POSITION) | 
					  (maskingLevels << _CM1MSKCON_HLMS_POSITION));
	
}


#endif /*_CMP_MASKING_DEFAULT_H*/

/******************************************************************************
 End of File
*/

