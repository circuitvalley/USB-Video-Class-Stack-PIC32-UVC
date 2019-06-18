/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_ConversionResult_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ConversionResult
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_AnalogInputDataReadyInterruptEnable
        PLIB_ADCHS_AnalogInputDataReadyInterruptDisable
        PLIB_ADCHS_AnalogInputDataIsReady
        PLIB_ADCHS_AnalogInputResultGet
        PLIB_ADCHS_ExistsConversionResults

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

#ifndef _ADCHS_CONVERSIONRESULT_DEFAULT_H
#define _ADCHS_CONVERSIONRESULT_DEFAULT_H



//******************************************************************************
/* Function :  ADCHS_AnalogInputDataReadyInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputDataReadyInterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputDataReadyInterruptEnable function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputDataReadyInterruptEnable_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

#ifndef CHECON /* PIC32MZ */
    regs->ADCGIRQENx[analogInput / 32] |= BIT(analogInput % 32);
#else /*PIC32MK */
    regs->ADCGIRQENx[analogInput / 32].set = BIT(analogInput % 32);
#endif
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputDataReadyInterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputDataReadyInterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputDataReadyInterruptDisable function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputDataReadyInterruptDisable_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

#ifndef CHECON /* PIC32MZ */
    regs->ADCGIRQENx[analogInput / 32] &= ~BIT(analogInput % 32);
#else /*PIC32MK */
    regs->ADCGIRQENx[analogInput / 32].clr = BIT(analogInput % 32);
#endif
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputDataIsReady_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputDataIsReady 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputDataIsReady function.
    Operation is atomic.
*/

PLIB_TEMPLATE bool ADCHS_AnalogInputDataIsReady_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

#ifndef CHECON /* PIC32MZ */
    return (bool)(regs->ADCSTATx[analogInput / 32] & BIT(analogInput % 32));
#else /*PIC32MK */
     return (bool)(regs->ADCSTATx[analogInput / 32].bits & BIT(analogInput % 32));
#endif
}

//******************************************************************************
/* Function :  ADCHS_AnalogInputResultGet_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputResultGet 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputResultGet function.
    Operation is atomic.
*/

PLIB_TEMPLATE uint32_t ADCHS_AnalogInputResultGet_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

#ifndef CHECON /* PIC32MZ */
    return regs->ADCDATAx[analogInput];
#else /*PIC32MK */
    return regs->ADCDATAx[analogInput].bits;
#endif
}

//******************************************************************************
/* Function :  ADCHS_ExistsConversionResults_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsConversionResults

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsConversionResults function.
*/

#define PLIB_ADCHS_ExistsConversionResults PLIB_ADCHS_ExistsConversionResults
PLIB_TEMPLATE bool ADCHS_ExistsConversionResults_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_CONVERSIONRESULT_DEFAULT_H*/

/******************************************************************************
 End of File
*/

