/*******************************************************************************
  CAN Peripheral Library Template Implementation

  File Name:
    can_FilterConfigure_pic32.h

  Summary:
    CAN PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : FilterConfigure
    and its Variant : pic32
    For following APIs :
        PLIB_CAN_FilterConfigure
        PLIB_CAN_ExistsFilterConfigure

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

#ifndef _CAN_FILTERCONFIGURE_PIC32_H
#define _CAN_FILTERCONFIGURE_PIC32_H

#include "../templates/can_registers.h"

//******************************************************************************
/* Function :  CAN_FilterConfigure_pic32

  Summary:
    Implements pic32 variant of PLIB_CAN_FilterConfigure 

  Description:
    This template implements the pic32 variant of the PLIB_CAN_FilterConfigure function.
*/

PLIB_TEMPLATE void CAN_FilterConfigure_pic32( CAN_MODULE_ID index , CAN_FILTER filter , uint32_t id , CAN_ID_TYPE filterType )
{
	volatile can_registers_t * can = ((can_registers_t *)(index));
    unsigned int sid;
    unsigned int eid;
    PLIB_ASSERT( (filter  <= CAN_FILTER31),   "Filter number more than Maximum" );

    if(filterType == CAN_EID)
    {
        /* An extended ID filter has a 29 bit id. The most significant 11 bits are the SID
          and the rest of the 18 bits are EID. */
        id &= 0x1FFFFFFFu;
        sid = (id & 0x1FFC0000u) >> 18u;
        eid = id & 0x3FFFFu;

		can->CRXF[filter].CRXF1.EID = eid;
		can->CRXF[filter].CRXF1.SID = sid;
		can->CRXF[filter].CRXF1SET = _C1RXF0_EXID_MASK;
    }
    else
    {
        /* An standard ID has 11 bits. */
        id &= 0x7FFu;
		can->CRXF[filter].CRXF1.SID = id;
		can->CRXF[filter].CRXF1CLR = _C1RXF0_EXID_MASK;
    }
}


//******************************************************************************
/* Function :  CAN_ExistsFilterConfigure_pic32

  Summary:
    Implements pic32 variant of PLIB_CAN_ExistsFilterConfigure

  Description:
    This template implements the pic32 variant of the PLIB_CAN_ExistsFilterConfigure function.
*/

#define PLIB_CAN_ExistsFilterConfigure PLIB_CAN_ExistsFilterConfigure
PLIB_TEMPLATE bool CAN_ExistsFilterConfigure_pic32( CAN_MODULE_ID index )
{
    return true;
}


#endif /*_CAN_FILTERCONFIGURE_PIC32_H*/

/******************************************************************************
 End of File
*/

