/*******************************************************************************
  CAN Peripheral Library Template Implementation

  File Name:
    can_ChannelUpdate_pic32.h

  Summary:
    CAN PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ChannelUpdate
    and its Variant : pic32
    For following APIs :
        PLIB_CAN_ChannelUpdate
        PLIB_CAN_ExistsChannelUpdate

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

#ifndef _CAN_CHANNELUPDATE_PIC32_H
#define _CAN_CHANNELUPDATE_PIC32_H

#include "../templates/can_registers.h"

//******************************************************************************
/* Function :  CAN_ChannelUpdate_pic32

  Summary:
    Implements pic32 variant of PLIB_CAN_ChannelUpdate 

  Description:
    This template implements the pic32 variant of the PLIB_CAN_ChannelUpdate function.
*/

PLIB_TEMPLATE void CAN_ChannelUpdate_pic32( CAN_MODULE_ID index , CAN_CHANNEL channel )
{
	volatile can_registers_t * can = ((can_registers_t *)(index));

    PLIB_ASSERT( (channel  <= CAN_CHANNEL31),   "Channel number more than limit" );
	
	can->CFIFOREG[channel].CFIFOCON0SET = _C1FIFOCON1_UINC_MASK;
}


//******************************************************************************
/* Function :  CAN_ExistsChannelUpdate_pic32

  Summary:
    Implements pic32 variant of PLIB_CAN_ExistsChannelUpdate

  Description:
    This template implements the pic32 variant of the PLIB_CAN_ExistsChannelUpdate function.
*/

#define PLIB_CAN_ExistsChannelUpdate PLIB_CAN_ExistsChannelUpdate
PLIB_TEMPLATE bool CAN_ExistsChannelUpdate_pic32( CAN_MODULE_ID index )
{
    return true;
}


#endif /*_CAN_CHANNELUPDATE_PIC32_H*/

/******************************************************************************
 End of File
*/

