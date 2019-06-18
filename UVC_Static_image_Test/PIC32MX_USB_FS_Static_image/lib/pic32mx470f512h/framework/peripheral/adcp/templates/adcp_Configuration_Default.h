/*******************************************************************************
  ADCP Peripheral Library Template Implementation

  File Name:
    adcp_Configuration_Default.h

  Summary:
    ADCP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : Configuration
    and its Variant : Default
    For following APIs :
        PLIB_ADCP_Configure
        PLIB_ADCP_ExistsConfiguration

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

#ifndef _ADCP_CONFIGURATION_DEFAULT_H
#define _ADCP_CONFIGURATION_DEFAULT_H

#include "adcp_registers.h"

//******************************************************************************

/* Function :  ADCP_Configure_Default

  Summary:
    Implements Default variant of PLIB_ADCP_Configure 

  Description:
    This template implements the Default variant of the PLIB_ADCP_Configure function.
 */

PLIB_TEMPLATE void ADCP_Configure_Default ( ADCP_MODULE_ID index , ADCP_VREF_SOURCE voltageRefSelect , bool boostVref , bool fractionalOutputOn , bool stopInIdle ,
        ADCP_CLOCK_SOURCE adcClockSource , int8_t adcClockDivider , int8_t oversampleDigFilterSamTime , int8_t earlyIntEnable , int8_t class2and3SampleTime )
{
	volatile adcp_registers_t *adcp = ((adcp_registers_t *)(index));

	adcp->ADxCON3.VREFSEL = voltageRefSelect;
	*((uint32_t*)(&adcp->ADxCON1)) |= ((_AD1CON1_FRACT_MASK & (((uint32_t)fractionalOutputOn) << _AD1CON1_FRACT_POSITION)) | \
								  (_AD1CON1_ADSIDL_MASK & (((uint32_t)stopInIdle) << _AD1CON1_ADSIDL_POSITION)) | \
					              (_AD1CON1_FILTRDLY_MASK & (((uint32_t)oversampleDigFilterSamTime) << _AD1CON1_FILTRDLY_POSITION)) | \
					              (_AD1CON1_EIE_MASK & (((uint32_t)earlyIntEnable) << _AD1CON1_EIE_POSITION))) ;
	*((uint32_t*)(&adcp->ADxCON2)) |= ((_AD1CON2_BOOST_MASK & (((uint32_t)boostVref) << _AD1CON2_BOOST_POSITION)) | \
						          (_AD1CON2_ADCSEL_MASK & (((uint32_t)adcClockSource) << _AD1CON2_ADCSEL_POSITION)) |\
								  (_AD1CON2_ADCDIV_MASK & (((uint32_t)adcClockDivider) << _AD1CON2_ADCDIV_POSITION)) | \
								  (_AD1CON2_SAMC_MASK & (((uint32_t)class2and3SampleTime) << _AD1CON2_SAMC_POSITION)));
    adcp->ADxCAL[0] = DEVADC1;
	adcp->ADxCAL[1] = DEVADC2;
	adcp->ADxCAL[2] = DEVADC3;
	adcp->ADxCAL[3] = DEVADC4;
	adcp->ADxCAL[4] = DEVADC5;
}


//******************************************************************************

/* Function :  ADCP_ExistsConfiguration_Default

  Summary:
    Implements Default variant of PLIB_ADCP_ExistsConfiguration

  Description:
    This template implements the Default variant of the PLIB_ADCP_ExistsConfiguration function.
 */

#define PLIB_ADCP_ExistsConfiguration PLIB_ADCP_ExistsConfiguration
PLIB_TEMPLATE bool ADCP_ExistsConfiguration_Default ( ADCP_MODULE_ID index )
{
    return true ;
}


#endif /*_ADCP_CONFIGURATION_DEFAULT_H*/

/******************************************************************************
 End of File
 */

