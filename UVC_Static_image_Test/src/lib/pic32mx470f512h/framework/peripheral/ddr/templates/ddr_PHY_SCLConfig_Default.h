/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_PHY_SCLConfig_Default.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : PHY_SCLConfig
    and its Variant : Default
    For following APIs :
        PLIB_DDR_PHY_SCLTestBurstModeSet
        PLIB_DDR_PHY_DDRTypeSet
        PLIB_DDR_PHY_ReadCASLatencySet
        PLIB_DDR_PHY_WriteCASLatencySet
        PLIB_DDR_PHY_OdtCSEnable
        PLIB_DDR_PHY_OdtCSDisable
        PLIB_DDR_PHY_SCLDelay
        PLIB_DDR_PHY_SCLEnable
        PLIB_DDR_PHY_SCLDDRClkDelaySet
        PLIB_DDR_PHY_SCLCapClkDelaySet
        PLIB_DDR_PHY_SCLStart
        PLIB_DDR_PHY_SCLStatus
        PLIB_DDR_ExistsPHY_SCLConfig

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

#ifndef _DDR_PHY_SCLCONFIG_DEFAULT_H
#define _DDR_PHY_SCLCONFIG_DEFAULT_H

//******************************************************************************
/* Function :  DDR_PHY_SCLTestBurstModeSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_SCLTestBurstModeSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_SCLTestBurstModeSet function.
*/

PLIB_TEMPLATE void DDR_PHY_SCLTestBurstModeSet_Default( DDR_MODULE_ID index , DDR_PHY_SCL_BURST_MODE brstMode )
{
	DDRSCLCFG0bits.BURST8 = brstMode;
}


//******************************************************************************
/* Function :  DDR_PHY_DDRTypeSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_DDRTypeSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_DDRTypeSet function.
*/

PLIB_TEMPLATE void DDR_PHY_DDRTypeSet_Default( DDR_MODULE_ID index , DDR_PHY_DDR_TYPE ddrType )
{
	DDRSCLCFG0bits.DDR2 = !ddrType;
}


//******************************************************************************
/* Function :  DDR_PHY_ReadCASLatencySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_ReadCASLatencySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_ReadCASLatencySet function.
*/

PLIB_TEMPLATE void DDR_PHY_ReadCASLatencySet_Default( DDR_MODULE_ID index , uint8_t rLat )
{
	DDRSCLCFG0bits.RCASLAT = rLat;
}


//******************************************************************************
/* Function :  DDR_PHY_WriteCASLatencySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_WriteCASLatencySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_WriteCASLatencySet function.
*/

PLIB_TEMPLATE void DDR_PHY_WriteCASLatencySet_Default( DDR_MODULE_ID index , uint8_t wLat )
{
	DDRSCLCFG1bits.WCASLAT = wLat;
}


//******************************************************************************
/* Function :  DDR_PHY_OdtCSEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_OdtCSEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_OdtCSEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_OdtCSEnable_Default( DDR_MODULE_ID index )
{
	DDRSCLCFG0bits.ODTCSW = 1;
}


//******************************************************************************
/* Function :  DDR_PHY_OdtCSDisable_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_OdtCSDisable 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_OdtCSDisable function.
*/

PLIB_TEMPLATE void DDR_PHY_OdtCSDisable_Default( DDR_MODULE_ID index )
{
	DDRSCLCFG0bits.ODTCSW = 0;
}


//******************************************************************************
/* Function :  DDR_PHY_SCLDelay_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_SCLDelay 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_SCLDelay function.
*/

PLIB_TEMPLATE void DDR_PHY_SCLDelay_Default( DDR_MODULE_ID index , DDR_PHY_SCL_DELAY sclDly )
{
	DDRSCLCFG1bits.DBLREFDLY = sclDly;
}


//******************************************************************************
/* Function :  DDR_PHY_SCLEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_SCLEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_SCLEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_SCLEnable_Default( DDR_MODULE_ID index , uint8_t cs )
{
	/* Chip select 0 enabled by hardware. Other chip selects not available. */
	/* DDRSCLCFG1bits.SCLCSEN = cs;*/
}


//******************************************************************************
/* Function :  DDR_PHY_SCLDDRClkDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_SCLDDRClkDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_SCLDDRClkDelaySet function.
*/

PLIB_TEMPLATE void DDR_PHY_SCLDDRClkDelaySet_Default( DDR_MODULE_ID index , uint8_t ddrDly )
{
	DDRSCLLATbits.DDRCLKDLY = ddrDly;
}


//******************************************************************************
/* Function :  DDR_PHY_SCLCapClkDelaySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_SCLCapClkDelaySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_SCLCapClkDelaySet function.
*/

PLIB_TEMPLATE void DDR_PHY_SCLCapClkDelaySet_Default( DDR_MODULE_ID index , uint8_t capDly )
{
	DDRSCLLATbits.CAPCLKDLY = capDly;
}


//******************************************************************************
/* Function :  DDR_PHY_SCLStart_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_SCLStart 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_SCLStart function.
*/

PLIB_TEMPLATE void DDR_PHY_SCLStart_Default( DDR_MODULE_ID index )
{
	DDRSCLSTARTbits.SCLEN = 1;
	DDRSCLSTARTbits.SCLSTART = 1;
}


//******************************************************************************
/* Function :  DDR_PHY_SCLStatus_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_SCLStatus 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_SCLStatus function.
*/

PLIB_TEMPLATE bool DDR_PHY_SCLStatus_Default( DDR_MODULE_ID index )
{
return ((DDRSCLSTARTbits.SCLLBPASS & DDRSCLSTARTbits.SCLUBPASS) == 0x01) ? true : false;
}


//******************************************************************************
/* Function :  DDR_ExistsPHY_SCLConfig_Default

  Summary:
    Implements Default variant of PLIB_DDR_ExistsPHY_SCLConfig

  Description:
    This template implements the Default variant of the PLIB_DDR_ExistsPHY_SCLConfig function.
*/

#define PLIB_DDR_ExistsPHY_SCLConfig PLIB_DDR_ExistsPHY_SCLConfig
PLIB_TEMPLATE bool DDR_ExistsPHY_SCLConfig_Default( DDR_MODULE_ID index )
{
    return true;
}


#endif /*_DDR_PHY_SCLCONFIG_DEFAULT_H*/

/******************************************************************************
 End of File
*/

