/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_Setup_pic32wk.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : Setup
    and its Variant : pic32wk
    For following APIs :
        PLIB_ADCHS_Setup
        PLIB_ADCHS_ChannelSetup
        PLIB_ADCHS_ExistsConfiguration

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

#ifndef _ADCHS_SETUP_PIC32WK_H
#define _ADCHS_SETUP_PIC32WK_H



//******************************************************************************
/* Function :  ADCHS_Setup_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_Setup 

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_Setup function.
*/

PLIB_TEMPLATE void ADCHS_Setup_pic32wk( ADCHS_MODULE_ID index , ADCHS_VREF_SOURCE voltageRefSelect , ADCHS_CHARGEPUMP_MODE chargePump , ADCHS_OUTPUT_DATA_FORMAT outputFormat , bool stopInIdle , ADCHS_FAST_SYNC_SYSTEM_CLOCK sysClk , ADCHS_FAST_SYNC_PERIPHERAL_CLOCK periClk , ADCHS_INTERRUPT_BIT_SHIFT_LEFT intVectorShift , uint16_t intVectorBase , ADCHS_CLOCK_SOURCE adcClockSource , int8_t adcClockDivider , ADCHS_WARMUP_CLOCK warmUpClock )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;
    volatile __ADCANCONbits_t *ADCANCON = (__ADCANCONbits_t *)&regs->ADCANCON;

    regs->ADCCON1.IRQVS = intVectorShift;
    regs->ADCCON1.FRACT = outputFormat;
    regs->ADCCON1.SIDL = stopInIdle;
    regs->ADCCON1.FSYDMA = sysClk;
    regs->ADCCON1.FSYUPB = periClk;

    regs->ADCCON3.VREFSEL = voltageRefSelect;
    regs->ADCCON3.ADCSEL = adcClockSource;
    regs->ADCCON3.CONCLKDIV = adcClockDivider;

    regs->ADCBASE = intVectorBase;

    ADCANCON->WKUPCLKCNT = warmUpClock;
}


//******************************************************************************
/* Function :  ADCHS_ChannelSetup_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_ChannelSetup 

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_ChannelSetup function.
*/

PLIB_TEMPLATE void ADCHS_ChannelSetup_pic32wk( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID , ADCHS_DATA_RESOLUTION res , uint8_t	channelClockDivider , uint16_t sampleTimeCount , ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK earlyInterruptClk )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;
    volatile uint32_t *ADCCON2 = (volatile uint32_t *)&regs->ADCCON2;
    uint32_t tempVal = 0;

    if (channelID == ADCHS_CHANNEL_7) {
	tempVal = *ADCCON2;
	tempVal &= ~(0x0000007F | 0x03FF0000);
	tempVal |= (uint32_t)(channelClockDivider);
	tempVal |= (uint32_t)(sampleTimeCount << 16);
	*ADCCON2 = tempVal;

	regs->ADCCON1.SELRES = res;
    } else {
	tempVal = regs->ADCxTIME[channelID].ADCxTIME;
	tempVal &= ~(0x000003FF | 0x007F0000 | 0x03000000);
	tempVal |= (uint32_t)(sampleTimeCount);
	tempVal |= (uint32_t)(channelClockDivider << 16);
	tempVal |= (uint32_t)(res << 24);
	regs->ADCxTIME[channelID].ADCxTIME = tempVal;
    }
}


//******************************************************************************
/* Function :  ADCHS_ExistsConfiguration_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_ExistsConfiguration

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_ExistsConfiguration function.
*/

#define PLIB_ADCHS_ExistsConfiguration PLIB_ADCHS_ExistsConfiguration
PLIB_TEMPLATE bool ADCHS_ExistsConfiguration_pic32wk( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_SETUP_PIC32WK_H*/

/******************************************************************************
 End of File
*/

