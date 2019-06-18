/*******************************************************************************
  SQI Peripheral Library Template Implementation

  File Name:
    sqi_ConfigWord_Unsupported.h

  Summary:
    SQI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ConfigWord
    and its Variant : Unsupported
    For following APIs :
        PLIB_SQI_ConfigWordSet
        PLIB_SQI_ConfigWordGet
        PLIB_SQI_ExistsConfigWord

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

#ifndef _SQI_CONFIGWORD_UNSUPPORTED_H
#define _SQI_CONFIGWORD_UNSUPPORTED_H

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
/* Function :  SQI_ConfigWordSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_ConfigWordSet 

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_ConfigWordSet function.
*/

PLIB_TEMPLATE void SQI_ConfigWordSet_Unsupported( SQI_MODULE_ID index , bool sqiEnable , SQI_CS_OEN csPins , SQI_DATA_OEN dataPins , bool reset , bool burstEn , bool hold , bool writeProtect , bool rxLatch , SQI_DATA_FORMAT lsbf , SQI_DATA_MODE dataMode , SQI_XFER_MODE xferMode )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_SQI_ConfigWordSet");
}


//******************************************************************************
/* Function :  SQI_ConfigWordGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_ConfigWordGet 

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_ConfigWordGet function.
*/

PLIB_TEMPLATE uint32_t SQI_ConfigWordGet_Unsupported( SQI_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_SQI_ConfigWordGet");

    return 0;
}


//******************************************************************************
/* Function :  SQI_ExistsConfigWord_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_SQI_ExistsConfigWord

  Description:
    This template implements the Unsupported variant of the PLIB_SQI_ExistsConfigWord function.
*/

PLIB_TEMPLATE bool SQI_ExistsConfigWord_Unsupported( SQI_MODULE_ID index )
{
    return false;
}


#endif /*_SQI_CONFIGWORD_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

