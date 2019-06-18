/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_DigitalFilter_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DigitalFilter
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_DigitalFilterEnable
        PLIB_ADCHS_DigitalFilterDisable
        PLIB_ADCHS_DigitalFilterOversamplingModeSetup
        PLIB_ADCHS_DigitalFilterAveragingModeSetup
        PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect
        PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect
        PLIB_ADCHS_DigitalFilterDataIsReady
        PLIB_ADCHS_DigitalFilterDataGet
        PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable
        PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable
        PLIB_ADCHS_ExistsDigitalFilter

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

#ifndef _ADCHS_DIGITALFILTER_DEFAULT_H
#define _ADCHS_DIGITALFILTER_DEFAULT_H



//******************************************************************************
/* Function :  ADCHS_DigitalFilterEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterEnable function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterEnable_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCFLTRx[id].AFEN = 1;
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterDisable function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterDisable_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCFLTRx[id].AFEN = 0;
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterOversamplingModeSetup_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterOversamplingModeSetup 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterOversamplingModeSetup function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterOversamplingModeSetup_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id , ADCHS_AN_INPUT_ID analogInput , ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length , ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio , bool intEnable )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCFLTRx[id].CHNLID = analogInput;
    regs->ADCFLTRx[id].DATA16EN = length;
    regs->ADCFLTRx[id].OVRSAM = ratio;
    regs->ADCFLTRx[id].DFMODE = 0;

    regs->ADCFLTRx[id].AFGIEN = intEnable;
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterAveragingModeSetup_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterAveragingModeSetup 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterAveragingModeSetup function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterAveragingModeSetup_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id , ADCHS_AN_INPUT_ID analogInput , ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length , ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count , bool intEnable )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCFLTRx[id].CHNLID = analogInput;
    regs->ADCFLTRx[id].DATA16EN = length;
    regs->ADCFLTRx[id].OVRSAM = count;
    regs->ADCFLTRx[id].DFMODE = 1;

    regs->ADCFLTRx[id].AFGIEN = intEnable;
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterOversamplingModeRatioSelect_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterOversamplingModeRatioSelect_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id , ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCFLTRx[id].OVRSAM = ratio;
    regs->ADCFLTRx[id].DFMODE = 0;
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterAveragingModeSampleCountSelect_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterAveragingModeSampleCountSelect_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id , ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCFLTRx[id].OVRSAM = count;
    regs->ADCFLTRx[id].DFMODE = 1;
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterDataIsReady_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterDataIsReady 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterDataIsReady function.
    Operation is atomic.
*/

PLIB_TEMPLATE bool ADCHS_DigitalFilterDataIsReady_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    return (bool)regs->ADCFLTRx[id].AFRDY;
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterDataGet_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterDataGet 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterDataGet function.
    Operation is atomic.
*/

PLIB_TEMPLATE int16_t ADCHS_DigitalFilterDataGet_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID dfltrID )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    return (int16_t)regs->ADCFLTRx[dfltrID].FLTRDATA;
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterDataReadyInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterDataReadyInterruptEnable_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID digFilter )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCFLTRx[digFilter].AFGIEN = 1;
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterDataReadyInterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterDataReadyInterruptDisable_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID digFilter )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCFLTRx[digFilter].AFGIEN = 0;
}


//******************************************************************************
/* Function :  ADCHS_ExistsDigitalFilter_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsDigitalFilter

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsDigitalFilter function.
*/

#define PLIB_ADCHS_ExistsDigitalFilter PLIB_ADCHS_ExistsDigitalFilter
PLIB_TEMPLATE bool ADCHS_ExistsDigitalFilter_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_DIGITALFILTER_DEFAULT_H*/

/******************************************************************************
 End of File
*/

