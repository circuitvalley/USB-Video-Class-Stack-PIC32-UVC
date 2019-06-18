/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_BlankingXY_Unsupported.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : BlankingXY
    and its Variant : Unsupported
    For following APIs :
        PLIB_GLCD_ExistsBlankingXY
        PLIB_GLCD_BlankingXYSet
        PLIB_GLCD_BlankingXGet
        PLIB_GLCD_BlankingYGet

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

#ifndef _GLCD_BLANKINGXY_UNSUPPORTED_H
#define _GLCD_BLANKINGXY_UNSUPPORTED_H

//******************************************************************************
/* Function :  GLCD_ExistsBlankingXY_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_ExistsBlankingXY

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_ExistsBlankingXY function.
*/
PLIB_TEMPLATE bool GLCD_ExistsBlankingXY_Unsupported( GLCD_MODULE_ID index )
{
    return false;
}

//******************************************************************************
/* Function :  GLCD_BlankingXYSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_BlankingXYSet 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_BlankingXYSet function.
*/
PLIB_TEMPLATE void GLCD_BlankingXYSet_Unsupported( GLCD_MODULE_ID index , uint32_t      blankingX                             uint32_t      blankingY )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_BlankingXYSet");
}

//******************************************************************************
/* Function :  GLCD_BlankingXGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_BlankingXGet 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_BlankingXGet function.
*/
PLIB_TEMPLATE uint32_t GLCD_BlankingXGet_Unsupported( GLCD_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_BlankingXGet");

    return (uint32_t) 0;
}

//******************************************************************************
/* Function :  GLCD_BlankingYGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_BlankingYGet 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_BlankingYGet function.
*/
PLIB_TEMPLATE uint32_t GLCD_BlankingYGet_Unsupported( GLCD_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_BlankingYGet");

    return (uint32_t) 0;
}

#endif /*_GLCD_BLANKINGXY_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

