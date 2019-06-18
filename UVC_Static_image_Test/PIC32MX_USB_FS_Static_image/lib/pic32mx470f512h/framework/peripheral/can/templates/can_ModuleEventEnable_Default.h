/*******************************************************************************
  CAN Peripheral Library Template Implementation

  File Name:
    can_ModuleEventEnable_Default.h

  Summary:
    CAN PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ModuleEventEnable
    and its Variant : Default
    For following APIs :
        PLIB_CAN_ModuleEventEnable
        PLIB_CAN_ModuleEventDisable
        PLIB_CAN_ExistsModuleEventEnable

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _CAN_MODULEEVENTENABLE_DEFAULT_H
#define _CAN_MODULEEVENTENABLE_DEFAULT_H

#include "../templates/can_registers.h"

//******************************************************************************
/* Function :  CAN_ModuleEventEnable_Default

  Summary:
    Implements Default variant of PLIB_CAN_ModuleEventEnable 

  Description:
    This template implements the Default variant of the PLIB_CAN_ModuleEventEnable function.
*/

PLIB_TEMPLATE void CAN_ModuleEventEnable_Default( CAN_MODULE_ID index , CAN_MODULE_EVENT flags )
{
	volatile can_registers_t * can = ((can_registers_t *)(index));
	uint32_t mask =  CAN_All_EVENTS << _C1INT_TBIE_POSITION;
	can->CINTSET = ( (can->CINT.w & ~(mask)) | ( (mask) & ((flags) << _C1INT_TBIE_POSITION)) );
}


//******************************************************************************
/* Function :  CAN_ModuleEventDisable_Default

  Summary:
    Implements Default variant of PLIB_CAN_ModuleEventDisable 

  Description:
    This template implements the Default variant of the PLIB_CAN_ModuleEventDisable function.
*/

PLIB_TEMPLATE void CAN_ModuleEventDisable_Default( CAN_MODULE_ID index , CAN_MODULE_EVENT flags )
{
	volatile can_registers_t * can = ((can_registers_t *)(index));
	can->CINTCLR =  ((flags) << _C1INT_TBIE_POSITION);
}


//******************************************************************************
/* Function :  CAN_ExistsModuleEventEnable_Default

  Summary:
    Implements Default variant of PLIB_CAN_ExistsModuleEventEnable

  Description:
    This template implements the Default variant of the PLIB_CAN_ExistsModuleEventEnable function.
*/

#define PLIB_CAN_ExistsModuleEventEnable PLIB_CAN_ExistsModuleEventEnable
PLIB_TEMPLATE bool CAN_ExistsModuleEventEnable_Default( CAN_MODULE_ID index )
{
    return true;
}


#endif /*_CAN_MODULEEVENTENABLE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

