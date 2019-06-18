/*******************************************************************************
  CDAC Peripheral Library Template Implementation

  File Name:
    cdac_DataControl_Default.h

  Summary:
    CDAC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DataControl
    and its Variant : Default
    For following APIs :
        PLIB_CDAC_DataRead
        PLIB_CDAC_DataWrite
        PLIB_CDAC_ExistsDataControl

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

#ifndef _CDAC_DATACONTROL_DEFAULT_H
#define _CDAC_DATACONTROL_DEFAULT_H

#include "cdac_registers.h"

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _CDAC_CDAC_DATA_VREG(index)

  MASKs: 
    _CDAC_CDAC_DATA_MASK(index)

  POSs: 
    _CDAC_CDAC_DATA_POS(index)

  LENs: 
    _CDAC_CDAC_DATA_LEN(index)

*/


//******************************************************************************
/* Function :  CDAC_DataRead_Default

  Summary:
    Implements Default variant of PLIB_CDAC_DataRead 

  Description:
    This template implements the Default variant of the PLIB_CDAC_DataRead function.
*/

PLIB_TEMPLATE uint16_t CDAC_DataRead_Default( CDAC_MODULE_ID index )
{
    volatile cdac_registers_t *regs = (cdac_registers_t *)index;

    return (uint16_t)regs->DACxCON.DACDAT;
}


//******************************************************************************
/* Function :  CDAC_DataWrite_Default

  Summary:
    Implements Default variant of PLIB_CDAC_DataWrite 

  Description:
    This template implements the Default variant of the PLIB_CDAC_DataWrite function.
*/

PLIB_TEMPLATE void CDAC_DataWrite_Default( CDAC_MODULE_ID index , uint16_t cdacData )
{
    volatile cdac_registers_t *regs = (cdac_registers_t *)index;

    regs->DACxCON.DACDAT = cdacData;
}


//******************************************************************************
/* Function :  CDAC_ExistsDataControl_Default

  Summary:
    Implements Default variant of PLIB_CDAC_ExistsDataControl

  Description:
    This template implements the Default variant of the PLIB_CDAC_ExistsDataControl function.
*/

#define PLIB_CDAC_ExistsDataControl PLIB_CDAC_ExistsDataControl
PLIB_TEMPLATE bool CDAC_ExistsDataControl_Default( CDAC_MODULE_ID index )
{
    return true;
}


#endif /*_CDAC_DATACONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

