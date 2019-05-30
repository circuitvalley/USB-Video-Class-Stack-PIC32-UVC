/*******************************************************************************
  BMX Peripheral Library Template Implementation

  File Name:
    bmx_DataRamWaitState_Unsupported.h

  Summary:
    BMX PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DataRamWaitState
    and its Variant : Unsupported
    For following APIs :
        PLIB_BMX_ExistsDataRamWaitState
        PLIB_BMX_DataRamWaitStateSet
        PLIB_BMX_DataRamWaitStateGet

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

#ifndef _BMX_DATARAMWAITSTATE_UNSUPPORTED_H
#define _BMX_DATARAMWAITSTATE_UNSUPPORTED_H

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
/* Function :  BMX_ExistsDataRamWaitState_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_BMX_ExistsDataRamWaitState

  Description:
    This template implements the Unsupported variant of the PLIB_BMX_ExistsDataRamWaitState function.
*/

PLIB_TEMPLATE bool BMX_ExistsDataRamWaitState_Unsupported( BMX_MODULE_ID index )
{
    return false;
}


//******************************************************************************
/* Function :  BMX_DataRamWaitStateSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_BMX_DataRamWaitStateSet 

  Description:
    This template implements the Unsupported variant of the PLIB_BMX_DataRamWaitStateSet function.
*/

PLIB_TEMPLATE void BMX_DataRamWaitStateSet_Unsupported( BMX_MODULE_ID index , PLIB_BMX_DATA_RAM_WAIT_STATES wait )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_BMX_DataRamWaitStateSet");
}


//******************************************************************************
/* Function :  BMX_DataRamWaitStateGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_BMX_DataRamWaitStateGet 

  Description:
    This template implements the Unsupported variant of the PLIB_BMX_DataRamWaitStateGet function.
*/

PLIB_TEMPLATE PLIB_BMX_DATA_RAM_WAIT_STATES BMX_DataRamWaitStateGet_Unsupported( BMX_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_BMX_DataRamWaitStateGet");

    return 0;
}


#endif /*_BMX_DATARAMWAITSTATE_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

