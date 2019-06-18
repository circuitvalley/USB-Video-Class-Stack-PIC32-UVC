/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_LayerStartXY_Unsupported.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : LayerStartXY
    and its Variant : Unsupported
    For following APIs :
        PLIB_GLCD_ExistsLayerStartXY
        PLIB_GLCD_LayerStartXYSet
        PLIB_GLCD_LayerStartXGet
        PLIB_GLCD_LayerStartYGet

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

#ifndef _GLCD_LAYERSTARTXY_UNSUPPORTED_H
#define _GLCD_LAYERSTARTXY_UNSUPPORTED_H

//******************************************************************************
/* Function :  GLCD_ExistsLayerStartXY_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_ExistsLayerStartXY

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_ExistsLayerStartXY function.
*/
PLIB_TEMPLATE bool GLCD_ExistsLayerStartXY_Unsupported( GLCD_MODULE_ID index )
{
    return false;
}

//******************************************************************************
/* Function :  GLCD_LayerStartXYSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_LayerStartXYSet 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_LayerStartXYSet function.
*/
PLIB_TEMPLATE void GLCD_LayerStartXYSet_Unsupported( GLCD_MODULE_ID index , GLCD_LAYER_ID  layerId , uint32_t      startX , uint32_t      startY )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_LayerStartXYSet");
}

//******************************************************************************
/* Function :  GLCD_LayerStartXGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_LayerStartXGet 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_LayerStartXGet function.
*/
PLIB_TEMPLATE uint32_t GLCD_LayerStartXGet_Unsupported( GLCD_MODULE_ID index , GLCD_LAYER_ID  layerId )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_LayerStartXGet");

    return (uint32_t) 0;
}

//******************************************************************************
/* Function :  GLCD_LayerStartYGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_LayerStartYGet 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_LayerStartYGet function.
*/
PLIB_TEMPLATE uint32_t GLCD_LayerStartYGet_Unsupported( GLCD_MODULE_ID index , GLCD_LAYER_ID  layerId )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_LayerStartYGet");

    return (uint32_t) 0;
}

#endif /*_GLCD_LAYERSTARTXY_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

