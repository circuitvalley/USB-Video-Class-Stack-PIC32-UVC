/*******************************************************************************
  I2S Driver Dynamic implementation.

  Company:
    Microchip Technology Inc.

  File Name:
    drv_i2s_dma.c

  Summary:
    I2S Driver Dynamic Implementation.

  Description:
    This file contains the Dynamic mode implementation of the I2S driver.
    The implementation supports DMA based implementation only.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2014 released Microchip Technology Inc.  All rights reserved.

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
#include "../drv_i2s_dma_local.h"

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
    Defines the readwrite buffer instances objects

  Description:
    This data type defines the buffer instance objects

  Remarks:
    None
 */
DRV_I2S_BUFFER_OBJECT gDrvI2SBufferQObj[DRV_I2S_QUEUE_DEPTH_COMBINED];

// *****************************************************************************
/* Driver buffer instance objects.

  Summary:
    Defines the read buffer instances objects

  Description:
    This data type defines the buffer instance objects

  Remarks:
    None
 */
DRV_I2S_BUFFER_OBJECT gDrvI2SReadBufferQObj[QUEUE_SIZE_RX_IDX0];
// *****************************************************************************
/* Driver buffer instance objects.

  Summary:
    Defines the write buffer instances objects

  Description:
    This data type defines the buffer instance objects

  Remarks:
    None
 */
DRV_I2S_BUFFER_OBJECT gDrvI2SWriteBufferQObj[QUEUE_SIZE_TX_IDX0];

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
        SYS_DEBUG(0, "Instance already in use\r\n");
        return SYS_MODULE_OBJ_INVALID;
    }

    i2sInit = (DRV_I2S_INIT *) init;
    drvObj = (DRV_I2S_OBJ *)&gDrvI2SObj[drvIndex];

    /* Populate the driver object with the required data */
    drvObj->inUse = true;
    drvObj->status = SYS_STATUS_BUSY;
    drvObj->spiID = i2sInit->spiID;
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
    drvObj->readQueueHead = (DRV_I2S_BUFFER_OBJECT *) NULL;
    drvObj->writeQueueHead = (DRV_I2S_BUFFER_OBJECT *) NULL;
    drvObj->task = DRV_I2S_TASK_PROCESS_QUEUE;
    drvObj->numClients = 0;
    drvObj->status = SYS_STATUS_READY;

    /* Clear the interrupts */
    _DRV_I2S_InterruptSourceClear(drvObj->txInterruptSource);
    _DRV_I2S_InterruptSourceClear(drvObj->rxInterruptSource);
    _DRV_I2S_InterruptSourceClear(drvObj->errorInterruptSource);
    _DRV_I2S_InterruptSourceClear(drvObj->dmaInterruptTransmitSource);
    _DRV_I2S_InterruptSourceClear(drvObj->dmaInterruptReceiveSource);

    /* Enable the interrupt source in case of interrupt mode */
    _DRV_I2S_InterruptSourceEnable(drvObj->errorInterruptSource);

    /* Create the hardware instance mutex. */
     if(OSAL_MUTEX_Create(&(drvObj->mutexDriverInstance)) != OSAL_RESULT_TRUE)
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
    DRV_I2S_BUFFER_OBJECT * iterator, *itRead, *itWrite;

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
    _DRV_I2S_InterruptSourceDisable(drvObj->errorInterruptSource);
    _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptReceiveSource);
    _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptTransmitSource);

    /* Deallocate the allocated channel handles  */
    if(SYS_DMA_CHANNEL_HANDLE_INVALID != drvObj->dmaChannelHandleWrite)
    {
        SYS_DMA_ChannelRelease(drvObj->dmaChannelHandleWrite);
    }
    if(SYS_DMA_CHANNEL_HANDLE_INVALID != drvObj->dmaChannelHandleRead)
    {
        SYS_DMA_ChannelRelease(drvObj->dmaChannelHandleRead);
    }

    /* Turn off I2S module */
    PLIB_SPI_Disable(spiID);

    /* Deallocate all the mutexes */
     if((OSAL_MUTEX_Delete(&(drvObj->mutexDriverInstance)) != OSAL_RESULT_TRUE))
     {
        SYS_DEBUG(0, "Unable to delete client handle mutex \r\n");
        return;
     }

    /* Remove all objects from the queue */
    iterator = drvObj->queueHead;
    itRead = drvObj->readQueueHead;
    itWrite = drvObj->writeQueueHead;
    while(iterator != NULL)
    {
        /* Return the buffer object to the pool */
        iterator->inUse = false;
        iterator = iterator->next;
    }
    while(itRead != NULL)
    {
        /* Return the buffer object to the pool */
        itRead->inUse = false;
        itRead = itRead->next;
    }
    while(itWrite != NULL)
    {
        /* Return the buffer object to the pool */
        itWrite->inUse = false;
        itWrite = itWrite->next;
    }
    /* Indicate that this object is not is use */
    drvObj->inUse = false;
    /* Deallocate the buffer queue Object */
    drvObj->queueHead = (DRV_I2S_BUFFER_OBJECT *) NULL;
    drvObj->readQueueHead = (DRV_I2S_BUFFER_OBJECT *) NULL;
    drvObj->writeQueueHead = (DRV_I2S_BUFFER_OBJECT *) NULL;
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
    Maintains the driver's receive state machine and implements its ISR,
    This function only works for WRITEREAD mode.

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

    This routine may execute in an ISR context and will never block or access any
    resources that may cause it to block.
*/
void DRV_I2S_Tasks(SYS_MODULE_OBJ object)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_OBJ *drvObj;
    DRV_I2S_BUFFER_OBJECT *lQueueObj;
    bool txChannelInterruptWasEnabled = false;
    bool rxChannelInterruptWasEnabled = false;

    drvObj = (DRV_I2S_OBJ *)object;

    if((false == drvObj->inUse) || (drvObj->status != SYS_STATUS_READY))
    {
        /* This instance of the driver is not initialized. Don't do anything */
        return;
    }

    _DRV_I2S_isInInterruptContextSet(drvObj->isInInterruptContext);
    /* Setup the state of the I2S task based on the contents at the
    head of queue and client IO intent */

    txChannelInterruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptTransmitSource);
    rxChannelInterruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptReceiveSource);
    lQueueObj = drvObj->queueHead;
    if(lQueueObj == (DRV_I2S_BUFFER_OBJECT*) NULL)
    {        
        return;
    }        
    clientObj = lQueueObj->clientObject;
    if ((lQueueObj != (DRV_I2S_BUFFER_OBJECT*) NULL))
    {
       if(DRV_I2S_BUFFER_OPERATION_TYPE_WRITEREAD == lQueueObj->bType)
        {
            drvObj->task = DRV_I2S_TASK_PROCESS_WRITE_READ;
        }
    }

    if (DRV_I2S_TASK_PROCESS_WRITE_READ == drvObj->task)
    {
        /* DMA mode of operation */
        if( SYS_DMA_CHANNEL_HANDLE_INVALID != drvObj->dmaChannelHandleWrite &&
            SYS_DMA_CHANNEL_HANDLE_INVALID != drvObj->dmaChannelHandleRead)
        {
            drvObj->task = DRV_I2S_TASK_PROCESS_QUEUE;

            /*Callback with I2S Buffer Complete Event*/
            clientObj->pEventCallBack(clientObj->bufferEvent,
                    (DRV_I2S_BUFFER_HANDLE)lQueueObj->indexHandle,
                    clientObj->hClientArg);
            
            lQueueObj->inUse = false;
            /* Update the driver object's head pointer */
			if(drvObj->queueHead != (DRV_I2S_BUFFER_OBJECT*) NULL)
            {
                drvObj->queueHead = drvObj->queueHead->next;
                /* Release the location of a queue size */
                drvObj->queueSizeTransmit++;
                drvObj->queueCurrentTransmitSize--;
            }
            
            if(drvObj->queueHead==NULL)
            {
               /* We don't have any buffers to process. We can disable the interrupt. */
                _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptTransmitSource);
                _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptReceiveSource);
            }
        }
    }
    else
    {
        /* Impossible case */
        ;
    }

    if(drvObj->queueHead!=NULL)
    {
        lQueueObj = drvObj->queueHead;

        if(DRV_I2S_BUFFER_OPERATION_TYPE_WRITEREAD == lQueueObj->bType)
        {
            
            /* Adding Read Request */
            SYS_DMA_ChannelTransferAdd(drvObj->dmaChannelHandleRead,
                            PLIB_SPI_BufferAddressGet(drvObj->spiID),
                            drvObj->srcDestSize, lQueueObj->rxbuffer,
                            lQueueObj->size,drvObj->cellSize);
            
            /* Adding Write Request */
            SYS_DMA_ChannelTransferAdd(drvObj->dmaChannelHandleWrite,
                                lQueueObj->txbuffer, lQueueObj->size,
                                PLIB_SPI_BufferAddressGet(drvObj->spiID),
                                drvObj->srcDestSize,drvObj->cellSize);
        }
        else
        {
            /* Impossible case */
            ;
        }
        if(txChannelInterruptWasEnabled)
        {
            _DRV_I2S_InterruptSourceEnable(drvObj->dmaInterruptTransmitSource);
        }
        if(rxChannelInterruptWasEnabled)
        {
            _DRV_I2S_InterruptSourceEnable(drvObj->dmaInterruptReceiveSource);
        }
    }
    else
    {
        /* Disable SPI In pin to avoid dummy receives when no requests are made */
        PLIB_SPI_PinDisable(drvObj->spiID, SPI_PIN_DATA_IN);         
    }
   _DRV_I2S_isInInterruptContextClear(drvObj->isInInterruptContext);
   
   return;
}

// *****************************************************************************
/* Function:
    void DRV_I2S_ReadTasks(SYS_MODULE_OBJ object )

  Summary:
    Maintains the driver's receive state machine and implements its ISR,
    This function only works for READ mode.

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

    This routine may execute in an ISR context and will never block or access any
    resources that may cause it to block.
*/
void DRV_I2S_ReadTasks(SYS_MODULE_OBJ object){
    
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_OBJ *drvObj;
    DRV_I2S_BUFFER_OBJECT *lQueueObj;
    
    bool rxChannelInterruptWasEnabled = false;

    drvObj = (DRV_I2S_OBJ *)object;

    if((false == drvObj->inUse) || (drvObj->status != SYS_STATUS_READY))
    {
        /* This instance of the driver is not initialized. Don't do anything */
        return;
    }

    _DRV_I2S_isInInterruptContextSet(drvObj->isInInterruptContext);
    /* Setup the state of the I2S task based on the contents at the
    head of queue and client IO intent */

   
    rxChannelInterruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptReceiveSource);
    lQueueObj = drvObj->readQueueHead;
    if(lQueueObj == (DRV_I2S_BUFFER_OBJECT*) NULL)
    {
        return;
    }    
    clientObj = lQueueObj->clientObject;
    
        /* DMA mode of operation */
    if(SYS_DMA_CHANNEL_HANDLE_INVALID != drvObj->dmaChannelHandleRead)
    {
        drvObj->task = DRV_I2S_TASK_PROCESS_QUEUE;

        /*Callback with I2S Buffer Complete Event*/
        clientObj->pEventCallBack(clientObj->bufferEvent,
                (DRV_I2S_BUFFER_HANDLE)lQueueObj->indexHandle,
                clientObj->hClientArg);

        lQueueObj->inUse = false;
        if(drvObj->readQueueHead != (DRV_I2S_BUFFER_OBJECT*) NULL)
        {
            /* Update the driver object's head pointer */
            drvObj->readQueueHead = drvObj->readQueueHead->next;
            /* Release the location of a queue size */
            drvObj->queueSizeReceive++;
            drvObj->queueCurrentReceiveSize--;
        }

        if(drvObj->readQueueHead==NULL)
        {
           /* We don't have any buffers to process. We can disable the interrupt */
            _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptReceiveSource);
        }
    }

    if(drvObj->readQueueHead!=NULL)
    {
        lQueueObj = drvObj->readQueueHead;
        if(DRV_I2S_BUFFER_OPERATION_TYPE_READ == lQueueObj->bType)
        {
            SYS_DMA_ChannelTransferAdd(drvObj->dmaChannelHandleRead,
                        PLIB_SPI_BufferAddressGet(drvObj->spiID),
                        drvObj->srcDestSize, lQueueObj->rxbuffer,
                        lQueueObj->size,drvObj->cellSize);
        }
        

        if(rxChannelInterruptWasEnabled)
            {
            _DRV_I2S_InterruptSourceEnable(drvObj->dmaInterruptReceiveSource);
        }
            }
    else
    {
        /* Disable SPI In pin to avoid dummy receives when no requests are made */
        PLIB_SPI_PinDisable(drvObj->spiID, SPI_PIN_DATA_IN);         
        }
   _DRV_I2S_isInInterruptContextClear(drvObj->isInInterruptContext);
   
   return;
    }

// *****************************************************************************
/* Function:
    void DRV_I2S_WriteTasks(SYS_MODULE_OBJ object )

  Summary:
    Maintains the driver's receive state machine and implements its ISR,
    This function only works for WRITE mode.

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

    This routine may execute in an ISR context and will never block or access any
    resources that may cause it to block.
*/
 void DRV_I2S_WriteTasks(SYS_MODULE_OBJ object){
        
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_OBJ *drvObj;
    DRV_I2S_BUFFER_OBJECT *lQueueObj;
    bool txChannelInterruptWasEnabled = false;
    

    drvObj = (DRV_I2S_OBJ *)object;

    if((false == drvObj->inUse) || (drvObj->status != SYS_STATUS_READY))
    {
        /* This instance of the driver is not initialized. Don't do anything */
        return;
    }

    _DRV_I2S_isInInterruptContextSet(drvObj->isInInterruptContext);
    /* Setup the state of the I2S task based on the contents at the
    head of queue and client IO intent */

    txChannelInterruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptTransmitSource);
    
    lQueueObj = drvObj->writeQueueHead;    
    if(lQueueObj == (DRV_I2S_BUFFER_OBJECT*) NULL){
        
        return;
    }
    clientObj = lQueueObj->clientObject;
    
    drvObj->task = DRV_I2S_TASK_PROCESS_WRITE_ONLY;
        /* DMA mode of operation */
    if(SYS_DMA_CHANNEL_HANDLE_INVALID != drvObj->dmaChannelHandleWrite)
    {
        drvObj->task = DRV_I2S_TASK_PROCESS_QUEUE;

        /*Callback with I2S Buffer Complete Event*/
        clientObj->pEventCallBack(clientObj->bufferEvent,
                (DRV_I2S_BUFFER_HANDLE)lQueueObj->indexHandle,
                clientObj->hClientArg);

        lQueueObj->inUse = false;
        if(drvObj->writeQueueHead != (DRV_I2S_BUFFER_OBJECT*) NULL)
        {
            /* Update the driver object's head pointer */
            drvObj->writeQueueHead = drvObj->writeQueueHead->next;
            /* Release the location of a queue size */
            drvObj->queueSizeTransmit++;
            drvObj->queueCurrentTransmitSize--;
        }
            
        if(drvObj->writeQueueHead==NULL)
        {
            /* We don't have any buffers to process. We can disable the interrupt. */
             _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptTransmitSource);
        }
    }
    
    if(drvObj->writeQueueHead!=NULL)
    {
        lQueueObj = drvObj->writeQueueHead;
       

        {
            SYS_DMA_ChannelTransferAdd(drvObj->dmaChannelHandleWrite,
                        lQueueObj->txbuffer, lQueueObj->size,
                        PLIB_SPI_BufferAddressGet(drvObj->spiID),
                        drvObj->srcDestSize,drvObj->cellSize);
        }
            
        if(txChannelInterruptWasEnabled)
        {
            _DRV_I2S_InterruptSourceEnable(drvObj->dmaInterruptTransmitSource);
        }
        
    }
    else
    {
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
    bool errorOccured;

    drvObj = (DRV_I2S_OBJ *)object;
    if((false == drvObj->inUse) || (drvObj->status != SYS_STATUS_READY))
    {
        /* This instance of the driver is not initialized. Don't do anything */
        return;
    }

    errorOccured = false;
    lQueueObj = drvObj->queueHead;
    /* Check for a valid pointer */
    if (lQueueObj != (DRV_I2S_BUFFER_OBJECT *)NULL )
    {
        clientObj = lQueueObj->clientObject;
        /* DMA Mode: See if there is a DMA error */
        if(SYS_DMA_CHANNEL_HANDLE_INVALID != drvObj->dmaChannelHandleWrite ||
            SYS_DMA_CHANNEL_HANDLE_INVALID != drvObj->dmaChannelHandleRead )
        {
            if(DRV_I2S_DMA_TRANSFER_ERROR == lQueueObj->nPendingBytes)
            {
                if(DRV_I2S_BUFFER_EVENT_ERROR == clientObj->bufferEvent)
                {
                    /*Callback with I2S Buffer Complete Event*/
                    clientObj->errorInfo = DRV_I2S_ERROR_ADDRESS;
                    errorOccured = true;
                }
            }
        }
        if(true == errorOccured)
        {
            lQueueObj->inUse = false;
            /* Update the driver object's head pointer */
            if(DRV_I2S_TASK_PROCESS_WRITE_ONLY == drvObj->task)
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
                (DRV_I2S_BUFFER_HANDLE)lQueueObj->indexHandle, clientObj->hClientArg);
        }
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
    options additionally affect the behavior of the DRV_I2S_Read() and
    DRV_I2S_Write() functions. If the ioIntent is DRV_IO_INTENT_NONBLOCKING,
    then these function will not block even if the required amount of
    data could not be processed. If the ioIntent is DRV_IO_INTENT_BLOCKING,
    these functions will block till the required amount of data is processed.

    If ioIntent is DRV_IO_INTENT_READ, the client will only be read from
    the driver. If ioIntent is DRV_IO_INTENT_WRITE, the client will only be
    able to write to the driver.

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
                /* Set the exclusive mode for the driver instance */
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
                }
                else
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
    bool dmaWriteInterruptWasEnabled;
    bool dmaReadInterruptWasEnabled;
    DRV_I2S_BUFFER_OBJECT *iterator1;

    if(client == DRV_HANDLE_INVALID || (DRV_HANDLE)NULL == client)
    {
        SYS_DEBUG(0, "Invalid Driver Handle \r\n");
        return;
    }

    clientObj = (DRV_I2S_CLIENT_OBJ *) client;
    if (false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid Driver Handle \r\n");
        return;
    }

    drvObj = (DRV_I2S_OBJ *) clientObj->hDriver;
    /* Remove all buffer that this client owns
     * from the driver queue */

    if((OSAL_MUTEX_Lock(&(drvObj->mutexDriverInstance), OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE))
    {
        /* Disable the transmit interrupt */
        dmaWriteInterruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptTransmitSource);
        dmaReadInterruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptReceiveSource);

        iterator1 = drvObj->queueHead;
        while(iterator1 != NULL)
        {
            if(clientObj == (DRV_I2S_CLIENT_OBJ *)iterator1->clientObject)
            {
                iterator1->inUse = false;
                iterator1 = iterator1->next;
                drvObj->queueSizeTransmit++;
                drvObj->queueCurrentTransmitSize--;
            }
        }
        
        iterator1 = drvObj->readQueueHead;
        while(iterator1 != NULL){
            if(clientObj == (DRV_I2S_CLIENT_OBJ *)iterator1->clientObject){
                iterator1->inUse = false;
                iterator1 = iterator1->next;
                drvObj->queueSizeReceive++;
                drvObj->queueCurrentReceiveSize--;
            }
        }
        
        iterator1 = drvObj->writeQueueHead;
        while(iterator1 != NULL){
            if(clientObj == (DRV_I2S_CLIENT_OBJ *)iterator1->clientObject){
                iterator1->inUse = false;
                iterator1 = iterator1->next;
                drvObj->queueSizeTransmit++;
                drvObj->queueCurrentTransmitSize--;
            }
        }

        /* After removing the closed clientobj,
         * If there are no buffers in the queue.
         * Make the head pointer point to NULL */
        if(0 == drvObj->queueCurrentReceiveSize &&
           0 == drvObj->queueCurrentTransmitSize)
        {
            drvObj->queueHead = (DRV_I2S_BUFFER_OBJECT *)0;
            drvObj->readQueueHead = (DRV_I2S_BUFFER_OBJECT *)0;
            drvObj->writeQueueHead = (DRV_I2S_BUFFER_OBJECT *)0;
            
            /* Once the queue becomes empty as a consequence to the calling of DRV_I2S_Close, 
             * Any interrupt which was enabled and pending and earlier to the call to 'DRV_I2S_Close'
             * needs to be cleared as it might lead to a false handling of interrupt */
            if(dmaWriteInterruptWasEnabled && _DRV_I2S_InterruptSourceStatusGet(drvObj->dmaInterruptTransmitSource))
            {            
                _DRV_I2S_InterruptSourceClear(drvObj->dmaInterruptTransmitSource);                                
            }
            if(dmaReadInterruptWasEnabled && _DRV_I2S_InterruptSourceStatusGet(drvObj->dmaInterruptReceiveSource))
            {
                _DRV_I2S_InterruptSourceClear(drvObj->dmaInterruptReceiveSource);                
            }          
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
            
            iterator1 = drvObj->readQueueHead;
            while(iterator1 != (DRV_I2S_BUFFER_OBJECT *)0)
            {
                if(iterator1->inUse == true)
                {
                    drvObj->readQueueHead = iterator1;
                    break;
                }
                iterator1 = iterator1->next;
            }
            
            iterator1 = drvObj->writeQueueHead;
            while(iterator1 != (DRV_I2S_BUFFER_OBJECT *)0)
            {
                if(iterator1->inUse == true)
                {
                    drvObj->writeQueueHead = iterator1;
                    break;
                }
                iterator1 = iterator1->next;
            }
            
        }


        /* Done with closing client now,
         * Re-enable the interrupt if it was disabled */
        if(dmaWriteInterruptWasEnabled)
        {
            _DRV_I2S_InterruptSourceEnable(drvObj->dmaInterruptTransmitSource);
        }
        if(dmaReadInterruptWasEnabled)
        {
            _DRV_I2S_InterruptSourceEnable(drvObj->dmaInterruptReceiveSource);
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
    return;

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
    bool interruptWasEnabled;

    /* The Client and driver objects from the handle */
    interruptWasEnabled = false;
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
                interruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptTransmitSource);
        }
        else
        {
            /* The mutex acquisition timed out. Return with an
             * invalid handle. This code will not execute
             * if there is no RTOS. */
            return;
        }
    }
    i2sBufIndex = _DRV_I2S_WriteQueueObjectIndexGet();
    if (i2sBufIndex != DRV_I2S_BUFFER_OBJECT_INDEX_INVALID)
    {
        i2sBufObj = &gDrvI2SWriteBufferQObj[i2sBufIndex];
        i2sBufObj->indexHandle = ((++gDrvI2SUniqueBufferHandle << 0x10) | i2sBufIndex);
        *bufferHandle = (DRV_I2S_BUFFER_HANDLE) i2sBufObj->indexHandle;
        i2sBufObj->txbuffer = (uint8_t *)buffer;
        i2sBufObj->rxbuffer = NULL;
        i2sBufObj->size = size;
        i2sBufObj->next = (DRV_I2S_BUFFER_OBJECT *) NULL;
        i2sBufObj->nPendingBytes = size;
        i2sBufObj->clientObject = clientObj;
        i2sBufObj->bType = DRV_I2S_BUFFER_OPERATION_TYPE_WRITE;

        /* If the queue is empty */
        if (drvObj->writeQueueHead == ((DRV_I2S_BUFFER_OBJECT *) NULL))
        {
            drvObj->writeQueueHead = i2sBufObj;
            /* Since this is the first buffer in the queue Add it immediately
            to DMA for processing */
            SYS_DMA_ChannelTransferAdd(drvObj->dmaChannelHandleWrite,
                                i2sBufObj->txbuffer, i2sBufObj->size,
                                PLIB_SPI_BufferAddressGet(drvObj->spiID),
                                drvObj->srcDestSize,drvObj->cellSize);
        }
        else
        {
            DRV_I2S_BUFFER_OBJECT *iterator;
            iterator = drvObj->writeQueueHead;
            /* Insert the object at the end of the queue */
            while (iterator->next != NULL)
            {
                iterator = iterator->next;
            }
            iterator->next = i2sBufObj;
            /* DMA Mode: There is already a buffer under processing in the queue.
            This buffer will be added to DMA for processing immediately
            after the processing of the buffer prior to this buffer completes.
            (This functionality is implemented in DRV_I2S_Tasks)*/
        }
        /* A location of the queue size is being used */
        drvObj->queueSizeTransmit--;
        drvObj->queueCurrentTransmitSize++;
        /* We are done. Restore the interrupt enable status and return. */
        _SYS_DMA_ChannelForceStart(drvObj->dmaChannelHandleWrite);
        _DRV_I2S_InterruptSourceEnable(drvObj->dmaInterruptTransmitSource);

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
            _DRV_I2S_InterruptSourceEnable(drvObj->dmaInterruptTransmitSource);
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
/* Function:
	void DRV_I2S_BufferAddWriteRead(const DRV_HANDLE handle,
                                        DRV_I2S_BUFFER_HANDLE	*bufferHandle,
                                        void *transmitBuffer, void *receiveBuffer,
                                        size_t size)

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

  Remarks:
    This function is thread safe in a RTOS application. It can be called from
    within the I2S Driver Buffer Event Handler that is registered by this
    client. It should not be called in the event handler associated with another
    I2S driver instance. It should not otherwise be called directly in an ISR.

    This function is useful when there is valid read expected for every
    I2S write. The transmit and receive size must be same.

*/
void DRV_I2S_BufferAddWriteRead(const DRV_HANDLE handle,
                                DRV_I2S_BUFFER_HANDLE	*bufferHandle,
                                void *transmitBuffer, void *receiveBuffer,
                                size_t size)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_BUFFER_OBJECT *i2sBufObj;
    DRV_I2S_BUFFER_OBJECT_INDEX i2sBufIndex;
    DRV_I2S_OBJ *drvObj;
    bool interruptWasEnabled;

    /* The Client and driver objects from the handle */
    interruptWasEnabled = false;
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
        SYS_DEBUG(0,
            "Cannot add a write operation as the queueSizeTransmit is 0 \r\n");
        return;
    }        /* Bound checking for the buffer parameters */
    else if ((NULL == transmitBuffer) || (NULL == receiveBuffer) || (0 == size) || (bufferHandle == NULL))
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
    /* If the driver was opened in read only or write only mode */
    else if (DRV_IO_INTENT_READ == (DRV_IO_INTENT_READWRITE & clientObj->ioIntent) ||
             DRV_IO_INTENT_WRITE == (DRV_IO_INTENT_READWRITE & clientObj->ioIntent))
    {
        SYS_DEBUG(0, "Driver was opened in Read/write only mode \r\n");
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
                interruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptTransmitSource);
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
        i2sBufObj->bType = DRV_I2S_BUFFER_OPERATION_TYPE_WRITEREAD;

        /* If the queue is empty */
        if (drvObj->queueHead == ((DRV_I2S_BUFFER_OBJECT *) NULL))
        { 
            drvObj->queueHead = i2sBufObj;            
            /* Adding Read Request */
            SYS_DMA_ChannelTransferAdd(drvObj->dmaChannelHandleRead,
                            PLIB_SPI_BufferAddressGet(drvObj->spiID),
                            drvObj->srcDestSize, i2sBufObj->rxbuffer,
                            i2sBufObj->size,drvObj->cellSize);
            /* Since this is the first buffer in the queue Add it immediately
                to DMA for processing */
            /* Adding Write Request */
            SYS_DMA_ChannelTransferAdd(drvObj->dmaChannelHandleWrite,
                                i2sBufObj->txbuffer, i2sBufObj->size,
                                PLIB_SPI_BufferAddressGet(drvObj->spiID),
                                drvObj->srcDestSize,drvObj->cellSize);
            
            /* After adding the first Read request, Enable SPI In pin 
             * to start receiving */
            PLIB_SPI_PinEnable(drvObj->spiID, SPI_PIN_DATA_IN); 
            
        }
        else
        {
            DRV_I2S_BUFFER_OBJECT *iterator;
            iterator = drvObj->queueHead;
            
            if (iterator != NULL)
            {
                /* Insert the object at the end of the queue */
                while (iterator->next != NULL)
                {
                    iterator = iterator->next;
                }
                iterator->next = i2sBufObj;
                /* DMA Mode: There is already a buffer under processing in the queue.
                This buffer will be added to DMA for processing immediately
                after the processing of the buffer prior to this buffer completes.
                (This functionality is implemented in DRV_I2S_Tasks)*/
            }
        }
        /* A location of the queue size is being used */
        drvObj->queueSizeTransmit--;
        drvObj->queueCurrentTransmitSize++;
        /* We are done. Restore the interrupt enable status and return. */
        _SYS_DMA_ChannelForceStart(drvObj->dmaChannelHandleWrite);
        _DRV_I2S_InterruptSourceEnable(drvObj->dmaInterruptTransmitSource);
        _DRV_I2S_InterruptSourceEnable(drvObj->dmaInterruptReceiveSource);

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
            _DRV_I2S_InterruptSourceEnable(drvObj->dmaInterruptTransmitSource);
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
    bool interruptWasEnabled;

    /* The Client and driver objects from the handle */
    interruptWasEnabled = false;
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
        SYS_DEBUG(0,
        "Cannot add a write operation as the queueSizeTransmit is 0 \r\n");
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
            interruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptReceiveSource);
        }
        else
        {
            /* The mutex acquisition timed out. Return with an
             * invalid handle. This code will not execute
             * if there is no RTOS. */
            return;
        }
    }

    i2sBufIndex = _DRV_I2S_ReadQueueObjectIndexGet();
    if (i2sBufIndex != DRV_I2S_BUFFER_OBJECT_INDEX_INVALID)
    {
        i2sBufObj = &gDrvI2SReadBufferQObj[i2sBufIndex];
        i2sBufObj->indexHandle = ((++gDrvI2SUniqueBufferHandle << 0x10) | i2sBufIndex);
        *bufferHandle = (DRV_I2S_BUFFER_HANDLE) i2sBufObj->indexHandle;
        i2sBufObj->rxbuffer = (uint8_t *)buffer;
        i2sBufObj->txbuffer = NULL;
        i2sBufObj->size = size;
        i2sBufObj->next = (DRV_I2S_BUFFER_OBJECT *) NULL;
        i2sBufObj->nPendingBytes = size;
        i2sBufObj->clientObject = clientObj;
        i2sBufObj->bType = DRV_I2S_BUFFER_OPERATION_TYPE_READ;

        /* If the queue is empty */
        if (drvObj->readQueueHead == ((DRV_I2S_BUFFER_OBJECT *) NULL))
        {
            drvObj->readQueueHead = i2sBufObj;
            /* Since this is the first buffer in the queue Add it immediately
               to DMA for processing */
            SYS_DMA_ChannelTransferAdd(drvObj->dmaChannelHandleRead,
                            PLIB_SPI_BufferAddressGet(drvObj->spiID),
                            drvObj->srcDestSize, i2sBufObj->rxbuffer,
                            i2sBufObj->size,drvObj->cellSize);
            /* After adding the first Read request, Enable SPI In pin 
             * to start receiving */
            PLIB_SPI_PinEnable(drvObj->spiID, SPI_PIN_DATA_IN);             
        }
        else
        {
            DRV_I2S_BUFFER_OBJECT *iterator;
            iterator = drvObj->readQueueHead;
            /* Insert the object at the end of the queue */
            while (iterator->next != NULL)
            {
                iterator = iterator->next;
            }
            iterator->next = i2sBufObj;
            /* DMA Mode: There is already a buffer under processing in the queue.
            This buffer will be added to DMA for processing immediately
            after the processing of the buffer prior to this buffer completes.
            (This functionality is implemented in DRV_I2S_Tasks)*/
        }
        /* A location of the queue size is being used */
        drvObj->queueSizeReceive--;
        drvObj->queueCurrentReceiveSize++;

        /* We are done. Restore the interrupt enable status and return. */
        /* DMA Mode of operation */
        _SYS_DMA_ChannelForceStart(drvObj->dmaChannelHandleRead);
        _DRV_I2S_InterruptSourceEnable(drvObj->dmaInterruptReceiveSource);

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
            _DRV_I2S_InterruptSourceEnable(drvObj->dmaInterruptReceiveSource);
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
    drvObj = clientObj->hDriver;
    /* Set the Event Handler and context */
    clientObj->pEventCallBack = eventHandler;
    clientObj->hClientArg = contextHandle;

    if(SYS_DMA_CHANNEL_HANDLE_INVALID != drvObj->dmaChannelHandleRead 
            && SYS_DMA_CHANNEL_HANDLE_INVALID != drvObj->dmaChannelHandleWrite)
    {
        if((DRV_IO_INTENT_READWRITE == (DRV_IO_INTENT_READWRITE & clientObj->ioIntent)))
        {
            SYS_DMA_ChannelTransferEventHandlerSet(drvObj->dmaChannelHandleRead,
                (SYS_DMA_CHANNEL_TRANSFER_EVENT_HANDLER)_DRV_I2S_DMA_EventHandler,
                (uintptr_t)drvObj);

            SYS_DMA_ChannelTransferEventHandlerSet(drvObj->dmaChannelHandleWrite,
                (SYS_DMA_CHANNEL_TRANSFER_EVENT_HANDLER)_DRV_I2S_DMA_EventHandler,
                (uintptr_t)drvObj);                                    
        }
        else
        {
            if((DRV_IO_INTENT_WRITE == (DRV_IO_INTENT_WRITE & clientObj->ioIntent))){
                SYS_DMA_ChannelTransferEventHandlerSet(drvObj->dmaChannelHandleWrite,
                        (SYS_DMA_CHANNEL_TRANSFER_EVENT_HANDLER)_DRV_I2S_DMA_WriteEventHandler,
                        (uintptr_t)drvObj);
            }
            else if((DRV_IO_INTENT_READ == (DRV_IO_INTENT_READ & clientObj->ioIntent)))
            {
                SYS_DMA_ChannelTransferEventHandlerSet(drvObj->dmaChannelHandleRead,
                    (SYS_DMA_CHANNEL_TRANSFER_EVENT_HANDLER)_DRV_I2S_DMA_ReadEventHandler,
                    (uintptr_t)drvObj);
            }
        } 
        
    }else{
    if(SYS_DMA_CHANNEL_HANDLE_INVALID != drvObj->dmaChannelHandleWrite )
    {
        if((DRV_IO_INTENT_WRITE == (DRV_IO_INTENT_WRITE & clientObj->ioIntent)))
        {
            SYS_DMA_ChannelTransferEventHandlerSet(drvObj->dmaChannelHandleWrite,
                    (SYS_DMA_CHANNEL_TRANSFER_EVENT_HANDLER)_DRV_I2S_DMA_WriteEventHandler,
                (uintptr_t)drvObj);
        }
    }
        else if(SYS_DMA_CHANNEL_HANDLE_INVALID != drvObj->dmaChannelHandleRead)
    {
        if((DRV_IO_INTENT_READ == (DRV_IO_INTENT_READ & clientObj->ioIntent)))
        {
            SYS_DMA_ChannelTransferEventHandlerSet(drvObj->dmaChannelHandleRead,
                    (SYS_DMA_CHANNEL_TRANSFER_EVENT_HANDLER)_DRV_I2S_DMA_ReadEventHandler,
                (uintptr_t)drvObj);
        }
    }
    }
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
size_t DRV_I2S_BufferProcessedSizeGet(DRV_HANDLE handle)
{
	DRV_I2S_CLIENT_OBJ *clientObj;    DRV_IO_INTENT ioIntent;
    DRV_I2S_OBJ *drvObj;
    size_t processedBytes;
    if((DRV_HANDLE_INVALID == handle) || (0 == handle))
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return (size_t) (DRV_I2S_BUFFER_HANDLE_INVALID);
    }

    /* Assign the event handler and the context */
    clientObj = (DRV_I2S_CLIENT_OBJ *) handle;
    if(false == clientObj->inUse)
    {
        SYS_DEBUG(0, "Invalid driver handle \r\n");
        return (size_t) (DRV_I2S_BUFFER_HANDLE_INVALID);
    }

    processedBytes = 0;
    ioIntent = clientObj->ioIntent;
    drvObj = clientObj->hDriver;
    if(DRV_IO_INTENT_READ == (DRV_IO_INTENT_READ & ioIntent))
    {
        processedBytes = SYS_DMA_ChannelDestinationTransferredSizeGet(drvObj->dmaChannelHandleRead);
    }
    else if(DRV_IO_INTENT_WRITE == (DRV_IO_INTENT_WRITE & ioIntent))
    {
        processedBytes = SYS_DMA_ChannelSourceTransferredSizeGet(drvObj->dmaChannelHandleWrite);

    }
    else if(DRV_IO_INTENT_READWRITE == (DRV_IO_INTENT_READWRITE & ioIntent))
    {
        /* For a WriteRead operation. The number of bytes read actually
         * equals the number of bytes written and corresponding replies read back */
        processedBytes = SYS_DMA_ChannelDestinationTransferredSizeGet(drvObj->dmaChannelHandleRead);
    }
    else
    {
        /* Impossible case */
        ;
    }
    return processedBytes;
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
    
*/
size_t DRV_I2S_BufferCombinedQueueSizeGet(DRV_HANDLE handle)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_OBJ *drvObj;
    uint16_t bufferQueuedSize;
    DRV_I2S_BUFFER_OBJECT *tempQueueObj;
    size_t processedBytes;
    bool firstObjDone;
    DRV_IO_INTENT ioInten;

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

    //TODO:  Why not get the ioIntent from the clientObj directly, so the 
    //       correct buffer queue can be selected based on ioIntent?
#if 1
    //New way
    ioInten = clientObj->ioIntent;
    if(DRV_IO_INTENT_READ == (DRV_IO_INTENT_READ & ioInten))
    {
        tempQueueObj = drvObj->readQueueHead;
    }
    else if(DRV_IO_INTENT_WRITE == (DRV_IO_INTENT_WRITE & ioInten))
    {
        tempQueueObj = drvObj->writeQueueHead;
    }
    else
    {
        tempQueueObj = drvObj->queueHead;
    }
#else
    //Old way
    tempQueueObj = drvObj->queueHead;
    ioInten = tempQueueObj->clientObject->ioIntent;
#endif

    firstObjDone = false; //????
    bufferQueuedSize = 0;
    processedBytes = 0;

    while(tempQueueObj != NULL)
    {
        /* Get the remaining size(bytes) at the first object at the head of the queue */
        if(!firstObjDone)  //ALLWAYS TRUE
        {
            /* If the first buffer object at the queue head is submitted by the 
             * calling client object */
            if(tempQueueObj->clientObject == clientObj)
            {            
                if(DRV_IO_INTENT_READ == (DRV_IO_INTENT_READ & ioInten))
                {
                    //Read Queue Head
                    processedBytes = SYS_DMA_ChannelDestinationTransferredSizeGet(drvObj->dmaChannelHandleRead);
                    bufferQueuedSize += (tempQueueObj->size - processedBytes);
                }
                else if(DRV_IO_INTENT_WRITE == (DRV_IO_INTENT_WRITE & ioInten))
                {
                    //Write Queue Head
                    processedBytes = SYS_DMA_ChannelSourceTransferredSizeGet(drvObj->dmaChannelHandleWrite);
                    bufferQueuedSize += (tempQueueObj->size - processedBytes);
                }
                else if(DRV_IO_INTENT_READWRITE == (DRV_IO_INTENT_READWRITE & ioInten))
                {
                    //READ/WRITE Queue Head
                    /* For a WriteRead operation. The number of bytes read actually
                     * equals the number of bytes written and corresponding replies read back */
                    processedBytes = SYS_DMA_ChannelDestinationTransferredSizeGet(drvObj->dmaChannelHandleRead);
                    bufferQueuedSize += (tempQueueObj->size - processedBytes);
                }
                else
                {
                    /* Impossible case */
                    ;
                }
            }
            firstObjDone = true;
        }
        else
        {
            /* If the buffer object at the queue is submitted by the 
             * calling client object */            
            if(tempQueueObj->clientObject == clientObj)
            {                
                /* Add the size of buffers queued. */
                bufferQueuedSize += tempQueueObj->size;
            }
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
     The Driver uses a specialized queue for the client's combined Read/Write, 
     Read Only, and Write Only operations.
*/
void DRV_I2S_BufferQueueFlush(DRV_HANDLE handle)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_OBJ *drvObj;
    DRV_I2S_BUFFER_OBJECT *iterator1, *readItr, *writeItr;    
    DRV_IO_INTENT ioIntent;
    bool dmaWriteInterruptWasEnabled;
    bool dmaReadInterruptWasEnabled;
    
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
    ioIntent = clientObj->ioIntent;
    drvObj = (DRV_I2S_OBJ *) clientObj->hDriver;    
    iterator1 = drvObj->queueHead;       
    readItr = drvObj->readQueueHead;
    writeItr = drvObj->writeQueueHead;
    
    dmaWriteInterruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptTransmitSource);
    dmaReadInterruptWasEnabled = _DRV_I2S_InterruptSourceDisable(drvObj->dmaInterruptReceiveSource);    
        

    /* If the object being processed at the head of queue is owned 
    * by this client. (clientObj) */
    if (DRV_IO_INTENT_READWRITE == (ioIntent & DRV_IO_INTENT_READWRITE))
    {                        
        //Clear the READWRITEQueue DMA
        if(iterator1 != NULL && clientObj == (DRV_I2S_CLIENT_OBJ *)iterator1->clientObject )
        {
            SYS_DMA_ChannelForceAbort(drvObj->dmaChannelHandleWrite);
            SYS_DMA_ChannelForceAbort(drvObj->dmaChannelHandleRead);                     
        }
        while(iterator1 != NULL)
        {
            if(clientObj == (DRV_I2S_CLIENT_OBJ *)iterator1->clientObject )
            {
                iterator1->inUse = false;
                iterator1 = iterator1->next;
                drvObj->queueSizeTransmit++;
                drvObj->queueCurrentTransmitSize--;
            }
        }
    }   
    else if (DRV_IO_INTENT_READ == (ioIntent & DRV_IO_INTENT_READ))
    {
        //Clear the READ Queue DMA
        if(readItr != NULL && clientObj == (DRV_I2S_CLIENT_OBJ *)readItr->clientObject )
        {                
            SYS_DMA_ChannelForceAbort(drvObj->dmaChannelHandleRead);                
        }
        while(readItr != NULL)
        {
            if(clientObj == (DRV_I2S_CLIENT_OBJ *)readItr->clientObject )
            {
                readItr->inUse = false;
                readItr = readItr->next;
                drvObj->queueSizeReceive++;
                drvObj->queueCurrentReceiveSize--;
            } 
        }        
    }
    else if (DRV_IO_INTENT_WRITE == (ioIntent & DRV_IO_INTENT_WRITE))
    {
        //Clear the WRITE Queue DMA
        if(writeItr != NULL && clientObj == (DRV_I2S_CLIENT_OBJ *)writeItr->clientObject )
        {                 
            SYS_DMA_ChannelForceAbort(drvObj->dmaChannelHandleWrite);
        }
        while(writeItr != NULL)
        {
            if(clientObj == (DRV_I2S_CLIENT_OBJ *)writeItr->clientObject )
            {
                writeItr->inUse = false;
                writeItr = writeItr->next;
                drvObj->queueSizeTransmit++;
                drvObj->queueCurrentTransmitSize--;
            }
        }
    }        
    /* After removing the closed clientobj, 
     * If there are no buffers in the queue.
     * Make the head pointer point to NULL */
    if(0 == drvObj->queueCurrentReceiveSize &&
       0 == drvObj->queueCurrentTransmitSize)
    {
        drvObj->queueHead = (DRV_I2S_BUFFER_OBJECT *)0;
        drvObj->readQueueHead = (DRV_I2S_BUFFER_OBJECT *)0;
        drvObj->writeQueueHead = (DRV_I2S_BUFFER_OBJECT *)0;
        
        /* Once the queue becomes empty as a consequence to the calling of DRV_I2S_BufferQueueFlush, 
        * Any interrupt which was enabled and pending and earlier to the call to 'DRV_I2S_BufferQueueFlush'
        * needs to be cleared as it might lead to a false handling of interrupt */
        if(dmaWriteInterruptWasEnabled && _DRV_I2S_InterruptSourceStatusGet(drvObj->dmaInterruptTransmitSource))
        {            
            _DRV_I2S_InterruptSourceClear(drvObj->dmaInterruptTransmitSource);                                
        }
        if(dmaReadInterruptWasEnabled && _DRV_I2S_InterruptSourceStatusGet(drvObj->dmaInterruptReceiveSource))
        {
            _DRV_I2S_InterruptSourceClear(drvObj->dmaInterruptReceiveSource);                
        }
        
    }
    else
    {
        // READ/WRITE Queue
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

        // READ Only Queue
        readItr = drvObj->readQueueHead;
        while(readItr != (DRV_I2S_BUFFER_OBJECT *)0){
            if(readItr->inUse == true){
                drvObj->readQueueHead = readItr;
                break;
            }
            readItr = readItr->next;
        }

        //WRITE Only Queue
        writeItr = drvObj->writeQueueHead;
        while(writeItr != (DRV_I2S_BUFFER_OBJECT *)0){
            if(writeItr->inUse == true){
                drvObj->writeQueueHead = writeItr;
                break;
            }
            writeItr = writeItr->next;
        }
    }


    if(drvObj->queueHead != NULL){
        SYS_DMA_ChannelEnable(drvObj->dmaChannelHandleWrite);
        SYS_DMA_ChannelEnable(drvObj->dmaChannelHandleRead);   
    }
    else{
        if(drvObj->readQueueHead != NULL){
            SYS_DMA_ChannelEnable(drvObj->dmaChannelHandleRead);
        }
        if(drvObj->writeQueueHead != NULL){
            SYS_DMA_ChannelEnable(drvObj->dmaChannelHandleWrite);         
        }
    }
                        
    /* Re-enable the interrupt if it was disabled */
    if(dmaWriteInterruptWasEnabled)
    {
        _DRV_I2S_InterruptSourceEnable(drvObj->dmaInterruptTransmitSource);
    }
    if(dmaReadInterruptWasEnabled)
    {
        _DRV_I2S_InterruptSourceEnable(drvObj->dmaInterruptReceiveSource);
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

    if(handle == (DRV_HANDLE)NULL || handle == DRV_HANDLE_INVALID)
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
    void DRV_I2S_SetAudioCommunicationMode(const DRV_HANDLE handle, SPI_AUDIO_COMMUNICATION_WIDTH audioCommWidth)

  Summary:
    This function sets the audio communication width.

  Description:
    This function sets the audio communication width for the I2S operation.

  Remarks:
    None.
*/
void DRV_I2S_SetAudioCommunicationMode(const DRV_HANDLE handle, SPI_AUDIO_COMMUNICATION_WIDTH audioCommWidth)
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
    
    PLIB_SPI_Disable(drvObj->spiID);
    drvObj->audioCommWidth = audioCommWidth;
    /* Audio Communication Width Selection */
    PLIB_SPI_AudioCommunicationWidthSelect(drvObj->spiID, drvObj->audioCommWidth);
    
    if(drvObj->audioCommWidth < SPI_AUDIO_COMMUNICATION_32DATA_32FIFO_32CHANNEL)
    {
        drvObj->srcDestSize = 2;
        drvObj->cellSize = 2;
    }
    else
    {
        drvObj->srcDestSize = 4;
        drvObj->cellSize = 4;
    }
    
    PLIB_SPI_Enable(drvObj->spiID);
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

    /* Disable SPI In Pin to keep Rx FIFO empty until explicitly enabled  */
    PLIB_SPI_PinDisable(i2sInit->spiID, SPI_PIN_DATA_IN);
    
    /* Usage Mode Master/Slave */
    if (DRV_I2S_MODE_MASTER == i2sInit->usageMode)
    {
        PLIB_SPI_MasterEnable(i2sInit->spiID);
        PLIB_SPI_SlaveSelectDisable(i2sInit->spiID);
    }
    else
    {
        PLIB_SPI_SlaveEnable(i2sInit->spiID);
        PLIB_SPI_SlaveSelectEnable(i2sInit->spiID);
    }
    /* Audio Communication Width Selection */
    PLIB_SPI_AudioCommunicationWidthSelect(i2sInit->spiID, i2sInit->audioCommWidth);
    drvObj->audioCommWidth = i2sInit->audioCommWidth;
    if(drvObj->audioCommWidth < SPI_AUDIO_COMMUNICATION_32DATA_32FIFO_32CHANNEL)
    {
        drvObj->srcDestSize = 2;
        drvObj->cellSize = 2;
    }
    else
    {
        drvObj->srcDestSize = 4;
        drvObj->cellSize = 4;
    }

    /* Audio protocol support is Enabled */
    PLIB_SPI_AudioProtocolEnable(i2sInit->spiID);
    /* Audio protocol select */
    PLIB_SPI_AudioProtocolModeSelect(i2sInit->spiID, i2sInit->protocolMode);
    /* Audio data transmit format selection */
    PLIB_SPI_AudioTransmitModeSelect(i2sInit->spiID, i2sInit->audioTransmitMode);

    /* By default do not Ignore receive overflow */
    PLIB_SPI_AudioErrorEnable(i2sInit->spiID, SPI_AUDIO_ERROR_RECEIVE_OVERFLOW);
    PLIB_SPI_ErrorInterruptEnable(i2sInit->spiID, SPI_ERROR_INTERRUPT_RECEIVE_OVERFLOW);
    drvObj->ignoreRxOverflow = false;

    /* By default do not Ignore transmit underrun */
    PLIB_SPI_AudioErrorEnable(i2sInit->spiID, SPI_AUDIO_ERROR_TRANSMIT_UNDERRUN);
    PLIB_SPI_ErrorInterruptEnable(i2sInit->spiID, SPI_ERROR_INTERRUPT_TRANSMIT_UNDERRUN);
    drvObj->ignoreTxUnderrun = false;
    /* SPI frame Error Enable */
    PLIB_SPI_ErrorInterruptEnable(i2sInit->spiID,SPI_ERROR_INTERRUPT_FRAME_ERROR_OVERFLOW);

    /* Buffer type selection */
#if defined (PLIB_SPI_ExistsFIFOControl)    
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

    /* DMA mode of operation.
     * Allocate a handle for the specified channel.
     * Setup the channel for transfer */
    /* Initializing the channel handles with invalid value */
    drvObj->dmaChannelHandleWrite = SYS_DMA_CHANNEL_HANDLE_INVALID;
    drvObj->dmaChannelHandleRead = SYS_DMA_CHANNEL_HANDLE_INVALID;

    /* Tx DMA channel setup */
    if(DMA_CHANNEL_NONE != i2sInit->dmaChannelTransmit &&
        DMA_NUMBER_OF_CHANNELS != i2sInit->dmaChannelTransmit)
    {
        drvObj->dmaChannelHandleWrite =
                SYS_DMA_ChannelAllocate(i2sInit->dmaChannelTransmit);
        if(SYS_DMA_CHANNEL_HANDLE_INVALID != drvObj->dmaChannelHandleWrite)
        {
            /* Setting the channel priority same as the channel number */
            SYS_DMA_ChannelSetup(drvObj->dmaChannelHandleWrite,
                                 SYS_DMA_CHANNEL_OP_MODE_BASIC, i2sInit->txInterruptSource);
            drvObj->dmaInterruptTransmitSource = i2sInit->dmaInterruptTransmitSource;
        }
    }

    /* Rx DMA channel setup */
    if(DMA_CHANNEL_NONE != i2sInit->dmaChannelReceive &&
        DMA_NUMBER_OF_CHANNELS != i2sInit->dmaChannelReceive)
    {
        drvObj->dmaChannelHandleRead =
                SYS_DMA_ChannelAllocate(i2sInit->dmaChannelReceive);
        if(SYS_DMA_CHANNEL_HANDLE_INVALID != drvObj->dmaChannelHandleRead)
        {
            /* Setting the channel priority same as the channel number */
            SYS_DMA_ChannelSetup(drvObj->dmaChannelHandleRead,
                                 SYS_DMA_CHANNEL_OP_MODE_BASIC, i2sInit->rxInterruptSource);
            drvObj->dmaInterruptReceiveSource = i2sInit->dmaInterruptReceiveSource;
        }
    }   
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
    SYS_INT_PROCESSOR_STATUS int_status;
    queueObj = &gDrvI2SBufferQObj[0];
    for (index = 0; index < DRV_I2S_QUEUE_DEPTH_COMBINED; index++)
    {
        int_status = SYS_INT_StatusGetAndDisable();
        if (false == queueObj->inUse)
        {
            queueObj->inUse = true;
            SYS_INT_StatusRestore(int_status);
            return index;
        }
        SYS_INT_StatusRestore(int_status);
        queueObj++;
    }
    return DRV_I2S_BUFFER_OBJECT_INDEX_INVALID;
}

static DRV_I2S_BUFFER_OBJECT_INDEX _DRV_I2S_ReadQueueObjectIndexGet(void)
{
    DRV_I2S_BUFFER_OBJECT *queueObj;
    uint32_t index;
    SYS_INT_PROCESSOR_STATUS int_status;
    queueObj = &gDrvI2SReadBufferQObj[0];
    for (index = 0; index < QUEUE_SIZE_RX_IDX0; index++)
    {
        int_status = SYS_INT_StatusGetAndDisable();
        if (false == queueObj->inUse)
        {
            queueObj->inUse = true;
            SYS_INT_StatusRestore(int_status);
            return index;
        }
        SYS_INT_StatusRestore(int_status);
        queueObj++;
    }
    return DRV_I2S_BUFFER_OBJECT_INDEX_INVALID;
}

static DRV_I2S_BUFFER_OBJECT_INDEX _DRV_I2S_WriteQueueObjectIndexGet(void)
{
    DRV_I2S_BUFFER_OBJECT *queueObj;
    uint32_t index;
    SYS_INT_PROCESSOR_STATUS int_status;
    queueObj = &gDrvI2SWriteBufferQObj[0];
    for (index = 0; index < QUEUE_SIZE_TX_IDX0; index++)
    {
        int_status = SYS_INT_StatusGetAndDisable();
        if (false == queueObj->inUse)
        {
            queueObj->inUse = true;
            SYS_INT_StatusRestore(int_status);
            return index;
        }
        SYS_INT_StatusRestore(int_status);
        queueObj++;
    }
    return DRV_I2S_BUFFER_OBJECT_INDEX_INVALID;
}

/*******************************************************************************
  Function:
    void _DRV_I2S_DMA_EventHandler(SYS_DMA_TRANSFER_EVENT event,
        SYS_DMA_CHANNEL_HANDLE handle, uintptr_t contextHandle)

  Summary:
 Callback for the DMA channels

  Description:
 Callback for the DMA channels

  Remarks:
    None
 */

void _DRV_I2S_DMA_EventHandler(SYS_DMA_TRANSFER_EVENT event,
        SYS_DMA_CHANNEL_HANDLE handle, uintptr_t contextHandle)
{
    DRV_I2S_OBJ *drvObj;

    if(SYS_DMA_CHANNEL_HANDLE_INVALID == handle || 0 == handle)
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }
    drvObj = (DRV_I2S_OBJ *)contextHandle;
    if(NULL != drvObj->queueHead)
    {
        if(drvObj->queueHead->bType == DRV_I2S_BUFFER_OPERATION_TYPE_WRITEREAD)
        {
            if(drvObj->dmaChannelHandleRead == handle)
            {
                DRV_I2S_Tasks((SYS_MODULE_OBJ)drvObj);
            }
            else
            {
                ;
            }
        }
        
    }
    return;
}



void _DRV_I2S_DMA_ReadEventHandler(SYS_DMA_TRANSFER_EVENT event,
        SYS_DMA_CHANNEL_HANDLE handle, uintptr_t contextHandle)
{
    DRV_I2S_OBJ *drvObj;

    if(SYS_DMA_CHANNEL_HANDLE_INVALID == handle || 0 == handle)
        {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }
    drvObj = (DRV_I2S_OBJ *)contextHandle;
    DRV_I2S_ReadTasks((SYS_MODULE_OBJ)drvObj);
    return;
}

void _DRV_I2S_DMA_WriteEventHandler(SYS_DMA_TRANSFER_EVENT event,
        SYS_DMA_CHANNEL_HANDLE handle, uintptr_t contextHandle)
{
    DRV_I2S_OBJ *drvObj;

    if(SYS_DMA_CHANNEL_HANDLE_INVALID == handle || 0 == handle)
    {
        /* This means the handle is invalid */
        SYS_DEBUG(0, "Handle is invalid \r\n");
        return;
    }
    drvObj = (DRV_I2S_OBJ *)contextHandle;
    DRV_I2S_WriteTasks((SYS_MODULE_OBJ)drvObj);
    return;
}