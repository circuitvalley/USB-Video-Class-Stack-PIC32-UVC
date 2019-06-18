/*******************************************************************************
 
  Company:
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "usb/usb_video.h"
#include "system_config.h"
#include "driver/pmp/drv_pmp.h"
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


APP_MAKE_BUFFER_DMA_READY uint8_t lines_buffer[UVC_WIDTH*MAX_LINES_BUFER*2];
APP_MAKE_BUFFER_DMA_READY uint8_t uvc_packet[VIDEO_PACKET_SIZE * 3];
uint8_t frame_index = 0;
bool VSYNC = false;

char buffer[128];

line_data_t lines[MAX_LINES_BUFER] = {
    {lines_buffer + (LINE_LENGTH * 0), 0, 0, &lines[1]},
    {lines_buffer + (LINE_LENGTH * 1), 0, 0, &lines[2]},
    {lines_buffer + (LINE_LENGTH * 2), 0, 0, &lines[3]},
    {lines_buffer + (LINE_LENGTH * 3), 0, 0, &lines[4]},
    {lines_buffer + (LINE_LENGTH * 4), 0, 0, &lines[5]},
    {lines_buffer + (LINE_LENGTH * 5), 0, 0, &lines[6]},
    {lines_buffer + (LINE_LENGTH * 6), 0, 0, &lines[7]},
    {lines_buffer + (LINE_LENGTH * 7), 0, 0, &lines[8]},
    {lines_buffer + (LINE_LENGTH * 8), 0, 0, &lines[9]},
    {lines_buffer + (LINE_LENGTH * 9), 0, 0, &lines[10]},
    {lines_buffer + (LINE_LENGTH * 10), 0, 0, &lines[11]},
    {lines_buffer + (LINE_LENGTH * 11), 0, 0, &lines[12]},
    {lines_buffer + (LINE_LENGTH * 12), 0, 0, &lines[13]},
    {lines_buffer + (LINE_LENGTH * 13), 0, 0, &lines[14]},
    {lines_buffer + (LINE_LENGTH * 14), 0, 0, &lines[15]},
    {lines_buffer + (LINE_LENGTH * 15), 0, 0, &lines[0]},
};

line_data_t *line_read = &lines[0];
static bool data_delivered = false;                
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
                    
                   // BSP_LEDOn(BSP_LED_1);
                    appData.state = APP_STATE_READY_TO_STREAM;
                }else
                {
                   // BSP_LEDOff(BSP_LED_1);
                    appData.state = APP_STATE_IDLE;
                }
              break;
            }
            case USB_DEVICE_VIDEO_EVENT_READ_COMPLETE:             
            break;
            case USB_DEVICE_VIDEO_EVENT_WRITE_COMPLETE:
            {
                data_delivered = true;

            }
            break;
            case USB_DEVICE_VIDEO_EVENT_CONTROL_SET_MIN:
            case USB_DEVICE_VIDEO_EVENT_CONTROL_SET_CUR:
            case USB_DEVICE_VIDEO_EVENT_CONTROL_SET_MAX:
                
                
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
                if (((USB_VIDEO_CONTROL_INTERFACE_REQUEST*)pData)->wValue ==256 )
                {
                    USB_DEVICE_ControlSend(appData.usbDevHandle, (void *)&videoProbeControl,((USB_VIDEO_CONTROL_INTERFACE_REQUEST*)pData)->wLength);
                }else if (((USB_VIDEO_CONTROL_INTERFACE_REQUEST*)pData)->wValue ==0x1400 )
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
    appData.drvI2CHandle = DRV_HANDLE_INVALID;
    appData.altSetting = 0;
    
    
    appData.usartBufferHandle = DRV_HANDLE_INVALID;
    /* Set the USART handler to invalid */
    appData.usartHandle       = DRV_HANDLE_INVALID;
}


const DRV_PMP_MODE_CONFIG pmpModeConfig =
{   
    .pmpMode = PMP_LEGACY_SLAVE,
    .incrementMode = PMP_ADDRESS_INCREMENT_DECREMENT_DISABLE,
    .intMode = PMP_INTERRUPT_EVERY_RW_CYCLE,
    .portSize = PMP_DATA_SIZE_8_BITS,
    .chipSelect = PMCS1_AND_PMCS2_AS_CHIP_SELECT, //in slave mode only CS1 can be used
 };



DRV_I2C_BUFFER_HANDLE i2c_buffer_handle;


#define OV7670_REG_NUM 			166
#define OV7670_WRITE_ADDR 	0x42
void Delay(volatile long nCount) {
	while (nCount--) {
	}
}

// *****************************************************************************
// <editor-fold defaultstate="collapsed" desc="Camera Initialization Data">
// *****************************************************************************
/* Camera Initialization Data
 */
const uint8_t OV7670_reg_qcif[][2] = { 
    {0x3a, 0x04},
    {0x40, 0xC0},
    {0x12, 0x0},
    {0x32, 0x80},
    {0x17, 0x16},
    {0x18, 0x04},
    {0x19, 0x02},
    {0x1a, 0x7b},
    {0x03, 0x06},
    {0x0c, 0x0C},
    {0x3e, 0x11},
    {0x70, 0x3A},
    {0x71, 0x35},
    {0x72, 0x11},
    {0x73, 0xF1},
    {0xa2, 0x52},
    {0x11, 0x01},  //CLKRC Prescaler settings 
    {0x7a, 0x20},
    {0x7b, 0x1c},
    {0x7c, 0x28},
    {0x7d, 0x3c},
    {0x7e, 0x55},
    {0x7f, 0x68},
    {0x80, 0x76},
    {0x81, 0x80},
    {0x82, 0x88},
    {0x83, 0x8f},
    {0x84, 0x96},
    {0x85, 0xa3},
    {0x86, 0xaf},
    {0x87, 0xc4},
    {0x88, 0xd7},
    {0x89, 0xe8},
    {0x13, 0xe0},
    {0x00, 0x00},
    {0x10, 0x00},
    {0x0d, 0x00},
    {0x14, 0x28},
    {0xa5, 0x05},
    {0xab, 0x07},
    {0x24, 0x75},
    {0x25, 0x63},
    {0x26, 0xA5},
    {0x9f, 0x78},
    {0xa0, 0x68},
    {0xa1, 0x03},
    {0xa6, 0xdf},
    {0xa7, 0xdf},
    {0xa8, 0xf0},
    {0xa9, 0x90},
    {0xaa, 0x94},
    {0x13, 0xe5},
    {0x0e, 0x61},
    {0x0f, 0x4b},
    {0x16, 0x02},
    {0x1e, 0x17},
    {0x21, 0x02},
    {0x22, 0x91},
    {0x29, 0x07},
    {0x33, 0x0b},
    {0x35, 0x0b},
    {0x37, 0x1d},
    {0x38, 0x71},
    {0x39, 0x2a},
    {0x3c, 0x78},
    {0x4d, 0x40},
    {0x4e, 0x20},
    {0x69, 0x00},
    {0x6b, 0x40}, //DBLV PLL Control Bit[7:6] 0x40 --> x4 ,0x80 --> x6 , 0xC0 --> 0x8
    {0x74, 0x19},
    {0x8d, 0x4f},
    {0x8e, 0x00},
    {0x8f, 0x00},
    {0x90, 0x00},
    {0x91, 0x00},
    {0x92, 0x00},
    {0x96, 0x00},
    {0x9a, 0x80},
    {0xb0, 0x84},
    {0xb1, 0x0c},
    {0xb2, 0x0e},
    {0xb3, 0x82},
    {0xb8, 0x0a},
    {0x43, 0x14},
    {0x44, 0xf0},
    {0x45, 0x34},
    {0x46, 0x58},
    {0x47, 0x28},
    {0x48, 0x3a},
    {0x59, 0x88},
    {0x5a, 0x88},
    {0x5b, 0x44},
    {0x5c, 0x67},
    {0x5d, 0x49},
    {0x5e, 0x0e},
    {0x64, 0x04},
    {0x65, 0x20},
    {0x66, 0x05},
    {0x94, 0x04},
    {0x95, 0x08},
    {0x6c, 0x0a},
    {0x6d, 0x55},
    {0x6e, 0x11},
    {0x6f, 0x9f},
    {0x6a, 0x40},
    {0x01, 0x40},
    {0x02, 0x40},
    {0x13, 0xe7},
    {0x15, 0x22},
    {0x4f, 0x40},
    {0x50, 0x34},
    {0x51, 0x0C},
    {0x52, 0x17},
    {0x53, 0x29},
    {0x54, 0x40},
    {0x58, 0x1E},   
    {0x41, 0x08},
    {0x3f, 0x00},
    {0x75, 0x05},
    {0x76, 0xe1},
    {0x4c, 0x00},
    {0x77, 0x01},
    {0x3d, 0xc2},  
    {0x4b, 0x09},
    {0xc9, 0x60},
    {0x41, 0x38},
    {0x56, 0x40},
    {0x34, 0x11},
    {0x3b, 0x02},
    {0xa4, 0x89},
    {0x96, 0x00},
    {0x97, 0x30},
    {0x98, 0x20},
    {0x99, 0x30},
    {0x9a, 0x84},
    {0x9b, 0x29},
    {0x9c, 0x03},
    {0x9d, 0x4c},
    {0x9e, 0x3f},
    {0x78, 0x04},   
    {0x79, 0x01},
    {0xc8, 0xf0},
    {0x79, 0x0f},
    {0xc8, 0x00},
    {0x79, 0x10},
    {0xc8, 0x7e},
    {0x79, 0x0a},
    {0xc8, 0x80},
    {0x79, 0x0b},
    {0xc8, 0x01},
    {0x79, 0x0c},
    {0xc8, 0x0f},
    {0x79, 0x0d},
    {0xc8, 0x20},
    {0x79, 0x09},
    {0xc8, 0x80},
    {0x79, 0x02},
    {0xc8, 0xc0},
    {0x79, 0x03},
    {0xc8, 0x40},
    {0x79, 0x05},
    {0xc8, 0x30},
    {0x79, 0x26},
    {0x09, 0x03},
    {0x3b, 0x42},
	{0xff, 0xff}
};
const uint8_t OV7670_reg_qvga[][2] = { 
    {0x3a, 0x04},
    {0x40, 0xC0},
    {0x12, 0x0},
    {0x32, 0x80},
    {0x17, 0x16},
    {0x18, 0x04},
    {0x19, 0x02},
    {0x1a, 0x7b},
    {0x03, 0x06},
    {0x0c, 0x04},
    {0x3e, 0x19},
    {0x70, 0x3A},
    {0x71, 0x35},
    {0x72, 0x11},
    {0x73, 0xF1},
    {0xa2, 0x02},
    {0x11, 0x01},  //CLKRC Prescaler settings 
    {0x7a, 0x20},
    {0x7b, 0x1c},
    {0x7c, 0x28},
    {0x7d, 0x3c},
    {0x7e, 0x55},
    {0x7f, 0x68},
    {0x80, 0x76},
    {0x81, 0x80},
    {0x82, 0x88},
    {0x83, 0x8f},
    {0x84, 0x96},
    {0x85, 0xa3},
    {0x86, 0xaf},
    {0x87, 0xc4},
    {0x88, 0xd7},
    {0x89, 0xe8},
    {0x13, 0xe0},
    {0x00, 0x00},
    {0x10, 0x00},
    {0x0d, 0x00},
    {0x14, 0x28},
    {0xa5, 0x05},
    {0xab, 0x07},
    {0x24, 0x75},
    {0x25, 0x63},
    {0x26, 0xA5},
    {0x9f, 0x78},
    {0xa0, 0x68},
    {0xa1, 0x03},
    {0xa6, 0xdf},
    {0xa7, 0xdf},
    {0xa8, 0xf0},
    {0xa9, 0x90},
    {0xaa, 0x94},
    {0x13, 0xe5},
    {0x0e, 0x61},
    {0x0f, 0x4b},
    {0x16, 0x02},
    {0x1e, 0x17},
    {0x21, 0x02},
    {0x22, 0x91},
    {0x29, 0x07},
    {0x33, 0x0b},
    {0x35, 0x0b},
    {0x37, 0x1d},
    {0x38, 0x71},
    {0x39, 0x2a},
    {0x3c, 0x78},
    {0x4d, 0x40},
    {0x4e, 0x20},
    {0x69, 0x00},
    {0x6b, 0x40}, //DBLV PLL Control Bit[7:6] 0x40 --> x4 ,0x80 --> x6 , 0xC0 --> 0x8
    {0x74, 0x19},
    {0x8d, 0x4f},
    {0x8e, 0x00},
    {0x8f, 0x00},
    {0x90, 0x00},
    {0x91, 0x00},
    {0x92, 0x00},
    {0x96, 0x00},
    {0x9a, 0x80},
    {0xb0, 0x84},
    {0xb1, 0x0c},
    {0xb2, 0x0e},
    {0xb3, 0x82},
    {0xb8, 0x0a},
    {0x43, 0x14},
    {0x44, 0xf0},
    {0x45, 0x34},
    {0x46, 0x58},
    {0x47, 0x28},
    {0x48, 0x3a},
    {0x59, 0x88},
    {0x5a, 0x88},
    {0x5b, 0x44},
    {0x5c, 0x67},
    {0x5d, 0x49},
    {0x5e, 0x0e},
    {0x64, 0x04},
    {0x65, 0x20},
    {0x66, 0x05},
    {0x94, 0x04},
    {0x95, 0x08},
    {0x6c, 0x0a},
    {0x6d, 0x55},
    {0x6e, 0x11},
    {0x6f, 0x9f},
    {0x6a, 0x40},
    {0x01, 0x40},
    {0x02, 0x40},
    {0x13, 0xe7},
    {0x15, 0x22},
    {0x4f, 0x40},
    {0x50, 0x34},
    {0x51, 0x0C},
    {0x52, 0x17},
    {0x53, 0x29},
    {0x54, 0x40},
    {0x58, 0x1E},   
    {0x41, 0x08},
    {0x3f, 0x00},
    {0x75, 0x05},
    {0x76, 0xe1},
    {0x4c, 0x00},
    {0x77, 0x01},
    {0x3d, 0xc2},  
    {0x4b, 0x09},
    {0xc9, 0x60},
    {0x41, 0x38},
    {0x56, 0x40},
    {0x34, 0x11},
    {0x3b, 0x02},
    {0xa4, 0x89},
    {0x96, 0x00},
    {0x97, 0x30},
    {0x98, 0x20},
    {0x99, 0x30},
    {0x9a, 0x84},
    {0x9b, 0x29},
    {0x9c, 0x03},
    {0x9d, 0x4c},
    {0x9e, 0x3f},
    {0x78, 0x04},   
    {0x79, 0x01},
    {0xc8, 0xf0},
    {0x79, 0x0f},
    {0xc8, 0x00},
    {0x79, 0x10},
    {0xc8, 0x7e},
    {0x79, 0x0a},
    {0xc8, 0x80},
    {0x79, 0x0b},
    {0xc8, 0x01},
    {0x79, 0x0c},
    {0xc8, 0x0f},
    {0x79, 0x0d},
    {0xc8, 0x20},
    {0x79, 0x09},
    {0xc8, 0x80},
    {0x79, 0x02},
    {0xc8, 0xc0},
    {0x79, 0x03},
    {0xc8, 0x40},
    {0x79, 0x05},
    {0xc8, 0x30},
    {0x79, 0x26},
    {0x09, 0x03},
    {0x3b, 0x42},
	{0xff, 0xff}
};
const uint8_t OV7670_reg_vga[][2] = { 
    {0x3a, 0x04},
    {0x40, 0xC0},
    {0x12, 0x0},
    {0x32, 0x80},
    {0x17, 0x16},
    {0x18, 0x04},
    {0x19, 0x02},
    {0x1a, 0x7b},
    {0x03, 0x06},
    {0x0c, 0x00},
    {0x3e, 0x00},
    {0x70, 0x3A},
    {0x71, 0x35},
    {0x72, 0x11},
    {0x73, 0xF0},
    {0xa2, 0x02},
    {0x11, 0x01},  //CLKRC Prescaler settings 
    {0x7a, 0x20},
    {0x7b, 0x1c},
    {0x7c, 0x28},
    {0x7d, 0x3c},
    {0x7e, 0x55},
    {0x7f, 0x68},
    {0x80, 0x76},
    {0x81, 0x80},
    {0x82, 0x88},
    {0x83, 0x8f},
    {0x84, 0x96},
    {0x85, 0xa3},
    {0x86, 0xaf},
    {0x87, 0xc4},
    {0x88, 0xd7},
    {0x89, 0xe8},
    {0x13, 0xe0},
    {0x00, 0x00},
    {0x10, 0x00},
    {0x0d, 0x00},
    {0x14, 0x28},
    {0xa5, 0x05},
    {0xab, 0x07},
    {0x24, 0x75},
    {0x25, 0x63},
    {0x26, 0xA5},
    {0x9f, 0x78},
    {0xa0, 0x68},
    {0xa1, 0x03},
    {0xa6, 0xdf},
    {0xa7, 0xdf},
    {0xa8, 0xf0},
    {0xa9, 0x90},
    {0xaa, 0x94},
    {0x13, 0xe5},
    {0x0e, 0x61},
    {0x0f, 0x4b},
    {0x16, 0x02},
    {0x1e, 0x17},
    {0x21, 0x02},
    {0x22, 0x91},
    {0x29, 0x07},
    {0x33, 0x0b},
    {0x35, 0x0b},
    {0x37, 0x1d},
    {0x38, 0x71},
    {0x39, 0x2a},
    {0x3c, 0x78},
    {0x4d, 0x40},
    {0x4e, 0x20},
    {0x69, 0x00},
    {0x6b, 0x40}, //DBLV PLL Control Bit[7:6] 0x40 --> x4 ,0x80 --> x6 , 0xC0 --> 0x8
    {0x74, 0x19},
    {0x8d, 0x4f},
    {0x8e, 0x00},
    {0x8f, 0x00},
    {0x90, 0x00},
    {0x91, 0x00},
    {0x92, 0x00},
    {0x96, 0x00},
    {0x9a, 0x80},
    {0xb0, 0x84},
    {0xb1, 0x0c},
    {0xb2, 0x0e},
    {0xb3, 0x82},
    {0xb8, 0x0a},
    {0x43, 0x14},
    {0x44, 0xf0},
    {0x45, 0x34},
    {0x46, 0x58},
    {0x47, 0x28},
    {0x48, 0x3a},
    {0x59, 0x88},
    {0x5a, 0x88},
    {0x5b, 0x44},
    {0x5c, 0x67},
    {0x5d, 0x49},
    {0x5e, 0x0e},
    {0x64, 0x04},
    {0x65, 0x20},
    {0x66, 0x05},
    {0x94, 0x04},
    {0x95, 0x08},
    {0x6c, 0x0a},
    {0x6d, 0x55},
    {0x6e, 0x11},
    {0x6f, 0x9f},
    {0x6a, 0x40},
    {0x01, 0x40},
    {0x02, 0x40},
    {0x13, 0xe7},
    {0x15, 0x22},
    {0x4f, 0x40},
    {0x50, 0x34},
    {0x51, 0x0C},
    {0x52, 0x17},
    {0x53, 0x29},
    {0x54, 0x40},
    {0x58, 0x1E},   
    {0x41, 0x08},
    {0x3f, 0x00},
    {0x75, 0x05},
    {0x76, 0xe1},
    {0x4c, 0x00},
    {0x77, 0x01},
    {0x3d, 0xc2},  
    {0x4b, 0x09},
    {0xc9, 0x60},
    {0x41, 0x38},
    {0x56, 0x40},
    {0x34, 0x11},
    {0x3b, 0x02},
    {0xa4, 0x89},
    {0x96, 0x00},
    {0x97, 0x30},
    {0x98, 0x20},
    {0x99, 0x30},
    {0x9a, 0x84},
    {0x9b, 0x29},
    {0x9c, 0x03},
    {0x9d, 0x4c},
    {0x9e, 0x3f},
    {0x78, 0x04},   
    {0x79, 0x01},
    {0xc8, 0xf0},
    {0x79, 0x0f},
    {0xc8, 0x00},
    {0x79, 0x10},
    {0xc8, 0x7e},
    {0x79, 0x0a},
    {0xc8, 0x80},
    {0x79, 0x0b},
    {0xc8, 0x01},
    {0x79, 0x0c},
    {0xc8, 0x0f},
    {0x79, 0x0d},
    {0xc8, 0x20},
    {0x79, 0x09},
    {0xc8, 0x80},
    {0x79, 0x02},
    {0xc8, 0xc0},
    {0x79, 0x03},
    {0xc8, 0x40},
    {0x79, 0x05},
    {0xc8, 0x30},
    {0x79, 0x26},
    {0x09, 0x03},
    {0x3b, 0x42},
	{0xff, 0xff}
};
// </editor-fold>

#define _countof(array) (sizeof(array) / sizeof(array[0]))


bool SCCB_write_reg(uint8_t reg_addr, uint8_t* data) {
    
    uint16_t buffer_16 =   *data <<8 | reg_addr;
    i2c_buffer_handle = DRV_I2C_Transmit(appData.drvI2CHandle, OV7670_WRITE_ADDR , &buffer_16, 2, NULL);
    
    while ( DRV_I2C_BUFFER_EVENT_COMPLETE != DRV_I2C_TransferStatusGet(appData.drvI2CHandle, i2c_buffer_handle));
    return 0;
}



void APP_BufferEventHandler(DRV_USART_BUFFER_EVENT buffEvent,
        DRV_USART_BUFFER_HANDLE hBufferEvent,
        uintptr_t context )

{
    switch(buffEvent)
    {
        /* Buffer event is completed successfully */
        case DRV_USART_BUFFER_EVENT_COMPLETE:
        {
            if(context == APP_DRV_CONTEXT)
            {
                /* Update buffer event status */
                appData.drvBufferEventComplete = true;
            }
            
        }
        break;
        
        /* Buffer event has some error */
        case DRV_USART_BUFFER_EVENT_ERROR:
            break;
            
            /* Buffer event has aborted */
        case DRV_USART_BUFFER_EVENT_ABORT:
            break;
    }
}

   
bool OV7670_init(void) {
	uint8_t data, i = 0;
	bool err;

	// Configure camera registers
	for (i = 0; i < _countof(OV7670_reg_vga); i++) {
		data = OV7670_reg_vga[i][1];
		err = SCCB_write_reg(OV7670_reg_vga[i][0], &data);
Delay(0xFFFE);
     
	}

	return err;
}


void printf32(char *format, ...)
{        
    va_list args;
    va_start(args, format);
    
    uint16_t n = vsprintf(buffer, format, args);
    DRV_USART_BufferAddWrite( appData.usartHandle, &(appData.usartBufferHandle), buffer, n);
    va_end(args);
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
            
            appData.usbDevHandle = USB_DEVICE_Open( USB_DEVICE_INDEX_0, DRV_IO_INTENT_READWRITE);
            
            if(appData.usbDevHandle != USB_DEVICE_HANDLE_INVALID)
            {
                /* Register a callback with device layer to get event notification (for end point 0) */
                USB_DEVICE_EventHandlerSet(appData.usbDevHandle,  APP_USBDeviceEventHandler, 0);
                appData.state = APP_STATE_WAIT_FOR_CONFIGURATION;
                
                appData.DMAChannelHandle = SYS_DMA_ChannelAllocate(DMA_CHANNEL_2);
                SYS_DMA_ChannelDisable(appData.DMAChannelHandle);
                if (appData.drvI2CHandle == DRV_HANDLE_INVALID)
                {
                    appData.drvI2CHandle = DRV_I2C_Open( DRV_I2C_INDEX_2, DRV_IO_INTENT_READWRITE);
                    DRV_I2C_QueueFlush(appData.drvI2CHandle);
                    OV7670_init();
                }
                
              //  appData.usartHandle = DRV_USART_Open(APP_USART_DRIVER_INDEX, (DRV_IO_INTENT_READWRITE | DRV_IO_INTENT_NONBLOCKING));
                //   appData.pmpDrvHandle = DRV_PMP_Open( PMP_DEVICE_INDEX_0, DRV_IO_INTENT_READ | DRV_IO_INTENT_EXCLUSIVE);
                //  DRV_PMP_ModeConfig(appData.pmpDrvHandle , pmpModeConfig);
                //  DRV_PMP_HardwareConfig(appData.pmpDrvHandle);
               // SYS_INT_SourceEnable(INT_SOURCE_USART_1_ERROR);
                //  SYS_INT_SourceEnable(INT_SOURCE_USART_1_TRANSMIT);
                
                SYS_INT_SourceEnable(INT_SOURCE_EXTERNAL_1);
                TRISDbits.TRISD1 = 0;
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
            break;
        case APP_STATE_READY_TO_STREAM:
            break;
        case APP_STATE_STREAMING:
        {             
            static uint8_t frame_toggle=0;
            static uint16_t line_number = 0;
            static uint32_t total_bytes =0;
            static uint16_t packet_tosend =0;

            if (VSYNC)
            {
                VSYNC = false;
                packet_tosend = 0;
                line_number = 0;
                frame_toggle ^= 1;      
                total_bytes = 0;

            }
            
            if (data_delivered == true)
            {
                BSP_LEDToggle(BSP_LED_1);

                    while(line_read->line_number == line_number && line_number < MAX_LINE_NUMBER && packet_tosend < VIDOE_PAYLOAD_SIZE && line_read->available_length )
                    {
                       
                        uint16_t remaining_tosend = min(line_read->available_length, VIDOE_PAYLOAD_SIZE - packet_tosend); //if tosend < VIDOE_PAYLOAD_SIZE copy , if not zero copy
                        memcpy(uvc_packet + packet_tosend + VIDOE_HEADER_SIZE , line_read->data + LINE_LENGTH - line_read->available_length , remaining_tosend);
                        packet_tosend += remaining_tosend;
                        line_read->available_length -= remaining_tosend;
                        if (!line_read->available_length)
                        {
                            line_read = line_read->next;
                            line_number++;
                        }
                        LATDbits.LATD1 ^=1;
                    }
                    
                    if((packet_tosend == VIDOE_PAYLOAD_SIZE || line_number >= MAX_LINE_NUMBER) && packet_tosend)
                    {
                        
                        data_delivered = false;                
                        
                        uvc_packet[0] = 0x2; //header length 
                        uvc_packet[1] = frame_toggle; //toggle frame bit
                        USB_DEVICE_VIDEO_Write(USB_DEVICE_INDEX_0, 
                                &appData.writeTransferHandle1, 
                                1 ,uvc_packet,  
                                packet_tosend + VIDOE_HEADER_SIZE);
                        total_bytes +=packet_tosend;
                        packet_tosend = 0;
                        
                    }
                    else
                    {
                        line_read = line_read->next;
                    }
                
                
            }
            break;
        }
        case APP_STATE_ERROR:
            break;
            
        default:
            break;
    }
}
 




   
   
   
                                       
/*******************************************************************************
 End of File
 */

