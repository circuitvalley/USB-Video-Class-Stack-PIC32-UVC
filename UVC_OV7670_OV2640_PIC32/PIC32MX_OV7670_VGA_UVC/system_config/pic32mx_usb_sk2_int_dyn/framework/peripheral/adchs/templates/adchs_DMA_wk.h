/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_DMA_wk.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DMA
    and its Variant : wk
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

#ifndef _ADCHS_DMA_WK_H
#define _ADCHS_DMA_WK_H



//******************************************************************************
/* Function :  ADCHS_DMAEnable_wk

  Summary:
    Implements wk variant of PLIB_ADCHS_DMAEnable 

  Description:
    This template implements the wk variant of the PLIB_ADCHS_DMAEnable function.
*/

PLIB_TEMPLATE void ADCHS_DMAEnable_wk( ADCHS_MODULE_ID index )
{
	volatile adchs_register_t *regs = (adchs_register_t *)index;
	
	regs->ADCDMAST.DMAEN = 1;
}


//******************************************************************************
/* Function :  ADCHS_DMADisable_wk

  Summary:
    Implements wk variant of PLIB_ADCHS_DMADisable 

  Description:
    This template implements the wk variant of the PLIB_ADCHS_DMADisable function.
*/

PLIB_TEMPLATE void ADCHS_DMADisable_wk( ADCHS_MODULE_ID index )
{
	volatile adchs_register_t *regs = (adchs_register_t *)index;
	
	regs->ADCDMAST.DMAEN = 0;
}


//******************************************************************************
/* Function :  ADCHS_DMASetup_wk

  Summary:
    Implements wk variant of PLIB_ADCHS_DMASetup 

  Description:
    This template implements the wk variant of the PLIB_ADCHS_DMASetup function.
*/

PLIB_TEMPLATE void ADCHS_DMASetup_wk( ADCHS_MODULE_ID index , ADCHS_DMA_BUFFER_LENGTH bufferLengthBytes , uint32_t baseAddress , ADCHS_DMA_COUNT countMode , uint32_t countBaseAddress )
{
	volatile adchs_register_t *regs = (adchs_register_t *)index;
	
	regs->ADCCON1.DMABL = bufferLengthBytes;
	regs->ADCDMAB = baseAddress;
	regs->ADCCNTB = countBaseAddress;
	regs->ADCDMAST.DMACNTEN = countMode;
}


//******************************************************************************
/* Function :  ADCHS_DMASourceSelect_wk

  Summary:
    Implements wk variant of PLIB_ADCHS_DMASourceSelect 

  Description:
    This template implements the wk variant of the PLIB_ADCHS_DMASourceSelect function.
*/

PLIB_TEMPLATE bool ADCHS_DMASourceSelect_wk( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
	volatile adchs_register_t *regs = (adchs_register_t *)index;
	
	if(channelID > ADCHS_CHANNEL_0)
		return false;
	
	regs->ADCxTIME[channelID].ADCxTIME = 1 << _ADC0TIME_BCHEN0_POSITION;
	
	return true;
}


//******************************************************************************
/* Function :  ADCHS_DMASourceRemove_wk

  Summary:
    Implements wk variant of PLIB_ADCHS_DMASourceRemove 

  Description:
    This template implements the wk variant of the PLIB_ADCHS_DMASourceRemove function.
*/

PLIB_TEMPLATE bool ADCHS_DMASourceRemove_wk( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
	volatile adchs_register_t *regs = (adchs_register_t *)index;
	
	if(channelID > ADCHS_CHANNEL_0)
		return false;
	
    regs->ADCxTIME[channelID].ADCxTIME &= ~(1 << _ADC0TIME_BCHEN0_POSITION);
	
	return true;
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_A_InterruptEnable_wk

  Summary:
    Implements wk variant of PLIB_ADCHS_DMABuffer_A_InterruptEnable 

  Description:
    This template implements the wk variant of the PLIB_ADCHS_DMABuffer_A_InterruptEnable function.
*/

PLIB_TEMPLATE bool ADCHS_DMABuffer_A_InterruptEnable_wk( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
	volatile adchs_register_t *regs = (adchs_register_t *)index;
	if(channelID > ADCHS_CHANNEL_0)
		return false;
	
    regs->ADCDMAST.RAF0IEN = 1;
	
	return true;
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_A_InterruptDisable_wk

  Summary:
    Implements wk variant of PLIB_ADCHS_DMABuffer_A_InterruptDisable 

  Description:
    This template implements the wk variant of the PLIB_ADCHS_DMABuffer_A_InterruptDisable function.
*/

PLIB_TEMPLATE bool ADCHS_DMABuffer_A_InterruptDisable_wk( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
	volatile adchs_register_t *regs = (adchs_register_t *)index;
	if(channelID > ADCHS_CHANNEL_0)
		return false;
	
	regs->ADCDMAST.RAF0IEN = 0;
	
	return true;
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_B_InterruptEnable_wk

  Summary:
    Implements wk variant of PLIB_ADCHS_DMABuffer_B_InterruptEnable 

  Description:
    This template implements the wk variant of the PLIB_ADCHS_DMABuffer_B_InterruptEnable function.
*/

PLIB_TEMPLATE bool ADCHS_DMABuffer_B_InterruptEnable_wk( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
	volatile adchs_register_t *regs = (adchs_register_t *)index;
	if(channelID > ADCHS_CHANNEL_0)
		return false;
	
	regs->ADCDMAST.RBF0IEN = 1;
	
	return true;
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_B_InterruptDisable_wk

  Summary:
    Implements wk variant of PLIB_ADCHS_DMABuffer_B_InterruptDisable 

  Description:
    This template implements the wk variant of the PLIB_ADCHS_DMABuffer_B_InterruptDisable function.
*/

PLIB_TEMPLATE bool ADCHS_DMABuffer_B_InterruptDisable_wk( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
	volatile adchs_register_t *regs = (adchs_register_t *)index;
	if(channelID > ADCHS_CHANNEL_0)
		return false;
	
	regs->ADCDMAST.RBF0IEN = 0;
	
	return true;
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_A_IsFull_wk

  Summary:
    Implements wk variant of PLIB_ADCHS_DMABuffer_A_IsFull 

  Description:
    This template implements the wk variant of the PLIB_ADCHS_DMABuffer_A_IsFull function.
*/

PLIB_TEMPLATE int8_t ADCHS_DMABuffer_A_IsFull_wk( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
	volatile adchs_register_t *regs = (adchs_register_t *)index;
    return (int8_t) regs->ADCDMAST.RAF0;
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_B_IsFull_wk

  Summary:
    Implements wk variant of PLIB_ADCHS_DMABuffer_B_IsFull 

  Description:
    This template implements the wk variant of the PLIB_ADCHS_DMABuffer_B_IsFull function.
*/

PLIB_TEMPLATE int8_t ADCHS_DMABuffer_B_IsFull_wk( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
	volatile adchs_register_t *regs = (adchs_register_t *)index;
    return (int8_t) regs->ADCDMAST.RBF0;
}


//******************************************************************************
/* Function :  ADCHS_DMAOverflowErrorHasOccurred_wk

  Summary:
    Implements wk variant of PLIB_ADCHS_DMAOverflowErrorHasOccurred 

  Description:
    This template implements the wk variant of the PLIB_ADCHS_DMAOverflowErrorHasOccurred function.
*/

PLIB_TEMPLATE bool ADCHS_DMAOverflowErrorHasOccurred_wk( ADCHS_MODULE_ID index )
{
	volatile adchs_register_t *regs = (adchs_register_t *)index;
    return (bool) regs->ADCDMAST.WROVRERR;
}


//******************************************************************************
/* Function :  ADCHS_ExistsDMA_wk

  Summary:
    Implements wk variant of PLIB_ADCHS_ExistsDMA

  Description:
    This template implements the wk variant of the PLIB_ADCHS_ExistsDMA function.
*/

#define PLIB_ADCHS_ExistsDMA PLIB_ADCHS_ExistsDMA
PLIB_TEMPLATE bool ADCHS_ExistsDMA_wk( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_DMA_WK_H*/

/******************************************************************************
 End of File
*/

