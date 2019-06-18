/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_AutoPrecharge_Unsupported.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : AutoPrecharge
    and its Variant : Unsupported
    For following APIs :
        PLIB_DDR_AutoPchrgEnable
        PLIB_DDR_AutoPchrgDisable
        PLIB_DDR_AutoPchrgPowerDownEnable
        PLIB_DDR_AutoPchrgPowerDownDisable
        PLIB_DDR_ExistsAutoPrecharge

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

#ifndef _DDR_AUTOPRECHARGE_UNSUPPORTED_H
#define _DDR_AUTOPRECHARGE_UNSUPPORTED_H

//******************************************************************************
/* Function :  DDR_AutoPchrgEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_AutoPchrgEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_AutoPchrgEnable function.
*/

PLIB_TEMPLATE void DDR_AutoPchrgEnable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_AutoPchrgEnable");
}


//******************************************************************************
/* Function :  DDR_AutoPchrgDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_AutoPchrgDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_AutoPchrgDisable function.
*/

PLIB_TEMPLATE void DDR_AutoPchrgDisable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_AutoPchrgDisable");
}


//******************************************************************************
/* Function :  DDR_AutoPchrgPowerDownEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_AutoPchrgPowerDownEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_AutoPchrgPowerDownEnable function.
*/

PLIB_TEMPLATE void DDR_AutoPchrgPowerDownEnable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_AutoPchrgPowerDownEnable");
}


//******************************************************************************
/* Function :  DDR_AutoPchrgPowerDownDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_AutoPchrgPowerDownDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_AutoPchrgPowerDownDisable function.
*/

PLIB_TEMPLATE void DDR_AutoPchrgPowerDownDisable_Unsupported( DDR_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_DDR_AutoPchrgPowerDownDisable");
}


//******************************************************************************
/* Function :  DDR_ExistsAutoPrecharge_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_DDR_ExistsAutoPrecharge

  Description:
    This template implements the Unsupported variant of the PLIB_DDR_ExistsAutoPrecharge function.
*/

PLIB_TEMPLATE bool DDR_ExistsAutoPrecharge_Unsupported( DDR_MODULE_ID index )
{
    return false;
}


#endif /*_DDR_AUTOPRECHARGE_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

