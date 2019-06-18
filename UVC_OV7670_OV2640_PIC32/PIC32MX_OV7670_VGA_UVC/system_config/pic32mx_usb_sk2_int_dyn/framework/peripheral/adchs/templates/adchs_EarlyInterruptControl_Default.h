/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_EarlyInterruptControl_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EarlyInterruptControl
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_EarlyInterruptEnable
        PLIB_ADCHS_EarlyInterruptDisable
        PLIB_ADCHS_AnalogInputEarlyInterruptEnable
        PLIB_ADCHS_AnalogInputEarlyInterruptDisable
        PLIB_ADCHS_AnalogInputEarlyInterruptIsReady
        PLIB_ADCHS_ExistsEarlyInterruptControl

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

#ifndef _ADCHS_EARLYINTERRUPTCONTROL_DEFAULT_H
#define _ADCHS_EARLYINTERRUPTCONTROL_DEFAULT_H



//******************************************************************************
/* Function :  ADCHS_EarlyInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_EarlyInterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_EarlyInterruptEnable function.
    This operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_EarlyInterruptEnable_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCON2.ADCEIOVR = 0;
}


//******************************************************************************
/* Function :  ADCHS_EarlyInterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_EarlyInterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_EarlyInterruptDisable function.
    This operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_EarlyInterruptDisable_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCON2.ADCEIOVR = 1;
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputEarlyInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputEarlyInterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputEarlyInterruptEnable function.
    This operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputEarlyInterruptEnable_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

#ifndef CHECON /* PIC32MZ */
    regs->ADCEIENx[analogInput >> 5] |= BIT(analogInput & 0x1f);
#else /*PIC32MK */
    regs->ADCEIENx[analogInput >> 5].bits |= BIT(analogInput & 0x1f);
#endif
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputEarlyInterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputEarlyInterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputEarlyInterruptDisable function.
    This operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputEarlyInterruptDisable_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

#ifndef CHECON /* PIC32MZ */
    regs->ADCEIENx[analogInput >> 5] &= ~BIT(analogInput & 0x1f);
#else /*PIC32MK */
    regs->ADCEIENx[analogInput >> 5].clr = BIT(analogInput & 0x1f);
#endif
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputEarlyInterruptIsReady_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputEarlyInterruptIsReady 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputEarlyInterruptIsReady function.
    This operation is atomic.
*/

PLIB_TEMPLATE bool ADCHS_AnalogInputEarlyInterruptIsReady_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

#ifndef CHECON /* PIC32MZ */
    return (bool)(regs->ADCEISTATx[analogInput >> 5] & BIT(analogInput & 0x1f));
#else /*PIC32MK */
    return (bool)(regs->ADCEISTATx[analogInput >> 5].bits & BIT(analogInput & 0x1f));
#endif
}


//******************************************************************************
/* Function :  ADCHS_ExistsEarlyInterruptControl_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsEarlyInterruptControl

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsEarlyInterruptControl function.
*/

#define PLIB_ADCHS_ExistsEarlyInterruptControl PLIB_ADCHS_ExistsEarlyInterruptControl
PLIB_TEMPLATE bool ADCHS_ExistsEarlyInterruptControl_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_EARLYINTERRUPTCONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

