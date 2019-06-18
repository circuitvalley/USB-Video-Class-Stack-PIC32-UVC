/*******************************************************************************
  ADCP Peripheral Library Template Implementation

  File Name:
    adcp_DigitalComparator_Default.h

  Summary:
    ADCP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DigitalComparator
    and its Variant : Default
    For following APIs :
        PLIB_ADCP_DigCmpConfig
        PLIB_ADCP_DigCmpEnable
        PLIB_ADCP_DigCmpDisable
        PLIB_ADCP_DigCmpAIdGet
        PLIB_ADCP_ExistsDigCmp

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

#ifndef _ADCP_DIGITALCOMPARATOR_DEFAULT_H
#define _ADCP_DIGITALCOMPARATOR_DEFAULT_H

#include "adcp_registers.h"

//******************************************************************************

/* Function :  ADCP_DigCmpConfig_Default

  Summary:
    Implements Default variant of PLIB_ADCP_DigCmpConfig 

  Description:
    This template implements the Default variant of the PLIB_ADCP_DigCmpConfig function.
 */

PLIB_TEMPLATE void ADCP_DigCmpConfig_Default(ADCP_MODULE_ID index, ADCP_DCMP_ID id, bool globalIntEnable, bool inBetweenOrEqual, bool greaterEqualHi, bool lessThanHi, bool greaterEqualLo, bool lessThanLo, uint32_t inputEnable, int32_t hiLimit, int32_t loLimit) 
{
	volatile adcp_registers_t * adcp = ((adcp_registers_t *)(index));
	
	*((uint32_t*)(&adcp->ADxCMPCON[id])) |= ((ADxCMPCONx_DCMPGIEN_MASK & (((uint32_t)globalIntEnable)<<ADxCMPCONx_DCMPGIEN_POSITION))|\
										(ADxCMPCONx_IEBTWN_MASK & (((uint32_t)inBetweenOrEqual)<<ADxCMPCONx_IEBTWN_POSITION)) | \
										(ADxCMPCONx_IEHIHI_MASK & (((uint32_t)greaterEqualHi)<<ADxCMPCONx_IEHIHI_POSITION)) | \
										(ADxCMPCONx_IEHILO_MASK & (((uint32_t)lessThanHi)<<ADxCMPCONx_IEHILO_POSITION)) | \
										(ADxCMPCONx_IELOHI_MASK & (((uint32_t)greaterEqualLo)<<ADxCMPCONx_IELOHI_POSITION)) |\
										(ADxCMPCONx_IELOLO_MASK & (((uint32_t)lessThanLo)<<ADxCMPCONx_IELOLO_POSITION))); 
	adcp->ADCCMPx[id].ADxCMPENx = inputEnable;
	adcp->ADCCMPx[id].ADxCMPx.ADCMPHI = hiLimit;
	adcp->ADCCMPx[id].ADxCMPx.ADCMPLO = loLimit;
}

//******************************************************************************

/* Function :  ADCP_DigCmpEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCP_DigCmpEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCP_DigCmpEnable function.
 */

PLIB_TEMPLATE void ADCP_DigCmpEnable_Default(ADCP_MODULE_ID index, ADCP_DCMP_ID id) 
{
	volatile adcp_registers_t * adcp = ((adcp_registers_t *)(index));
	adcp->ADxCMPCON[id].ENDCMP = 1;
}


//******************************************************************************

/* Function :  ADCP_DigCmpDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCP_DigCmpDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCP_DigCmpDisable function.
 */

PLIB_TEMPLATE void ADCP_DigCmpDisable_Default(ADCP_MODULE_ID index, ADCP_DCMP_ID id) 
{

	volatile adcp_registers_t * adcp = ((adcp_registers_t *)(index));
	adcp->ADxCMPCON[id].ENDCMP = 0;
}


//******************************************************************************

/* Function :  ADCP_DigCmpAIdGet_Default

  Summary:
    Implements Default variant of PLIB_ADCP_DigCmpAIdGet 

  Description:
    This template implements the Default variant of the PLIB_ADCP_DigCmpAIdGet function.
 */

PLIB_TEMPLATE int16_t ADCP_DigCmpAIdGet_Default(ADCP_MODULE_ID index, ADCP_DCMP_ID id)
{

	volatile adcp_registers_t * adcp = ((adcp_registers_t *)(index));
	return adcp->ADxCMPCON[id].DCMPED == 1 ? adcp->ADxCMPCON[id].AINID : -1;	
}


//******************************************************************************

/* Function :  ADCP_ExistsDigCmp_Default

  Summary:
    Implements Default variant of PLIB_ADCP_ExistsDigCmp

  Description:
    This template implements the Default variant of the PLIB_ADCP_ExistsDigCmp function.
 */

#define PLIB_ADCP_ExistsDigCmp PLIB_ADCP_ExistsDigCmp
PLIB_TEMPLATE bool ADCP_ExistsDigCmp_Default(ADCP_MODULE_ID index) 
{
    return true;
}


#endif /*_ADCP_DIGITALCOMPARATOR_DEFAULT_H*/

/******************************************************************************
 End of File
 */

