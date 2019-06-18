/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_RefreshConfig_Default.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : RefreshConfig
    and its Variant : Default
    For following APIs :
        PLIB_DDR_RefreshTimingSet
        PLIB_DDR_MaxPendingRefSet
        PLIB_DDR_ExistsRefreshConfig

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

#ifndef _DDR_REFRESHCONFIG_DEFAULT_H
#define _DDR_REFRESHCONFIG_DEFAULT_H

//******************************************************************************
/* Function :  DDR_RefreshTimingSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_RefreshTimingSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_RefreshTimingSet function.
*/

PLIB_TEMPLATE void DDR_RefreshTimingSet_Default( DDR_MODULE_ID index , uint32_t tRFC , uint32_t tRFI , uint32_t ctrlClkPer )
{
	DDRREFCFGbits.REFCNT = (tRFI + ctrlClkPer - 1) / ctrlClkPer - 2;
	DDRREFCFGbits.REFDLY = (tRFC + ctrlClkPer - 1) / ctrlClkPer - 2;
}


//******************************************************************************
/* Function :  DDR_MaxPendingRefSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_MaxPendingRefSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_MaxPendingRefSet function.
*/

PLIB_TEMPLATE void DDR_MaxPendingRefSet_Default( DDR_MODULE_ID index , uint8_t maxRefs )
{
	DDRREFCFGbits.MAXREFS = maxRefs;
}


//******************************************************************************
/* Function :  DDR_ExistsRefreshConfig_Default

  Summary:
    Implements Default variant of PLIB_DDR_ExistsRefreshConfig

  Description:
    This template implements the Default variant of the PLIB_DDR_ExistsRefreshConfig function.
*/

#define PLIB_DDR_ExistsRefreshConfig PLIB_DDR_ExistsRefreshConfig
PLIB_TEMPLATE bool DDR_ExistsRefreshConfig_Default( DDR_MODULE_ID index )
{
    return true;
}


#endif /*_DDR_REFRESHCONFIG_DEFAULT_H*/

/******************************************************************************
 End of File
*/

