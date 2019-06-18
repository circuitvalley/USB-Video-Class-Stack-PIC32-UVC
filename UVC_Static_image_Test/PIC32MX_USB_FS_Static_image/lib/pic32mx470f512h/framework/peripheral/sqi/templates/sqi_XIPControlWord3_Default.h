/*******************************************************************************
  SQI Peripheral Library Template Implementation

  File Name:
    sqi_XIPControlWord3_Default.h

  Summary:
    SQI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : XIPControlWord3
    and its Variant : Default
    For following APIs :
        PLIB_SQI_XIPControlWord3Set
        PLIB_SQI_XIPControlWord3Get
        PLIB_SQI_ExistsXIPControlWord3

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _SQI_XIPCONTROLWORD3_DEFAULT_H
#define _SQI_XIPCONTROLWORD3_DEFAULT_H

#include "sqi_registers.h"

//******************************************************************************
/* Function :  SQI_XIPControlWord3Set_Default

  Summary:
    Implements Default variant of PLIB_SQI_XIPControlWord3Set

  Description:
    This template implements the Default variant of the PLIB_SQI_XIPControlWord3Set function.
*/

PLIB_TEMPLATE void SQI_XIPControlWord3Set_Default( SQI_MODULE_ID index ,
						   bool initStatCheck ,
						   uint8_t initCmdCount ,
						   SQI_LANE_MODE initCmdType ,
						   uint8_t initCmd3 ,
						   uint8_t initCmd2 ,
						   uint8_t initCmd1 )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;

    sqi->SQIXCON3 = (initStatCheck << _SQI1XCON3_INIT1SCHECK_POSITION) |
		    (initCmdCount << _SQI1XCON3_INIT1COUNT_POSITION) |
		    (initCmdType << _SQI1XCON3_INIT1TYPE_POSITION) |
		    (initCmd3 << _SQI1XCON3_INIT1CMD3_POSITION) |
		    (initCmd2 << _SQI1XCON3_INIT1CMD2_POSITION) |
		    (initCmd1 << _SQI1XCON3_INIT1CMD1_POSITION);
}


//******************************************************************************
/* Function :  SQI_XIPControlWord3Get_Default

  Summary:
    Implements Default variant of PLIB_SQI_XIPControlWord3Get

  Description:
    This template implements the Default variant of the PLIB_SQI_XIPControlWord3Get function.
*/

PLIB_TEMPLATE uint32_t SQI_XIPControlWord3Get_Default( SQI_MODULE_ID   index )
{
    volatile sqi_registers_t *sqi = (volatile sqi_registers_t *)index;

    return sqi->SQIXCON3;
}


//******************************************************************************
/* Function :  SQI_ExistsXIPControlWord3_Default

  Summary:
    Implements Default variant of PLIB_SQI_ExistsXIPControlWord3

  Description:
    This template implements the Default variant of the PLIB_SQI_ExistsXIPControlWord3 function.
*/

#define PLIB_SQI_ExistsXIPControlWord3 PLIB_SQI_ExistsXIPControlWord3
PLIB_TEMPLATE bool SQI_ExistsXIPControlWord3_Default( SQI_MODULE_ID index )
{
    return true;
}


#endif /*_SQI_XIPCONTROLWORD3_DEFAULT_H*/

/******************************************************************************
 End of File
*/

