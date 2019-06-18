/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_PHY_PadConfig_Default.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : PHY_PadConfig
    and its Variant : Default
    For following APIs :
        PLIB_DDR_PHY_OdtEnable
        PLIB_DDR_PHY_OdtDisable
        PLIB_DDR_PHY_DataDriveStrengthSet
        PLIB_DDR_PHY_AddCtlDriveStrengthSet
        PLIB_DDR_PHY_OdtCal
        PLIB_DDR_PHY_DrvStrgthCal
        PLIB_DDR_PHY_ExtraClockEnable
        PLIB_DDR_PHY_ExtraClockDisable
        PLIB_DDR_PHY_InternalDllEnable
        PLIB_DDR_PHY_ExternalDllEnable
        PLIB_DDR_PHY_PadReceiveEnable
        PLIB_DDR_PHY_PadReceiveDisable
        PLIB_DDR_PHY_PreambleDlySet
        PLIB_DDR_PHY_HalfRateSet
        PLIB_DDR_PHY_WriteCmdDelayEnable
        PLIB_DDR_PHY_WriteCmdDelayDisable
        PLIB_DDR_ExistsPHY_PadConfig

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

#ifndef _DDR_PHY_PADCONFIG_DEFAULT_H
#define _DDR_PHY_PADCONFIG_DEFAULT_H

//******************************************************************************
/* Function :  DDR_PHY_OdtEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_OdtEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_OdtEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_OdtEnable_Default( DDR_MODULE_ID index , DDR_PHY_ODT odtVal )
{
	DDRPHYPADCONbits.ODTSEL = odtVal;
	DDRPHYPADCONbits.ODTEN = 1;
}


//******************************************************************************
/* Function :  DDR_PHY_OdtDisable_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_OdtDisable 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_OdtDisable function.
*/

PLIB_TEMPLATE void DDR_PHY_OdtDisable_Default( DDR_MODULE_ID index )
{
	DDRPHYPADCONbits.ODTEN = 0;
}


//******************************************************************************
/* Function :  DDR_PHY_DataDriveStrengthSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_DataDriveStrengthSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_DataDriveStrengthSet function.
*/

PLIB_TEMPLATE void DDR_PHY_DataDriveStrengthSet_Default( DDR_MODULE_ID index , DDR_PHY_DRIVE_STRENGTH drvStr )
{
	DDRPHYPADCONbits.DATDRVSEL = drvStr;
}


//******************************************************************************
/* Function :  DDR_PHY_AddCtlDriveStrengthSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_AddCtlDriveStrengthSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_AddCtlDriveStrengthSet function.
*/

PLIB_TEMPLATE void DDR_PHY_AddCtlDriveStrengthSet_Default( DDR_MODULE_ID index , DDR_PHY_DRIVE_STRENGTH drvStr )
{
	DDRPHYPADCONbits.ADDCDRVSEL = drvStr;
}


//******************************************************************************
/* Function :  DDR_PHY_OdtCal_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_OdtCal 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_OdtCal function.
*/

PLIB_TEMPLATE void DDR_PHY_OdtCal_Default( DDR_MODULE_ID index , uint8_t puCal , uint8_t pdCal )
{
	DDRPHYPADCONbits.ODTPUCAL = puCal;
	DDRPHYPADCONbits.ODTPDCAL = pdCal;
}


//******************************************************************************
/* Function :  DDR_PHY_DrvStrgthCal_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_DrvStrgthCal 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_DrvStrgthCal function.
*/

PLIB_TEMPLATE void DDR_PHY_DrvStrgthCal_Default( DDR_MODULE_ID index , uint8_t nFet , uint8_t pFet )
{
	DDRPHYPADCONbits.DRVSTRNFET = nFet;
	DDRPHYPADCONbits.DRVSTRPFET = pFet;
}


//******************************************************************************
/* Function :  DDR_PHY_ExtraClockEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_ExtraClockEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_ExtraClockEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_ExtraClockEnable_Default( DDR_MODULE_ID index )
{
	DDRPHYPADCONbits.EOENCLKCYC = 1; 
}


//******************************************************************************
/* Function :  DDR_PHY_ExtraClockDisable_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_ExtraClockDisable 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_ExtraClockDisable function.
*/

PLIB_TEMPLATE void DDR_PHY_ExtraClockDisable_Default( DDR_MODULE_ID index )
{
	DDRPHYPADCONbits.EOENCLKCYC = 0;
}


//******************************************************************************
/* Function :  DDR_PHY_InternalDllEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_InternalDllEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_InternalDllEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_InternalDllEnable_Default( DDR_MODULE_ID index )
{
	DDRPHYPADCONbits.NOEXTDLL = 1;
}


//******************************************************************************
/* Function :  DDR_PHY_ExternalDllEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_ExternalDllEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_ExternalDllEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_ExternalDllEnable_Default( DDR_MODULE_ID index )
{
	DDRPHYPADCONbits.NOEXTDLL = 0;
}


//******************************************************************************
/* Function :  DDR_PHY_PadReceiveEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_PadReceiveEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_PadReceiveEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_PadReceiveEnable_Default( DDR_MODULE_ID index )
{
	DDRPHYPADCONbits.RCVREN = 1;
}

//******************************************************************************
/* Function :  DDR_PHY_PadReceiveDisable_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_PadReceiveDisable 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_PadReceiveDisable function.
*/

PLIB_TEMPLATE void DDR_PHY_PadReceiveDisable_Default( DDR_MODULE_ID index )
{
	DDRPHYPADCONbits.RCVREN = 0;
}


//******************************************************************************
/* Function :  DDR_PHY_PreambleDlySet_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_PreambleDlySet 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_PreambleDlySet function.
*/

PLIB_TEMPLATE void DDR_PHY_PreambleDlySet_Default( DDR_MODULE_ID index , DDR_PHY_PREAMBLE_DLY preDly )
{
	DDRPHYPADCONbits.PREAMBDLY = preDly;
}


//******************************************************************************
/* Function :  DDR_PHY_HalfRateSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_HalfRateSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_HalfRateSet function.
*/

PLIB_TEMPLATE void DDR_PHY_HalfRateSet_Default( DDR_MODULE_ID index )
{
	DDRPHYPADCONbits.HALFRATE = 1;
}


//******************************************************************************
/* Function :  DDR_PHY_WriteCmdDelayEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_WriteCmdDelayEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_WriteCmdDelayEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_WriteCmdDelayEnable_Default( DDR_MODULE_ID index )
{
	DDRPHYPADCONbits.WRCMDDLY = 1;
}


//******************************************************************************
/* Function :  DDR_PHY_WriteCmdDelayDisable_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_WriteCmdDelayDisable 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_WriteCmdDelayDisable function.
*/

PLIB_TEMPLATE void DDR_PHY_WriteCmdDelayDisable_Default( DDR_MODULE_ID index )
{
	DDRPHYPADCONbits.WRCMDDLY = 0;
}


//******************************************************************************
/* Function :  DDR_ExistsPHY_PadConfig_Default

  Summary:
    Implements Default variant of PLIB_DDR_ExistsPHY_PadConfig

  Description:
    This template implements the Default variant of the PLIB_DDR_ExistsPHY_PadConfig function.
*/

#define PLIB_DDR_ExistsPHY_PadConfig PLIB_DDR_ExistsPHY_PadConfig
PLIB_TEMPLATE bool DDR_ExistsPHY_PadConfig_Default( DDR_MODULE_ID index )
{
    return true;
}


#endif /*_DDR_PHY_PADCONFIG_DEFAULT_H*/

/******************************************************************************
 End of File
*/

