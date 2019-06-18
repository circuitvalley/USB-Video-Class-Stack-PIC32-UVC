/*******************************************************************************
  SQI Peripheral Library Template Implementation

  File Name:
    sqi_InterruptSignalControl_Default.h

  Summary:
    SQI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : InterruptSignalControl
    and its Variant : Default
    For following APIs :
        PLIB_SQI_InterruptSignalEnable
        PLIB_SQI_InterruptSignalDisable
        PLIB_SQI_InterruptSignalDisableAll
        PLIB_SQI_InterruptSignalIsEnabled
        PLIB_SQI_ExistsInterruptSignalControl

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

#ifndef _SQI_INTERRUPTSIGNALCONTROL_DEFAULT_H
#define _SQI_INTERRUPTSIGNALCONTROL_DEFAULT_H

#include "sqi_registers.h"

//******************************************************************************
/* Function :  SQI_InterruptSignalEnable_Default

  Summary:
    Implements Default variant of PLIB_SQI_InterruptSignalEnable

  Description:
    This template implements the Default variant of the PLIB_SQI_InterruptSignalEnable function.
*/

PLIB_TEMPLATE void SQI_InterruptSignalEnable_Default( SQI_MODULE_ID index , SQI_INTERRUPTS interruptFlag )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;
    switch (interruptFlag)
    {
	case SQI_PKTCOMP:
	     sqi->SQIINTSIGEN.PKTCOMPISE = 1;
	     break;
	case SQI_BDDONE:
	     sqi->SQIINTSIGEN.BDDONEISE = 1;
	     break;
	case SQI_CONTHR:
	     sqi->SQIINTSIGEN.CONTHRISE = 1;
	       break;
	case SQI_CONEMPTY:
	     sqi->SQIINTSIGEN.CONEMPTYISE = 1;
	     break;
	case SQI_CONFULL:
	     sqi->SQIINTSIGEN.CONFULLISE = 1;
	     break;
	case SQI_RXTHR:
	     sqi->SQIINTSIGEN.RXTHRISE = 1;
	     break;
	case SQI_RXFULL:
	     sqi->SQIINTSIGEN.RXFULLISE = 1;
	     break;
	case SQI_RXEMPTY:
	     sqi->SQIINTSIGEN.RXEMPTYISE = 1;
	     break;
	case SQI_TXTHR:
	     sqi->SQIINTSIGEN.TXTHRISE = 1;
	     break;
	case SQI_TXFULL:
	     sqi->SQIINTSIGEN.TXFULLISE = 1;
	     break;
	case SQI_TXEMPTY:
	     sqi->SQIINTSIGEN.TXEMPTYISE = 1;
	     break;
	default:
	     sqi->SQIINTSIGEN.TXFULLISE = 1;
    }
}


//******************************************************************************
/* Function :  SQI_InterruptSignalDisable_Default

  Summary:
    Implements Default variant of PLIB_SQI_InterruptSignalDisable

  Description:
    This template implements the Default variant of the PLIB_SQI_InterruptSignalDisable function.
*/

PLIB_TEMPLATE void SQI_InterruptSignalDisable_Default( SQI_MODULE_ID index , SQI_INTERRUPTS interruptFlag )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;
    switch (interruptFlag)
    {
	case SQI_PKTCOMP:
	     sqi->SQIINTSIGEN.PKTCOMPISE = 0;
	     break;
	case SQI_BDDONE:
	     sqi->SQIINTSIGEN.BDDONEISE = 0;
	     break;
	case SQI_CONTHR:
	     sqi->SQIINTSIGEN.CONTHRISE = 0;
	     break;
	case SQI_CONEMPTY:
	     sqi->SQIINTSIGEN.CONEMPTYISE = 0;
	     break;
	case SQI_CONFULL:
	     sqi->SQIINTSIGEN.CONFULLISE = 0;
	     break;
	case SQI_RXTHR:
	     sqi->SQIINTSIGEN.RXTHRISE = 0;
	     break;
	case SQI_RXFULL:
	     sqi->SQIINTSIGEN.RXFULLISE = 0;
	     break;
	case SQI_RXEMPTY:
	     sqi->SQIINTSIGEN.RXEMPTYISE = 0;
	     break;
	case SQI_TXTHR:
	     sqi->SQIINTSIGEN.TXTHRISE = 0;
	     break;
	case SQI_TXFULL:
	     sqi->SQIINTSIGEN.TXFULLISE = 0;
	     break;
	case SQI_TXEMPTY:
	     sqi->SQIINTSIGEN.TXEMPTYISE = 0;
	     break;
	default:
	     sqi->SQIINTSIGEN.TXFULLISE = 0;
    }
}

//******************************************************************************
/* Function :  SQI_InterruptSignalDisableAll_Default

  Summary:
    Implements Default variant of PLIB_SQI_InterruptSignalDisableAll 

  Description:
    This template implements the Default variant of the PLIB_SQI_InterruptSignalDisableAll function.
*/

PLIB_TEMPLATE void SQI_InterruptSignalDisableAll_Default( SQI_MODULE_ID index )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;
    volatile uint32_t *reg = (volatile uint32_t *)&sqi->SQIINTSIGEN;
    *reg = 0;
}

//******************************************************************************
/* Function :  SQI_InterruptSignalIsEnabled_Default

  Summary:
    Implements Default variant of PLIB_SQI_InterruptSignalIsEnabled

  Description:
    This template implements the Default variant of the PLIB_SQI_InterruptSignalIsEnabled function.
*/

PLIB_TEMPLATE bool SQI_InterruptSignalIsEnabled_Default( SQI_MODULE_ID index , SQI_INTERRUPTS interruptFlag )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;
    uint8_t ret;

    switch (interruptFlag)
    {
	case SQI_PKTCOMP:
	     ret = sqi->SQIINTSIGEN.PKTCOMPISE;
	     break;
	case SQI_BDDONE:
	     ret = sqi->SQIINTSIGEN.BDDONEISE;
	     break;
	case SQI_CONTHR:
	     ret =  sqi->SQIINTSIGEN.CONTHRISE;
	     break;
	case SQI_CONEMPTY:
	     ret =  sqi->SQIINTSIGEN.CONEMPTYISE;
	     break;
	case SQI_CONFULL:
	     ret =  sqi->SQIINTSIGEN.CONFULLISE;
	     break;
	case SQI_RXTHR:
	     ret =  sqi->SQIINTSIGEN.RXTHRISE;
	     break;
	case SQI_RXEMPTY:
	     ret = sqi->SQIINTSIGEN.RXEMPTYISE;
	     break;
	case SQI_RXFULL:
	     ret =  sqi->SQIINTSIGEN.RXFULLISE;
	     break;
	case SQI_TXTHR:
	     ret =  sqi->SQIINTSIGEN.TXTHRISE;
	     break;
	case SQI_TXEMPTY:
	     ret = sqi->SQIINTSIGEN.TXEMPTYISE;
	     break;
	case SQI_TXFULL:
	     ret = sqi->SQIINTSIGEN.TXFULLISE;
	     break;
	default:
	     ret =  sqi->SQIINTSIGEN.TXFULLISE;
	     break;
    }

    return (bool) ret;
}


//******************************************************************************
/* Function :  SQI_ExistsInterruptSignalControl_Default

  Summary:
    Implements Default variant of PLIB_SQI_ExistsInterruptSignalControl

  Description:
    This template implements the Default variant of the PLIB_SQI_ExistsInterruptSignalControl function.
*/

#define PLIB_SQI_ExistsInterruptSignalControl PLIB_SQI_ExistsInterruptSignalControl
PLIB_TEMPLATE bool SQI_ExistsInterruptSignalControl_Default( SQI_MODULE_ID index )
{
    return true;
}


#endif /*_SQI_INTERRUPTSIGNALCONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

