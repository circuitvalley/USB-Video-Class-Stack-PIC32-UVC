/*******************************************************************************
  CMP Peripheral Library Template Implementation

  File Name:
    cmp_OpAmpOutputEnableControl_Default.h

  Summary:
    CMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : OpAmpOutputEnableControl
    and its Variant : Default
    For following APIs :
        PLIB_CMP_ExistsOpAmpOutputControl
        PLIB_CMP_OpAmpOutputEnable
        PLIB_CMP_OpAmpOutputDisable

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

#ifndef _CMP_OPAMPOUTPUTENABLECONTROL_DEFAULT_H
#define _CMP_OPAMPOUTPUTENABLECONTROL_DEFAULT_H

#include "cmp_registers.h"

//******************************************************************************
/* Function :  CMP_ExistsOpAmpOutputControl_Default

  Summary:
    Implements Default variant of PLIB_CMP_ExistsOpAmpOutputControl

  Description:
    This template implements the Default variant of the PLIB_CMP_ExistsOpAmpOutputControl function.
*/

#define PLIB_CMP_ExistsOpAmpOutputControl PLIB_CMP_ExistsOpAmpOutputControl
PLIB_TEMPLATE bool CMP_ExistsOpAmpOutputControl_Default( CMP_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  CMP_OpAmpOutputEnable_Default

  Summary:
    Implements Default variant of PLIB_CMP_OpAmpOutputEnable 

  Description:
    This template implements the Default variant of the PLIB_CMP_OpAmpOutputEnable function.
*/

PLIB_TEMPLATE void CMP_OpAmpOutputEnable_Default( CMP_MODULE_ID index )
{
	volatile cmp_registers_t *cmp = ((cmp_registers_t *)(index));
	
    if( CMP_ID_4 == index )
	{
		PLIB_ASSERT(false, "This instance of Comparator module doesn't support OPAMP features");
	}
	else
	{
	    cmp->CMxCONSET = CMxCON_OAO_MASK;
	}
}


//******************************************************************************
/* Function :  CMP_OpAmpOutputDisable_Default

  Summary:
    Implements Default variant of PLIB_CMP_OpAmpOutputDisable 

  Description:
    This template implements the Default variant of the PLIB_CMP_OpAmpOutputDisable function.
*/

PLIB_TEMPLATE void CMP_OpAmpOutputDisable_Default( CMP_MODULE_ID index )
{
	volatile cmp_registers_t *cmp = ((cmp_registers_t *)(index));
	
    if( CMP_ID_4 == index )
	{
		PLIB_ASSERT(false, "This instance of Comparator module doesn't support OPAMP features");
	}
	else
	{
	    cmp->CMxCONCLR = CMxCON_OAO_MASK;
	}
}


#endif /*_CMP_OPAMPOUTPUTENABLECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

