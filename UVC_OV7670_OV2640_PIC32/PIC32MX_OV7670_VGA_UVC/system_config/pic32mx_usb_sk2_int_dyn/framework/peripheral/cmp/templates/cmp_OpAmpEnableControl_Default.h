/*******************************************************************************
  CMP Peripheral Library Template Implementation

  File Name:
    cmp_OpAmpEnableControl_Default.h

  Summary:
    CMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : OpAmpEnableControl
    and its Variant : Default
    For following APIs :
        PLIB_CMP_ExistsOpAmpEnableControl
        PLIB_CMP_OpAmpEnable
        PLIB_CMP_OpAmpDisable

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

#ifndef _CMP_OPAMPENABLECONTROL_DEFAULT_H
#define _CMP_OPAMPENABLECONTROL_DEFAULT_H

#include "cmp_registers.h"

//******************************************************************************
/* Function :  CMP_ExistsOpAmpEnableControl_Default

  Summary:
    Implements Default variant of PLIB_CMP_ExistsOpAmpEnableControl

  Description:
    This template implements the Default variant of the PLIB_CMP_ExistsOpAmpEnableControl function.
*/

#define PLIB_CMP_ExistsOpAmpEnableControl PLIB_CMP_ExistsOpAmpEnableControl
PLIB_TEMPLATE bool CMP_ExistsOpAmpEnableControl_Default( CMP_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  CMP_OpAmpEnable_Default

  Summary:
    Implements Default variant of PLIB_CMP_OpAmpEnable 

  Description:
    This template implements the Default variant of the PLIB_CMP_OpAmpEnable function.
*/

PLIB_TEMPLATE void CMP_OpAmpEnable_Default( CMP_MODULE_ID index )
{
	volatile cmp_registers_t *cmp = ((cmp_registers_t *)(index));
	
    if( CMP_ID_4 == index )
	{
		PLIB_ASSERT(false, "This instance of Comparator module doesn't support OPAMP features");
	}
	else
	{
	    cmp->CMxCONSET = CMxCON_AMPMOD_MASK;
	}
}


//******************************************************************************
/* Function :  CMP_OpAmpDisable_Default

  Summary:
    Implements Default variant of PLIB_CMP_OpAmpDisable 

  Description:
    This template implements the Default variant of the PLIB_CMP_OpAmpDisable function.
*/

PLIB_TEMPLATE void CMP_OpAmpDisable_Default( CMP_MODULE_ID index )
{
	volatile cmp_registers_t *cmp = ((cmp_registers_t *)(index));
	
    if( CMP_ID_4 == index )
	{
		PLIB_ASSERT(false, "This instance of Comparator module doesn't support OPAMP features");
	}
	else
	{
	    cmp->CMxCONCLR = CMxCON_AMPMOD_MASK;
	}
}


#endif /*_CMP_OPAMPENABLECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

