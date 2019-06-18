/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_ExternalConversionRequest_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ExternalConversionRequest
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_ExternalConversionRequestEnable
        PLIB_ADCHS_ExternalConversionRequestDisable
        PLIB_ADCHS_ExistsExternalConversionRequestControl

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

#ifndef _ADCHS_EXTERNALCONVERSIONREQUEST_DEFAULT_H
#define _ADCHS_EXTERNALCONVERSIONREQUEST_DEFAULT_H



//******************************************************************************
/* Function :  ADCHS_ExternalConversionRequestEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExternalConversionRequestEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExternalConversionRequestEnable function.
*/

PLIB_TEMPLATE void ADCHS_ExternalConversionRequestEnable_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;
	regs->ADCCON2.ENXCNVRT = 1;
}


//******************************************************************************
/* Function :  ADCHS_ExternalConversionRequestDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExternalConversionRequestDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExternalConversionRequestDisable function.
*/

PLIB_TEMPLATE void ADCHS_ExternalConversionRequestDisable_Default( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;
	regs->ADCCON2.ENXCNVRT = 0;
}


//******************************************************************************
/* Function :  ADCHS_ExistsExternalConversionRequestControl_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsExternalConversionRequestControl

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsExternalConversionRequestControl function.
*/

#define PLIB_ADCHS_ExistsExternalConversionRequestControl PLIB_ADCHS_ExistsExternalConversionRequestControl
PLIB_TEMPLATE bool ADCHS_ExistsExternalConversionRequestControl_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_EXTERNALCONVERSIONREQUEST_DEFAULT_H*/

/******************************************************************************
 End of File
*/

