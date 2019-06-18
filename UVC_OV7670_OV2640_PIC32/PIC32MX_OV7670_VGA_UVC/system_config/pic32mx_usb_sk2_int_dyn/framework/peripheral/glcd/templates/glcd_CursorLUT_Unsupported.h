/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_CursorLUT_Unsupported.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : CursorLUT
    and its Variant : Unsupported
    For following APIs :
        PLIB_GLCD_ExistsCursorLUT
        PLIB_GLCD_CursorLUTSet
        PLIB_GLCD_CursorLUTGet

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

#ifndef _GLCD_CURSORLUT_UNSUPPORTED_H
#define _GLCD_CURSORLUT_UNSUPPORTED_H

//******************************************************************************
/* Function :  GLCD_ExistsCursorLUT_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_ExistsCursorLUT

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_ExistsCursorLUT function.
*/
PLIB_TEMPLATE bool GLCD_ExistsCursorLUT_Unsupported( GLCD_MODULE_ID index )
{
    return false;
}

//******************************************************************************
/* Function :  GLCD_CursorLUTSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_CursorLUTSet 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_CursorLUTSet function.
*/
PLIB_TEMPLATE void GLCD_CursorLUTSet_Unsupported( GLCD_MODULE_ID index , uint32_t       * cursorLUT )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_CursorLUTSet");
}

//******************************************************************************
/* Function :  GLCD_CursorLUTGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_CursorLUTGet 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_CursorLUTGet function.
*/
PLIB_TEMPLATE uint32_t GLCD_CursorLUTGet_Unsupported( GLCD_MODULE_ID index , uint32_t lutIndex )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_CursorLUTGet");

    return (uint32_t) 0;
}

#endif /*_GLCD_CURSORLUT_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

