/*******************************************************************************
  Board Support Package Implementation

  Company:
    Microchip Technology Inc.

  File Name:
    bsp.c

  Summary:
    Board Support Package implementation for PIC32MZ Embedded Connectivity (EC)
    Starter Kit.

  Description:
    This file contains routines that implement the board support package for
    PIC32MZ Embedded Connectivity (EC) Starter Kit.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip Technology Inc.  All rights reserved.

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "bsp.h"


// *****************************************************************************
/* Data Structure: 
    switch_port_channel_map[]

  Summary:
    Maps each switch to its port channel
  
  Description:
    The switch_port_channel_map array, indexed by BSP_SWITCH, maps each switch 
    to its port channel.

  Remarks:
    Refer to bsp.h for usage information.
*/
static const PORTS_CHANNEL switch_port_channel_map[] =
{
    PORT_CHANNEL_E,
};

// *****************************************************************************
/* Data Structure: 
    switch_port_bit_pos_map[]

  Summary:
    Maps each switch to its port bit position
  
  Description:
    The switch_port_bit_pos_map array, indexed by BSP_SWITCH, maps each switch to its port bit position

  Remarks:
    Refer to bsp.h for usage information.
*/
static const PORTS_BIT_POS switch_port_bit_pos_map[] =
{
    PORTS_BIT_POS_6,
};


// *****************************************************************************
/* Function: 
    void BSP_SwitchStateGet(BSP_SWITCH switch);

  Summary:
    Returns the present state (pressed or not pressed) of the specified switch.
  
  Description:
    This function returns the present state (pressed or not pressed) of the
    specified switch.

  Remarks:
    Refer to bsp.h for usage information.
*/

BSP_SWITCH_STATE BSP_SwitchStateGet( BSP_SWITCH bspSwitch )
{
    return ( PLIB_PORTS_PinGet(PORTS_ID_0, switch_port_channel_map[bspSwitch], switch_port_bit_pos_map[bspSwitch]) );
}

// *****************************************************************************
/* Data Structure: 
    led_port_channel_map[]

  Summary:
    Maps each led to its port channel
  
  Description:
    The led_port_channel_map array, indexed by BSP_LED, maps each led to its 
    port channel.

  Remarks:
    Refer to bsp.h for usage information.
*/
static const PORTS_CHANNEL led_port_channel_map[] =
{
    PORT_CHANNEL_B,
};

// *****************************************************************************
/* Data Structure: 
    led_port_bit_pos_map[]

  Summary:
    Maps each led to its port bit position
  
  Description:
    The led_port_bit_pos_map array, indexed by BSP_LED, maps each led to its port 
    bit position.

  Remarks:
    Refer to bsp.h for usage information.
*/
static const PORTS_BIT_POS led_port_bit_pos_map[] =
{
    PORTS_BIT_POS_9,
};

// *****************************************************************************
/* Data Structure: 
    led_active_level_map[]

  Summary:
    Maps each led to its active level
  
  Description:
    The led_active_level_map array, indexed by BSP_LED, maps each led to its active 
    level.

  Remarks:
    Refer to bsp.h for usage information.
*/
static const BSP_LED_ACTIVE_LEVEL led_active_level_map[] =
{
   BSP_LED_ACTIVE_LOW,
};

// *****************************************************************************
/* Function: 
    void BSP_LEDStateSet(BSP_LED led, BSP_LED_STATE state);

  Summary:
    Controls the state of the LED.
  
  Description:
    This function allows the application to specify the state of the LED.

  Remarks:
    Refer to bsp_config.h for usage information.
*/

void BSP_LEDStateSet(BSP_LED led, BSP_LED_STATE state)
{
    /* Set the state of the LED */
    if(led_active_level_map[led] == BSP_LED_ACTIVE_HIGH)
    {
        PLIB_PORTS_PinWrite (PORTS_ID_0 , led_port_channel_map[led], led_port_bit_pos_map[led], 
							 (BSP_LED_STATE_ON == state ? true : false));
    }
    else
    {
        PLIB_PORTS_PinWrite (PORTS_ID_0 , led_port_channel_map[led], led_port_bit_pos_map[led], 
							 (BSP_LED_STATE_ON == state ? false : true));
    }
}

// *****************************************************************************
/* Function: 
    void BSP_LEDToggle(BSP_LED led);

  Summary:
    Toggles the state of the LED between BSP_LED_STATE_ON and BSP_LED_STATE_OFF.
  
  Description:
    This function toggles the state of the LED between BSP_LED_STATE_ON and
    BSP_LED_STATE_OFF.

  Remarks:
    Refer to bsp.h for usage information.
*/    

void BSP_LEDToggle(BSP_LED led)
{
    PLIB_PORTS_PinToggle(PORTS_ID_0, led_port_channel_map[led], led_port_bit_pos_map[led] );
}

// *****************************************************************************
/* Function: 
    BSP_LED_STATE BSP_LEDStateGet(BSP_LED led);

  Summary:
    Returns the present state of the LED.
  
  Description:
    This function returns the present state of the LED.

  Remarks:
    Refer to bsp.h for usage information.
*/    

BSP_LED_STATE BSP_LEDStateGet (BSP_LED led)
{
    bool value;

    /* Get LED Status */
    value = PLIB_PORTS_PinGetLatched (PORTS_ID_0, led_port_channel_map[led], led_port_bit_pos_map[led]);

    if(led_active_level_map[led] == BSP_LED_ACTIVE_LOW)
    {
        value = !value;
    }

    return (value ? BSP_LED_STATE_ON : BSP_LED_STATE_OFF);
}

// *****************************************************************************
/* Function: 
    void BSP_LEDOn(BSP_LED led);

  Summary:
    Switches ON the specified LED.
  
  Description:
    This function switches ON the specified LED.

  Remarks:
    Refer to bsp.h for usage information.
*/

void BSP_LEDOn(BSP_LED led)
{
    if(led_active_level_map[led] == BSP_LED_ACTIVE_HIGH)
    {
        PLIB_PORTS_PinSet( PORTS_ID_0, led_port_channel_map[led], led_port_bit_pos_map[led] );
    }
    else
    {
        PLIB_PORTS_PinClear( PORTS_ID_0, led_port_channel_map[led], led_port_bit_pos_map[led] );
    }
}

// *****************************************************************************
/* Function: 
    void BSP_LEDOff(BSP_LED led);

  Summary:
    Switches Off the specified LED.
  
  Description:
    This function switches Off the specified LED.

  Remarks:
    Refer to bsp.h for usage information.
*/

void BSP_LEDOff(BSP_LED led)
{
    if(led_active_level_map[led] == BSP_LED_ACTIVE_HIGH)
    {
        PLIB_PORTS_PinClear( PORTS_ID_0, led_port_channel_map[led], led_port_bit_pos_map[led] );
    }
    else
    {
        PLIB_PORTS_PinSet( PORTS_ID_0, led_port_channel_map[led], led_port_bit_pos_map[led] );
    }
}
// *****************************************************************************
/* Function: 
    void BSP_USBVBUSSwitchStateSet(BSP_USB_VBUS_SWITCH_STATE state);

  Summary:
    This function enables or disables the USB VBUS switch on the board.
  
  Description:
    This function enables or disables the VBUS switch on the board.

  Remarks:
    Refer to bsp_config.h for usage information.
*/

void BSP_USBVBUSSwitchStateSet(BSP_USB_VBUS_SWITCH_STATE state)
{
    /* Enable the VBUS switch */

    PLIB_PORTS_PinWrite( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_5, state );
}

// *****************************************************************************
/* Function: 
    bool BSP_USBVBUSSwitchOverCurrentDetect(uint8_t port)

  Summary:
    Returns true if the over current is detected on the VBUS supply.
  
  Description:
    This function returns true if over current is detected on the VBUS supply.

  Remarks:
    None.
*/

bool BSP_USBVBUSSwitchOverCurrentDetect(uint8_t port)
{
    return(false);
}

// *****************************************************************************
/* Function: 
    bool BSP_USBVBUSPowerEnable(uint8_t port, bool enable)

  Summary:
    This function controls the USB VBUS supply.
  
  Description:
    This function controls the USB VBUS supply.

  Remarks:
    None.
*/

void BSP_USBVBUSPowerEnable(uint8_t port, bool enable)
{
    /* Enable the VBUS switch */

    PLIB_PORTS_PinWrite( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_5, enable );
}

// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function: 
    void BSP_Initialize(void)

  Summary:
    Performs the necessary actions to initialize a board
  
  Description:
    This function initializes the LED, Switch and other ports on the board.
    This function must be called by the user before using any APIs present in
    this BSP.  

  Remarks:
    Refer to bsp.h for usage information.
*/

void BSP_Initialize(void )
{
    /* Setup the USB VBUS Switch Control Pin */
    BSP_USBVBUSSwitchStateSet(BSP_USB_VBUS_SWITCH_STATE_DISABLE);

    PLIB_PORTS_PinDirectionOutputSet( PORTS_ID_0, led_port_channel_map[BSP_LED_1], led_port_bit_pos_map[BSP_LED_1] );
    *(&ANSELBCLR + (led_port_channel_map[BSP_LED_1] - 1) * 0x40) = 1<<led_port_bit_pos_map[BSP_LED_1];

    /* Switch off LEDs */
    BSP_LEDOff(BSP_LED_1);
}

// *****************************************************************************
/* Function:
    void BSP_GFX_Initialize(void)
  Summary:
    Sets up the PPS for the PIC32MX to work with SPI2 on MOST GFX PICTails
  Description:

  Parameters:

  Return Values:
    None.
  Conditions:
    None
*/

void BSP_GFX_Initialize(uint8_t spichannel)
{
    DDPCONbits.JTAGEN = 0; // Disable JTAG

    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELG = 0;            // Disable all ADC inputs

    if(spichannel == 2)
    {
        SYSKEY = 0x00000000;
        SYSKEY = 0xAA996655;
        SYSKEY = 0x556699AA;
        CFGCONbits.IOLOCK = 0;
        SDI2Rbits.SDI2R = 1;     //PMA4 = SDI2 = RG6
        RPG8Rbits.RPG8R = 6;     //PMA3 = SDO2 = RG8
        SYSKEY = 0x33333333;
    }
    else if(spichannel == 1)
    {
        SYSKEY = 0x00000000;
        SYSKEY = 0xAA996655;
        SYSKEY = 0x556699AA;
        CFGCONbits.IOLOCK = 0;
        SDI1Rbits.SDI1R = 10;     //RPC4 = SDI1 = RC4
        RPD0Rbits.RPD0R = 8;     //PMA3 = SDO2 = RG8
        SYSKEY = 0x33333333;
    }
}

/*******************************************************************************
 End of File
*/
