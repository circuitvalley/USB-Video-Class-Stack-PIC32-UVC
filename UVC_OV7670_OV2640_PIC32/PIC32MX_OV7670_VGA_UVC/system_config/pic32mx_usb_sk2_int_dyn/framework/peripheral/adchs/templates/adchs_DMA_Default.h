/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_DMA_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DMA
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_DMAEnable
        PLIB_ADCHS_DMADisable
        PLIB_ADCHS_DMASetup
        PLIB_ADCHS_DMASourceEnable
        PLIB_ADCHS_DMASourceDisable
        PLIB_ADCHS_DMABuffer_A_InterruptEnable
        PLIB_ADCHS_DMABuffer_A_InterruptDisable
        PLIB_ADCHS_DMABuffer_B_InterruptEnable
        PLIB_ADCHS_DMABuffer_B_InterruptDisable
        PLIB_ADCHS_DMABuffer_B_IsFull
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

#ifndef _ADCHS_DMA_DEFAULT_H
#define _ADCHS_DMA_DEFAULT_H

//******************************************************************************
/* Function :  ADCHS_DMAEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DMAEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DMAEnable function.
*/

PLIB_TEMPLATE void ADCHS_DMAEnable_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCDSTAT.bits.DMAEN = 1;
}


//******************************************************************************
/* Function :  ADCHS_DMADisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DMADisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DMADisable function.
*/

PLIB_TEMPLATE void ADCHS_DMADisable_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCDSTAT.bits.DMAEN = 0;
}


//******************************************************************************
/* Function :  ADCHS_DMASetup_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DMASetup 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DMASetup function.
*/

PLIB_TEMPLATE void ADCHS_DMASetup_Default( ADCHS_MODULE_ID index , ADCHS_DMA_BUFFER_LENGTH bufferLengthBytes , uint32_t baseAddress , ADCHS_DMA_COUNT countMode , uint32_t countBaseAddress )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCDSTAT.bits.DMACEN = countMode;
    regs->ADCCON1.DMABL = bufferLengthBytes;  
    regs->ADCDMAB.bits = baseAddress;
    regs->ADCCNTB.bits = countBaseAddress;
}


//******************************************************************************
/* Function :  ADCHS_DMASourceEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DMASourceEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DMASourceEnable function.
*/

PLIB_TEMPLATE bool ADCHS_DMASourceEnable_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;
    volatile __ADC0TIMEbits_t *ADCxTIME = (volatile __ADC0TIMEbits_t *)&regs->ADCxTIME;

    if (channelID < 7)
    {
        ADCxTIME[channelID].BCHEN = 1;
        return true;
    }
    else
    {
        return false;
    }
}


//******************************************************************************
/* Function :  ADCHS_DMASourceDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DMASourceDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DMASourceDisable function.
*/

PLIB_TEMPLATE bool ADCHS_DMASourceDisable_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;
    volatile __ADC0TIMEbits_t *ADCxTIME = (volatile __ADC0TIMEbits_t *)&regs->ADCxTIME;

    if (channelID < 7)
    {
        ADCxTIME[channelID].BCHEN = 0;
        return true;
    }
    else
    {
        return false;
    }
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_A_InterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DMABuffer_A_InterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DMABuffer_A_InterruptEnable function.
*/

PLIB_TEMPLATE bool ADCHS_DMABuffer_A_InterruptEnable_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;
    volatile uint32_t *pADCDSTAT = (volatile uint32_t *)&regs->ADCDSTAT;

    if (channelID < 7)
    {
        *pADCDSTAT |= (1 << (8 + channelID));  
        return true;
    }
    else
    {
        return false;
    }
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_A_InterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DMABuffer_A_InterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DMABuffer_A_InterruptDisable function.
*/

PLIB_TEMPLATE bool ADCHS_DMABuffer_A_InterruptDisable_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;
    volatile uint32_t *pADCDSTAT = (volatile uint32_t *)&regs->ADCDSTAT;

    if (channelID < 7)
    {
        *pADCDSTAT &= (1 << (8 + channelID))^0xffffffff;  
        return true;
    }
    else
    {
        return false;
    }
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_B_InterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DMABuffer_B_InterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DMABuffer_B_InterruptEnable function.
*/

PLIB_TEMPLATE bool ADCHS_DMABuffer_B_InterruptEnable_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;
    volatile uint32_t *pADCDSTAT = (volatile uint32_t *)&regs->ADCDSTAT;

    if (channelID < 7)
    {
        *pADCDSTAT |= 1 << (24 + channelID);  
        return true;
    }
    else
    {
        return false;
    }
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_B_InterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DMABuffer_B_InterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DMABuffer_B_InterruptDisable function.
*/

PLIB_TEMPLATE bool ADCHS_DMABuffer_B_InterruptDisable_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;
    volatile uint32_t *pADCDSTAT = (volatile uint32_t *)&regs->ADCDSTAT;

    if (channelID < 7)
    {
        *pADCDSTAT &= (1 << (24 + channelID))^0xffffffff;  
        return true;
    }
    else
    {
        return false;
    }
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_A_IsFull_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DMABuffer_A_IsFull 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DMABuffer_A_IsFull function.
*/

PLIB_TEMPLATE int8_t ADCHS_DMABuffer_A_IsFull_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;
    volatile uint32_t *pADCDSTAT = (volatile uint32_t *)&regs->ADCDSTAT;

    if (channelID < 7)
    {
        if (*pADCDSTAT & (1 << (channelID)))
            return 1;
        else
            return 0;
    }
    else
    {
        return -1;
    }
}


//******************************************************************************
/* Function :  ADCHS_DMABuffer_B_IsFull_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DMABuffer_B_IsFull 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DMABuffer_B_IsFull function.
*/

PLIB_TEMPLATE int8_t ADCHS_DMABuffer_B_IsFull_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;
    volatile uint32_t *pADCDSTAT = (volatile uint32_t *)&regs->ADCDSTAT;

    if (channelID < 7)
    {
        if (*pADCDSTAT & (1 << (16+channelID)))
            return 1;
        else
            return 0;
    }
    else
    {
        return -1;
    }
}


//******************************************************************************
/* Function :  ADCHS_DMAOverflowErrorHasOccurred_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DMAOverflowErrorHasOccurred 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DMAOverflowErrorHasOccurred function.
*/

PLIB_TEMPLATE bool ADCHS_DMAOverflowErrorHasOccurred_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;
    return regs->ADCDSTAT.bits.WOVERR;
}


//******************************************************************************
/* Function :  ADCHS_ExistsDMA_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsDMA

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsDMA function.
*/

#define PLIB_ADCHS_ExistsDMA PLIB_ADCHS_ExistsDMA
PLIB_TEMPLATE bool ADCHS_ExistsDMA_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_DMA_DEFAULT_H*/

/******************************************************************************
 End of File
*/

