/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_AutoPrecharge_Default.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : AutoPrecharge
    and its Variant : Default
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

#ifndef _DDR_AUTOPRECHARGE_DEFAULT_H
#define _DDR_AUTOPRECHARGE_DEFAULT_H

//******************************************************************************
/* Function :  DDR_AutoPchrgEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_AutoPchrgEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_AutoPchrgEnable function.
*/

PLIB_TEMPLATE void DDR_AutoPchrgEnable_Default( DDR_MODULE_ID index )
{
	DDRMEMCFG0bits.APCHRGEN = 1;
}


//******************************************************************************
/* Function :  DDR_AutoPchrgDisable_Default

  Summary:
    Implements Default variant of PLIB_DDR_AutoPchrgDisable 

  Description:
    This template implements the Default variant of the PLIB_DDR_AutoPchrgDisable function.
*/

PLIB_TEMPLATE void DDR_AutoPchrgDisable_Default( DDR_MODULE_ID index )
{
	DDRMEMCFG0bits.APCHRGEN = 0;
}


//******************************************************************************
/* Function :  DDR_AutoPchrgPowerDownEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_AutoPchrgPowerDownEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_AutoPchrgPowerDownEnable function.
*/

PLIB_TEMPLATE void DDR_AutoPchrgPowerDownEnable_Default( DDR_MODULE_ID index )
{
	DDRPWRCFGbits.PCHRGPWRDN = 1;
}


//******************************************************************************
/* Function :  DDR_AutoPchrgPowerDownDisable_Default

  Summary:
    Implements Default variant of PLIB_DDR_AutoPchrgPowerDownDisable 

  Description:
    This template implements the Default variant of the PLIB_DDR_AutoPchrgPowerDownDisable function.
*/

PLIB_TEMPLATE void DDR_AutoPchrgPowerDownDisable_Default( DDR_MODULE_ID index )
{
	DDRPWRCFGbits.PCHRGPWRDN = 0;
}


//******************************************************************************
/* Function :  DDR_ExistsAutoPrecharge_Default

  Summary:
    Implements Default variant of PLIB_DDR_ExistsAutoPrecharge

  Description:
    This template implements the Default variant of the PLIB_DDR_ExistsAutoPrecharge function.
*/

#define PLIB_DDR_ExistsAutoPrecharge PLIB_DDR_ExistsAutoPrecharge
PLIB_TEMPLATE bool DDR_ExistsAutoPrecharge_Default( DDR_MODULE_ID index )
{
    return true;
}


#endif /*_DDR_AUTOPRECHARGE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

