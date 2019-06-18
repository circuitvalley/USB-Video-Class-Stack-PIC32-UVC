/*******************************************************************************
  SQI Peripheral Library Template Implementation

  File Name:
    sqi_ControlWord_Default.h

  Summary:
    SQI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ControlWord
    and its Variant : Default
    For following APIs :
        PLIB_SQI_ControlWordSet
        PLIB_SQI_ControlWordGet
        PLIB_SQI_ExistsControlWord

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

#ifndef _SQI_CONTROLWORD_DEFAULT_H
#define _SQI_CONTROLWORD_DEFAULT_H

#include "sqi_registers.h"

//******************************************************************************
/* Function :  SQI_ControlWordSet_Default

  Summary:
    Implements Default variant of PLIB_SQI_ControlWordSet

  Description:
    This template implements the Default variant of the PLIB_SQI_ControlWordSet function.
*/

PLIB_TEMPLATE void SQI_ControlWordSet_Default( SQI_MODULE_ID index ,
					       bool csDeassert ,
					       SQI_CS_NUM csNum ,
					       SQI_LANE_MODE laneMode ,
					       SQI_XFER_CMD command ,
					       uint16_t xferCount )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;
    volatile uint32_t *SQICON = (volatile uint32_t *) &sqi->SQICON;

    *SQICON = (csDeassert << _SQI1CON_DASSERT_POSITION) |
	      (csNum << _SQI1CON_DEVSEL_POSITION) |
	      (laneMode << _SQI1CON_LANEMODE_POSITION) |
	      (command << _SQI1CON_CMDINIT_POSITION) |
	      (xferCount << _SQI1CON_TXRXCOUNT_POSITION);
}


//******************************************************************************
/* Function :  SQI_ControlWordGet_Default

  Summary:
    Implements Default variant of PLIB_SQI_ControlWordGet

  Description:
    This template implements the Default variant of the PLIB_SQI_ControlWordGet function.
*/

PLIB_TEMPLATE uint32_t SQI_ControlWordGet_Default( SQI_MODULE_ID index )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;
    volatile uint32_t *SQICON = (volatile uint32_t *) &sqi->SQICON;

    return *SQICON;
}


//******************************************************************************
/* Function :  SQI_ExistsControlWord_Default

  Summary:
    Implements Default variant of PLIB_SQI_ExistsControlWord

  Description:
    This template implements the Default variant of the PLIB_SQI_ExistsControlWord function.
*/

#define PLIB_SQI_ExistsControlWord PLIB_SQI_ExistsControlWord
PLIB_TEMPLATE bool SQI_ExistsControlWord_Default( SQI_MODULE_ID index )
{
    return true;
}


#endif /*_SQI_CONTROLWORD_DEFAULT_H*/

/******************************************************************************
 End of File
*/

