/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
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


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "usb/usb_video.h"
#include "nv12_picture.c"
#include "system_config.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/
extern uint8_t stream_state ;
APP_DATA appData;

/* Receive data buffer */
uint8_t receivedDataBuffer[APP_READ_BUFFER_SIZE] APP_MAKE_BUFFER_DMA_READY;

/* Transmit data buffer */
uint8_t  transmitDataBuffer[APP_READ_BUFFER_SIZE] APP_MAKE_BUFFER_DMA_READY;

/* The endpoint size is 64 for FS and 512 for HS */
uint16_t endpointSize;
                
typedef struct  _VideoControl{
    uint8_t    bmHint[2];                      // 2
    uint8_t    bFormatIndex[1];                // 3
    uint8_t    bFrameIndex[1];                 // 4
    uint8_t    dwFrameInterval[4];             // 8
    uint8_t    wKeyFrameRate[2];               // 10
    uint8_t    wPFrameRate[2];                 // 12
    uint8_t    wCompQuality[2];                // 14
    uint8_t    wCompWindowSize[2];             // 16
    uint8_t    wDelay[2];                      // 18
    uint8_t    dwMaxVideoFrameSize[4];         // 22
    uint8_t    dwMaxPayloadTransferSize[4];    // 26
    uint8_t    dwClockFrequency[4];
    uint8_t    bmFramingInfo[1];
    uint8_t    bPreferedVersion[1];
    uint8_t    bMinVersion[1];
    uint8_t    bMaxVersion[1];
}VideoControl;
                

                //data array for Video Probe and Commit
VideoControl    videoCommitControl =
{
  {0x00,0x00},                      // bmHint
  {0x01},                           // bFormatIndex
  {0x01},                           // bFrameIndex
  {DBVAL(INTERVAL)},          // dwFrameInterval
  {0x00,0x00,},                     // wKeyFrameRate
  {0x00,0x00,},                     // wPFrameRate
  {0x00,0x00,},                     // wCompQuality
  {0x00,0x00,},                     // wCompWindowSize
  {0x00,0x00},                      // wDelay
  {DBVAL(MAX_FRAME_SIZE)},    // dwMaxVideoFrameSize
  {0x00, 0x00, 0x00, 0x00},         // dwMaxPayloadTransferSize
  {0x00, 0x00, 0x00, 0x00},         // dwClockFrequency
  {0x00},                           // bmFramingInfo
  {0x00},                           // bPreferedVersion
  {0x00},                           // bMinVersion
  {0x00},                           // bMaxVersion
};

VideoControl    videoProbeControl =
{
  {0x00,0x00},                      // bmHint
  {0x01},                           // bFormatIndex
  {0x01},                           // bFrameIndex
  {DBVAL(INTERVAL)},          // dwFrameInterval
  {0x00,0x00,},                     // wKeyFrameRate
  {0x00,0x00,},                     // wPFrameRate
  {0x00,0x00,},                     // wCompQuality
  {0x00,0x00,},                     // wCompWindowSize
  {0x00,0x00},                      // wDelay
  {DBVAL(MAX_FRAME_SIZE)},    // dwMaxVideoFrameSize
  {0x00, 0x00, 0x00, 0x00},         // dwMaxPayloadTransferSize
  {0x00, 0x00, 0x00, 0x00},         // dwClockFrequency
  {0x00},                           // bmFramingInfo
  {0x00},                           // bPreferedVersion
  {0x00},                           // bMinVersion
  {0x00},                           // bMaxVersion
};
// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************
//=============================================================================
// APP_USBDeviceVideoEventHandler()
//=============================================================================

void APP_USBDeviceVideoEventHandler
(
    USB_DEVICE_VIDEO_INDEX iVideo ,
    USB_DEVICE_VIDEO_EVENT event ,
    void * pData,
    uintptr_t context
)
{
   // volatile USB_DEVICE_VIDEO_EVENT_DATA_INTERFACE_SETTING_CHANGED *interfaceInfo;
    //volatile USB_DEVICE_VIDEO_EVENT_DATA_READ_COMPLETE *readEventData;
   // USB_DEVICE_VIDEO_EVENT_DATA_WRITE_COMPLETE *writeEventData;
    volatile uint8_t entityID = 0;
    volatile uint8_t controlSelector =0 ;

        entityID = entityID +1 + controlSelector;   

    //volatile uint8_t index;

    if ( iVideo == 0 )
    {
        switch (event)
        {
            case USB_DEVICE_VIDEO_EVENT_INTERFACE_SETTING_CHANGED:
            {
                /* We have received a request from USB host to change the Interface-
                 Alternate setting.*/
                USB_DEVICE_VIDEO_EVENT_DATA_INTERFACE_SETTING_CHANGED *interfaceInfo = (USB_DEVICE_VIDEO_EVENT_DATA_INTERFACE_SETTING_CHANGED *)pData;
                if(interfaceInfo->interfaceAlternateSetting == 1)
                {
                    
                    BSP_LEDOn(BSP_LED_1);
                    appData.state = APP_STATE_READY_TO_STREAM;
                }else
                {
                    BSP_LEDOff(BSP_LED_1);
                    appData.state = APP_STATE_IDLE;
                }
              break;
            }
            case USB_DEVICE_VIDEO_EVENT_READ_COMPLETE:             
            break;
            case USB_DEVICE_VIDEO_EVENT_WRITE_COMPLETE:
            {
                
                static uint8_t packet[1023];
                static uint8_t frame_toggle=0;
                static uint16_t picture_index=0;
                volatile uint16_t tosend = min(sizeof(yuy2_picture0) - picture_index, 1023 - 2);

                memcpy(packet + 2, yuy2_picture0 + picture_index, tosend);
                
                packet[0] = 0x2; //header length 
                packet[1] = frame_toggle; //toggle frame bit
                picture_index = picture_index + tosend;
                if (tosend < (1023-2))
                {
                    picture_index = 0;
                    frame_toggle ^= 1;
                }
                
                USB_DEVICE_VIDEO_Write(USB_DEVICE_INDEX_0, 
                        &appData.writeTransferHandle1, 
                        1 ,(void *)packet,  
                        tosend+2);      
            }
            break;
            case USB_DEVICE_VIDEO_EVENT_CONTROL_SET_MIN:
            case USB_DEVICE_VIDEO_EVENT_CONTROL_SET_CUR:
            case USB_DEVICE_VIDEO_EVENT_CONTROL_SET_MAX:
                
                TRISDbits.TRISD0 = 0;
                
                if(((USB_VIDEO_CONTROL_INTERFACE_REQUEST*)pData)->wValue ==256 )
                {
                    USB_DEVICE_ControlReceive(appData.usbDevHandle, (void *)&videoProbeControl,((USB_VIDEO_CONTROL_INTERFACE_REQUEST*)pData)->wLength);
                }
                else if (  ((USB_VIDEO_CONTROL_INTERFACE_REQUEST*)pData)->wValue == 512  )
                {
                    USB_DEVICE_ControlReceive(appData.usbDevHandle, (void *)&videoCommitControl,((USB_VIDEO_CONTROL_INTERFACE_REQUEST*)pData)->wLength);
                }
                break;
            case USB_DEVICE_VIDEO_EVENT_CONTROL_GET_DEF:
                      if (((USB_VIDEO_CONTROL_INTERFACE_REQUEST*)pData)->wValue ==0x1400 )
                {
                    USB_DEVICE_ControlSend(appData.usbDevHandle, (void *)&videoProbeControl,((USB_VIDEO_CONTROL_INTERFACE_REQUEST*)pData)->wLength);
                }
                else if (  ((USB_VIDEO_CONTROL_INTERFACE_REQUEST*)pData)->wValue == 512  )
                {
                    USB_DEVICE_ControlSend(appData.usbDevHandle, (void *)&videoCommitControl,((USB_VIDEO_CONTROL_INTERFACE_REQUEST*)pData)->wLength);
                }
                break;
            case USB_DEVICE_VIDEO_EVENT_CONTROL_GET_MAX:
            case USB_DEVICE_VIDEO_EVENT_CONTROL_GET_MIN:
            case USB_DEVICE_VIDEO_EVENT_CONTROL_GET_CUR:
                if (((USB_VIDEO_CONTROL_INTERFACE_REQUEST*)pData)->wValue ==256 )
                {
                    USB_DEVICE_ControlSend(appData.usbDevHandle, (void *)&videoProbeControl,((USB_VIDEO_CONTROL_INTERFACE_REQUEST*)pData)->wLength);
                }
                else if (  ((USB_VIDEO_CONTROL_INTERFACE_REQUEST*)pData)->wValue == 512  )
                {
                    USB_DEVICE_ControlSend(appData.usbDevHandle, (void *)&videoCommitControl,((USB_VIDEO_CONTROL_INTERFACE_REQUEST*)pData)->wLength);
                }
                break;
            case USB_DEVICE_VIDEO_EVENT_CONTROL_SET_RES:
            case USB_DEVICE_VIDEO_EVENT_CONTROL_GET_RES:
                break;
            case USB_DEVICE_VIDEO_EVENT_ENTITY_GET_MEM:
                /* Stall request */
                USB_DEVICE_ControlStatus (appData.usbDevHandle, USB_DEVICE_CONTROL_STATUS_ERROR);
            break;
            case USB_DEVICE_VIDEO_EVENT_CONTROL_TRANSFER_DATA_RECEIVED:
                USB_DEVICE_ControlStatus(appData.usbDevHandle, USB_DEVICE_CONTROL_STATUS_OK );
            break;
            case  USB_DEVICE_VIDEO_EVENT_CONTROL_TRANSFER_DATA_SENT:
            break;
            default:
                SYS_ASSERT ( false , "Invalid callback" );
            break;

        } //end of switch ( callback )
    }//end of if  if ( iVideo == 0 )

} // APP_USBDeviceVideoEventHandler()

/*********************************************
 * Application USB Device Layer Event Handler
 *********************************************/
USB_DEVICE_VIDEO_RESULT USB_DEVICE_VIDEO_EventHandlerSet
(
    USB_DEVICE_VIDEO_INDEX iVideo ,
    USB_DEVICE_VIDEO_EVENT_HANDLER eventHandler ,
    uintptr_t userData
);

void APP_USBDeviceEventHandler(USB_DEVICE_EVENT event, void * eventData, uintptr_t context)
{
    uint8_t * configurationValue;
    USB_SETUP_PACKET * setupPacket;
    switch(event)
    {
        case USB_DEVICE_EVENT_SOF:
            
            if ( appData.state == APP_STATE_READY_TO_STREAM)
            {
                USB_DEVICE_VIDEO_Write(USB_DEVICE_INDEX_0, 
                        &appData.writeTransferHandle1, 
                        1 ,(void *) 0x0002, 
                        2);
                appData.state =APP_STATE_STREAMING;
            }
            break;
        case USB_DEVICE_EVENT_RESET:
        case USB_DEVICE_EVENT_DECONFIGURED:

            appData.deviceIsConfigured = false;

            break;

        case USB_DEVICE_EVENT_CONFIGURED:

            /* Check the configuration */
            configurationValue = (uint8_t *)eventData;
            if(*configurationValue == 1 )
            {

         USB_DEVICE_VIDEO_EventHandlerSet
                (
                    0,
                    APP_USBDeviceVideoEventHandler ,
                    (uintptr_t)NULL
                );
                /* Reset endpoint data send & receive flag  */
                appData.deviceIsConfigured = true;
            }
            break;

        case USB_DEVICE_EVENT_SUSPENDED:

            break;


        case USB_DEVICE_EVENT_POWER_DETECTED:

            /* VBUS is detected. Attach the device */
            USB_DEVICE_Attach(appData.usbDevHandle);
            break;

        case USB_DEVICE_EVENT_POWER_REMOVED:

            /* VBUS is removed. Detach the device */
            USB_DEVICE_Detach (appData.usbDevHandle);
            break;

        case USB_DEVICE_EVENT_CONTROL_TRANSFER_SETUP_REQUEST:
            /* This means we have received a setup packet */
            setupPacket = (USB_SETUP_PACKET *)eventData;
            if(setupPacket->bRequest == USB_REQUEST_SET_INTERFACE)
            {
                /* If we have got the SET_INTERFACE request, we just acknowledge
                 for now. This demo has only one alternate setting which is already
                 active. */
                USB_DEVICE_ControlStatus(appData.usbDevHandle,USB_DEVICE_CONTROL_STATUS_OK);
            }
            else if(setupPacket->bRequest == USB_REQUEST_GET_INTERFACE)
            {
                /* We have only one alternate setting and this setting 0. So
                 * we send this information to the host. */

                USB_DEVICE_ControlSend(appData.usbDevHandle, &appData.altSetting, 1);
            }
            else
            {
                /* We have received a request that we cannot handle. Stall it*/
                USB_DEVICE_ControlStatus(appData.usbDevHandle, USB_DEVICE_CONTROL_STATUS_ERROR);
            }
            break;

        case USB_DEVICE_EVENT_ENDPOINT_READ_COMPLETE:
           /* Endpoint read is complete */
            appData.epDataReadPending = false;
            break;

        case USB_DEVICE_EVENT_ENDPOINT_WRITE_COMPLETE:
            /* Endpoint write is complete */
            appData.epDataWritePending = false;
            break;

        /* These events are not used in this demo. */
        case USB_DEVICE_EVENT_RESUMED:
        case USB_DEVICE_EVENT_ERROR:
        default:
            break;
    }
}



// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    appData.usbDevHandle = USB_DEVICE_HANDLE_INVALID;
    appData.deviceIsConfigured = false;
    appData.endpointTxInt = (APP_EP_INTERRUPT_IN | USB_EP_DIRECTION_IN);
    appData.endpointTx = (USB_TRANSFER_TYPE_ISOCHRONOUS_IN | USB_EP_DIRECTION_IN);
    appData.epDataReadPending = false;
    appData.epDataWritePending = false;
    appData.altSetting = 0;
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks (void )
{
    switch(appData.state)
    {
        case APP_STATE_INIT:
            /* Open the device layer */
            appData.usbDevHandle = USB_DEVICE_Open( USB_DEVICE_INDEX_0,
                    DRV_IO_INTENT_READWRITE );

            if(appData.usbDevHandle != USB_DEVICE_HANDLE_INVALID)
            {
                /* Register a callback with device layer to get event notification (for end point 0) */
                USB_DEVICE_EventHandlerSet(appData.usbDevHandle,  APP_USBDeviceEventHandler, 0);

                appData.state = APP_STATE_WAIT_FOR_CONFIGURATION;
            }
            else
            {
                /* The Device Layer is not ready to be opened. We should try
                 * again later. */
            }
            break;

        case APP_STATE_WAIT_FOR_CONFIGURATION:

            /* Check if the device is configured */
            if(appData.deviceIsConfigured == true)
            {
                if (USB_DEVICE_ActiveSpeedGet(appData.usbDevHandle) == USB_SPEED_FULL)
                {
                    endpointSize = 64;
                }
                else if (USB_DEVICE_ActiveSpeedGet(appData.usbDevHandle) == USB_SPEED_HIGH)
                {
                    endpointSize = 512;
                }
                if (USB_DEVICE_EndpointIsEnabled(appData.usbDevHandle, appData.endpointTx) == false )
                {
                    /* Enable Write Endpoint */
                    USB_DEVICE_EndpointEnable(appData.usbDevHandle, 0, appData.endpointTx,
                            USB_TRANSFER_TYPE_ISOCHRONOUS, endpointSize);
                }
            
                /* Device is ready to run the main task */
                appData.state = APP_STATE_IDLE;
            }
            break;

        case APP_STATE_IDLE:

            if(!appData.deviceIsConfigured)
            {
                /* This means the device got deconfigured. Change the
                 * application state back to waiting for configuration. */
                appData.state = APP_STATE_WAIT_FOR_CONFIGURATION;

                /* Disable the endpoint*/
                USB_DEVICE_EndpointDisable(appData.usbDevHandle, appData.endpointTxInt);
                USB_DEVICE_EndpointDisable(appData.usbDevHandle, appData.endpointTx);
                appData.epDataReadPending = false;
                appData.epDataWritePending = false;
            }            
                /* Look at the data the host sent, to see what kind of
                 * application specific command it sent. */
            break;

        case APP_STATE_ERROR:
            break;

        default:
            break;
    }
}
 

/*******************************************************************************
 End of File
 */

