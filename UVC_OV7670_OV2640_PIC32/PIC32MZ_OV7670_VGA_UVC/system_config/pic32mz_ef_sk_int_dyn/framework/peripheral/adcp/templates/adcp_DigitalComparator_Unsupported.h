/*******************************************************************************
  ADCP Peripheral Library Template Implementation

  File Name:
    adcp_DigitalComparator_Unsupported.h

  Summary:
    ADCP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DigitalComparator
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCP_DigCmpConfig
        PLIB_ADCP_DigCmpEnable
        PLIB_ADCP_DigCmpDisable
        PLIB_ADCP_DigCmpAIdGet
        PLIB_ADCP_ExistsDigCmp

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

#ifndef _ADCP_DIGITALCOMPARATOR_UNSUPPORTED_H
#define _ADCP_DIGITALCOMPARATOR_UNSUPPORTED_H

//******************************************************************************
/* Function :  ADCP_DigCmpConfig_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCP_DigCmpConfig 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCP_DigCmpConfig function.
*/

PLIB_TEMPLATE void ADCP_DigCmpConfig_Unsupported( ADCP_MODULE_ID index , ADCP_DCMP_ID id , bool globalIntEnable , bool inBetweenOrEqual , bool greaterEqualHi , bool lessThanHi , bool greaterEqualLo , bool lessThanLo , ADCP_ENABLE_LOW_INPUT inputEnable , int32_t  hiLimit , int32_t  loLimit )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCP_DigCmpConfig");
}


//******************************************************************************
/* Function :  ADCP_DigCmpEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCP_DigCmpEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCP_DigCmpEnable function.
*/

PLIB_TEMPLATE void ADCP_DigCmpEnable_Unsupported( ADCP_MODULE_ID index , ADCP_DCMP_ID id )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCP_DigCmpEnable");
}


//******************************************************************************
/* Function :  ADCP_DigCmpDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCP_DigCmpDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCP_DigCmpDisable function.
*/

PLIB_TEMPLATE void ADCP_DigCmpDisable_Unsupported( ADCP_MODULE_ID index , ADCP_DCMP_ID id )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCP_DigCmpDisable");
}


//******************************************************************************
/* Function :  ADCP_DigCmpAIdGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCP_DigCmpAIdGet 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCP_DigCmpAIdGet function.
*/

PLIB_TEMPLATE int16_t ADCP_DigCmpAIdGet_Unsupported( ADCP_MODULE_ID index , ADCP_DCMP_ID id )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCP_DigCmpAIdGet");

    return 0;
}


//******************************************************************************
/* Function :  ADCP_ExistsDigCmp_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCP_ExistsDigCmp

  Description:
    This template implements the Unsupported variant of the PLIB_ADCP_ExistsDigCmp function.
*/

PLIB_TEMPLATE bool ADCP_ExistsDigCmp_Unsupported( ADCP_MODULE_ID index )
{
    return false;
}


#endif /*_ADCP_DIGITALCOMPARATOR_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

