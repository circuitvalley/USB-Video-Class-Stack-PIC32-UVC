/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_SignalPolarityMode_Unsupported.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : SignalPolarityMode
    and its Variant : Unsupported
    For following APIs :
        PLIB_GLCD_ExistsSignalPolarity
        PLIB_GLCD_SignalPolaritySet
        PLIB_GLCD_SignalPolarityGet

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

#ifndef _GLCD_SIGNALPOLARITYMODE_UNSUPPORTED_H
#define _GLCD_SIGNALPOLARITYMODE_UNSUPPORTED_H

//******************************************************************************
/* Function :  GLCD_ExistsSignalPolarity_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_ExistsSignalPolarity

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_ExistsSignalPolarity function.
*/
PLIB_TEMPLATE bool GLCD_ExistsSignalPolarity_Unsupported( GLCD_MODULE_ID index )
{
    return false;
}

//******************************************************************************
/* Function :  GLCD_SignalPolaritySet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_SignalPolaritySet 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_SignalPolaritySet function.
*/
PLIB_TEMPLATE void GLCD_SignalPolaritySet_Unsupported( GLCD_MODULE_ID       index , GLCD_SIGNAL_POLARITY polarity )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_SignalPolaritySet");
}

//******************************************************************************
/* Function :  GLCD_SignalPolarityGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_GLCD_SignalPolarityGet 

  Description:
    This template implements the Unsupported variant of the PLIB_GLCD_SignalPolarityGet function.
*/
PLIB_TEMPLATE GLCD_SIGNAL_POLARITY GLCD_SignalPolarityGet_Unsupported( GLCD_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_GLCD_SignalPolarityGet");

    return (GLCD_SIGNAL_POLARITY) 0;
}

#endif /*_GLCD_SIGNALPOLARITYMODE_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

