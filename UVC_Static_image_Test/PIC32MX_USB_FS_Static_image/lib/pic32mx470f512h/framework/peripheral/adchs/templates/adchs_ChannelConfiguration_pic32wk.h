/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_ChannelConfiguration_pic32wk.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ChannelConfiguration
    and its Variant : pic32wk
    For following APIs :
        PLIB_ADCHS_ChannelConfigurationGet
        PLIB_ADCHS_ChannelConfigurationSet
        PLIB_ADCHS_ExistsChannelConfiguration

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _ADCHS_CHANNELCONFIGURATION_PIC32WK_H
#define _ADCHS_CHANNELCONFIGURATION_PIC32WK_H



//******************************************************************************
/* Function :  ADCHS_ChannelConfigurationGet_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_ChannelConfigurationGet 

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_ChannelConfigurationGet function.
*/

PLIB_TEMPLATE uint32_t ADCHS_ChannelConfigurationGet_pic32wk( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    return regs->ADCxCFG[channelID].ADCxCFG;
}


//******************************************************************************
/* Function :  ADCHS_ChannelConfigurationSet_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_ChannelConfigurationSet 

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_ChannelConfigurationSet function.
*/

PLIB_TEMPLATE void ADCHS_ChannelConfigurationSet_pic32wk( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID , uint32_t config )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCxCFG[channelID].ADCxCFG = config;
}


//******************************************************************************
/* Function :  ADCHS_ExistsChannelConfiguration_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_ExistsChannelConfiguration

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_ExistsChannelConfiguration function.
*/

#define PLIB_ADCHS_ExistsChannelConfiguration PLIB_ADCHS_ExistsChannelConfiguration
PLIB_TEMPLATE bool ADCHS_ExistsChannelConfiguration_pic32wk( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_CHANNELCONFIGURATION_PIC32WK_H*/

/******************************************************************************
 End of File
*/

