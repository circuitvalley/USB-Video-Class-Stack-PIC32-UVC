/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_LayerForceWithGlobalAlphaControl_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : LayerForceWithGlobalAlphaControl
    and its Variant : Default
    For following APIs :
        PLIB_GLCD_ExistsLayerForceWithGlobalAlpha
        PLIB_GLCD_LayerForceWithGlobalAlphaEnable
        PLIB_GLCD_LayerForceWithGlobalAlphaDisable
        PLIB_GLCD_LayerForceWithGlobalAlphaIsEnabled

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

#ifndef _GLCD_LAYERFORCEWITHGLOBALALPHACONTROL_DEFAULT_H
#define _GLCD_LAYERFORCEWITHGLOBALALPHACONTROL_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsLayerForceWithGlobalAlpha_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsLayerForceWithGlobalAlpha

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsLayerForceWithGlobalAlpha function.
*/
#define PLIB_GLCD_ExistsLayerForceWithGlobalAlpha PLIB_GLCD_ExistsLayerForceWithGlobalAlpha
PLIB_TEMPLATE bool GLCD_ExistsLayerForceWithGlobalAlpha_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_LayerForceWithGlobalAlphaEnable_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerForceWithGlobalAlphaEnable 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerForceWithGlobalAlphaEnable function.
*/
PLIB_TEMPLATE void GLCD_LayerForceWithGlobalAlphaEnable_Default( GLCD_MODULE_ID index , GLCD_LAYER_ID  layerId )
{
	 *((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) ))) = ( ( *((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) ))) ) & \
	 ~(1<<(_GLCDL0MODE_FORCEALPHA_POSITION)) ) | (0x1&(1))<<(_GLCDL0MODE_FORCEALPHA_POSITION);
}

//******************************************************************************
/* Function :  GLCD_LayerForceWithGlobalAlphaDisable_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerForceWithGlobalAlphaDisable 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerForceWithGlobalAlphaDisable function.
*/
PLIB_TEMPLATE void GLCD_LayerForceWithGlobalAlphaDisable_Default( GLCD_MODULE_ID index , GLCD_LAYER_ID  layerId )
{
	 *((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) ))) = ( ( *((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) ))) ) & \
	 ~(1<<(_GLCDL0MODE_FORCEALPHA_POSITION)) ) | (0x1&(0))<<(_GLCDL0MODE_FORCEALPHA_POSITION);
}

//******************************************************************************
/* Function :  GLCD_LayerForceWithGlobalAlphaIsEnabled_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LayerForceWithGlobalAlphaIsEnabled 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LayerForceWithGlobalAlphaIsEnabled function.
*/
PLIB_TEMPLATE bool GLCD_LayerForceWithGlobalAlphaIsEnabled_Default( GLCD_MODULE_ID index , GLCD_LAYER_ID  layerId )
{						
	return   (  ( ( *((SFR_TYPE *)(( (&GLCDL0MODE) + ( layerId * 8 ) ))) )&(1<<(_GLCDL0MODE_FORCEALPHA_POSITION)) ) ? 1 : 0  );
}

#endif /*_GLCD_LAYERFORCEWITHGLOBALALPHACONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

