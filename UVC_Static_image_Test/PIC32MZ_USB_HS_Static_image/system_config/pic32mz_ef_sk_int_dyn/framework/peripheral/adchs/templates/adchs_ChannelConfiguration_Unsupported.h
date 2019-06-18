/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_ChannelConfiguration_Unsupported.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ChannelConfiguration
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCHS_ChannelConfigurationGet
        PLIB_ADCHS_ChannelConfigurationSet
        PLIB_ADCHS_ExistsChannelConfiguration

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

#ifndef _ADCHS_CHANNELCONFIGURATION_UNSUPPORTED_H
#define _ADCHS_CHANNELCONFIGURATION_UNSUPPORTED_H

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
/* Function :  ADCHS_ChannelConfigurationGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ChannelConfigurationGet 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ChannelConfigurationGet function.
*/

PLIB_TEMPLATE uint32_t ADCHS_ChannelConfigurationGet_Unsupported( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_ChannelConfigurationGet");

    return 0;
}


//******************************************************************************
/* Function :  ADCHS_ChannelConfigurationSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ChannelConfigurationSet 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ChannelConfigurationSet function.
*/

PLIB_TEMPLATE void ADCHS_ChannelConfigurationSet_Unsupported( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID , uint32_t config )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_ChannelConfigurationSet");
}


//******************************************************************************
/* Function :  ADCHS_ExistsChannelConfiguration_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ExistsChannelConfiguration

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ExistsChannelConfiguration function.
*/

PLIB_TEMPLATE bool ADCHS_ExistsChannelConfiguration_Unsupported( ADCHS_MODULE_ID index )
{
    return false;
}


#endif /*_ADCHS_CHANNELCONFIGURATION_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

