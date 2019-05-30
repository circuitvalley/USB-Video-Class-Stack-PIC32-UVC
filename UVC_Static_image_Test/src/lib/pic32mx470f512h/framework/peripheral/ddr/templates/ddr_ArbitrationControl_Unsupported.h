/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_ArbitrationControl_Unsupported.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ArbitrationControl
    and its Variant : Unsupported
    For following APIs :
        PLIB_DDR_MinLimit
        PLIB_DDR_ReqPeriod
        PLIB_DDR_MinCommand
        PLIB_DDR_ExistsArbitrationControl

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

#ifndef _DDR_ARBITRATIONCONTROL_UNSUPPORTED_H
#define _DDR_ARBITRATIONCONTROL_UNSUPPORTED_H

//******************************************************************************
/* Function :  DDR_MinLimit_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_MinLimit 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_MinLimit function.
*/

PLIB_TEMPLATE void DDR_MinLimit_Unsupported( DDR_MODULE_ID index , uint8_t minLim , DDR_TARGET target )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_MinLimit");
}


//******************************************************************************
/* Function :  DDR_ReqPeriod_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_ReqPeriod 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_ReqPeriod function.
*/

PLIB_TEMPLATE void DDR_ReqPeriod_Unsupported( DDR_MODULE_ID index , uint8_t reqPer , DDR_TARGET target )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_ReqPeriod");
}


//******************************************************************************
/* Function :  DDR_MinCommand_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_MinCommand 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_MinCommand function.
*/

PLIB_TEMPLATE void DDR_MinCommand_Unsupported( DDR_MODULE_ID index , uint8_t minCmd , DDR_TARGET target )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_MinCommand");
}


//******************************************************************************
/* Function :  DDR_ExistsArbitrationControl_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_ExistsArbitrationControl

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_ExistsArbitrationControl function.
*/

PLIB_TEMPLATE bool DDR_ExistsArbitrationControl_Unsupported( DDR_MODULE_ID index )
{
    return false;
}


#endif /*_DDR_ARBITRATIONCONTROL_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

