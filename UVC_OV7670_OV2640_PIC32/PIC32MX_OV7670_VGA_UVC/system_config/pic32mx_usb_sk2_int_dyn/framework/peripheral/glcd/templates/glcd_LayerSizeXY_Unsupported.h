/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_LayerSizeXY_Unsupported.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : LayerSizeXY
    and its Variant : Unsupported
    For following APIs :
        PLIB_GLCD_ExistsLayerSizeXY
        PLIB_GLCD_LayerSizeXYSet
        PLIB_GLCD_LayerSizeXGet
        PLIB_GLCD_LayerSizeYGet

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

#ifndef _GLCD_LAYERSIZEXY_UNSUPPORTED_H
#define _GLCD_LAYERSIZEXY_UNSUPPORTED_H

//******************************************************************************
/* Function :  GLCD_ExistsLayerSizeXY_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_ExistsLayerSizeXY

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_ExistsLayerSizeXY function.
*/
PLIB_TEMPLATE bool GLCD_ExistsLayerSizeXY_Unsupported( GLCD_MODULE_ID index )
{
    return false;
}

//******************************************************************************
/* Function :  GLCD_LayerSizeXYSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_LayerSizeXYSet 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_LayerSizeXYSet function.
*/
PLIB_TEMPLATE void GLCD_LayerSizeXYSet_Unsupported( GLCD_MODULE_ID index , GLCD_LAYER_ID  layerId , uint32_t      sizeX , uint32_t      sizeY )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_LayerSizeXYSet");
}

//******************************************************************************
/* Function :  GLCD_LayerSizeXGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_LayerSizeXGet 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_LayerSizeXGet function.
*/
PLIB_TEMPLATE uint32_t GLCD_LayerSizeXGet_Unsupported( GLCD_MODULE_ID index , GLCD_LAYER_ID  layerId )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_LayerSizeXGet");

    return (uint32_t) 0;
}

//******************************************************************************
/* Function :  GLCD_LayerSizeYGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_LayerSizeYGet 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_LayerSizeYGet function.
*/
PLIB_TEMPLATE uint32_t GLCD_LayerSizeYGet_Unsupported( GLCD_MODULE_ID index , GLCD_LAYER_ID  layerId )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_LayerSizeYGet");

    return (uint32_t) 0;
}

#endif /*_GLCD_LAYERSIZEXY_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

