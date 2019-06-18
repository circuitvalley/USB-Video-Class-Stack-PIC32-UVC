/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_ManualControl_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ManualControl
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_SoftwareSamplingStart
        PLIB_ADCHS_SoftwareSamplingStop
        PLIB_ADCHS_SoftwareConversionStart
        PLIB_ADCHS_SoftwareConversionInputSelect
        PLIB_ADCHS_ExistsManualControl

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

#ifndef _ADCHS_MANUALCONTROL_DEFAULT_H
#define _ADCHS_MANUALCONTROL_DEFAULT_H



//******************************************************************************
/* Function :  ADCHS_SoftwareSamplingStart_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_SoftwareSamplingStart 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_SoftwareSamplingStart function.
    This operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_SoftwareSamplingStart_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (volatile adchs_register_t *)index;

    regs->ADCCON3.SAMP = 1;
}


//******************************************************************************
/* Function :  ADCHS_SoftwareSamplingStop_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_SoftwareSamplingStop 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_SoftwareSamplingStop function.
    This operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_SoftwareSamplingStop_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (volatile adchs_register_t *)index;

    regs->ADCCON3.SAMP = 0;
}


//******************************************************************************
/* Function :  ADCHS_SoftwareConversionStart_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_SoftwareConversionStart 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_SoftwareConversionStart function.
    This operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_SoftwareConversionStart_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (volatile adchs_register_t *)index;

    regs->ADCCON3.RQCNVRT = 1;
}


//******************************************************************************
/* Function :  ADCHS_SoftwareConversionInputSelect_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_SoftwareConversionInputSelect 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_SoftwareConversionInputSelect function.
    This operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_SoftwareConversionInputSelect_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID anInput )
{
    volatile adchs_register_t *regs = (volatile adchs_register_t *)index;

    regs->ADCCON3.ADINSEL = anInput;
}


//******************************************************************************
/* Function :  ADCHS_ExistsManualControl_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsManualControl

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsManualControl function.
*/

#define PLIB_ADCHS_ExistsManualControl PLIB_ADCHS_ExistsManualControl
PLIB_TEMPLATE bool ADCHS_ExistsManualControl_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_MANUALCONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

