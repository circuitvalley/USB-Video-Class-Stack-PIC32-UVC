/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_ScanEnable_default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ScanEnable
    and its Variant : default
    For following APIs :
        PLIB_ADCHS_ChannelScanEnable
        PLIB_ADCHS_ChannelScanAbort
        PLIB_ADCHS_ExistsScanEnable

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

#ifndef _ADCHS_SCANENABLE_DEFAULT_H
#define _ADCHS_SCANENABLE_DEFAULT_H

//******************************************************************************
/* Function :  ADCHS_ChannelScanEnable_default

  Summary:
    Implements default variant of PLIB_ADCHS_ChannelScanEnable 

  Description:
    This template implements the default variant of the PLIB_ADCHS_ChannelScanEnable function.
*/

PLIB_TEMPLATE void ADCHS_ChannelScanEnable_default( ADCHS_MODULE_ID index )
{
	volatile adchs_register_t *regs = (volatile adchs_register_t *)index;
	regs->ADCCON1.SCANEN = 1;
}


//******************************************************************************
/* Function :  ADCHS_ChannelScanAbort_default

  Summary:
    Implements default variant of PLIB_ADCHS_ChannelScanAbort 

  Description:
    This template implements the default variant of the PLIB_ADCHS_ChannelScanAbort function.
*/

PLIB_TEMPLATE void ADCHS_ChannelScanAbort_default( ADCHS_MODULE_ID index )
{
	volatile adchs_register_t *regs = (volatile adchs_register_t *)index;
	regs->ADCCON1.SCANEN = 0;
}


//******************************************************************************
/* Function :  ADCHS_ExistsScanEnable_default

  Summary:
    Implements default variant of PLIB_ADCHS_ExistsScanEnable

  Description:
    This template implements the default variant of the PLIB_ADCHS_ExistsScanEnable function.
*/

#define PLIB_ADCHS_ExistsScanEnable PLIB_ADCHS_ExistsScanEnable
PLIB_TEMPLATE bool ADCHS_ExistsScanEnable_default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_SCANENABLE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

