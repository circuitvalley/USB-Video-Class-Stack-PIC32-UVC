/*******************************************************************************
  SQI Peripheral Library Template Implementation

  File Name:
    sqi_LaneMode_Default.h

  Summary:
    SQI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : LaneMode
    and its Variant : Default
    For following APIs :
        PLIB_SQI_LaneModeSet
        PLIB_SQI_LaneModeGet
        PLIB_SQI_ExistsLaneMode

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

#ifndef _SQI_LANEMODE_DEFAULT_H
#define _SQI_LANEMODE_DEFAULT_H

#include "sqi_registers.h"

//******************************************************************************
/* Function :  SQI_LaneModeSet_Default

  Summary:
    Implements Default variant of PLIB_SQI_LaneModeSet

  Description:
    This template implements the Default variant of the PLIB_SQI_LaneModeSet function.
*/

PLIB_TEMPLATE void SQI_LaneModeSet_Default( SQI_MODULE_ID index , SQI_LANE_MODE mode )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;
    sqi->SQICON.LANEMODE = mode;
}


//******************************************************************************
/* Function :  SQI_LaneModeGet_Default

  Summary:
    Implements Default variant of PLIB_SQI_LaneModeGet

  Description:
    This template implements the Default variant of the PLIB_SQI_LaneModeGet function.
*/

PLIB_TEMPLATE SQI_LANE_MODE SQI_LaneModeGet_Default( SQI_MODULE_ID index )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;
    return (SQI_LANE_MODE) sqi->SQICON.LANEMODE;
}


//******************************************************************************
/* Function :  SQI_ExistsLaneMode_Default

  Summary:
    Implements Default variant of PLIB_SQI_ExistsLaneMode

  Description:
    This template implements the Default variant of the PLIB_SQI_ExistsLaneMode function.
*/

#define PLIB_SQI_ExistsLaneMode PLIB_SQI_ExistsLaneMode
PLIB_TEMPLATE bool SQI_ExistsLaneMode_Default( SQI_MODULE_ID index )
{
    return true;
}


#endif /*_SQI_LANEMODE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

