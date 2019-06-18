/*******************************************************************************
  SQI Peripheral Library Template Implementation

  File Name:
    sqi_XIPControlWord1_Unsupported.h

  Summary:
    SQI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : XIPControlWord1
    and its Variant : Unsupported
    For following APIs :
        PLIB_SQI_XIPControlWord1Set
        PLIB_SQI_XIPControlWord1Get
        PLIB_SQI_ExistsXIPControlWord1

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _SQI_XIPCONTROLWORD1_UNSUPPORTED_H
#define _SQI_XIPCONTROLWORD1_UNSUPPORTED_H

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
/* Function :  SQI_XIPControlWord1Set_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_XIPControlWord1Set 

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_XIPControlWord1Set function.
*/

PLIB_TEMPLATE void SQI_XIPControlWord1Set_Unsupported( SQI_MODULE_ID   index , SQI_DUMMY_BYTES dummyBytes , SQI_ADDR_BYTES  addressBytes , uint8_t          readOpcode , SQI_LANE_MODE   dataLaneMode , SQI_LANE_MODE   dummyLaneMode , SQI_LANE_MODE   modeCodeLaneMode , SQI_LANE_MODE   addressLaneMode , SQI_LANE_MODE   cmdLaneMode )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_SQI_XIPControlWord1Set");
}


//******************************************************************************
/* Function :  SQI_XIPControlWord1Get_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_XIPControlWord1Get 

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_XIPControlWord1Get function.
*/

PLIB_TEMPLATE uint32_t SQI_XIPControlWord1Get_Unsupported( SQI_MODULE_ID   index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_SQI_XIPControlWord1Get");

    return 0;
}


//******************************************************************************
/* Function :  SQI_ExistsXIPControlWord1_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_ExistsXIPControlWord1

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_ExistsXIPControlWord1 function.
*/

PLIB_TEMPLATE bool SQI_ExistsXIPControlWord1_Unsupported( SQI_MODULE_ID index )
{
    return false;
}


#endif /*_SQI_XIPCONTROLWORD1_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

