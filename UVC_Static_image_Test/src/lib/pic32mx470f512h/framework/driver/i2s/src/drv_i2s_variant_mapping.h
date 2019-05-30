/*******************************************************************************
  I2S Driver Feature Variant Implementations

  Company:
    Microchip Technology Inc.

  File Name:
    drv_I2S_variant_mapping.h

  Summary:
    I2S Driver Feature Variant Implementations

  Description:
    This file implements the functions which differ based on different parts
    and various implementations of the same feature.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip  Technology  Inc.   All  rights  reserved.

Microchip licenses to  you  the  right  to  use,  modify,  copy  and  distribute
Software only when embedded on a Microchip  microcontroller  or  digital  signal
controller  that  is  integrated  into  your  product  or  third  party  product
(pursuant to the  sublicense  terms  in  the  accompanying  license  agreement).

You should refer  to  the  license  agreement  accompanying  this  Software  for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS  WITHOUT  WARRANTY  OF  ANY  KIND,
EITHER EXPRESS  OR  IMPLIED,  INCLUDING  WITHOUT  LIMITATION,  ANY  WARRANTY  OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A  PARTICULAR  PURPOSE.
IN NO EVENT SHALL MICROCHIP OR  ITS  LICENSORS  BE  LIABLE  OR  OBLIGATED  UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,  BREACH  OF  WARRANTY,  OR
OTHER LEGAL  EQUITABLE  THEORY  ANY  DIRECT  OR  INDIRECT  DAMAGES  OR  EXPENSES
INCLUDING BUT NOT LIMITED TO ANY  INCIDENTAL,  SPECIAL,  INDIRECT,  PUNITIVE  OR
CONSEQUENTIAL DAMAGES, LOST  PROFITS  OR  LOST  DATA,  COST  OF  PROCUREMENT  OF
SUBSTITUTE  GOODS,  TECHNOLOGY,  SERVICES,  OR  ANY  CLAIMS  BY  THIRD   PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE  THEREOF),  OR  OTHER  SIMILAR  COSTS.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef _DRV_I2S_VARIANT_MAPPING_H
#define _DRV_I2S_VARIANT_MAPPING_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#if !defined(DRV_I2S_INSTANCES_NUMBER)

    #if defined(DRV_I2S_CLIENTS_NUMBER)

		/* Map internal macros and functions to the static multi open variant */

    #else

		/* Map internal macros and functions to the static single open variant */
    #endif

    #define _DRV_I2S_IS_STATIC

#else

    /* This means that dynamic operation is requested */

    #define _DRV_I2S_IS_DYNAMIC

#endif

// *****************************************************************************
// *****************************************************************************
// Section: I2S Driver Static Object Generation
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Macro: _DRV_I2S_OBJ_MAKE_NAME(name)

  Summary:
    Creates an instance-specific static object name.

  Description:
     This macro creates the instance-specific name of the specified static object
     by inserting the index number into the name.

  Remarks:
    This macro does not affect the dynamic objects.
*/

#define _DRV_STATIC_OBJ_NAME_B(name,id)     name ## id
#define _DRV_STATIC_OBJ_NAME_A(name,id)     _DRV_STATIC_OBJ_NAME_B(name,id)
#define _DRV_I2S_OBJ_MAKE_NAME(name)        _DRV_STATIC_OBJ_NAME_A(name, DRV_I2S_INDEX)

/**********************************************
 * These macros allow variables to be compiled
 * based on dynamic or static buil.
 *********************************************/

#ifdef _DRV_I2S_IS_STATIC

    #define _DRV_I2S_FOR_DYNAMIC( type, object )
    #define _DRV_I2S_FOR_STATIC( type, object )     type object

#endif

#ifdef _DRV_I2S_IS_DYNAMIC

    #define _DRV_I2S_FOR_DYNAMIC( type, object )    type object
    #define _DRV_I2S_FOR_STATIC( type, object )

#endif

// *****************************************************************************
/* Interrupt Source Control

  Summary:
    Macros to enable, disable or clear the interrupt source

  Description:
    These macros enable, disable, or clear the interrupt source.

    The macros get mapped to the respective SYS module APIs if the configuration
    option DRV_I2S_INTERRUPT_MODE is set to true.

  Remarks:
    These macros are mandatory.
*/

#ifndef DRV_I2S_INTERRUPT_MODE
    #error "Interrupt mode must be defined and must be either true or false"
#endif

#if defined (DRV_I2S_INTERRUPT_MODE) && \
            (DRV_I2S_INTERRUPT_MODE == true)

    #define _DRV_I2S_InterruptSourceEnable(source)      SYS_INT_SourceEnable( source )
    #define _DRV_I2S_InterruptSourceDisable(source)     SYS_INT_SourceDisable( source )
    #define _DRV_I2S_InterruptSourceClear(source)       SYS_INT_SourceStatusClear( source )

    #define _DRV_I2S_InterruptSourceStatusGet(source)   SYS_INT_SourceStatusGet( source )
    #define _DRV_I2S_InterruptSourceStatusSet(source)   SYS_INT_SourceStatusSet( source )

    #define _DRV_I2S_isInInterruptContextSet(isInInterruptContext)  isInInterruptContext = true
    #define _DRV_I2S_isInInterruptContextClear(isInInterruptContext)  isInInterruptContext = false

    #define _DRV_I2S_SEM_POST(x)                          OSAL_SEM_PostISR(x)

    #define _SYS_DMA_ChannelForceStart(channelHandle)

#elif defined (DRV_I2S_INTERRUPT_MODE) && \
              (DRV_I2S_INTERRUPT_MODE == false)

    #define _DRV_I2S_InterruptSourceEnable(source)
    #define _DRV_I2S_InterruptSourceDisable(source)     false
    #define _DRV_I2S_InterruptSourceClear(source)       SYS_INT_SourceStatusClear( source )
    #define _DRV_I2S_InterruptSourceStatusGet(source)   SYS_INT_SourceStatusGet( source )

    #define _DRV_I2S_isInInterruptContextSet(isInInterruptContext)
    #define _DRV_I2S_isInInterruptContextClear(isInInterruptContext)

    #define _DRV_I2S_SEM_POST(x)                          OSAL_SEM_Post(x)

    #define _SYS_DMA_ChannelForceStart(channelHandle)   SYS_DMA_ChannelForceStart(channelHandle)
#else

    #error "No Task mode chosen at build, interrupt or polling needs to be selected. "

#endif

/**********************************************
 * Sets up driver mode-specific init routine
 * based on selected support.
 *********************************************/


#endif //_DRV_I2S_VARIANT_MAPPING_H
