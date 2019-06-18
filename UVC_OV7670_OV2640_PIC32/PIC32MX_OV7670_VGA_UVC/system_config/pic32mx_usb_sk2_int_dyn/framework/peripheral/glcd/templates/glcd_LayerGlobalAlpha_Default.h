/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_LayerGlobalAlpha_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : LayerGlobalAlpha
    and its Variant : Default
    For following APIs :
        PLIB_GLCD_ExistsLayerGlobalAlpha
        PLIB_GLCD_LayerGlobalAlphaSet
        PLIB_GLCD_LayerGlobalAlphaGet

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

#ifndef _GLCD_LAYERGLOBALALPHA_DEFAULT_H
#define _GLCD_LAYERGLOBALALPHA_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsLayerGlobalAlpha_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsLayerGlobalAlpha

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsLayerGlobalAlpha function.
*/
#define PLIB_GLCD_ExistsLayerGlobalAlpha PLIB_GLCD_ExistsLayerGlobalAlpha
PLIB_TEMPLATE bool GLCD_ExistsLayerGlobalAlpha_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_LayerGlobalAlphaSet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerGlobalAlphaSet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerGlobalAlphaSet function.
*/
PLIB_TEMPLATE void GLCD_LayerGlobalAlphaSet_Default( GLCD_MODULE_ID index , 
                                                     GLCD_LAYER_ID  layerId , 
                                                     uint8_t        value )
{
	*((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) ))) = \
            ( (*((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) )))) & ~(_GLCDL0MODE_ALPHA_MASK) ) \
            | ( (_GLCDL0MODE_ALPHA_MASK)&((value)<<(_GLCDL0MODE_ALPHA_POSITION)) );
}

//******************************************************************************
/* Function :  GLCD_LayerGlobalAlphaGet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerGlobalAlphaGet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerGlobalAlphaGet function.
*/
PLIB_TEMPLATE uint8_t GLCD_LayerGlobalAlphaGet_Default( GLCD_MODULE_ID index , 
                                                        GLCD_LAYER_ID  layerId )
{
	return (  ( *((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) )))&(_GLCDL0MODE_ALPHA_MASK) ) \
            >> (_GLCDL0MODE_ALPHA_POSITION)  );
}

#endif /*_GLCD_LAYERGLOBALALPHA_DEFAULT_H*/

/******************************************************************************
 End of File
*/

