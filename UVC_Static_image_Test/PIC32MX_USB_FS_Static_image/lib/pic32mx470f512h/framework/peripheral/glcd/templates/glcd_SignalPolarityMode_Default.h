/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_SignalPolarityMode_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : SignalPolarityMode
    and its Variant : Default
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

#ifndef _GLCD_SIGNALPOLARITYMODE_DEFAULT_H
#define _GLCD_SIGNALPOLARITYMODE_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsSignalPolarity_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsSignalPolarity

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsSignalPolarity function.
*/
#define PLIB_GLCD_ExistsSignalPolarity PLIB_GLCD_ExistsSignalPolarity
PLIB_TEMPLATE bool GLCD_ExistsSignalPolarity_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_SignalPolaritySet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_SignalPolaritySet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_SignalPolaritySet function.
*/
PLIB_TEMPLATE void GLCD_SignalPolaritySet_Default( GLCD_MODULE_ID       index , 
                                                   GLCD_SIGNAL_POLARITY polarity )
{
    uint32_t mask = _GLCDMODE_PCLKPOL_MASK | _GLCDMODE_DEPOL_MASK |
                    _GLCDMODE_HSYNCPOL_MASK | _GLCDMODE_VSYNCPOL_MASK;
    GLCDMODE = polarity & mask;
}

//******************************************************************************
/* Function :  GLCD_SignalPolarityGet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_SignalPolarityGet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_SignalPolarityGet function.
*/
PLIB_TEMPLATE GLCD_SIGNAL_POLARITY GLCD_SignalPolarityGet_Default( GLCD_MODULE_ID index )
{
    uint32_t mask = _GLCDMODE_PCLKPOL_MASK | _GLCDMODE_DEPOL_MASK |
                    _GLCDMODE_HSYNCPOL_MASK | _GLCDMODE_VSYNCPOL_MASK;
    return (GLCD_SIGNAL_POLARITY)(GLCDMODE & mask);
}

#endif /*_GLCD_SIGNALPOLARITYMODE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

