/*******************************************************************************
  I2S Driver Dynamic implementation.

  Company:
    Microchip Technology Inc.

  File Name:
    drv_i2s.c

  Summary:
    I2S Driver Dynamic Implementation.

  Description:
    This file contains the Dynamic implementation of the I2S driver in
    non DMA mode.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute Software
only when embedded on a Microchip microcontroller or digital  signal  controller
that is integrated into your product or third party  product  (pursuant  to  the
sublicense terms in the accompanying license agreement).

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
//DOM-IGNORE-END

/*************************************************************
 * Include files.
 ************************************************************/
#include "../drv_i2s_local.h"

// *****************************************************************************
/* Driver Hardware instance objects.

  Summary:
    Defines the hardware instances objects that are available on the part

  Description:
    This data type defines the hardware instance objects that are available on
    the part, so as to capture the hardware state of the instance.

  Remarks:
    Not all modes are available on all micro-controllers.
 */
DRV_I2S_OBJ gDrvI2SObj[DRV_I2S_INSTANCES_NUMBER];

// *****************************************************************************
/* Driver Client instance objects.

  Summary:
    Defines the client instances objects

  Description:
    This data type defines the client instance objects that are available on
    the part, so as to capture the client state of the instance.
    It uses the configuration of maximum number of clients which can get
    registered per hardware instance.

  Remarks:
    Not all modes are available on all micro-controllers.
 */
DRV_I2S_CLIENT_OBJ gDrvI2SClientObj[DRV_I2S_CLIENTS_NUMBER];

// *****************************************************************************
/* Driver buffer instance objects.

  Summary:
    Defines the buffer instances objects

  Description:
    This data type defines the buffer instance objects

  Remarks:
    None
 */
DRV_I2S_BUFFER_OBJECT gDrvI2SBufferQObj[DRV_I2S_QUEUE_DEPTH_COMBINED];


// *****************************************************************************
/* Driver common data object

  Summary:
    Defines the common data object

  Description:
    This object maintains data that is required by all I2S
   driver instances

  Remarks:
    None
 */
DRV_I2S_COMMON_DATA_OBJ gDrvI2SCommonDataObj;

// *****************************************************************************
/* Driver Unique buffer handle

  Summary:
    Defines the unique buffer handle

  Description:
    This data type defines Unique buffer handle.

  Remarks:
    None
 */
static uint16_t gDrvI2SUniqueBufferHandle;

// *****************************************************************************
// *****************************************************************************
// Section: I2S Driver Interface Implementations
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*   Function:
    SYS_MODULE_OBJ DRV_I2S_Initialize ( const SYS_MODULE_INDEX drvIndex,
                                        const SYS_MODULE_INIT *const init )

  Summary:
    Initializes hardware and data for the instance of the I2S module

  Description:
    This routine initializes the I2S driver instance for the specified driver
    index, making it ready for clients to open and use it. The initialization
    data is specified by the init parameter. The initialization may fail if the
    number of driver objects allocated are insufficient or if the specified
    driver instance is already initialized. The driver instance index is
    independent of the I2S module ID. For example, driver instance 0 can be
    assigned to I2S2.  If the driver is built statically, then some of the
    initialization parameters are overridden by configuration macros. Refer to
    the description of the DRV_I2S_INIT data structure for more details on
    which members on this data structure are overridden.

  Remarks:
    This routine must be called before any other I2S routine is called.

    This routine should only be called once during system initialization
    unless DRV_I2S_Deinitialize is called to de-initialize the driver
    instance. This routine will NEVER block for hardware access.

 */
SYS_MODULE_OBJ DRV_I2S_Initialize(const SYS_MODULE_INDEX drvIndex,
        const SYS_MODULE_INIT * const init)
{
    DRV_I2S_OBJ *drvObj;
    DRV_I2S_INIT *i2sInit;

    /* Validate the driver index */
    if (drvIndex > DRV_I2S_INSTANCES_NUMBER)
    {
        SYS_DEBUG(0, "Invalid driver index \r\n");
        return SYS_MODULE_OBJ_INVALID;
    }

    if (true == gDrvI2SObj[drvIndex].inUse)
    {
        /* Cannot initialize an object that is already in use. */
        SYS_DEBUG(0, "Instance already in use \r\n");
        return SYS_MODULE_OBJ_INVALID;
    }

    i2sInit = (DRV_I2S_INIT *) init;
    drvObj = (DRV_I2S_OBJ *)&gDrvI2SObj[drvIndex];

    /* Populate the driver object with the required data */
    drvObj->inUse = true;
    drvObj->status = SYS_STATUS_BUSY;
    drvObj->spiID = i2sInit->spiID;
    drvObj->txInterruptSource = i2sInit->txInterruptSource;
    drvObj->rxInterruptSource = i2sInit->rxInterruptSource;
    drvObj->errorInterruptSource = i2sInit->errorInterruptSource;

    /* Disable the I2S module */
    PLIB_SPI_Disable(i2sInit->spiID);
    /* Setup the Hardware */
    _DRV_I2S_HardwareSetup(drvObj, i2sInit);

    drvObj->isInInterruptContext = false;
    drvObj->queueSizeTransmit = i2sInit->queueSizeTransmit;
    drvObj->queueSizeReceive = i2sInit->queueSizeReceive;
    drvObj->queueCurrentTransmitSize = 0;
    drvObj->queueCurrentReceiveSize = 0;
    drvObj->queueHead = (DRV_I2S_BUFFER_OBJECT *) NULL;
    drvObj->task = DRV_I2S_TASK_PROCESS_QUEUE;
    drvObj->numClients = 0;
    drvObj->status = SYS_STATUS_READY;

    /* Clear the interrupts */
    _DRV_I2S_InterruptSourceClear(drvObj->txInterruptSource);
    _DRV_I2S_InterruptSourceClear(drvObj->rxInterruptSource);
    _DRV_I2S_InterruptSourceClear(drvObj->errorInterruptSource);

    
    /* TBD: Disabled for now. Need to enable to support error interrupts  
      Enable the interrupt source in case of interrupt mode */
    //_DRV_I2S_InterruptSourceEnable(drvObj->errorInterruptSource);

    /* Create the hardware instance mutex. */
     if(OSAL_MUTEX_Create(&(drvObj->mutexDriverInstance)) != OSAL_RESULT_TRUE)
     {
        return SYS_MODULE_OBJ_INVALID;
     }

     /* Create the semaphore */
     if(((OSAL_SEM_Create(&(drvObj->semBufferQueueEmpty), OSAL_SEM_TYPE_BINARY,1,0)) != OSAL_RESULT_TRUE))
     {
        return SYS_MODULE_OBJ_INVALID;
     }

    /* Check if the global mutexes have been created. If not
       then create these. */
     if(!gDrvI2SCommonDataObj.membersAreInitialized)
     {
         /* This means that mutexes where not created. Create them. */
         if((OSAL_MUTEX_Create(&(gDrvI2SCommonDataObj.mutexClientObjects)) != OSAL_RESULT_TRUE))
         {
            return SYS_MODULE_OBJ_INVALID;
         }
         /* Set this flag so that global mutexes get allocated only once */
         gDrvI2SCommonDataObj.membersAreInitialized = true;
     }

    /* Enable the I2S module */
    PLIB_SPI_Enable(drvObj->spiID);

    /* Return the object structure */
    return ((SYS_MODULE_OBJ) drvObj);

} /* DRV_I2S_Initialize */

// *****************************************************************************
/* Function:
    void DRV_I2S_Deinitialize( SYS_MODULE_OBJ object )

  Summary:
    Deinitializes the specified instance of the I2S driver module

  Description:
    Deinitializes the specified instance of the I2S driver module, disabling
    its operation (and any hardware).  Invalidates all the internal data.

  Remarks:
    Once the Initialize operation has been called, the De-initialize operation
    must be called before the Initialize operation can be called again. This
    routine will NEVER block waiting for hardware.
*/
void DRV_I2S_Deinitialize(SYS_MODULE_OBJ object)
{
    DRV_I2S_OBJ *drvObj;
    SPI_MODULE_ID spiID;
    DRV_I2S_BUFFER_OBJECT * iterator;

    if (object == SYS_MODULE_OBJ_INVALID || object == (SYS_MODULE_OBJ)NULL)
    {
        /* Invalid object */
        SYS_DEBUG(0, "Invalid object \r\n");
        return;
    }

    drvObj = (DRV_I2S_OBJ *) object;
    spiID = drvObj->spiID;
    if (false == drvObj->inUse)
    {
        /* Cannot deinitialize an object that is
         * not already in use. */
        SYS_DEBUG(0, "Instance not in use \r\n");
        return;
    }
    /* Disable the interrupt */
    _DRV_I2S_InterruptSourceDisable(drvObj->txInterruptSource);
    _DRV_I2S_InterruptSourceDisable(drvObj->rxInterruptSource);
    _DRV_I2S_InterruptSourceDisable(drvObj->errorInterruptSource);

    /* Turn off I2S module */
    PLIB_SPI_Disable(spiID);

	/* Deallocate all the mutexes */
     if((OSAL_MUTEX_Delete(&(drvObj->mutexDriverInstance)) != OSAL_RESULT_TRUE))
     {
        SYS_DEBUG(0, "Unable to delete client handle mutex \r\n");
        return;
     }

     if(((OSAL_SEM_Delete(&(drvObj->semBufferQueueEmpty))) == OSAL_RESULT_TRUE))
     {
        SYS_DEBUG(0, "Unable to delete buffer queue empty semaphore \r\n");
        return;
     }

    /* Remove all objects from the queue */
    iterator = drvObj->queueHead;
    while(iterator != NULL)
    {
        /* Return the buffer object to the pool */
        iterator->inUse = false;
        iterator = iterator->next;
    }
    /* Indicate that this object is not is use */
    drvObj->inUse = false;
    /* Deallocate the buffer queue Object */
    drvObj->queueHead = (DRV_I2S_BUFFER_OBJECT *) NULL;
    /* Set number of clients to zero */
    drvObj->numClients = 0;
    drvObj->status = SYS_STATUS_UNINITIALIZED;
    
    return;
} /* DRV_I2S_Deinitialize */

// *****************************************************************************
/* Function:
    SYS_STATUS DRV_I2S_Status( SYS_MODULE_OBJ object )

  Summary:
    Gets the current status of the I2S driver module.

  Description:
    This routine provides the current status of the I2S driver module.

  Remarks:
    A driver can opened only when its status is SYS_STATUS_READY.
*/
SYS_STATUS DRV_I2S_Status(SYS_MODULE_OBJ object)
{
    DRV_I2S_OBJ *drvObj;

    if (object == SYS_MODULE_OBJ_INVALID ||
        object < DRV_I2S_INSTANCES_NUMBER)
    {
        SYS_DEBUG(0, "System Module Object is invalid \r\n");
        return SYS_STATUS_ERROR;
    }
    drvObj = (DRV_I2S_OBJ *) object;

    /* Return the status of the driver object */
    return drvObj->status;
} /* DRV_I2S_Status */

// *****************************************************************************
/* Function:
    void DRV_I2S_Tasks(SYS_MODULE_OBJ object )

  Summary:
    Maintains the driver's receive state machine and implements its ISR

  Description:
    This routine is used to maintain the driver's internal receive state machine
    and implement its transmit and receive ISR for interrupt-driven implementations.
    In polling mode, this function should be called from the SYS_Tasks() function.
    In interrupt mode, this function should be called from the interrupt
    service routine of the I2S that is associated with this I2S driver
    hardware instance.
    In DMA mode of operation, this function should be called from the interrupt
    service routine of the channel associated with the transmission/reception
    of the I2s driver hardware instance.

  Remarks:
    This routine is normally not called directly by an application.  It is
    called by the system's Tasks routine (SYS_Tasks) or by the appropriate raw
    ISR.

    This routine may excute in an ISR context and will never block or access any
    resources that may cause it to block.
*/
void DRV_I2S_Tasks(SYS_MODULE_OBJ object)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_OBJ *drvObj;
    DRV_I2S_BUFFER_OBJECT *lreadQueueObj;
    DRV_I2S_BUFFER_OBJECT *lwriteQueueObj;
    DRV_I2S_BUFFER_OBJECT *lwriteReadQueueObj;
    uint8_t dummy;

    drvObj = (DRV_I2S_OBJ *)object;

    if((false == drvObj->inUse) || (drvObj->status != SYS_STATUS_READY))
    {
        /* This instance of the driver is not initialized. Don't
         * do anything */
        return;
    }

    _DRV_I2S_isInInterruptContextSet(drvObj->isInInterruptContext);
    /* Setup the state of the I2S task based on the contents at the
    head of queue and client IO intent */
    if (drvObj->task == DRV_I2S_TASK_PROCESS_QUEUE)
    {
        if ((drvObj->queueHead != (DRV_I2S_BUFFER_OBJECT*) NULL))
        {
            DRV_IO_INTENT ioInten;
            ioInten = drvObj->queueHead->clientObject->ioIntent;
            if(DRV_IO_INTENT_READWRITE == (DRV_IO_INTENT_READWRITE & ioInten))
            {
                drvObj->task = DRV_I2S_TASK_PROCESS_WRITE_READ;
            }
            else if(DRV_IO_INTENT_READ == (DRV_IO_INTENT_READ & ioInten))
            {
                drvObj->task = DRV_I2S_TASK_PROCESS_READ_ONLY;
            } else if(DRV_IO_INTENT_WRITE == (DRV_IO_INTENT_WRITE & ioInten))
            {
                drvObj->task = DRV_I2S_TASK_PROCESS_WRITE_ONLY;
            }
        }
    }

    if (DRV_I2S_TASK_PROCESS_READ_ONLY == drvObj->task)
    {
        dummy = 0xFF;
        /* FIFO is enabled */
        if (DRV_I2S_BUFFER_TYPE_ENHANCED == drvObj->bufferType)
        {
            /* Taking the reference to a Local queue object
             * so as to avoid multiple dereferencing and to speed up */
            lreadQueueObj = drvObj->queueHead;
            clientObj = lreadQueueObj->clientObject;
            while (lreadQueueObj->nPendingBytes)
            {
                if (true == PLIB_SPI_TransmitBufferIsFull(drvObj->spiID) &&
                        false == PLIB_SPI_ReceiverFIFOIsEmpty(drvObj->spiID))
                {
                    _DRV_I2S_InterruptSourceClear(drvObj->rxInterruptSource);
                    break;
                }
                if (false == PLIB_SPI_TransmitBufferIsFull(drvObj->spiID) &&
                        drvObj->rxInhibit == 0)
                {
                    PLIB_SPI_BufferWrite((drvObj->spiID), dummy);
                    drvObj->rxInhibit = 1;
                }
                if (false == PLIB_SPI_ReceiverFIFOIsEmpty(drvObj->spiID) &&
                    drvObj->rxInhibit == 1)
                {
                    drvObj->rxInhibit = 1;
                    *lreadQueueObj->rxbuffer++ = PLIB_SPI_BufferRead(drvObj->spiID);
                    if (lreadQueueObj->nPendingBytes > 1)
                    {
                        lreadQueueObj->nPendingBytes--;
                    } else
                    {
                        /* All bytes are read. */
                        lreadQueueObj->nPendingBytes--;
                        lreadQueueObj->inUse = false;
                        drvObj->task = DRV_I2S_TASK_PROCESS_QUEUE;
                        /* Disable the interrupt source */
                        _DRV_I2S_InterruptSourceClear(drvObj->rxInterruptSource);
                        /* Update the driver object's head pointer */
                        drvObj->queueHead = drvObj->queueHead->next;
                        /* Release the location of a queue size */
                        drvObj->queueSizeReceive++;
                        drvObj->queueCurrentReceiveSize--;
                        /*Callback with I2S Buffer Complete Event*/
                        clientObj->pEventCallBack(DRV_I2S_BUFFER_EVENT_COMPLETE,
                                (DRV_I2S_BUFFER_HANDLE)lreadQueueObj, clientObj->hClientArg);
                    }
                }
            }
            if(drvObj->queueHead==NULL)
            {
                /* We dont have any buffers to process. We
                * can disable the interrupt. We
                * post a semaphore to let the DRV_I2S_write and DRV_I2S_Read
                * function know that the queue is empty */
                if(_DRV_I2S_SEM_POST(&(drvObj->semBufferQueueEmpty)) != OSAL_RESULT_TRUE)
                {
                    SYS_DEBUG(0, "Unable to post buffer queue empty semaphore \r\n");
                    return;
                }
                _DRV_I2S_InterruptSourceDisable(drvObj->rxInterruptSource);
            }

        }/* FIFO is disabled */
        else
        {
            /* Taking the reference to a Local queue object
             * so as to avoid multiple dereferencing and to speed up */
            lreadQueueObj = drvObj->queueHead;
            clientObj = lreadQueueObj->clientObject;
            while (lreadQueueObj->nPendingBytes)
            {
                if (false == PLIB_SPI_TransmitBufferIsEmpty(drvObj->spiID) &&
                        false == PLIB_SPI_ReceiverBufferIsFull(drvObj->spiID))
                {
                    break;
                }

                if (true == PLIB_SPI_TransmitBufferIsEmpty(drvObj->spiID) &&
                        drvObj->rxInhibit == 0)
                {
                    PLIB_SPI_BufferWrite((drvObj->spiID), dummy);
                    drvObj->rxInhibit = 1;
                }
                if (true == PLIB_SPI_ReceiverBufferIsFull(drvObj->spiID) &&
                        drvObj->rxInhibit == 1)
                {
                    drvObj->rxInhibit = 1;
                    *lreadQueueObj->rxbuffer++ = PLIB_SPI_BufferRead(drvObj->spiID);
                    _DRV_I2S_InterruptSourceClear(drvObj->rxInterruptSource);
                    if (lreadQueueObj->nPendingBytes > 1)
                    {
                        lreadQueueObj->nPendingBytes--;
                    } else
                    {
                        /* All bytes are read. */
                        lreadQueueObj->nPendingBytes--;
                        lreadQueueObj->inUse = false;
                        drvObj->task = DRV_I2S_TASK_PROCESS_QUEUE;
                        /* Update the driver object's head pointer */
                        drvObj->queueHead = drvObj->queueHead->next;
                        /* Release the location of a queue size */
                        drvObj->queueSizeReceive++;
                        drvObj->queueCurrentReceiveSize--;
                        /*Callback with I2S Buffer Complete Event*/
                        clientObj->pEventCallBack(DRV_I2S_BUFFER_EVENT_COMPLETE,
                                (DRV_I2S_BUFFER_HANDLE)lreadQueueObj, clientObj->hClientArg);
                    }
                }
            }
            if(drvObj->queueHead==NULL)
            {
                /* We dont have any buffers to process. We
                * can disable the interrupt. We
                * post a semaphore to let the DRV_I2S_write and DRV_I2S_Read
                * function know that the queue is empty */
                if(_DRV_I2S_SEM_POST(&(drvObj->semBufferQueueEmpty)) != OSAL_RESULT_TRUE)
                {
                    SYS_DEBUG(0, "Unable to post buffer queue empty semaphore \r\n");
                    return;
                }
                _DRV_I2S_InterruptSourceDisable(drvObj->rxInterruptSource);
            }
        }
    }
    else if (DRV_I2S_TASK_PROCESS_WRITE_ONLY == drvObj->task)
    {
        /* FIFO is enabled */
        if (DRV_I2S_BUFFER_TYPE_ENHANCED == drvObj->bufferType)
        {
            /* Taking the reference to a Local queue object
             * so as to avoid multiple dereferencing and to speed up */
            lwriteQueueObj = drvObj->queueHead;
            clientObj = lwriteQueueObj->clientObject;
            while (lwriteQueueObj->nPendingBytes)
            {
                if (false == PLIB_SPI_TransmitBufferIsFull(drvObj->spiID)
                        && (drvObj->txInhibit == 0))
                {
                    PLIB_SPI_BufferWrite((drvObj->spiID), *lwriteQueueObj->txbuffer++);
                }
                if (false == PLIB_SPI_ReceiverFIFOIsEmpty(drvObj->spiID))
                {
                    dummy = PLIB_SPI_BufferRead(drvObj->spiID);
                    drvObj->txInhibit = 0;
                    if (lwriteQueueObj->nPendingBytes > 1) {
                        lwriteQueueObj->nPendingBytes--;
                    } else
                    {
                        /* All bytes are read. */
                        lwriteQueueObj->nPendingBytes--;
                        lwriteQueueObj->inUse = false;
                        drvObj->task = DRV_I2S_TASK_PROCESS_QUEUE;
                        _DRV_I2S_InterruptSourceClear(drvObj->txInterruptSource);
                        /* Update the driver object's head pointer */
                        drvObj->queueHead = drvObj->queueHead->next;
                        /* Release the location of a queue size */
                        drvObj->queueSizeTransmit++;
                        drvObj->queueCurrentTransmitSize--;
                        /*Callback with I2S Buffer Complete Event*/
                        clientObj->pEventCallBack(DRV_I2S_BUFFER_EVENT_COMPLETE,
                                (DRV_I2S_BUFFER_HANDLE)lwriteQueueObj, clientObj->hClientArg);
                    }
                }
                else
                {
                    _DRV_I2S_InterruptSourceClear(drvObj->txInterruptSource);
                    drvObj->txInhibit = 1;
                    break;
                }
            }
            if(drvObj->queueHead==NULL)
            {
                /* We dont have any buffers to process. We
                * can disable the interrupt. We
                * post a semaphore to let the DRV_I2S_write and DRV_I2S_Read
                * function know that the queue is empty */
                if(_DRV_I2S_SEM_POST(&(drvObj->semBufferQueueEmpty)) != OSAL_RESULT_TRUE)
                {
                    SYS_DEBUG(0, "Unable to post buffer queue empty semaphore \r\n");
                    return;
                }
                _DRV_I2S_InterruptSourceDisable(drvObj->txInterruptSource);
            }
        }
        else
        {
            /* Taking the reference to a Local queue object
             * so as to avoid multiple dereferencing and to speed up */
            lwriteQueueObj = drvObj->queueHead;
            clientObj = lwriteQueueObj->clientObject;
            while (lwriteQueueObj->nPendingBytes)
            {
                if ((false == PLIB_SPI_TransmitBufferIsFull(drvObj->spiID)) &&
                       (drvObj->txInhibit == 0))
                {
                    PLIB_SPI_BufferWrite((drvObj->spiID),
                            *lwriteQueueObj->txbuffer++);
                }
                if (true == PLIB_SPI_ReceiverBufferIsFull(drvObj->spiID))
                {
                    dummy = PLIB_SPI_BufferRead(drvObj->spiID);
                    drvObj->txInhibit = 0;
                    /* One byte is read */
                    _DRV_I2S_InterruptSourceClear(drvObj->txInterruptSource);
                    if (lwriteQueueObj->nPendingBytes > 1) {
                        lwriteQueueObj->nPendingBytes--;
                    } else
                    {
                        /* All bytes are read. */
                        lwriteQueueObj->nPendingBytes--;
                        lwriteQueueObj->inUse = false;
                        drvObj->task = DRV_I2S_TASK_PROCESS_QUEUE;
                        /* Update the driver object's head pointer */
                        drvObj->queueHead = drvObj->queueHead->next;
                        /* Release the location of a queue size */
                        drvObj->queueSizeTransmit++;
                        drvObj->queueCurrentTransmitSize--;
                        /*Callback with I2S Buffer Complete Event*/
                        clientObj->pEventCallBack(DRV_I2S_BUFFER_EVENT_COMPLETE,
                                (DRV_I2S_BUFFER_HANDLE)lwriteQueueObj, clientObj->hClientArg);
                    }
                }
                else
                {
                    drvObj->txInhibit = 1;
                    break;
                }
            }
            if(drvObj->queueHead==NULL)
            {
                /* We dont have any buffers to process. We
                * can disable the interrupt. We
                * post a semaphore to let the DRV_I2S_write and DRV_I2S_Read
                * function know that the queue is empty */
                if(_DRV_I2S_SEM_POST(&(drvObj->semBufferQueueEmpty)) != OSAL_RESULT_TRUE)
                {
                    SYS_DEBUG(0, "Unable to post buffer queue empty semaphore \r\n");
                    return;
                }
                _DRV_I2S_InterruptSourceDisable(drvObj->txInterruptSource);
            }
        }
    } else if (DRV_I2S_TASK_PROCESS_WRITE_READ == drvObj->task)
    {
        /* FIFO is enabled */
        if (DRV_I2S_BUFFER_TYPE_ENHANCED == drvObj->bufferType)
        {
            /* Taking the reference to a Local queue object
             * so as to avoid multiple dereferencing and to speed up */
            lwriteReadQueueObj = drvObj->queueHead;
            clientObj = lwriteReadQueueObj->clientObject;
            while (lwriteReadQueueObj->nPendingBytes)
            {
                if (false == PLIB_SPI_TransmitBufferIsFull(drvObj->spiID)
                        && (drvObj->txInhibit == 0))
                {
                    PLIB_SPI_BufferWrite((drvObj->spiID),
                            *lwriteReadQueueObj->txbuffer++);
                }
                if (false == PLIB_SPI_ReceiverFIFOIsEmpty(drvObj->spiID))
                {
                    *lwriteReadQueueObj->rxbuffer++ =
                            PLIB_SPI_BufferRead(drvObj->spiID);
                    drvObj->txInhibit = 0;
                    if (lwriteReadQueueObj->nPendingBytes > 1)
                    {
                        lwriteReadQueueObj->nPendingBytes--;
                    } else
                    {
                        /* All bytes are read. */
                        lwriteReadQueueObj->nPendingBytes--;
                        lwriteReadQueueObj->inUse = false;
                        drvObj->task = DRV_I2S_TASK_PROCESS_QUEUE;
                        _DRV_I2S_InterruptSourceClear(drvObj->txInterruptSource);
                        /* Update the driver object's head pointer */
                        drvObj->queueHead = drvObj->queueHead->next;
                        /* Release the location of a queue size */
                        drvObj->queueSizeTransmit++;
                        drvObj->queueCurrentTransmitSize--;
                        /*Callback with I2S Buffer Complete Event*/
                        clientObj->pEventCallBack(DRV_I2S_BUFFER_EVENT_COMPLETE,
                                (DRV_I2S_BUFFER_HANDLE)lwriteReadQueueObj, clientObj->hClientArg);
                    }
                }
                else
                {
                    _DRV_I2S_InterruptSourceClear(drvObj->txInterruptSource);
                    drvObj->txInhibit = 1;
                    break;
                }
            }
            if(drvObj->queueHead==NULL)
            {
                /* We dont have any buffers to process. We
                * can disable the interrupt. We
                * post a semaphore to let the DRV_I2S_write and DRV_I2S_Read
                * function know that the queue is empty */
                if(_DRV_I2S_SEM_POST(&(drvObj->semBufferQueueEmpty)) != OSAL_RESULT_TRUE)
                {
                    SYS_DEBUG(0, "Unable to post buffer queue empty semaphore \r\n");
                    return;
                }
                _DRV_I2S_InterruptSourceDisable(drvObj->txInterruptSource);
            }

        } else
        {
            /* Taking the reference to a Local queue object
             * so as to avoid multiple dereferencing and to speed up */
            lwriteReadQueueObj = drvObj->queueHead;
            clientObj = lwriteReadQueueObj->clientObject;
            while (lwriteReadQueueObj->nPendingBytes)
            {

                if ((false == PLIB_SPI_TransmitBufferIsFull(drvObj->spiID)) &&
                       (drvObj->txInhibit == 0))
                {
                    PLIB_SPI_BufferWrite((drvObj->spiID),
                            *lwriteReadQueueObj->txbuffer++);
                }
                if (true == PLIB_SPI_ReceiverBufferIsFull(drvObj->spiID))
                {
                    *lwriteReadQueueObj->rxbuffer++ = PLIB_SPI_BufferRead(drvObj->spiID);
                    drvObj->txInhibit = 0;
                    /* One byte is read */
                    if (lwriteReadQueueObj->nPendingBytes > 1)
                    {
                        lwriteReadQueueObj->nPendingBytes--;
                    } else
                    {
                        /* All bytes are read. */
                        lwriteReadQueueObj->nPendingBytes--;
                        lwriteReadQueueObj->inUse = false;
                        drvObj->task = DRV_I2S_TASK_PROCESS_QUEUE;
                        /* Disable the interrupt source */
                        _DRV_I2S_InterruptSourceClear(drvObj->txInterruptSource);
                        /* Update the driver object's head pointer */
                        drvObj->queueHead = drvObj->queueHead->next;
                        drvObj->queueSizeTransmit++;
                        drvObj->queueCurrentTransmitSize--;
                        /*Callback with I2S Buffer Complete Event*/
                        clientObj->pEventCallBack(DRV_I2S_BUFFER_EVENT_COMPLETE,
                                (DRV_I2S_BUFFER_HANDLE)lwriteReadQueueObj, clientObj->hClientArg);
                    }
                }
                else
                {
                    _DRV_I2S_InterruptSourceClear(drvObj->txInterruptSource);
                    drvObj->txInhibit = 1;
                    break;
                }
            }
            if(drvObj->queueHead==NULL)
            {
                /* We dont have any buffers to process. We
                * can disable the interrupt. We
                * post a semaphore to let the DRV_I2S_write and DRV_I2S_Read
                * function know that the queue is empty */
                if(_DRV_I2S_SEM_POST(&(drvObj->semBufferQueueEmpty)) != OSAL_RESULT_TRUE)
                {
                    SYS_DEBUG(0, "Unable to post buffer queue empty semaphore \r\n");
                    return;
                }
                _DRV_I2S_InterruptSourceDisable(drvObj->txInterruptSource);
            }
        }
    } else
    {
        /* Impossible case */
        ;
    }
    _DRV_I2S_isInInterruptContextClear(drvObj->isInInterruptContext);
    
    return;
}

// *****************************************************************************
/* Function:
    void DRV_I2S_TasksError (SYS_MODULE_OBJ object )

  Summary:
    Maintains the driver's error state machine and implements its ISR

  Description:
    This routine is used to maintain the driver's internal error state machine
    and implement its error ISR for interrupt-driven implementations.  In
    polling mode, this function should be called from the SYS_Tasks() function.
    In interrupt mode, this function should be called in the error interrupt
    service routine of the I2S that is associated with this I2S driver
    hardware instance.
    In DMA mode of operation, this function should be called from the interrupt
    service routine of the channel associated with the transmission/reception
    of the I2s driver hardware instance.

  Remarks:
    This routine is normally not called directly by an application.  It is
    called by the system's Tasks routine (SYS_Tasks) or by the appropriate raw
    ISR.

    This routine may execute in an ISR context and will never block or access any
    resources that may cause it to block.
*/
void DRV_I2S_TasksError(SYS_MODULE_OBJ object)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_OBJ *drvObj;
    DRV_I2S_BUFFER_OBJECT *lQueueObj;

    drvObj = (DRV_I2S_OBJ *)object;
    if((false == drvObj->inUse) || (drvObj->status != SYS_STATUS_READY))
    {
        /* This instance of the driver is not initialized. Don't do anything */
        return;
    }

    lQueueObj = drvObj->queueHead;
    /* An error has occurred.*/
    if (true == _DRV_I2S_InterruptSourceStatusGet(drvObj->errorInterruptSource) &&
            lQueueObj != (DRV_I2S_BUFFER_OBJECT *)NULL )
    {

        clientObj = lQueueObj->clientObject;

        /* If all (or more than 1) of the transmission errors
           (overflow, underrun and framing) has occurred We update
           the last error occurred in the client according to the
           below condition check sequence. */
#if defined (PLIB_SPI_ExistsTransmitUnderRunStatus)
        if (true == PLIB_SPI_ExistsTransmitUnderRunStatus(drvObj->spiID))
        {
            if (true == PLIB_SPI_TransmitUnderRunStatusGet(drvObj->spiID))
            {
                clientObj->errorInfo = DRV_I2S_ERROR_TRANSMIT_UNDERUN;
                PLIB_SPI_TransmitUnderRunStatusClear(drvObj->spiID);
            }
        }
#endif        
        if (true == PLIB_SPI_FrameErrorStatusGet(drvObj->spiID))
        {
            clientObj->errorInfo = DRV_I2S_ERROR_FRAMING;
            PLIB_SPI_FrameErrorStatusClear(drvObj->spiID);
        }
        if (true == PLIB_SPI_ReceiverHasOverflowed(drvObj->spiID))
        {
            clientObj->errorInfo = DRV_I2S_ERROR_RECEIVE_OVERFLOW;
            PLIB_SPI_ReceiverOverflowClear(drvObj->spiID);
            PLIB_SPI_Disable(drvObj->spiID);
            PLIB_SPI_Enable(drvObj->spiID);
        }

        lQueueObj->inUse = false;

        /* Disable the interrupt source */
        _DRV_I2S_InterruptSourceClear(drvObj->errorInterruptSource);
        _DRV_I2S_InterruptSourceDisable(drvObj->errorInterruptSource);
        /* Update the driver object's head pointer */
        if(DRV_I2S_TASK_PROCESS_WRITE_ONLY == drvObj->task ||
           DRV_I2S_TASK_PROCESS_WRITE_READ == drvObj->task)
        {
            drvObj->queueSizeTransmit++;
            drvObj->queueCurrentTransmitSize--;
        }
        else if(DRV_I2S_TASK_PROCESS_READ_ONLY == drvObj->task)
        {
            drvObj->queueSizeReceive++;
            drvObj->queueCurrentReceiveSize--;
        }
        else
        {
            /* Impossible case */
            ;
        }
        drvObj->task = DRV_I2S_TASK_PROCESS_QUEUE;
        drvObj->queueHead = drvObj->queueHead->next;
        /*Callback with I2S Buffer Error Event*/
        clientObj->pEventCallBack(DRV_I2S_BUFFER_EVENT_ERROR,
                (DRV_I2S_BUFFER_HANDLE)lQueueObj, clientObj->hClientArg);
    }
    return;
}


// *****************************************************************************
// *****************************************************************************
// Section: I2S Driver Client Routines Implementation
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    DRV_HANDLE DRV_I2S_Open( const SYS_MODULE_INDEX drvIndex,
                             const DRV_IO_INTENT    ioIntent )

  Summary:
    Opens the specified I2S driver instance and returns a handle to it

  Description:
    This routine opens the specified I2S driver instance and provides a
    handle that must be provided to all other client-level operations to
    identify the caller and the instance of the driver. The ioIntent
    parameter defines how the client interacts with this driver instance.

    The DRV_IO_INTENT_BLOCKING and DRV_IO_INTENT_NONBLOCKING ioIntent
    options additionally affect the behaviour of the DRV_I2S_Read() and
    DRV_I2S_Write() functions. If the ioIntent is DRV_IO_INTENT_NONBLOCKING,
    then these function will not block even if the required amount of
    data could not be processed. If the ioIntent is DRV_IO_INTENT_BLOCKING,
    these functions will block till the required amount of data is processed.

    If ioIntent is DRV_IO_INTENT_READ, the client will only be read from
    the driver. If ioIntent is DRV_IO_INTENT_WRITE, the client will only be
    able to write to the driver. If the ioIntent in DRV_IO_INTENT_READWRITE,
    the client will be able to do both, read and write.

    Specifying a DRV_IO_INTENT_EXCLUSIVE will cause the driver to provide
    exclusive access to this client. The driver cannot be opened by any
    other client.

   Remarks:
    The handle returned is valid until the DRV_I2S_Close routine is called.
    This routine will NEVER block waiting for hardware.If the requested intent
    flags are not supported, the routine will return DRV_HANDLE_INVALID.  This
    function is thread safe in a RTOS application. It should not be called in an
    ISR.
*/
DRV_HANDLE DRV_I2S_Open(const SYS_MODULE_INDEX iDriver,
        const DRV_IO_INTENT ioIntent)
{
    DRV_I2S_CLIENT_OBJ *hClient;
    DRV_I2S_OBJ *drvObj;
    uint32_t iClient;

    /* The iDriver value should be valid. It should be
     * less the number of driver object instances.
     */
    if (iDriver >= DRV_I2S_INSTANCES_NUMBER)
    {
        SYS_DEBUG(0, "Bad Driver Index \r\n");
        return DRV_HANDLE_INVALID;
    }
    drvObj = (DRV_I2S_OBJ *)&gDrvI2SObj[iDriver];
    if (drvObj->status != SYS_STATUS_READY)
    {
        /* The I2S module should be ready */
        SYS_DEBUG(0, "Was the driver initialized? \r\n");
        return DRV_HANDLE_INVALID;
    }

    if ((drvObj->numClients > 0) && (true == drvObj->isExclusive))
    {
        /* Driver already opened in exclusive mode. Cannot open a new client. */
        SYS_DEBUG(0, "Cannot open a new client in exclusive mode \r\n");
        return DRV_HANDLE_INVALID;
    }

    if ((drvObj->numClients > 0) &&
    	(DRV_IO_INTENT_EXCLUSIVE == (ioIntent & DRV_IO_INTENT_EXCLUSIVE)))
    {
        /*  A client Instance of driver is open.
    	Cannot open the new client in exclusive mode */
        SYS_DEBUG(0, "Cannot open a new client in exclusive mode \r\n");
                    return DRV_HANDLE_INVALID;
    }

    iClient = 0;
    hClient = (DRV_I2S_CLIENT_OBJ *)&gDrvI2SClientObj[iClient];

    /* Grab client object mutex here */
    if(OSAL_MUTEX_Lock(&(gDrvI2SCommonDataObj.mutexClientObjects), OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
    {
        /* Setup client operations */
        /* Find available slot in array of client objects */
        for (; iClient < DRV_I2S_CLIENTS_NUMBER; iClient++)
        {
            if (false == hClient->inUse)
            {

                /* Set the exlusive mode for the driver instance */
                if (DRV_IO_INTENT_EXCLUSIVE == (ioIntent & DRV_IO_INTENT_EXCLUSIVE))
                {
                    drvObj->isExclusive = true;
                }

                if (DRV_IO_INTENT_READWRITE == (ioIntent & DRV_IO_INTENT_READWRITE))
                {
                    hClient->ioIntent = DRV_IO_INTENT_READWRITE;
                }
                else if (DRV_IO_INTENT_READ == (ioIntent & DRV_IO_INTENT_READ))
                {
                    hClient->ioIntent = DRV_IO_INTENT_READ;
                }
                else if (DRV_IO_INTENT_WRITE == (ioIntent & DRV_IO_INTENT_WRITE))
                {
                    hClient->ioIntent = DRV_IO_INTENT_WRITE;
                }
                else
                {
                    /* An operation mode is needed */
                    if((OSAL_MUTEX_Unlock(&(gDrvI2SCommonDataObj.mutexClientObjects))) != OSAL_RESULT_TRUE)
                    {
                        SYS_DEBUG(0, "Unable to unlock open routine mutex \r\n");
                        return DRV_HANDLE_INVALID;
                    }
                }

                if (DRV_IO_INTENT_NONBLOCKING ==
                        (ioIntent & DRV_IO_INTENT_NONBLOCKING))
                {
                    hClient->ioIntent |= DRV_IO_INTENT_NONBLOCKING;
                } else
                {
                    hClient->ioIntent |= DRV_IO_INTENT_BLOCKING;
                }

                /* Remember which I2S driver instance owns me */
                hClient->inUse  = true;
                hClient->hDriver = drvObj;
                hClient->spiID = drvObj->spiID;
                hClient->pEventCallBack = NULL;
                drvObj->numClients++;
                /* We have found a client object
                 * Release the mutex and return with
                 * the driver handle */
                    /* An operation mode is needed */
                if((OSAL_MUTEX_Unlock(&(gDrvI2SCommonDataObj.mutexClientObjects))) != OSAL_RESULT_TRUE)
                {
                    SYS_DEBUG(0, "Unable to unlock open routine mutex \r\n");
                    return DRV_HANDLE_INVALID;
                }
                /* Return the client object */
                return (DRV_HANDLE) hClient;
            }
            hClient++;
        }
        /* Could not find a client object. Release the mutex and
         * return with an invalid handle. */
        if((OSAL_MUTEX_Unlock(&(gDrvI2SCommonDataObj.mutexClientObjects))) != OSAL_RESULT_TRUE)
        {
            SYS_DEBUG(0, "Unable to unlock open routine mutex \r\n");
        }
    }
    return DRV_HANDLE_INVALID;
} /* DRV_I2S_Open */

// *****************************************************************************
/* Function:
    void DRV_I2S_Close( DRV_Handle handle )

  Summary:
    Closes an opened-instance of the I2S driver

  Description:
    This routine closes an opened-instance of the I2S driver, invalidating the
    handle. Any buffers in the driver queue that were submitted by this client
    will be removed.  After calling this routine, the handle passed in "handle"
    must not be used with any of the remaining driver routines.  A new handle must
    be obtained by calling DRV_I2S_Open before the caller may use the driver
    again

  Remarks:
    Usually there is no need for the driver client to verify that the Close
    operation has completed.  The driver will abort any ongoing operations
    when this routine is called.
*/
void DRV_I2S_Close(const DRV_HANDLE client)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_OBJ *drvObj;
    bool txInterruptWasEnabled;
    bool rxInterruptWasEnabled;
    DRV_I2S_BUFFER_OBJECT *iterator1, *iterator2;

    if(client == DRV_HANDLE_INVALID || (DRV_HANDLE) 0 == client)
    {
        SYS_DEBUG(0, "Invalid Driver Handle \r\n");
        return;
    }

    clientObj = (DRV_I2S_CLIENT_OBJ *) client;
    if (false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid Driver Handle \r\n");
        return ;
    }

    drvObj = (DRV_I2S_OBJ *) clientObj->hDriver;
    /* Remove all buffer that this client owns
     * from the driver queue */

    if((OSAL_MUTEX_Lock(&(drvObj->mutexDriverInstance), OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE))
    {
        /* Disable the transmit interrupt */
        txInterruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->txInterruptSource);
        rxInterruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->rxInterruptSource);

        iterator1 = drvObj->queueHead;
        while(iterator1->next!=NULL)
        {
            iterator2 = iterator1->next;
            if(clientObj == (DRV_I2S_CLIENT_OBJ *)iterator1->clientObject )
            {
                /* That means this buffer object is owned
                 * by this client. This buffer object should
                 * be removed. */
                iterator1->inUse = false;
                iterator1 = iterator1->next;
                iterator2 = iterator2->next;
            }
            else if(clientObj == (DRV_I2S_CLIENT_OBJ *)iterator2->clientObject)
            {
                /* That means this buffer object is owned
                 * by this client. This buffer object should
                 * be removed. */
                iterator2->inUse = false;
                iterator1->next = iterator2->next;
                iterator2 = iterator2->next;
            }
            else
            {
                iterator1 = iterator1->next;
                iterator2 = iterator2->next;
            }
        }
        /* This condition is for the case when there is only one object in the
           queue and that object is the buffer object owned by this client (clientObj) */
        if(clientObj == (DRV_I2S_CLIENT_OBJ *)iterator1->clientObject )
        {
            /* That means this buffer object is owned
             * by this client. This buffer object should
             * be removed. */
            iterator1->inUse = false;
            iterator1 = iterator1->next;
        }

        /* After removing the closed clientobj
         * If there are no buffers in the queue.
         * Make the head pointer point to NULL */
        if(0 == drvObj->queueCurrentReceiveSize &&
           0 == drvObj->queueCurrentTransmitSize)
        {
            drvObj->queueHead = (DRV_I2S_BUFFER_OBJECT *)0;
        }
        else
        {
            /* Iterate to update the head pointer to point
             * the first valid buffer object in the queue */
            iterator1 = drvObj->queueHead;
            while(iterator1 != (DRV_I2S_BUFFER_OBJECT *)0)
            {
                if(iterator1->inUse == true)
                {
                    drvObj->queueHead = iterator1;
                    break;
                }
                iterator1 = iterator1->next;
            }
        }

        /* Done with closing client now,
         * Re-enable the interrupt if it was disabled */
        if(txInterruptWasEnabled)
        {
            _DRV_I2S_InterruptSourceEnable(drvObj->txInterruptSource);
        }
        if(rxInterruptWasEnabled)
        {
            _DRV_I2S_InterruptSourceEnable(drvObj->rxInterruptSource);
        }
        /* Release the mutex */
        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
        {
            SYS_DEBUG(0, "Unable to unlock write queue mutex in close routine \r\n");
        }
    }
    else
    {
        /* The case where the mutex lock timed out and the
         * client buffer objects could not be removed from
         * the driver queue, the close function should fail. */
        SYS_DEBUG(0, "Could not remove client buffer objects \r\n");
        return;
    }

    /* De-allocate the object */
    clientObj->inUse = false;
    /* Reduce the number of clients */
    drvObj->numClients--;
    return ;

} /* DRV_I2S_Close */

// *****************************************************************************
/*
Function:
    void DRV_I2S_BufferAddWrite( const DRV_HANDLE handle,
                                 DRV_I2S_BUFFER_HANDLE *bufferHandle,
                                 void * buffer, size_t size);

  Summary:
    Schedule a non-blocking driver write operation.

  Description:
    This function schedules a non-blocking write operation. The function returns
    with a valid buffer handle in the bufferHandle argument if the write request
    was scheduled successfully. The function adds the request to the hardware
    instance transmit queue and returns immediately. While the request is in the
    queue, the application buffer is owned by the driver and should not be
    modified.  The function returns DRV_I2S_BUFFER_HANDLE_INVALID
    - if a buffer could not be allocated to the request
    - if the input buffer pointer is NULL
    - if the client opened the driver for read only
    - if the buffer size is 0.
    - if the queue is full or the queue depth is insufficient
    If the requesting client registered an event callback with the driver,
    the driver will issue a DRV_I2S_BUFFER_EVENT_COMPLETE event if the buffer
    was processed successfully of DRV_I2S_BUFFER_EVENT_ERROR event if the
    buffer was not processed successfully.

  Remarks:
    This function is thread safe in a RTOS application. It can be called from
    within the I2S Driver Buffer Event Handler that is registered by this
    client. It should not be called in the event handler associated with another
    I2S driver instance. It should not otherwise be called directly in an ISR.

*/
void DRV_I2S_BufferAddWrite(const DRV_HANDLE handle,
        DRV_I2S_BUFFER_HANDLE *bufferHandle,
        void *buffer, size_t size)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_BUFFER_OBJECT *i2sBufObj;
    DRV_I2S_BUFFER_OBJECT_INDEX i2sBufIndex;
    DRV_I2S_OBJ *drvObj;
    bool interruptWasEnabled = false;

    /* The Client and driver objects from the handle */
    clientObj = (DRV_I2S_CLIENT_OBJ *) handle;
    drvObj = (DRV_I2S_OBJ *) clientObj->hDriver;

    /* We first check the arguments and initialize the
     * buffer handle */
    if(bufferHandle != NULL)
    {
        *bufferHandle = DRV_I2S_BUFFER_HANDLE_INVALID;
    }

    /* check if the transmit queue size is 0 */
    if (0 == drvObj->queueSizeTransmit)
    {
        SYS_DEBUG(0, "Cannot add a write operation as the queueSizeTransmit is 0 \r\n");
        return;
    }        /* Bound checking for the buffer parameters */
    else if ((NULL == buffer) || (0 == size) || (bufferHandle == NULL))
    {
        SYS_DEBUG(0, "Invalid parameters \r\n");
        return;
    }
    /* See if the handle is still valid */
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid Driver Handle \r\n");
        return;
    }
    /* If the driver was opened in read only mode */
    else if (DRV_IO_INTENT_READ == clientObj->ioIntent)
    {
        SYS_DEBUG(0, "Driver was opened in Read mode \r\n");
        return;
    }
    else
    {
        ;
    }

    /* We will allow buffers to be added in the interrupt
     * context of this I2S driver. But we must make
     * sure that if we are in interrupt, then we should
     * not modify mutexes. */
    if(!drvObj->isInInterruptContext)
    {
        /* Grab a mutex. This is okay because we are not in an
         * interrupt context */
        if(OSAL_MUTEX_Lock(&(drvObj->mutexDriverInstance), OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
        {
            /* We will disable interrupts so that the queue
             * status does not get updated asynchronously.
             * This code will always execute. */
            interruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->txInterruptSource);
        }
        else
        {
            /* The mutex acquisition timed out. Return with an
             * invalid handle. This code will not execute
             * if there is no RTOS. */
            return;
        }
    }
    i2sBufIndex = _DRV_I2S_QueueObjectIndexGet();
    if (i2sBufIndex != DRV_I2S_BUFFER_OBJECT_INDEX_INVALID)
    {
        i2sBufObj = &gDrvI2SBufferQObj[i2sBufIndex];
        i2sBufObj->indexHandle = ((++gDrvI2SUniqueBufferHandle << 0x10) | i2sBufIndex);
        *bufferHandle = (DRV_I2S_BUFFER_HANDLE) i2sBufObj->indexHandle;        
        i2sBufObj->txbuffer = (uint8_t *)buffer;
        i2sBufObj->rxbuffer = NULL;
        i2sBufObj->size = size;
        i2sBufObj->next = (DRV_I2S_BUFFER_OBJECT *) NULL;
        i2sBufObj->nPendingBytes = size;
        i2sBufObj->clientObject = clientObj;

        /* If the queue is empty */
        if (drvObj->queueHead == ((DRV_I2S_BUFFER_OBJECT *) NULL))
        {
            drvObj->queueHead = i2sBufObj;
            /* Enable the I2S transmit interrupt */
        }
        else
        {
            DRV_I2S_BUFFER_OBJECT *iterator;
            iterator = drvObj->queueHead;
            /* Insert the object at the end of the queue */
            while (iterator->next != NULL)
            {
                iterator = iterator->next;
            }
            iterator->next = i2sBufObj;
        }
        /* A location of the queue size is being used */
        drvObj->txInhibit = 0;
        drvObj->queueSizeTransmit--;
        drvObj->queueCurrentTransmitSize++;
        /* We are done. Restore the interrupt enable status
        * and return. */
        /* Enable the I2S transmit interrupt */
        _DRV_I2S_InterruptSourceEnable(drvObj->txInterruptSource);
        /* Release mutex */
        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
        {
            SYS_DEBUG(0, "Unable to DriverInstance mutex \r\n");
        }
        return;
    }
    else
    {
        /* This means we could not find a buffer. This
         * will happen if the the DRV_USART_QUEUE_DEPTH_COMBINED
         * parameter is configured to be less */
        SYS_DEBUG(0, "Insufficient Combined Queue Depth \r\n");
        /* Enable the interrupt if it was disabled */
        if(interruptWasEnabled)
        {
            _DRV_I2S_InterruptSourceEnable(drvObj->txInterruptSource);
        }
        /* Release mutex */
        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
        {
            SYS_DEBUG(0, "Unable to uDriverInstance mutex \r\n");
        }
        return;
    }

}

// *****************************************************************************
/*
Function:
    void DRV_I2S_BufferAddRead( const DRV_HANDLE handle,
                                DRV_I2S_BUFFER_HANDLE *bufferHandle,
                                void * buffer, size_t size)

  Summary:
    Schedule a non-blocking driver read operation.

  Description:
    This function schedules a non-blocking read operation. The function returns
    with a valid buffer handle  in the bufferHandle argument if the read request
    was scheduled successfully. The function adds the request to the hardware
    instance receive queue and returns immediately. While the request is in the
    queue, the application buffer is owned by the driver and should not be
    modified.  The function returns DRV_I2S_BUFFER_HANDLE_INVALID
    - if a buffer could not be allocated to the request
    - if the input buffer pointer is NULL
    - if the client opened the driver for write only
    - if the buffer size is 0.
    - if the queue is full or the queue depth is insufficient
    If the requesting client registered an event callback with the driver,
    the driver will issue a DRV_I2S_BUFFER_EVENT_COMPLETE event if the buffer
    was processed successfully of DRV_I2S_BUFFER_EVENT_ERROR event if the buffer
    was not processed successfully.

   Remarks:
    This function is thread safe in a RTOS application. It can be called from
    within the I2S Driver Buffer Event Handler that is registered by this
    client. It should not be called in the event handler associated with another
    I2S driver instance. It should not otherwise be called directly in an ISR.

*/
void DRV_I2S_BufferAddRead(const DRV_HANDLE handle,
        DRV_I2S_BUFFER_HANDLE *bufferHandle,
        void *buffer, size_t size)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_BUFFER_OBJECT *i2sBufObj;
    DRV_I2S_BUFFER_OBJECT_INDEX i2sBufIndex;
    DRV_I2S_OBJ *drvObj;
    bool interruptWasEnabled = false;

    /* The Client and driver objects from the handle */
    clientObj = (DRV_I2S_CLIENT_OBJ *) handle;
    drvObj = (DRV_I2S_OBJ *) clientObj->hDriver;

    /* We first check the arguments and initialize the
     * buffer handle */
    if(bufferHandle != NULL)
    {
        *bufferHandle = DRV_I2S_BUFFER_HANDLE_INVALID;
    }

    /* check if the receive queue size is 0 */
    if (0 == drvObj->queueSizeReceive)
    {
        SYS_DEBUG(0,"Cannot add a write operation as the queueSizeReceive is 0 \r\n");
        return;
    }        /* Bound checking for the buffer parameters */
    else if ((NULL == buffer) || (0 == size) || (bufferHandle == NULL))
    {
        SYS_DEBUG(0,"Buffer Pointer is NULL or size is 0 \r\n");
        return;
    }
    /* See if the handle is still valid */
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0,"Invalid Driver Handle \r\n");
        return;
    }
    /* If the driver was not opened in read mode */
    else if (!(DRV_IO_INTENT_READ & clientObj->ioIntent))
    {
        SYS_DEBUG(0,"Driver was not opened for read \r\n");
        return;
    }
    else
    {
        ;
    }

    /* We will allow buffers to be added in the interrupt
     * context of this I2S driver. But we must make
     * sure that if we are in interrupt, then we should
     * not modify mutexes. */
    if(!drvObj->isInInterruptContext)
    {
        /* Grab a mutex. This is okay because we are not in an
         * interrupt context */
        if(OSAL_MUTEX_Lock(&(drvObj->mutexDriverInstance), OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
        {
            /* We will disable interrupts so that the queue
             * status does not get updated asynchronously.
             * This code will always execute. */
            interruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->rxInterruptSource);
        }
        else
        {
            /* The mutex acquisition timed out. Return with an
             * invalid handle. This code will not execute
             * if there is no RTOS. */
            return;
        }
    }

    i2sBufIndex = _DRV_I2S_QueueObjectIndexGet();
    if (i2sBufIndex != DRV_I2S_BUFFER_OBJECT_INDEX_INVALID)
    {
        i2sBufObj = &gDrvI2SBufferQObj[i2sBufIndex];
        i2sBufObj->indexHandle = ((++gDrvI2SUniqueBufferHandle << 0x10) | i2sBufIndex);
        *bufferHandle = (DRV_I2S_BUFFER_HANDLE) i2sBufObj->indexHandle;         
        i2sBufObj->rxbuffer = (uint8_t *)buffer;
        i2sBufObj->txbuffer = NULL;
        i2sBufObj->size = size;
        i2sBufObj->next = (DRV_I2S_BUFFER_OBJECT *) NULL;
        i2sBufObj->nPendingBytes = size;
        i2sBufObj->clientObject = clientObj;

        /* If the queue is empty */
        if (drvObj->queueHead == ((DRV_I2S_BUFFER_OBJECT *) NULL))
        {
            drvObj->queueHead = i2sBufObj;
        } else
        {
            DRV_I2S_BUFFER_OBJECT *iterator;
            iterator = drvObj->queueHead;
            /* Insert the object at the end of the queue */
            while (iterator->next != NULL)
            {
                iterator = iterator->next;
            }
            iterator->next = i2sBufObj;
        }
        /* A location of the queue size is being used */
        drvObj->rxInhibit = 0;
        drvObj->queueSizeReceive--;
        drvObj->queueCurrentReceiveSize++;


        /* We are done. Restore the interrupt enable status
        * and return. */
        /* Enable the I2S receive interrupt */
        _DRV_I2S_InterruptSourceEnable(drvObj->rxInterruptSource);
        /* Release mutex */
        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
        {
            SYS_DEBUG(0, "Unable to unlock mutexDriverInstance mutex \r\n");
        }
        return;
    }
    else
    {
        /* This means we could not find a buffer. This
         * will happen if the the DRV_USART_QUEUE_DEPTH_COMBINED
         * parameter is configured to be less */
        SYS_DEBUG(0, "Insufficient Combined Queue Depth \r\n");
        /* Enable the interrupt if it was disabled */
        if(interruptWasEnabled)
        {
            _DRV_I2S_InterruptSourceEnable(drvObj->rxInterruptSource);
        }
        /* Release mutex */
        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
        {
            SYS_DEBUG(0, "Unable to unlock mutexDriverInstance mutex \r\n");
        }
        return;
    }
}

// *****************************************************************************
/* Function:
	void DRV_I2S_BufferAddWriteRead(const DRV_HANDLE handle,
                                        DRV_I2S_BUFFER_HANDLE	*bufferHandle,
                                        void *transmitBuffer, void *receiveBuffer,
                                        size_t size)

  Summary:
    Schedule a non-blocking driver write-read operation.

  Description:
    This function schedules a non-blocking write-read operation. The function
    returns with a valid buffer handle in the bufferHandle argument if the
    write-read request was scheduled successfully. The function adds the request
    to the hardware instance queue and returns immediately. While the request is
    in the queue, the application buffer is owned by the driver and should not
    be modified. The function returns DRV_I2S_BUFFER_HANDLE_INVALID
    - if a buffer could not be allocated to the request
    - if the input buffer pointer is NULL
    - if the client opened the driver for read only or write only
    - if the buffer size is 0.
    - if the queue is full or the queue depth is insufficient
    If the requesting client registered an event callback with the driver,
    the driver will issue a DRV_I2S_BUFFER_EVENT_COMPLETE event if the buffer
    was processed successfully of DRV_I2S_BUFFER_EVENT_ERROR event if the
    buffer was not processed successfully.

  Remarks:
    This function is thread safe in a RTOS application. It can be called from
    within the I2S Driver Buffer Event Handler that is registered by this
    client. It should not be called in the event handler associated with another
    I2S driver instance. It should not otherwise be called directly in an ISR.

    This function is useful when there is valid read expected for every
    I2S write. The transmit and receive size must be same.

*/

void DRV_I2S_BufferAddWriteRead(const DRV_HANDLE handle,
        DRV_I2S_BUFFER_HANDLE *bufferHandle,
        void *transmitBuffer, void *receiveBuffer,
        size_t size)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_BUFFER_OBJECT *i2sBufObj;
    DRV_I2S_BUFFER_OBJECT_INDEX i2sBufIndex;
    DRV_I2S_OBJ *drvObj;
    bool interruptWasEnabled = false;

    /* The Client and driver objects from the handle */
    clientObj = (DRV_I2S_CLIENT_OBJ *) handle;
    drvObj = (DRV_I2S_OBJ *) clientObj->hDriver;

    /* We first check the arguments and initialize the
     * buffer handle */
    if(bufferHandle != NULL)
    {
        *bufferHandle = DRV_I2S_BUFFER_HANDLE_INVALID;
    }

    /* check if the receive queue size is 0 */
    if (0 == drvObj->queueSizeReceive ||
            0 == drvObj->queueSizeTransmit)
    {
        SYS_DEBUG(0,
        "Cannot add the operation as the queueSizeTransmit/queueSizeReceive is 0 \r\n");
        return;
    }        /* Bound checking for the buffer parameters */
    else if ((NULL == transmitBuffer) || (NULL == receiveBuffer) || (0 == size)
            || (bufferHandle == NULL))
    {
        SYS_DEBUG(0, "Buffer Pointer is NULL or size is 0");
        return;
    }
    /* See if the handle is still valid */
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid Driver Handle");
        return;
    }
    /* If the driver was opened in write or read only mode */
    else if (DRV_IO_INTENT_READWRITE != (DRV_IO_INTENT_READWRITE & clientObj->ioIntent))
    {
        SYS_DEBUG(0, "Driver was not opened in Write/Read mode");
        return;
    }
    else
    {
        ;
    }

    /* We will allow buffers to be added in the interrupt
     * context of this I2S driver. But we must make
     * sure that if we are in interrupt, then we should
     * not modify mutexes. */
    if(!drvObj->isInInterruptContext)
    {
        /* Grab a mutex. This is okay because we are not in an
         * interrupt context */
        if(OSAL_MUTEX_Lock(&(drvObj->mutexDriverInstance), OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
        {
            /* We will disable interrupts so that the queue
             * status does not get updated asynchronously.
             * This code will always execute. */
            interruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->txInterruptSource);
        }
        else
        {
            /* The mutex acquisition timed out. Return with an
             * invalid handle. This code will not execute
             * if there is no RTOS. */
            return;
        }
    }

    i2sBufIndex = _DRV_I2S_QueueObjectIndexGet();
    if (i2sBufIndex != DRV_I2S_BUFFER_OBJECT_INDEX_INVALID)
    {
        i2sBufObj = &gDrvI2SBufferQObj[i2sBufIndex];
        i2sBufObj->indexHandle = ((++gDrvI2SUniqueBufferHandle << 0x10) | i2sBufIndex);
        *bufferHandle = (DRV_I2S_BUFFER_HANDLE) i2sBufObj->indexHandle;         
        i2sBufObj->txbuffer = (uint8_t *)transmitBuffer;
        i2sBufObj->rxbuffer = (uint8_t *)receiveBuffer;
        i2sBufObj->size = size;
        i2sBufObj->next = (DRV_I2S_BUFFER_OBJECT *) NULL;
        i2sBufObj->nPendingBytes = size;
        i2sBufObj->clientObject = clientObj;

        /* If the queue is empty */
        if (drvObj->queueHead == ((DRV_I2S_BUFFER_OBJECT *) NULL))
        {
            drvObj->queueHead = i2sBufObj;
            /* Enable the I2S transmit interrupt */
        } else
        {
            DRV_I2S_BUFFER_OBJECT *iterator;
            iterator = drvObj->queueHead;
            /* Insert the object at the end of the queue */
            while (iterator->next != NULL)
            {
                iterator = iterator->next;
            }
            iterator->next = i2sBufObj;
        }
        /* A location of the queue size is being used */
        drvObj->txInhibit = 0;
        drvObj->queueSizeTransmit--;
        drvObj->queueCurrentTransmitSize++;
        /*ToDo: We Don't have to add another buffer for Read. */
        //drvObj->queueSizeReceive--;
        //drvObj->queueCurrentReceiveSize++;

        /* We are done. Restore the interrupt enable status
        * and return. */
        /* Enable the I2S transmit interrupt */
        _DRV_I2S_InterruptSourceEnable(drvObj->txInterruptSource);
        /* Release mutex */
        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
        {
            SYS_DEBUG(0, "Unable to unlock mutexDriverInstance mutex \r\n");
        }
        return;
    }
    else
    {
        /* This means we could not find a buffer. This
         * will happen if the the DRV_USART_QUEUE_DEPTH_COMBINED
         * parameter is configured to be less */
        SYS_DEBUG(0, "Insufficient Combined Queue Depth");
        /* Enable the interrupt if it was disabled */
        if(interruptWasEnabled)
        {
            _DRV_I2S_InterruptSourceEnable(drvObj->txInterruptSource);
        }
        /* Release mutex */
        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
        {
            SYS_DEBUG(0, "Unable to unlock mutexDriverInstance mutex \r\n");
        }
        return;
    }
}


// *****************************************************************************
/*
  Function:
    void DRV_I2S_BufferEventHandlerSet( const DRV_HANDLE handle,
                                DRV_I2S_BUFFER_EVENT_HANDLER eventHandler,
	                			uintptr_t contextHandle)

  Summary:
    This function allows a client to identify a buffer event handling function
    for the driver to call back when queued buffer transfers have finished.

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

  Remarks:
    If the client does not want to be notified when the queued buffer transfer
    has completed, it does not need to register a callback.
*/
void DRV_I2S_BufferEventHandlerSet(DRV_HANDLE handle,
        const DRV_I2S_BUFFER_EVENT_HANDLER eventHandler,
        const uintptr_t contextHandle)
{
    DRV_I2S_CLIENT_OBJ *clientObj;

    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }

    if (eventHandler == (DRV_I2S_BUFFER_EVENT_HANDLER) NULL ||
        contextHandle == (uintptr_t) NULL)
    {
        SYS_DEBUG(0, "Invalid handler parameters \r\n");
        return;
    }

    /* Assing the event handler and the context */
    clientObj = (DRV_I2S_CLIENT_OBJ *) handle;

    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return;
    }

	/* Set the Event Handler and context */
	clientObj->pEventCallBack = eventHandler;
	clientObj->hClientArg = contextHandle;
    return;
}

// *****************************************************************************
/*
  Function:
    size_t DRV_I2S_BufferProcessedSizeGet(DRV_I2S_BUFFER_HANDLE bufferHandle)

  Summary:
    This function returns number of bytes that have been processed for the
    specified buffer.

  Description:
    This function returns number of bytes that have been processed for the
    specified buffer. The client can use this function, in a case where the
    buffer has terminated due to an error, to obtain the number of bytes that
    have been processed.
    If this function is called on a invalid buffer handle, or if the buffer
    handle has expired, then the function returns 0.

  Remarks:
    None.
*/
size_t DRV_I2S_BufferProcessedSizeGet(DRV_I2S_BUFFER_HANDLE bufferHandle)
{
    DRV_I2S_BUFFER_OBJECT *i2sBufObj;

    /* Validate the handle */
    if((DRV_I2S_BUFFER_HANDLE_INVALID == bufferHandle) ||
            (0 == bufferHandle))
    {
        return (size_t)(DRV_I2S_BUFFER_HANDLE_INVALID);
    }

    /* The buffer index is the contained in the lower 16 bits of the buffer
     * handle */
    i2sBufObj = (DRV_I2S_BUFFER_OBJECT *)&gDrvI2SObj[bufferHandle & 0xFFFF];
    if(false == i2sBufObj->inUse)
    {
        return (size_t)(DRV_I2S_BUFFER_HANDLE_INVALID);
    }

    return (size_t) (i2sBufObj->size - i2sBufObj->nPendingBytes);
}


// *****************************************************************************
/*
  Function:
    size_t DRV_I2S_BufferCombinedQueueSizeGet(DRV_HANDLE handle)

  Summary:
    This function returns the number of bytes queued (to be processed) in the
    buffer queue.

  Description:
    This function returns the number of bytes queued (to be processed) in the
    buffer queue. The client can use this function to know number of bytes
    that is in the queue to be transmitted.

    If this function is called on a invalid client handle, or if the
    handle has expired, then the function returns 0.

  Remarks:
    None.
*/
size_t DRV_I2S_BufferCombinedQueueSizeGet(DRV_HANDLE handle)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_OBJ *drvObj;
    uint16_t bufferQueuedSize;
    DRV_I2S_BUFFER_OBJECT *tempQueueObj;
    bool firstObjDone;

    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return 0;
    }
    /* Assign the event handler and the context */
    clientObj = (DRV_I2S_CLIENT_OBJ *) handle;
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return 0;
    }

    drvObj = (DRV_I2S_OBJ *) clientObj->hDriver;
    tempQueueObj = drvObj->queueHead;
    firstObjDone = false;
    bufferQueuedSize = 0;
    while(tempQueueObj != NULL)
    {
        /* Get the remaining size(bytes) at the first object at the head of the queue */
        if(!firstObjDone)
        {

            firstObjDone = true;
            bufferQueuedSize += tempQueueObj->nPendingBytes;            
        }
        else
        {
            /* Add the size of buffers queued. */
            bufferQueuedSize += tempQueueObj->size;
        }
        tempQueueObj = tempQueueObj->next;
    }
    return bufferQueuedSize;
}


// *****************************************************************************
/*
  Function:
    void DRV_I2S_BufferQueueFlush(DRV_HANDLE handle)

  Summary:
    This function flushes off the buffers associated with the client object.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function flushes off the buffers associated with the client object and
    disables the DMA channel used for transmission.

  Remarks:
    None.
*/
void DRV_I2S_BufferQueueFlush(DRV_HANDLE handle)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_OBJ *drvObj;
    DRV_I2S_BUFFER_OBJECT *iterator1, *iterator2;    
    DRV_IO_INTENT ioInten;
    bool txInterruptWasEnabled;
    bool rxInterruptWasEnabled;

    
    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }
    /* Assign the event handler and the context */
    clientObj = (DRV_I2S_CLIENT_OBJ *) handle;
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return;
    }
    ioInten = ioInten | clientObj->ioIntent;
    drvObj = (DRV_I2S_OBJ *) clientObj->hDriver;    
    iterator1 = drvObj->queueHead;       
    
    /* Disable the transmit interrupt */
    txInterruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->txInterruptSource);
    rxInterruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->rxInterruptSource);
        
    /*If the client do not have any object at the queue 
     * return by re enabling disabled DMA channels*/
    if(iterator1 == (DRV_I2S_BUFFER_OBJECT *) NULL)
    {
    }    
    else
    {     
        /* If the object being processed at the head of queue is owned 
         * by this client. (clientObj) */
        if(clientObj == (DRV_I2S_CLIENT_OBJ *)iterator1->clientObject )
        {
            iterator1->nPendingBytes = 0;
        }        
        while(iterator1->next!=NULL)
        {
            iterator2 = iterator1->next;
            if(clientObj == (DRV_I2S_CLIENT_OBJ *)iterator1->clientObject )
            {
                /* That means this buffer object is owned
                 * by this client. This buffer object should
                 * be removed. */
                iterator1->inUse = false;
                iterator1 = iterator1->next;
                iterator2 = iterator2->next;
            }
            else if(clientObj == (DRV_I2S_CLIENT_OBJ *)iterator2->clientObject)
            {
                /* That means this buffer object is owned
                 * by this client. This buffer object should
                 * be removed. */
                iterator2->inUse = false;
                iterator1->next = iterator2->next;
                iterator2 = iterator2->next;
            }
            else
            {
                iterator1 = iterator1->next;
                iterator2 = iterator2->next;
            }
        }
        
        /* This condition is for the case when there is only one object 
         * in the queue and that object is the buffer object owned by 
         * this client (clientObj) */
        if(clientObj == (DRV_I2S_CLIENT_OBJ *)iterator1->clientObject )
        {
            /* That means this buffer object is owned by this client. 
             * This buffer object should be removed. */
            iterator1->inUse = false;
            iterator1 = iterator1->next;
        }

        /* After removing the closed clientobj, 
         * If there are no buffers in the queue.
         * Make the head pointer point to NULL */
        if(0 == drvObj->queueCurrentReceiveSize &&
           0 == drvObj->queueCurrentTransmitSize)
        {
            drvObj->queueHead = (DRV_I2S_BUFFER_OBJECT *)0;
        }
        else
        {
            /* Iterate to update the head pointer to point
             * the first valid buffer object in the queue */
            iterator1 = drvObj->queueHead;
            while(iterator1 != (DRV_I2S_BUFFER_OBJECT *)0)
            {
                if(iterator1->inUse == true)
                {
                    drvObj->queueHead = iterator1;
                    break;
                }
                iterator1 = iterator1->next;
            }
        }
    }

    if(drvObj->queueHead!=NULL)
    {                                
        /* Re-enable the interrupt if it was disabled */
        if(txInterruptWasEnabled)
        {
            _DRV_I2S_InterruptSourceEnable(drvObj->txInterruptSource);
        }
        if(rxInterruptWasEnabled)
        {
            _DRV_I2S_InterruptSourceEnable(drvObj->rxInterruptSource);
        }  
    }    
    return;
}

// *****************************************************************************
/* Function:
    DRV_I2S_ERROR DRV_I2S_ErrorGet(DRV_HANDLE handle)

  Summary:
    This function returns the error(if any) associated with the last client
    request.

  Description:
    This function returns the error(if any) associated with the last client
    request. The DRV_I2S_Read() and DRV_I2S_Write() will update the client
    error status when these functions return DRV_I2S_READ_ERROR and
    DRV_I2S_WRITE_ERROR respectively.  If the driver send a
    DRV_I2S_BUFFER_EVENT_ERROR to the client, the client can call this function
    to know the error cause. The error status will be updated on every operation
    and should be read frequently (ideally immediately after the driver operation
    has completed) to know the relevant error status.

  Remarks:
    It is the client's responsibility to make sure that the error status is
    obtained frequently. The driver will update the client error status
    irrespective of whether this has been examined by the client.
*/
DRV_I2S_ERROR DRV_I2S_ErrorGet(DRV_HANDLE handle)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_ERROR error;

    if(handle == (DRV_HANDLE)0 || handle == DRV_HANDLE_INVALID)
    {
        SYS_DEBUG(0, "Invalid Client handle \r\n");
        return (DRV_I2S_ERROR_NONE);
    }

    clientObj = (DRV_I2S_CLIENT_OBJ *) handle;

    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid Driver Handle \r\n");
        return (DRV_I2S_ERROR_NONE);
    }

    /* Return the error. Clear the error before
     * returning. */
    error = clientObj->errorInfo;
    clientObj->errorInfo = DRV_I2S_ERROR_NONE;
    return (error);

}

/******************************************************************************
  Function:
    void DRV_I2S_BaudSet(DRV_HANDLE handle, uint32_t clockFrequency, uint32_t baudRate)

  Summary:
    This function sets the baudrate.

  Description:
    This function sets the baud rate for the I2S operation.

  Remarks:
    None.
*/
void DRV_I2S_BaudSet(DRV_HANDLE handle, uint32_t clockFrequency, uint32_t baudRate)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_OBJ *drvObj;

    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }

    /* Assign the event handler and the context */
    clientObj = (DRV_I2S_CLIENT_OBJ *) handle;
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return;
    }
    if(0 == clockFrequency || 0 == baudRate)
    {
        SYS_DEBUG(0, "Invalid parameters \r\n");
        return;
    }

    drvObj = (DRV_I2S_OBJ *) clientObj->hDriver;
    /* Baudrate selection */
    PLIB_SPI_BaudRateSet(drvObj->spiID, clockFrequency, baudRate);
    drvObj->baudRate = baudRate;
    return;
}

/******************************************************************************
  Function:
    void DRV_I2S_TransmitErrorIgnore(DRV_HANDLE handle, bool errorIgnore)

  Summary:
    This function enable/disable ignoring of the transmit underrun error.

  Description:
    A Transmit underrun error is not a critical error and zeros are transmitted
    until the SPIxTXB is not empty. Ignore Transmit underrun error is needed for
    cases when software does not care or does not need to know about underrun
    conditions.

  Remarks:
    None.
 */
void DRV_I2S_TransmitErrorIgnore(DRV_HANDLE handle, bool errorIgnore)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_OBJ *drvObj;

    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }

    /* Assign the event handler and the context */
    clientObj = (DRV_I2S_CLIENT_OBJ *) handle;
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return;
    }
    drvObj = (DRV_I2S_OBJ *) clientObj->hDriver;
    /* Ignore transmit underrun */
    if(true == errorIgnore)
    {
        PLIB_SPI_AudioErrorDisable(drvObj->spiID,
                                    SPI_AUDIO_ERROR_TRANSMIT_UNDERRUN);
        PLIB_SPI_ErrorInterruptDisable(drvObj->spiID,
                                    SPI_ERROR_INTERRUPT_TRANSMIT_UNDERRUN);
    }
    else
    {
        PLIB_SPI_AudioErrorEnable(drvObj->spiID,
                                    SPI_AUDIO_ERROR_TRANSMIT_UNDERRUN);
        PLIB_SPI_ErrorInterruptEnable(drvObj->spiID,
                                    SPI_ERROR_INTERRUPT_TRANSMIT_UNDERRUN);
    }
    return;
}

/******************************************************************************
  Function:
    void DRV_I2S_ReceiveErrorIgnore(DRV_HANDLE handle, bool errorEnable)

  Summary:
    This function enable/disable ignoring of the receive overflow error.

  Description:
    A receive overflow is not a critical error; during receive overflow data in
    the FIFO is not overwritten by receive data. Ignore receive overflow is
    needed for cases when there is a general performance problem in the system
    that software must handle properly.

  Remarks:
    None.
 */
void DRV_I2S_ReceiveErrorIgnore(DRV_HANDLE handle, bool errorIgnore)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_OBJ *drvObj;

    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }
    /* Assign the event handler and the context */
    clientObj = (DRV_I2S_CLIENT_OBJ *) handle;
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return;
    }
    drvObj = (DRV_I2S_OBJ *) clientObj->hDriver;
    /* By default do not Ignore receive overflow */
    if(true == errorIgnore)
    {
        PLIB_SPI_AudioErrorDisable(drvObj->spiID,
                                    SPI_AUDIO_ERROR_RECEIVE_OVERFLOW);
        PLIB_SPI_ErrorInterruptDisable(drvObj->spiID,
                                    SPI_ERROR_INTERRUPT_RECEIVE_OVERFLOW);
    }
    else
    {
        PLIB_SPI_AudioErrorEnable(drvObj->spiID,
                                    SPI_AUDIO_ERROR_RECEIVE_OVERFLOW);
        PLIB_SPI_ErrorInterruptEnable(drvObj->spiID,
                                    SPI_ERROR_INTERRUPT_RECEIVE_OVERFLOW);
    }
    return;
}



// *****************************************************************************
// *****************************************************************************
// Section: File scope functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    static void _DRV_I2S_HardwareSetup (DRV_I2S_OBJ *drvObj, DRV_I2S_INIT * i2sInit )

  Summary:
    Initializes the hardware registers.

  Description:
    Take the initialization data from the application (through DRV_I2S_Initialize
    function) and initialize the hardware registers.

  Remarks:
    None
 */
static void _DRV_I2S_HardwareSetup(DRV_I2S_OBJ *drvObj, DRV_I2S_INIT *i2sInit)
{
    /* Stop in Idle mode Initialization */
    if (true == DRV_I2S_STOP_IN_IDLE)
    {
        PLIB_SPI_StopInIdleEnable(i2sInit->spiID);
    }
    else
    {
        PLIB_SPI_StopInIdleDisable(i2sInit->spiID);
    }

    /* Clock Mode Initialization */
    if (DRV_I2S_CLOCK_MODE_IDLE_LOW_EDGE_RISE == i2sInit->clockMode)
    {
        /* Clock Polarity: Mode 0 - Idle State Low & Sampling on Rising Edge */
        PLIB_SPI_ClockPolaritySelect(i2sInit->spiID, SPI_CLOCK_POLARITY_IDLE_LOW);
        /* Output Data Phase */
        PLIB_SPI_OutputDataPhaseSelect(i2sInit->spiID,
                SPI_OUTPUT_DATA_PHASE_ON_IDLE_TO_ACTIVE_CLOCK);
    } else if (DRV_I2S_CLOCK_MODE_IDLE_LOW_EDGE_FALL == i2sInit->clockMode)
    {
        /* Clock Polarity: Mode 1 - Idle State Low & Sampling on Falling Edge */
        PLIB_SPI_ClockPolaritySelect(i2sInit->spiID, SPI_CLOCK_POLARITY_IDLE_LOW);
        /* Output Data Phase */
        PLIB_SPI_OutputDataPhaseSelect(i2sInit->spiID,
                SPI_OUTPUT_DATA_PHASE_ON_ACTIVE_TO_IDLE_CLOCK);
    } else if (DRV_I2S_CLOCK_MODE_IDLE_HIGH_EDGE_FALL == i2sInit->clockMode)
    {
        /* Clock Polarity: Mode 2 - Idle State High & Sampling on Falling Edge */
        PLIB_SPI_ClockPolaritySelect(i2sInit->spiID, SPI_CLOCK_POLARITY_IDLE_HIGH);
        /* Output Data Phase */
        PLIB_SPI_OutputDataPhaseSelect(i2sInit->spiID,
                SPI_OUTPUT_DATA_PHASE_ON_IDLE_TO_ACTIVE_CLOCK);
    } else if (DRV_I2S_CLOCK_MODE_IDLE_HIGH_EDGE_RISE == i2sInit->clockMode)
    {
        /* Clock Polarity: Mode 3 - Idle State High & Sampling on Rising Edge */
        PLIB_SPI_ClockPolaritySelect(i2sInit->spiID, SPI_CLOCK_POLARITY_IDLE_HIGH);
        /* Output Data Phase */
        PLIB_SPI_OutputDataPhaseSelect(i2sInit->spiID,
                SPI_OUTPUT_DATA_PHASE_ON_ACTIVE_TO_IDLE_CLOCK);
    } else
    {
        SYS_DEBUG(0, "Invalid Clock Mode \r\n");
    }
    PLIB_SPI_InputSamplePhaseSelect(i2sInit->spiID, i2sInit->inputSamplePhase);

    /* Audio protocol mode selection */
    if(i2sInit->protocolMode == DRV_I2S_AUDIO_LFET_JUSTIFIED ||
            DRV_I2S_AUDIO_RIGHT_JUSTIFIED == i2sInit->protocolMode)
    {
        PLIB_SPI_PinEnable(i2sInit->spiID, SPI_PIN_DATA_OUT);
        PLIB_SPI_FrameSyncPulseWidthSelect(i2sInit->spiID, SPI_FRAME_PULSE_WIDTH_ONE_CLOCK_WIDE);
        PLIB_SPI_FrameSyncPulseDirectionSelect(i2sInit->spiID, SPI_FRAME_PULSE_DIRECTION_OUTPUT);
        PLIB_SPI_FrameSyncPulsePolaritySelect(i2sInit->spiID, SPI_FRAME_PULSE_POLARITY_ACTIVE_HIGH);
        PLIB_SPI_FramedCommunicationEnable(i2sInit->spiID);
    }

    /* Usage Mode Master/Slave */
    if (DRV_I2S_MODE_MASTER == i2sInit->usageMode)
    {
        PLIB_SPI_MasterEnable(i2sInit->spiID);
        PLIB_SPI_SlaveSelectDisable(i2sInit->spiID);
    } else
    {
        PLIB_SPI_SlaveEnable(i2sInit->spiID);
        PLIB_SPI_SlaveSelectEnable(i2sInit->spiID);
    }

    /* Audio Communication Width Selection */
    PLIB_SPI_AudioCommunicationWidthSelect(i2sInit->spiID, i2sInit->audioCommWidth);
    drvObj->audioCommWidth = i2sInit->audioCommWidth;

    /* Audio protocol support is Enabled */
    PLIB_SPI_AudioProtocolEnable(i2sInit->spiID);
    /* Audio protocol mode selection */
    PLIB_SPI_AudioProtocolModeSelect(i2sInit->spiID, i2sInit->protocolMode);
    /* Audio data transmit format selection */
    PLIB_SPI_AudioTransmitModeSelect(i2sInit->spiID, i2sInit->audioTransmitMode);

    /* By default do not Ignore receive overflow */
    PLIB_SPI_AudioErrorEnable(i2sInit->spiID,
                                    SPI_AUDIO_ERROR_RECEIVE_OVERFLOW);
    PLIB_SPI_ErrorInterruptEnable(i2sInit->spiID,
                                    SPI_ERROR_INTERRUPT_RECEIVE_OVERFLOW);
    drvObj->ignoreRxOverflow = false;

    /* By default do not Ignore transmit underrun */
    PLIB_SPI_AudioErrorEnable(i2sInit->spiID,
                                    SPI_AUDIO_ERROR_TRANSMIT_UNDERRUN);
    PLIB_SPI_ErrorInterruptEnable(i2sInit->spiID,
                                    SPI_ERROR_INTERRUPT_TRANSMIT_UNDERRUN);
    drvObj->ignoreTxUnderrun = false;

    PLIB_SPI_ErrorInterruptEnable(i2sInit->spiID,
                                SPI_ERROR_INTERRUPT_FRAME_ERROR_OVERFLOW);
#if defined(PLIB_SPI_ExistsFIFOControl)
    /* Buffer type selection */
    if (true == PLIB_SPI_ExistsFIFOControl(i2sInit->spiID))
    {
        /* Enhanced Buffer Mode Enable */
        PLIB_SPI_FIFOEnable(i2sInit->spiID);
        /* Update the transmit buffer interrupt mode */
        PLIB_SPI_FIFOInterruptModeSelect(i2sInit->spiID,SPI_FIFO_INTERRUPT_WHEN_TRANSMIT_BUFFER_IS_COMPLETELY_EMPTY);
        /* Update the receive buffer interrupt mode */
        PLIB_SPI_FIFOInterruptModeSelect(i2sInit->spiID, SPI_FIFO_INTERRUPT_WHEN_RECEIVE_BUFFER_IS_FULL);

        drvObj->bufferType = DRV_I2S_BUFFER_TYPE_ENHANCED;
    }
#else
        /* Standard Buffer Mode */
        drvObj->bufferType = DRV_I2S_BUFFER_TYPE_STANDARD;
#endif
    /*Set the baudrate clock type */
    PLIB_SPI_BaudRateClockSelect(i2sInit->spiID, i2sInit->baudClock);
    return;
}

/*******************************************************************************
  Function:
    static DRV_I2S_BUFFER_OBJECT *_DRV_I2S_QueueObjectGet(void)

  Summary:
    Gets a buffer queue object from the available pool.

  Description:
    Take the initialization data from the application (through DRV_I2S_Initialize
    function) and initialize the hardware registers.

  Remarks:
    None
 */
static DRV_I2S_BUFFER_OBJECT_INDEX _DRV_I2S_QueueObjectIndexGet(void)
{
    DRV_I2S_BUFFER_OBJECT *queueObj;
    uint32_t index;

    queueObj = &gDrvI2SBufferQObj[0];
    for (index = 0; index < DRV_I2S_QUEUE_DEPTH_COMBINED; index++)
    {
        if (false == queueObj->inUse)
        {
            queueObj->inUse = true;
            return index;
        }
        queueObj++;
    }
    return DRV_I2S_BUFFER_OBJECT_INDEX_INVALID;
}



