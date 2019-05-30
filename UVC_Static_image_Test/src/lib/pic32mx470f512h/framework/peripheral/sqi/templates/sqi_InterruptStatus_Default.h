/*******************************************************************************
  SQI Peripheral Library Template Implementation

  File Name:
    sqi_InterruptStatus_Default.h

  Summary:
    SQI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : InterruptStatus
    and its Variant : Default
    For following APIs :
        PLIB_SQI_InterruptFlagGet
        PLIB_SQI_InterruptWordGet
        PLIB_SQI_InterruptWordClear
        PLIB_SQI_ExistsInterruptStatus

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

#ifndef _SQI_INTERRUPTSTATUS_DEFAULT_H
#define _SQI_INTERRUPTSTATUS_DEFAULT_H

#include "sqi_registers.h"

//******************************************************************************
/* Function :  SQI_InterruptFlagGet_Default

  Summary:
    Implements Default variant of PLIB_SQI_InterruptFlagGet

  Description:
    This template implements the Default variant of the PLIB_SQI_InterruptFlagGet function.
*/

PLIB_TEMPLATE bool SQI_InterruptFlagGet_Default( SQI_MODULE_ID index , SQI_INTERRUPTS interruptFlag )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;

    switch (interruptFlag)
    {
	case SQI_PKTCOMP:
	    return (bool) sqi->SQIINTSTAT.PKTCOMPIF;
	case SQI_BDDONE:
	    return (bool) sqi->SQIINTSTAT.BDDONEIF;
	case SQI_CONTHR:
	    return (bool) sqi->SQIINTSTAT.CONTHRIF;
	case SQI_CONEMPTY:
	    return (bool) sqi->SQIINTSTAT.CONEMPTYIF;
	case SQI_CONFULL:
	    return (bool) sqi->SQIINTSTAT.CONFULLIF;
	case SQI_RXTHR:
	    return (bool) sqi->SQIINTSTAT.RXTHRIF;
	case SQI_RXFULL:
	    return (bool) sqi->SQIINTSTAT.RXFULLIF;
	case SQI_RXEMPTY:
	    return (bool) sqi->SQIINTSTAT.RXEMPTYIF;
	case SQI_TXTHR:
	    return (bool) sqi->SQIINTSTAT.TXTHRIF;
	case SQI_TXFULL:
	    return (bool) sqi->SQIINTSTAT.TXFULLIF;
	case SQI_TXEMPTY:
	    return (bool) sqi->SQIINTSTAT.TXEMPTYIF;
	default:
	    return (bool) sqi->SQIINTSTAT.TXFULLIF;
	}
}

//******************************************************************************
/* Function :  SQI_InterruptWordGet_Default

  Summary:
    Implements Default variant of PLIB_SQI_InterruptWordGet 

  Description:
    This template implements the Default variant of the PLIB_SQI_InterruptWordGet function.
*/

PLIB_TEMPLATE uint32_t SQI_InterruptWordGet_Default( SQI_MODULE_ID index )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;
    volatile uint32_t *reg =  (volatile uint32_t *)&sqi->SQIINTSTAT;
    return *reg;
}


//******************************************************************************
/* Function :  SQI_InterruptWordClear_Default

  Summary:
    Implements Default variant of PLIB_SQI_InterruptWordClear 

  Description:
    This template implements the Default variant of the PLIB_SQI_InterruptWordClear function.
*/

PLIB_TEMPLATE void SQI_InterruptWordClear_Default( SQI_MODULE_ID index , uint32_t flags )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;
    volatile uint32_t *reg =  (volatile uint32_t *)&sqi->SQIINTSTAT;
    *reg = flags;
}

//******************************************************************************
/* Function :  SQI_ExistsInterruptStatus_Default

  Summary:
    Implements Default variant of PLIB_SQI_ExistsInterruptStatus

  Description:
    This template implements the Default variant of the PLIB_SQI_ExistsInterruptStatus function.
*/

#define PLIB_SQI_ExistsInterruptStatus PLIB_SQI_ExistsInterruptStatus
PLIB_TEMPLATE bool SQI_ExistsInterruptStatus_Default( SQI_MODULE_ID index )
{
    return true;
}


#endif /*_SQI_INTERRUPTSTATUS_DEFAULT_H*/

/******************************************************************************
 End of File
*/

