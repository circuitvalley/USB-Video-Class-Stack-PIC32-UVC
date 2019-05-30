/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_AutoPowerDown_Default.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : AutoPowerDown
    and its Variant : Default
    For following APIs :
        PLIB_DDR_AutoPowerDownEnable
        PLIB_DDR_AutoPowerDownDisable
        PLIB_DDR_ExistsAutoPowerDown

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

#ifndef _DDR_AUTOPOWERDOWN_DEFAULT_H
#define _DDR_AUTOPOWERDOWN_DEFAULT_H

//******************************************************************************
/* Function :  DDR_AutoPowerDownEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_AutoPowerDownEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_AutoPowerDownEnable function.
*/

PLIB_TEMPLATE void DDR_AutoPowerDownEnable_Default( DDR_MODULE_ID index )
{
	DDRPWRCFGbits.APWRDNEN = 1;
}


//******************************************************************************
/* Function :  DDR_AutoPowerDownDisable_Default

  Summary:
    Implements Default variant of PLIB_DDR_AutoPowerDownDisable 

  Description:
    This template implements the Default variant of the PLIB_DDR_AutoPowerDownDisable function.
*/

PLIB_TEMPLATE void DDR_AutoPowerDownDisable_Default( DDR_MODULE_ID index )
{
	DDRPWRCFGbits.APWRDNEN = 0;
}


//******************************************************************************
/* Function :  DDR_ExistsAutoPowerDown_Default

  Summary:
    Implements Default variant of PLIB_DDR_ExistsAutoPowerDown

  Description:
    This template implements the Default variant of the PLIB_DDR_ExistsAutoPowerDown function.
*/

#define PLIB_DDR_ExistsAutoPowerDown PLIB_DDR_ExistsAutoPowerDown
PLIB_TEMPLATE bool DDR_ExistsAutoPowerDown_Default( DDR_MODULE_ID index )
{
    return true;
}


#endif /*_DDR_AUTOPOWERDOWN_DEFAULT_H*/

/******************************************************************************
 End of File
*/

