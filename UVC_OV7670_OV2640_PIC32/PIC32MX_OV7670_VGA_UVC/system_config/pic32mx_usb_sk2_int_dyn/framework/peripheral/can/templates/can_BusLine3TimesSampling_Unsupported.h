/*******************************************************************************
  CAN Peripheral Library Template Implementation

  File Name:
    can_BusLine3TimesSampling_Unsupported.h

  Summary:
    CAN PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : BusLine3TimesSampling
    and its Variant : Unsupported
    For following APIs :
        PLIB_CAN_BusLine3TimesSamplingEnable
        PLIB_CAN_BusLine3TimesSamplingDisable
        PLIB_CAN_ExistsBusLine3TimesSampling

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

#ifndef _CAN_BUSLINE3TIMESSAMPLING_UNSUPPORTED_H
#define _CAN_BUSLINE3TIMESSAMPLING_UNSUPPORTED_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    None.

  MASKs: 
    None.

  POSs: 
    None.

  LENs: 
    None.

*/


//******************************************************************************
/* Function :  CAN_BusLine3TimesSamplingEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_CAN_BusLine3TimesSamplingEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_CAN_BusLine3TimesSamplingEnable function.
*/

PLIB_TEMPLATE void CAN_BusLine3TimesSamplingEnable_Unsupported( CAN_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_CAN_BusLine3TimesSamplingEnable");
}


//******************************************************************************
/* Function :  CAN_BusLine3TimesSamplingDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_CAN_BusLine3TimesSamplingDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_CAN_BusLine3TimesSamplingDisable function.
*/

PLIB_TEMPLATE void CAN_BusLine3TimesSamplingDisable_Unsupported( CAN_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_CAN_BusLine3TimesSamplingDisable");
}


//******************************************************************************
/* Function :  CAN_ExistsBusLine3TimesSampling_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_CAN_ExistsBusLine3TimesSampling

  Description:
    This template implements the Unsupported variant of the PLIB_CAN_ExistsBusLine3TimesSampling function.
*/

PLIB_TEMPLATE bool CAN_ExistsBusLine3TimesSampling_Unsupported( CAN_MODULE_ID index )
{
    return false;
}


#endif /*_CAN_BUSLINE3TIMESSAMPLING_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

