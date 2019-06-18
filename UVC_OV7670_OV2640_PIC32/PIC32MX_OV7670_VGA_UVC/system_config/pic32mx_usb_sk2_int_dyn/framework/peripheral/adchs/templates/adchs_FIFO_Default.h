/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_FIFO_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : FIFO
    and its Variant : Default
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

#ifndef _ADCHS_FIFO_DEFAULT_H
#define _ADCHS_FIFO_DEFAULT_H



//******************************************************************************
/* Function :  ADCHS_FIFORead_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_FIFORead 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_FIFORead function.
    This operation is atomic.
*/

PLIB_TEMPLATE int32_t ADCHS_FIFORead_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    return (int32_t)regs->ADCFIFO;
}


//******************************************************************************
/* Function :  ADCHS_FIFODataIsAvailable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_FIFODataIsAvailable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_FIFODataIsAvailable function.
    This operation is atomic.
*/

PLIB_TEMPLATE bool ADCHS_FIFODataIsAvailable_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    return (bool)regs->ADCFSTAT.FRDY;
}


//******************************************************************************
/* Function :  ADCHS_FIFODataReadyInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_FIFODataReadyInterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_FIFODataReadyInterruptEnable function.
    This operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_FIFODataReadyInterruptEnable_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCFSTAT.FIEN = 1;
}


//******************************************************************************
/* Function :  ADCHS_FIFODataReadyInterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_FIFODataReadyInterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_FIFODataReadyInterruptDisable function.
    This operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_FIFODataReadyInterruptDisable_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCFSTAT.FIEN = 0;
}


//******************************************************************************
/* Function :  ADCHS_FIFOEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_FIFOEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_FIFOEnable function.
    This operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_FIFOEnable_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCFSTAT.FEN = 1;
}


//******************************************************************************
/* Function :  ADCHS_FIFODisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_FIFODisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_FIFODisable function.
    This operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_FIFODisable_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCFSTAT.FEN = 0;
}


//******************************************************************************
/* Function :  ADCHS_FIFOSourceSelect_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_FIFOSourceSelect 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_FIFOSourceSelect function.
    This operation is not atomic.
*/

PLIB_TEMPLATE bool ADCHS_FIFOSourceSelect_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;
    volatile uint32_t *ADCFSTAT = (volatile uint32_t *)&regs->ADCFSTAT;

    *ADCFSTAT |= BIT(channelID + 24);

    return true;
}


//******************************************************************************
/* Function :  ADCHS_FIFODataCountGet_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_FIFODataCountGet 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_FIFODataCountGet function.
    This operation is atomic.
*/

PLIB_TEMPLATE uint8_t ADCHS_FIFODataCountGet_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    return (uint8_t) regs->ADCFSTAT.FCNT;
}


//******************************************************************************
/* Function :  ADCHS_FIFOSourceGet_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_FIFOSourceGet 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_FIFOSourceGet function.
    This operation is atomic.
*/

PLIB_TEMPLATE ADCHS_CHANNEL_ID ADCHS_FIFOSourceGet_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    return (ADCHS_CHANNEL_ID)regs->ADCFSTAT.ADCID;
}


//******************************************************************************
/* Function :  ADCHS_FIFOErrorHasOccurred_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_FIFOErrorHasOccurred 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_FIFOErrorHasOccurred function.
    This operation is atomic.
*/

PLIB_TEMPLATE bool ADCHS_FIFOErrorHasOccurred_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    return (bool) regs->ADCFSTAT.FWROVERR;
}


//******************************************************************************
/* Function :  ADCHS_FIFODataIsNegative_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_FIFODataIsNegative 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_FIFODataIsNegative function.
    This operation is atomic.
*/

PLIB_TEMPLATE bool ADCHS_FIFODataIsNegative_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    return (bool) regs->ADCFSTAT.FSIGN;
}


//******************************************************************************
/* Function :  ADCHS_ExistsFIFO_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsFIFO

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsFIFO function.
*/

#define PLIB_ADCHS_ExistsFIFO PLIB_ADCHS_ExistsFIFO
PLIB_TEMPLATE bool ADCHS_ExistsFIFO_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_FIFO_DEFAULT_H*/

/******************************************************************************
 End of File
*/

