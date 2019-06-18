/*******************************************************************************
  SQI Peripheral Library Template Implementation

  File Name:
    sqi_XIPControlWord2_Unsupported.h

  Summary:
    SQI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : XIPControlWord2
    and its Variant : Unsupported
    For following APIs :
        PLIB_SQI_XIPControlWord2Set
        PLIB_SQI_XIPControlWord2Get
        PLIB_SQI_ExistsXIPControlWord2

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

#ifndef _SQI_XIPCONTROLWORD2_UNSUPPORTED_H
#define _SQI_XIPCONTROLWORD2_UNSUPPORTED_H

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
/* Function :  SQI_XIPControlWord2Set_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_XIPControlWord2Set 

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_XIPControlWord2Set function.
*/

PLIB_TEMPLATE void SQI_XIPControlWord2Set_Unsupported( SQI_MODULE_ID   index , SQI_CS_NUM       devSelect , SQI_MODE_BYTES  modeBytes , uint8_t           modeCode )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_SQI_XIPControlWord2Set");
}


//******************************************************************************
/* Function :  SQI_XIPControlWord2Get_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_XIPControlWord2Get 

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_XIPControlWord2Get function.
*/

PLIB_TEMPLATE uint32_t SQI_XIPControlWord2Get_Unsupported( SQI_MODULE_ID   index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_SQI_XIPControlWord2Get");

    return 0;
}


//******************************************************************************
/* Function :  SQI_ExistsXIPControlWord2_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_ExistsXIPControlWord2

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_ExistsXIPControlWord2 function.
*/

PLIB_TEMPLATE bool SQI_ExistsXIPControlWord2_Unsupported( SQI_MODULE_ID index )
{
    return false;
}


#endif /*_SQI_XIPCONTROLWORD2_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

