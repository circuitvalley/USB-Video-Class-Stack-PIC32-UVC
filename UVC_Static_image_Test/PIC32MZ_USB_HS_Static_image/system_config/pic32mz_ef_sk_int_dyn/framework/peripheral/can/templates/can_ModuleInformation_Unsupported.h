/*******************************************************************************
  CAN Peripheral Library Template Implementation

  File Name:
    can_ModuleInformation_Unsupported.h

  Summary:
    CAN PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ModuleInformation
    and its Variant : Unsupported
    For following APIs :
        PLIB_CAN_TotalChannelsGet
        PLIB_CAN_TotalFiltersGet
        PLIB_CAN_TotalMasksGet
        PLIB_CAN_ExistsModuleInfo

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _CAN_MODULEINFORMATION_UNSUPPORTED_H
#define _CAN_MODULEINFORMATION_UNSUPPORTED_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    None.

  MASKs: 
    None.

  POSs: 
    None.

  LENs: 
    None.

*/


//******************************************************************************
/* Function :  CAN_TotalChannelsGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_CAN_TotalChannelsGet 

  Description:
    This template implements the Unsupported variant of the PLIB_CAN_TotalChannelsGet function.
*/

PLIB_TEMPLATE char CAN_TotalChannelsGet_Unsupported( CAN_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_CAN_TotalChannelsGet");

    return 0;
}


//******************************************************************************
/* Function :  CAN_TotalFiltersGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_CAN_TotalFiltersGet 

  Description:
    This template implements the Unsupported variant of the PLIB_CAN_TotalFiltersGet function.
*/

PLIB_TEMPLATE char CAN_TotalFiltersGet_Unsupported( CAN_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_CAN_TotalFiltersGet");

    return 0;
}


//******************************************************************************
/* Function :  CAN_TotalMasksGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_CAN_TotalMasksGet 

  Description:
    This template implements the Unsupported variant of the PLIB_CAN_TotalMasksGet function.
*/

PLIB_TEMPLATE char CAN_TotalMasksGet_Unsupported( CAN_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_CAN_TotalMasksGet");

    return 0;
}


//******************************************************************************
/* Function :  CAN_ExistsModuleInfo_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_CAN_ExistsModuleInfo

  Description:
    This template implements the Unsupported variant of the PLIB_CAN_ExistsModuleInfo function.
*/

PLIB_TEMPLATE bool CAN_ExistsModuleInfo_Unsupported( CAN_MODULE_ID index )
{
    return false;
}


#endif /*_CAN_MODULEINFORMATION_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

