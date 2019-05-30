/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_LayerStartXY_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : LayerStartXY
    and its Variant : Default
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

#ifndef _GLCD_LAYERSTARTXY_DEFAULT_H
#define _GLCD_LAYERSTARTXY_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsLayerStartXY_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsLayerStartXY

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsLayerStartXY function.
*/
#define PLIB_GLCD_ExistsLayerStartXY PLIB_GLCD_ExistsLayerStartXY
PLIB_TEMPLATE bool GLCD_ExistsLayerStartXY_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_LayerStartXYSet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerStartXYSet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerStartXYSet function.
*/
PLIB_TEMPLATE void GLCD_LayerStartXYSet_Default( GLCD_MODULE_ID index , 
                                                 GLCD_LAYER_ID  layerId , 
                                                 uint32_t       startX , 
                                                 uint32_t       startY )
{
	*((SFR_TYPE *)(( (&GLCDL0START) + ( layerId * 8 ) ))) = \
        ( (*((SFR_TYPE *)(( (&GLCDL0START) + ( layerId * 8 ) )))) & ~(_GLCDL0START_STARTX_MASK) ) | \
		( (_GLCDL0START_STARTX_MASK)&((startX)<<(_GLCDL0START_STARTX_POSITION)) );  
    
	*((SFR_TYPE *)(( (&GLCDL0START) + ( layerId * 8 ) ))) = \
        ( (*((SFR_TYPE *)(( (&GLCDL0START) + ( layerId * 8 ) )))) & ~(_GLCDL0START_STARTY_MASK) ) | \
		( (_GLCDL0START_STARTY_MASK)&((startY)<<(_GLCDL0START_STARTY_POSITION)) );  
}

//******************************************************************************
/* Function :  GLCD_LayerStartXGet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerStartXGet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerStartXGet function.
*/
PLIB_TEMPLATE uint32_t GLCD_LayerStartXGet_Default( GLCD_MODULE_ID index , 
                                                    GLCD_LAYER_ID  layerId )
{
	return  (  ( *((SFR_TYPE *)(( (&GLCDL0START) + ( layerId * 8 ) )))& \
	           (_GLCDL0START_STARTX_MASK) ) >> (_GLCDL0START_STARTX_POSITION)  );
}

//******************************************************************************
/* Function :  GLCD_LayerStartYGet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerStartYGet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerStartYGet function.
*/
PLIB_TEMPLATE uint32_t GLCD_LayerStartYGet_Default( GLCD_MODULE_ID index , GLCD_LAYER_ID  layerId )
{
	return  (  ( *((SFR_TYPE *)(( (&GLCDL0START) + ( layerId * 8 ) )))& \
	           (_GLCDL0START_STARTY_MASK) ) >> (_GLCDL0START_STARTY_POSITION)  );
}

#endif /*_GLCD_LAYERSTARTXY_DEFAULT_H*/

/******************************************************************************
 End of File
*/

