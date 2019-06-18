/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_DMA_Unsupported.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DMA
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCHS_DMAEnable
        PLIB_ADCHS_DMADisable
        PLIB_ADCHS_DMASetup
        PLIB_ADCHS_DMASourceSelect
        PLIB_ADCHS_DMASourceRemove
        PLIB_ADCHS_DMABuffer_A_InterruptEnable
        PLIB_ADCHS_DMABuffer_A_InterruptDisable
        PLIB_ADCHS_DMABuffer_B_InterruptEnable
        PLIB_ADCHS_DMABuffer_B_InterruptDisable
        PLIB_ADCHS_DMABuffer_A_IsFull
        PLIB_ADCHS_DMABuffer_B_IsFull
        PLIB_ADCHS_DMAOverflowErrorHasOccurred
        PLIB_ADCHS_ExistsDMA

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

#ifndef _ADCHS_DMA_UNSUPPORTED_H
#define _ADCHS_DMA_UNSUPPORTED_H

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
/* Function :  ADCHS_DMAEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DMAEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DMAEnable function.
*/

PLIB_TEMPLATE void ADCHS_DMAEnable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DMAEnable");
}


//******************************************************************************
/* Function :  ADCHS_DMADisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DMADisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DMADisable function.
*/

PLIB_TEMPLATE void ADCHS_DMADisable_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DMADisable");
}


//******************************************************************************
/* Function :  ADCHS_DMASetup_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DMASetup 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DMASetup function.
*/

PLIB_TEMPLATE void ADCHS_DMASetup_Unsupported( ADCHS_MODULE_ID index , ADCHS_DMA_BUFFER_LENGTH bufferLengthBytes , uint32_t baseAddress , ADCHS_DMA_COUNT countMode , uint32_t countBaseAddress )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DMASetup");
}


//******************************************************************************
/* Function :  ADCHS_DMASourceSelect_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DMASourceSelect 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DMASourceSelect function.
*/

PLIB_TEMPLATE bool ADCHS_DMASourceEnable_Unsupported( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DMASourceSelect");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_DMASourceRemove_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DMASourceRemove 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DMASourceRemove function.
*/

PLIB_TEMPLATE bool ADCHS_DMASourceDisable_Unsupported( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DMASourceRemove");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_A_InterruptEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DMABuffer_A_InterruptEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DMABuffer_A_InterruptEnable function.
*/

PLIB_TEMPLATE bool ADCHS_DMABuffer_A_InterruptEnable_Unsupported( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DMABuffer_A_InterruptEnable");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_A_InterruptDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DMABuffer_A_InterruptDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DMABuffer_A_InterruptDisable function.
*/

PLIB_TEMPLATE bool ADCHS_DMABuffer_A_InterruptDisable_Unsupported( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DMABuffer_A_InterruptDisable");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_B_InterruptEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DMABuffer_B_InterruptEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DMABuffer_B_InterruptEnable function.
*/

PLIB_TEMPLATE bool ADCHS_DMABuffer_B_InterruptEnable_Unsupported( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DMABuffer_B_InterruptEnable");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_B_InterruptDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DMABuffer_B_InterruptDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DMABuffer_B_InterruptDisable function.
*/

PLIB_TEMPLATE bool ADCHS_DMABuffer_B_InterruptDisable_Unsupported( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DMABuffer_B_InterruptDisable");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_A_IsFull_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DMABuffer_A_IsFull 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DMABuffer_A_IsFull function.
*/

PLIB_TEMPLATE int8_t ADCHS_DMABuffer_A_IsFull_Unsupported( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DMABuffer_A_IsFull");

    return 0;
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_B_IsFull_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DMABuffer_B_IsFull 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DMABuffer_B_IsFull function.
*/

PLIB_TEMPLATE int8_t ADCHS_DMABuffer_B_IsFull_Unsupported( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DMABuffer_B_IsFull");

    return 0;
}


//******************************************************************************
/* Function :  ADCHS_DMAOverflowErrorHasOccurred_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_DMAOverflowErrorHasOccurred 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_DMAOverflowErrorHasOccurred function.
*/

PLIB_TEMPLATE bool ADCHS_DMAOverflowErrorHasOccurred_Unsupported( ADCHS_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_DMAOverflowErrorHasOccurred");

    return false;
}


//******************************************************************************
/* Function :  ADCHS_ExistsDMA_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ExistsDMA

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ExistsDMA function.
*/

PLIB_TEMPLATE bool ADCHS_ExistsDMA_Unsupported( ADCHS_MODULE_ID index )
{
    return false;
}


#endif /*_ADCHS_DMA_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

