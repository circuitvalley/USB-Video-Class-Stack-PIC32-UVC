/*******************************************************************************
  I2S Driver Interface

  Company:
    Microchip Technology Inc.

  File Name:
    drv_i2s.h

  Summary:
    I2S Driver Interface header file

  Description:
    The I2S device driver provides a simple interface to manage the I2S module
    on Microchip microcontrollers.  This file provides the interface definition
    for the I2S driver.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
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

#ifndef _DRV_I2S_H
#define _DRV_I2S_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************
/* Note:  A file that maps the interface definitions above to appropriate static
          implementations (depending on build mode) is included at the end of
          this file.
*/
#include "system/dma/sys_dma.h"
#include "system/int/sys_int.h"
#include "driver/driver_common.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END  

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Driver I2S Module Index

  Summary:
    I2S driver index definitions

  Description:
    These constants provide I2S driver index definition.

  Remarks:
    These constants should be used in place of hard-coded numeric literals.
    These values should be passed into the DRV_I2S_Initialize and DRV_I2S_Open
    routines to identify the driver instance in use.
*/

#define      DRV_I2S_INDEX_0      0
#define      DRV_I2S_INDEX_1      1
#define      DRV_I2S_INDEX_2      2
#define      DRV_I2S_INDEX_3      3
#define      DRV_I2S_INDEX_4      4
#define      DRV_I2S_INDEX_5      5

// *****************************************************************************
/* I2S Driver Module Count

  Summary:
    Number of valid I2S driver indices

  Description:
    This constant identifies the maximum number of I2S Driver instances that
    should be defined by the application. Defining more instances than this
    constant will waste RAM memory space.

    This constant can also be used by the application to identify the number of
    I2S instances on this microcontroller.

  Remarks:
    This value is part-specific.
*/

#define DRV_I2S_COUNT /*DOM-IGNORE-BEGIN*/ SPI_NUMBER_OF_MODULES/*DOM-IGNORE-END*/

// *****************************************************************************
/* I2S Driver Write Error

  Summary:
    I2S Driver Write Error.

  Description:
    This constant is returned by DRV_I2S_Write() function when an error occurs.

  Remarks:
    None.
*/

#define DRV_I2S_WRITE_ERROR ((size_t)(-1))

// *****************************************************************************
/* I2S Driver Read Error

  Summary:
    I2S Driver Read Error.

  Description:
    This constant is returned by DRV_I2S_Read function when an error occurs.

  Remarks:
    None.
*/

#define DRV_I2S_READ_ERROR ((size_t)(-1))

// *****************************************************************************
/* I2S Driver Buffer Handle

  Summary:
    Handle identifying a read or write buffer passed to the driver.

  Description:
    A buffer handle value is returned by a call to the DRV_I2S_BufferAddRead,
    DRV_I2S_BufferAddWrite, and DRV_I2S_BufferAddWriteRead functions. This
    handle is associated with the buffer passed into the function and it allows
    the application to track the completion of the data from (or into) that
    buffer.  The buffer handle value returned from the "buffer add" function is
    returned back to the client by the "event handler callback" function
    registered with the driver.

    The buffer handle assigned to a client request expires when the client has
    been notified of the completion of the buffer transfer (after event handler
    function that notifies the client returns) or after the buffer has been
    retired by the driver if no event handler callback was set.

  Remarks:
    None
*/

typedef uintptr_t DRV_I2S_BUFFER_HANDLE;

// *****************************************************************************
/* I2S Driver Invalid Buffer Handle

  Summary:
    Definition of an invalid buffer handle.

  Description:
    This is the definition of an invalid buffer handle. An invalid buffer handle
    is returned by DRV_I2S_BufferAddRead, DRV_I2S_BufferAddWrite and
    DRV_I2S_BufferAddWriteRead functions if the buffer add request was not
    successful.

  Remarks:
    None
*/

#define DRV_I2S_BUFFER_HANDLE_INVALID ((DRV_I2S_BUFFER_HANDLE)(-1))

// *****************************************************************************
/* I2S Clock Mode Selection

  Summary:
    Identifies the various clock modes of the I2S module.

  Description:
    This enumeration identifies the supported clock modes of the I2S module.

  Remarks:
    None.
*/

typedef enum
{
    /* I2S Clock Mode 0 - Idle State Low & Sampling on Rising Edge */
    DRV_I2S_CLOCK_MODE_IDLE_LOW_EDGE_RISE
        /*DOM-IGNORE-BEGIN*/  = 0 /*DOM-IGNORE-END*/,

    /* I2S Clock Mode 1 - Idle State Low & Sampling on Falling Edge */
    DRV_I2S_CLOCK_MODE_IDLE_LOW_EDGE_FALL
        /*DOM-IGNORE-BEGIN*/  = 1 /*DOM-IGNORE-END*/,

    /* I2S Clock Mode 2 - Idle State High & Sampling on Falling Edge */
    DRV_I2S_CLOCK_MODE_IDLE_HIGH_EDGE_FALL
        /*DOM-IGNORE-BEGIN*/  = 2 /*DOM-IGNORE-END*/,

    /* I2S Clock Mode 3 - Idle State High & Sampling on Rising Edge */
    DRV_I2S_CLOCK_MODE_IDLE_HIGH_EDGE_RISE
        /*DOM-IGNORE-BEGIN*/  = 3 /*DOM-IGNORE-END*/

} DRV_I2S_CLOCK_MODE;

// *****************************************************************************
/* I2S Usage Modes Enumeration

  Summary:
    Identifies the  usage modes of the I2S module.

  Description:
    This enumeration identifies the whether the I2S module will be used as a
    master or slave.

  Remarks:
    None.
*/

typedef enum
{
    /* I2S Mode Slave */
    DRV_I2S_MODE_SLAVE,

    /* I2S Mode Master */
    DRV_I2S_MODE_MASTER

} DRV_I2S_MODE;

// *****************************************************************************
/* I2S Audio Protocol Mode

  Summary:
    Identifies the Audio Protocol Mode of the I2S module.

  Description:
    This enumeration identifies Audio Protocol Mode of the I2S module.

  Remarks:
    None.
*/

typedef enum
{
    /* I2S Audio Protocol */
    DRV_I2S_AUDIO_I2S,

    /* Left Justified Audio Protocol */
    DRV_I2S_AUDIO_LFET_JUSTIFIED,

    /* Right Justified Audio Protocol */
    DRV_I2S_AUDIO_RIGHT_JUSTIFIED,

    /* PCM/DSP Audio Protocol */
    DRV_I2S_AUDIO_PCM_DSP

} DRV_I2S_AUDIO_PROTOCOL_MODE;

// *****************************************************************************
/* I2S Driver Events

  Summary
    Identifies the possible events that can result from a buffer add request.

  Description
    This enumeration identifies the possible events that can result from a
    buffer add request caused by the client calling either the
    DRV_I2S_BufferAddRead, DRV_I2S_BufferAddWrite or DRV_I2S_BufferAddWriteRead
    functions.

  Remarks:
    One of these values is passed in the "event" parameter of the event handling
    callback function that the client registered with the driver by calling the
    DRV_I2S_BufferEventHandlerSet function when a buffer transfer request is
    completed.
*/

typedef enum
{
    /* Data was transferred successfully. */
    DRV_I2S_BUFFER_EVENT_COMPLETE,

    /* Error while processing the request */
    DRV_I2S_BUFFER_EVENT_ERROR,

    /* Data transfer aborted (Applicable in DMA mode) */
    DRV_I2S_BUFFER_EVENT_ABORT

} DRV_I2S_BUFFER_EVENT;

// *****************************************************************************
/* I2S Driver Error

  Summary
    Defines the possible errors that can occur during driver operation.

  Description
    This data type defines the possible errors that can occur when occur during
    USART driver operation. These values are returned by DRV_I2S_ErrorGet
    function.

  Remarks:
    None.
*/

typedef enum
{
    /* Data was transferred successfully. */
    DRV_I2S_ERROR_NONE /*DOM-IGNORE-BEGIN*/ = (1 << 0)/* DOM-IGNORE-END*/,

    /* Receive overflow error. */
    DRV_I2S_ERROR_RECEIVE_OVERFLOW /*DOM-IGNORE-BEGIN*/ = (1 << 1)/* DOM-IGNORE-END*/,

    /* Transmit underrun error. */
    DRV_I2S_ERROR_TRANSMIT_UNDERUN /*DOM-IGNORE-BEGIN*/ = (1 << 2)/* DOM-IGNORE-END*/,

    /* Framing error. */
    DRV_I2S_ERROR_FRAMING /*DOM-IGNORE-BEGIN*/ = (1 << 3)/* DOM-IGNORE-END*/,

   /* Channel address error (Applicable in DMA mode) */
    DRV_I2S_ERROR_ADDRESS /*DOM-IGNORE-BEGIN*/ = (1 << 4) /* DOM-IGNORE-END*/

} DRV_I2S_ERROR;

// *****************************************************************************
/* I2S Driver Buffer Event Handler Function

  Summary:
    Pointer to a I2S Driver Buffer Event handler function

    Description
    This data type defines the required function signature for the I2S driver
    buffer event handling callback function. A client must register a pointer to
    a buffer event handling function whose function signature (parameter and
    return value types) match the types specified by this function pointer in
    order to receive buffer related event calls back from the driver.

    The parameters and return values are described here and a partial example
    implementation is provided.

  Parameters:
    event           - Identifies the type of event

    bufferHandle    - Handle identifying the buffer to which the event relates

    context         - Value identifying the context of the application that registered
                      the event handling function.

  Returns:
    None.

  Example:
    <code>
    void APP_MyBufferEventHandler
    ( 
        DRV_I2S_BUFFER_EVENT event,
        DRV_I2S_BUFFER_HANDLE bufferHandle,
        uintptr_t context 
    )
    {
        MY_APP_DATA_STRUCT pAppData = (MY_APP_DATA_STRUCT) context;

        switch(event)
        {
            case DRV_I2S_BUFFER_EVENT_COMPLETE:

                // Handle the completed buffer.
                break;

            case DRV_I2S_BUFFER_EVENT_ERROR:
            default:

                // Handle error.
                break;
        }
    }
    </code>

   Remarks:

    If the event is DRV_I2S_BUFFER_EVENT_COMPLETE, this means that the data was
    transferred successfully.

    If the event is DRV_I2S_BUFFER_EVENT_ERROR, this means that the data was not
    transferred successfully. The bufferHandle parameter contains the buffer
    handle of the buffer that failed.  The DRV_I2S_ErrorGet function can be
    called to know the error. The DRV_I2S_BufferProcessedSizeGet function can be
    called to find out how many bytes were processed.

    The bufferHandle parameter contains the buffer handle of the buffer that
    associated with the event.

    The context parameter contains a handle to the client context,
    provided at the time the event handling function was  registered using the
    DRV_I2S_BufferEventHandlerSet function.  This context handle value is
    passed back to the client as the "context" parameter.  It can be any value
    necessary to identify the client context or instance (such as a pointer to
    the client's data) instance of the client that made the buffer add request.

    The buffer handle in bufferHandle expires after this event handler exits. In
    that the buffer object that was allocated is deallocated by the driver after
    the event handler exits.

    The event handler function executes in the driver peripheral's interrupt
    context when the driver is configured for interrupt mode operation. It is
    recommended of the application to not perform process intensive or blocking
    operations with in this function.

    The DRV_I2S_BufferAddRead, DRV_I2S_BufferAddWrite and
    DRV_I2S_BufferAddWriteRead functions can be called in the event handler to
    add a buffer to the driver queue. These functions can only be called to add
    buffers to the driver whose event handler is running. For example, buffers
    cannot be added I2S2 driver in I2S1 driver event handler.
*/

typedef void (*DRV_I2S_BUFFER_EVENT_HANDLER) 
(
    DRV_I2S_BUFFER_EVENT event,
    DRV_I2S_BUFFER_HANDLE bufferHandle, 
    uintptr_t contextHandle
);

// *****************************************************************************
/* I2S Driver Audio Data 16

  Summary:
    Defines the left and right channel data for 16-bit audio data

  Description:
    Defines the left and right channel data for 16-bit audio data

  Remarks:
    None.
*/

typedef struct 
{
    /* Left channel data */
    int16_t leftData;

    /* Right channel data */
    int16_t rightData;

} DRV_I2S_DATA16;

// *****************************************************************************
/* I2S Driver Audio Data 24

  Summary:
    Defines the left and right channel data for 24-bit audio data

  Description:
    Defines the left and right channel data for 24-bit audio data

  Remarks:
    None.
*/

typedef struct 
{
    /* Left channel data */
    int32_t leftData 		:24;

    /* Left channel data pad */
    int32_t leftDataPad 	:8;

    /* Right channel data */
    int32_t rightData 		:24;

    /* Right channel data pad */
    int32_t rightDataPad 	:8;

} DRV_I2S_DATA24;

// *****************************************************************************
/* I2S Driver Audio Data 32

  Summary:
    Defines the left and right channel data for 32-bit audio data

  Description:
    Defines the left and right channel data for 32-bit audio data

  Remarks:
    None.
*/

typedef struct 
{
    /* Left channel data */
    int32_t leftData;

    /* Right channel data */
    int32_t rightDataPad;

} DRV_I2S_DATA32;

// *****************************************************************************
/* I2S Driver Interface

  Summary:
    This structure defines a structure of I2S Driver function pointers.

  Description:
    This structure defines a structure of I2S Driver function pointers. A driver
    of any peripheral that supports the I2S protocol can export such a
    structure. The top level I2S Driver abstraction layer will then use this
    structure to map a I2S Driver call to underlying peripheral driver.

  Remarks:
    None.
*/

typedef struct
{
    /* Pointer to the driver Initialization function */
    SYS_MODULE_OBJ (*initialize)
    (
        const SYS_MODULE_INDEX drvIndex, 
        const SYS_MODULE_INIT * const init
    );

    /* Pointer to the driver Deinitialization function */
    void (*deinitialize)(SYS_MODULE_OBJ);

    /* Pointer to the driver Status function */
    SYS_STATUS (*status)( SYS_MODULE_OBJ object);

    /* Pointer to the Tasks function */
    void (*tasks)(SYS_MODULE_OBJ object);

    /* Pointer to the Error Tasks function */
    void (*tasksError)( SYS_MODULE_OBJ object );

    /* Pointer to the Open function */
    DRV_HANDLE (*open)
    ( 
        const SYS_MODULE_INDEX iDriver, 
        const DRV_IO_INTENT ioIntent
    );

    /* Pointer to the Close function */
    void (*close)( const DRV_HANDLE handle);

    /* Pointer to the Buffer Add Write function */
    void (*bufferAddWrite)
    (
        const DRV_HANDLE handle,
        DRV_I2S_BUFFER_HANDLE *bufferHandle,
        void *buffer, size_t size
    );

    /* Pointer to the Buffer Add Read function */
    void (*bufferAddRead)
    (
        const DRV_HANDLE handle,
        DRV_I2S_BUFFER_HANDLE *bufferHandle,
        void *buffer, size_t size
    );

    /* Pointer to the buffer Add Read Write function */ 
    void (*bufferAddWriteRead)
    (
        const DRV_HANDLE handle,
        DRV_I2S_BUFFER_HANDLE	*bufferHandle,
        void *transmitBuffer, void *receiveBuffer,
        size_t size
    );

    /* Pointer to the driver Read function */
    size_t (*read)
    (
        const DRV_HANDLE handle, 
        uint8_t *buffer,
        const size_t numBytes
    );

    /* Pointer to the driver Write function */
    size_t (*write)
    (
        const DRV_HANDLE handle, 
        uint8_t *buffer,
        const size_t numBytes
    );

    /* Pointer to the driver Buffer Event Handler Set function */
    void (*eventHandlerSet)
    (
        DRV_HANDLE handle,
        const DRV_I2S_BUFFER_EVENT_HANDLER eventHandler,
        const uintptr_t contextHandle
    );

    /* Pointer to the driver Buffer Processed Size Get function */
    size_t (*bufferProcessedSizeGet)(DRV_HANDLE handle);

    /* Pointer to the driver Buffer Combined Queue Size Get Function */
    size_t (*bufferCombinedQueueSizeGet)(DRV_HANDLE handle);
    
    /* Pointer to the driver Buffer Queue Flush Function */
    void (*bufferQueueFlush)(DRV_HANDLE handle);
   
    /* Pointer to the driver Error Get function */
    DRV_I2S_ERROR (*errorGet)(DRV_HANDLE handle);

    /* Pointer to the driver Baud Set function */
    void (*baudSet)(DRV_HANDLE handle, uint32_t peripheralClock, uint32_t baud);

    /* Pointer to the driver Transmit Error Ignore function */
    void (*transmitErrorIgnore)(DRV_HANDLE handle, bool errorIgnore);

    /* Pointer to the driver Receive Error Ignore function */
    void (*receiveErrorIgnore)(DRV_HANDLE handle, bool errorEnable);

} DRV_I2S_INTERFACE;

// *****************************************************************************
// *****************************************************************************
// Section: I2S Driver Module Interface Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    SYS_MODULE_OBJ DRV_I2S_Initialize 
    ( 
        const SYS_MODULE_INDEX drvIndex,
        const SYS_MODULE_INIT *const init 
    );

  Summary:
    Initializes hardware and data for the instance of the I2S module.
    <p><b>Implementation:</b> Dynamic</p>

  Description:
    This routine initializes the I2S driver instance for the specified driver
    index, making it ready for clients to open and use it. The initialization
    data is specified by the init parameter. The initialization may fail if the
    number of driver objects allocated are insufficient or if the specified
    driver instance is already initialized. The driver instance index is
    independent of the I2S module ID. For example, driver instance 0 can be
    assigned to I2S2.  If the driver is built statically, then some of the
    initialization parameters are overridden by configuration macros. Refer to
    the description of the DRV_I2S_INIT data structure for more details on which
    members on this data structure are overridden.

  Precondition:
    If DMA mode of operation is intended, SYS_DMA_Initialize should have been
    called before calling this function.

  Parameters:
    drvIndex        - Identifier for the driver instance to be initialized
    init            - Pointer to the data structure containing any data
                      necessary to initialize the hardware. This pointer may
                      be null if no data is required and default
                      initialization is to be used.

  Returns:
    If successful, returns a valid handle to a driver instance object.
    Otherwise, it returns SYS_MODULE_OBJ_INVALID.

  Example:
    <code>
    DRV_I2S_INIT              	init;
    SYS_MODULE_OBJ              objectHandle;

    init.moduleInit.value           = SYS_MODULE_POWER_RUN_FULL;
    init.spiID                      = SPI_ID_1;
    init.usageMode                  = DRV_I2S_MODE_MASTER;
    init.baudClock                  = SPI_BAUD_RATE_MCLK_CLOCK;
    init.baud                       = 48000;
    init.clockMode                  = DRV_I2S_CLOCK_MODE_IDLE_HIGH_EDGE_FALL;
    init.audioCommWidth             = SPI_AUDIO_COMMUNICATION_24DATA_32FIFO_32CHANNEL;
    init.audioTransmitMode          = SPI_AUDIO_TRANSMIT_STEREO;
    init.inputSamplePhase           = SPI_INPUT_SAMPLING_PHASE_IN_MIDDLE;
    init.protocolMode               = DRV_I2S_AUDIO_I2S;
    init.txInterruptSource          = INT_SOURCE_SPI_1_TRANSMIT;
    init.rxInterruptSource          = INT_SOURCE_SPI_1_RECEIVE;
    init.errorInterruptSource       = INT_SOURCE_SPI_1_ERROR;
    init.queueSizeTransmit          = 3;
    init.queueSizeReceive           = 2;
    init.dmaChannelTransmit         = DMA_CHANNEL_NONE;
    init.dmaChannelReceive          = DMA_CHANNEL_NONE;

    objectHandle = DRV_I2S_Initialize(DRV_I2S_INDEX_1, (SYS_MODULE_INIT*)init);
    if (SYS_MODULE_OBJ_INVALID == objectHandle)
    {
        // Handle error
    }
    </code>
    
  Remarks:
    This routine must be called before any other I2S routine is called.

    This routine should only be called once during system initialization unless
    DRV_I2S_Deinitialize is called to deinitialize the driver instance. This
    routine will NEVER block for hardware access.

    To Enable the DMA mode of operation the init parameters 'dmaChannelTransmit'
    /'dmaChannelReceive' must be set to valid DMA channel.  When DMA mode of
    operation is enabled, the normal mode(Usual TX and RX) operation is
    inhibited.  When 'dmaChannelTransmit'/'dmaChannelReceive' are set to valid
    channel numbers the related DMA interrupt source parameters
    'dmaInterruptTransmitSource'/ 'dmaInterruptReceiveSource' must be set with
    appropriate DMA channel interrupt source.
*/
 
SYS_MODULE_OBJ  DRV_I2S_Initialize
( 
    const SYS_MODULE_INDEX drvIndex,
    const SYS_MODULE_INIT *const init
);

// *****************************************************************************
/* Function:
    void DRV_I2S_Deinitialize( SYS_MODULE_OBJ object )

  Summary:
    Deinitializes the specified instance of the I2S driver module.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    Deinitializes the specified instance of the I2S driver module, disabling
    its operation (and any hardware).  Invalidates all the internal data.

  Precondition:
    Function DRV_I2S_Initialize should have been called before calling this
    function.

  Parameters:
    object          - Driver object handle, returned from the
                      DRV_I2S_Initialize routine

  Returns:
    None.

  Example:
    <code>
    SYS_MODULE_OBJ      object;     //  Returned from DRV_I2S_Initialize
    SYS_STATUS          status;


    DRV_I2S_Deinitialize(object);

    status = DRV_I2S_Status(object);
    if (SYS_MODULE_DEINITIALIZED != status)
    {
        // Check again later if you need to know
        // when the driver is deinitialized.
    }
    </code>

  Remarks:
    Once the Initialize operation has been called, the Deinitialize operation
    must be called before the Initialize operation can be called again. This
    routine will NEVER block waiting for hardware.
*/

void DRV_I2S_Deinitialize( SYS_MODULE_OBJ object);

// *****************************************************************************
/* Function:
    SYS_STATUS DRV_I2S_Status( SYS_MODULE_OBJ object )

  Summary:
    Gets the current status of the I2S driver module.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This routine provides the current status of the I2S driver module.

  Precondition:
    Function DRV_I2S_Initialize should have been called before calling this
    function.

  Parameters:
    object          - Driver object handle, returned from the
                      DRV_I2S_Initialize routine

  Returns:
    SYS_STATUS_DEINITIALIZED  - Indicates that the driver has been
                                deinitialized

    SYS_STATUS_READY          - Indicates that any previous module operation
                                for the specified module has completed

    SYS_STATUS_BUSY           - Indicates that a previous module operation for
                                the specified module has not yet completed

    SYS_STATUS_ERROR          - Indicates that the specified module is in an
                                error state

  Example:
    <code>
    SYS_MODULE_OBJ      object;     // Returned from DRV_I2S_Initialize
    SYS_STATUS          i2sStatus;

    i2sStatus = DRV_I2S_Status(object);
    if (SYS_STATUS_READY == i2sStatus)
    {
        // This means the driver can be opened using the
        // DRV_I2S_Open() function.
    }
    </code>

  Remarks:
    A driver can opened only when its status is SYS_STATUS_READY.
*/

SYS_STATUS DRV_I2S_Status( SYS_MODULE_OBJ object);

// *****************************************************************************
/* Function:
    void DRV_I2S_Tasks(SYS_MODULE_OBJ object )

  Summary:
    Maintains the driver's receive state machine and implements its ISR.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This routine is used to maintain the driver's internal receive state machine
    and implement its transmit and receive ISR for interrupt-driven
    implementations.  In polling mode, this function should be called from the
    SYS_Tasks function.  In interrupt mode, this function should be called from
    the interrupt service routine of the I2S that is associated with this I2S
    driver hardware instance.
    
    In DMA mode of operation, this function should be called from the interrupt
    service routine of the channel associated with the transmission/reception
    of the I2s driver hardware instance.

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S driver instance.

  Parameters:
    object      - Object handle for the specified driver instance (returned from
                  DRV_I2S_Initialize)

  Returns:
    None.

  Example:
    <code>
    SYS_MODULE_OBJ      object;     // Returned from DRV_I2S_Initialize

    while (true)
    {
        DRV_I2S_Tasks (object);

        // Do other tasks
    }
    </code>

  Remarks:
    This routine is normally not called directly by an application.  It is
    called by the system's Tasks routine (SYS_Tasks) or by the appropriate raw
    ISR.

    This routine may execute in an ISR context and will never block or access any
    resources that may cause it to block.
*/

void  DRV_I2S_Tasks(SYS_MODULE_OBJ object);

// *****************************************************************************
/* Function:
    void DRV_I2S_TasksError (SYS_MODULE_OBJ object )

  Summary:
    Maintains the driver's error state machine and implements its ISR.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This routine is used to maintain the driver's internal error state machine
    and implement its error ISR for interrupt-driven implementations.  In
    polling mode, this function should be called from the SYS_Tasks() function.
    In interrupt mode, this function should be called in the error interrupt
    service routine of the I2S that is associated with this I2S driver hardware
    instance.
    
    In DMA mode of operation, this function should be called from the interrupt
    service routine of the channel associated with the transmission/reception of
    the I2s driver hardware instance.

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S driver instance.

  Parameters:
    object      - Object handle for the specified driver instance (returned from
                  DRV_I2S_Initialize)

  Returns:
    None.

  Example:
    <code>
    SYS_MODULE_OBJ      object;     // Returned from DRV_I2S_Initialize

    while (true)
    {
        DRV_I2S_TasksError (object);

        // Do other tasks
    }
    </code>

  Remarks:
    This routine is normally not called directly by an application.  It is
    called by the system's Tasks routine (SYS_Tasks) or by the appropriate raw
    ISR.

    This routine may execute in an ISR context and will never block or access any
    resources that may cause it to block.
*/

void DRV_I2S_TasksError ( SYS_MODULE_OBJ object );

// *****************************************************************************
// *****************************************************************************
// Section: I2S Driver Client Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    DRV_HANDLE DRV_I2S_Open
    ( 
        const SYS_MODULE_INDEX drvIndex,
        const DRV_IO_INTENT    ioIntent 
    )

  Summary:
    Opens the specified I2S driver instance and returns a handle to it.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This routine opens the specified I2S driver instance and provides a handle
    that must be provided to all other client-level operations to identify the
    caller and the instance of the driver. The ioIntent parameter defines how
    the client interacts with this driver instance.

    The DRV_IO_INTENT_BLOCKING and DRV_IO_INTENT_NONBLOCKING ioIntent options
    additionally affect the behavior of the DRV_I2S_Read() and DRV_I2S_Write()
    functions. If the ioIntent is DRV_IO_INTENT_NONBLOCKING, then these function
    will not block even if the required amount of data could not be processed.
    If the ioIntent is DRV_IO_INTENT_BLOCKING, these functions will block until
    the required amount of data is processed.

    If ioIntent is DRV_IO_INTENT_READ, the client will only be read from the
    driver. If ioIntent is DRV_IO_INTENT_WRITE, the client will only be able to
    write to the driver. If the ioIntent in DRV_IO_INTENT_READWRITE, the client
    will be able to do both, read and write.

    Specifying a DRV_IO_INTENT_EXCLUSIVE will cause the driver to provide
    exclusive access to this client. The driver cannot be opened by any other
    client.

  Precondition:
    Function DRV_I2S_Initialize must have been called before calling this
    function.

  Parameters:
    drvIndex    - Identifier for the object instance to be opened

    ioIntent    - Zero or more of the values from the enumeration
                  DRV_IO_INTENT "ORed" together to indicate the intended use
                  of the driver. See function description for details.

  Returns:
    If successful, the routine returns a valid open-instance handle (a number
    identifying both the caller and the module instance).

    If an error occurs, the return value is DRV_HANDLE_INVALID. Error can occur
    - if the number of client objects allocated via DRV_I2S_CLIENTS_NUMBER is
    insufficient.  
    - if the client is trying to open the driver but driver has been opened
    exclusively by another client.  
    - if the driver hardware instance being opened is not initialized or is
    invalid.

  Example:
    <code>
    DRV_HANDLE handle;

    handle = DRV_I2S_Open(DRV_I2S_INDEX_0, DRV_IO_INTENT_EXCLUSIVE);
    if (DRV_HANDLE_INVALID == handle)
    {
        // Unable to open the driver
        // May be the driver is not initialized or the initialization
        // is not complete.
    }
    </code>

  Remarks:
    The handle returned is valid until the DRV_I2S_Close routine is called.
    This routine will NEVER block waiting for hardware.If the requested intent
    flags are not supported, the routine will return DRV_HANDLE_INVALID.  This
    function is thread safe in a RTOS application. It should not be called in an
    ISR.
*/

DRV_HANDLE DRV_I2S_Open
( 
    const SYS_MODULE_INDEX iDriver, 
    const DRV_IO_INTENT ioIntent
);

// *****************************************************************************
/* Function:
    void DRV_I2S_Close( DRV_Handle handle )

  Summary:
    Closes an opened-instance of the I2S driver.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This routine closes an opened-instance of the I2S driver, invalidating the
    handle. Any buffers in the driver queue that were submitted by this client
    will be removed.  After calling this routine, the handle passed in "handle"
    must not be used with any of the remaining driver routines.  A new handle
    must be obtained by calling DRV_I2S_Open before the caller may use the
    driver again

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S driver instance.

    DRV_I2S_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

  Returns:
                 - None

  Example:
    <code>
    DRV_HANDLE handle;  // Returned from DRV_I2S_Open

    DRV_I2S_Close(handle);

    </code>

  Remarks:

    Usually there is no need for the driver client to verify that the Close
    operation has completed.  The driver will abort any ongoing operations
    when this routine is called.
*/

void DRV_I2S_Close( const DRV_HANDLE handle);

// *****************************************************************************
/* Function:
    void DRV_I2S_BufferAddWrite
    (
        const DRV_HANDLE handle,
        DRV_I2S_BUFFER_HANDLE *bufferHandle,
        void * buffer, size_t size
    );

  Summary:
    Schedule a non-blocking driver write operation.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function schedules a non-blocking write operation. The function returns
    with a valid buffer handle in the bufferHandle argument if the write request
    was scheduled successfully. The function adds the request to the hardware
    instance transmit queue and returns immediately. While the request is in the
    queue, the application buffer is owned by the driver and should not be
    modified.  The function returns DRV_I2S_BUFFER_HANDLE_INVALID:
    - if a buffer could not be allocated to the request
    - if the input buffer pointer is NULL
    - if the client opened the driver for read-only
    - if the buffer size is 0
    - if the queue is full or the queue depth is insufficient
    If the requesting client registered an event callback with the driver,
    the driver will issue a DRV_I2S_BUFFER_EVENT_COMPLETE event if the buffer
    was processed successfully of DRV_I2S_BUFFER_EVENT_ERROR event if the
    buffer was not processed successfully.

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S device instance and the DRV_I2S_Status must have returned
    SYS_STATUS_READY.

    DRV_I2S_Open must have been called to obtain a valid opened device handle.

    DRV_IO_INTENT_WRITE or DRV_IO_INTENT_READWRITE must have been specified in
    the DRV_I2S_Open call.

  Parameters:
    handle       - Handle of the I2S instance as return by the
                   DRV_I2S_Open function
    buffer       - Data to be transmitted
    size         - Buffer size in bytes
    bufferHandle - Pointer to an argument that will contain the
                   return buffer handle

  Returns:
    The bufferHandle parameter will contain the return buffer handle. This will be
    DRV_I2S_BUFFER_HANDLE_INVALID if the function was not successful.

  Example:
    <code>

    MY_APP_OBJ myAppObj;
    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_I2S_BUFFER_HANDLE bufferHandle;

    // myI2SHandle is the handle returned
    // by the DRV_I2S_Open function.

    // Client registers an event handler with driver

    DRV_I2S_BufferEventHandlerSet(myI2SHandle,
                    APP_I2SBufferEventHandler, (uintptr_t)&myAppObj);

    DRV_I2S_BufferAddWrite(myI2Shandle, &bufferHandle
                                        myBuffer, MY_BUFFER_SIZE);

    if(DRV_I2S_BUFFER_HANDLE_INVALID == bufferHandle)
    {
        // Error handling here
    }

    // Event is received when
    // the buffer is processed.

    void APP_I2SBufferEventHandler(DRV_I2S_BUFFER_EVENT event,
            DRV_I2S_BUFFER_HANDLE bufferHandle, uintptr_t contextHandle)
    {
        // contextHandle points to myAppObj.

        switch(event)
        {
            case DRV_I2S_BUFFER_EVENT_COMPLETE:

                // This means the data was transferred.
                break;

            case DRV_I2S_BUFFER_EVENT_ERROR:

                // Error handling here.
                break;

            default:
                break;
        }
    }

    </code>

  Remarks:
    This function is thread safe in a RTOS application. It can be called from
    within the I2S Driver Buffer Event Handler that is registered by this
    client. It should not be called in the event handler associated with another
    I2S driver instance. It should not otherwise be called directly in an ISR.

    This function supports DMA mode of operation.
*/

void DRV_I2S_BufferAddWrite
(
    const DRV_HANDLE handle,
    DRV_I2S_BUFFER_HANDLE *bufferHandle,
    void *buffer, size_t size
);

// *****************************************************************************
/* Function:
    void DRV_I2S_BufferAddRead
    ( 
        const DRV_HANDLE handle,
        DRV_I2S_BUFFER_HANDLE *bufferHandle,
        void * buffer, size_t size
    )

  Summary:
    Schedule a non-blocking driver read operation.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function schedules a non-blocking read operation. The function returns
    with a valid buffer handle  in the bufferHandle argument if the read request
    was scheduled successfully. The function adds the request to the hardware
    instance receive queue and returns immediately. While the request is in the
    queue, the application buffer is owned by the driver and should not be
    modified.  The function returns DRV_I2S_BUFFER_HANDLE_INVALID:
    - if a buffer could not be allocated to the request
    - if the input buffer pointer is NULL
    - if the client opened the driver for write-only
    - if the buffer size is 0
    - if the queue is full or the queue depth is insufficient
    If the requesting client registered an event callback with the driver,
    the driver will issue a DRV_I2S_BUFFER_EVENT_COMPLETE event if the buffer
    was processed successfully of DRV_I2S_BUFFER_EVENT_ERROR event if the buffer
    was not processed successfully.

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S device instance and the DRV_I2S_Status must have returned
    SYS_STATUS_READY.

    DRV_I2S_Open must have been called to obtain a valid opened device handle.

    DRV_IO_INTENT_READ  or DRV_IO_INTENT_READWRITE must have been specified in
    the DRV_I2S_Open call.

  Parameters:
    handle       - Handle of the I2S instance as returned by the
                   DRV_I2S_Open function
    buffer       - Buffer where the received data will be stored.
    size         - Buffer size in bytes
    bufferHandle - Pointer to an argument that will contain the
                   return buffer handle

  Returns:
    The bufferHandle parameter will contain the return buffer handle. This will be
    DRV_I2S_BUFFER_HANDLE_INVALID if the function was not successful.

  Example:
    <code>

    MY_APP_OBJ myAppObj;
    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_I2S_BUFFER_HANDLE bufferHandle;

    // myI2SHandle is the handle returned
    // by the DRV_I2S_Open function.

    // Client registers an event handler with driver

    DRV_I2S_BufferEventHandlerSet(myI2SHandle,
                    APP_I2SBufferEventHandler, (uintptr_t)&myAppObj);

    DRV_I2S_BufferAddRead(myI2Shandle, &bufferHandle,
                                        myBuffer, MY_BUFFER_SIZE);

    if(DRV_I2S_BUFFER_HANDLE_INVALID == bufferHandle)
    {
        // Error handling here
    }

    // Event is received when
    // the buffer is processed.

    void APP_I2SBufferEventHandler(DRV_I2S_BUFFER_EVENT event,
            DRV_I2S_BUFFER_HANDLE bufferHandle, uintptr_t contextHandle)
    {
        // contextHandle points to myAppObj.

        switch(event)
        {
            case DRV_I2S_BUFFER_EVENT_COMPLETE:

                // This means the data was transferred.
                break;

            case DRV_I2S_BUFFER_EVENT_ERROR:

                // Error handling here.
                break;

            default:
                break;
        }
    }

    </code>

  Remarks:
    This function is thread safe in a RTOS application. It can be called from
    within the I2S Driver Buffer Event Handler that is registered by this
    client. It should not be called in the event handler associated with another
    I2S driver instance. It should not otherwise be called directly in an ISR.

    This function supports DMA mode of operation.
*/

void DRV_I2S_BufferAddRead
(
    const DRV_HANDLE handle,
    DRV_I2S_BUFFER_HANDLE *bufferHandle,
    void *buffer, size_t size
);

// *****************************************************************************
/* Function:
	void DRV_I2S_BufferAddWriteRead
    (
        const DRV_HANDLE handle,
        DRV_I2S_BUFFER_HANDLE	*bufferHandle,
        void *transmitBuffer, void *receiveBuffer,
        size_t size
    )

  Summary:
    Schedule a non-blocking driver write-read operation.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function schedules a non-blocking write-read operation. The function
    returns with a valid buffer handle in the bufferHandle argument if the
    write-read request was scheduled successfully. The function adds the request
    to the hardware instance queue and returns immediately. While the request is
    in the queue, the application buffer is owned by the driver and should not
    be modified. The function returns DRV_I2S_BUFFER_HANDLE_INVALID:
    - if a buffer could not be allocated to the request
    - if the input buffer pointer is NULL
    - if the client opened the driver for read only or write only
    - if the buffer size is 0
    - if the queue is full or the queue depth is insufficient
    If the requesting client registered an event callback with the driver,
    the driver will issue a DRV_I2S_BUFFER_EVENT_COMPLETE event if the buffer
    was processed successfully of DRV_I2S_BUFFER_EVENT_ERROR event if the
    buffer was not processed successfully.

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S device instance and the DRV_I2S_Status must have returned
    SYS_STATUS_READY.

    DRV_I2S_Open must have been called to obtain a valid opened device handle.

    DRV_IO_INTENT_READWRITE must have been specified in
    the DRV_I2S_Open call.

  Parameters:
    handle         - Handle of the I2S instance as returned by the
                     DRV_I2S_Open function
    bufferHandle   - Pointer to an argument that will contain the
                     return buffer handle
    transmitBuffer - Buffer where the transmit data will be stored
    receiveBuffer  - Buffer where the received data will be stored
    size           - Buffer size in bytes

  Returns:
    The bufferHandle parameter will contain the return buffer handle. This will be
    DRV_I2S_BUFFER_HANDLE_INVALID if the function was not successful.

  Example:
    <code>

    MY_APP_OBJ myAppObj;
    uint8_t mybufferTx[MY_BUFFER_SIZE];
    uint8_t mybufferRx[MY_BUFFER_SIZE];
    DRV_I2S_BUFFER_HANDLE bufferHandle;

    // myI2SHandle is the handle returned
    // by the DRV_I2S_Open function.

    // Client registers an event handler with driver

    DRV_I2S_BufferEventHandlerSet(myI2SHandle,
                    APP_I2SBufferEventHandler, (uintptr_t)&myAppObj);

    DRV_I2S_BufferAddWriteRead(myI2Shandle, &bufferHandle,
                                        mybufferTx,mybufferRx,MY_BUFFER_SIZE);

    if(DRV_I2S_BUFFER_HANDLE_INVALID == bufferHandle)
    {
        // Error handling here
    }

    // Event is received when
    // the buffer is processed.

    void APP_I2SBufferEventHandler(DRV_I2S_BUFFER_EVENT event,
            DRV_I2S_BUFFER_HANDLE bufferHandle, uintptr_t contextHandle)
    {
        // contextHandle points to myAppObj.

        switch(event)
        {
            case DRV_I2S_BUFFER_EVENT_COMPLETE:

                // This means the data was transferred.
                break;

            case DRV_I2S_BUFFER_EVENT_ERROR:

                // Error handling here.
                break;

            default:
                break;
        }
    }

    </code>

  Remarks:
    This function is thread safe in a RTOS application. It can be called from
    within the I2S Driver Buffer Event Handler that is registered by this
    client. It should not be called in the event handler associated with another
    I2S driver instance. It should not otherwise be called directly in an ISR.

    This function is useful when there is valid read expected for every
    I2S write. The transmit and receive size must be same.
*/

void DRV_I2S_BufferAddWriteRead
(
    const DRV_HANDLE handle,
    DRV_I2S_BUFFER_HANDLE	*bufferHandle,
    void *transmitBuffer, void *receiveBuffer,
    size_t size
);

// *****************************************************************************
/* Function:
    size_t DRV_I2S_Read
    (
        const DRV_HANDLE handle, 
        uint8_t *buffer,
        const size_t numBytes
    )

  Summary:
    Reads data from the I2S.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This routine reads data from the I2S. This function is blocking if the
    driver was opened by the client for blocking operation.  This function will
    not block if the driver was opened by the client for non blocking operation.
    If the ioIntent parameter at the time of opening the driver was
    DRV_IO_INTENT_BLOCKING, this function will only return when (or will block
    until) numBytes of bytes have been received or if an error occurred.

    If the ioIntent parameter at the time of opening the driver was
    DRV_IO_INTENT_NON_BLOCKING, this function will return with the number of
    bytes that were actually read. The function will not wait until numBytes of
    bytes have been read.

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S driver instance.

    DRV_I2S_Open must have been called to obtain a valid opened device handle.

    DRV_IO_INTENT_READ or DRV_IO_INTENT_READWRITE must have been specified in
    the DRV_I2S_Open call.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

    buffer       - Buffer into which the data read from the I2S instance
                   will be placed.

    numBytes     - Total number of bytes that need to be read from the module
                   instance (must be equal to or less than the size of the
                   buffer)

  Returns:
    Number of bytes actually copied into the caller's buffer. Returns
    DRV_I2S_READ_ERROR in case of an error.

  Example:
    <code>
    DRV_HANDLE      myI2SHandle;    // Returned from DRV_I2S_Open
    char            myBuffer[MY_BUFFER_SIZE];
    unsigned int    count;
    unsigned int    total;

    total = 0;
    do
    {
        count  = DRV_I2S_Read(myI2SHandle, &myBuffer[total],
                                MY_BUFFER_SIZE - total);
        total += count;
        if(count == DRV_I2S_READ_ERROR)
        {
            // Handle error ...
        }
        else
        {
            // Do what needs to be..
        }
    } while( total < MY_BUFFER_SIZE );
    </code>

  Remarks:
    This function is thread safe in a RTOS application. It is recommended that
    this function not be called in I2S Driver Event Handler due to the potential
    blocking nature of the function. This function should not be
    called directly in an ISR. It should not be called in the event handler
    associated with another I2S driver instance.

    This function does not supports DMA mode of operation.
*/

size_t DRV_I2S_Read
(
    const DRV_HANDLE handle, 
    uint8_t *buffer,
    const size_t numBytes
);

// *****************************************************************************
/* Function:
    size_t DRV_I2S_Write
    ( 
        const DRV_HANDLE handle,  
        void * buffer,
        const size_t numbytes
    )

  Summary:
    Writes data to the I2S.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This routine writes data to the I2S. This function is blocking if the
    driver was opened by the client for blocking operation.  This function will
    not block if the driver was opened by the client for non blocking operation.
    If the ioIntent parameter at the time of opening the driver was
    DRV_IO_INTENT_BLOCKING, this function will only return when (or will block
    until) numbytes of bytes have been transmitted or if an error occurred.

    If the ioIntent parameter at the time of opening the driver was
    DRV_IO_INTENT_NON_BLOCKING, this function will return with the number of
    bytes that were actually accepted for transmission. The function will not
    wait until numBytes of bytes have been transmitted.

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S driver instance.

    DRV_I2S_Open must have been called to obtain a valid opened device handle.

    DRV_IO_INTENT_WRITE or DRV_IO_INTENT_READWRITE must have been specified in
    the DRV_I2S_Open call.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine

    buffer       - Buffer containing the data to written.

    numbytes     - size of the buffer

  Returns:
    Number of bytes actually written to the driver. Return DRV_I2S_WRITE_ERROR
    in case of an error.

  Example:
    <code>
    DRV_HANDLE myI2SHandle;    // Returned from DRV_I2S_Open
    char myBuffer[MY_BUFFER_SIZE];
    int count;
    unsigned int total;
    total = 0;
    do
    {
        count  = DRV_I2S_Write(myI2SHandle, &myBuffer[total],
                MY_BUFFER_SIZE - total);
        total += count;
        if(count == DRV_I2S_WRITE_ERROR)
        {
            // Handle error ...
        }
        else
        {
            // Do what needs to be ..
        }
    } while( total < MY_BUFFER_SIZE );
    </code>

  Remarks:
    This function is thread safe in a RTOS application. It is recommended that
    this function not be called in I2S Driver Event Handler due to the potential
    blocking nature of the function. This function should not be
    called directly in an ISR. It should not be called in the event handler
    associated with another USART driver instance.

    This function does not supports DMA mode of operation.
*/

size_t DRV_I2S_Write
(
    const DRV_HANDLE handle, 
    uint8_t *buffer,
    const size_t numBytes
);

// *****************************************************************************
/* Function:
    void DRV_I2S_BufferEventHandlerSet
    ( 
        const DRV_HANDLE handle,
        DRV_I2S_BUFFER_EVENT_HANDLER eventHandler,
	    uintptr_t contextHandle
    )

  Summary:
    This function allows a client to identify a buffer event handling function
    for the driver to call back when queued buffer transfers have finished.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function allows a client to identify a buffer event handling function
    for the driver to call back when queued buffer transfers have finished.
    When a client calls either the DRV_I2S_BufferAddRead, DRV_I2S_BufferAddWrite
    or DRV_I2S_BufferAddWriteRead  function, it is provided with a handle
    identifying  the buffer that was added to the driver's buffer queue.  The
    driver will pass this handle back to the client by calling "eventHandler"
    function when the buffer transfer has completed.

    The event handler should be set before the client performs any "buffer add"
    operations that could generate events. The event handler once set, persists
    until the client closes the driver or sets another event handler (which
    could be a "NULL" pointer to indicate no callback).

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S driver instance.

    DRV_I2S_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine
    eventHandler - Pointer to the event handler function.
    context      - The value of parameter will be passed back to the client
                   unchanged, when the eventHandler function is called.  It can
                   be used to identify any client specific data object that
                   identifies the instance of the client module (for example,
                   it may be a pointer to the client module's state structure).

  Returns:
    None.

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;

    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_I2S_BUFFER_HANDLE bufferHandle;

    // myI2SHandle is the handle returned
    // by the DRV_I2S_Open function.

    // Client registers an event handler with driver. This is done once

    DRV_I2S_BufferEventHandlerSet(myI2SHandle, APP_I2SBufferEventHandler,
                                    (uintptr_t)&myAppObj);

    DRV_I2S_BufferAddRead(myI2Shandle,&bufferHandle,
                                        myBuffer, MY_BUFFER_SIZE);

    if(DRV_I2S_BUFFER_HANDLE_INVALID == bufferHandle)
    {
        // Error handling here
    }

    // Event Processing Technique. Event is received when
    // the buffer is processed.

    void APP_I2SBufferEventHandler(DRV_I2S_BUFFER_EVENT event,
            DRV_I2S_BUFFER_HANDLE handle, uintptr_t contextHandle)
    {
        // The context handle was set to an application specific
        // object. It is now retrievable easily in the event handler.
        MY_APP_OBJ myAppObj = (MY_APP_OBJ *) contextHandle;

        switch(event)
        {
            case DRV_I2S_BUFFER_EVENT_COMPLETE:

                // This means the data was transferred.
                break;

            case DRV_I2S_BUFFER_EVENT_ERROR:

                // Error handling here.
                break;

            default:
                break;
        }
    }
    </code>

  Remarks:
    If the client does not want to be notified when the queued buffer transfer
    has completed, it does not need to register a callback.
*/

void DRV_I2S_BufferEventHandlerSet
(
    DRV_HANDLE handle,
	const DRV_I2S_BUFFER_EVENT_HANDLER eventHandler,
	const uintptr_t contextHandle
);

// *****************************************************************************
/* Function:
    size_t DRV_I2S_BufferProcessedSizeGet(DRV_HANDLE handle)

  Summary:
    This function returns number of bytes that have been processed for the
    specified buffer.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function returns number of bytes that have been processed for the
    specified buffer. The client can use this function, in a case where the
    buffer has terminated due to an error, to obtain the number of bytes that
    have been processed.
    If this function is called on a invalid buffer handle, or if the buffer
    handle has expired, the function returns 0.

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S driver instance.

    DRV_I2S_Open must have been called to obtain a valid opened device handle.

     One of DRV_I2S_BufferAddRead, DRV_I2S_BufferAddWrite or
     DRV_I2S_BufferAddWriteRead function must have been called and a valid
     buffer handle returned.

  Parameters:
    bufferhandle    - Handle of the buffer of which the processed number of bytes
                      to be obtained.

  Returns:
    Returns the number of the bytes that have been processed for this buffer.
    Returns 0 for an invalid or an expired buffer handle.

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;

    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_I2S_BUFFER_HANDLE bufferHandle;

    // myI2SHandle is the handle returned
    // by the DRV_I2S_Open function.

    // Client registers an event handler with driver. This is done once

    DRV_I2S_BufferEventHandlerSet(myI2SHandle, APP_I2SBufferEventHandle,
                                                            (uintptr_t)&myAppObj);

    DRV_I2S_BufferAddRead(myI2Shandle,&bufferHandle,
                                        myBuffer, MY_BUFFER_SIZE);

    if(DRV_I2S_BUFFER_HANDLE_INVALID == bufferHandle)
    {
        // Error handling here
    }

    // Event Processing Technique. Event is received when
    // the buffer is processed.

    void APP_I2SBufferEventHandler(DRV_I2S_BUFFER_EVENT event,
            DRV_I2S_BUFFER_HANDLE bufferHandle, uintptr_t contextHandle)
    {
        // The context handle was set to an application specific
        // object. It is now retrievable easily in the event handler.
        MY_APP_OBJ myAppObj = (MY_APP_OBJ *) contextHandle;
        size_t processedBytes;

        switch(event)
        {
            case DRV_I2S_BUFFER_EVENT_COMPLETE:

                // This means the data was transferred.
                break;

            case DRV_I2S_BUFFER_EVENT_ERROR:

                // Error handling here.
                // We can find out how many bytes were processed in this
                // buffer before the error occurred.

                processedBytes = DRV_I2S_BufferProcessedSizeGet(myI2SHandle);

                break;

            default:
                break;
        }
    }
    </code>

  Remarks:
    None.
*/

size_t DRV_I2S_BufferProcessedSizeGet(DRV_HANDLE handle);

// *****************************************************************************
/* Function:
    size_t DRV_I2S_BufferCombinedQueueSizeGet(DRV_HANDLE handle)

  Summary:
    This function returns the number of bytes queued (to be processed) in the
    buffer queue.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function returns the number of bytes queued (to be processed) in the
    buffer queue of the driver instance associated with the calling
    client. The client can use this function to know number of remaining bytes
    (from the buffers submitted by it)is in the queue to be transmitted.

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S driver instance.

    DRV_I2S_Open must have been called to obtain a valid opened device handle.

    One of DRV_I2S_BufferAddRead/DRV_I2S_BufferAddWrite
    function must have been called and buffers should have been queued for transmission.

  Parameters:
    handle    - Opened client handle associated with a driver object.

  Returns:
    Returns the number of the bytes that have been processed for this buffer.
    Returns 0 for an invalid or an expired client handle.

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;
	size_t bufferQueuedSize;
    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_I2S_BUFFER_HANDLE bufferHandle;

    // myI2SHandle is the handle returned
    // by the DRV_I2S_Open function.

    // Client registers an event handler with driver. This is done once

    DRV_I2S_BufferEventHandlerSet(myI2SHandle, APP_I2SBufferEventHandle,
                                                            (uintptr_t)&myAppObj);

    DRV_I2S_BufferAddRead(myI2Shandle,&bufferHandle,
                                        myBuffer, MY_BUFFER_SIZE);

    if(DRV_I2S_BUFFER_HANDLE_INVALID == bufferHandle)
    {
        // Error handling here
    }

    // The data is being processed after adding the buffer to the queue.
    // The user can get to know dynamically available data in the queue to be
    // transmitted by calling DRV_I2S_BufferCombinedQueueSizeGet
    bufferQueuedSize = DRV_I2S_BufferCombinedQueueSizeGet(myI2SHandle);

    </code>

  Remarks:
    None.
*/

size_t DRV_I2S_BufferCombinedQueueSizeGet(DRV_HANDLE handle);

// *****************************************************************************
/* Function:
    void DRV_I2S_BufferQueueFlush(DRV_HANDLE handle)

  Summary:
    This function flushes off the buffers associated with the client object.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function flushes off the buffers associated with the client object and
    disables the DMA channel used for transmission.

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S driver instance.

    DRV_I2S_Open must have been called to obtain a valid opened device handle.

    One of DRV_I2S_BufferAddRead/DRV_I2S_BufferAddWrite
    function must have been called and buffers should have been queued for transmission.

  Parameters:
    handle    - Opened client handle associated with a driver object.

  Returns:
    None.

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;
	size_t bufferQueuedSize;
    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_I2S_BUFFER_HANDLE bufferHandle;

    // myI2SHandle is the handle returned
    // by the DRV_I2S_Open function.

    // Client registers an event handler with driver. This is done once

    DRV_I2S_BufferEventHandlerSet(myI2SHandle, APP_I2SBufferEventHandle,
                                                            (uintptr_t)&myAppObj);

    DRV_I2S_BufferAddRead(myI2Shandle,&bufferHandle,
                                        myBuffer, MY_BUFFER_SIZE);

    if(DRV_I2S_BUFFER_HANDLE_INVALID == bufferHandle)
    {
        // Error handling here
    }

    // The data is being processed after adding the buffer to the queue.
    // The user can stop the data processing and flushoff the data
    // in the queue by calling DRV_I2S_BufferQueueFlush
    DRV_I2S_BufferQueueFlush(myI2SHandle);

    </code>

  Remarks:
    None.
*/

void DRV_I2S_BufferQueueFlush(DRV_HANDLE handle);

// *****************************************************************************
/* Function:
    DRV_I2S_ERROR DRV_I2S_ErrorGet(DRV_HANDLE handle)

  Summary:
    This function returns the error(if any) associated with the last client
    request.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function returns the error(if any) associated with the last client
    request. The DRV_I2S_Read() and DRV_I2S_Write() will update the client
    error status when these functions return DRV_I2S_READ_ERROR and
    DRV_I2S_WRITE_ERROR, respectively.  If the driver send a
    DRV_I2S_BUFFER_EVENT_ERROR to the client, the client can call this function
    to know the error cause. The error status will be updated on every operation
    and should be read frequently (ideally immediately after the driver operation
    has completed) to know the relevant error status.

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S driver instance.

    DRV_I2S_Open must have been called to obtain a valid opened device handle.

  Parameters:
    bufferhandle    - Handle of the buffer of which the processed number of bytes
                      to be obtained.

  Returns:
    A DRV_I2S_ERROR type indicating last known error status.

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;

    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_I2S_BUFFER_HANDLE bufferHandle;

    // myI2SHandle is the handle returned
    // by the DRV_I2S_Open function.

    // Client registers an event handler with driver. This is done once

    DRV_I2S_BufferEventHandlerSet( myI2SHandle, APP_I2SBufferEventHandle,
                                     (uintptr_t)&myAppObj );

    DRV_I2S_BufferAddRead( myI2Shandle,&bufferHandle,
                                            myBuffer, MY_BUFFER_SIZE );

    if(DRV_I2S_BUFFER_HANDLE_INVALID == bufferHandle)
    {
        // Error handling here
    }

    // Event Processing Technique. Event is received when
    // the buffer is processed.

    void APP_I2SBufferEventHandler( DRV_I2S_BUFFER_EVENT event,
            DRV_I2S_BUFFER_HANDLE bufferHandle, uintptr_t contextHandle )
    {
        // The context handle was set to an application specific
        // object. It is now retrievable easily in the event handler.
        MY_APP_OBJ myAppObj = (MY_APP_OBJ *) contextHandle;
        size_t processedBytes;

        switch(event)
        {
            case DRV_I2S_BUFFER_EVENT_SUCCESS:

                // This means the data was transferred.
                break;

            case DRV_I2S_BUFFER_EVENT_FAILURE:

                // Error handling here.
                // We can find out how many bytes were processed in this
                // buffer before the error occurred. We can also find
                // the error cause.

                processedBytes = DRV_I2S_BufferProcessedSizeGet(myI2SHandle);
                if(DRV_I2S_ERROR_RECEIVE_OVERRUN == DRV_I2S_ErrorGet(myI2SHandle))
                {
                    // There was an receive over flow error.
                    // Do error handling here.
                }

                break;

            default:
                break;
        }
    }
    </code>

  Remarks:
    It is the client's responsibility to make sure that the error status is
    obtained frequently. The driver will update the client error status
    regardless of whether this has been examined by the client.
*/

DRV_I2S_ERROR DRV_I2S_ErrorGet(DRV_HANDLE handle);

// *****************************************************************************
/* Function:
    void DRV_I2S_BaudSet(DRV_HANDLE handle, uint32_t spiClock, uint32_t baud)

  Summary:
    This function sets the baud.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function sets the baud rate for the I2S operation.

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S driver instance.

    DRV_I2S_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine
    i2sClock     - The Source clock frequency to the i2S module.
    baud         - The baud to be set.

  Returns:
    None

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;

    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_HANDLE handle;
	uint32_t baud;
    uint32_t clock;
 
  
    // myI2SHandle is the handle returned
    // by the DRV_I2S_Open function.

    // Client registers an event handler with driver. This is done once

    DRV_I2S_BufferEventHandlerSet(myI2SHandle, APP_I2SBufferEventHandle,
                                                            (uintptr_t)&myAppObj);

    // Sets the baud rate to a new value as below
    baud = 115200;
    clock = 40000000UL;
    DRV_I2S_BaudSet(myI2SHandle, clock, baud);

	// Further perform the operation needed
    DRV_I2S_BufferAddRead(myI2Shandle,&bufferHandle,
                                        myBuffer, MY_BUFFER_SIZE);

    if(DRV_I2S_BUFFER_HANDLE_INVALID == bufferHandle)
    {
        // Error handling here
    }

    // Event Processing Technique. Event is received when
    // the buffer is processed.

    void APP_I2SBufferEventHandler(DRV_I2S_BUFFER_EVENT event,
            DRV_I2S_BUFFER_HANDLE bufferHandle, uintptr_t contextHandle)
    {
        // The context handle was set to an application specific
        // object. It is now retrievable easily in the event handler.
        MY_APP_OBJ myAppObj = (MY_APP_OBJ *) contextHandle;
        size_t processedBytes;

        switch(event)
        {
            case DRV_I2S_BUFFER_EVENT_COMPLETE:

                // This means the data was transferred.
                break;

            case DRV_I2S_BUFFER_EVENT_ERROR:

                // Error handling here.
                // We can find out how many bytes were processed in this
                // buffer before the error occurred.

                processedBytes = DRV_I2S_BufferProcessedSizeGet(myI2SHandle);

                break;

            default:
                break;
        }
    }
    </code>

  Remarks:
    None.
*/

void DRV_I2S_BaudSet(DRV_HANDLE handle, uint32_t spiClock, uint32_t baud);

// *****************************************************************************
/* Function:
    void DRV_I2S_TransmitErrorIgnore(DRV_HANDLE handle, bool errorIgnore)

  Summary:
    This function enable/disable ignoring of the transmit underrun error.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    A Transmit underrun error is not a critical error and zeros are transmitted
    until the SPIxTXB is not empty. Ignore Transmit underrun error is needed for
    cases when software does not care or does not need to know about underrun
    conditions.

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S driver instance.

    DRV_I2S_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine
    errorIgnore  - When set to 'true' enables ignoring of transmit underrun error.
                   When set to 'false' disables ignoring of transmit underrun error.

  Returns:
    None

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;

    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_HANDLE handle;
	uint32_t baud;
 	uint32_t baud;*

    // myI2SHandle is the handle returned
    // by the DRV_I2S_Open function.

    // Client registers an event handler with driver. This is done once

    DRV_I2S_BufferEventHandlerSet(myI2SHandle, APP_I2SBufferEventHandle,
                                                            (uintptr_t)&myAppObj);

    // Enable ignoring of transmit underrun error
    DRV_I2S_TransmitErrorIgnore(myI2SHandle, true);

	// Further perform the operation needed
    DRV_I2S_BufferAddRead(myI2Shandle,&bufferHandle,
                                        myBuffer, MY_BUFFER_SIZE);

    if(DRV_I2S_BUFFER_HANDLE_INVALID == bufferHandle)
    {
        // Error handling here
    }

    // Event Processing Technique. Event is received when
    // the buffer is processed.

    void APP_I2SBufferEventHandler(DRV_I2S_BUFFER_EVENT event,
            DRV_I2S_BUFFER_HANDLE bufferHandle, uintptr_t contextHandle)
    {
        // The context handle was set to an application specific
        // object. It is now retrievable easily in the event handler.
        MY_APP_OBJ myAppObj = (MY_APP_OBJ *) contextHandle;
        size_t processedBytes;

        switch(event)
        {
            case DRV_I2S_BUFFER_EVENT_COMPLETE:

                // This means the data was transferred.
                break;

            case DRV_I2S_BUFFER_EVENT_ERROR:

                // Error handling here.
                // We can find out how many bytes were processed in this
                // buffer before the error occurred.

                processedBytes = DRV_I2S_BufferProcessedSizeGet(bufferHandle);

                break;

            default:
                break;
        }
    }
    </code>

  Remarks:
    None.
*/

void DRV_I2S_TransmitErrorIgnore(DRV_HANDLE handle, bool errorIgnore);

// *****************************************************************************
/* Function:
    void DRV_I2S_ReceiveErrorIgnore(DRV_HANDLE handle, bool errorEnable)

  Summary:
    This function enable/disable ignoring of the receive overflow error.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    A receive overflow is not a critical error; during receive overflow data in
    the FIFO is not overwritten by receive data. Ignore receive overflow is
    needed for cases when there is a general performance problem in the system
    that software must handle properly.

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S driver instance.

    DRV_I2S_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle       - A valid open-instance handle, returned from the driver's
                   open routine
    errorIgnore  - When set to 'true' enables ignoring of transmit underrun error.
                   When set to 'false' disables ignoring of transmit underrun error.

  Returns:
    None

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;

    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_HANDLE handle;
	uint32_t baud;
 	uint32_t baud;*

    // myI2SHandle is the handle returned
    // by the DRV_I2S_Open function.

    // Client registers an event handler with driver. This is done once

    DRV_I2S_BufferEventHandlerSet(myI2SHandle, APP_I2SBufferEventHandle,
                                                            (uintptr_t)&myAppObj);

    // Enable ignoring of receive overflow error
    DRV_I2S_ReceiveErrorIgnore(myI2SHandle, true);

	// Further perform the operation needed
    DRV_I2S_BufferAddRead(myI2Shandle,&bufferHandle,
                                        myBuffer, MY_BUFFER_SIZE);

    if(DRV_I2S_BUFFER_HANDLE_INVALID == bufferHandle)
    {
        // Error handling here
    }

    // Event Processing Technique. Event is received when
    // the buffer is processed.

    void APP_I2SBufferEventHandler(DRV_I2S_BUFFER_EVENT event,
            DRV_I2S_BUFFER_HANDLE bufferHandle, uintptr_t contextHandle)
    {
        // The context handle was set to an application specific
        // object. It is now retrievable easily in the event handler.
        MY_APP_OBJ myAppObj = (MY_APP_OBJ *) contextHandle;
        size_t processedBytes;

        switch(event)
        {
            case DRV_I2S_BUFFER_EVENT_COMPLETE:

                // This means the data was transferred.
                break;

            case DRV_I2S_BUFFER_EVENT_ERROR:

                // Error handling here.
                // We can find out how many bytes were processed in this
                // buffer before the error occurred.

                processedBytes = DRV_I2S_BufferProcessedSizeGet(bufferHandle);

                break;

            default:
                break;
        }
    }
    </code>

  Remarks:
    None.
*/

void DRV_I2S_ReceiveErrorIgnore(DRV_HANDLE handle, bool errorEnable);

// ****************************************************************************
// ****************************************************************************
// Section: Included Files (continued)
// ****************************************************************************
// ****************************************************************************
/*  The files included below map the interface definitions above to appropriate
    static implementations, depending on build mode.
*/

//#include "driver/i2s/drv_i2s_mapping.h"
#if defined(__PIC32C__)
#include "driver/i2s/src/drv_i2s_pic32c_local.h"
#include "drv_i2s_ssc_definitions_pic32c.h"
#include "driver/i2s/src/drv_i2s_ssc_pic32c_local.h"
#else
#include "peripheral/spi/plib_spi.h" // I2S uses SPI PLIB
#include "drv_i2s_pic32m_definitions.h"
#endif

#ifdef __cplusplus
}
#endif
    
#endif // #ifndef _DRV_I2S_H
/*******************************************************************************
 End of File
*/

