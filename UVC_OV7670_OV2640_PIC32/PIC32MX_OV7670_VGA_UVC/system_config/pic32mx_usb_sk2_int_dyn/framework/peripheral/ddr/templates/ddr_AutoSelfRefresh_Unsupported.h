/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_AutoSelfRefresh_Unsupported.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : AutoSelfRefresh
    and its Variant : Unsupported
    For following APIs :
        PLIB_DDR_AutoSelfRefreshEnable
        PLIB_DDR_AutoSelfRefreshDisable
        PLIB_DDR_ExistsAutoSelfRefresh

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

#ifndef _DDR_AUTOSELFREFRESH_UNSUPPORTED_H
#define _DDR_AUTOSELFREFRESH_UNSUPPORTED_H

//******************************************************************************
/* Function :  DDR_AutoSelfRefreshEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_AutoSelfRefreshEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_AutoSelfRefreshEnable function.
*/

PLIB_TEMPLATE void DDR_AutoSelfRefreshEnable_Unsupported( DDR_MODULE_ID index , uint16_t slfRefDly )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_AutoSelfRefreshEnable");
}


//******************************************************************************
/* Function :  DDR_AutoSelfRefreshDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_AutoSelfRefreshDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_AutoSelfRefreshDisable function.
*/

PLIB_TEMPLATE void DDR_AutoSelfRefreshDisable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_AutoSelfRefreshDisable");
}


//******************************************************************************
/* Function :  DDR_ExistsAutoSelfRefresh_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_ExistsAutoSelfRefresh

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_ExistsAutoSelfRefresh function.
*/

PLIB_TEMPLATE bool DDR_ExistsAutoSelfRefresh_Unsupported( DDR_MODULE_ID index )
{
    return false;
}


#endif /*_DDR_AUTOSELFREFRESH_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

