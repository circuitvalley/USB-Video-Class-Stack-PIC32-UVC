/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef _APP_H
#define _APP_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"
#include "usb/usb_video.h"
// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application States

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* Application's state machine's initial state. */
    APP_STATE_INIT=0,

    /* Application waits for device configuration */
    APP_STATE_WAIT_FOR_CONFIGURATION,

    /* Application runs the main task */
    APP_STATE_IDLE,

    APP_STATE_READY_TO_STREAM,
            
    APP_STATE_STREAMING,
    /* Application error occurred */
    APP_STATE_ERROR

} APP_STATES;


// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
   /* Device layer handle returned by device layer open function */
    USB_DEVICE_HANDLE usbDevHandle;
    
    DRV_HANDLE pmpDrvHandle;
    
    DRV_HANDLE drvI2CHandle;
    
    SYS_DMA_CHANNEL_HANDLE DMAChannelHandle;

    /* Application state*/
    APP_STATES state;

    /* Track device configuration */
    bool deviceIsConfigured;

    /* Configuration value */
    uint8_t configValue;

    /* speed */
    USB_SPEED speed;

    /* ep data sent */
    bool epDataWritePending;

    /* ep data received */
    bool epDataReadPending;

    /* Transfer handle */
    USB_DEVICE_TRANSFER_HANDLE writeTranferHandle;

    /* Transfer handle */
    USB_DEVICE_TRANSFER_HANDLE readTranferHandle;

    /* The transmit endpoint address */
    USB_ENDPOINT_ADDRESS endpointTx;

    /* The receive endpoint address */
    USB_ENDPOINT_ADDRESS endpointTxInt;

    /* Tracks the alternate setting */
    uint8_t altSetting;

    USB_DEVICE_VIDEO_TRANSFER_HANDLE writeTransferHandle1;

    DRV_HANDLE usartBufferHandle;
    /* Set the USART handler to invalid */
    DRV_HANDLE usartHandle;
    
    bool drvBufferEventComplete;
} APP_DATA;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

	
// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the 
    application in its initial state and prepares it to run so that its 
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */


typedef struct line_data_s
{
    uint8_t * const data ;
    uint16_t available_length;
    uint16_t line_number; //actual line number of image 
    struct  line_data_s  * const next;
}line_data_t;

void APP_Tasks ( void );
void printf32(char *format, ...);

#define MAX_LINES_BUFER 16
#define MAX_LINE_NUMBER UVC_HEIGHT

#define LINE_LENGTH_QVGA 640
#define LINE_LENGTH_VGA 1280


//#define LINE_LENGTH  LINE_LENGTH_QVGA
#define LINE_LENGTH  LINE_LENGTH_VGA


#define APP_DRV_CONTEXT         1
#define APP_USR_CONTEXT         2
#endif /* _APP_H */
/*******************************************************************************
 End of File
 */

