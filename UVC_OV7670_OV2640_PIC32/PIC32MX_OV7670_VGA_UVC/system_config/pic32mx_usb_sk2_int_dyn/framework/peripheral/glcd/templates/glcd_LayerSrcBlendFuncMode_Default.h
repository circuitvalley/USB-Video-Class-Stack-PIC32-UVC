/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_LayerSrcBlendFuncMode_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : LayerSrcBlendFuncMode
    and its Variant : Default
    For following APIs :
        PLIB_GLCD_ExistsLayerSrcBlendFunc
        PLIB_GLCD_LayerSrcBlendFuncSet
        PLIB_GLCD_LayerSrcBlendFuncGet

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

#ifndef _GLCD_LAYERSRCBLENDFUNCMODE_DEFAULT_H
#define _GLCD_LAYERSRCBLENDFUNCMODE_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsLayerSrcBlendFunc_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsLayerSrcBlendFunc

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsLayerSrcBlendFunc function.
*/
#define PLIB_GLCD_ExistsLayerSrcBlendFunc PLIB_GLCD_ExistsLayerSrcBlendFunc
PLIB_TEMPLATE bool GLCD_ExistsLayerSrcBlendFunc_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_LayerSrcBlendFuncSet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerSrcBlendFuncSet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerSrcBlendFuncSet function.
*/
PLIB_TEMPLATE void GLCD_LayerSrcBlendFuncSet_Default( GLCD_MODULE_ID            index , 
                                                      GLCD_LAYER_ID             layerId , 
                                                      GLCD_LAYER_SRC_BLEND_FUNC blendFunc )
{
	*((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) ))) = \
        ( (*((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) )))) & ~(_GLCDL0MODE_SRCBLEND_MASK) ) | \
		( _GLCDL0MODE_SRCBLEND_MASK & blendFunc );  
}

//******************************************************************************
/* Function :  GLCD_LayerSrcBlendFuncGet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerSrcBlendFuncGet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerSrcBlendFuncGet function.
*/
PLIB_TEMPLATE GLCD_LAYER_SRC_BLEND_FUNC GLCD_LayerSrcBlendFuncGet_Default( GLCD_MODULE_ID index , 
                                                                           GLCD_LAYER_ID  layerId )
{
	return  ( *((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) ))) & _GLCDL0MODE_SRCBLEND_MASK );
}

#endif /*_GLCD_LAYERSRCBLENDFUNCMODE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

