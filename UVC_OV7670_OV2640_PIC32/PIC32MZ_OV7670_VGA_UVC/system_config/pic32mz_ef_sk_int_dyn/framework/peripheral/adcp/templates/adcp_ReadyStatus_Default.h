/*******************************************************************************
  ADCP Peripheral Library Template Implementation

  File Name:
    adcp_ReadyStatus_Default.h

  Summary:
    ADCP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ReadyStatus
    and its Variant : Default
    For following APIs :
        PLIB_ADCP_ModuleIsReady
        PLIB_ADCP_ExistsReadyStatus

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

#ifndef _ADCP_READYSTATUS_DEFAULT_H
#define _ADCP_READYSTATUS_DEFAULT_H

#include "adcp_registers.h"

//******************************************************************************
/* Function :  ADCP_ModuleIsReady_Default

  Summary:
    Implements Default variant of PLIB_ADCP_ModuleIsReady 

  Description:
    This template implements the Default variant of the PLIB_ADCP_ModuleIsReady function.
*/

PLIB_TEMPLATE bool ADCP_ModuleIsReady_Default( ADCP_MODULE_ID index )
{
	volatile adcp_registers_t * adcp = ((adcp_registers_t *)(index));
	return adcp->ADxCON2.ADCRDY; 
}


//******************************************************************************
/* Function :  ADCP_ExistsReadyStatus_Default

  Summary:
    Implements Default variant of PLIB_ADCP_ExistsReadyStatus

  Description:
    This template implements the Default variant of the PLIB_ADCP_ExistsReadyStatus function.
*/

#define PLIB_ADCP_ExistsReadyStatus PLIB_ADCP_ExistsReadyStatus
PLIB_TEMPLATE bool ADCP_ExistsReadyStatus_Default( ADCP_MODULE_ID index )
{
    return true;
}


#endif /*_ADCP_READYSTATUS_DEFAULT_H*/

/******************************************************************************
 End of File
*/

