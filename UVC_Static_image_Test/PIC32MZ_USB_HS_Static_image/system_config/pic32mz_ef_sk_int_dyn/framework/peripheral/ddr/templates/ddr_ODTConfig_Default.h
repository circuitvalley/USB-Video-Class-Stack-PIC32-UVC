/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_ODTConfig_Default.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ODTConfig
    and its Variant : Default
    For following APIs :
        PLIB_DDR_OdtReadEnable
        PLIB_DDR_OdtReadDisable
        PLIB_DDR_OdtWriteEnable
        PLIB_DDR_OdtWriteDisable
        PLIB_DDR_OdtWriteParamSet
        PLIB_DDR_OdtReadParamSet
        PLIB_DDR_ExistsODTConfig

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

#ifndef _DDR_ODTCONFIG_DEFAULT_H
#define _DDR_ODTCONFIG_DEFAULT_H

//******************************************************************************
/* Function :  DDR_OdtReadEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_OdtReadEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_OdtReadEnable function.
*/

PLIB_TEMPLATE void DDR_OdtReadEnable_Default( DDR_MODULE_ID index , uint8_t odtCS )
{
	DDRODTCFGbits.ODTCSEN = odtCS;
	DDRODTENCFGbits.ODTREN = 1;
}


//******************************************************************************
/* Function :  DDR_OdtReadDisable_Default

  Summary:
    Implements Default variant of PLIB_DDR_OdtReadDisable 

  Description:
    This template implements the Default variant of the PLIB_DDR_OdtReadDisable function.
*/

PLIB_TEMPLATE void DDR_OdtReadDisable_Default( DDR_MODULE_ID index , uint8_t odtCS )
{
	DDRODTCFGbits.ODTCSEN = odtCS;
	DDRODTENCFGbits.ODTREN = 0;
}


//******************************************************************************
/* Function :  DDR_OdtWriteEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_OdtWriteEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_OdtWriteEnable function.
*/

PLIB_TEMPLATE void DDR_OdtWriteEnable_Default( DDR_MODULE_ID index , uint8_t odtCS )
{
	DDRODTCFGbits.ODTCSEN = odtCS;
	DDRODTENCFGbits.ODTWEN = 1;
}


//******************************************************************************
/* Function :  DDR_OdtWriteDisable_Default

  Summary:
    Implements Default variant of PLIB_DDR_OdtWriteDisable 

  Description:
    This template implements the Default variant of the PLIB_DDR_OdtWriteDisable function.
*/

PLIB_TEMPLATE void DDR_OdtWriteDisable_Default( DDR_MODULE_ID index , uint8_t odtCS )
{
	DDRODTCFGbits.ODTCSEN = odtCS;
	DDRODTENCFGbits.ODTWEN = 0;
}


//******************************************************************************
/* Function :  DDR_OdtWriteParamSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_OdtWriteParamSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_OdtWriteParamSet function.
*/

PLIB_TEMPLATE void DDR_OdtWriteParamSet_Default( DDR_MODULE_ID index , uint8_t wLen , uint8_t wDly )
{
	DDRODTCFGbits.ODTWLEN = wLen;
	DDRODTCFGbits.ODTWDLY = wDly;
}


//******************************************************************************
/* Function :  DDR_OdtReadParamSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_OdtReadParamSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_OdtReadParamSet function.
*/

PLIB_TEMPLATE void DDR_OdtReadParamSet_Default( DDR_MODULE_ID index , uint8_t rLen , uint8_t rDly )
{
	DDRODTCFGbits.ODTRLEN = rLen;
	DDRODTCFGbits.ODTRDLY = rDly;
}


//******************************************************************************
/* Function :  DDR_ExistsODTConfig_Default

  Summary:
    Implements Default variant of PLIB_DDR_ExistsODTConfig

  Description:
    This template implements the Default variant of the PLIB_DDR_ExistsODTConfig function.
*/

#define PLIB_DDR_ExistsODTConfig PLIB_DDR_ExistsODTConfig
PLIB_TEMPLATE bool DDR_ExistsODTConfig_Default( DDR_MODULE_ID index )
{
    return true;
}


#endif /*_DDR_ODTCONFIG_DEFAULT_H*/

/******************************************************************************
 End of File
*/

