/*******************************************************************************
  PMP Device Driver Definition

  Company:
    Microchip Technology Inc.

  File Name:
    drv_pmp_dynamic.c

  Summary:
    PMP device driver dynamic multiple client omplementation.

  Description:
    The PMP device driver provides a simple interface to manage the PMP
    modules on Microchip microcontrollers.  This file implements the core
    interface routines for the PMP driver.
    
    While building the driver from source, ALWAYS use this file in the build.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

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
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Include Files
// *****************************************************************************
// *****************************************************************************
#include "system_config.h"
#include "system/int/sys_int.h"
#include "driver/pmp/src/drv_pmp_local.h"

inline void _DRV_PMP_Master_Read_Task(void);
inline void _DRV_PMP_Master_Write_Task(void);
//static void _DRV_PMP_HardwareConfig (DRV_HANDLE);

PMP_MODULE_ID  _pmpID; //global module ID for task machine use
int8_t arrayDirection = 1;
PMP_QUEUE_ELEMENT_OBJECT  PMPcommandBuffer[DRV_PMP_QUEUE_SIZE];                   //This contains the commands to send to the graphics driver
PMP_QUEUE_ELEMENT_OBJECT* PMPqueueIndex = &PMPcommandBuffer[0];                   //pointer to where the command Buffer is currently
PMP_QUEUE_ELEMENT_OBJECT* PMPtaskIndex =  &PMPcommandBuffer[0];                   //pointer to where the command Buffer is currently
volatile uint16_t     PMPqueueCount = 0;

extern SYS_MODULE_OBJ   object;

// *****************************************************************************
// *****************************************************************************
// Section: File Scope Variables
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Driver Hardware instance objects.

  Summary:
    Defines the hardware instances objects that are available on the device.

  Description:
    This data type defines the hardware instance objects that are available on
    the device, so as to capture the hardware state of the instance.

  Remarks:
    Not all modes are available on all devices.
*/
DRV_PMP_OBJ             gDrvPMPObj[DRV_PMP_INSTANCES_NUMBER] ;


// *****************************************************************************
/* Driver Client instance objects.

  Summary:
    Defines the Client instances objects that are available on the device.

  Description:
    This data type defines the Client instance objects that are available on
    the device, so as to capture the Client state of the instance.

  Remarks:
    None.
*/

DRV_PMP_CLIENT_OBJ      gDrvPMPClientObj[DRV_PMP_CLIENTS_NUMBER] ;

// *****************************************************************************
// *****************************************************************************
// Section: File Scope Functions
// *****************************************************************************
// *****************************************************************************

//******************************************************************************
/* Function:
    static void _DRV_PMP_SetupHardware( DRV_PMP_INIT  * pmpInit )

  Summary:
    Sets up the PMP hardware from the initialization structure.

  Description:
    This function sets up the hardware from the initialization structure.
 
  Remarks:
    This function is internally called by the driver
*/

static void _DRV_PMP_SetupHardware( DRV_PMP_INIT * pmpInit )
{
	PMP_MODULE_ID  pmpID =  pmpInit->pmpID;
//	DRV_PMP_BASIC_INIT  pmpBasicInit = pmpInit->PMP_ADDITIONAL_INIT.pmpBasicInit;
	DRV_PMP_POLARITY_OBJECT  polarity = pmpInit->polarity;
	
	/* Idle mode setting */
	if ( pmpInit->stopInIdle == true )
	{
		PLIB_PMP_StopInIdleEnable( pmpID );
	}
	else
	{
		PLIB_PMP_StopInIdleDisable( pmpID );
	}
	
	/* Address multiplexing setting */
	PLIB_PMP_MultiplexModeSelect( pmpID, pmpInit->muxMode );
	
	/* input buffer type selection */
	PLIB_PMP_InputBufferTypeSelect( pmpID, pmpInit->inputBuffer );

	/* pins polarity setting */
	PLIB_PMP_AddressLatchPolaritySelect( pmpID, polarity.addressLatchPolarity );
//	PLIB_PMP_ByteEnablePolaritySelect ( pmpID, polarity.byteEnablePolarity );
	PLIB_PMP_ChipSelectXPolaritySelect( pmpID, PMP_CHIP_SELECT_ONE, polarity.chipselect1Polarity );
	PLIB_PMP_ChipSelectXPolaritySelect( pmpID, PMP_CHIP_SELECT_TWO, polarity.chipselect2Polarity );
	PLIB_PMP_ReadWriteStrobePolaritySelect( pmpID, polarity.rwStrobePolarity );
	PLIB_PMP_WriteEnableStrobePolaritySelect( pmpID, polarity.writeEnableStrobePolarity );
	
	/* Ports Setting */
	PLIB_PMP_AddressPortEnable( pmpID, pmpInit->ports.addressPortsMask );
//	PLIB_PMP_AddressPortDisable( pmpID, !(pmpBasicInit.ports.addressPortsMask) );
	
	if (pmpInit->ports.readWriteStrobe == PORT_ENABLE)
	{
		PLIB_PMP_ReadWriteStrobePortEnable( pmpID );
	}
	else //pmpBasicInit.ports.readWriteStrobe == PORT_DISABLE
	{
		PLIB_PMP_ReadWriteStrobePortDisable( pmpID );
	}
	
	if (pmpInit->ports.writeEnableStrobe == PORT_ENABLE)
	{
		PLIB_PMP_WriteEnableStrobePortEnable( pmpID );
	}
	else //pmpBasicInit.ports.writeEnableStrobe == PORT_DISABLE
	{
		PLIB_PMP_WriteEnableStrobePortDisable( pmpID );
	}
	
    /* PMP Port Setup */
 //  _DRV_PMP_PortSetup( _DRV_PMP_PERIPHERAL_ID_GET(plibId), pmpInit->pinConfig );
 //   gDrvPMPObj[dObj].pinConfig = pmpInit->portsConfig;

} /* _DRV_PMP_SetupHardware */


// *****************************************************************************
// *****************************************************************************
// Section: Driver Interface Function Definitions
// *****************************************************************************
// *****************************************************************************

//******************************************************************************
/* Function:
    SYS_MODULE_OBJ DRV_PMP_Initialize( const SYS_MODULE_INDEX  index,
                                       const SYS_MODULE_INIT * const init )

  Summary:
    Initializes hardware and data for the given instance of the PMP module.

  Description:
    This function initializes hardware for the instance of the PMP module,
    using the hardware initialization given data.  It also initializes all 
    necessary internal data.

  Parameters:
    index           - Identifies the driver instance to be initialized
    
    init            - Pointer to the data structure containing all data
                      necessary to initialize the hardware. This pointer may
                      be null if no data is required and static initialization 
                      values are to be used.

  Returns:
    If successful, it returns a valid handle to a driver instance object.
    Otherwise, it returns SYS_MODULE_OBJ_INVALID.
*/

//SYS_MODULE_OBJ DRV_PMP_Initialize( const SYS_MODULE_INDEX   drvIndex,
//                                   const SYS_MODULE_INIT * const   init )
//{
//	  return(&gDrvPMPObj[drvIndex]);
//}
SYS_MODULE_OBJ DRV_PMP_Initialize( const SYS_MODULE_INDEX   drvIndex,
                                   const SYS_MODULE_INIT    * const init )
{
   
    DRV_PMP_INIT * pmpInit = NULL;
	uint8_t iEntry;

    /* Validate the driver index */
    if ( drvIndex >= DRV_PMP_INSTANCES_NUMBER )
    {
        return SYS_MODULE_OBJ_INVALID;
    }

    /* Assign to the local pointer the init data passed */
    pmpInit = ( DRV_PMP_INIT * ) init;

    /* Object is valid, set it in use */
    gDrvPMPObj[drvIndex].inUse = true;
	
    /* make the status busy */
    gDrvPMPObj[drvIndex].status = SYS_STATUS_BUSY;
	 
    /* Update the PMP Module Index */
    gDrvPMPObj[drvIndex].pmpID = pmpInit->pmpID;

    /* Update the object index */
//    gDrvPMPObj[drvIndex].objIndex = drvIndex;
	
	/* Disable the PMP module */
    PLIB_PMP_Disable(pmpInit->pmpID);
	
	/* PMP hardware setup */
	_DRV_PMP_SetupHardware( pmpInit );
	
    /* Initialize the clients tables. Set each client
     * to indicate no use.
     * We also set the client status to closed to 
     * indicate that this client is not open. Additionally,
     * we also initialize the client pointers in the
     * driver instance object to null. */
	 
	for(iEntry = 0; iEntry < DRV_PMP_CLIENTS_NUMBER; iEntry++)
    {
        gDrvPMPClientObj[iEntry].inUse = false;
        gDrvPMPClientObj[iEntry].status = DRV_PMP_CLIENT_STATUS_INVALID;
//      gDrvPMPClientObj[iEntry].pEventCallBack = NULL;
//      gDrvPMPObj[drvIndex].pDrvPMPClientObj[iEntry] = NULL;
	}
	
	
    /* Update the necessary internal data for Queue operations */
/*
    gDrvPMPObj[drvIndex].queue.fixedHead = (QUEUE_ELEMENT_OBJECT *)malloc(DRV_PMP_QUEUE_SIZE * sizeof(QUEUE_ELEMENT_OBJECT));
    if(gDrvPMPObj[drvIndex].queue.fixedHead == NULL)
    {
        SYS_ASSERT( false, "no Heap memory allocated" );
    }
    
    QUEUE_ELEMENT_OBJECT * elementPointers;
    for (elementPointers = (QUEUE_ELEMENT_OBJECT *)gDrvPMPObj[drvIndex].queue.fixedHead;
    	elementPointers < (QUEUE_ELEMENT_OBJECT *)gDrvPMPObj[drvIndex].queue.fixedHead + DRV_PMP_QUEUE_SIZE;
    	elementPointers++)
    	{
	    	elementPointers->eTransferStatus = TRANSFER_DATA_NEVER_QUEUED;
	    	elementPointers->seqID =0;
	    	elementPointers->nBytesDone = 0;
	    	elementPointers->nRepeatsDone = 0;
	    }		
    
    gDrvPMPObj[drvIndex].queue.head = NULL;
    gDrvPMPObj[drvIndex].queue.tail = NULL;
    gDrvPMPObj[drvIndex].queue.size = DRV_PMP_QUEUE_SIZE;
    gDrvPMPObj[drvIndex].queue.numElements = 0;
*/	
	/* reset the sequence ID */
	gDrvPMPObj[drvIndex].seqID = 0;

    /* transfer is not triggered in the beginning */
    gDrvPMPObj[drvIndex].transferTriggered = false;
	
    /* Set the current driver state */
    gDrvPMPObj[drvIndex].status = SYS_STATUS_READY;

    /* set priority for PMP interrupt source */
    //SYS_INT_VectorPrioritySet(INT_VECTOR_PMP, INT_PRIORITY_LEVEL5);
	
	/* Enable the PMP module */
    PLIB_PMP_Enable(pmpInit->pmpID);

    /* Return the driver handle */
    return((SYS_MODULE_OBJ)&gDrvPMPObj[drvIndex]);
	
} /* DRV_PMP_Initialize */


//******************************************************************************
/* Function:
    void DRV_PMP_Reinitialize( SYS_MODULE_OBJ          pmpDriverObject,
                               const SYS_MODULE_INIT * const init )

  Summary:
    Reinitializes and refreshes the hardware for the instance of the PMP
    module.

  Description:
    This function reinitializes and refreshes the hardware for the instance
    of the PMP module using the hardware initialization given data.
    It does not clear or reinitialize internal data structures.

  Parameters:
    pmpDriverObject - Identifies the driver object returned by the Initialize
                      interface
    init            - Pointer to the data structure containing any data
                      necessary to initialize the hardware

  Returns:
    None.
*/

void DRV_PMP_Reinitialize( SYS_MODULE_OBJ pmpDriverObject,
                           const SYS_MODULE_INIT * const init )
{

    PMP_MODULE_ID	pmpID;
    DRV_PMP_OBJ * 	hDriver;
	DRV_PMP_INIT * pmpInit = NULL;

	hDriver = (DRV_PMP_OBJ *) pmpDriverObject;
    pmpID = hDriver->pmpID;
	
    /* Check for the valid driver object passed */
    SYS_ASSERT( hDriver != NULL, "Driver Object is invalid" );

    /* Valid init structure is present */
    pmpInit = ( DRV_PMP_INIT * ) init;

    /* Stop/Disable the device if needed */
    PLIB_PMP_Disable( pmpID );

    /* Set the current driver state */
    hDriver->status = SYS_STATUS_UNINITIALIZED ;

    /* Setup the Hardware */
    _DRV_PMP_SetupHardware( pmpInit );

    /* Update the necessary internal data for Queue operations */
/*
    hDriver->queue.fixedHead = (QUEUE_ELEMENT_OBJECT *)malloc(DRV_PMP_QUEUE_SIZE * sizeof(QUEUE_ELEMENT_OBJECT));
	hDriver->queue.head = NULL;
    hDriver->queue.tail = NULL;
	hDriver->queue.size = DRV_PMP_QUEUE_SIZE;
    hDriver->queue.numElements = 0;
*/
    /* reset the sequence ID */
    hDriver->seqID = 0;

    /* transfer is not triggered in the beginning */
    hDriver->transferTriggered = false;
	
    /* Start/Enable the device if it was stop/disabled */
    PLIB_PMP_Enable( pmpID );

    /* Set the curent driver state */
    hDriver->status = SYS_STATUS_READY;

} /* DRV_PMP_Reinitialize */


//******************************************************************************
/* Function:
    void DRV_PMP_Deinitialize( SYS_MODULE_OBJ pmpDriverObject )

  Summary:
    Deinitializes the specific module instance of the PMP module.

  Description:
    Deinitializes the specific module instancedisabling its operation (and any
    hardware for driver modules).  Resets all the internal data structures and
    fields for the specified instance to the default settings.

  Parameters:
    pmpDriverObject - Identifies the driver object returned by the Initialize
                      interface

  Returns:
    None
*/

void DRV_PMP_Deinitialize( SYS_MODULE_OBJ pmpDriverObject )
{
    PMP_MODULE_ID	pmpID;
    DRV_PMP_OBJ * 	hDriver;

	hDriver = (DRV_PMP_OBJ *) pmpDriverObject;
    pmpID = hDriver->pmpID;
	
    /* Check for the valid driver object passed */
    SYS_ASSERT( hDriver != NULL, "Driver Object is invalid" );

    // /* Interrupt De-Registration */
    // _DRV_PMP_InterruptSourceDisable( _DRV_PMP_INT_SRC_GET( gDrvPMPObj[dObj].interruptSource) );
    // _DRV_PMP_InterruptSourceDisable( _DRV_PMP_INT_SRC_GET( gDrvPMPObj[dObj].rxInterruptSource) );
    // _DRV_PMP_InterruptSourceDisable( _DRV_PMP_INT_SRC_GET( gDrvPMPObj[dObj].errInterruptSource) );

    /* Stop/Disable the device if needed */
    PLIB_PMP_Disable( pmpID ) ;

    /* free the allocated memory for queue from heap */
//    free(hDriver->queue.fixedHead); //TODO it will free all the elements or just 1?

    /* transfer is not triggered in the beginning */
    hDriver->transferTriggered = false;

    /* Set the Device Status */
    hDriver->status = SYS_STATUS_UNINITIALIZED;

    /* Remove the driver usage */
    hDriver->inUse = false;

} /* DRV_PMP_Deinitialize */


//******************************************************************************
/* Function:
    SYS_STATUS DRV_PMP_Status( SYS_MODULE_OBJ pmpDriverObject )

  Summary:
    Provides the current status of the hardware instance of the PMP module.

  Description:
    This function Provides the current status of the hardware instance of the
    PMP module.

  Parameters:
    pmpDriverObject - Identifies the driver object returned by the Initialize
                      interface

  Returns:
    SYS_STATUS_READY  -  Indicates that any previous module operation for the
                         specified module has completed
                        
    SYS_STATUS_BUSY   -  Indicates that a previous module operation for the
                         specified module has not yet completed
                        
    SYS_STATUS_ERROR  -  Indicates that the specified module is in an error state
*/

SYS_STATUS DRV_PMP_Status( SYS_MODULE_OBJ pmpDriverObject )
{
    
	DRV_PMP_OBJ * 	hDriver;

	hDriver = (DRV_PMP_OBJ *) pmpDriverObject;
	
    /* Check for the valid driver object passed */
    SYS_ASSERT( hDriver != NULL, "Driver Object is invalid" );

    /* Return the status associated with the driver handle */
    return ( hDriver->status );

} /* DRV_PMP_Status */


//******************************************************************************
/* Function:
    void DRV_PMP_Tasks( SYS_MODULE_OBJ pmpDriverObject )

  Summary:
    Used to maintain the driver's state machine and implement its ISR.

  Description:
    This function is used to maintain the driver's internal state machine and
    implement its ISR for interrupt-driven implementations.

  Parameters:
    pmpDriverObject - Identifies the driver object returned by the Initialize
                      interface

  Returns:
    None.
*/

void DRV_PMP_Tasks( SYS_MODULE_OBJ pmpDriverObject )
{
    static DRV_PMP_OBJ* 	hDriver;
    static DRV_PMP_CLIENT_OBJ	*hClient;
    static uint8_t          state = 0;

switch(state)
{

case 0:	//Change case to init/reinit 
    hDriver = (DRV_PMP_OBJ *) pmpDriverObject;
    _pmpID = hDriver->pmpID;

	if ( (hDriver->transferTriggered == false))
	{     

         hClient = PMPtaskIndex->data.hClient;

	     _DRV_PMP_HardwareConfig ((DRV_HANDLE)hClient);

		 PLIB_PMP_Enable(_pmpID);	// turn on the PMP module
         //PLIB_PMP_AddressSet( _pmpID, /*PMPtaskIndex->data.address*/0 );

         hDriver->transferTriggered = true;
	 }
    state = 1;
   
	while (PMPqueueCount != 0) //There are commands to be serviced
	{

        while(PMPtaskIndex->data.nRepeats >= 0)
        {  

 case 1:
     while (PMPtaskIndex->nTransfersDone < PMPtaskIndex->data.nTransfers)
     {

          if(PLIB_PMP_PortIsBusy(_pmpID))
            return;

	    switch(PMPtaskIndex->data.type)
            {
                case ADDRESS:
                 #if defined USE_GFX_PMP
                 DisplaySetCommand(); //Set Address Line Low
                 #endif
                case BUFFERED_WRITE:
                case WRITE:
                 _DRV_PMP_Master_Write_Task();
                 break;

                case READ:
                 _DRV_PMP_Master_Read_Task();
                 break;
            }      

            PMPtaskIndex->nTransfersDone++;  //One transfer is complete	                 
            
     }
           
           PMPtaskIndex->nTransfersDone = 0;  
           PMPtaskIndex->data.nRepeats--;      
}

      PMPqueueCount--;

      #if defined USE_GFX_PMP
      DisplaySetData(); //Set Address Line Low
      #endif

  	  // if one complete element transfer is done, change the status
      PMPtaskIndex->eTransferStatus  = PMP_TRANSFER_FINISHED;

      /* trigger the next transfer if Queue is not empty */
      if(PMPtaskIndex++ == &PMPcommandBuffer[DRV_PMP_QUEUE_SIZE-1])
      {
           PMPtaskIndex = &PMPcommandBuffer[0];     
      }

     }

 state = 0; //Reset State Machine
 return;
}

}
/* DRV_PMP_Tasks */

/* internal Read API */
inline void _DRV_PMP_Master_Read_Task(void)
{
	static DRV_PMP_QUEUE_ELEMENT_OBJ *dataElement;
	static uint8_t 	       *buffer;
        static uint16_t        *wordBuffer;

switch(PMPtaskIndex->eTransferStatus)
{

    case QUEUED_BUT_PMP_TRANSFER_NOT_STARTED:

        dataElement = &PMPtaskIndex->data;

        PLIB_PMP_MasterReceive( _pmpID ); //Perform the fake read

        if(dataElement->hClient->modeConfig.portSize  == PMP_DATA_SIZE_8_BITS ) // 8 bit data lines
        {
	    buffer = (uint8_t*)dataElement->addressBuffer;	
            PMPtaskIndex->eTransferStatus = MASTER_8BIT_TRANSFER_IN_PROGRESS;
            return;

    case MASTER_8BIT_TRANSFER_IN_PROGRESS:
         PMCONbits.PMPEN = 0; // disable PMP	   
         *buffer = PLIB_PMP_MasterReceive( _pmpID );
         buffer += arrayDirection;
	}
        else //16 bit data lines
        {
            wordBuffer = (uint16_t*)dataElement->addressBuffer;
            PMPtaskIndex->eTransferStatus = MASTER_16BIT_TRANSFER_IN_PROGRESS;
            return;

    case MASTER_16BIT_TRANSFER_IN_PROGRESS:
            PMCONbits.PMPEN = 0; // disable PMP
	    *wordBuffer = PLIB_PMP_MasterReceive( _pmpID );
            wordBuffer += arrayDirection;
	 }

       PMCONbits.PMPEN = 1; // enable  PMP

    default:
        return;
}
}

/* internal master write api */
inline void  _DRV_PMP_Master_Write_Task (void)
{

    static uint8_t* 	    buffer;
    static uint8_t          byteSwap = 0;      //Swapping flag for endian
    static int8_t           order[2] = {1,-1}; //Endian array

    switch(PMPtaskIndex->eTransferStatus)
    {

         case MASTER_8BIT_TRANSFER_IN_PROGRESS:
                buffer = (uint8_t*)&PMPtaskIndex->data.buffer + 1;
                PMPtaskIndex->eTransferStatus = MASTER_8BIT_TRANSFER_CONTINUE;

         case MASTER_8BIT_TRANSFER_CONTINUE:
                buffer--;
                PLIB_PMP_MasterSend(_pmpID, *(buffer));
                break;

         case MASTER_8BIT_BUFFER_IN_PROGRESS:
                byteSwap = 0;
                buffer = (uint8_t*)PMPtaskIndex->data.addressBuffer;
                PMPtaskIndex->eTransferStatus = MASTER_8BIT_BUFFER_CONTINUE;

         case MASTER_8BIT_BUFFER_CONTINUE:                 
                PLIB_PMP_MasterSend(_pmpID, *(buffer+order[byteSwap]));
                byteSwap ^= 1;
                buffer += arrayDirection;
                break;

         case MASTER_16BIT_TRANSFER_IN_PROGRESS:              
                PLIB_PMP_MasterSend( _pmpID, *((uint16_t*)&PMPtaskIndex->data.buffer + 1 - (PMPtaskIndex->nTransfersDone>>1)));                        
                PMPtaskIndex->nTransfersDone++;
                break;

         case MASTER_16BIT_BUFFER_IN_PROGRESS:                 
                PLIB_PMP_MasterSend(_pmpID, (uint16_t)*PMPtaskIndex->data.addressBuffer);
                PMPtaskIndex->data.addressBuffer += arrayDirection;
 		PMPtaskIndex->nTransfersDone++; 
                break;    
        default:
                break;
}
}

//******************************************************************************
/* Function:
    DRV_HANDLE DRV_PMP_Open( const SYS_MODULE_INDEX    drvIndex,
                             const DRV_IO_INTENT       intent )

  Summary:
    Opens the specific module instance and returns a handle.

  Description:
    This function opens a driver for use by any client module and provides a
    handle that must be provided to any of the other driver operations to
    identify the caller and the instance of the driver/hardware module.

  Parameters:
    drvIndex        - Identifier for the driver instance to be initialized
    ioIntent        - Possible values from the enumeration DRV_IO_INTENT

  Returns:
    If successful, the routine returns a valid open-instance handle (a number
    identifying both the caller and the module instance).
    If an error occurs, the return value is DRV_HANDLE_INVALID.
*/

DRV_HANDLE DRV_PMP_Open( const SYS_MODULE_INDEX   drvIndex,
                         const DRV_IO_INTENT      ioIntent )
{
    // /* Multi client variables are removed from single client builds. */
    // DRV_PMP_CLIENT_OBJ_HANDLE clientObj = (DRV_PMP_CLIENT_OBJ_HANDLE) 0;
    // DRV_PMP_OBJ_HANDLE dObj = 0;
    
	unsigned int iClient;
    bool foundIt;
    DRV_PMP_CLIENT_OBJ * hClient;
	
	
    /* Validate the driver index */
    if( drvIndex >= DRV_PMP_INSTANCES_NUMBER )
    {
        return DRV_HANDLE_INVALID;
    }

	/* The PMP module should be ready */
	if(gDrvPMPObj[drvIndex].status != SYS_STATUS_READY)
    {
        return DRV_HANDLE_INVALID;
    }
        /* checking the maximum number of client limit */
    	if(gDrvPMPObj[drvIndex].numClients >= DRV_PMP_CLIENTS_NUMBER)
	{
		SYS_ASSERT( false, "Client Overflow" );
        return DRV_HANDLE_INVALID;
        }

	/* Single client mode */
	/* hardware instance is already handling a client in exclusive mode so cant open any new clients */
	if( ( gDrvPMPObj[drvIndex].numClients == 1 ) && gDrvPMPObj[drvIndex].IsExclusive == true )
	{
		SYS_ASSERT( false, "hardware instance is already handling a client in exclusive mode so cant open any new clients" );
        return DRV_HANDLE_INVALID;
        }
	
	/* need of a single client mode, which is not available */
	/* hardware instance is already handling a client, so cant open another in exclusive mode */
	if( ( gDrvPMPObj[drvIndex].numClients > 0) && DRV_IO_ISEXCLUSIVE( ioIntent ) )   
	{
		SYS_ASSERT( false, "hardware instance is already handling a client, so cant open another in exclusive mode" );
        return DRV_HANDLE_INVALID;
        }
	
    /* Get the handle to the client table 
     * for this particular driver instance */
       
    foundIt = false;
    
    /* OSAL - Lock Mutex */
    for (iClient = 0; iClient < DRV_PMP_CLIENTS_NUMBER ; iClient++)
    {
        if ( !gDrvPMPClientObj[iClient].inUse )
        {
            
            gDrvPMPClientObj[iClient].inUse  = true;
            foundIt = true;
            break;
        }
    }//end for (iClient = 0; iClient < DRV_PMP_CLIENTS_NUMBER ; iClient++)
    
    /* OSAL - Unlock Mutex */

    if ( !foundIt ) 
    {
        /* Couldn't find open slot in object array */
        
 //       gDrvPMPObj[drvIndex].statusBadClient = PMP_CLIENT_NOTAVAIL;
        return  DRV_HANDLE_INVALID ;
    }

    /* From here on we start accessing the client via a pointer */

    hClient = &gDrvPMPClientObj[iClient];

    /* Fill in driver client data structure */
    
    /* Remember which PMP control driver owns me */
    hClient->hDriver        = &gDrvPMPObj[drvIndex]; 
    
	/* remember the client's intent */
	hClient->intent			= ioIntent;
	
    /* Clear prior value */
    
//    hClient->pEventCallBack = NULL;

    /* Store the handle in the driver object
     * client table */

 //   gDrvUSBObj[drvIndex].pDrvPMPClientObj[iClient] = hClient;
	
    /* Update that, the client is opened in exclusive access mode */
    if( DRV_IO_ISEXCLUSIVE( ioIntent ) )
    {
        gDrvPMPObj[drvIndex].IsExclusive = true;
    }
    else
    {
        gDrvPMPObj[drvIndex].IsExclusive = false;
    }

    hClient->status         = DRV_PMP_CLIENT_STATUS_OPEN;
	
    gDrvPMPObj[drvIndex].numClients++;

    /* To Do: OSAL - Unlock Mutex */

	/* Return the client object */
    return ( ( DRV_HANDLE ) hClient );
	
} /* End of DRV_PMP_Open */


//******************************************************************************
/* Function:
    void DRV_PMP_Close( DRV_HANDLE hClient )

  Summary:
    Closes an opened instance of a driver.

  Description:
    This function closes an opened instance of a driver, invalidating the
    specified handle.

  Parameters:
    hClient       - A valid open instance handle, returned from the driver's
                   open routine

  Returns:
    None
*/

void DRV_PMP_Close( DRV_HANDLE hClient )
{
    DRV_PMP_CLIENT_OBJ * hClientObj;
    DRV_PMP_OBJ * hDriver;

    /* Get the Client object from the handle passed */
	 hClientObj = (DRV_PMP_CLIENT_OBJ *)hClient;

    /* Check for the Client validity */
    SYS_ASSERT( hClientObj != NULL, "Invalid Client Object" ) ;

    /* To Do: OSAL - lock Mutex */

    /* Free the Client Instance */
    hClientObj->inUse = false ;
    
    /* reduce the numClients info saved in driver object */
    hDriver = (DRV_PMP_OBJ *)hClientObj->hDriver;
    hDriver->numClients--;

    /* To Do: OSAL - unlock Mutex */

    /* Update the Client Status */
    hClientObj->status = PMP_CLIENT_STATUS_CLOSED;

} /* DRV_PMP_Close */


//******************************************************************************
/* Function:
    DRV_PMP_CLIENT_STATUS DRV_PMP_ClientStatus(DRV_HANDLE hClient)

  Summary:
    Gets the status of the module instance associated with the handle.

  Description:
    This function gets the status of the module instance associated with the
    handle.

  Parameters:
    hClient       - A valid open-instance handle, returned from the driver's
                   open routine

  Returns:
    DRV_PMP_CLIENT_STATUS value describing the current status of the driver.
*/

DRV_PMP_CLIENT_STATUS DRV_PMP_ClientStatus( DRV_HANDLE hClient )
{
    DRV_PMP_CLIENT_OBJ * hClientObj;

    /* Get the Client object from the handle passed */
	 hClientObj = (DRV_PMP_CLIENT_OBJ *)hClient;

    /* Check for the Client validity */
    SYS_ASSERT( hClientObj != NULL, "Invalid Client Object" ) ;

    /* Return the client status associated with the handle passed */
    return( hClientObj->status );

} /* DRV_PMP_ClientStatus */


// *****************************************************************************
/* Function:
    void DRV_PMP_ModeConfig ( DRV_HANDLE hClient,
                                 const DRV_PMP_MODE_CONFIG * const config )

  Summary:
    Configure the PMP modes.

  Description:
    This function configures the modes for client in which it wants to operate. 
    Different master-slave modes, 8/16 data bits selection, address 
    increment/decrement, interrupt mode, wait states, etc., can be configured 
    through this function.
	
  Parameters:
    hClient    	- Client handle obtained from DRV_PMP_Open API

    config      - Pointer to the structure which will have all of the required 
                 PMP modes configuration

  Returns:
    None.
*/

void DRV_PMP_ModeConfig( DRV_HANDLE hClient,
                                 DRV_PMP_MODE_CONFIG config )
{
    DRV_PMP_CLIENT_OBJ  * hClientObj;
    DRV_PMP_OBJ         * hDriver;
	
    /* Get the Client object from the handle passed */
	 hClientObj = (DRV_PMP_CLIENT_OBJ *)hClient;

	/* Check for a valid client */
    SYS_ASSERT(hClientObj != NULL, "Invalid client handle");
	
     /* Client should have been initialized */
   	SYS_ASSERT(hClientObj->inUse, "Client not in use");
    
    hDriver = (DRV_PMP_OBJ * )hClientObj->hDriver;

    /* Stop/Disable the device */
    PLIB_PMP_Disable( hDriver->pmpID );

    SYS_INT_SourceStatusClear(INT_SOURCE_PARALLEL_PORT);

	/* saving all the configurations in the client structure */
	hClientObj->modeConfig = (DRV_PMP_MODE_CONFIG )config;

    /* Restart the device */
    PLIB_PMP_Enable( hDriver->pmpID );

} /* DRV_PMP_ModeConfig */

/* it sets up the actual PMP hardware registers as per the requiremnt of the client */
void _DRV_PMP_HardwareConfig (DRV_HANDLE hClient)
{

    DRV_PMP_CLIENT_OBJ  * hClientObj;
    DRV_PMP_OBJ         * hDriver;
    PMP_MODULE_ID	pmpID;

    /* Get the Client object from the handle passed */
    hClientObj = (DRV_PMP_CLIENT_OBJ *)hClient;

    hDriver = (DRV_PMP_OBJ * )hClientObj->hDriver;

    pmpID = hDriver->pmpID;

    	/* Stop/Disable the device */
   // PLIB_PMP_Disable( pmpID );

/* setting the PMP hardware according to configuration done in DRV_PMP_ModeConfig API */

	/* set the operating mode */
	PLIB_PMP_OperationModeSelect( pmpID, hClientObj->modeConfig.pmpMode );

/* interrupt mode selection */
	
    // Interrupt flag cleared on the safer side
     //  SYS_INT_SourceStatusClear(INT_SOURCE_PARALLEL_PORT);
	
	/* setting the hardware for the required interrupt mode */
	PLIB_PMP_InterruptModeSelect( pmpID, hClientObj->modeConfig.intMode );

	if (( hClientObj->modeConfig.pmpMode == PMP_LEGACY_SLAVE) ||
		( hClientObj->modeConfig.pmpMode == PMP_MASTER_READ_WRITE_STROBES_MULTIPLEXED) || 
		( hClientObj->modeConfig.pmpMode == PMP_MASTER_READ_WRITE_STROBES_INDEPENDENT))
	{	
		if(hClientObj->modeConfig.intMode == PMP_INTERRUPT_EVERY_RW_CYCLE)
		{
			PLIB_INT_SourceEnable(INT_ID_0,INT_SOURCE_PARALLEL_PORT);

		}
		else if (hClientObj->modeConfig.intMode == PMP_INTERRUPT_NONE)
		{
                        PLIB_INT_SourceDisable(INT_ID_0,INT_SOURCE_PARALLEL_PORT);
		}
		else
		{
		SYS_ASSERT( false, "Interrupt Mode is invalid" );
		}
	} 	
/*	else if ((hClientObj->modeConfig.pmpMode ==PMP_BUFFERED_SLAVE) || (hClientObj->modeConfig.pmpMode == PMP_ENHANCED_SLAVE))
	{
		if((hClientObj->modeConfig.intMode == PMP_INTERRUPT_EVERY_RW_CYCLE) || (hClientObj->modeConfig.intMode == PMP_INTERRUPT_BUFFER_3_IS_ACCESSED))
		{
		// This should eventually use the Interrupt PLIB // TODO
			// Enable the interrupt
			IEC1bits.PMPIE = 1;
			// Set the Interrupt Prioriry
			IPC7bits.PMPIP = 6;
		}
		else
		{
			// This should eventually use the Interrupt PLIB // TODO
			// Disable the interrupt
			IEC1bits.PMPIE = 0;
		}
		
	}
*/
        	/* Address Increment/Decrement mode setting */
/*	if ((hClientObj->modeConfig.pmpMode == PMP_BUFFERED_SLAVE) && ( hClientObj->modeConfig.incrementMode != PMP_BUFFERS_AUTO_INCREMENT))
         in Buffered Slave mode, buffer auto increment has to be enabled 
	{
		SYS_ASSERT( false, "Increment Mode Does not match with Operating Mode" );
          //      return;
	}
        */
	PLIB_PMP_AddressIncrementModeSelect( pmpID, hClientObj->modeConfig.incrementMode );

	/* Data size (4/8/16 bit data width) setting */
//	SYS_ASSERT( hClientObj->modeConfig.portSize  != PMP_DATA_SIZE_FOUR_BITS, "Data port size is Not Supported" ); // 4 bit data size is not supported in 32bit devices
	PLIB_PMP_DataSizeSelect( pmpID, hClientObj->modeConfig.portSize );

	/* wait states setting */
	PLIB_PMP_WaitStatesDataHoldSelect( pmpID, hClientObj->modeConfig.waitStates.dataHoldWait );
	PLIB_PMP_WaitStatesDataSetUpSelect( pmpID, hClientObj->modeConfig.waitStates.dataWait );
	PLIB_PMP_WaitStatesStrobeSelect( pmpID, hClientObj->modeConfig.waitStates.strobeWait );

	/* Chip Selection */
	PLIB_PMP_ChipSelectFunctionSelect( pmpID, hClientObj->modeConfig.chipSelect ); // this line should be used when plib code is corrected
	PLIB_PMP_ChipSelectXEnable(pmpID, hClientObj->modeConfig.chipSelect); // temporary, remove later when plib is corrected
//PMAENbits.PTEN15=1;
	PMADDRbits.CS2=0; // temporary, remove later when plib is corrected
	PMADDRbits.CS1=1; // temporary, remove later when plib is corrected
	PMCONbits.CSF=0b10; // temporary, remove later when plib is corrected
//	PORTFbits.RF13 = PORTDbits.RD10; //RD10 is chips2, RF12 is connected to chip select of ext RAM
//	PORTFbits.RF13 = 0;

    /* PMP Port Setup */
//    _DRV_PMP_PortSetup( _DRV_PMP_PERIPHERAL_ID_GET(gDrvPMPObj[dObj].pmpID ), hClientObj->portsConfig );

 	/* end of hardware configuration */

	
} // End of _DRV_PMP_HardwareConfig function
	
	
// *****************************************************************************
/* Function:
   uint32_t   DRV_PMP_Read ( DRV_HANDLE hClient,
                            uint32_t address,
                            unsigned char* buffer,
                            uint32_t nBytes)

  Summary:
    Read the data from external device.

  Description:
    This function reads the given number of data bytes from the given address of 
    the external device to the MCU buffer through the selected PMP instance. This 
    function should be used for all the master and slave modes. Proper configuration 
    should be done using DRV_PMP_ModeConfig() before calling this function.

  Parameters:
    hClient       - A valid open instance handle, returned from the driver's
                   open routine
    address      - Starting address of the slave device from where data has to be read. 
                   It does not have any significance for legacy slave mode and buffer mode. 
                   In PMP enhanced slave mode (i.e., addressable buffer slave mode), 
                   this parameter  should be the buffer number to be used.
    buffer       - Pointer to buffer into which the data read through the PMP instance
                   will be placed. Even if only one word has to be tranferred, pointer 
                   should be used.
    nBytes       - Number of bytes that need to be read through the PMP instance
	
  Returns:
    Returns the position number of the queue, where the data element was stored. 
    Returns '0' when there is no place in the queue to store the data.
  
*/

PMP_QUEUE_ELEMENT_OBJECT* 	DRV_PMP_Read ( DRV_HANDLE hClient,
									uint32_t address,
									uint16_t* buffer,
									uint32_t nBytes)
{

    DRV_PMP_CLIENT_OBJ  * hClientObj;
	
    /* Get the Client object from the handle passed */
	 hClientObj = (DRV_PMP_CLIENT_OBJ *)hClient;

	/* Check for a valid client */
    SYS_ASSERT(hClientObj != NULL, "Invalid client handle");
	
    /* Client should have been initialized */
   	SYS_ASSERT(hClientObj->inUse, "Client not in use");

   if(PMPqueueCount >= (DRV_PMP_QUEUE_SIZE-1)) 
   {
        return(NULL);  //queue is full
   }

    PMPqueueIndex->eTransferStatus = QUEUED_BUT_PMP_TRANSFER_NOT_STARTED; //saving the status of the PMP transfer of the element

	PMPqueueIndex->data.hClient = hClientObj;
	PMPqueueIndex->data.addressBuffer = buffer;
	PMPqueueIndex->data.nTransfers = nBytes + 1;
	PMPqueueIndex->data.nRepeats = 0; // repeatCount is not used in reading, so it's a dont care

    if(address == false)
	{
          PMPqueueIndex->data.type = READ;
    }   
    else
    {
         PMPqueueIndex->data.type = ADDRESS;
    }

   PMP_QUEUE_ELEMENT_OBJECT* index = PMPqueueIndex;

   if(PMPqueueIndex == &PMPcommandBuffer[DRV_PMP_QUEUE_SIZE-1])
   {
        PMPqueueIndex = &PMPcommandBuffer[0];
   }
   else
   {
        PMPqueueIndex++;
   } 

   PMPqueueCount++;

   return(index); //return a pointer to the queue object 

} /* End of DRV_PMP_Read */ 


// *****************************************************************************
/* Function:
   uint32_t   DRV_PMP_Write ( DRV_HANDLE hClient,
                            uint32_t address,
                            unsigned char* buffer,
                            uint32_t nBytes,
                            uint32_t repeatCount)

  Summary:
    Transfers the data from MCU to the external device.

  Description:
    This function transfer the given number of data bytes from the MCU buffer 
    location to the defined address of the external device through the selected 
    PMP instance. It repeats the operation n (=repeatCount) number of times as 
    well. This function should be used for all the master and slave modes. Proper
    configuration should be done using DRV_PMP_ModeConfig before calling this function.

  Parameters:
    hClient       - A valid open-instance handle, returned from the driver's
                   open routine
    address      - Starting address of the slave device where data has to be written. 
                   It does not have any significance for legacy slave mode and buffer 
                   mode. In PMP enhanced slave mode (i.e., addressable buffer slave 
                   mode), this parameter should be the buffer number to be used.
    buffer       - Pointer to MCU Buffer from which the data will be written
                   through the PMP instance. even if only one word has to be 
                   tranferred, pointer should be used.
    nBytes       - Total number of bytes that need to be written through the 
                   PMP instance
    repeatCount  - Number of times the data set (nBytes of data) to be repetedly written. 
                   This value should be 0 if user does not want any repetition. If 
                   repeatCount is greater than 0, then after writing every nBytes 
                   of data, the buffer starts pointing to its first element. Ideally, 
                   PMP Address should be in auto-increment/decrement mode for 
                   repeatCount greater than 0.
	
   Returns:
    Returns a 32-bit ID with which status of the transfer can be checked later.
    Returns '0' when there is no place in the queue to store the data.
 
*/				   
 PMP_QUEUE_ELEMENT_OBJECT* DRV_PMP_Write ( DRV_HANDLE* hClient,
									   bool address,
									   uint32_t *buffer,
									   uint32_t nBytes,
									   uint32_t repeatCount)
{

   if(PMPqueueCount >= (DRV_PMP_QUEUE_SIZE-1)) 
   {
        return(NULL);  //queue is full
   }

    PMPqueueIndex->data.hClient = (DRV_PMP_CLIENT_OBJ *)*hClient;
    PMPqueueIndex->eTransferStatus = PMPqueueIndex->data.hClient->modeConfig.portSize; //saving the status of the PMP transfer of the element
	
	PMPqueueIndex->data.nTransfers = nBytes;
	PMPqueueIndex->data.nRepeats = repeatCount;

    if(address == false)
	{
         if(nBytes <= MAX_NONBUFFERED_BYTE_COUNT)
         {
	          PMPqueueIndex->data.buffer = (*buffer) << ((MAX_NONBUFFERED_BYTE_COUNT - nBytes)<<3); //Shift over for easier task machine data access
              PMPqueueIndex->eTransferStatus = MASTER_8BIT_TRANSFER_IN_PROGRESS + PMPqueueIndex->data.hClient->modeConfig.portSize; //saving the status of the PMP transfer of the element
              PMPqueueIndex->data.type = WRITE;
         }
         else
         {
              PMPqueueIndex->data.addressBuffer = (uint16_t*)buffer;
              PMPqueueIndex->eTransferStatus = MASTER_8BIT_BUFFER_IN_PROGRESS + PMPqueueIndex->data.hClient->modeConfig.portSize; //saving the status of the PMP transfer of the element
              PMPqueueIndex->data.type = BUFFERED_WRITE;
         }
    }   
    else
    {
	     PMPqueueIndex->data.buffer = (*buffer) << ((MAX_NONBUFFERED_BYTE_COUNT - nBytes)<<3); //Shift over for easier task machine data access
         PMPqueueIndex->data.type = ADDRESS;
    }

   PMP_QUEUE_ELEMENT_OBJECT* index = PMPqueueIndex;

   if(PMPqueueIndex == &PMPcommandBuffer[DRV_PMP_QUEUE_SIZE-1])
   {
        PMPqueueIndex = &PMPcommandBuffer[0];
   }
   else
   {
        PMPqueueIndex++;
   } 

   PMPqueueCount++;
   return(index); //return a pointer to the queue object 

} /* End of DRV_PMP_Write */


// *****************************************************************************
/* Function:
    DRV_PMP_TRANSFER_STATUS DRV_PMP_TransferStatus( DRV_HANDLE hClient )

  Summary:
    Returns the transmitter and receiver transfer status.

  Description:
    This function returns the status of a particular transfer whose ID has
    been specified as input.

  Parameters:
    drvIndex       - Identifier for the object instance to be opened
    seqID          - A valid ID returned from read/write transfer functions

  Returns:
    A DRV_PMP_TRANSFER_STATUS value describing the current status of the
    transfer.
*/

DRV_PMP_TRANSFER_STATUS DRV_PMP_TransferStatus( PMP_QUEUE_ELEMENT_OBJECT* queueObject)
{
    return queueObject->eTransferStatus;

} /* DRV_PMP_TransferStatus */




/*******************************************************************************
End of File
*/
