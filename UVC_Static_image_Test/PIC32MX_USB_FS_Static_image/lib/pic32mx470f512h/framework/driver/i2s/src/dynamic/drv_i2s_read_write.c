/*******************************************************************************
  I2S Driver Dynamic implementation.

  Company:
    Microchip Technology Inc.

  File Name:
    drv_i2s_read_write.c

  Summary:
    I2S Driver Dynamic Implementation read/write functions.

  Description:
    This file contains the Dynamic mode implementation of the I2S driver for
    basic read/write functions.
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

#include "../drv_i2s_local.h"

// *****************************************************************************

/*
  Function:
    size_t DRV_I2S_Read(const DRV_HANDLE handle, uint8_t *buffer,
                        const size_t numBytes)

  Summary:
    Reads data from the I2S

  Description:
    This routine reads data from the I2S. This function is blocking if the
    driver was opened by the client for blocking operation.  This function will
    not block if the driver was opened by the client for non blocking operation.
    If the ioIntent parameter at the time of opening the driver was
    DRV_IO_INTENT_BLOCKING, this function will only return when (or will block
    till) numBytes of bytes have been received or if an error occurred.

    If the ioIntent parameter at the time of opening the driver was
    DRV_IO_INTENT_NON_BLOCKING, this function will return with the number of
    bytes that were actually read. The function will not wait till numBytes of
    bytes have been read.

  Remarks:
    This function is thread safe in a RTOS application. It is recommended that
    this function not be called in I2S Driver Event Handler due to the potential
    blocking nature of the function. This function should not be
    called directly in an ISR. It should not be called in the event handler
    associated with another I2S driver instance.

 */
size_t DRV_I2S_Read(const DRV_HANDLE handle, uint8_t *buffer,
        const size_t numBytes) {
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_OBJ *drvObj;
    size_t BytesToRead;
    size_t bytesRead;
    uint8_t *tempBuffer = buffer;
    uint8_t dummy = 0xFF;

    if ((handle == DRV_HANDLE_INVALID) || (handle == 0))
    {
        /* This means the client handle parameter is invalid */
        SYS_DEBUG(SYS_ERROR_DEBUG, "Invalid client Handle \r\n");
        return 0;
    }

    /* The Client and driver objects from the handle */
    clientObj = (DRV_I2S_CLIENT_OBJ *) handle;
    drvObj = (DRV_I2S_OBJ *) clientObj->hDriver;

    if (false == clientObj->inUse)
    {
        /* Client is not a valid one */
        SYS_DEBUG(SYS_ERROR_DEBUG, "Invalid client Handle \r\n");
        return 0;
    }
    if (DRV_IO_INTENT_READ != (clientObj->ioIntent & DRV_IO_INTENT_READ))
    {
        /* This client did not open the driver for
         * writing */
        SYS_DEBUG(SYS_ERROR_DEBUG, "Driver not opened for write \r\n");
        return 0;
    }
    if ((buffer == NULL) || (numBytes == 0))
    {
        /* We have a NULL pointer or dont have
         * any data to write. */
        SYS_DEBUG(SYS_ERROR_DEBUG, "NULL data pointer or no data to write \r\n");
        return 0;
    }

    BytesToRead = numBytes;
    /* Grab the driver instance mutex */
    if(OSAL_MUTEX_Lock(&(drvObj->mutexDriverInstance), OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
    {
        /* Non-blocking mode */
        if (DRV_IO_INTENT_NONBLOCKING ==
                (clientObj->ioIntent & DRV_IO_INTENT_NONBLOCKING))
        {
            /* If there is something in the buffer object queue */
            if (drvObj->queueHead != (DRV_I2S_BUFFER_OBJECT *) NULL)
            {
                /* return immediately with number of bytes read as 0 */
                bytesRead = 0;
                return bytesRead;
            } else
            {
                /* FIFO is enabled */
                if (DRV_I2S_BUFFER_TYPE_ENHANCED == drvObj->bufferType)
                {
                    bytesRead = 0;
                    while (BytesToRead--)
                    {
                        if (false == PLIB_SPI_TransmitBufferIsEmpty(clientObj->spiID) &&
                                true == PLIB_SPI_ReceiverFIFOIsEmpty(clientObj->spiID))
                        {
                            break;
                        }

                        if (true == PLIB_SPI_TransmitBufferIsEmpty(clientObj->spiID))
                        {
                            PLIB_SPI_BufferWrite((clientObj->spiID), dummy);
#if defined (PLIB_SPI_ExistsTransmitUnderRunStatus)
                            /* Check if the last operation has caused an error condition */
                            if (true == PLIB_SPI_ExistsTransmitUnderRunStatus(clientObj->spiID))
                            {
                                if (true == PLIB_SPI_TransmitUnderRunStatusGet(clientObj->spiID))
                                {
                                    clientObj->errorInfo = DRV_I2S_ERROR_TRANSMIT_UNDERUN;
                                    if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                                    {
                                        SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                                    }
                                    return DRV_I2S_READ_ERROR;
                                }
                            }
#endif                            
                        }
                        if (false == PLIB_SPI_ReceiverFIFOIsEmpty(clientObj->spiID))
                        {
                            *tempBuffer++ = PLIB_SPI_BufferRead(clientObj->spiID);
                            bytesRead++;
                            if (true == PLIB_SPI_ReceiverHasOverflowed(clientObj->spiID))
                            {
                                clientObj->errorInfo = DRV_I2S_ERROR_RECEIVE_OVERFLOW;
                                if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                                {
                                    SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                                }
                                return DRV_I2S_READ_ERROR;
                            }
                        }
                        if (true == PLIB_SPI_FrameErrorStatusGet(clientObj->spiID))
                        {
                            clientObj->errorInfo = DRV_I2S_ERROR_FRAMING;
                            if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                            {
                                SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                            }
                            return DRV_I2S_READ_ERROR;
                        }
                    }
                } else
                {
                    bytesRead = 0;
                    /* Populate until the data transmit buffer is full
                            (In this case it should be one byte) . */
                    if (true == PLIB_SPI_TransmitBufferIsEmpty(clientObj->spiID))
                    {
                        PLIB_SPI_BufferWrite((clientObj->spiID), dummy);
#if defined (PLIB_SPI_ExistsTransmitUnderRunStatus)                        
                        /* Check if the last operation has caused an error condition */
                        if (true == PLIB_SPI_ExistsTransmitUnderRunStatus(clientObj->spiID))
                        {
                            if (true == PLIB_SPI_TransmitUnderRunStatusGet(clientObj->spiID))
                            {
                                clientObj->errorInfo = DRV_I2S_ERROR_TRANSMIT_UNDERUN;
                                if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                                {
                                    SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                                }
                                return DRV_I2S_READ_ERROR;
                            }
                        }
#endif                        
                    }
                    if (true == PLIB_SPI_ReceiverBufferIsFull(clientObj->spiID))
                    {
                        /* Read the Data */
                        *tempBuffer++ = PLIB_SPI_BufferRead(clientObj->spiID);
                        bytesRead++;
                    }
                    if (true == PLIB_SPI_ReceiverHasOverflowed(clientObj->spiID))
                    {
                        clientObj->errorInfo = DRV_I2S_ERROR_RECEIVE_OVERFLOW;
                        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                        {
                            SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                        }
                        return DRV_I2S_READ_ERROR;
                    }
                    if (true == PLIB_SPI_FrameErrorStatusGet(clientObj->spiID))
                    {
                        clientObj->errorInfo = DRV_I2S_ERROR_FRAMING;
                        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                        {
                            SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                        }
                        return DRV_I2S_READ_ERROR;
                    }

                }
            }
        }/* Blocking mode */
        else
        {
            while (drvObj->queueHead != (DRV_I2S_BUFFER_OBJECT *) NULL)
            {
                /* We block. Because some data transfer is
                 happening in buffer queue object */
                if (OSAL_SEM_Pend(&(drvObj->semBufferQueueEmpty), OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
                {
                    /* This means we were pending on the semaphore
                     * and we got the semaphore. This only happens
                     * when the ISR has posted the semaphore when
                     * the queue becomes empty. We dont do anything
                     * because the code will check if the queue is
                     * still empty and then proceed */
                }
                else
                {
                    /* Failed to get the semaphore due to a time out.
                     * We should return the mutex that we grabbed and then
                     * return transfer failed. */
                    if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                    {
                        SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                    }
                    return DRV_I2S_WRITE_ERROR;
                }
            }
            bytesRead = BytesToRead;
            /* FIFO is enabled */
            if (DRV_I2S_BUFFER_TYPE_ENHANCED == drvObj->bufferType)
            {
                while (BytesToRead)
                {
                    /* Populate until the data transmit buffer is full*/
                    while (true == PLIB_SPI_TransmitBufferIsEmpty(clientObj->spiID))
                    {
                        /* This is dummy write to get the read working */
                        PLIB_SPI_BufferWrite((clientObj->spiID), dummy);
#if defined (PLIB_SPI_ExistsTransmitUnderRunStatus)                        
                        /* Check if the last operation has caused an error condition */
                        if (true == PLIB_SPI_ExistsTransmitUnderRunStatus(clientObj->spiID))
                        {
                            if (true == PLIB_SPI_TransmitUnderRunStatusGet(clientObj->spiID))
                            {
                                clientObj->errorInfo = DRV_I2S_ERROR_TRANSMIT_UNDERUN;
                                clientObj->errorInfo = DRV_I2S_ERROR_TRANSMIT_UNDERUN;
                                if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                                {
                                    SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                                }
                                return DRV_I2S_READ_ERROR;
                            }
                        }
#endif                        
                    }
                    while (false == PLIB_SPI_ReceiverFIFOIsEmpty(clientObj->spiID))
                    {
                        *tempBuffer++ = PLIB_SPI_BufferRead(clientObj->spiID);
                        BytesToRead--;
                        if (true == PLIB_SPI_ReceiverHasOverflowed(clientObj->spiID))
                        {
                            clientObj->errorInfo = DRV_I2S_ERROR_RECEIVE_OVERFLOW;
                            if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                            {
                                SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                            }
                            return DRV_I2S_READ_ERROR;
                        }
                    }
                    if (true == PLIB_SPI_FrameErrorStatusGet(clientObj->spiID))
                    {
                        clientObj->errorInfo = DRV_I2S_ERROR_FRAMING;
                        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                        {
                            SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                        }
                        return DRV_I2S_READ_ERROR;
                    }
                }
            }
            else
            {
                while (BytesToRead)
                {
                    /* Populate until the data transmit buffer is full
                            (In this case it should be one byte) . */
                    while (true == PLIB_SPI_TransmitBufferIsEmpty(clientObj->spiID))
                    {
                        PLIB_SPI_BufferWrite((clientObj->spiID), dummy);
#if defined (PLIB_SPI_ExistsTransmitUnderRunStatus)                        
                        /* Check if the last write has caused an error condition */
                        if (true == PLIB_SPI_ExistsTransmitUnderRunStatus(clientObj->spiID))
                        {
                            if (true == PLIB_SPI_TransmitUnderRunStatusGet(clientObj->spiID))
                            {
                                clientObj->errorInfo = DRV_I2S_ERROR_TRANSMIT_UNDERUN;
                                if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                                {
                                    SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                                }
                                return DRV_I2S_READ_ERROR;
                            }
                        }
#endif                        
                    }
                    /* Wait until the data is received back */
                    while (false == PLIB_SPI_ReceiverBufferIsFull(clientObj->spiID))
                    {
                        ;
                    }
                    /* Read the Data */
                    *tempBuffer++ = PLIB_SPI_BufferRead(clientObj->spiID);
                    BytesToRead--;
                    if (true == PLIB_SPI_ReceiverHasOverflowed(clientObj->spiID))
                    {
                        clientObj->errorInfo = DRV_I2S_ERROR_RECEIVE_OVERFLOW;
                        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                        {
                            SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                        }
                        return DRV_I2S_READ_ERROR;
                    }

                    if (true == PLIB_SPI_FrameErrorStatusGet(clientObj->spiID))
                    {
                        clientObj->errorInfo = DRV_I2S_ERROR_FRAMING;
                        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                        {
                            SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                        }
                        return DRV_I2S_READ_ERROR;
                    }
                }
            }
        }
        /* Release mutex */
        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
        {
            SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
        }
    }
    else
    {
        /* Write mutex timed out. Set bytesRead to zero. */
        bytesRead = 0;

    }
    return bytesRead;
}

// *****************************************************************************

/*
  Function:
    ssize_t DRV_I2S_Write( const DRV_HANDLE handle,  void * buffer,
                        const size_t numbytes)

  Summary:
    Writes data to the I2S

  Description:
    This routine writes data to the I2S. This function is blocking if the
    driver was opened by the client for blocking operation.  This function will
    not block if the driver was opened by the client for non blocking operation.
    If the ioIntent parameter at the time of opening the driver was
    DRV_IO_INTENT_BLOCKING, this function will only return when (or will block
    till) numbytes of bytes have been transmitted or if an error occurred.

    If the ioIntent parameter at the time of opening the driver was
    DRV_IO_INTENT_NON_BLOCKING, this function will return with the number of
    bytes that were actually accepted for transmission. The function will not
    wait till numBytes of bytes have been transmitted.

  Remarks:
    This function is thread safe in a RTOS application. It is recommended that
    this function not be called in I2S Driver Event Handler due to the potential
    blocking nature of the function. This function should not be
    called directly in an ISR. It should not be called in the event handler
    associated with another USART driver instance.

 */
size_t DRV_I2S_Write(const DRV_HANDLE handle, uint8_t *buffer,
        const size_t numBytes)
{
    DRV_I2S_CLIENT_OBJ *clientObj;
    DRV_I2S_OBJ *drvObj;
    size_t BytesToWrite;
    size_t bytesWritten;
    size_t requestReadResponse;
    uint8_t *tempBuffer = buffer, dummy;

    if ((handle == DRV_HANDLE_INVALID) || (handle == 0))
    {
        /* This means the client handle parameter is invalid */
        SYS_DEBUG(SYS_ERROR_DEBUG, "Invalid client Handle \r\n");
        return 0;
    }

    /* The Client and driver objects from the handle */
    clientObj = (DRV_I2S_CLIENT_OBJ *) handle;
    drvObj = (DRV_I2S_OBJ *) clientObj->hDriver;

    if (false == clientObj->inUse)
    {
        /* Client is not a valid one */
        SYS_DEBUG(SYS_ERROR_DEBUG, "Invalid client Handle \r\n");
        return 0;
    }
    if (DRV_IO_INTENT_WRITE != (clientObj->ioIntent & DRV_IO_INTENT_WRITE))
    {
        /* This client did not open the driver for
         * writing */
        SYS_DEBUG(SYS_ERROR_DEBUG, "Driver not opened for write \r\n");
        return 0;
    }
    if ((buffer == NULL) || (numBytes == 0))
    {
        /* We have a NULL pointer or dont have
         * any data to write. */
        SYS_DEBUG(SYS_ERROR_DEBUG, "NULL data pointer or no data to write \r\n");
        return 0;
    }

    BytesToWrite = numBytes;

    /* Grab the driver instance mutex */
    if(OSAL_MUTEX_Lock(&(drvObj->mutexDriverInstance), OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
    {
        /* Non-blocking mode */
        if (DRV_IO_INTENT_NONBLOCKING ==
                (clientObj->ioIntent & DRV_IO_INTENT_NONBLOCKING))
        {
            if (drvObj->queueHead != (DRV_I2S_BUFFER_OBJECT *) NULL)
            {
                /* return immediately with number of bytes read as 0 */
                bytesWritten = 0;
                return bytesWritten;
            }
            else
            {
                if (DRV_I2S_BUFFER_TYPE_ENHANCED == drvObj->bufferType)
                {
                    bytesWritten = 0;
                    while (BytesToWrite) {
                        if (false == PLIB_SPI_TransmitBufferIsFull(clientObj->spiID))
                        {
                            PLIB_SPI_BufferWrite((clientObj->spiID), *tempBuffer++);
                            BytesToWrite--;
                        }
                        else
                        {
                            break;
                        }
                        if (false == PLIB_SPI_ReceiverFIFOIsEmpty(clientObj->spiID))
                        {
                            dummy = PLIB_SPI_BufferRead(clientObj->spiID);
                            bytesWritten++;
                        }
                    }
                    if (false == drvObj->ignoreTxUnderrun)
                    {
#if defined (PLIB_SPI_ExistsTransmitUnderRunStatus)                        
                        /* Check if the last operation has caused an error condition */
                        if (true == PLIB_SPI_ExistsTransmitUnderRunStatus(clientObj->spiID))
                        {
                            if (true == PLIB_SPI_TransmitUnderRunStatusGet(clientObj->spiID))
                            {
                                clientObj->errorInfo = DRV_I2S_ERROR_TRANSMIT_UNDERUN;
                                if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                                {
                                    SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                                }
                                return DRV_I2S_WRITE_ERROR;
                            }
                        }
#endif
                    }
                    if (false == drvObj->ignoreRxOverflow)
                    {
                        if (true == PLIB_SPI_ReceiverHasOverflowed(clientObj->spiID))
                        {
                            clientObj->errorInfo = DRV_I2S_ERROR_RECEIVE_OVERFLOW;
                            if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                            {
                                SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                            }
                            return DRV_I2S_WRITE_ERROR;
                        }
                    }
                    if (true == PLIB_SPI_FrameErrorStatusGet(clientObj->spiID))
                    {
                        clientObj->errorInfo = DRV_I2S_ERROR_FRAMING;
                        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                        {
                            SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                        }
                        return DRV_I2S_WRITE_ERROR;
                    }
                }
                else
                {
                    bytesWritten = 0;

                    /* Populate until the data transmit buffer is full
                    (In this case it should be one byte) . */
                    if (true == PLIB_SPI_TransmitBufferIsEmpty(clientObj->spiID))
                    {
                        PLIB_SPI_BufferWrite((clientObj->spiID), *tempBuffer++);
                    }
                    if (true == PLIB_SPI_ReceiverBufferIsFull(clientObj->spiID))
                    {
                        /* Read the Data */
                        dummy = PLIB_SPI_BufferRead(clientObj->spiID);
                        bytesWritten++;
                    }

                    if (false == drvObj->ignoreTxUnderrun)
                    {
#if defined (PLIB_SPI_ExistsTransmitUnderRunStatus)                        
                        /* Check if the last operation has caused an error condition */
                        if (true == PLIB_SPI_ExistsTransmitUnderRunStatus(clientObj->spiID))
                        {
                            if (true == PLIB_SPI_TransmitUnderRunStatusGet(clientObj->spiID))
                            {
                                clientObj->errorInfo = DRV_I2S_ERROR_TRANSMIT_UNDERUN;
                                if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                                {
                                    SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                                }
                                return DRV_I2S_WRITE_ERROR;
                            }
                        }
#endif                        
                    }
                    if (false == drvObj->ignoreRxOverflow)
                    {
                        if (true == PLIB_SPI_ReceiverHasOverflowed(clientObj->spiID))
                        {
                            clientObj->errorInfo = DRV_I2S_ERROR_RECEIVE_OVERFLOW;
                            if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                            {
                                SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                            }
                            return DRV_I2S_WRITE_ERROR;
                        }
                    }
                    if (true == PLIB_SPI_FrameErrorStatusGet(clientObj->spiID))
                    {
                        clientObj->errorInfo = DRV_I2S_ERROR_FRAMING;
                        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                        {
                            SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                        }
                        return DRV_I2S_WRITE_ERROR;
                    }
                }
            }
        }/* Blocking mode */
        else
        {
            while (drvObj->queueHead != (DRV_I2S_BUFFER_OBJECT *) NULL)
            {
                /* We block. Because some data transfer is
                 happening in buffer queue object */
                if (OSAL_SEM_Pend(&(drvObj->semBufferQueueEmpty), OSAL_WAIT_FOREVER) == OSAL_RESULT_TRUE)
                {
                    /* This means we were pending on the semaphore
                     * and we got the semaphore. This only happens
                     * when the ISR has posted the semaphore when
                     * the queue becomes empty. We dont do anything
                     * because the code will check if the queue is
                     * still empty and then proceed */
                }
                else
                {
                    /* Failed to get the semaphore due to a time out.
                     * We should return the mutex that we grabbed and then
                     * return transfer failed. */
                    if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                    {
                        SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                    }
                    return DRV_I2S_WRITE_ERROR;
                }
            }
            bytesWritten = BytesToWrite;
            /* FIFO is enabled */
            if (DRV_I2S_BUFFER_TYPE_ENHANCED == drvObj->bufferType)
            {
                while (BytesToWrite) {
                    /* Populate until the data transmit buffer is full*/
                    while (true == PLIB_SPI_TransmitBufferIsEmpty(clientObj->spiID))
                    {
                        PLIB_SPI_BufferWrite((clientObj->spiID), *tempBuffer++);
                    }
                    while (false == PLIB_SPI_ReceiverFIFOIsEmpty(clientObj->spiID))
                    {
                        dummy = PLIB_SPI_BufferRead(clientObj->spiID);
                        BytesToWrite--;
                    }
                    if (false == drvObj->ignoreTxUnderrun)
                    {
#if defined (PLIB_SPI_ExistsTransmitUnderRunStatus)                        
                        /* Check if the last operation has caused an error condition */
                        if (true == PLIB_SPI_ExistsTransmitUnderRunStatus(clientObj->spiID))
                        {
                            if (true == PLIB_SPI_TransmitUnderRunStatusGet(clientObj->spiID))
                            {
                                clientObj->errorInfo = DRV_I2S_ERROR_TRANSMIT_UNDERUN;
                                if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                                {
                                    SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                                }
                                return DRV_I2S_WRITE_ERROR;
                            }
                        }
#endif                        
                    }
                    if (false == drvObj->ignoreRxOverflow)
                    {
                        if (true == PLIB_SPI_ReceiverHasOverflowed(clientObj->spiID))
                        {
                            clientObj->errorInfo = DRV_I2S_ERROR_RECEIVE_OVERFLOW;
                            if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                            {
                                SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                            }
                            return DRV_I2S_WRITE_ERROR;
                        }
                    }
                    if (true == PLIB_SPI_FrameErrorStatusGet(clientObj->spiID))
                    {
                        clientObj->errorInfo = DRV_I2S_ERROR_FRAMING;
                        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                        {
                            SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                        }
                        return DRV_I2S_WRITE_ERROR;
                    }

                }
            }
            else
            {
                while (BytesToWrite)
                {
                    requestReadResponse = 0;

                    /* Populate until the data transmit buffer is full
                            (In this case it should be one byte) . */
                    while (true == PLIB_SPI_TransmitBufferIsEmpty(clientObj->spiID))
                    {
                        PLIB_SPI_BufferWrite((clientObj->spiID), *tempBuffer++);
                    }
                    /* Wait until the data is received back */
                    while (false == PLIB_SPI_ReceiverBufferIsFull(clientObj->spiID))
                    {
                        ;
                    }
                    /* Read the Data */
                    dummy = PLIB_SPI_BufferRead(clientObj->spiID);
                    BytesToWrite--;
                    if (false == drvObj->ignoreTxUnderrun) {
#if defined (PLIB_SPI_ExistsTransmitUnderRunStatus)                        
                        /* Check if the last operation has caused an error condition */
                        if (true == PLIB_SPI_ExistsTransmitUnderRunStatus(clientObj->spiID))
                        {
                            if (true == PLIB_SPI_TransmitUnderRunStatusGet(clientObj->spiID))
                            {
                                clientObj->errorInfo = DRV_I2S_ERROR_TRANSMIT_UNDERUN;
                                if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                                {
                                    SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                                }
                                return DRV_I2S_WRITE_ERROR;
                            }
                        }
#endif                        
                    }
                    if (false == drvObj->ignoreRxOverflow)
                    {
                        if (true == PLIB_SPI_ReceiverHasOverflowed(clientObj->spiID))
                        {
                            clientObj->errorInfo = DRV_I2S_ERROR_RECEIVE_OVERFLOW;
                            if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                            {
                                SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                            }
                            return DRV_I2S_WRITE_ERROR;
                        }
                    }
                    if (true == PLIB_SPI_FrameErrorStatusGet(clientObj->spiID))
                    {
                        clientObj->errorInfo = DRV_I2S_ERROR_FRAMING;
                        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
                        {
                            SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
                        }
                        return DRV_I2S_WRITE_ERROR;
                    }

                }
            }
        }
        /* Release mutex */
        if((OSAL_MUTEX_Unlock(&(drvObj->mutexDriverInstance))) != OSAL_RESULT_TRUE)
        {
            SYS_DEBUG(0, "Unable to unlock buffer add  mutex \r\n");
        }
    }
    else
    {
        /* Write mutex timed out. Set bytesWritten to zero. */
        bytesWritten = 0;
    }
    return bytesWritten;

}


