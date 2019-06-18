/*******************************************************************************
  CDAC Peripheral Library Template Implementation

  File Name:
    cdac_EnableControl_Default.h

  Summary:
    CDAC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EnableControl
    and its Variant : Default
    For following APIs :
        PLIB_CDAC_Enable
        PLIB_CDAC_Disable
        PLIB_CDAC_ExistsEnableControl

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

#ifndef _CDAC_ENABLECONTROL_DEFAULT_H
#define _CDAC_ENABLECONTROL_DEFAULT_H

#include "cdac_registers.h"
//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _CDAC_ENABLE_CONTROL_VREG(index)

  MASKs: 
    _CDAC_ENABLE_CONTROL_MASK(index)

  POSs: 
    _CDAC_ENABLE_CONTROL_POS(index)

  LENs: 
    _CDAC_ENABLE_CONTROL_LEN(index)

*/


//******************************************************************************
/* Function :  CDAC_Enable_Default

  Summary:
    Implements Default variant of PLIB_CDAC_Enable 

  Description:
    This template implements the Default variant of the PLIB_CDAC_Enable function.
*/

PLIB_TEMPLATE void CDAC_Enable_Default( CDAC_MODULE_ID index )
{
    volatile cdac_registers_t *regs = (cdac_registers_t *)index;

    regs->DACxCONSET = _DAC1CON_ON_MASK;
}


//******************************************************************************
/* Function :  CDAC_Disable_Default

  Summary:
    Implements Default variant of PLIB_CDAC_Disable 

  Description:
    This template implements the Default variant of the PLIB_CDAC_Disable function.
*/

PLIB_TEMPLATE void CDAC_Disable_Default( CDAC_MODULE_ID index )
{
    volatile cdac_registers_t *regs = (cdac_registers_t *)index;

    regs->DACxCONCLR = _DAC1CON_ON_MASK;
}


//******************************************************************************
/* Function :  CDAC_ExistsEnableControl_Default

  Summary:
    Implements Default variant of PLIB_CDAC_ExistsEnableControl

  Description:
    This template implements the Default variant of the PLIB_CDAC_ExistsEnableControl function.
*/

#define PLIB_CDAC_ExistsEnableControl PLIB_CDAC_ExistsEnableControl
PLIB_TEMPLATE bool CDAC_ExistsEnableControl_Default( CDAC_MODULE_ID index )
{
    return true;
}


#endif /*_CDAC_ENABLECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

