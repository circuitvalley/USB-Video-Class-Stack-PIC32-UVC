/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_EnableControl_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EnableControl
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_Enable
        PLIB_ADCHS_Disable
        PLIB_ADCHS_ExistsEnableControl

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

#ifndef _ADCHS_ENABLECONTROL_DEFAULT_H
#define _ADCHS_ENABLECONTROL_DEFAULT_H



//******************************************************************************
/* Function :  ADCHS_Enable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_Enable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_Enable function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_Enable_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCON1.ON = 1;
}


//******************************************************************************
/* Function :  ADCHS_Disable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_Disable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_Disable function.
    Operation is not atomic.
*/

PLIB_TEMPLATE void ADCHS_Disable_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCON1.ON = 0;
}


//******************************************************************************
/* Function :  ADCHS_ExistsEnableControl_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsEnableControl

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsEnableControl function.
*/

#define PLIB_ADCHS_ExistsEnableControl PLIB_ADCHS_ExistsEnableControl
PLIB_TEMPLATE bool ADCHS_ExistsEnableControl_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_ENABLECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

