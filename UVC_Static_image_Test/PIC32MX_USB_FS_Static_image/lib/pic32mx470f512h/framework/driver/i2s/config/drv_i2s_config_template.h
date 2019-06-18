/*******************************************************************************
 I2S Driver Configuration Template

  Company:
    Microchip Technology Inc.

  File Name:
    drv_i2s_config_template.h

  Summary:
    I2S Driver Configuration Template.

  Description:
    These file provides the list of all the configurations that can be used with
    the driver. This file should not be included in the driver.

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
// DOM-IGNORE-END

#ifndef _DRV_I2S_CONFIG_TEMPLATE_H
#define _DRV_I2S_CONFIG_TEMPLATE_H

//DOM-IGNORE-BEGIN
#error "This is a configuration template file.  Do not include it directly."
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Core Functionality Configuration Options
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* I2S driver objects configuration

  Summary
    Sets up the maximum number of hardware instances that can be supported

  Description
    Sets up the maximum number of hardware instances that can be supported.
    It is recommended that this number be set exactly equal to the number of
    I2S modules that are needed by the application. Hardware Instance
    support consumes RAM memory space.
    If this macro is not defined, then the driver will be built statically.

  Remarks:
    None
*/

#define DRV_I2S_INSTANCES_NUMBER


// *****************************************************************************
/* I2S Client Count Configuration

  Summary
    Sets up the maximum number of clients that can be connected to any hardware
    instance.

  Description
    Sets up the maximum number of clients that can be connected to any hardware
    instance. This value represents the total number of clients to be supported
    across all hardware instances. So if I2S1 will be accessed by 2 clients
    and I2S2 will accessed by 3 clients, then this number should be 5.
    It is recommended that this be set exactly equal to the number of expected
    clients. Client support consumes RAM memory space.
    If this macro is not defined and the DRV_I2S_INSTANCES_NUMBER macro is not
    defined, then the driver will be built for static - single client operation.
    If this macro is defined and the DRV_I2S_INSTANCES_NUMBER macro is not
    defined, then the driver will be built for static - multi client operation.

  Remarks:
    None
*/

#define DRV_I2S_CLIENTS_NUMBER

// *****************************************************************************
/* I2S Interrupt Mode Operation Control

  Summary:
    Macro controls interrupt based operation of the driver

  Description:
    This macro controls the interrupt based operation of the driver. The
    possible values it can take are
    - true - Enables the interrupt mode
    - false - Enables the polling mode
    If the macro value is true, then Interrupt Service Routine for the
    interrupt should be defined in the application. The DRV_I2S_Tasks()
    routine should be called in the ISR.

*/

#define DRV_I2S_INTERRUPT_MODE

// *****************************************************************************
/* I2S Driver Buffer Queue Entries

  Summary:
    Number of entries of all queues in all instances of the driver.

  Description:
    This macro defined the number of entries of all queues in all instances of
    the driver.

    Each hardware instance supports a buffer queue for transmit and receive
    operations. The size of queue is specified either in driver
    initialization (for dynamic build) or by macros (for static build). The
    hardware instance transmit buffer queue will queue transmit buffers
    submitted by the DRV_I2S_BufferAddWrite() function.  The hardware instance
    receive buffer queue will queue receive buffers submitted by the
    DRV_I2S_BufferAddRead() function.

    A buffer queue will contains buffer queue entries, each related to a
    BufferAdd request.  This configuration macro defines total number of buffer
    entries that will be available for use between all I2S driver hardware
    instances. The buffer queue entries are allocated to individual hardware
    instances as requested by hardware instances. Once the request is processed,
    the buffer queue entry is free for use by other hardware instances.

    The total number of buffer entries in the system determines the ability of
    the driver to service non blocking read and write requests. If a free buffer
    entry is not available, the driver will not add the request and will return
    an invalid buffer handle. More the number of buffer entries, greater the
    ability of the driver to service and add requests to its queue. A hardware
    instance additionally can queue up as many buffer entries as  specified by
    its transmit and receive buffer queue size.

    As an example, consider the case of static single client driver application
    where full duplex non blocking operation is desired without queuing, the
    minimum transmit queue depth and minimum receive queue depth should be 1.
    Hence the total number of buffer entries should be 2.

    As an example, consider the case of a dynamic driver (say 2 instances) where
    instance 1 will queue up to 3 write requests and up to 2 read requests, and
    instance 2 will queue up to 2 write requests and up to 6 read requests, the
    value of this macro should be 13 (2 + 3 + 2 + 6).

  Note:
    The maximum combined queue depth should not be greater than 0xFFFF(ie 65535)
*/

#define  DRV_I2S_QUEUE_DEPTH_COMBINED


// *****************************************************************************
/* I2S driver objects configuration

  Summary
    Identifies whether the driver should stop operations in stop in Idle mode.

  Description
    Identifies whether the driver should stop operations in stop in Idle mode.
    true - Indicates stop in idle mode.
    false - Indicates do not stop in Idle mode.

  Remarks:
    None
*/

#define DRV_I2S_STOP_IN_IDLE

// *****************************************************************************
// *****************************************************************************
// Section: Static Overrides
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
/* Index - Used for static drivers

  Summary:
    I2S Static Index selection

  Description:
    I2S Static Index selection for the driver object reference. This macro
    defines the driver index in case of static and static multi-client
    build. For example, if this macro is set to DRV_I2S_INDEX_2, then
    static driver APIs would be DRV_I2S2_Initialize(), DRV_I2S2_Open() etc.
    When building static drivers, this macro should be different for
    each static build of the I2S driver that needs to be included in the
    project.

  Remarks:
    This index is required to make a reference to the driver object

*/

#define DRV_I2S_INDEX


// *****************************************************************************
/* I2S Peripheral Library Module ID

  Summary:
    Configures the I2S PLIB Module ID

  Description:
    This macro configures the PLIB ID if the driver is built statically. This
    value will override the I2SID member of the DRV_I2S_INIT initialization
    data structure. In that when the driver is built statically, the
    I2SID member of the DRV_I2S_INIT data structure will be ignored by the
    driver initialization routine and this macro will be considered. This should
    be set to the PLIB ID of I2S module (I2S_ID_1, I2S_ID_2 and so on).
*/

#define DRV_I2S_PERIPHERAL_ID

// *****************************************************************************
/* Transmit Interrupt Source

  Summary:
    Macro to define the Transmit interrupt source in case of static driver

  Description:
    Macro to define the TX interrupt source in case of static driver. The
    interrupt source defined by this macro will override the txInterruptSource
    member of the DRV_I2S_INIT initialization data structure in the driver
    initialization routine. This value should be set to the I2S module
    transmit interrupt enumeration in the Interrupt PLIB for the
    microcontroller.

  Remarks:
    None.

*/

#define DRV_I2S_INTERRUPT_SOURCE_TRANSMIT


// *****************************************************************************
/* Receive Interrupt Source

  Summary:
    Macro to define the Receive interrupt source in case of static driver

  Description:
    Macro to define the Receive interrupt source in case of static driver. The
    interrupt source defined by this macro will override the rxInterruptSource
    member of the DRV_I2S_INIT initialization data structure in the driver
    initialization routine. This value should be set to the I2S module
    receive interrupt enumeration in the Interrupt PLIB for the
    microcontroller.

  Remarks:
    None.


*/

#define DRV_I2S_INTERRUPT_SOURCE_RECEIVE

// *****************************************************************************
/* Error Interrupt Source

  Summary:
    Defines the interrupt source for the error interrupt

  Description:
    Macro to define the Error interrupt source in case of static driver. The
    interrupt source defined by this macro will override the errorInterruptSource
    member of the DRV_I2S_INIT initialization data structure in the driver
    initialization routine. This value should be set to the I2S module error
    interrupt enumeration in the Interrupt PLIB for the microcontroller.
*/

#define DRV_I2S_INTERRUPT_SOURCE_ERROR


// *****************************************************************************
/* I2S Driver Receive DMA Channel

  Summary:
    Macro to defines the I2S Driver Receive DMA Channel  in case of static
    driver

  Description:
    Macro to define the I2S Receive DMA Channel  in case of static driver. The
    DMA channel defined by this macro will override the dmaChannelReceive member
    of the DRV_I2S_INIT initialization data structure in the driver
    initialization routine. This value should be set to the DMA channel in the
    DMA PLIB for the microcontroller.

  Remarks:
    None.

*/

#define DRV_I2S_RECEIVE_DMA_CHANNEL

// *****************************************************************************
/* I2S Driver Receive DMA Chaining Channel

  Summary:
    Macro to defines the I2S Driver Receive DMA Chaining Channel in case of static
    driver

  Description:
    Macro to define the I2S Receive DMA Chaining Channel  in case of static driver. The
    DMA channel defined by this macro will override the dmaChaningChannelReceive member
    of the DRV_I2S_INIT initialization data structure in the driver
    initialization routine. This value should be set to the DMA channel in the
    DMA PLIB for the microcontroller.

  Remarks:
    None.

*/

#define DRV_I2S_RECEIVE_DMA_CHAINING_CHANNEL


// *****************************************************************************
/* I2S Driver Transmit DMA Channel

  Summary:
    Macro to defines the I2S Driver Transmit DMA Channel  in case of static
    driver

  Description:
    Macro to define the I2S Transmit DMA Channel  in case of static driver. The
    DMA channel defined by this macro will override the dmaChannelTransmit member
    of the DRV_I2S_INIT initialization data structure in the driver
    initialization routine. This value should be set to the DMA channel in the
    DMA PLIB for the microcontroller.

  Remarks:
    None.

*/

#define DRV_I2S_TRANSMIT_DMA_CHANNEL


// *****************************************************************************
/* I2S Driver Transmit DMA Chaining Channel

  Summary:
    Macro to defines the I2S Driver Transmit DMA Chaining Channel  in case of static
    driver

  Description:
    Macro to define the I2S Transmit DMA Chaining Channel in case of static driver. The
    DMA channel defined by this macro will override the dmaChaningChannelTransmit member
    of the DRV_I2S_INIT initialization data structure in the driver
    initialization routine. This value should be set to the DMA channel in the
    DMA PLIB for the microcontroller.

  Remarks:
    None.

*/
DRV_I2S_TRANSMIT_DMA_CHAINING_CHANNEL


// *****************************************************************************
/* i2s Baud Rate Multiplier

  Summary:
    Identifies the multiplier to be applied to baud rate to generate the
    i2s master clock to be provided to the clients

  Description:
    Identifies the multiplier to be applied to baud rate to generate the
    i2s master clock to be provided to the clients

	Various supported baud rate multipliers are as follows
    128fs, 192fs, 256fs, 384fs, 512fs, 768fs or 1152fs
  Remarks:
    None
*/
#define DRV_I2S_BAUD_RATE_MULTIPLIER


// *****************************************************************************
/* i2s bit clock divisor

  Summary:
    Identifies the divisor to the master clock to produce the desired
    BCLK for the given baud rate.

  Description:
    Sets up the BCLK to LRCK Ratio to Generate Audio Stream for 32, 44.1 and 48K
    I2S sampling frequency

    Following BCLK divisor values are supported
    1
    2
    4
    8

  Remarks:
    None.
*/
#define DRV_I2S_BCLK_BIT_CLK_DIVISOR



#endif // #ifndef _DRV_I2S_CONFIG_TEMPLATE_H

/*******************************************************************************
 End of File
*/
