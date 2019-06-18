/*******************************************************************************
  SQI Peripheral Library Template Implementation

  File Name:
    sqi_InterruptControl_Unsupported.h

  Summary:
    SQI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : InterruptControl
    and its Variant : Unsupported
    For following APIs :
        PLIB_SQI_InterruptEnable
        PLIB_SQI_InterruptDisable
        PLIB_SQI_InterruptDisableAll
        PLIB_SQI_InterruptIsEnabled
        PLIB_SQI_ExistsInterruptControl

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

#ifndef _SQI_INTERRUPTCONTROL_UNSUPPORTED_H
#define _SQI_INTERRUPTCONTROL_UNSUPPORTED_H

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
/* Function :  SQI_InterruptEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_InterruptEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_InterruptEnable function.
*/

PLIB_TEMPLATE void SQI_InterruptEnable_Unsupported( SQI_MODULE_ID index , SQI_INTERRUPTS interruptFlag )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_SQI_InterruptEnable");
}


//******************************************************************************
/* Function :  SQI_InterruptDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_InterruptDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_InterruptDisable function.
*/

PLIB_TEMPLATE void SQI_InterruptDisable_Unsupported( SQI_MODULE_ID index , SQI_INTERRUPTS interruptFlag )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_SQI_InterruptDisable");
}


//******************************************************************************
/* Function :  SQI_InterruptDisableAll_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_InterruptDisableAll 

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_InterruptDisableAll function.
*/

PLIB_TEMPLATE void SQI_InterruptDisableAll_Unsupported( SQI_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_SQI_InterruptDisableAll");
}


//******************************************************************************
/* Function :  SQI_InterruptIsEnabled_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_InterruptIsEnabled 

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_InterruptIsEnabled function.
*/

PLIB_TEMPLATE bool SQI_InterruptIsEnabled_Unsupported( SQI_MODULE_ID index , SQI_INTERRUPTS interruptFlag )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_SQI_InterruptIsEnabled");

    return false;
}


//******************************************************************************
/* Function :  SQI_ExistsInterruptControl_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_ExistsInterruptControl

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_ExistsInterruptControl function.
*/

PLIB_TEMPLATE bool SQI_ExistsInterruptControl_Unsupported( SQI_MODULE_ID index )
{
    return false;
}


#endif /*_SQI_INTERRUPTCONTROL_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

