/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_LayerSizeXY_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : LayerSizeXY
    and its Variant : Default
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

#ifndef _GLCD_LAYERSIZEXY_DEFAULT_H
#define _GLCD_LAYERSIZEXY_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsLayerSizeXY_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsLayerSizeXY

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsLayerSizeXY function.
*/
#define PLIB_GLCD_ExistsLayerSizeXY PLIB_GLCD_ExistsLayerSizeXY
PLIB_TEMPLATE bool GLCD_ExistsLayerSizeXY_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_LayerSizeXYSet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerSizeXYSet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerSizeXYSet function.
*/
PLIB_TEMPLATE void GLCD_LayerSizeXYSet_Default( GLCD_MODULE_ID index , 
                                                GLCD_LAYER_ID  layerId , 
                                                uint32_t       sizeX , 
                                                uint32_t       sizeY )
{
	*((SFR_TYPE *)(( (&GLCDL0SIZE) + ( layerId * 8 ) ))) = \
        ( (*((SFR_TYPE *)(( (&GLCDL0SIZE) + ( layerId * 8 ) )))) & ~(_GLCDL0SIZE_SIZEX_MASK) ) | \
		( (_GLCDL0SIZE_SIZEX_MASK)&((sizeX)<<(_GLCDL0SIZE_SIZEX_POSITION)) );  
    
	*((SFR_TYPE *)(( (&GLCDL0SIZE) + ( layerId * 8 ) ))) = \
        ( (*((SFR_TYPE *)(( (&GLCDL0SIZE) + ( layerId * 8 ) )))) & ~(_GLCDL0SIZE_SIZEY_MASK) ) | \
		( (_GLCDL0SIZE_SIZEY_MASK)&((sizeY)<<(_GLCDL0SIZE_SIZEY_POSITION)) );  
}

//******************************************************************************
/* Function :  GLCD_LayerSizeXGet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerSizeXGet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerSizeXGet function.
*/
PLIB_TEMPLATE uint32_t GLCD_LayerSizeXGet_Default( GLCD_MODULE_ID index , 
                                                   GLCD_LAYER_ID  layerId )
{
	return  (  ( *((SFR_TYPE *)(( (&GLCDL0SIZE) + ( layerId * 8 ) )))& \
	           (_GLCDL0SIZE_SIZEX_MASK) ) >> (_GLCDL0SIZE_SIZEX_POSITION)  );
}

//******************************************************************************
/* Function :  GLCD_LayerSizeYGet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerSizeYGet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerSizeYGet function.
*/
PLIB_TEMPLATE uint32_t GLCD_LayerSizeYGet_Default( GLCD_MODULE_ID index , 
                                                   GLCD_LAYER_ID  layerId )
{
	return  (  ( *((SFR_TYPE *)(( (&GLCDL0SIZE) + ( layerId * 8 ) )))& \
	           (_GLCDL0SIZE_SIZEY_MASK) ) >> (_GLCDL0SIZE_SIZEY_POSITION)  );
}

#endif /*_GLCD_LAYERSIZEXY_DEFAULT_H*/

/******************************************************************************
 End of File
*/

