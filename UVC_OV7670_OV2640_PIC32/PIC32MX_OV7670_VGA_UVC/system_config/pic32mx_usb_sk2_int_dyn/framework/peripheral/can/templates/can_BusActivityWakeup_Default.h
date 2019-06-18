/*******************************************************************************
  CAN Peripheral Library Template Implementation

  File Name:
    can_BusActivityWakeup_Default.h

  Summary:
    CAN PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : BusActivityWakeup
    and its Variant : Default
    For following APIs :
        PLIB_CAN_BusActivityWakeupEnable
        PLIB_CAN_BusActivityWakeupDisable
        PLIB_CAN_ExistsBusActivityWakeup

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

#ifndef _CAN_BUSACTIVITYWAKEUP_DEFAULT_H
#define _CAN_BUSACTIVITYWAKEUP_DEFAULT_H

#include "../templates/can_registers.h"

//******************************************************************************
/* Function :  CAN_BusActivityWakeupEnable_Default

  Summary:
    Implements Default variant of PLIB_CAN_BusActivityWakeupEnable 

  Description:
    This template implements the Default variant of the PLIB_CAN_BusActivityWakeupEnable function.
*/

PLIB_TEMPLATE void CAN_BusActivityWakeupEnable_Default( CAN_MODULE_ID index )
{
	volatile can_registers_t * can = ((can_registers_t *)(index));
	can->CCFGSET = _C1CFG_WAKFIL_MASK;
}


//******************************************************************************
/* Function :  CAN_BusActivityWakeupDisable_Default

  Summary:
    Implements Default variant of PLIB_CAN_BusActivityWakeupDisable 

  Description:
    This template implements the Default variant of the PLIB_CAN_BusActivityWakeupDisable function.
*/

PLIB_TEMPLATE void CAN_BusActivityWakeupDisable_Default( CAN_MODULE_ID index )
{
	volatile can_registers_t * can = ((can_registers_t *)(index));
	can->CCFGCLR = _C1CFG_WAKFIL_MASK;
}


//******************************************************************************
/* Function :  CAN_ExistsBusActivityWakeup_Default

  Summary:
    Implements Default variant of PLIB_CAN_ExistsBusActivityWakeup

  Description:
    This template implements the Default variant of the PLIB_CAN_ExistsBusActivityWakeup function.
*/

#define PLIB_CAN_ExistsBusActivityWakeup PLIB_CAN_ExistsBusActivityWakeup
PLIB_TEMPLATE bool CAN_ExistsBusActivityWakeup_Default( CAN_MODULE_ID index )
{
    return true;
}


#endif /*_CAN_BUSACTIVITYWAKEUP_DEFAULT_H*/

/******************************************************************************
 End of File
*/

