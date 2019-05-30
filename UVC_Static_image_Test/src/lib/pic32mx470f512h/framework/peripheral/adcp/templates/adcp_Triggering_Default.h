/*******************************************************************************
  ADCP Peripheral Library Template Implementation

  File Name:
    adcp_Triggering_Default.h

  Summary:
    ADCP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : Triggering
    and its Variant : Default
    For following APIs :
        PLIB_ADCP_Class12TriggerConfigure
        PLIB_ADCP_GlobalSoftwareTrigger
        PLIB_ADCP_IndividualTrigger
        PLIB_ADCP_ExistsTriggering

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

#ifndef _ADCP_TRIGGERING_DEFAULT_H
#define _ADCP_TRIGGERING_DEFAULT_H

#include "adcp_registers.h"

//******************************************************************************

/* Function :  ADCP_Class12TriggerConfigure_Default

  Summary:
    Implements Default variant of PLIB_ADCP_Class12TriggerConfigure 

  Description:
    This template implements the Default variant of the PLIB_ADCP_Class12TriggerConfigure function.
 */

PLIB_TEMPLATE void ADCP_Class12TriggerConfigure_Default(ADCP_MODULE_ID index, ADCP_CLASS12_INPUT_ID inputId, ADCP_TRG_SRC triggerSource) 
{
	volatile adcp_registers_t * adcp = ((adcp_registers_t *)(index));
	uint32_t temp = inputId / 4;

    *((SFR_TYPE *)(&adcp->ADxTRG[temp])) = ( (*((SFR_TYPE *)(&adcp->ADxTRG[temp]))) & \
			~(ADxTRG1_TRGSRC0_MASK << ((inputId % 4) * ADxTRG1_TRGSRC1_POSITION)) ) \
			| ( (ADxTRG1_TRGSRC0_MASK << ((inputId % 4) * ADxTRG1_TRGSRC1_POSITION))&  \
			(triggerSource<<(ADxTRG1_TRGSRC1_POSITION * (inputId % 4)) )) ;		
}


//******************************************************************************

/* Function :  ADCP_GlobalSoftwareTrigger_Default

  Summary:
    Implements Default variant of PLIB_ADCP_GlobalSoftwareTrigger 

  Description:
    This template implements the Default variant of the PLIB_ADCP_GlobalSoftwareTrigger function.
 */

PLIB_TEMPLATE void ADCP_GlobalSoftwareTrigger_Default(ADCP_MODULE_ID index) 
{
	volatile adcp_registers_t * adcp = ((adcp_registers_t *)(index));
	adcp->ADxCON3.GSWTRG = 1;
}


//******************************************************************************

/* Function :  ADCP_IndividualTrigger_Default

  Summary:
    Implements Default variant of PLIB_ADCP_IndividualTrigger 

  Description:
    This template implements the Default variant of the PLIB_ADCP_IndividualTrigger function.
 */

PLIB_TEMPLATE void ADCP_IndividualTrigger_Default(ADCP_MODULE_ID index, ADCP_INPUT_ID inputId) 
{
	volatile adcp_registers_t * adcp = ((adcp_registers_t *)(index));
	adcp->ADxCON3.ADINSEL = inputId;
	adcp->ADxCON3.RQCONVRT = 1;
}


//******************************************************************************

/* Function :  ADCP_ExistsTriggering_Default

  Summary:
    Implements Default variant of PLIB_ADCP_ExistsTriggering

  Description:
    This template implements the Default variant of the PLIB_ADCP_ExistsTriggering function.
 */

#define PLIB_ADCP_ExistsTriggering PLIB_ADCP_ExistsTriggering
PLIB_TEMPLATE bool ADCP_ExistsTriggering_Default(ADCP_MODULE_ID index) {
    return true;
}


#endif /*_ADCP_TRIGGERING_DEFAULT_H*/

/******************************************************************************
 End of File
 */

