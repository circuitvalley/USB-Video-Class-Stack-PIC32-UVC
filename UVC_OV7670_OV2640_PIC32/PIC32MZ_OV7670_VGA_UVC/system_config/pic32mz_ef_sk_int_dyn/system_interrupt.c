/*******************************************************************************
 System Interrupts File

  File Name:
    system_interrupt.c

  Summary:
    Raw ISR definitions.
 *******************************************************************************/


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "system/common/sys_common.h"
#include "app.h"
#include "system_definitions.h"
#include "pmp/drv_pmp.h"
// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************
extern APP_DATA appData;
extern uint8_t lines_buffer[640*MAX_LINES_BUFER*2];
extern uint8_t lines_available ;
extern uint8_t frame_index;
extern bool VSYNC;
extern line_data_t lines[MAX_LINES_BUFER];
static uint16_t line_number= 0;

line_data_t *line_write = &lines[0];

void __ISR(_UART1_TX_VECTOR, ipl1AUTO) _IntHandlerDrvUsartTransmitInstance0(void)
{
    DRV_USART_TasksTransmit(sysObj.drvUsart0);
}
void __ISR(_UART1_RX_VECTOR, ipl1AUTO) _IntHandlerDrvUsartReceiveInstance0(void)
{
    DRV_USART_TasksReceive(sysObj.drvUsart0);
}
void __ISR(_UART1_FAULT_VECTOR, ipl1AUTO) _IntHandlerDrvUsartErrorInstance0(void)
{
    DRV_USART_TasksError(sysObj.drvUsart0);
}


void __ISR(_TIMER_1_VECTOR, ipl1AUTO) IntHandlerDrvTmrInstance0(void)
{
    DRV_TMR_Tasks(sysObj.drvTmr0);
}

void __ISR(_USB_VECTOR, ipl4AUTO) _IntHandlerUSBInstance0(void)
{
    DRV_USBHS_Tasks_ISR(sysObj.drvUSBObject);
}

void __ISR(_USB_DMA_VECTOR, ipl4AUTO) _IntHandlerUSBInstance0_USBDMA ( void )
{
    DRV_USBHS_Tasks_ISR_USBDMA(sysObj.drvUSBObject);
}


void __ISR(_DMA2_VECTOR, ipl4AUTO) _IntHandlerSysDmaCh2(void)
{
        BSP_LEDToggle(BSP_LED_2);

    SYS_DMA_ChannelDisable(appData.DMAChannelHandle);

    line_write->line_number = line_number;
    line_write->available_length = LINE_LENGTH;
    line_write = line_write->next;
    line_number++;
          
    SYS_DMA_ChannelTransferAdd(appData.DMAChannelHandle, (const void *)&PORTE, 1, line_write->data, LINE_LENGTH, 1 );
    SYS_DMA_ChannelEnable(appData.DMAChannelHandle);
    
    PLIB_DMA_ChannelXINTSourceFlagClear(DMA_ID_0, DMA_CHANNEL_2, DMA_INT_BLOCK_TRANSFER_COMPLETE);
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_DMA_2);
}

void __ISR(_I2C4_MASTER_VECTOR, ipl1AUTO) _IntHandlerDrvI2CInstance2(void)
{
    DRV_I2C_Tasks(sysObj.drvI2C2);
}

void __ISR(_EXTERNAL_1_VECTOR, IPL1AUTO) _IntHandlerExternalInterruptInstance0(void)
{
    VSYNC  = true;
    line_number = 0;
    
    for(uint8_t i=0; i<MAX_LINES_BUFER; i++ )
    {
        line_write->available_length =0;
        line_write = line_write->next;
    }
    
    SYS_DMA_ChannelDisable(appData.DMAChannelHandle);
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_DMA_2);
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_EXTERNAL_2);    
    SYS_DMA_ChannelTransferAdd(appData.DMAChannelHandle, (const void *)&PORTE, 1, line_write->data, LINE_LENGTH, 1); 
    SYS_DMA_ChannelSetup(appData.DMAChannelHandle, SYS_DMA_CHANNEL_OP_MODE_BASIC, DMA_TRIGGER_EXTERNAL_2);
    SYS_DMA_ChannelEnable(appData.DMAChannelHandle);
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_EXTERNAL_1);    
}

/*******************************************************************************
 End of File
*/
