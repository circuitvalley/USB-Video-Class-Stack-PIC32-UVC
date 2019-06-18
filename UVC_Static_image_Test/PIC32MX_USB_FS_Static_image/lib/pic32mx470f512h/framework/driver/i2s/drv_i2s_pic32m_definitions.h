/*******************************************************************************
  I2S PIC32M Driver Definitions Header File

  Company:
    Microchip Technology Inc.

  File Name:
    drv_i2s_pic32m_definitions.h

  Summary:
    I2S PIC32M Driver Definitions Header File

  Description:
    This file will provide enumerations and other dependencies needed by
    I2S driver to manage the I2S(SPI) module on PIC32 microcontrollers.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2015 released Microchip Technology Inc.  All rights reserved.

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
//DOM-IGNORE-END

#ifndef _DRV_I2S_PIC32M_DEFINITIONS_H
#define _DRV_I2S_PIC32M_DEFINITIONS_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

//#include "system_config.h"
#include "driver/driver_common.h"
#include "drv_i2s.h"
//#include "peripheral/usart/plib_usart.h"
//#include "system/system.h"
//#include "system/int/sys_int.h"
//#include "system/dma/sys_dma.h"

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



/******************************************************************************
  Function:
    void DRV_I2S_SetAudioCommunicationMode(const DRV_HANDLE handle, 
                                SPI_AUDIO_COMMUNICATION_WIDTH audioCommWidth);

  Summary:
    This function sets the audio communication width in I2S.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function sets the audio communication width for the I2S operation.

  Precondition:
    The DRV_I2S_Initialize routine must have been called for the specified
    I2S driver instance.

    DRV_I2S_Open must have been called to obtain a valid opened device handle.

  Parameters:
    handle          - A valid open-instance handle, returned from the driver's
                      open routine
    audioCommWidth  - The audio communication width to be set.

  Returns:
    None

  Example:
    <code>
    // myAppObj is an application specific object.
    MY_APP_OBJ myAppObj;

    uint8_t mybuffer[MY_BUFFER_SIZE];
    DRV_HANDLE handle;
	SPI_AUDIO_COMMUNICATION_WIDTH audioCommWidth = APP_INIT_AUDIO_COMMUNICATION_WIDTH;
 
  
    // myI2SHandle is the handle returned
    // by the DRV_I2S_Open function.

    // Client registers an event handler with driver. This is done once

    DRV_I2S_BufferEventHandlerSet(myI2SHandle, APP_I2SBufferEventHandle,
                                                            (uintptr_t)&myAppObj);

    // Sets the audio communication width to a new value as below
    audioCommWidth = newAudioCommWidth;
    DRV_I2S_SetAudioCommunicationMode(myI2SHandle, audioCommWidth);

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

                processedBytes = DRV_I2S_BufferProcessedSizeGet(myI2Shandle);

                break;

            default:
                break;
        }
    }
    </code>

  Remarks:
    None.
*/
void DRV_I2S_SetAudioCommunicationMode(const DRV_HANDLE handle, 
                                SPI_AUDIO_COMMUNICATION_WIDTH audioCommWidth);

// *****************************************************************************
/* I2S Driver Initialization Data

  Summary:
    Defines the data required to initialize or reinitialize the I2S driver

  Description:
    This data type defines the data required to initialize or reinitialize the
    I2S driver. If the driver is built statically, some members of this data
    structure are statically over-ridden by static overrides in the
    system_config.h file.

  Remarks:
    None.
*/
typedef struct
{
    /* System module initialization */
    SYS_MODULE_INIT moduleInit;

    /* Identifies I2S hardware module ID(PLIB-level SPI ID)
       For static build of the driver, this is overridden by
       DRV_I2S_MODULE_ID macro in system_config.h.  */
    SPI_MODULE_ID spiID;

    /* Usage Mode Type */
    DRV_I2S_MODE usageMode;

    /* Select the clock which generates the baud rate
       The options available are Peripheral Clock/
       Reference clock. */
    SPI_BAUD_RATE_CLOCK baudClock;

    /* Initial Baud Rate Value */
    uint32_t baud;

    /* Clock mode */
    DRV_I2S_CLOCK_MODE clockMode;

    /* Audio communication width */
    SPI_AUDIO_COMMUNICATION_WIDTH audioCommWidth;

    /* Audio mono/stereo */
    SPI_AUDIO_TRANSMIT_MODE audioTransmitMode;

    /* Input Sample Phase Selection */
    SPI_INPUT_SAMPLING_PHASE inputSamplePhase;

    /* Audio Protocol Mode */
    DRV_I2S_AUDIO_PROTOCOL_MODE protocolMode;

    /* Interrupt Source for Transmit Interrupt. For static build of
       the driver, this is overridden by the
       DRV_I2S_TRANSMIT_INTERRUPT_SOURCE macro in system_config.h. */
    INT_SOURCE txInterruptSource;

    /* Interrupt Source for Receive Interrupt. For static build of
       the driver, this is overridden by the
       DRV_I2S_RECEIVE_INTERRUPT_SOURCE macro in system_config.h. */
    INT_SOURCE rxInterruptSource;

    /* Interrupt Source for Error Interrupt. For static build of
       the driver, this is overridden by the
       DRV_I2S_ERROR_INTERRUPT_SOURCE macro in system_config.h. */
    INT_SOURCE errorInterruptSource;

    /* This is the transmit buffer queue size. This is the maximum
       number of write requests that driver will queue. For a
       static build of the driver, this is overridden by the
       DRV_I2S_TRANSMIT_QUEUE_SIZE macro in system_config.h. */
    uint32_t queueSizeTransmit;

    /* This is the receive buffer queue size. This is the maximum
       number of read requests that driver will queue. For a
       static build of the driver, this is overridden by the
       DRV_I2S_RECEIVE_QUEUE_SIZE macro in system_config.h. */
    uint32_t queueSizeReceive;

    /* This is the transmit DMA channel.
       A value of DMA_CHANNEL_NONE indicates DMA is not required for
       Tx. For a static build of the driver this is overridden by the
       DRV_I2S_TRANSMIT_DMA_CHANNEL macro in system_config.h. */
    DMA_CHANNEL dmaChannelTransmit;

    /* This is the transmit DMA chaining channel.
       This channel is needed when DMA is needed to be used
       channel chaining mode for Tx. Channel Chaining could be used to
       obtain high quality/resolution audio.  */
    DMA_CHANNEL dmaChaningChannelTransmit;

    /* This is the receive DMA channel.
       A value of DMA_CHANNEL_NONE indicates DMA is not required for
       Rx. For a static build of the driver this is overridden by the
       DRV_I2S_RECEIVE_DMA_CHANNEL macro in system_config.h. */
    DMA_CHANNEL dmaChannelReceive;

    /* This is the receive DMA chaining channel.
       This channel is needed when DMA is needed to be used
       channel chaining mode for Rx. Channel Chaining could be used to
       obtain high quality/resolution audio. */
    DMA_CHANNEL dmaChaningChannelReceive;

    /* This is the transmit DMA channel interrupt. This is
       applicable only if 'dmaChannelTransmit' has a valid channel number.
       This takes the interrupt source number for the corresponding
       DMA channel. */
    INT_SOURCE dmaInterruptTransmitSource;

    /* This is the transmit DMA chaining channel interrupt. This is
       applicable only if 'dmaChaningChannelTransmit' has a valid channel number.
       This takes the interrupt source number for the corresponding
       DMA chaining channel. */
    INT_SOURCE dmaInterruptChainingTransmitSource;

    /* This is the receive DMA channel interrupt. This is
       applicable only if 'dmaChannelReceive' has a valid channel number.
       This takes the interrupt source number for the corresponding
       DMA channel. */
    INT_SOURCE dmaInterruptReceiveSource;

    /* This is the receive DMA chaining channel interrupt. This is
       applicable only if 'dmaInterruptReceiveSource' has a valid channel number.
       This takes the interrupt source number for the corresponding
       DMA chaining channel. */
    INT_SOURCE dmaInterruptChainingReceiveSource;

} DRV_I2S_INIT;


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END


#endif // #ifndef _DRV_I2S_PIC32M_DEFINITIONS_H
/*******************************************************************************
 End of File
*/

