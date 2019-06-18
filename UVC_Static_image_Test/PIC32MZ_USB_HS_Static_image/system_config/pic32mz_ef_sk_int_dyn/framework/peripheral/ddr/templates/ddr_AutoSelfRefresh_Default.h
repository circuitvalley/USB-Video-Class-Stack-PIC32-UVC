/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_AutoSelfRefresh_Default.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : AutoSelfRefresh
    and its Variant : Default
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

#ifndef _DDR_AUTOSELFREFRESH_DEFAULT_H
#define _DDR_AUTOSELFREFRESH_DEFAULT_H

//******************************************************************************
/* Function :  DDR_AutoSelfRefreshEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_AutoSelfRefreshEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_AutoSelfRefreshEnable function.
*/

PLIB_TEMPLATE void DDR_AutoSelfRefreshEnable_Default( DDR_MODULE_ID index )
{
	DDRPWRCFGbits.ASLFREFEN = 1;
}


//******************************************************************************
/* Function :  DDR_AutoSelfRefreshDisable_Default

  Summary:
    Implements Default variant of PLIB_DDR_AutoSelfRefreshDisable 

  Description:
    This template implements the Default variant of the PLIB_DDR_AutoSelfRefreshDisable function.
*/

PLIB_TEMPLATE void DDR_AutoSelfRefreshDisable_Default( DDR_MODULE_ID index )
{
	DDRPWRCFGbits.ASLFREFEN = 0;
}


//******************************************************************************
/* Function :  DDR_ExistsAutoSelfRefresh_Default

  Summary:
    Implements Default variant of PLIB_DDR_ExistsAutoSelfRefresh

  Description:
    This template implements the Default variant of the PLIB_DDR_ExistsAutoSelfRefresh function.
*/

#define PLIB_DDR_ExistsAutoSelfRefresh PLIB_DDR_ExistsAutoSelfRefresh
PLIB_TEMPLATE bool DDR_ExistsAutoSelfRefresh_Default( DDR_MODULE_ID index )
{
    return true;
}


#endif /*_DDR_AUTOSELFREFRESH_DEFAULT_H*/

/******************************************************************************
 End of File
*/

