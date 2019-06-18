/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_GlobalColorLUT_Unsupported.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : GlobalColorLUT
    and its Variant : Unsupported
    For following APIs :
        PLIB_GLCD_ExistsGlobalColorLUT
        PLIB_GLCD_GlobalColorLUTSet
        PLIB_GLCD_GlobalColorLUTGet

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

#ifndef _GLCD_GLOBALCOLORLUT_UNSUPPORTED_H
#define _GLCD_GLOBALCOLORLUT_UNSUPPORTED_H

//******************************************************************************
/* Function :  GLCD_ExistsGlobalColorLUT_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_ExistsGlobalColorLUT

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_ExistsGlobalColorLUT function.
*/
PLIB_TEMPLATE bool GLCD_ExistsGlobalColorLUT_Unsupported( GLCD_MODULE_ID index )
{
    return false;
}

//******************************************************************************
/* Function :  GLCD_GlobalColorLUTSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_GlobalColorLUTSet 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_GlobalColorLUTSet function.
*/
PLIB_TEMPLATE void GLCD_GlobalColorLUTSet_Unsupported( GLCD_MODULE_ID   index , uint32_t       * globalLUT )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_GlobalColorLUTSet");
}

//******************************************************************************
/* Function :  GLCD_GlobalColorLUTGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_GlobalColorLUTGet 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_GlobalColorLUTGet function.
*/
PLIB_TEMPLATE uint32_t GLCD_GlobalColorLUTGet_Unsupported( GLCD_MODULE_ID index , uint32_t lutIndex )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_GlobalColorLUTGet");

    return (uint32_t) 0;
}

#endif /*_GLCD_GLOBALCOLORLUT_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

