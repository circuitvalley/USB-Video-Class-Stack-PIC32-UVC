/*******************************************************************************
  PTG Peripheral Library Template Implementation

  File Name:
    ptg_SingleStepControl_Unsupported.h

  Summary:
    PTG PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : SingleStepControl
    and its Variant : Unsupported
    For following APIs :
        PLIB_PTG_SingleStepEnable
        PLIB_PTG_SingleStepDisable
        PLIB_PTG_ExistsSingleStepControl

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

#ifndef _PTG_SINGLESTEPCONTROL_UNSUPPORTED_H
#define _PTG_SINGLESTEPCONTROL_UNSUPPORTED_H

//******************************************************************************
/* Function :  PTG_SingleStepEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_PTG_SingleStepEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_PTG_SingleStepEnable function.
*/

PLIB_TEMPLATE void PTG_SingleStepEnable_Unsupported( PTG_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_PTG_SingleStepEnable");
}


//******************************************************************************
/* Function :  PTG_SingleStepDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_PTG_SingleStepDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_PTG_SingleStepDisable function.
*/

PLIB_TEMPLATE void PTG_SingleStepDisable_Unsupported( PTG_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_PTG_SingleStepDisable");
}


//******************************************************************************
/* Function :  PTG_ExistsSingleStepControl_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_PTG_ExistsSingleStepControl

  Description:
    This template implements the Unsupported variant of the PLIB_PTG_ExistsSingleStepControl function.
*/

PLIB_TEMPLATE bool PTG_ExistsSingleStepControl_Unsupported( PTG_MODULE_ID index )
{
    return false;
}


#endif /*_PTG_SINGLESTEPCONTROL_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

