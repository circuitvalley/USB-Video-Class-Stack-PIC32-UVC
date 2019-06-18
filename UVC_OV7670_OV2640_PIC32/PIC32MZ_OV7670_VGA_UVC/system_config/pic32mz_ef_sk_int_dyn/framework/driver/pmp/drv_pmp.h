/*******************************************************************
  Company:
    Microchip Technology Inc.
    
  File Name:
    drv_pmp.h
	  
  Summary:
    Parallel Master Port (PMP) device driver interface file.
	
  Description:
    PMP Device Driver Interface
    
    The PMP device driver provides a simple interface to manage the
    Parallel Master and Slave ports. This file defines the interface
    definitions and prototypes for the PMP driver.                  
  *******************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

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


#ifndef _DRV_PMP_H
#define _DRV_PMP_H


// *****************************************************************************
// *****************************************************************************
// Section: Include Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>

#include "../driver_common.h"
#include "peripheral/pmp/plib_pmp.h"
#include "system/common/sys_module.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

#define MAX_NONBUFFERED_BYTE_COUNT 4 /**********************************************************************
                                       After this number the PMP transfer should be polled to guarantee data
                                       transfer                                                             
                                       **********************************************************************/

// *****************************************************************************
/* PMP Driver Module Index Numbers

  Summary:
    PMP driver index definitions.

  Description:
    These constants provide PMP driver index definitions.

  Remarks:
    These values should be passed into the DRV_PMP_Initialize and
    DRV_PMP_Open functions to identify the driver instance in use.
*/

typedef enum
{
    /* First PMP instance */
    DRV_PMP_INDEX_0,         
    /*Second PMP instance (not available for now)*/
    DRV_PMP_INDEX_1         
         
} DRV_PMP_INDEX;    


// *****************************************************************************
/* PMP Driver Module Index Count

  Summary:
    Number of valid PMP driver indices.

  Description:
    This constant identifies the number of valid PMP driver indices.

  Remarks:
    The value of "_PMP_EXISTS" is derived from device-specific header files defined
    as part of the peripheral libraries.
*/

	#define DRV_PMP_INDEX_COUNT     _PMP_EXISTS

 
// *****************************************************************************

/* PMP port enable/disable.

  Summary:
    PMP port enable/disable definitions.

  Description:
    This enumeration provides port enable/disable values.

 */

typedef enum
{
    /* Enable the given port */
    PORT_ENABLE,
	
    /* Disable the given port */
    PORT_DISABLE

} DRV_PMP_PORT_CONTROL;

// *****************************************************************************
/* PMP Client Status

  Summary:
    PMP client status definitions.

  Description:
    This enumeration provides various client status possibilities.

 */

typedef enum
{
   
    DRV_PMP_CLIENT_STATUS_INVALID
        /*DOM-IGNORE-BEGIN*/  = DRV_CLIENT_STATUS_ERROR  - 1 /*DOM-IGNORE-END*/,

    PMP_CLIENT_STATUS_CLOSED
        /*DOM-IGNORE-BEGIN*/  = DRV_CLIENT_STATUS_CLOSED  /*DOM-IGNORE-END*/,

    DRV_PMP_CLIENT_STATUS_OPEN
        /*DOM-IGNORE-BEGIN*/  = DRV_CLIENT_STATUS_BUSY      /*DOM-IGNORE-END*/,
   

} DRV_PMP_CLIENT_STATUS;

/*****************************************************************************/
/* Queue Element Transfer Status

   Summary:
    Defines the PMP transfer status.

   Description:
    This enumeration defines the PMP transfer status.

*/
typedef enum
{

    MASTER_8BIT_TRANSFER_IN_PROGRESS = PMP_DATA_SIZE_8_BITS,

    MASTER_16BIT_TRANSFER_IN_PROGRESS = PMP_DATA_SIZE_16_BITS,

    MASTER_8BIT_BUFFER_IN_PROGRESS,

    MASTER_16BIT_BUFFER_IN_PROGRESS,

    MASTER_8BIT_TRANSFER_CONTINUE,

    MASTER_8BIT_BUFFER_CONTINUE,

    QUEUED_BUT_PMP_TRANSFER_NOT_STARTED,
	
    PMP_TRANSFER_FINISHED,
	
} DRV_PMP_TRANSFER_STATUS;

typedef enum
{
    /* PMP Address needs to be updated */
    ADDRESS,

    /* PMP Read Transfer */
    READ,

    /* PMP Write Transfer */
    WRITE,

    /* PMP Array Write Transfer */
    BUFFERED_WRITE

} DRV_PMP_TRANSFER_TYPE;

// *****************************************************************************
/* PMP Driver Queue Element Object

  Summary:
    Defines the object for PMP queue element.

  Description:
    This defines the object structure for each queue element of PMP.
    This object gets created for every Read/Write operations APIs.

  Remarks:
    None
*/

typedef struct _DRV_PMP_QUEUE_ELEMENT_OBJ
{
	/* handle of the client object returned from open API */
    struct _DRV_PMP_CLIENT_OBJ                              *hClient;

	/* pointer to the buffer holding the transmitted data */
	uint32_t 											    buffer;

	/* pointer to the buffer holding the transmitted data */
	uint16_t* 											    addressBuffer;
	
	/* number of bytes to be transferred */
	uint32_t 												nTransfers;
	
	/* number of times the data set has to be transferred repeatedly */
	int32_t 												nRepeats;
	
	/* PMP Read or Write */
	DRV_PMP_TRANSFER_TYPE                                   type;
	
} DRV_PMP_QUEUE_ELEMENT_OBJ;


/*****************************************************************************/
/* Queue Element Object

   Summary
    Defines the structure required for maintaining the queue element.

   Description
    This defines the structure required for maintaining the queue element.

   Remarks:
    None
*/

typedef struct
{
    /* The PMP Q Element */
    DRV_PMP_QUEUE_ELEMENT_OBJ               data;

    /* Flag to indicate that the element is in use */
    DRV_PMP_TRANSFER_STATUS                 eTransferStatus;
	
	/* sequence id */
	uint32_t								nTransfersDone;

} PMP_QUEUE_ELEMENT_OBJECT;


// *****************************************************************************

/* PMP writeEnable/ReadWrite strobes

  Summary:
    PMP writeEnable/ReadWrite strobes.

  Description:
    This enumeration provides ReadWrite/WriteEnable Strobe definitions.

 */

typedef enum
{
    /* One strobe for read/write and another for enable */
    PMP_RW_STROBE_WITH_ENABLE_STROBE,

    /* Separate strobes for read and write operations */
    PMP_READ_AND_WRITE_STROBES

} DRV_PMP_CHIPX_STROBE_MODE;

// *****************************************************************************

/* PMP Endian modes

  Summary:
    PMP Endian modes.

  Description:
    This enumeration holds the Endian configuration options.

 */

typedef enum
{
    /* Little Endian */
    LITTLE,

    /* Big Endian */
    BIG

} DRV_PMP_ENDIAN_MODE;

// *****************************************************************************
/* PMP wait states object

  Summary:
    PMP wait states object.

  Description:
    This structure holds the different wait states to be configured.
    Refer to the PMP PLIB help document for the possible values and meaning 
    of the different wait states.

 */

typedef struct
{
    /* data hold wait states */
    PMP_DATA_HOLD_STATES dataHoldWait
					/*DOM-IGNORE-BEGIN*/ : 2  /*DOM-IGNORE-END*/;
						
    /* read/write strobe wait states */
    PMP_STROBE_WAIT_STATES strobeWait
					/*DOM-IGNORE-BEGIN*/ : 4  /*DOM-IGNORE-END*/;
    /* data wait strobe wait sates */
    PMP_DATA_WAIT_STATES dataWait
					/*DOM-IGNORE-BEGIN*/ : 2  /*DOM-IGNORE-END*/;
						
}DRV_PMP_WAIT_STATES;


// *****************************************************************************
/* PMP polarity object

  Summary:
    PMP polarity object.

  Description:
    This structure holds the polarities of different entities to be configured.

 */
 
typedef struct
{
    /* Address latch polarity */
    PMP_POLARITY_LEVEL addressLatchPolarity 
						/*DOM-IGNORE-BEGIN*/ : 1  /*DOM-IGNORE-END*/;

    /* ByteEnable port polarity */
    PMP_POLARITY_LEVEL byteEnablePolarity
						/*DOM-IGNORE-BEGIN*/ : 1  /*DOM-IGNORE-END*/;
						
    /* Read/Write strobe polarity */
    PMP_POLARITY_LEVEL rwStrobePolarity
						/*DOM-IGNORE-BEGIN*/ : 1  /*DOM-IGNORE-END*/;
						
    /* Write/Enable strobe polarity */
    PMP_POLARITY_LEVEL writeEnableStrobePolarity
						/*DOM-IGNORE-BEGIN*/ : 1  /*DOM-IGNORE-END*/;
						
    /* ChipSelect-1 Polarity */
    PMP_POLARITY_LEVEL chipselect1Polarity
						/*DOM-IGNORE-BEGIN*/ : 1  /*DOM-IGNORE-END*/;
						
    /* chipSelect-2 Polarity */
    PMP_POLARITY_LEVEL chipselect2Polarity
						/*DOM-IGNORE-BEGIN*/ : 1  /*DOM-IGNORE-END*/;
						
} DRV_PMP_POLARITY_OBJECT;


// *****************************************************************************
/* PMP Ports

  Summary:
    PMP port configuration.

  Description:
    This structure holds the ports (including the address ports) to be configured
    by the application to function as general purpose I/O (GPIO) or part of the PMP.

 */

typedef struct
{
    
	/******************************************************************
	  User needs to put the address lines which he wants to use in ORed
	  fashion * Address ports                                     
	  ******************************************************************/
	PMP_ADDRESS_PORT addressPortsMask;

    /* Byte enable ports */
    PMP_PMBE_PORT byteEnablePort;
	
	/* READ/WRITE Strobe PORT */
	DRV_PMP_PORT_CONTROL  readWriteStrobe;

    /* WRITE/ENABLE strobe port */
	DRV_PMP_PORT_CONTROL  writeEnableStrobe;
      
}DRV_PMP_PORTS;

// *****************************************************************************
/* PMP modes configuration

  Summary:
    PMP modes configuration.

  Description:
    This data type controls the configuration of PMP modes.

*/

typedef struct
{
    /* PMP Usage Mode Type */
    PMP_OPERATION_MODE              pmpMode;
	
	/* Interrupt mode */
    PMP_INTERRUPT_MODE              intMode;
	
	// should be appropriately selected based on read/write requirements 
	// and operation mode setting */
	/* address/buffer increment mode */
    PMP_INCREMENT_MODE              incrementMode;
	
	// it does not have any significance in PMP slave mode or 8bit data mode */
	/* Endian modes */
	DRV_PMP_ENDIAN_MODE				endianMode;
	
	/* Data Port Size */
    PMP_DATA_SIZE                   portSize;
	
	/* Wait states */
    DRV_PMP_WAIT_STATES             waitStates;
	
	/* PMP chip select pins selection */
	PMP_CHIPSELECT_FUNCTION			chipSelect; // use this when PLIB is fixed
	
//	PMP_CHIP_SELECT					chipSelect; //remove this when PLIB is fixed

    /* PMP callback */
//    DRV_PMP_CALLBACK                callback; //use later when call back functionality is implemented

} DRV_PMP_MODE_CONFIG;


// *****************************************************************************
/* PMP Driver Initialize Data

  Summary:
    Defines the PMP driver initialization data.

  Description:
    This data type defines data required to initialize or reinitialize the PMP
    driver.

  Remarks:
    Not all the initialization features are available for all devices.
*/

typedef struct 
{
    
    /* module power state info */
    SYS_MODULE_INIT                 moduleInit;

    /* module PLIB ID */
    PMP_MODULE_ID                   pmpID;

    /* Stop in Idle enable */
    bool                            stopInIdle;

    /* address latch enable */
   //PMP_ADDRESS_LATCH               addressLatch;

    /* MUX mode */
    PMP_MUX_MODE                    muxMode;

    /* Input buffer type to be used */
    PMP_INPUT_BUFFER_TYPE           inputBuffer;

    /* Polarity settings */
    DRV_PMP_POLARITY_OBJECT         polarity;

    /* PMP port settings */
    DRV_PMP_PORTS                   ports;

}DRV_PMP_INIT;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - System Level
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
       SYS_MODULE_OBJ DRV_PMP_Initialize( const SYS_MODULE_INDEX drvIndex,
                                          const SYS_MODULE_INIT * const init )
    
  Summary:
    Initializes the PMP driver.
	<p><b>Implementation:</b> Static/Dynamic</p>
	
  Description:
    This function initializes the PMP driver, making it ready for clients
    to open and use it.
	
  Precondition:
    None.
	
  Parameters:
    drvIndex -  Index for the driver instance to be initialized
    init -      Pointer to a data structure containing any data necessary to
                initialize the driver
				
  Returns:
    If successful, it returns a valid handle to a driver object. Otherwise,
    it returns SYS_MODULE_OBJ_INVALID. The returned object must be passed
    as argument to DRV_PMP_Reinitialize, DRV_PMP_Deinitialize,
    DRV_PMP_Tasks and DRV_PMP_Status routines.
	
  Example:
    <code>
    
    DRV_PMP_INIT    init;
    SYS_MODULE_OBJ  objectHandle;
    
    // Populate the initialization structure
    init.inputBuffer = PMP_INPUT_BUFFER_TTL;
    init.polarity.addressLatchPolarity = PMP_POLARITY_ACTIVE_HIGH;
    init.polarity.rwStrobePolarity = PMP_POLARITY_ACTIVE_LOW;
    init.polarity.writeEnableStrobePolarity = PMP_POLARITY_ACTIVE_LOW;
    init.polarity.chipselect1Polarity = PMP_POLARITY_ACTIVE_HIGH;
    init.polarity.chipselect2Polarity = PMP_POLARITY_ACTIVE_LOW;
    init.ports.addressPortsMask = PMP_PMA0_PORT | PMP_PMA1_PORT | PMP_PMA2_TO_PMA13_PORTS | PMP_PMA14_PORT;
    init.ports.readWriteStrobe = PORT_ENABLE;
    init.ports.writeEnableStrobe = PORT_ENABLE;
    init.moduleInit.value = SYS_MODULE_POWER_RUN_FULL;
    init.pmpID            = PMP_ID_0;
    init.stopInIdle       = false;
    init.muxMode          = PMP_MUX_NONE;
    
    // Do something
    
    objectHandle = DRV_PMP_Initialize(DRV_PMP_INDEX_0,  (SYS_MODULE_INIT*)&init);
    if (SYS_MODULE_OBJ_INVALID == objectHandle)
    {
        // Handle error
    }
    </code>
	
  Remarks:
    This function must be called before any other PMP function is called.
    
    This function should only be called once during system initialization
    unless DRV_PMP_Deinitialize is called to deinitialize the driver
    instance.
    
    This function will NEVER block for hardware access. If the operation
    requires time to allow the hardware to reinitialize, it will be
    reported by the DRV_PMP_Status operation. The system must use
    DRV_PMP_Status to find out when the driver is in the ready state.
    
    Build configuration options may be used to statically override options
    in the "init" structure and will take precedence over initialization
    data passed using this function.                                                                       
  **********************************************************************************************************/


SYS_MODULE_OBJ DRV_PMP_Initialize ( const SYS_MODULE_INDEX drvIndex,
                                    const SYS_MODULE_INIT * const init );

									
/**********************************************************************************************************
  Summary:
    Reinitializes the driver and refreshes any associated hardware
    settings.
	<p><b>Implementation:</b> Dynamic</p>
	
  Description:
    This function reinitializes the driver and refreshes any associated
    hardware settings using the specified initialization data, but it will
    not interrupt any ongoing operations.
	
  Precondition:
    The DRV_PMP_Initialize function must have been called before calling
    this function and a valid SYS_MODULE_OBJ must have been returned.
	
  Parameters:
    pmpDriverObject -  Driver object handle, returned from the
                       DRV_PMP_Initialize
  Function:
       void DRV_PMP_Reinitialize ( SYS_MODULE_OBJ                pmpDriverObject,
                                   const SYS_MODULE_INIT * const init )
    
       init            - Pointer to the initialization data structure
    
  Returns:
    None.
	
  Example:
    <code>
    
    DRV_PMP_INIT    init;
    SYS_MODULE_OBJ  pmpDriverObject;
    SYS_STATUS  pmpStatus;
    
    // Populate the initialization structure
    init.inputBuffer = PMP_INPUT_BUFFER_TTL;
    init.polarity.addressLatchPolarity = PMP_POLARITY_ACTIVE_HIGH;
    init.polarity.rwStrobePolarity = PMP_POLARITY_ACTIVE_LOW;
    init.polarity.writeEnableStrobePolarity = PMP_POLARITY_ACTIVE_LOW;
    init.polarity.chipselect1Polarity = PMP_POLARITY_ACTIVE_HIGH;
    init.polarity.chipselect2Polarity = PMP_POLARITY_ACTIVE_LOW;
    init.ports.addressPortsMask = PMP_PMA0_PORT | PMP_PMA1_PORT | PMP_PMA2_TO_PMA13_PORTS | PMP_PMA14_PORT;
    init.ports.readWriteStrobe = PORT_ENABLE;
    init.ports.writeEnableStrobe = PORT_ENABLE;
    init.moduleInit.value = SYS_MODULE_POWER_RUN_FULL;
    init.pmpID            = PMP_ID_0;
    init.stopInIdle       = false;
    init.muxMode          = PMP_MUX_NONE;
    
    DRV_PMP_Reinitialize(pmpDriverObject, (SYS_MODULE_INIT*)&init);
    
    pmpStatus = DRV_PMP_Status(pmpDriverObject);
    if (SYS_STATUS_BUSY == pmpStatus)
    {
        // Check again later to ensure the driver is ready
    }
    else if (SYS_STATUS_ERROR >= pmpStatus)
    {
        // Handle error
    }
    </code>
	
  Remarks:
    This function can be called multiple times to reinitialize the module.
    
    This operation can be used to refresh any supported hardware registers
    as specified by the initialization data or to change the power state of
    the module.
    
    This function will NEVER block for hardware access. If the operation
    requires time to allow the hardware to re-initialize, it will be
    reported by the DRV_PMP_Status operation. The system must use
    DRV_PMP_Status to find out when the driver is in the ready state.
    
    Build configuration options may be used to statically override options
    in the "init" structure and will take precedence over initialization
    data passed using this function.                                                                       
  **********************************************************************************************************/

void DRV_PMP_Reinitialize ( const SYS_MODULE_OBJ pmpDriverObject,
                            const SYS_MODULE_INIT * const init );

							
// *****************************************************************************
/* Function:
    void DRV_PMP_Deinitialize ( SYS_MODULE_OBJ pmpDriverObject )

  Summary:
    Deinitializes the specified instance of the PMP driver module.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function deinitializes the specified instance of the PMP driver module, 
    disabling its operation (and any hardware). All internal data is invalidated.

  Precondition:
    The DRV_PMP_Initialize function must have been called before calling this
    routine and a valid SYS_MODULE_OBJ must have been returned.

  Parameters:
    pmpDriverObject - Driver object handle, returned from the DRV_PMP_Initialize
                      function

  Returns:
    None.

  Example:
    <code>
    SYS_MODULE_OBJ      pmpDriverObject;     //  Returned from DRV_PMP_Initialize
    SYS_STATUS          status;

    DRV_PMP_Deinitialize(pmpDriverObject);

    status = DRV_PMP_Status(pmpDriverObject);
    if (SYS_MODULE_DEINITIALIZED == status)
    {
        // Check again later if you need to know
        // when the driver is deinitialized.
    }
    </code>

  Remarks:
    Once the Initialize operation has been called, the Deinitialize operation
    must be called before the Initialize operation can be called again.

    This function will NEVER block waiting for hardware. If the operation
    requires time to allow the hardware to complete, this will be reported by
    the DRV_PMP_Status operation.  The system has to use DRV_PMP_Status to find
    out when the module is in the ready state.
*/
							
void DRV_PMP_Deinitialize ( const SYS_MODULE_OBJ pmpDriverObject );


// *****************************************************************************
/* Function:
    SYS_STATUS DRV_PMP_Status ( SYS_MODULE_OBJ pmpDriverObject )

  Summary:
    Provides the current status of the PMP driver module.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function provides the current status of the PMP driver module.

  Precondition:
    The DRV_PMP_Initialize function must have been called before calling this
    function.

  Parameters:
    pmpDriverObject - Driver object handle, returned from the 
                      DRV_PMP_Initialize routine

  Returns:
    SYS_STATUS_READY          - Indicates that the driver is busy with a
                                previous system level operation and cannot start
                                another

                                Note: Any value greater than SYS_STATUS_READY is
                                also a normal running state in which the driver
                                is ready to accept new operations.

    SYS_STATUS_BUSY           - Indicates that the driver is busy with a
                                previous system level operation and cannot start
                                another

    SYS_STATUS_ERROR          - Indicates that the driver is in an error state

                                Note: Any value less than SYS_STATUS_ERROR is
                                also an error state.

    SYS_MODULE_DEINITIALIZED  - Indicates that the driver has been
                                deinitialized

                                Note: This value is less than SYS_STATUS_ERROR.

  Example:
    <code>
    SYS_MODULE_OBJ      pmpDriverObject;     // Returned from DRV_PMP_Initialize
    SYS_STATUS          status;

    status = DRV_PMP_Status(pmpDriverObject);
    else if (SYS_STATUS_ERROR >= status)
    {
        // Handle error
    }
    </code>

  Remarks:
    This operation can be used to determine when any of the driver's module
    level operations has completed.

    If the status operation returns SYS_STATUS_BUSY, a previous operation
    has not yet completed.  Once the status operation returns SYS_STATUS_READY,
    any previous operations have completed.

    The value of SYS_STATUS_ERROR is negative (-1). Any value less than that is
    also an error state.

    This function will NEVER block waiting for hardware.

    If the Status operation returns an error value, the error may be cleared by
    calling the reinitialize operation.  If that fails, the deinitialize
    operation will need to be called, followed by the initialize operation to
    return to normal operations.
*/

SYS_STATUS DRV_PMP_Status ( const SYS_MODULE_OBJ pmpDriverObject );

/*******************************************************************************
  Function:
       void DRV_PMP_Tasks ( SYS_MODULE_OBJ pmpDriverObject );
    
  Summary:
    Maintains the driver's state machine and implements its ISR.
	<p><b>Implementation:</b> Dynamic</p>
	
  Description:
    This function is used to maintain the queue and execute the tasks
    stored in the queue. It resides in the ISR of the PMP for
    interrupt-driven implementations.
	
  Precondition:
    The DRV_PMP_Initialize function must have been called for the specified
    PMP driver instance.
	
  Parameters:
    pmpDriverObject -  Object handle for the specified driver instance
                       (returned from DRV_PMP_Initialize)
					   
  Returns:
    None.
	
  Example:
    <code>
    SYS_MODULE_OBJ      pmpDriverObject;     // Returned from DRV_PMP_Initialize
    
    while (true)
    {
        DRV_PMP_Tasks (pmpDriverObject);
    
        // Do other tasks
    }
    </code>
	
  Remarks:
    This function is normally not called directly by an application. It is
    called by the system's Tasks routine (SYS_Tasks) or by the appropriate
    raw ISR.
    
    This function may execute in an ISR context and will never block or
    access any resources that may cause it to block.                            
  *******************************************************************************/

void DRV_PMP_Tasks( SYS_MODULE_OBJ pmpDriverObject );

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Client Level
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    DRV_HANDLE DRV_PMP_Open ( const SYS_MODULE_INDEX drvIndex,
                              const DRV_IO_INTENT    intent )

  Summary:
    Opens the specified PMP driver instance and returns a handle to it.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function opens the specified PMP driver instance and provides a
    handle that must be provided to all other client-level operations to
    identify the caller and the instance of the driver.

  Precondition:
    The DRV_PMP_Initialize function must have been called before calling this
    function.

  Parameters:
    drvIndex    - Identifier for the object instance to be opened

    intent      - Zero or more of the values from the enumeration
                  DRV_IO_INTENT ORed together to indicate the intended use
                  of the driver

  Returns:
    If successful, the function returns a valid open-instance handle (a number
    identifying both the caller and the module instance).

    If an error occurs, the return value is DRV_HANDLE_INVALID.

  Example:
    <code>
    DRV_HANDLE  hClient;

    hClient = DRV_PMP_Open(DRV_PMP_INDEX_0, DRV_IO_INTENT_EXCLUSIVE);
    if (DRV_HANDLE_INVALID == hClient)
    {
        // Unable to open the driver
    }
    </code>

  Remarks:
    The handle returned is valid until the DRV_PMP_Close routine is called.

    This function will NEVER block waiting for hardware.

    If the DRV_IO_INTENT_BLOCKING is requested and the driver was built
    appropriately to support blocking behavior, other client-level
    operations may block waiting on hardware until they are complete.

    If DRV_IO_INTENT_NON_BLOCKING is requested the driver client can call the
    DRV_PMP_ClientStatus operation to find out when the module is in the ready
    state.

    If the requested intent flags are not supported, the routine will return
    DRV_HANDLE_INVALID.
*/

DRV_HANDLE DRV_PMP_Open ( const SYS_MODULE_INDEX index,
                          const DRV_IO_INTENT intent );

// *****************************************************************************
/* Function:
    void DRV_PMP_Close ( DRV_HANDLE hClient )

  Summary:
    Closes an opened instance of the PMP driver.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function closes an opened instance of the PMP driver, invalidating the
    handle.

  Precondition:
    The DRV_PMP_Initialize routine must have been called for the specified
    PMP driver instance.

    DRV_PMP_Open must have been called to obtain a valid opened device handle.

  Parameters:
    hClient       - A valid open instance handle, returned from the driver's
                   open routine

  Returns:
    None

  Example:
    <code>
    DRV_HANDLE hClient;  // Returned from DRV_PMP_Open

    DRV_PMP_Close(hClient);
    </code>

  Remarks:
    After calling this function, the handle passed in "handle" must not be used
    with any of the remaining driver routines.  A new handle must be obtained by
    calling DRV_PMP_Open before the caller may use the driver again.

    If DRV_IO_INTENT_BLOCKING was requested and the driver was built
    appropriately to support blocking behavior call may block until the
    operation is complete.

    If DRV_IO_INTENT_NON_BLOCKING request the driver client can call the
    DRV_PMP_Status operation to find out when the module is in
    the ready state (the handle is no longer valid).

    Note: Usually there is no need for the driver client to verify that the Close
    operation has completed.
*/
						  
void DRV_PMP_Close ( const DRV_HANDLE hClient );


/****************************************************************************
  Function:
       DRV_PMP_CLIENT_STATUS DRV_PMP_ClientStatus ( DRV_HANDLE hClient )
    
  Summary:
    Gets the current client-specific status of the PMP driver.
	<p><b>Implementation:</b> Dynamic</p>
	
  Description:
    This function gets the client-specific status of the PMP driver
    associated with the specified handle.
	
  Precondition:
    The DRV_PMP_Initialize routine must have been called.
    
    DRV_PMP_Open must have been called to obtain a valid opened device
    handle.
	
  Parameters:
    hClient -  A valid open-instance handle, returned from the driver's open
               routine
			   
  Returns:
    A DRV_PMP_CLIENT_STATUS value describing the current status of the
    driver.
	
  Example:
    <code>
    DRV_HANDLE hClient;  // Returned from DRV_PMP_Open
    DRV_PMP_CLIENT_STATUS pmpClientStatus;
    
    pmpClientStatus = DRV_PMP_ClientStatus(hClient);
    if(DRV_PMP_CLIENT_STATUS_ERROR >= pmpClientStatus)
    {
        // Handle the error
    }
    </code>
	
  Remarks:
    This function will not block for hardware access and will immediately
    return the current status.                                              
  ****************************************************************************/

DRV_PMP_CLIENT_STATUS DRV_PMP_ClientStatus ( DRV_HANDLE hClient );

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Client & Module Level
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
/* Function:
    void DRV_PMP_ModeConfig ( DRV_HANDLE hClient,
                                 DRV_PMP_MODE_CONFIG config )

  Summary:
    Configures the PMP modes.
	<p><b>Implementation:</b> Static/Dynamic</p>

  Description:
    This function configures the modes for client in which it wants to operate. 
    Different master-slave modes, 8/16 data bits selection, address 
    increment/decrement, interrupt mode, wait states, etc., can be configured 
    through this function.
	
  Precondition:
    Function DRV_PMP_Initialize must have been called. 
    DRV_PMP_Open must have been called to obtain a valid opened device handle.

  Parameters:
    hClient    	- Client handle obtained from DRV_PMP_Open API

    config      - Structure which will have all the required PMP modes configuration

  Returns:
    None.

  Example:
    <code>
    DRV_HANDLE  hClient;
	DRV_PMP_MODE_CONFIG config;
	
	config.chipSelect = PMCS1_AND_PMCS2_AS_CHIP_SELECT;
    config.endianMode = LITTLE_ENDIAN;
    config.incrementMode = PMP_ADDRESS_AUTO_INCREMENT;
    config.intMode =  PMP_INTERRUPT_NONE;
    config.pmpMode = PMP_MASTER_READ_WRITE_STROBES_INDEPENDENT;
    config.portSize =  PMP_DATA_SIZE_8_BITS;
    config.waitStates.dataHoldWait = PMP_DATA_HOLD_2;
    config.waitStates.dataWait = PMP_DATA_WAIT_THREE;
    config.waitStates.strobeWait = PMP_STROBE_WAIT_5;

	DRV_PMP_ModeConfig ( hClient, config );
    </code>

  Remarks:
    This function will NEVER block waiting for hardware. If this API is called 
    more than once for a particular client handle, previous config setting of 
    that client will be overwritten.
  
*/

void DRV_PMP_ModeConfig ( DRV_HANDLE hClient,
                                 DRV_PMP_MODE_CONFIG config );
						  
						  
/******************************************************************************
  Function:
      uint32_t DRV_PMP_Read ( DRV_HANDLE hClient,
                   uint32_t address,
                   unsigned char* buffer,
                   uint32_t nBytes)
    
  Summary:
    Read the data from external device.
	<p><b>Implementation:</b> Static/Dynamic</p>
	
  Description:
    This function reads the given number of data bytes from the given
    address of the external device to the MCU buffer through the selected
    PMP instance. This function should be used for all the master and slave
    modes. Proper configuration should be done using DRV_PMP_ModeConfig
    before calling this function.
	
  Precondition:
    The DRV_PMP_Initialize routine must have been called. DRV_PMP_Open must
    have been called to obtain a valid opened device handle.
    DRV_PMP_ModeConfig must have been called to configure the desired mode
	
  Parameters:
    hClient -  A valid open-instance handle, returned from the driver's
               open routine
    address -  Starting address of the slave device from where data has to
               be read. It does not have any significance for legacy slave
               mode and buffer mode. In PMP enhanced slave mode i.e.
               addressable buffer slave mode, this parameter should be the
               buffer number to be used.
    buffer -   Pointer to the buffer into which the data read through the
               PMP instance will be placed. Even if only one word has to be
               transferred, pointer should be used.
    nBytes -   Number of bytes that need to be read through the PMP instance
	
  Returns:
    Returns the position number of the queue, where the data element was
    stored. Returns '0' when there is no place in the queue to store the
    data.
	
  Example:
    <code>
    DRV_HANDLE hClient;  // Returned from DRV_PMP_Open
    uint32_t deviceAddress;
    uint32_t nBytes;
    unsigned char myBuffer[nBytes];
    uint32_t transferID;
    
    transferID = DRV_PMP_Read ( hClient, deviceAddress, &myBuffer, nBytes);
    </code>
                                                                               
  ******************************************************************************/

   PMP_QUEUE_ELEMENT_OBJECT* DRV_PMP_Read ( DRV_HANDLE hClient,
                        uint32_t address,
                        uint16_t* buffer,
                        uint32_t nBytes);

						 
/**************************************************************************************************
  Function:
      uint32_t   DRV_PMP_Write ( DRV_HANDLE hClient,
                               uint32_t address,
                               unsigned char* buffer,
                               uint32_t nBytes,
                               uint32_t repeatCount)
    
  Summary:
    Transfers the data from the MCU to the external device.
	<p><b>Implementation:</b> Static/Dynamic</p>
	
  Description:
    This function transfer the given number of data bytes from the MCU
    buffer location to the defined address of the external device through
    the selected PMP instance. It repeats the operation n (=repeatCount)
    number of times as well. This function should be used for all the
    master and slave modes. Proper configuration should be done using
    DRV_PMP_ModeConfig before calling this function.
	
  Precondition:
  
    The DRV_PMP_Initialize routine must have been called. DRV_PMP_Open must
    have been called to obtain a valid opened device handle.
    DRV_PMP_ModeConfig must have been called to configure the desired mode.
	
  Parameters:
    hClient -      A valid open-instance handle, returned from the driver's
                   open routine
    address -      Starting address of the slave device where data has to be
                   written. It does not have any significance for legacy
                   slave mode and buffer mode. In PMP enhanced slave mode
                   (i.e., addressable buffer slave mode), this parameter
                   should be the buffer number to be used.
    buffer -       Pointer to MCU Buffer from which the data will be written
                   through the PMP instance. even if only one word has to be
                   transferred, pointer should be used.
    nBytes -       Total number of bytes that need to be written through the
                   PMP instance
    repeatCount -  Number of times the data set (nBytes of data) to be
                   repeatedly written. This value should be 0 if user does
                   not want any repetition. If repeatCount is greater than
                   0, then after writing every nBytes of data, the buffer
                   starts pointing to its first element. Ideally, PMP
                   Address should be in auto increment/decrement mode for
                   repeatCount greater than 0.
				   
  Returns:
    Returns a 32-bit ID with which status of the transfer can be checked
    later. Returns '0' when there is no place in the queue to store the
    data.
	
  Example:
    <code>
    DRV_HANDLE hClient;  // Returned from DRV_PMP_Open
    uint32_t deviceAddress;
    uint32_t nBytes;
    unsigned char myBuffer[nBytes];
    uint32_t repeatCount;
    uint32_t transferID;
    
    transferID = DRV_PMP_MasterWrite ( hClient, deviceAddress, &myBuffer, nBytes, repeatCount);
    </code>
                                                                                                   
  **************************************************************************************************/				   
PMP_QUEUE_ELEMENT_OBJECT*       DRV_PMP_Write ( DRV_HANDLE* hClient,
                            bool address,
                            uint32_t *buffer,
                            uint32_t nBytes,
                            uint32_t repeatCount);


// *****************************************************************************
/* Function:
    DRV_PMP_TRANSFER_STATUS DRV_PMP_TransferStatus( DRV_HANDLE hClient )

  Summary:
    Returns the transfer status.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function returns the status of a particular transfer whose ID has been
    specified as input.

  Parameters:
    drvIndex       - Identifier for the object instance to be opened
    seqID          - A valid ID returned from read/write transfer functions

  Returns:
    A DRV_PMP_TRANSFER_STATUS value describing the current status of the
    transfer.
    
  Example:
    <code>
    uint32_8 seqID;
	DRV_PMP_TRANSFER_STATUS transferStatus;
	
    transferStatus = DRV_PMP_TransferStatus( DRV_PMP_INDEX_0, seqID);
    </code>
*/

DRV_PMP_TRANSFER_STATUS DRV_PMP_TransferStatus( PMP_QUEUE_ELEMENT_OBJECT* queueObject);


// *****************************************************************************
/* Function:
    void DRV_PMP_TimingSet(
	                        PMP_DATA_WAIT_STATES dataWait,
							PMP_STROBE_WAIT_STATES strobeWait,
                            PMP_DATA_HOLD_STATES dataHold
							)

  Summary:
    Sets PMP timing parameters.
	<p><b>Implementation:</b> Static</p>

  Description:
    This function sets the PMP timing parameters. 
	
  Precondition:
    The DRV_PMP_Initialize function must have been called.

  Parameters:
    dataWait    - Data setup to read/write strobe wait states
	strobeWait  - Read/write strobe wait states
	dataHold    - Data hold time after read/write strobe wait states

  Returns:
    None.

  Example:
    <code>
    DRV_PMP0_TimingSet(PMP_DATA_WAIT_THREE,PMP_STROBE_WAIT_6,PMP_DATA_HOLD_4);
    </code>

  Remarks:
    None.
*/

void DRV_PMP_TimingSet(PMP_DATA_WAIT_STATES dataWait, PMP_STROBE_WAIT_STATES strobeWait,
                       PMP_DATA_HOLD_STATES dataHold);

void _DRV_PMP_HardwareConfig (DRV_HANDLE);

#define DRV_PMP_HardwareConfig(handle) _DRV_PMP_HardwareConfig(handle)

#endif // #ifndef _DRV_PMP_H

/*******************************************************************************
 End of File
*/