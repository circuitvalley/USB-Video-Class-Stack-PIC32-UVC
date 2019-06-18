/*******************************************************************************
  CAN Peripheral Library Template Implementation

  File Name:
    can_BusSpeed_Unsupported.h

  Summary:
    CAN PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : BusSpeed
    and its Variant : Unsupported
    For following APIs :
        PLIB_CAN_PrecalculatedBitRateSetup
        PLIB_CAN_ExistsPrecalculatedBitRateSetup
        PLIB_CAN_BitSamplePhaseSet
        PLIB_CAN_ExistsBitSamplePhaseSet
        PLIB_CAN_BaudRatePrescaleSetup
        PLIB_CAN_ExistsBaudRatePrescaleSetup
        PLIB_CAN_BaudRateGet
        PLIB_CAN_ExistsBaudRateGet

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

#ifndef _CAN_BUSSPEED_UNSUPPORTED_H
#define _CAN_BUSSPEED_UNSUPPORTED_H

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
/* Function :  CAN_PrecalculatedBitRateSetup_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_CAN_PrecalculatedBitRateSetup 

  Description:
    This template implements the Unsupported variant of the PLIB_CAN_PrecalculatedBitRateSetup function.
*/

PLIB_TEMPLATE bool CAN_PrecalculatedBitRateSetup_Unsupported( CAN_MODULE_ID  index , uint8_t        prescale , uint8_t        syncjumpWidth , uint8_t        propagation , uint8_t        segment1 , uint8_t        segment2 )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_CAN_PrecalculatedBitRateSetup");

    return false;
}


//******************************************************************************
/* Function :  CAN_ExistsPrecalculatedBitRateSetup_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_CAN_ExistsPrecalculatedBitRateSetup

  Description:
    This template implements the Unsupported variant of the PLIB_CAN_ExistsPrecalculatedBitRateSetup function.
*/

PLIB_TEMPLATE bool CAN_ExistsPrecalculatedBitRateSetup_Unsupported( CAN_MODULE_ID index )
{
    return false;
}


//******************************************************************************
/* Function :  CAN_BitSamplePhaseSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_CAN_BitSamplePhaseSet 

  Description:
    This template implements the Unsupported variant of the PLIB_CAN_BitSamplePhaseSet function.
*/

PLIB_TEMPLATE bool CAN_BitSamplePhaseSet_Unsupported( CAN_MODULE_ID   index , uint8_t         syncJumpWidth , uint8_t         propagation , uint8_t         segment1 , uint8_t         segment2 )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_CAN_BitSamplePhaseSet");

    return false;
}


//******************************************************************************
/* Function :  CAN_ExistsBitSamplePhaseSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_CAN_ExistsBitSamplePhaseSet

  Description:
    This template implements the Unsupported variant of the PLIB_CAN_ExistsBitSamplePhaseSet function.
*/

PLIB_TEMPLATE bool CAN_ExistsBitSamplePhaseSet_Unsupported( CAN_MODULE_ID index )
{
    return false;
}


//******************************************************************************
/* Function :  CAN_BaudRatePrescaleSetup_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_CAN_BaudRatePrescaleSetup 

  Description:
    This template implements the Unsupported variant of the PLIB_CAN_BaudRatePrescaleSetup function.
*/

PLIB_TEMPLATE bool CAN_BaudRatePrescaleSetup_Unsupported( CAN_MODULE_ID index , uint16_t prescale )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_CAN_BaudRatePrescaleSetup");

    return false;
}


//******************************************************************************
/* Function :  CAN_ExistsBaudRatePrescaleSetup_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_CAN_ExistsBaudRatePrescaleSetup

  Description:
    This template implements the Unsupported variant of the PLIB_CAN_ExistsBaudRatePrescaleSetup function.
*/

PLIB_TEMPLATE bool CAN_ExistsBaudRatePrescaleSetup_Unsupported( CAN_MODULE_ID index )
{
    return false;
}


//******************************************************************************
/* Function :  CAN_BaudRateGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_CAN_BaudRateGet 

  Description:
    This template implements the Unsupported variant of the PLIB_CAN_BaudRateGet function.
*/

PLIB_TEMPLATE uint32_t CAN_BaudRateGet_Unsupported( CAN_MODULE_ID index , uint32_t sysclock )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_CAN_BaudRateGet");

    return 0;
}


//******************************************************************************
/* Function :  CAN_ExistsBaudRateGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_CAN_ExistsBaudRateGet

  Description:
    This template implements the Unsupported variant of the PLIB_CAN_ExistsBaudRateGet function.
*/

PLIB_TEMPLATE bool CAN_ExistsBaudRateGet_Unsupported( CAN_MODULE_ID index )
{
    return false;
}


#endif /*_CAN_BUSSPEED_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

