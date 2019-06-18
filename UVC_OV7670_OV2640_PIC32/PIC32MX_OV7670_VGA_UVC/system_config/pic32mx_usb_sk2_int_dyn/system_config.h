/*******************************************************************************
  MPLAB Harmony System Configuration Header

  File Name:
    system_config.h

  Summary:
    Build-time configuration header for the system defined by this MPLAB Harmony
    project.

  Description:
    An MPLAB Project may have multiple configurations.  This file defines the
    build-time options for a single configuration.

  Remarks:
    This configuration header must not define any prototypes or data
    definitions (or include any files that do).  It only provides macro
    definitions for build-time configuration options that are not instantiated
    until used by another MPLAB Harmony module or application.
    
    Created with MPLAB Harmony Version 2.04
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2015 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _SYSTEM_CONFIG_H
#define _SYSTEM_CONFIG_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/*  This section Includes other configuration headers necessary to completely
    define this configuration.
*/
#include "bsp.h"


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

// *****************************************************************************
// *****************************************************************************
// Section: System Service Configuration
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Common System Service Configuration Options
*/
#define SYS_VERSION_STR           "2.04"
#define SYS_VERSION               20400

// *****************************************************************************
/* Clock System Service Configuration Options
*/
#define SYS_CLK_FREQ                        115200000ul
#define SYS_CLK_BUS_PERIPHERAL_1            57600000ul
#define SYS_CLK_UPLL_BEFORE_DIV2_FREQ       48000000ul
#define SYS_CLK_CONFIG_PRIMARY_XTAL         24000000ul
#define SYS_CLK_CONFIG_SECONDARY_XTAL       32768ul

/*** Ports System Service Configuration ***/
#define SYS_PORT_A_ANSEL        0x3F00
#define SYS_PORT_A_TRIS         0xFFFF
#define SYS_PORT_A_LAT          0x0000
#define SYS_PORT_A_ODC          0x0000
#define SYS_PORT_A_CNPU         0x0000
#define SYS_PORT_A_CNPD         0x0000
#define SYS_PORT_A_CNEN         0x0000

#define SYS_PORT_B_ANSEL        0xFFDF
#define SYS_PORT_B_TRIS         0xFFDF
#define SYS_PORT_B_LAT          0x0000
#define SYS_PORT_B_ODC          0x0000
#define SYS_PORT_B_CNPU         0x0000
#define SYS_PORT_B_CNPD         0x0000
#define SYS_PORT_B_CNEN         0x0000

#define SYS_PORT_C_ANSEL        0xFFE1
#define SYS_PORT_C_TRIS         0xFFFF
#define SYS_PORT_C_LAT          0x0000
#define SYS_PORT_C_ODC          0x0000
#define SYS_PORT_C_CNPU         0x0000
#define SYS_PORT_C_CNPD         0x0000
#define SYS_PORT_C_CNEN         0x0000

#define SYS_PORT_D_ANSEL        0x0008
#define SYS_PORT_D_TRIS         0xFFF8
#define SYS_PORT_D_LAT          0x0000
#define SYS_PORT_D_ODC          0x0000
#define SYS_PORT_D_CNPU         0x20C0
#define SYS_PORT_D_CNPD         0x0000
#define SYS_PORT_D_CNEN         0x0000

#define SYS_PORT_E_ANSEL        0xFCF4
#define SYS_PORT_E_TRIS         0xFFFF
#define SYS_PORT_E_LAT          0x0000
#define SYS_PORT_E_ODC          0x0000
#define SYS_PORT_E_CNPU         0x0000
#define SYS_PORT_E_CNPD         0x0000
#define SYS_PORT_E_CNEN         0x0000

#define SYS_PORT_F_ANSEL        0xCEC0
#define SYS_PORT_F_TRIS         0xFFFF
#define SYS_PORT_F_LAT          0x0000
#define SYS_PORT_F_ODC          0x0000
#define SYS_PORT_F_CNPU         0x0000
#define SYS_PORT_F_CNPD         0x0000
#define SYS_PORT_F_CNEN         0x0000

#define SYS_PORT_G_ANSEL        0x0FFC
#define SYS_PORT_G_TRIS         0xFFFF
#define SYS_PORT_G_LAT          0x0000
#define SYS_PORT_G_ODC          0x0000
#define SYS_PORT_G_CNPU         0x0000
#define SYS_PORT_G_CNPD         0x0000
#define SYS_PORT_G_CNEN         0x0000


/*** Interrupt System Service Configuration ***/
#define SYS_INT                     true

// *****************************************************************************
// *****************************************************************************
// Section: Driver Configuration
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Middleware & Other Library Configuration
// *****************************************************************************
// *****************************************************************************

/*** USB Driver Configuration ***/


/* Enables Device Support */
#define DRV_USBFS_DEVICE_SUPPORT      true

/* Disable Host Support */
#define DRV_USBFS_HOST_SUPPORT      false

/* Maximum USB driver instances */
#define DRV_USBFS_INSTANCES_NUMBER    1

/* Interrupt mode enabled */
#define DRV_USBFS_INTERRUPT_MODE      true


/* Number of Endpoints used */
#define DRV_USBFS_ENDPOINTS_NUMBER    4




/*** USB Device Stack Configuration ***/










/* The USB Device Layer will not initialize the USB Driver */
#define USB_DEVICE_DRIVER_INITIALIZE_EXPLICIT

/* Maximum device layer instances */
#define USB_DEVICE_INSTANCES_NUMBER     1

/* EP0 size in bytes */
#define USB_DEVICE_EP0_BUFFER_SIZE      64

#define WBVAL(x) (x & 0xFF),((x >> 8) & 0xFF)
#define DBVAL(x) (x & 0xFF),((x >> 8) & 0xFF),((x >> 16) & 0xFF),((x >> 24) & 0xFF)


#define WIDTH                                         (unsigned int)160
#define HEIGHT                                        (unsigned int)120
#define CAM_FPS                                       26
#define VIDEO_PACKET_SIZE                             (unsigned int)(768+2)//128+130
#define MIN_BIT_RATE                                  (unsigned long)(WIDTH*HEIGHT*16*CAM_FPS)//16 bit
#define MAX_BIT_RATE                                  (unsigned long)(WIDTH*HEIGHT*16*CAM_FPS)
#define MAX_FRAME_SIZE                                (unsigned long)(WIDTH*HEIGHT*2)//yuy2
//#define MAX_FRAME_SIZE                                (unsigned long)(WIDTH*HEIGHT*3/2)//nv12
#define INTERVAL                                      (unsigned long)(10000000/CAM_FPS)
#define PACKETS_IN_FRAME                              (unsigned int)(MAX_FRAME_SIZE/(VIDEO_PACKET_SIZE-2))



#define USB_DEVICE_VIDEO_INSTANCES_NUMBER 1

#define USB_DEVICE_VIDEO_MAX_ALTERNATE_SETTING 2

#define USB_DEVICE_VIDEO_MAX_STREAMING_INTERFACES 1

#define USB_DEVICE_VIDEO_QUEUE_DEPTH_COMBINED     4

#define USB_DEVICE_SOF_EVENT_ENABLE

// *****************************************************************************
/* BSP Configuration Options
*/


#define APP_MAKE_BUFFER_DMA_READY

#define APP_USB_LED_1 BSP_LED_1
#define APP_USB_LED_2 BSP_LED_2
#define APP_USB_LED_3 BSP_LED_3

#define APP_USB_SWITCH_1 BSP_SWITCH_1

#define APP_READ_BUFFER_SIZE 64

/* Number of Endpoints used */    
#define USB_TRANSFER_TYPE_ISOCHRONOUS_IN  1

/* Number of Endpoints used */    
#define APP_EP_BULK_OUT 1

#define APP_EP_INTERRUPT_IN 2

// *****************************************************************************
// *****************************************************************************
// Section: Application Configuration
// *****************************************************************************
// *****************************************************************************
/*** Application Defined Pins ***/

/*** Functions for BSP_LED_1 pin ***/
#define BSP_LED_1Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_0)
#define BSP_LED_1On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_0)
#define BSP_LED_1Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_0)
#define BSP_LED_1StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_0)

/*** Functions for BSP_LED_2 pin ***/
#define BSP_LED_2Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_1)
#define BSP_LED_2On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_1)
#define BSP_LED_2Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_1)
#define BSP_LED_2StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_1)

/*** Functions for BSP_LED_3 pin ***/
#define BSP_LED_3Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_2)
#define BSP_LED_3On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_2)
#define BSP_LED_3Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_2)
#define BSP_LED_3StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_2)

/*** Functions for BSP_SWITCH_3 pin ***/
#define BSP_SWITCH_3StateGet() PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_13)

/*** Functions for BSP_SWITCH_1 pin ***/
#define BSP_SWITCH_1StateGet() PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_6)

/*** Functions for BSP_SWITCH_2 pin ***/
#define BSP_SWITCH_2StateGet() PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_7)


/*** Application Instance 0 Configuration ***/

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // _SYSTEM_CONFIG_H
/*******************************************************************************
 End of File
*/
