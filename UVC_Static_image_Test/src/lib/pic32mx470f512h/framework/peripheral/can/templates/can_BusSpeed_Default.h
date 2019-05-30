/*******************************************************************************
  CAN Peripheral Library Template Implementation

  File Name:
    can_BusSpeed_Default.h

  Summary:
    CAN PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : BusSpeed
    and its Variant : Default
    For following APIs :
        PLIB_CAN_PrecalculatedBitRateSetup
        PLIB_CAN_ExistsPrecalculatedBitRateSetup
        PLIB_CAN_BitSamplePhaseSet
        PLIB_CAN_ExistsBitSamplePhaseSet
        PLIB_CAN_BaudRatePrescaleSetup
        PLIB_CAN_ExistsBaudRatePrescaleSetup
        PLIB_CAN_BaudRateGet
        PLIB_CAN_ExistsBaudRateGet

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

#ifndef _CAN_BUSSPEED_DEFAULT_H
#define _CAN_BUSSPEED_DEFAULT_H

#include "../templates/can_registers.h"

//******************************************************************************
/* Function :  CAN_PrecalculatedBitRateSetup_Default

  Summary:
    Implements Default variant of PLIB_CAN_PrecalculatedBitRateSetup 

  Description:
    This template implements the Default variant of the PLIB_CAN_PrecalculatedBitRateSetup function.
*/

PLIB_TEMPLATE bool CAN_PrecalculatedBitRateSetup_Default( CAN_MODULE_ID  index , uint8_t        prescale , uint8_t        syncjumpWidth , uint8_t        propagation , uint8_t        segment1 , uint8_t        segment2 )
{
	volatile can_registers_t * can = ((can_registers_t *)(index));
	uint32_t phaseSeg2free = 0x0001;
	uint32_t value = 0;
	uint32_t sample3times = 0;
	uint32_t wakeupfilter = 0;
	uint32_t totalTq = 0;
	uint32_t range = 0;
	range    = (segment1 + propagation);
	totalTq  = (((segment1) + (segment2) + (propagation)) + 1u);	
	
	if( (prescale>0x003eu)||(syncjumpWidth>0x0003u)||(propagation>0x0007u)||(segment1>0x0007u)||(segment2>0x0007u)||(syncjumpWidth<0x0000u)||(propagation<0x0000u)||(segment1<0x0000u)||(segment2<0x0000u))
	{
          return false;
      } 
    //Time quantum range limit		
	else if( (totalTq > 25u) || (totalTq < 8u) || (range < segment2 ) || (segment2 < syncjumpWidth))
	{
          return false;
	}	
	else
	{
	    if(can->CCFG.SAM != 0u)
		{
			if(prescale>=0x0002u)
			{
                      sample3times = 0x0001u;
			}
			else
			{
			    sample3times = 0x0000u;
			}
		}	
	    else
          {
		  sample3times = 0x0000u;
	    } 		
	    if(can->CCFG.WAKFIL != 0u)
	    {
              wakeupfilter = 0x0001u;
	    }
	    else
          {
		  wakeupfilter = 0x0000u;		
	    }
	
	    value = (((uint32_t)(prescale-1u))|(((uint32_t)(syncjumpWidth-1u))<<6u)|(((uint32_t)(propagation-1u))<<8u)|(((uint32_t)(segment1-1u))<<11u)|
	            ((sample3times)<<14u)|((phaseSeg2free)<<15u)|(((uint32_t)(segment2-1u))<<16u)|((wakeupfilter)<<22u));
	

	    can->CCFG.w = value; 
		
		return true;
	}	
}


//******************************************************************************
/* Function :  CAN_ExistsPrecalculatedBitRateSetup_Default

  Summary:
    Implements Default variant of PLIB_CAN_ExistsPrecalculatedBitRateSetup

  Description:
    This template implements the Default variant of the PLIB_CAN_ExistsPrecalculatedBitRateSetup function.
*/

#define PLIB_CAN_ExistsPrecalculatedBitRateSetup PLIB_CAN_ExistsPrecalculatedBitRateSetup
PLIB_TEMPLATE bool CAN_ExistsPrecalculatedBitRateSetup_Default( CAN_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  CAN_BitSamplePhaseSet_Default

  Summary:
    Implements Default variant of PLIB_CAN_BitSamplePhaseSet 

  Description:
    This template implements the Default variant of the PLIB_CAN_BitSamplePhaseSet function.
*/

PLIB_TEMPLATE bool CAN_BitSamplePhaseSet_Default( CAN_MODULE_ID   index , uint8_t         syncJumpWidth , uint8_t         propagation , uint8_t         segment1 , uint8_t         segment2 )
{
	volatile can_registers_t * can = ((can_registers_t *)(index));
    uint8_t SEG1 = (segment1-1u);
    uint8_t SEG2 = (segment2-1u);
    uint8_t PROP = (propagation-1u);
    uint8_t SYNCJUMP = (syncJumpWidth-1u);
	uint32_t totalTq = 0;
	uint32_t range = 0u, value = 0u;
	range    = (uint32_t)(segment1 + propagation);	
	totalTq  = (uint32_t)(((segment1) + (segment2) + (propagation)) + 1u);

	if((syncJumpWidth>0x0004u)||(propagation>0x0008u)||(segment1>0x0008u)||
        (segment2>0x0008u)||(syncJumpWidth<0x0001u)||(propagation<0x0001u)||
        (segment1<0x0001u)||(segment2<0x0001u))
    { 
	    return false;
    }    
	else if( (totalTq > 25u) || (totalTq < 8u) || (range < segment2 ) ||
             (segment2 < syncJumpWidth) ) 
        //Time quantum range limit		
    {
	    return false;	
	}
	else
	{
        value = ( ( 1u <<_C1CFG_SEG2PHTS_POSITION ) | 
                  ( SEG1 << _C1CFG_SEG1PH_POSITION)|
                  ( SEG2 << _C1CFG_SEG2PH_POSITION)|
                  ( PROP << _C1CFG_PRSEG_POSITION) |
                  ( SYNCJUMP << _C1CFG_SJW_POSITION));
        can->CCFG.w |= value;
        return true;						 
	}		
}


//******************************************************************************
/* Function :  CAN_ExistsBitSamplePhaseSet_Default

  Summary:
    Implements Default variant of PLIB_CAN_ExistsBitSamplePhaseSet

  Description:
    This template implements the Default variant of the PLIB_CAN_ExistsBitSamplePhaseSet function.
*/

#define PLIB_CAN_ExistsBitSamplePhaseSet PLIB_CAN_ExistsBitSamplePhaseSet
PLIB_TEMPLATE bool CAN_ExistsBitSamplePhaseSet_Default( CAN_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  CAN_BaudRatePrescaleSetup_Default

  Summary:
    Implements Default variant of PLIB_CAN_BaudRatePrescaleSetup 

  Description:
    This template implements the Default variant of the PLIB_CAN_BaudRatePrescaleSetup function.
*/

PLIB_TEMPLATE bool CAN_BaudRatePrescaleSetup_Default( CAN_MODULE_ID index , uint16_t prescale )
{
	volatile can_registers_t * can = ((can_registers_t *)(index));
	if(prescale <= 0x003Fu)
	{
		can->CCFG.BRP = prescale;
		return true;
	}	
	else 
	{
      	return false;
      }
}


//******************************************************************************
/* Function :  CAN_ExistsBaudRatePrescaleSetup_Default

  Summary:
    Implements Default variant of PLIB_CAN_ExistsBaudRatePrescaleSetup

  Description:
    This template implements the Default variant of the PLIB_CAN_ExistsBaudRatePrescaleSetup function.
*/

#define PLIB_CAN_ExistsBaudRatePrescaleSetup PLIB_CAN_ExistsBaudRatePrescaleSetup
PLIB_TEMPLATE bool CAN_ExistsBaudRatePrescaleSetup_Default( CAN_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  CAN_BaudRateGet_Default

  Summary:
    Implements Default variant of PLIB_CAN_BaudRateGet 

  Description:
    This template implements the Default variant of the PLIB_CAN_BaudRateGet function.
*/

PLIB_TEMPLATE uint32_t CAN_BaudRateGet_Default( CAN_MODULE_ID index , uint32_t sysclock )
{
	volatile can_registers_t * can = ((can_registers_t *)(index));
	uint32_t speedconfig;
	uint32_t totalTq,Baudrate;
	uint8_t  prescaler;
	uint8_t  segment2;
	uint8_t  segment1;
	uint8_t  propagation;
	
	speedconfig = can->CCFG.w; 

	prescaler   =  (speedconfig & 0x0000003Fu);
	propagation = (((speedconfig & 0x00000700u) >> 8u) + 1u);
	segment1    = (((speedconfig & 0x00003800u) >> 11u) + 1u);
	segment2    = (((speedconfig & 0x00070000u) >> 16u) + 1u);
	totalTq     = (((segment1) + (segment2) + (propagation)) + 1u);	

	Baudrate = (sysclock/((prescaler+1u) * totalTq * 2u))/1000u;	
	
	return ( Baudrate);
}


//******************************************************************************
/* Function :  CAN_ExistsBaudRateGet_Default

  Summary:
    Implements Default variant of PLIB_CAN_ExistsBaudRateGet

  Description:
    This template implements the Default variant of the PLIB_CAN_ExistsBaudRateGet function.
*/

#define PLIB_CAN_ExistsBaudRateGet PLIB_CAN_ExistsBaudRateGet
PLIB_TEMPLATE bool CAN_ExistsBaudRateGet_Default( CAN_MODULE_ID index )
{
    return true;
}


#endif /*_CAN_BUSSPEED_DEFAULT_H*/

/******************************************************************************
 End of File
*/

