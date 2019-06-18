/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_IRQTriggerControl_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : IRQTriggerControl
    and its Variant : Default
    For following APIs :
        PLIB_GLCD_ExistsIRQTriggerControl
        PLIB_GLCD_IRQTriggerControlSet
        PLIB_GLCD_IRQTriggerControlGet

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

#ifndef _GLCD_IRQTRIGGERCONTROL_DEFAULT_H
#define _GLCD_IRQTRIGGERCONTROL_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsIRQTriggerControl_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsIRQTriggerControl

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsIRQTriggerControl function.
*/
#define PLIB_GLCD_ExistsIRQTriggerControl PLIB_GLCD_ExistsIRQTriggerControl
PLIB_TEMPLATE bool GLCD_ExistsIRQTriggerControl_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_IRQTriggerControlSet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_IRQTriggerControlSet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_IRQTriggerControlSet function.
*/
PLIB_TEMPLATE void GLCD_IRQTriggerControlSet_Default( GLCD_MODULE_ID           index , 
                                                      GLCD_IRQ_TRIGGER_CONTROL irqControl )
{
    switch( irqControl )
    {
	case GLCD_IRQ_TRIGGER_LEVEL:
        {
	    GLCDINTbits.IRQCON = 0;
	    break;
	}

	case GLCD_IRQ_TRIGGER_EDGE:
	{
	    GLCDINTbits.IRQCON = 1;
	    break;
	}
    }
}

//******************************************************************************
/* Function :  GLCD_IRQTriggerControlGet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_IRQTriggerControlGet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_IRQTriggerControlGet function.
*/
PLIB_TEMPLATE GLCD_IRQ_TRIGGER_CONTROL GLCD_IRQTriggerControlGet_Default( GLCD_MODULE_ID index )
{
    if(  GLCDINTbits.IRQCON )
    {
        return ( GLCD_IRQ_TRIGGER_EDGE );
    }
    else
    {
        return ( GLCD_IRQ_TRIGGER_LEVEL ) ;
    }
}

#endif /*_GLCD_IRQTRIGGERCONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

