/*******************************************************************************
  ADCP Peripheral Library Template Implementation

  File Name:
    adcp_EnableControl_Default.h

  Summary:
    ADCP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EnableControl
    and its Variant : Default
    For following APIs :
        PLIB_ADCP_Enable
        PLIB_ADCP_Disable
        PLIB_ADCP_ExistsEnableControl

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

#ifndef _ADCP_ENABLECONTROL_DEFAULT_H
#define _ADCP_ENABLECONTROL_DEFAULT_H

#include "adcp_registers.h"

//******************************************************************************

/* Function :  ADCP_Enable_Default

  Summary:
    Implements Default variant of PLIB_ADCP_Enable 

  Description:
    This template implements the Default variant of the PLIB_ADCP_Enable function.
 */

PLIB_TEMPLATE void ADCP_Enable_Default(ADCP_MODULE_ID index) 
{
	volatile adcp_registers_t * adcp = ((adcp_registers_t *)(index));
	adcp->ADxCON1.ADCEN = 1;
}


//******************************************************************************

/* Function :  ADCP_Disable_Default

  Summary:
    Implements Default variant of PLIB_ADCP_Disable 

  Description:
    This template implements the Default variant of the PLIB_ADCP_Disable function.
 */

PLIB_TEMPLATE void ADCP_Disable_Default(ADCP_MODULE_ID index)
{	
	volatile adcp_registers_t * adcp = ((adcp_registers_t *)(index));
	adcp->ADxCON1.ADCEN = 0;
}


//******************************************************************************

/* Function :  ADCP_ExistsEnableControl_Default

  Summary:
    Implements Default variant of PLIB_ADCP_ExistsEnableControl

  Description:
    This template implements the Default variant of the PLIB_ADCP_ExistsEnableControl function.
 */

#define PLIB_ADCP_ExistsEnableControl PLIB_ADCP_ExistsEnableControl
PLIB_TEMPLATE bool ADCP_ExistsEnableControl_Default(ADCP_MODULE_ID index) 
{
    return true;
}


#endif /*_ADCP_ENABLECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
 */

