/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_RGBSequentialMode_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : RGBSequentialMode
    and its Variant : Default
    For following APIs :
        PLIB_GLCD_ExistsRGBSequentialMode
        PLIB_GLCD_RGBSequentialModeSet
        PLIB_GLCD_RGBSequentialModeGet

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

#ifndef _GLCD_RGBSEQUENTIALMODE_DEFAULT_H
#define _GLCD_RGBSEQUENTIALMODE_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsRGBSequentialMode_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsRGBSequentialMode

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsRGBSequentialMode function.
*/
#define PLIB_GLCD_ExistsRGBSequentialMode PLIB_GLCD_ExistsRGBSequentialMode
PLIB_TEMPLATE bool GLCD_ExistsRGBSequentialMode_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_RGBSequentialModeSet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_RGBSequentialModeSet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_RGBSequentialModeSet function.
*/
PLIB_TEMPLATE void GLCD_RGBSequentialModeSet_Default( GLCD_MODULE_ID index , GLCD_RGB_MODE  mode )
{
    switch( mode )
    {
        case GLCD_RGB_MODE_PARALLEL_RGB565:
        {
			CFGCON2bits.GLCDMODE = 1;
            GLCDMODEbits.RGBSEQ = 0;
            break;
        }
        
        case GLCD_RGB_MODE_PARALLEL_RGB888:
        {
            CFGCON2bits.GLCDMODE = 0;
            GLCDMODEbits.RGBSEQ = 0;
            break;
        }
        
        case GLCD_RGB_MODE_SERIAL_RGB_3:
        {
            GLCDMODEbits.RGBSEQ = 1;
            break;
        }
        
        case GLCD_RGB_MODE_SERIAL_RGBA_4:
        {
            GLCDMODEbits.RGBSEQ = 2;
            break;
        }
        
        case GLCD_RGB_MODE_SERIAL_12BIT:
        {
            GLCDMODEbits.RGBSEQ = 3;
            break;
        }
        
        case GLCD_RGB_MODE_YUYV_16BIT:
        {
            GLCDMODEbits.RGBSEQ = 6;
            break;
        }
        
        case GLCD_RGB_MODE_BT_656:
        {
            GLCDMODEbits.RGBSEQ = 7;
            break;
        }
    }
}

//******************************************************************************
/* Function :  GLCD_RGBSequentialModeGet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_RGBSequentialModeGet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_RGBSequentialModeGet function.
*/
PLIB_TEMPLATE GLCD_RGB_MODE GLCD_RGBSequentialModeGet_Default( GLCD_MODULE_ID index )
{
	GLCD_RGB_MODE RGB_MODE;
    switch( GLCDMODEbits.RGBSEQ )
    {
        case 0:
            if( CFGCON2bits.GLCDMODE)
			{	
				RGB_MODE = GLCD_RGB_MODE_PARALLEL_RGB565;
			}
            else
			{
                RGB_MODE = GLCD_RGB_MODE_PARALLEL_RGB888;
			}
			break;
        case 1:
            RGB_MODE = GLCD_RGB_MODE_SERIAL_RGB_3;
			break;
        case 2:
            RGB_MODE = GLCD_RGB_MODE_SERIAL_RGBA_4;
			break;
        case 3:
            RGB_MODE = GLCD_RGB_MODE_SERIAL_12BIT;
			break;
        case 6:
            RGB_MODE = GLCD_RGB_MODE_YUYV_16BIT;
			break;
        case 7:
            RGB_MODE = GLCD_RGB_MODE_BT_656;
			break;
    }
	return RGB_MODE;
}

#endif /*_GLCD_RGBSEQUENTIALMODE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

