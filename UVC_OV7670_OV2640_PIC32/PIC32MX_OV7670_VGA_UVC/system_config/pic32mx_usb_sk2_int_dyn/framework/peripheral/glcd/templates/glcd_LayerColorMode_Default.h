/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_LayerColorMode_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : LayerColorMode
    and its Variant : Default
    For following APIs :
        PLIB_GLCD_ExistsLayerColorMode
        PLIB_GLCD_LayerColorModeSet
        PLIB_GLCD_LayerColorModeGet

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

#ifndef _GLCD_LAYERCOLORMODE_DEFAULT_H
#define _GLCD_LAYERCOLORMODE_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsLayerColorMode_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsLayerColorMode

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsLayerColorMode function.
*/
#define PLIB_GLCD_ExistsLayerColorMode PLIB_GLCD_ExistsLayerColorMode
PLIB_TEMPLATE bool GLCD_ExistsLayerColorMode_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_LayerColorModeSet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerColorModeSet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerColorModeSet function.
*/
PLIB_TEMPLATE void GLCD_LayerColorModeSet_Default( GLCD_MODULE_ID         index , 
                                                   GLCD_LAYER_ID          layerId , 
                                                   GLCD_LAYER_COLOR_MODE  colorMode )
{
	*((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) ))) = \
        ( (*((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) )))) & ~(_GLCDL0MODE_COLORMODE_MASK) ) | ( (_GLCDL0MODE_COLORMODE_MASK)&(colorMode) );
}

//******************************************************************************
/* Function :  GLCD_LayerColorModeGet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerColorModeGet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerColorModeGet function.
*/
PLIB_TEMPLATE GLCD_LAYER_COLOR_MODE GLCD_LayerColorModeGet_Default( GLCD_MODULE_ID index , 
                                                                    GLCD_LAYER_ID  layerId )
{						   
	return   (  *((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) )))&(_GLCDL0MODE_COLORMODE_MASK)  );
}

#endif /*_GLCD_LAYERCOLORMODE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

