/*******************************************************************************
  GLCD Peripheral Library Template Implementation

  File Name:
    glcd_LinesPrefetch_Default.h

  Summary:
    GLCD PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : LinesPrefetch
    and its Variant : Default
    For following APIs :
        PLIB_GLCD_ExistsLinesPrefetch
        PLIB_GLCD_LinesPrefetchSet
        PLIB_GLCD_LinesPrefetchGet

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

#ifndef _GLCD_LINESPREFETCH_DEFAULT_H
#define _GLCD_LINESPREFETCH_DEFAULT_H

//******************************************************************************
/* Function :  GLCD_ExistsLinesPrefetch_Default

  Summary:
    Implements Default variant of PLIB_GLCD_ExistsLinesPrefetch

  Description:
    This template implements the Default variant of the PLIB_GLCD_ExistsLinesPrefetch function.
*/

#define PLIB_GLCD_ExistsLinesPrefetch PLIB_GLCD_ExistsLinesPrefetch
PLIB_TEMPLATE bool GLCD_ExistsLinesPrefetch_Default( GLCD_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  GLCD_LinesPrefetchSet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LinesPrefetchSet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LinesPrefetchSet function.
*/
PLIB_TEMPLATE void GLCD_LinesPrefetchSet_Default( GLCD_MODULE_ID  index , 
                                                  uint32_t        linesPrefetch )
{
    GLCDCLKCONbits.LPREFETCH = linesPrefetch;
}

//******************************************************************************
/* Function :  GLCD_LinesPrefetchGet_Default

  Summary:
    Implements Default variant of PLIB_GLCD_LinesPrefetchGet 

  Description:
    This template implements the Default variant of the PLIB_GLCD_LinesPrefetchGet function.
*/
PLIB_TEMPLATE uint32_t GLCD_LinesPrefetchGet_Default( GLCD_MODULE_ID index )
{
    return GLCDCLKCONbits.LPREFETCH;
}

#endif /*_GLCD_LINESPREFETCH_DEFAULT_H*/

/******************************************************************************
 End of File
*/

