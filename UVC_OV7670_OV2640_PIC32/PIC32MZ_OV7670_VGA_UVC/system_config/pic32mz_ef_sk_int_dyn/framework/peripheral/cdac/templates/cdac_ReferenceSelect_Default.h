/*******************************************************************************
  CDAC Peripheral Library Template Implementation

  File Name:
    cdac_ReferenceSelect_Default.h

  Summary:
    CDAC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ReferenceSelect
    and its Variant : Default
    For following APIs :
        PLIB_CDAC_ReferenceVoltageSelect
        PLIB_CDAC_ExistsReferenceVoltageSelect

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

#ifndef _CDAC_REFERENCESELECT_DEFAULT_H
#define _CDAC_REFERENCESELECT_DEFAULT_H

#include "cdac_registers.h"

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _CDAC_REFERENCE_SELECT_VREG(index)

  MASKs: 
    _CDAC_REFERENCE_SELECT_MASK(index)

  POSs: 
    _CDAC_REFERENCE_SELECT_POS(index)

  LENs: 
    _CDAC_REFERENCE_SELECT_LEN(index)

*/


//******************************************************************************
/* Function :  CDAC_ReferenceVoltageSelect_Default

  Summary:
    Implements Default variant of PLIB_CDAC_ReferenceVoltageSelect 

  Description:
    This template implements the Default variant of the PLIB_CDAC_ReferenceVoltageSelect function.
*/

PLIB_TEMPLATE void CDAC_ReferenceVoltageSelect_Default( CDAC_MODULE_ID index , CDAC_REF_SEL refSel )
{
    volatile cdac_registers_t *regs = (cdac_registers_t *)index;

    regs->DACxCON.REFSEL = refSel;
}


//******************************************************************************
/* Function :  CDAC_ExistsReferenceVoltageSelect_Default

  Summary:
    Implements Default variant of PLIB_CDAC_ExistsReferenceVoltageSelect

  Description:
    This template implements the Default variant of the PLIB_CDAC_ExistsReferenceVoltageSelect function.
*/

#define PLIB_CDAC_ExistsReferenceVoltageSelect PLIB_CDAC_ExistsReferenceVoltageSelect
PLIB_TEMPLATE bool CDAC_ExistsReferenceVoltageSelect_Default( CDAC_MODULE_ID index )
{
    return true;
}


#endif /*_CDAC_REFERENCESELECT_DEFAULT_H*/

/******************************************************************************
 End of File
*/

