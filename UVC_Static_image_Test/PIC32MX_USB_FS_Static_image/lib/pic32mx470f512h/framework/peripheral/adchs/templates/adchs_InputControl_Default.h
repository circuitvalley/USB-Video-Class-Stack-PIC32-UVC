/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_InputControl_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : InputControl
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_ChannelInputSelect
        PLIB_ADCHS_ExistsChannelInputSelectControl

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

#ifndef _ADCHS_INPUTCONTROL_DEFAULT_H
#define _ADCHS_INPUTCONTROL_DEFAULT_H



//******************************************************************************
/* Function :  ADCHS_ChannelInputSelect_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ChannelInputSelect 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ChannelInputSelect function.
    Operation is not atomic.
*/               
PLIB_TEMPLATE bool ADCHS_ChannelInputSelect_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID , ADCHS_CHANNEL_INP_SEL sel )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

#ifndef CHECON /* PIC32MZ */
    regs->ADCTRGMODE &= ~(3 << (2 * channelID)  <<16); 
    regs->ADCTRGMODE |= (sel - 4 * channelID) << (2 * channelID)  << 16; 
#else /*PIC32MK */
    regs->ADCTRGMODE.bits &= ~(3 << (2 * channelID)  <<16); 
    regs->ADCTRGMODE.bits |= (sel - 4 * channelID) << (2 * channelID)  << 16; 
#endif

    return true;
}


//******************************************************************************
/* Function :  ADCHS_ExistsChannelInputSelectControl_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsChannelInputSelectControl

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsChannelInputSelectControl function.
*/

#define PLIB_ADCHS_ExistsChannelInputSelectControl PLIB_ADCHS_ExistsChannelInputSelectControl
PLIB_TEMPLATE bool ADCHS_ExistsChannelInputSelectControl_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_INPUTCONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

