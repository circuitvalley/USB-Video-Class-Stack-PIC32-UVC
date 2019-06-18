/*******************************************************************************
  I2S Driver Local Data Structures

  Company:
    Microchip Technology Inc.

  File Name:
    drv_i2s_local.h

  Summary:
    I2S driver local declarations and definitions

  Description:
    This file contains the I2S driver's local declarations and definitions.
*******************************************************************************/

// DOM-IGNORE-BEGIN
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

#ifndef _DRV_I2S_LOCAL_H
#define _DRV_I2S_LOCAL_H


// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "system_config.h"
#include "system/debug/sys_debug.h"
#include "osal/osal.h"
#include "driver/i2s/drv_i2s.h"

#ifndef DRV_I2S_INTERRUPT_MODE
	#define DRV_I2S_INTERRUPT_MODE false
#endif
#include "driver/i2s/src/drv_i2s_variant_mapping.h"

// *****************************************************************************
// *****************************************************************************
// Section: Version Numbers
// *****************************************************************************
// *****************************************************************************
/* Versioning of the driver */

// *****************************************************************************
/* I2S Driver Version Macros

  Summary:
    I2S driver version.

  Description:
    These constants provide I2S driver version information. The driver
    version is:
    DRV_I2S_VERSION_MAJOR.DRV_I2S_VERSION_MINOR.DRV_I2S_VERSION_PATCH.
    It is represented in DRV_I2S_VERSION as:
    MAJOR *10000 + MINOR * 100 + PATCH, so as to allow comparisons.
    It is also represented in string format in DRV_I2S_VERSION_STR.
    DRV_I2S_VERSION_TYPE provides the type of the release when the
	release is alpha or beta. The interfaces DRV_I2S_VersionGet
	and DRV_I2S_VersionStrGet provide interfaces to the access the
	version and the version string.

  Remarks:
    Modify the return value of DRV_I2S_VersionStrGet and the
    DRV_I2S_VERSION_MAJOR, DRV_I2S_VERSION_MINOR,
    DRV_I2S_VERSION_PATCH, and DRV_I2S_VERSION_TYPE.
*/

#define _DRV_I2S_VERSION_MAJOR         0
#define _DRV_I2S_VERSION_MINOR         1
#define _DRV_I2S_VERSION_PATCH         0
#define _DRV_USB_VERSION_TYPE          Alpha
#define _DRV_USB_VERSION_STR           "0.1.0 Alpha"


// *****************************************************************************
/* I2S Buffer object Index

  Summary:
    I2S Buffer object Index

  Description:
    This constant indicates the I2S Buffer object Index.

  Remarks:
    None.
*/
#define DRV_I2S_BUFFER_OBJECT_INDEX_INVALID /*DOM-IGNORE-BEGIN*/((uint32_t)(-1))/*DOM-IGNORE-END*/

// *****************************************************************************
// *****************************************************************************
// Section: Data Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* SPI Driver task states

  Summary
    Lists the different states that SPI task routine can have.

  Description
    This enumeration lists the different states that SPI task routine can have.

  Remarks:
    None.
*/

typedef enum
{
    /* Process queue */
    DRV_I2S_TASK_PROCESS_QUEUE,

    /* SPI task handle read only buffer request */
    DRV_I2S_TASK_PROCESS_READ_ONLY,

    /* SPI task handle write only buffer request */
    DRV_I2S_TASK_PROCESS_WRITE_ONLY,

    /* SPI task handle read and write buffers request */
    DRV_I2S_TASK_PROCESS_WRITE_READ

} DRV_I2S_TASK;

/* I2S Buffer Type Selection

  Summary:
    Identifies the buffer types of the I2S module.

  Description:
    This enumeration identifies the buffer types ie FIFO or non FIFO mode
    of the I2S module.

    In Enhanced Buffer mode, two 128-bit FIFO buffers are used for the transmit
    buffer and the receive buffer. The FIFO depth depends on the data width
    chosen.

  Remarks:
    None.
*/
typedef enum
{
    /* I2S Standard Buffer Type */
    DRV_I2S_BUFFER_TYPE_STANDARD,

    /* I2S Enhanced Buffer Type */
    DRV_I2S_BUFFER_TYPE_ENHANCED

} DRV_I2S_BUFFER_TYPE;


/**********************************************
 * Driver Client Obj
 **********************************************/
typedef struct _DRV_I2S_CLIENT_OBJ_STRUCT
{
    /* PLIB I2S Module ID */
    SPI_MODULE_ID spiID;

    /* Indicates that this object is in use */
    bool inUse;

    /* Indicate whether the client is open in
     * read,write or read/write mode */
    DRV_IO_INTENT ioIntent;

    /* Inidcates the error information for
       the last I2S operation (Read/Write) */
    DRV_I2S_ERROR errorInfo;

    /* Call back function for this client */
    DRV_I2S_BUFFER_EVENT_HANDLER  pEventCallBack;

    /* Client data(Event Context) that will be
	 * returned at callback */
    uintptr_t hClientArg;

    /* pointer to the driver that own this object */
    void* hDriver;

} DRV_I2S_CLIENT_OBJ;


/***************************************************
 * This object is used by the driver as buffer place
 * holder along with queueing feature.
 ***************************************************/
typedef struct _DRV_I2S_BUFFER_OBJECT
{
    /* Indicates this object is in use */
    bool inUse;

    /* index handle to the buffer object */
    uint32_t indexHandle;

    /* tx Data buffer pointer */
    uint8_t *txbuffer;

    /* rx Data buffer pointer */
    uint8_t *rxbuffer;

    /* size in bytes */
    size_t size;

    /* Pending bytes in the object */
    size_t nPendingBytes;

    /* Pointer to the client object */
    DRV_I2S_CLIENT_OBJ	*clientObject;

    /* This points to the next object in the queue */
    struct _DRV_I2S_BUFFER_OBJECT * next;

} DRV_I2S_BUFFER_OBJECT;

/***************************************************
 * This is a data type for the buffer object
   index which will be combined with the unique index id
   to produce a unique buffer handle.
 ***************************************************/
typedef uint32_t DRV_I2S_BUFFER_OBJECT_INDEX;



/***********************************************
 * Driver object structure. One object per
 * hardware instance
 **********************************************/

typedef struct _DRV_I2S_OBJ_STRUCT
{
    /* The peripheral Id associated with the object */
    SPI_MODULE_ID spiID;

    /* Status of this driver instance */
    SYS_STATUS status;

    /* Indicates this object is in use */
    bool inUse;

    /* Flag to indicate that the hardware instance is used
     *  in exclusive access mode */
    bool isExclusive;

    /* Number of clients possible with the hardware instance */
    uint8_t numClients;

    /* I2S Initial Baud Rate Value */
    uint32_t baudRate;

    /* I2S Audio communication width */
    SPI_AUDIO_COMMUNICATION_WIDTH audioCommWidth;

    /* I2S Buffer Type */
    DRV_I2S_BUFFER_TYPE bufferType;

   /* Interrupt Source for Transmit Interrupt*/
    INT_SOURCE txInterruptSource;

    /* Interrupt Source for Receive Interrupt.*/
    INT_SOURCE rxInterruptSource;

    /* Ignore an Receive overflow condition. */
    bool ignoreRxOverflow;

    /* Ignore an Transmit underrun condition. */
    bool ignoreTxUnderrun;

    /* Interrupt Source for Error Interrupt.*/
    INT_SOURCE errorInterruptSource;

    /* Keeps track if the driver is in interrupt
     * context */
    bool isInInterruptContext;

    /* Hardware instance mutex */
    OSAL_MUTEX_DECLARE(mutexDriverInstance);

    /* Create a semaphore for read write function*/
    OSAL_SEM_DECLARE(semBufferQueueEmpty);

    /* This is the transmit buffer queue size. It
     * Indicates the number of available empty slots */
    uint32_t queueSizeTransmit;

    /* This is the receive buffer queue size.  It
     * Indicates the number of available empty slots */
    uint32_t queueSizeReceive;

   /* This is the transmit buffer current queue size. It
     * Indicates the number of occupied slots */
    uint32_t queueCurrentTransmitSize;

    /* This is the receive buffer current queue size.  It
     * Indicates the number of occupied slots  */
    uint32_t queueCurrentReceiveSize;

    /* This is the buffer queue object pointer */
    DRV_I2S_BUFFER_OBJECT *queueHead;

    /* I2S hardware object task in process */
    DRV_I2S_TASK task;

    /* Flag to inhibit further transmission
    unless, a data is received */
    uint32_t txInhibit;

    /* Flag to inhibit further transmission
    unless, a data is received */
    uint32_t rxInhibit;

} DRV_I2S_OBJ;


// *****************************************************************************
/* I2S Driver Global Instances Object

  Summary:
    Object used to keep track of data that is common to all instances of the
    I2S driver.

  Description:
    This object is used to keep track of any data that is common to all
    instances of the I2S driver.

  Remarks:
    None.
*/

typedef struct
{
    /* Set to true if all members of this structure
       have been initialized once */
    bool membersAreInitialized;

    /* Mutex to protect client object pool */
    OSAL_MUTEX_DECLARE(mutexClientObjects);

} DRV_I2S_COMMON_DATA_OBJ;


/**************************************
 * Local functions.
 *************************************/
 /*
  Function:
    static void _DRV_I2S_SetupHardware (DRV_I2S_OBJ *dObj, DRV_I2S_INIT * i2sInit )

  Summary:
    Initializes the hardware registers.

  Description:
    Take the initialization data from the application (through DRV_I2S_Initialize
    function) and initialize the hardware registers.

  Remarks:
    None
*/
static void   _DRV_I2S_HardwareSetup(DRV_I2S_OBJ *dObj, DRV_I2S_INIT *i2sInit);


/*
  Function:
    static DRV_I2S_BUFFER_OBJECT_INDEX _DRV_I2S_QueueObjectIndexGet(void)

  Summary:
    Gets the index of buffer queue object from the available pool.

  Description:
    Returns a buffer object index from the available pool.

  Remarks:
    None
*/
static DRV_I2S_BUFFER_OBJECT_INDEX _DRV_I2S_QueueObjectIndexGet(void);


#endif // _DRV_I2S_LOCAL_H
