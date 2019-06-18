/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_PHY_DLLCalibration_Default.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : PHY_DLLCalibration
    and its Variant : Default
    For following APIs :
        PLIB_DDR_PHY_DllRecalibEnable
        PLIB_DDR_PHY_DllRecalibDisable
        PLIB_DDR_PHY_DllMasterDelayStartSet
        PLIB_DDR_ExistsPHY_DLLCalibration

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

#ifndef _DDR_PHY_DLLCALIBRATION_DEFAULT_H
#define _DDR_PHY_DLLCALIBRATION_DEFAULT_H

//******************************************************************************
/* Function :  DDR_PHY_DllRecalibEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_DllRecalibEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_DllRecalibEnable function.
*/

PLIB_TEMPLATE void DDR_PHY_DllRecalibEnable_Default( DDR_MODULE_ID index , uint32_t recalibCnt )
{
	DDRPHYDLLRbits.RECALIBCNT = recalibCnt;
	DDRPHYDLLRbits.DISRECALIB = 0;
}


//******************************************************************************
/* Function :  DDR_PHY_DllRecalibDisable_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_DllRecalibDisable 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_DllRecalibDisable function.
*/

PLIB_TEMPLATE void DDR_PHY_DllRecalibDisable_Default( DDR_MODULE_ID index )
{
	DDRPHYDLLRbits.DISRECALIB = 1;
}


//******************************************************************************
/* Function :  DDR_PHY_DllMasterDelayStartSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_PHY_DllMasterDelayStartSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_PHY_DllMasterDelayStartSet function.
*/

PLIB_TEMPLATE void DDR_PHY_DllMasterDelayStartSet_Default( DDR_MODULE_ID index , uint8_t dlyStart )
{
	DDRPHYDLLRbits.DLYSTVAL = dlyStart;
}


//******************************************************************************
/* Function :  DDR_ExistsPHY_DLLCalibration_Default

  Summary:
    Implements Default variant of PLIB_DDR_ExistsPHY_DLLCalibration

  Description:
    This template implements the Default variant of the PLIB_DDR_ExistsPHY_DLLCalibration function.
*/

#define PLIB_DDR_ExistsPHY_DLLCalibration PLIB_DDR_ExistsPHY_DLLCalibration
PLIB_TEMPLATE bool DDR_ExistsPHY_DLLCalibration_Default( DDR_MODULE_ID index )
{
    return true;
}


#endif /*_DDR_PHY_DLLCALIBRATION_DEFAULT_H*/

/******************************************************************************
 End of File
*/

