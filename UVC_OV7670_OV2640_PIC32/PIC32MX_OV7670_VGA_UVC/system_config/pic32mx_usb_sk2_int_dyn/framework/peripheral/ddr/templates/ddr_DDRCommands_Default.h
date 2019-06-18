/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_DDRCommands_Default.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DDRCommands
    and its Variant : Default
    For following APIs :
        PLIB_DDR_MaxCmdBrstCntSet
        PLIB_DDR_NumHostCmdsSet
        PLIB_DDR_CmdDataWrite
        PLIB_DDR_CmdDataValid
        PLIB_DDR_CmdDataSend
        PLIB_DDR_CmdDataIsComplete
        PLIB_DDR_ControllerEnable
        PLIB_DDR_ExistsDDRCommands

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

#ifndef _DDR_DDRCOMMANDS_DEFAULT_H
#define _DDR_DDRCOMMANDS_DEFAULT_H

//******************************************************************************
/* Function :  DDR_MaxCmdBrstCntSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_MaxCmdBrstCntSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_MaxCmdBrstCntSet function.
*/

PLIB_TEMPLATE void DDR_MaxCmdBrstCntSet_Default( DDR_MODULE_ID index , int8_t maxCmds )
{
	DDRXFERCFGbits.MAXBURST = maxCmds;
}


//******************************************************************************
/* Function :  DDR_NumHostCmdsSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_NumHostCmdsSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_NumHostCmdsSet function.
*/

PLIB_TEMPLATE void DDR_NumHostCmdsSet_Default( DDR_MODULE_ID index , int8_t numCmds )
{
	DDRCMDISSUEbits.NUMHOSTCMDS = numCmds;
}


//******************************************************************************
/* Function :  DDR_CmdDataWrite_Default

  Summary:
    Implements Default variant of PLIB_DDR_CmdDataWrite 

  Description:
    This template implements the Default variant of the PLIB_DDR_CmdDataWrite function.
*/

PLIB_TEMPLATE void DDR_CmdDataWrite_Default( DDR_MODULE_ID index , DDR_HOST_CMD_REG cmdReg , uint32_t cmdData )
{
	*(&DDRCMD10 + cmdReg) = cmdData;
}


//******************************************************************************
/* Function :  DDR_CmdDataValid_Default

  Summary:
    Implements Default variant of PLIB_DDR_CmdDataValid 

  Description:
    This template implements the Default variant of the PLIB_DDR_CmdDataValid function.
*/

PLIB_TEMPLATE void DDR_CmdDataValid_Default( DDR_MODULE_ID index )
{
	DDRCMDISSUEbits.VALID = 1;
}


//******************************************************************************
/* Function :  DDR_CmdDataSend_Default

  Summary:
    Implements Default variant of PLIB_DDR_CmdDataSend 

  Description:
    This template implements the Default variant of the PLIB_DDR_CmdDataSend function.
*/

PLIB_TEMPLATE void DDR_CmdDataSend_Default( DDR_MODULE_ID index )
{
	DDRMEMCONbits.STINIT = 1;
}


//******************************************************************************
/* Function :  DDR_CmdDataIsComplete_Default

  Summary:
    Implements Default variant of PLIB_DDR_CmdDataIsComplete 

  Description:
    This template implements the Default variant of the PLIB_DDR_CmdDataIsComplete function.
*/

PLIB_TEMPLATE bool DDR_CmdDataIsComplete_Default( DDR_MODULE_ID index )
{
	return DDRCMDISSUEbits.VALID;
}


//******************************************************************************
/* Function :  DDR_ControllerEnable_Default

  Summary:
    Implements Default variant of PLIB_DDR_ControllerEnable 

  Description:
    This template implements the Default variant of the PLIB_DDR_ControllerEnable function.
*/

PLIB_TEMPLATE void DDR_ControllerEnable_Default( DDR_MODULE_ID index )
{
	DDRMEMCONbits.INITDN = 1;
}


//******************************************************************************
/* Function :  DDR_ExistsDDRCommands_Default

  Summary:
    Implements Default variant of PLIB_DDR_ExistsDDRCommands

  Description:
    This template implements the Default variant of the PLIB_DDR_ExistsDDRCommands function.
*/

#define PLIB_DDR_ExistsDDRCommands PLIB_DDR_ExistsDDRCommands
PLIB_TEMPLATE bool DDR_ExistsDDRCommands_Default( DDR_MODULE_ID index )
{
    return true;
}


#endif /*_DDR_DDRCOMMANDS_DEFAULT_H*/

/******************************************************************************
 End of File
*/

