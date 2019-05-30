/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_EnableControl_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EnableControl
    and its Variant : Default
    For following APIs :
        PLIB_GLCD_ExistsEnable
        PLIB_GLCD_Enable
        PLIB_GLCD_Disable
        PLIB_GLCD_IsEnabled

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

#ifndef _GLCD_ENABLECONTROL_DEFAULT_H
#define _GLCD_ENABLECONTROL_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsEnable_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsEnable

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsEnable function.
*/
#define PLIB_GLCD_ExistsEnable PLIB_GLCD_ExistsEnable
PLIB_TEMPLATE bool GLCD_ExistsEnable_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_Enable_Default

  Summary:
    Implements Default variant of PLIB_GLCD_Enable 

  Description:
    This template implements the Default variant of the PLIB_GLCD_Enable function.
*/
PLIB_TEMPLATE void GLCD_Enable_Default( GLCD_MODULE_ID index )
{

	GLCDMODEbits.LCDEN = 1;				
    

	 CFGCON2bits.GLCDPINEN = 1;					
}

//******************************************************************************
/* Function :  GLCD_Disable_Default

  Summary:
    Implements Default variant of PLIB_GLCD_Disable 

  Description:
    This template implements the Default variant of the PLIB_GLCD_Disable function.
*/

PLIB_TEMPLATE void GLCD_Disable_Default( GLCD_MODULE_ID index )
{
	GLCDMODEbits.LCDEN = 0;				
    

	CFGCON2bits.GLCDPINEN = 0;	
}

//******************************************************************************
/* Function :  GLCD_IsEnabled_Default

  Summary:
    Implements Default variant of PLIB_GLCD_IsEnabled 

  Description:
    This template implements the Default variant of the PLIB_GLCD_IsEnabled function.
*/
PLIB_TEMPLATE bool GLCD_IsEnabled_Default( GLCD_MODULE_ID index )
{
    return GLCDMODEbits.LCDEN & CFGCON2bits.GLCDPINEN;
}

#endif /*_GLCD_ENABLECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

