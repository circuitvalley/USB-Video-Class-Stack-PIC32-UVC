/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_LayerDestBlendFuncMode_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : LayerDestBlendFuncMode
    and its Variant : Default
    For following APIs :
        PLIB_GLCD_ExistsLayerDestBlendFunc
        PLIB_GLCD_LayerDestBlendFuncSet
        PLIB_GLCD_LayerDestBlendFuncGet

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

#ifndef _GLCD_LAYERDESTBLENDFUNCMODE_DEFAULT_H
#define _GLCD_LAYERDESTBLENDFUNCMODE_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsLayerDestBlendFunc_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsLayerDestBlendFunc

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsLayerDestBlendFunc function.
*/
#define PLIB_GLCD_ExistsLayerDestBlendFunc PLIB_GLCD_ExistsLayerDestBlendFunc
PLIB_TEMPLATE bool GLCD_ExistsLayerDestBlendFunc_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_LayerDestBlendFuncSet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerDestBlendFuncSet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerDestBlendFuncSet function.
*/
PLIB_TEMPLATE void GLCD_LayerDestBlendFuncSet_Default( GLCD_MODULE_ID             index , 
                                                       GLCD_LAYER_ID              layerId , 
                                                       GLCD_LAYER_DEST_BLEND_FUNC blendFunc )
{		  
	*((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) ))) = \
        ( (*((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) )))) & ~(_GLCDL0MODE_DESTBLEND_MASK) ) | \
		( (_GLCDL0MODE_DESTBLEND_MASK)&(blendFunc) );
}

//******************************************************************************
/* Function :  GLCD_LayerDestBlendFuncGet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerDestBlendFuncGet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerDestBlendFuncGet function.
*/
PLIB_TEMPLATE GLCD_LAYER_DEST_BLEND_FUNC GLCD_LayerDestBlendFuncGet_Default( GLCD_MODULE_ID index , 
                                                                             GLCD_LAYER_ID  layerId )
{
	return ( *((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) )))&(_GLCDL0MODE_DESTBLEND_MASK) );
}

#endif /*_GLCD_LAYERDESTBLENDFUNCMODE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

