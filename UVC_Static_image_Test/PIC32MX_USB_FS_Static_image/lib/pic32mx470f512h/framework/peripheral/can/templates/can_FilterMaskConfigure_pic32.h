/*******************************************************************************
  CAN Peripheral Library Template Implementation

  File Name:
    can_FilterMaskConfigure_pic32.h

  Summary:
    CAN PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : FilterMaskConfigure
    and its Variant : pic32
    For following APIs :
        PLIB_CAN_FilterMaskConfigure
        PLIB_CAN_ExistsFilterMaskConfigure

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

#ifndef _CAN_FILTERMASKCONFIGURE_PIC32_H
#define _CAN_FILTERMASKCONFIGURE_PIC32_H

#include "../templates/can_registers.h"

//******************************************************************************
/* Function :  CAN_FilterMaskConfigure_pic32

  Summary:
    Implements pic32 variant of PLIB_CAN_FilterMaskConfigure 

  Description:
    This template implements the pic32 variant of the PLIB_CAN_FilterMaskConfigure function.
*/

PLIB_TEMPLATE void CAN_FilterMaskConfigure_pic32( CAN_MODULE_ID index , CAN_FILTER_MASK mask , uint32_t maskbits , CAN_ID_TYPE idType , CAN_FILTER_MASK_TYPE mide )
{
	volatile can_registers_t * can = ((can_registers_t *)(index));
    unsigned int sid;
    unsigned int eid;

    if(idType == CAN_EID)
    {
            /* Extract the sid and eid from the specified id and assign these to
         the register fields. */
        maskbits &= 0x1FFFFFFFu;
        sid = (maskbits & 0x1FFC0000u) >> 18u;
        eid = maskbits & 0x3FFFFu;
		
		can->CRXM[mask].CRXM0.EID = eid;
		can->CRXM[mask].CRXM0.SID = sid;
    }
    else if(idType == CAN_SID)
    {
        maskbits &= 0x7FFu;
		can->CRXM[mask].CRXM0.SID = maskbits;
    }
    else
    {
        /*...*/
    }
    if(mide == CAN_FILTER_MASK_IDE_TYPE)
    {
        /* This means masking will also compare the message type */
		can->CRXM[mask].CRXM0SET = _C1RXM0_MIDE_MASK;
    }
    else if(mide == CAN_FILTER_MASK_ANY_TYPE)
    {
        /* This means any message is masked */
		can->CRXM[mask].CRXM0CLR = _C1RXM0_MIDE_MASK;
    }
    else
    {
        /*...*/
    }
}


//******************************************************************************
/* Function :  CAN_ExistsFilterMaskConfigure_pic32

  Summary:
    Implements pic32 variant of PLIB_CAN_ExistsFilterMaskConfigure

  Description:
    This template implements the pic32 variant of the PLIB_CAN_ExistsFilterMaskConfigure function.
*/

#define PLIB_CAN_ExistsFilterMaskConfigure PLIB_CAN_ExistsFilterMaskConfigure
PLIB_TEMPLATE bool CAN_ExistsFilterMaskConfigure_pic32( CAN_MODULE_ID index )
{
    return true;
}


#endif /*_CAN_FILTERMASKCONFIGURE_PIC32_H*/

/******************************************************************************
 End of File
*/

