/*******************************************************************************
  SQI Peripheral Library Template Implementation

  File Name:
    sqi_InterruptStatus_Unsupported.h

  Summary:
    SQI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : InterruptStatus
    and its Variant : Unsupported
    For following APIs :
        PLIB_SQI_InterruptFlagGet
        PLIB_SQI_InterruptWordGet
        PLIB_SQI_InterruptWordClear
        PLIB_SQI_ExistsInterruptStatus

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

#ifndef _SQI_INTERRUPTSTATUS_UNSUPPORTED_H
#define _SQI_INTERRUPTSTATUS_UNSUPPORTED_H

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
/* Function :  SQI_InterruptFlagGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_InterruptFlagGet 

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_InterruptFlagGet function.
*/

PLIB_TEMPLATE bool SQI_InterruptFlagGet_Unsupported( SQI_MODULE_ID index , SQI_INTERRUPTS interruptFlag )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_SQI_InterruptFlagGet");

    return false;
}


//******************************************************************************
/* Function :  SQI_InterruptWordGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_InterruptWordGet 

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_InterruptWordGet function.
*/

PLIB_TEMPLATE uint32_t SQI_InterruptWordGet_Unsupported( SQI_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_SQI_InterruptWordGet");

    return (uint32_t) 0;
}


//******************************************************************************
/* Function :  SQI_InterruptWordClear_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_InterruptWordClear 

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_InterruptWordClear function.
*/

PLIB_TEMPLATE void SQI_InterruptWordClear_Unsupported( SQI_MODULE_ID index , uint32_t flags )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_SQI_InterruptWordClear");
}


//******************************************************************************
/* Function :  SQI_ExistsInterruptStatus_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_ExistsInterruptStatus

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_ExistsInterruptStatus function.
*/

PLIB_TEMPLATE bool SQI_ExistsInterruptStatus_Unsupported( SQI_MODULE_ID index )
{
    return false;
}


#endif /*_SQI_INTERRUPTSTATUS_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

