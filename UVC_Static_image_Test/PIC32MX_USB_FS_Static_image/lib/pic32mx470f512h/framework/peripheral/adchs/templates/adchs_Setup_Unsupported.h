/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_Setup_Unsupported.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : Setup
    and its Variant : Unsupported
    For following APIs :
        PLIB_ADCHS_Setup
        PLIB_ADCHS_ChannelSetup
        PLIB_ADCHS_ExistsConfiguration

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

#ifndef _ADCHS_SETUP_UNSUPPORTED_H
#define _ADCHS_SETUP_UNSUPPORTED_H

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
/* Function :  ADCHS_Setup_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_Setup 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_Setup function.
*/

PLIB_TEMPLATE void ADCHS_Setup_Unsupported( ADCHS_MODULE_ID index , ADCHS_VREF_SOURCE voltageRefSelect , ADCHS_CHARGEPUMP_MODE chargePump , ADCHS_OUTPUT_DATA_FORMAT outputFormat , bool stopInIdle , ADCHS_FAST_SYNC_SYSTEM_CLOCK sysClk , ADCHS_FAST_SYNC_PERIPHERAL_CLOCK periClk , ADCHS_INTERRUPT_BIT_SHIFT_LEFT intVectorShift , uint16_t intVectorBase , ADCHS_CLOCK_SOURCE adcClockSource , int8_t adcClockDivider , ADCHS_WARMUP_CLOCK warmUpClock )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_Setup");
}


//******************************************************************************
/* Function :  ADCHS_ChannelSetup_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ChannelSetup 

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ChannelSetup function.
*/

PLIB_TEMPLATE void ADCHS_ChannelSetup_Unsupported( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID , ADCHS_DATA_RESOLUTION res , uint8_t	channelClockDivider , uint16_t sampleTimeCount , ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK earlyInterruptClk )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_ADCHS_ChannelSetup");
}


//******************************************************************************
/* Function :  ADCHS_ExistsConfiguration_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_ADCHS_ExistsConfiguration

  Description:
    This template implements the Unsupported variant of the PLIB_ADCHS_ExistsConfiguration function.
*/

PLIB_TEMPLATE bool ADCHS_ExistsConfiguration_Unsupported( ADCHS_MODULE_ID index )
{
    return false;
}


#endif /*_ADCHS_SETUP_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

