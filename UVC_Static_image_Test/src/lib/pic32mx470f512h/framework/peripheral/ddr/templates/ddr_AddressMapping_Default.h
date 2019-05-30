/*******************************************************************************
  DDR Peripheral Library Template Implementation

  File Name:
    ddr_AddressMapping_Default.h

  Summary:
    DDR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : AddressMapping
    and its Variant : Default
    For following APIs :
        PLIB_DDR_RowAddressSet
        PLIB_DDR_ColumnAddressSet
        PLIB_DDR_BankAddressSet
        PLIB_DDR_ChipSelectAddressSet
        PLIB_DDR_ExistsAddressMapping

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _DDR_ADDRESSMAPPING_DEFAULT_H
#define _DDR_ADDRESSMAPPING_DEFAULT_H

//******************************************************************************
/* Function :  DDR_RowAddressSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_RowAddressSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_RowAddressSet function.
*/

PLIB_TEMPLATE void DDR_RowAddressSet_Default( DDR_MODULE_ID index , uint32_t rowShft , uint32_t rowMsk )
{
	DDRMEMCFG0bits.RWADDR = rowShft;
	DDRMEMCFG1bits.RWADDRMSK = rowMsk;
}


//******************************************************************************
/* Function :  DDR_ColumnAddressSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_ColumnAddressSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_ColumnAddressSet function.
*/

PLIB_TEMPLATE void DDR_ColumnAddressSet_Default( DDR_MODULE_ID index , uint32_t colShft , uint32_t colMskLo , uint32_t colMskHi )
{
    DDRMEMCFG0bits.CLHADDR = colShft;
	DDRMEMCFG3bits.CLADDRLMSK = colMskLo;
	DDRMEMCFG2bits.CLADDRHMSK = colMskHi;
}


//******************************************************************************
/* Function :  DDR_BankAddressSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_BankAddressSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_BankAddressSet function.
*/

PLIB_TEMPLATE void DDR_BankAddressSet_Default( DDR_MODULE_ID index , uint32_t bnkShft , uint32_t bnkMsk )
{
	DDRMEMCFG0bits.BNKADDR = bnkShft;
	DDRMEMCFG4bits.BNKADDRMSK = bnkMsk;
}


//******************************************************************************
/* Function :  DDR_ChipSelectAddressSet_Default

  Summary:
    Implements Default variant of PLIB_DDR_ChipSelectAddressSet 

  Description:
    This template implements the Default variant of the PLIB_DDR_ChipSelectAddressSet function.
*/

PLIB_TEMPLATE void DDR_ChipSelectAddressSet_Default( DDR_MODULE_ID index , uint32_t csShft , uint32_t csMsk )
{
	DDRMEMCFG0bits.CSADDR = csShft;
	DDRMEMCFG4bits.CSADDRMSK = csMsk;
}


//******************************************************************************
/* Function :  DDR_ExistsAddressMapping_Default

  Summary:
    Implements Default variant of PLIB_DDR_ExistsAddressMapping

  Description:
    This template implements the Default variant of the PLIB_DDR_ExistsAddressMapping function.
*/

#define PLIB_DDR_ExistsAddressMapping PLIB_DDR_ExistsAddressMapping
PLIB_TEMPLATE bool DDR_ExistsAddressMapping_Default( DDR_MODULE_ID index )
{
    return true;
}


#endif /*_DDR_ADDRESSMAPPING_DEFAULT_H*/

/******************************************************************************
 End of File
*/

