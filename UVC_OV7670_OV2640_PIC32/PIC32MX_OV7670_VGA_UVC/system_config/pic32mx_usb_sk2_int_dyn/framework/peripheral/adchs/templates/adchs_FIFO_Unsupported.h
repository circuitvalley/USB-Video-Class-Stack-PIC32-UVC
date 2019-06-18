/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_FIFO_Unsupported.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : FIFO
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCHS_FIFORead
        PLIB_ADCHS_FIFODataIsAvailable
        PLIB_ADCHS_FIFODataReadyInterruptEnable
        PLIB_ADCHS_FIFODataReadyInterruptDisable
        PLIB_ADCHS_FIFOEnable
        PLIB_ADCHS_FIFODisable
        PLIB_ADCHS_FIFOSourceSelect
        PLIB_ADCHS_FIFODataCountGet
        PLIB_ADCHS_FIFOSourceGet
        PLIB_ADCHS_FIFOErrorHasOccurred
        PLIB_ADCHS_FIFODataIsNegative
        PLIB_ADCHS_ExistsFIFO

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

#ifndef _ADCHS_FIFO_UNSUPPORTED_H
#define _ADCHS_FIFO_UNSUPPORTED_H

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
/* Function :  ADCHS_FIFORead_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_FIFORead 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_FIFORead function.
*/

PLIB_TEMPLATE int32_t ADCHS_FIFORead_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_FIFORead");

    return (int32_t) 0;
}


//******************************************************************************
/* Function :  ADCHS_FIFODataIsAvailable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_FIFODataIsAvailable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_FIFODataIsAvailable function.
*/

PLIB_TEMPLATE bool ADCHS_FIFODataIsAvailable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_FIFODataIsAvailable");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_FIFODataReadyInterruptEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_FIFODataReadyInterruptEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_FIFODataReadyInterruptEnable function.
*/

PLIB_TEMPLATE void ADCHS_FIFODataReadyInterruptEnable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_FIFODataReadyInterruptEnable");
}


//******************************************************************************
/* Function :  ADCHS_FIFODataReadyInterruptDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_FIFODataReadyInterruptDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_FIFODataReadyInterruptDisable function.
*/

PLIB_TEMPLATE void ADCHS_FIFODataReadyInterruptDisable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_FIFODataReadyInterruptDisable");
}


//******************************************************************************
/* Function :  ADCHS_FIFOEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_FIFOEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_FIFOEnable function.
*/

PLIB_TEMPLATE void ADCHS_FIFOEnable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_FIFOEnable");
}


//******************************************************************************
/* Function :  ADCHS_FIFODisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_FIFODisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_FIFODisable function.
*/

PLIB_TEMPLATE void ADCHS_FIFODisable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_FIFODisable");
}


//******************************************************************************
/* Function :  ADCHS_FIFOSourceSelect_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_FIFOSourceSelect 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_FIFOSourceSelect function.
*/

PLIB_TEMPLATE bool ADCHS_FIFOSourceSelect_Unsupported( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_FIFOSourceSelect");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_FIFODataCountGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_FIFODataCountGet 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_FIFODataCountGet function.
*/

PLIB_TEMPLATE uint8_t ADCHS_FIFODataCountGet_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_FIFODataCountGet");

    return (uint8_t) 0;
}


//******************************************************************************
/* Function :  ADCHS_FIFOSourceGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_FIFOSourceGet 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_FIFOSourceGet function.
*/

PLIB_TEMPLATE ADCHS_CHANNEL_ID ADCHS_FIFOSourceGet_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_FIFOSourceGet");

    return (ADCHS_CHANNEL_ID) 0;
}


//******************************************************************************
/* Function :  ADCHS_FIFOErrorHasOccurred_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_FIFOErrorHasOccurred 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_FIFOErrorHasOccurred function.
*/

PLIB_TEMPLATE bool ADCHS_FIFOErrorHasOccurred_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_FIFOErrorHasOccurred");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_FIFODataIsNegative_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_FIFODataIsNegative 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_FIFODataIsNegative function.
*/

PLIB_TEMPLATE bool ADCHS_FIFODataIsNegative_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_FIFODataIsNegative");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_ExistsFIFO_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ExistsFIFO

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ExistsFIFO function.
*/

PLIB_TEMPLATE bool ADCHS_ExistsFIFO_Unsupported( ADCHS_MODULE_ID index )
{
    return false;
}


#endif /*_ADCHS_FIFO_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

