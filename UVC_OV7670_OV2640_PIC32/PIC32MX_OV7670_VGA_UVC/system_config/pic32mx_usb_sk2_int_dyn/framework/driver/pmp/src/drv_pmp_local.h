/*******************************************************************************
  PMP Driver Local Data Structures

  Company:
    Microchip Technology Inc.

  File Name:
    drv_pmp_local.h

  Summary:
    PMP driver local declarations and definitions.

  Description:
    This file contains the PMP driver's local declarations and definitions.
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

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
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

#ifndef _DRV_PMP_LOCAL_H
#define _DRV_PMP_LOCAL_H


// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "driver/pmp/drv_pmp.h"


// *****************************************************************************
// *****************************************************************************
// Section: Data Type Definitions
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
/* PMP Driver Mapped Address Object

  Summary:
    Defines the object required for mapping port pins as higher address lines 
    of the PMP module.

  Description:
    This defines the object required for mapping port pins as higher address lines
    of the PMP module. This object exists once per driver instance.

  Remarks:
    None
*/
typedef union
{
	struct
	{
    	#ifdef DRV_PMP_ADDRESS_LINE_14
		uint16_t 	address_14:1;		// PMPA14 line is multiplexd with CS line
		#endif
		#ifdef DRV_PMP_ADDRESS_LINE_15
		uint16_t	address_15:1;		// PMPA15 line is multiplexd with CS line
		#endif
		#ifdef DRV_PMP_ADDRESS_LINE_16
		uint16_t	address_16:1;
		#endif
		#ifdef DRV_PMP_ADDRESS_LINE_17
		uint16_t	address_17:1;
		#endif
		#ifdef DRV_PMP_ADDRESS_LINE_18
		uint16_t	address_18:1;
		#endif
		#ifdef DRV_PMP_ADDRESS_LINE_19
		uint16_t	address_19:1;
		#endif
		#ifdef DRV_PMP_ADDRESS_LINE_20
		uint16_t	address_20:1;
		#endif
		#ifdef DRV_PMP_ADDRESS_LINE_21
		uint16_t	address_21:1;
		#endif
		#ifdef DRV_PMP_ADDRESS_LINE_22
		uint16_t	address_22:1;
		#endif
		#ifdef DRV_PMP_ADDRESS_LINE_23
		uint16_t	address_23:1;
		#endif
		#ifdef DRV_PMP_ADDRESS_LINE_24
		uint16_t	address_24:1;
		#endif
		#ifdef DRV_PMP_ADDRESS_LINE_25
		uint16_t	address_25:1;
		#endif
		#ifdef DRV_PMP_ADDRESS_LINE_26
		uint16_t	address_26:1;
		#endif
		#ifdef DRV_PMP_ADDRESS_LINE_27
		uint16_t	address_27:1;
		#endif
		#ifdef DRV_PMP_ADDRESS_LINE_28
		uint16_t	address_28:1;
		#endif
		#ifdef DRV_PMP_ADDRESS_LINE_29
		uint16_t	address_29:1;
		#endif
	
	}HIGHER_ADDRESS;

uint16_t PMP_HIGHER_ADDRESS;

}PMP_HIGHER_ADDRESS_MAP;


// *****************************************************************************
/* PMP Driver Hardware Instance Object

  Summary:
    Defines the object required for the maintainence of the hardware instance.

  Description:
    This defines the object required for the maintainence of the hardware
    instance. This object exists once per hardware instance of the peripheral.

  Remarks:
    None.
*/

typedef struct _DRV_PMP_OBJ
{
 
   /* Required : The status of the driver */
    SYS_STATUS                                              status;

    /* Required : The peripheral Id associated with the object */
    PMP_MODULE_ID                                           pmpID;

    // /* Object Index */
    // SYS_MODULE_INDEX                                        objIndex;

    /* Required : Flag to indicate in use  */
    bool                                                    inUse;
	
	/* Flag to indicate that PMP is used in exclusive access mode */
    bool                                                    IsExclusive;

    /* Optional: number of clients possible with the hardware instance */
    uint8_t                                                 numClients;

    	/* Pointer to table of clients */
//    DRV_PMP_CLIENT_OBJ * pDrvPMPClientObj[DRV_PMP_CLIENTS_NUMBER];

    
    /* Status of failed client assignment. */
  DRV_PMP_CLIENT_STATUS   								statusBadClient;
 
	 /* sequence ID which tells the transfer sequence number */
	 uint32_t												seqID;

         bool                                           transferTriggered;

	/* higher addresses mapping */
	PMP_HIGHER_ADDRESS_MAP							addressMap;

	uint32_t										pmpInbuiltAddress;

    /* PORTS Remap Configuration */
 //   DRV_PMP_PORT_PINS                                       pinConfig;


    /* Internal buffer empty status */
//    bool                                                    isBufferEmpty;

    /* Internal buffer full status */
//    bool                                                    isBufferFull;
  
} DRV_PMP_OBJ;


typedef unsigned short int DRV_PMP_OBJ_HANDLE;


// *****************************************************************************
/* PMP Driver Client Object

  Summary:
    Defines the object required for the maintainence of the software clients.

  Description:
    This defines the object required for the maintainence of the software
    clients instance. This object exists once per client instance.

  Remarks:
    None.
*/

typedef struct _DRV_PMP_CLIENT_OBJ
{
    /* Optional : Maintains Client Status  */
    DRV_PMP_CLIENT_STATUS                                   status;

    /* Handle of the driver that own this object */
    DRV_PMP_OBJ 										*  	hDriver; 

    /* Required : Flag to indicate in use  */
    bool                                                    inUse;
    
    /* The intent with which the client was opened */
    DRV_IO_INTENT                                           intent;
	
	/* Mode Configuration setting for the particular client */
	DRV_PMP_MODE_CONFIG										modeConfig;

}DRV_PMP_CLIENT_OBJ;



typedef unsigned short int DRV_PMP_CLIENT_OBJ_HANDLE;

//typedef unsigned short int DRV_PMP_QUEUE_STATUS;  //moved to drv_pmp_local.h file 

// *****************************************************************************
// *****************************************************************************
// Section: Extern data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*  Hardware Objects for the dynamic driver
*/

extern DRV_PMP_OBJ            gDrvPMPObj[];


// *****************************************************************************
/*  Client Objects for the multi-client driver
*/

//extern DRV_PMP_CLIENT_OBJ     gDrvPMPClientObj[];


// *****************************************************************************
/*  Hardware Objects for the static driver
*/

// extern DRV_PMP_OBJ            gDrvPMPObj0;
// extern DRV_PMP_OBJ            gDrvPMPObj1;
// extern DRV_PMP_OBJ            gDrvPMPObj2;
// extern DRV_PMP_OBJ            gDrvPMPObj3;
// extern DRV_PMP_OBJ            gDrvPMPObj4;
// extern DRV_PMP_OBJ            gDrvPMPObj5;
// extern DRV_PMP_OBJ            gDrvPMPObj6;


// *****************************************************************************
/*  Client Objects for the single-client driver
*/

// extern DRV_PMP_CLIENT_OBJ     gDrvPMPClientObj0;
// extern DRV_PMP_CLIENT_OBJ     gDrvPMPClientObj1;
// extern DRV_PMP_CLIENT_OBJ     gDrvPMPClientObj2;
// extern DRV_PMP_CLIENT_OBJ     gDrvPMPClientObj3;
// extern DRV_PMP_CLIENT_OBJ     gDrvPMPClientObj4;
// extern DRV_PMP_CLIENT_OBJ     gDrvPMPClientObj5;
// extern DRV_PMP_CLIENT_OBJ     gDrvPMPClientObj6;


// *****************************************************************************
/*  Byte Q Buffers for dynamic driver
*/

// extern PMP_DATA_TYPE  gDrvByteQ[][DRV_PMP_CONFIG_BYTE_Q_SIZE];


// *****************************************************************************
/*  Byte Q Buffers for static driver
*/

// extern PMP_DATA_TYPE  gDrvByteQ0[DRV_PMP_CONFIG_BYTE_Q_SIZE];

// extern PMP_DATA_TYPE  gDrvByteQ1[DRV_PMP_CONFIG_BYTE_Q_SIZE];

// extern PMP_DATA_TYPE  gDrvByteQ2[DRV_PMP_CONFIG_BYTE_Q_SIZE];

// extern PMP_DATA_TYPE  gDrvByteQ3[DRV_PMP_CONFIG_BYTE_Q_SIZE];

// extern PMP_DATA_TYPE  gDrvByteQ4[DRV_PMP_CONFIG_BYTE_Q_SIZE];

// extern PMP_DATA_TYPE  gDrvByteQ5[DRV_PMP_CONFIG_BYTE_Q_SIZE];

// extern PMP_DATA_TYPE  gDrvByteQ6[DRV_PMP_CONFIG_BYTE_Q_SIZE];


#endif //#ifndef _DRV_PMP_LOCAL_H

/*******************************************************************************
 End of File
*/

