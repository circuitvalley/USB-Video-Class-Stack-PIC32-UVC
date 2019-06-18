/*******************************************************************************
  SQI Peripheral Library Template Implementation

  File Name:
    sqi_DataModeControl_Default.h

  Summary:
    SQI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DataModeControl
    and its Variant : Default
    For following APIs :
        PLIB_SQI_DataModeSet
        PLIB_SQI_ExistsDataModeControl

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

#ifndef _SQI_DATAMODECONTROL_DEFAULT_H
#define _SQI_DATAMODECONTROL_DEFAULT_H

#include "sqi_registers.h"

//******************************************************************************
/* Function :  SQI_DataModeSet_Default

  Summary:
    Implements Default variant of PLIB_SQI_DataModeSet

  Description:
    This template implements the Default variant of the PLIB_SQI_DataModeSet function.
*/

PLIB_TEMPLATE void SQI_DataModeSet_Default( SQI_MODULE_ID index , SQI_DATA_MODE mode )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;

    if (mode == SQI_DATA_MODE_3)
    {
	sqi->SQICFG.CPOL = 1;
	sqi->SQICFG.CPHA = 1;
    }
    else if(mode == SQI_DATA_MODE_0)
    {
	sqi->SQICFG.CPOL = 0;
	sqi->SQICFG.CPHA = 0;
    }
    else
    {
	sqi->SQICFG.CPOL = 1;
	sqi->SQICFG.CPHA = 1;
    }
}


//******************************************************************************
/* Function :  SQI_ExistsDataModeControl_Default

  Summary:
    Implements Default variant of PLIB_SQI_ExistsDataModeControl

  Description:
    This template implements the Default variant of the PLIB_SQI_ExistsDataModeControl function.
*/

#define PLIB_SQI_ExistsDataModeControl PLIB_SQI_ExistsDataModeControl
PLIB_TEMPLATE bool SQI_ExistsDataModeControl_Default( SQI_MODULE_ID index )
{
    return true;
}


#endif /*_SQI_DATAMODECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

