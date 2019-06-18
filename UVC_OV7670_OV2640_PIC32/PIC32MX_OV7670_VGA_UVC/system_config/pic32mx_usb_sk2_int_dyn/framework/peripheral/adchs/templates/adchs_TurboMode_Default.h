/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_TurboMode_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : TurboMode
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_TurboModeEnable
        PLIB_ADCHS_TurboModeDisable
        PLIB_ADCHS_TurboModeErrorHasOccurred
        PLIB_ADCHS_TurboModeChannelSelect
        PLIB_ADCHS_ExistsTurboMode

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

#ifndef _ADCHS_TURBOMODE_DEFAULT_H
#define _ADCHS_TURBOMODE_DEFAULT_H



//******************************************************************************
/* Function :  ADCHS_TurboModeEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_TurboModeEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_TurboModeEnable function.
    This opeartion is not atomic.
*/

PLIB_TEMPLATE void ADCHS_TurboModeEnable_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCON1.TRBEN = 1;
}


//******************************************************************************
/* Function :  ADCHS_TurboModeDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_TurboModeDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_TurboModeDisable function.
    This opeartion is not atomic.
*/

PLIB_TEMPLATE void ADCHS_TurboModeDisable_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCON1.TRBEN = 0;
}


//******************************************************************************
/* Function :  ADCHS_TurboModeErrorHasOccurred_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_TurboModeErrorHasOccurred 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_TurboModeErrorHasOccurred function.
    This operation is atomic.
*/

PLIB_TEMPLATE bool ADCHS_TurboModeErrorHasOccurred_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    return (bool)regs->ADCCON1.TRBERR;
}


//******************************************************************************
/* Function :  ADCHS_TurboModeChannelSelect_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_TurboModeChannelSelect 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_TurboModeChannelSelect function.
    This operation is not atomic.
*/

PLIB_TEMPLATE bool ADCHS_TurboModeChannelSelect_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID masterChannelID , ADCHS_CHANNEL_ID slaveChannelID )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCON1.TRBMST = masterChannelID;
    regs->ADCCON1.TRBSLV = slaveChannelID;

    return true;
}


//******************************************************************************
/* Function :  ADCHS_ExistsTurboMode_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsTurboMode

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsTurboMode function.
*/

#define PLIB_ADCHS_ExistsTurboMode PLIB_ADCHS_ExistsTurboMode
PLIB_TEMPLATE bool ADCHS_ExistsTurboMode_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_TURBOMODE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

