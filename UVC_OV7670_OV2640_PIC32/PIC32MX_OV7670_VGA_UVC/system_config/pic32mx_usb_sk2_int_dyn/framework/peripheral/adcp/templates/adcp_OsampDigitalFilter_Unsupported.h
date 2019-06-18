/*******************************************************************************
  ADCP Peripheral Library Template Implementation

  File Name:
    adcp_OsampDigitalFilter_Unsupported.h

  Summary:
    ADCP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : OsampDigitalFilter
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCP_OsampDigFilterConfig
        PLIB_ADCP_OsampDigFilterEnable
        PLIB_ADCP_OsampDigFilterDisable
        PLIB_ADCP_OsampDigFilterDataRdy
        PLIB_ADCP_OsampDigFilterDataGet
        PLIB_ADCP_ExistsOsampDigFilter

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

#ifndef _ADCP_OSAMPDIGITALFILTER_UNSUPPORTED_H
#define _ADCP_OSAMPDIGITALFILTER_UNSUPPORTED_H

//******************************************************************************
/* Function :  ADCP_OsampDigFilterConfig_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCP_OsampDigFilterConfig 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCP_OsampDigFilterConfig function.
*/

PLIB_TEMPLATE void ADCP_OsampDigFilterConfig_Unsupported( ADCP_MODULE_ID index , ADCP_ODFLTR_ID id , ADCP_INPUT_ID inputId , ADCP_ODFLTR_SAMPLE_RATIO oversampleRatio , bool globalIntEnable )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCP_OsampDigFilterConfig");
}


//******************************************************************************
/* Function :  ADCP_OsampDigFilterEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCP_OsampDigFilterEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCP_OsampDigFilterEnable function.
*/

PLIB_TEMPLATE void ADCP_OsampDigFilterEnable_Unsupported( ADCP_MODULE_ID index , ADCP_ODFLTR_ID id )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCP_OsampDigFilterEnable");
}


//******************************************************************************
/* Function :  ADCP_OsampDigFilterDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCP_OsampDigFilterDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCP_OsampDigFilterDisable function.
*/

PLIB_TEMPLATE void ADCP_OsampDigFilterDisable_Unsupported( ADCP_MODULE_ID index , ADCP_ODFLTR_ID id )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCP_OsampDigFilterDisable");
}


//******************************************************************************
/* Function :  ADCP_OsampDigFilterDataRdy_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCP_OsampDigFilterDataRdy 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCP_OsampDigFilterDataRdy function.
*/

PLIB_TEMPLATE bool ADCP_OsampDigFilterDataRdy_Unsupported( ADCP_MODULE_ID index , ADCP_ODFLTR_ID id )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCP_OsampDigFilterDataRdy");

    return false;
}


//******************************************************************************
/* Function :  ADCP_OsampDigFilterDataGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCP_OsampDigFilterDataGet 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCP_OsampDigFilterDataGet function.
*/

PLIB_TEMPLATE int16_t ADCP_OsampDigFilterDataGet_Unsupported( ADCP_MODULE_ID index , ADCP_ODFLTR_ID dfltrID )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCP_OsampDigFilterDataGet");

    return 0;
}


//******************************************************************************
/* Function :  ADCP_ExistsOsampDigFilter_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCP_ExistsOsampDigFilter

  Description:
    This template implements the Unsupported variant of the PLIB_ADCP_ExistsOsampDigFilter function.
*/

PLIB_TEMPLATE bool ADCP_ExistsOsampDigFilter_Unsupported( ADCP_MODULE_ID index )
{
    return false;
}


#endif /*_ADCP_OSAMPDIGITALFILTER_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

