/*******************************************************************************
  SQI Peripheral Library Template Implementation

  File Name:
    sqi_InterruptControl_Default.h

  Summary:
    SQI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : InterruptControl
    and its Variant : Default
    For following APIs :
        PLIB_SQI_InterruptEnable
        PLIB_SQI_InterruptDisable
        PLIB_SQI_InterruptDisableAll
        PLIB_SQI_InterruptIsEnabled
        PLIB_SQI_ExistsInterruptControl

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

#ifndef _SQI_INTERRUPTCONTROL_DEFAULT_H
#define _SQI_INTERRUPTCONTROL_DEFAULT_H

#include "sqi_registers.h"

//******************************************************************************
/* Function :  SQI_InterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_SQI_InterruptEnable

  Description:
    This template implements the Default variant of the PLIB_SQI_InterruptEnable function.
*/

PLIB_TEMPLATE void SQI_InterruptEnable_Default( SQI_MODULE_ID index , SQI_INTERRUPTS interruptFlag )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;
    volatile uint32_t *reg = (volatile uint32_t *)&sqi->SQIINTEN;

    switch (interruptFlag)
    {
	case SQI_PKTCOMP:
	     sqi->SQIINTEN.PKTCOMPIE = 1;
	     break;
	case SQI_BDDONE:
	     sqi->SQIINTEN.BDDONEIE = 1;
	     break;
	case SQI_CONTHR:
	     sqi->SQIINTEN.CONTHRIE = 1;
	     break;
	case SQI_CONEMPTY:
	     sqi->SQIINTEN.CONEMPTYIE = 1;
	     break;
	case SQI_CONFULL:
	     sqi->SQIINTEN.CONFULLIE = 1;
	     break;
	case SQI_RXTHR:
	     sqi->SQIINTEN.RXTHRIE = 1;
	     break;
	case SQI_RXFULL:
	     sqi->SQIINTEN.RXFULLIE = 1;
	     break;
	case SQI_RXEMPTY:
	     sqi->SQIINTEN.RXEMPTYIE = 1;
	     break;
	case SQI_TXTHR:
	     sqi->SQIINTEN.TXTHRIE = 1;
	     break;
	case SQI_TXFULL:
	     sqi->SQIINTEN.TXFULLIE = 1;
	     break;
	case SQI_TXEMPTY:
	     sqi->SQIINTEN.TXEMPTYIE = 1;
	     break;
	default:
	     *reg = 0x7FF;
	     break;
    }
}


//******************************************************************************
/* Function :  SQI_InterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_SQI_InterruptDisable

  Description:
    This template implements the Default variant of the PLIB_SQI_InterruptDisable function.
*/

PLIB_TEMPLATE void SQI_InterruptDisable_Default( SQI_MODULE_ID index , SQI_INTERRUPTS interruptFlag )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;
    volatile uint32_t *reg = (volatile uint32_t *)&sqi->SQIINTEN;

    switch (interruptFlag)
    {
	case SQI_PKTCOMP:
	     sqi->SQIINTEN.PKTCOMPIE = 0;
	     break;
	case SQI_BDDONE:
	     sqi->SQIINTEN.BDDONEIE = 0;
	     break;
	case SQI_CONTHR:
	     sqi->SQIINTEN.CONTHRIE = 0;
	     break;
	case SQI_CONEMPTY:
	     sqi->SQIINTEN.CONEMPTYIE = 0;
	     break;
	case SQI_CONFULL:
	     sqi->SQIINTEN.CONFULLIE = 0;
	     break;
	case SQI_RXTHR:
	     sqi->SQIINTEN.RXTHRIE = 0;
	     break;
	case SQI_RXFULL:
	     sqi->SQIINTEN.RXFULLIE = 0;
	     break;
	case SQI_RXEMPTY:
	     sqi->SQIINTEN.RXEMPTYIE = 0;
	     break;
	case SQI_TXTHR:
	     sqi->SQIINTEN.TXTHRIE = 0;
	     break;
	case SQI_TXFULL:
	     sqi->SQIINTEN.TXFULLIE = 0;
	     break;
	case SQI_TXEMPTY:
	     sqi->SQIINTEN.TXEMPTYIE = 0;
	     break;
	default:
	     *reg = 0;
	     break;
    }
}

//******************************************************************************
/* Function :  SQI_InterruptDisableAll_Default

  Summary:
    Implements Default variant of PLIB_SQI_InterruptDisableAll 

  Description:
    This template implements the Default variant of the PLIB_SQI_InterruptDisableAll function.
*/

PLIB_TEMPLATE void SQI_InterruptDisableAll_Default( SQI_MODULE_ID index )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;
    volatile uint32_t *reg = (volatile uint32_t *)&sqi->SQIINTEN;
    *reg = 0;
}

//******************************************************************************
/* Function :  SQI_InterruptIsEnabled_Default

  Summary:
    Implements Default variant of PLIB_SQI_InterruptIsEnabled

  Description:
    This template implements the Default variant of the PLIB_SQI_InterruptIsEnabled function.
*/

PLIB_TEMPLATE bool SQI_InterruptIsEnabled_Default( SQI_MODULE_ID index , SQI_INTERRUPTS interruptFlag )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;
    uint32_t ret;

    switch (interruptFlag)
    {
	case SQI_PKTCOMP:
	    ret = sqi->SQIINTEN.PKTCOMPIE;
	    break;
	case SQI_BDDONE:
	    ret = sqi->SQIINTEN.BDDONEIE;
	    break;
	case SQI_CONTHR:
	    ret = sqi->SQIINTEN.CONTHRIE;
	    break;
	case SQI_CONEMPTY:
	    ret = sqi->SQIINTEN.CONEMPTYIE;
	    break;
	case SQI_CONFULL:
	    ret = sqi->SQIINTEN.CONFULLIE;
	    break;
	case SQI_RXTHR:
	    ret = sqi->SQIINTEN.RXTHRIE;
	    break;
	case SQI_RXFULL:
	    ret = sqi->SQIINTEN.RXFULLIE;
	    break;
	case SQI_RXEMPTY:
	    ret = sqi->SQIINTEN.RXEMPTYIE;
	    break;
	case SQI_TXTHR:
	    ret =  sqi->SQIINTEN.TXTHRIE;
	    break;
	case SQI_TXFULL:
	    ret = sqi->SQIINTEN.TXFULLIE;
	    break;
	case SQI_TXEMPTY:
	    ret = sqi->SQIINTEN.TXEMPTYIE;
	    break;
	default:
	    ret = sqi->SQIINTEN.TXFULLIE;
	    break;
    }

    return (bool) ret;
}


//******************************************************************************
/* Function :  SQI_ExistsInterruptControl_Default

  Summary:
    Implements Default variant of PLIB_SQI_ExistsInterruptControl

  Description:
    This template implements the Default variant of the PLIB_SQI_ExistsInterruptControl function.
*/

#define PLIB_SQI_ExistsInterruptControl PLIB_SQI_ExistsInterruptControl
PLIB_TEMPLATE bool SQI_ExistsInterruptControl_Default( SQI_MODULE_ID index )
{
    return true;
}


#endif /*_SQI_INTERRUPTCONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

