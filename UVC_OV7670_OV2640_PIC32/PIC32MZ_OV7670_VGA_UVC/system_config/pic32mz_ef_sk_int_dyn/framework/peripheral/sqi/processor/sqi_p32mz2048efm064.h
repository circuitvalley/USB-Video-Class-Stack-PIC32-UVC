/* Created by plibgen $Revision: 1.31 $ */

#ifndef _SQI_P32MZ2048EFM064_H
#define _SQI_P32MZ2048EFM064_H

/* Section 1 - Enumerate instances, define constants, VREGs */

#include <xc.h>
#include <stdbool.h>

#include "peripheral/peripheral_common_32bit.h"

/* Default definition used for all API dispatch functions */
#ifndef PLIB_INLINE_API
    #define PLIB_INLINE_API extern inline
#endif

/* Default definition used for all other functions */
#ifndef PLIB_INLINE
    #define PLIB_INLINE extern inline
#endif

typedef enum {

    SQI_ID_0 = _SQI1_BASE_ADDRESS,
    SQI_NUMBER_OF_MODULES = 1

} SQI_MODULE_ID;

typedef enum {

    SQI_XFER_MODE_XIP = 3,
    SQI_XFER_MODE_DMA = 2,
    SQI_XFER_MODE_PIO = 1

} SQI_XFER_MODE;

typedef enum {

    SQI_DATA_MODE_3 = 3,
    SQI_DATA_MODE_0 = 0

} SQI_DATA_MODE;

typedef enum {

    SQI_DATA_FORMAT_LSBF = 1,
    SQI_DATA_FORMAT_MSBF = 0

} SQI_DATA_FORMAT;

typedef enum {

    SQI_DATA_OEN_QUAD = 2,
    SQI_DATA_OEN_DUAL = 1,
    SQI_DATA_OEN_SINGLE = 0

} SQI_DATA_OEN;

typedef enum {

    SQI_CS_OEN_BOTH = 3,
    SQI_CS_OEN_1 = 2,
    SQI_CS_OEN_0 = 1,
    SQI_CS_OEN_NONE = 0

} SQI_CS_OEN;

typedef enum {

    SQI_CMD_RECEIVE = 2,
    SQI_CMD_TRANSMIT = 1,
    SQI_CMD_IDLE = 0

} SQI_XFER_CMD;

typedef enum {

    SQI_LANE_QUAD = 2,
    SQI_LANE_DUAL = 1,
    SQI_LANE_SINGLE = 0

} SQI_LANE_MODE;

typedef enum {

    SQI_CS_1 = 1,
    SQI_CS_0 = 0

} SQI_CS_NUM;

typedef enum {

    CLK_DIV_2048 = 0x400,
    CLK_DIV_1024 = 0x200,
    CLK_DIV_512 = 0x100,
    CLK_DIV_256 = 0x80,
    CLK_DIV_128 = 0x40,
    CLK_DIV_64 = 0x20,
    CLK_DIV_32 = 0x10,
    CLK_DIV_16 = 0x8,
    CLK_DIV_8 = 0x4,
    CLK_DIV_4 = 0x2,
    CLK_DIV_2 = 0x1,
    CLK_DIV_1 = 0x0

} SQI_CLK_DIV;

typedef enum {

    ADDR_BYTES_4 = 4,
    ADDR_BYTES_3 = 3,
    ADDR_BYTES_2 = 2,
    ADDR_BYTES_1 = 1,
    ADDR_BYTES_0 = 0

} SQI_ADDR_BYTES;

typedef enum {

    DUMMY_BYTES_7 = 7,
    DUMMY_BYTES_6 = 6,
    DUMMY_BYTES_5 = 5,
    DUMMY_BYTES_4 = 4,
    DUMMY_BYTES_3 = 3,
    DUMMY_BYTES_2 = 2,
    DUMMY_BYTES_1 = 1,
    DUMMY_BYTES_0 = 0

} SQI_DUMMY_BYTES;

typedef enum {

    MODE_BYTES_3 = 3,
    MODE_BYTES_2 = 2,
    MODE_BYTES_1 = 1,
    MODE_BYTES_0 = 0

} SQI_MODE_BYTES;

typedef enum {

    SQI_DMAERROR = 11,
    SQI_PKTCOMP = 10,
    SQI_BDDONE = 9,
    SQI_CONTHR = 8,
    SQI_CONEMPTY = 7,
    SQI_CONFULL = 6,
    SQI_RXTHR = 5,
    SQI_RXEMPTY = 3,
    SQI_RXFULL = 4,
    SQI_TXTHR = 2,
    SQI_TXEMPTY = 0,
    SQI_TXFULL = 1

} SQI_INTERRUPTS;

typedef enum {

    BD_STATE_DISABLED = 5,
    BD_STATE_DONE = 4,
    BD_STATE_PROCESSING_DATA = 3,
    BD_STATE_BEING_FETCHED = 2,
    BD_STATE_FETCH_REQ_PENDING = 1,
    BD_STATE_IDLE = 0

} SQI_BD_STATE;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/sqi_XIPSDRCommandDDRData_Default.h"
#include "../templates/sqi_XIPDDRMode_Default.h"
#include "../templates/sqi_XIPNumberOfDummyBytes_Default.h"
#include "../templates/sqi_XIPNumberOfAddressBytes_Default.h"
#include "../templates/sqi_XIPReadOpCode_Default.h"
#include "../templates/sqi_XIPLaneMode_Default.h"
#include "../templates/sqi_XIPControlWord1_Default.h"
#include "../templates/sqi_XIPChipSelect_Default.h"
#include "../templates/sqi_XIPModeBytes_Default.h"
#include "../templates/sqi_XIPModeCode_Default.h"
#include "../templates/sqi_XIPControlWord2_Default.h"
#include "../templates/sqi_EnableControl_Default.h"
#include "../templates/sqi_CSOutputEnable_Default.h"
#include "../templates/sqi_DataOutputEnable_Default.h"
#include "../templates/sqi_ConBufferReset_Default.h"
#include "../templates/sqi_RxBufferReset_Default.h"
#include "../templates/sqi_TxBufferReset_Default.h"
#include "../templates/sqi_SoftReset_Default.h"
#include "../templates/sqi_BurstControl_Default.h"
#include "../templates/sqi_HoldPinControl_Default.h"
#include "../templates/sqi_WPPinControl_Default.h"
#include "../templates/sqi_ReceiveLatch_Unsupported.h"
#include "../templates/sqi_DataFormat_Default.h"
#include "../templates/sqi_DataModeControl_Default.h"
#include "../templates/sqi_TransferModeControl_Default.h"
#include "../templates/sqi_ConfigWord_Default.h"
#include "../templates/sqi_StatusCheck_Default.h"
#include "../templates/sqi_DDRMode_Default.h"
#include "../templates/sqi_CSDeassert_Default.h"
#include "../templates/sqi_ChipSelect_Default.h"
#include "../templates/sqi_LaneMode_Default.h"
#include "../templates/sqi_TransferCommand_Default.h"
#include "../templates/sqi_TransferCount_Default.h"
#include "../templates/sqi_ControlWord_Default.h"
#include "../templates/sqi_ClockDivider_Default.h"
#include "../templates/sqi_ClockReady_Default.h"
#include "../templates/sqi_ClockControl_Default.h"
#include "../templates/sqi_RxBufThreshold_Default.h"
#include "../templates/sqi_TxBufThreshold_Default.h"
#include "../templates/sqi_RxBufIntThreshold_Default.h"
#include "../templates/sqi_TxBufIntThreshold_Default.h"
#include "../templates/sqi_InterruptControl_Default.h"
#include "../templates/sqi_InterruptStatus_Default.h"
#include "../templates/sqi_TxData_Default.h"
#include "../templates/sqi_RxData_Default.h"
#include "../templates/sqi_TxBufferFree_Default.h"
#include "../templates/sqi_RxBufferCount_Default.h"
#include "../templates/sqi_ConBufAvailable_Default.h"
#include "../templates/sqi_CommandStatus_Default.h"
#include "../templates/sqi_DataPinStatus_Default.h"
#include "../templates/sqi_RxUnderRun_Default.h"
#include "../templates/sqi_TxOverFlow_Default.h"
#include "../templates/sqi_DMAEnable_Default.h"
#include "../templates/sqi_BDPollingEnable_Default.h"
#include "../templates/sqi_DMABDFetch_Default.h"
#include "../templates/sqi_BDCurrentAddress_Default.h"
#include "../templates/sqi_BDBaseAddress_Default.h"
#include "../templates/sqi_BDProcessState_Default.h"
#include "../templates/sqi_DMAProcessInProgress_Default.h"
#include "../templates/sqi_DMAEngineBusy_Default.h"
#include "../templates/sqi_BDControlWord_Default.h"
#include "../templates/sqi_BDPollCount_Default.h"
#include "../templates/sqi_BDTxState_Default.h"
#include "../templates/sqi_BDTxBufCount_Default.h"
#include "../templates/sqi_BDTxLength_Default.h"
#include "../templates/sqi_BDRxState_Default.h"
#include "../templates/sqi_BDRxBufCount_Default.h"
#include "../templates/sqi_BDRxLength_Default.h"
#include "../templates/sqi_ConBufThreshold_Default.h"
#include "../templates/sqi_InterruptSignalControl_Default.h"
#include "../templates/sqi_TapDelay_Default.h"
#include "../templates/sqi_XIPControlWord3_Default.h"
#include "../templates/sqi_XIPControlWord4_Default.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void PLIB_SQI_XIPSDRCommandDDRDataSet(SQI_MODULE_ID index)
{
     SQI_XIPSDRCommandDDRDataSet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_XIPSDRCommandDDRDataGet(SQI_MODULE_ID index)
{
     return SQI_XIPSDRCommandDDRDataGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPSDRCommandDDRData(SQI_MODULE_ID index)
{
     return SQI_ExistsXIPSDRCommandDDRData_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_XIPDDRModeSet(SQI_MODULE_ID index)
{
     SQI_XIPDDRModeSet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPDDRMode(SQI_MODULE_ID index)
{
     return SQI_ExistsXIPDDRMode_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_XIPDummyBytesSet(SQI_MODULE_ID index, SQI_DUMMY_BYTES bytes)
{
     SQI_XIPDummyBytesSet_Default(index, bytes);
}

PLIB_INLINE_API SQI_DUMMY_BYTES PLIB_SQI_XIPDummyBytesGet(SQI_MODULE_ID index)
{
     return SQI_XIPDummyBytesGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPNumberOfDummyBytes(SQI_MODULE_ID index)
{
     return SQI_ExistsXIPNumberOfDummyBytes_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_XIPAddressBytesSet(SQI_MODULE_ID index, SQI_ADDR_BYTES bytes)
{
     SQI_XIPAddressBytesSet_Default(index, bytes);
}

PLIB_INLINE_API SQI_ADDR_BYTES PLIB_SQI_XIPAddressBytesGet(SQI_MODULE_ID index)
{
     return SQI_XIPAddressBytesGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPNumberOfAddressBytes(SQI_MODULE_ID index)
{
     return SQI_ExistsXIPNumberOfAddressBytes_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_XIPReadOpcodeSet(SQI_MODULE_ID index, uint8_t opCode)
{
     SQI_XIPReadOpcodeSet_Default(index, opCode);
}

PLIB_INLINE_API uint8_t PLIB_SQI_XIPReadOpcodeGet(SQI_MODULE_ID index)
{
     return SQI_XIPReadOpcodeGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPReadOpCode(SQI_MODULE_ID index)
{
     return SQI_ExistsXIPReadOpCode_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_XIPLaneModeSet(SQI_MODULE_ID index, SQI_LANE_MODE dataLanes, SQI_LANE_MODE dummyLanes, SQI_LANE_MODE modeLanes, SQI_LANE_MODE addrLanes, SQI_LANE_MODE cmdLanes)
{
     SQI_XIPLaneModeSet_Default(index, dataLanes, dummyLanes, modeLanes, addrLanes, cmdLanes);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPLaneMode(SQI_MODULE_ID index)
{
     return SQI_ExistsXIPLaneMode_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_XIPControlWord1Set(SQI_MODULE_ID index, SQI_DUMMY_BYTES dummyBytes, SQI_ADDR_BYTES addressBytes, uint8_t readOpcode, SQI_LANE_MODE dataLaneMode, SQI_LANE_MODE dummyLaneMode, SQI_LANE_MODE modeCodeLaneMode, SQI_LANE_MODE addressLaneMode, SQI_LANE_MODE cmdLaneMode)
{
     SQI_XIPControlWord1Set_Default(index, dummyBytes, addressBytes, readOpcode, dataLaneMode, dummyLaneMode, modeCodeLaneMode, addressLaneMode, cmdLaneMode);
}

PLIB_INLINE_API uint32_t PLIB_SQI_XIPControlWord1Get(SQI_MODULE_ID index)
{
     return SQI_XIPControlWord1Get_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPControlWord1(SQI_MODULE_ID index)
{
     return SQI_ExistsXIPControlWord1_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_XIPChipSelectSet(SQI_MODULE_ID index, SQI_CS_NUM csNum)
{
     SQI_XIPChipSelectSet_Default(index, csNum);
}

PLIB_INLINE_API SQI_CS_NUM PLIB_SQI_XIPChipSelectGet(SQI_MODULE_ID index)
{
     return SQI_XIPChipSelectGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPChipSelect(SQI_MODULE_ID index)
{
     return SQI_ExistsXIPChipSelect_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_XIPModeBytesSet(SQI_MODULE_ID index, SQI_MODE_BYTES bytes)
{
     SQI_XIPModeBytesSet_Default(index, bytes);
}

PLIB_INLINE_API SQI_MODE_BYTES PLIB_SQI_XIPModeBytesGet(SQI_MODULE_ID index)
{
     return SQI_XIPModeBytesGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPModeBytes(SQI_MODULE_ID index)
{
     return SQI_ExistsXIPModeBytes_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_XIPModeCodeSet(SQI_MODULE_ID index, uint8_t code)
{
     SQI_XIPModeCodeSet_Default(index, code);
}

PLIB_INLINE_API uint8_t PLIB_SQI_XIPModeCodeGet(SQI_MODULE_ID index)
{
     return SQI_XIPModeCodeGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPModeCode(SQI_MODULE_ID index)
{
     return SQI_ExistsXIPModeCode_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_XIPControlWord2Set(SQI_MODULE_ID index, SQI_CS_NUM devSelect, SQI_MODE_BYTES modeBytes, uint8_t modeCode)
{
     SQI_XIPControlWord2Set_Default(index, devSelect, modeBytes, modeCode);
}

PLIB_INLINE_API uint32_t PLIB_SQI_XIPControlWord2Get(SQI_MODULE_ID index)
{
     return SQI_XIPControlWord2Get_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPControlWord2(SQI_MODULE_ID index)
{
     return SQI_ExistsXIPControlWord2_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_Enable(SQI_MODULE_ID index)
{
     SQI_Enable_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_Disable(SQI_MODULE_ID index)
{
     SQI_Disable_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsEnableControl(SQI_MODULE_ID index)
{
     return SQI_ExistsEnableControl_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_CSOutputEnableSelect(SQI_MODULE_ID index, SQI_CS_OEN csPins)
{
     SQI_CSOutputEnableSelect_Default(index, csPins);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsCSOutputEnable(SQI_MODULE_ID index)
{
     return SQI_ExistsCSOutputEnable_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_DataOutputEnableSelect(SQI_MODULE_ID index, SQI_DATA_OEN dataPins)
{
     SQI_DataOutputEnableSelect_Default(index, dataPins);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDataOutputEnable(SQI_MODULE_ID index)
{
     return SQI_ExistsDataOutputEnable_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_ConBufferSoftReset(SQI_MODULE_ID index)
{
     SQI_ConBufferSoftReset_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsConBufferSoftReset(SQI_MODULE_ID index)
{
     return SQI_ExistsConBufferSoftReset_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_RxBufferSoftReset(SQI_MODULE_ID index)
{
     SQI_RxBufferSoftReset_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsRxBufferSoftReset(SQI_MODULE_ID index)
{
     return SQI_ExistsRxBufferSoftReset_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_TxBufferSoftReset(SQI_MODULE_ID index)
{
     SQI_TxBufferSoftReset_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTxBufferSoftReset(SQI_MODULE_ID index)
{
     return SQI_ExistsTxBufferSoftReset_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_SoftReset(SQI_MODULE_ID index)
{
     SQI_SoftReset_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsSoftReset(SQI_MODULE_ID index)
{
     return SQI_ExistsSoftReset_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_BurstEnable(SQI_MODULE_ID index)
{
     SQI_BurstEnable_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBurstControl(SQI_MODULE_ID index)
{
     return SQI_ExistsBurstControl_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_HoldSet(SQI_MODULE_ID index)
{
     SQI_HoldSet_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_HoldClear(SQI_MODULE_ID index)
{
     SQI_HoldClear_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_HoldGet(SQI_MODULE_ID index)
{
     return SQI_HoldGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsHoldPinControl(SQI_MODULE_ID index)
{
     return SQI_ExistsHoldPinControl_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_WriteProtectSet(SQI_MODULE_ID index)
{
     SQI_WriteProtectSet_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_WriteProtectClear(SQI_MODULE_ID index)
{
     SQI_WriteProtectClear_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_WriteProtectGet(SQI_MODULE_ID index)
{
     return SQI_WriteProtectGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsWPPinControl(SQI_MODULE_ID index)
{
     return SQI_ExistsWPPinControl_Default(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_ReceiveLatchEnable(SQI_MODULE_ID index)
{
     SQI_ReceiveLatchEnable_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_ReceiveLatchDisable(SQI_MODULE_ID index)
{
     SQI_ReceiveLatchDisable_Unsupported(index);
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_ReceiveLatchGet(SQI_MODULE_ID index)
{
     return SQI_ReceiveLatchGet_Unsupported(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsReceiveLatch(SQI_MODULE_ID index)
{
     return SQI_ExistsReceiveLatch_Unsupported(index);
}

PLIB_INLINE_API void PLIB_SQI_DataFormatSet(SQI_MODULE_ID index, SQI_DATA_FORMAT dataformat)
{
     SQI_DataFormatSet_Default(index, dataformat);
}

PLIB_INLINE_API SQI_DATA_FORMAT PLIB_SQI_DataFormatGet(SQI_MODULE_ID index)
{
     return SQI_DataFormatGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDataFormat(SQI_MODULE_ID index)
{
     return SQI_ExistsDataFormat_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_DataModeSet(SQI_MODULE_ID index, SQI_DATA_MODE mode)
{
     SQI_DataModeSet_Default(index, mode);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDataModeControl(SQI_MODULE_ID index)
{
     return SQI_ExistsDataModeControl_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_TransferModeSet(SQI_MODULE_ID index, SQI_XFER_MODE mode)
{
     SQI_TransferModeSet_Default(index, mode);
}

PLIB_INLINE_API SQI_XFER_MODE PLIB_SQI_TransferModeGet(SQI_MODULE_ID index)
{
     return SQI_TransferModeGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTransferModeControl(SQI_MODULE_ID index)
{
     return SQI_ExistsTransferModeControl_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_ConfigWordSet(SQI_MODULE_ID index, bool sqiEnable, SQI_CS_OEN csPins, SQI_DATA_OEN dataPins, bool reset, bool burstEn, bool hold, bool writeProtect, bool rxLatch, SQI_DATA_FORMAT lsbf, SQI_DATA_MODE dataMode, SQI_XFER_MODE xferMode)
{
     SQI_ConfigWordSet_Default(index, sqiEnable, csPins, dataPins, reset, burstEn, hold, writeProtect, rxLatch, lsbf, dataMode, xferMode);
}

PLIB_INLINE_API uint32_t PLIB_SQI_ConfigWordGet(SQI_MODULE_ID index)
{
     return SQI_ConfigWordGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsConfigWord(SQI_MODULE_ID index)
{
     return SQI_ExistsConfigWord_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_StatusCheckSet(SQI_MODULE_ID index, uint16_t statCheckCmd, uint8_t numStatBytes, SQI_LANE_MODE statCmdType, bool statBitPos)
{
     SQI_StatusCheckSet_Default(index, statCheckCmd, numStatBytes, statCmdType, statBitPos);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsStatusCheck(SQI_MODULE_ID index)
{
     return SQI_ExistsStatusCheck_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_DDRModeSet(SQI_MODULE_ID index)
{
     SQI_DDRModeSet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_DDRModeGet(SQI_MODULE_ID index)
{
     return SQI_DDRModeGet_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_DDRModeClear(SQI_MODULE_ID index)
{
     SQI_DDRModeClear_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDDRMode(SQI_MODULE_ID index)
{
     return SQI_ExistsDDRMode_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_ChipSelectDeassertEnable(SQI_MODULE_ID index)
{
     SQI_ChipSelectDeassertEnable_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_ChipSelectDeassertDisable(SQI_MODULE_ID index)
{
     SQI_ChipSelectDeassertDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsCSDeassert(SQI_MODULE_ID index)
{
     return SQI_ExistsCSDeassert_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_ChipSelectSet(SQI_MODULE_ID index, SQI_CS_NUM csNum)
{
     SQI_ChipSelectSet_Default(index, csNum);
}

PLIB_INLINE_API SQI_CS_NUM PLIB_SQI_ChipSelectGet(SQI_MODULE_ID index)
{
     return SQI_ChipSelectGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsChipSelect(SQI_MODULE_ID index)
{
     return SQI_ExistsChipSelect_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_LaneModeSet(SQI_MODULE_ID index, SQI_LANE_MODE mode)
{
     SQI_LaneModeSet_Default(index, mode);
}

PLIB_INLINE_API SQI_LANE_MODE PLIB_SQI_LaneModeGet(SQI_MODULE_ID index)
{
     return SQI_LaneModeGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsLaneMode(SQI_MODULE_ID index)
{
     return SQI_ExistsLaneMode_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_TransferDirectionSet(SQI_MODULE_ID index, SQI_XFER_CMD command)
{
     SQI_TransferDirectionSet_Default(index, command);
}

PLIB_INLINE_API SQI_XFER_CMD PLIB_SQI_TransferDirectionGet(SQI_MODULE_ID index)
{
     return SQI_TransferDirectionGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTransferCommand(SQI_MODULE_ID index)
{
     return SQI_ExistsTransferCommand_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_ByteCountSet(SQI_MODULE_ID index, uint16_t xferCount)
{
     SQI_ByteCountSet_Default(index, xferCount);
}

PLIB_INLINE_API uint16_t PLIB_SQI_ByteCountGet(SQI_MODULE_ID index)
{
     return SQI_ByteCountGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTransferCount(SQI_MODULE_ID index)
{
     return SQI_ExistsTransferCount_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_ControlWordSet(SQI_MODULE_ID index, bool csDeassert, SQI_CS_NUM csNum, SQI_LANE_MODE laneMode, SQI_XFER_CMD command, uint16_t xferCount)
{
     SQI_ControlWordSet_Default(index, csDeassert, csNum, laneMode, command, xferCount);
}

PLIB_INLINE_API uint32_t PLIB_SQI_ControlWordGet(SQI_MODULE_ID index)
{
     return SQI_ControlWordGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsControlWord(SQI_MODULE_ID index)
{
     return SQI_ExistsControlWord_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_ClockDividerSet(SQI_MODULE_ID index, SQI_CLK_DIV clkDivider)
{
     SQI_ClockDividerSet_Default(index, clkDivider);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsClockDivider(SQI_MODULE_ID index)
{
     return SQI_ExistsClockDivider_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ClockIsStable(SQI_MODULE_ID index)
{
     return SQI_ClockIsStable_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsClockReady(SQI_MODULE_ID index)
{
     return SQI_ExistsClockReady_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_ClockEnable(SQI_MODULE_ID index)
{
     SQI_ClockEnable_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_ClockDisable(SQI_MODULE_ID index)
{
     SQI_ClockDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsClockControl(SQI_MODULE_ID index)
{
     return SQI_ExistsClockControl_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_RxBufferThresholdSet(SQI_MODULE_ID index, uint8_t threshold)
{
     SQI_RxBufferThresholdSet_Default(index, threshold);
}

PLIB_INLINE_API uint8_t PLIB_SQI_RxBufferThresholdGet(SQI_MODULE_ID index)
{
     return SQI_RxBufferThresholdGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsRxBufThreshold(SQI_MODULE_ID index)
{
     return SQI_ExistsRxBufThreshold_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_TxBufferThresholdSet(SQI_MODULE_ID index, uint8_t threshold)
{
     SQI_TxBufferThresholdSet_Default(index, threshold);
}

PLIB_INLINE_API uint8_t PLIB_SQI_TxBufferThresholdGet(SQI_MODULE_ID index)
{
     return SQI_TxBufferThresholdGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTxBufThreshold(SQI_MODULE_ID index)
{
     return SQI_ExistsTxBufThreshold_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_RxBufferThresholdIntSet(SQI_MODULE_ID index, uint8_t threshold)
{
     SQI_RxBufferThresholdIntSet_Default(index, threshold);
}

PLIB_INLINE_API uint8_t PLIB_SQI_RxBufferThresholdIntGet(SQI_MODULE_ID index)
{
     return SQI_RxBufferThresholdIntGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsRxBufIntThreshold(SQI_MODULE_ID index)
{
     return SQI_ExistsRxBufIntThreshold_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_TxBufferThresholdIntSet(SQI_MODULE_ID index, uint8_t threshold)
{
     SQI_TxBufferThresholdIntSet_Default(index, threshold);
}

PLIB_INLINE_API uint8_t PLIB_SQI_TxBufferThresholdIntGet(SQI_MODULE_ID index)
{
     return SQI_TxBufferThresholdIntGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTxBufIntThreshold(SQI_MODULE_ID index)
{
     return SQI_ExistsTxBufIntThreshold_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_InterruptEnable(SQI_MODULE_ID index, SQI_INTERRUPTS interruptFlag)
{
     SQI_InterruptEnable_Default(index, interruptFlag);
}

PLIB_INLINE_API void PLIB_SQI_InterruptDisable(SQI_MODULE_ID index, SQI_INTERRUPTS interruptFlag)
{
     SQI_InterruptDisable_Default(index, interruptFlag);
}

PLIB_INLINE_API void PLIB_SQI_InterruptDisableAll(SQI_MODULE_ID index)
{
     SQI_InterruptDisableAll_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_InterruptIsEnabled(SQI_MODULE_ID index, SQI_INTERRUPTS interruptFlag)
{
     return SQI_InterruptIsEnabled_Default(index, interruptFlag);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsInterruptControl(SQI_MODULE_ID index)
{
     return SQI_ExistsInterruptControl_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_InterruptFlagGet(SQI_MODULE_ID index, SQI_INTERRUPTS interruptFlag)
{
     return SQI_InterruptFlagGet_Default(index, interruptFlag);
}

PLIB_INLINE_API uint32_t PLIB_SQI_InterruptWordGet(SQI_MODULE_ID index)
{
     return SQI_InterruptWordGet_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_InterruptWordClear(SQI_MODULE_ID index, uint32_t flags)
{
     SQI_InterruptWordClear_Default(index, flags);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsInterruptStatus(SQI_MODULE_ID index)
{
     return SQI_ExistsInterruptStatus_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_TransmitData(SQI_MODULE_ID index, uint32_t data)
{
     SQI_TransmitData_Default(index, data);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTxData(SQI_MODULE_ID index)
{
     return SQI_ExistsTxData_Default(index);
}

PLIB_INLINE_API uint32_t PLIB_SQI_ReceiveData(SQI_MODULE_ID index)
{
     return SQI_ReceiveData_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsRxData(SQI_MODULE_ID index)
{
     return SQI_ExistsRxData_Default(index);
}

PLIB_INLINE_API uint8_t PLIB_SQI_TransmitBufferFreeSpaceGet(SQI_MODULE_ID index)
{
     return SQI_TransmitBufferFreeSpaceGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTxBufferFree(SQI_MODULE_ID index)
{
     return SQI_ExistsTxBufferFree_Default(index);
}

PLIB_INLINE_API uint8_t PLIB_SQI_NumberOfReceiveBufferReads(SQI_MODULE_ID index)
{
     return SQI_NumberOfReceiveBufferReads_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsRxBufferCount(SQI_MODULE_ID index)
{
     return SQI_ExistsRxBufferCount_Default(index);
}

PLIB_INLINE_API uint8_t PLIB_SQI_ConBufWordsAvailable(SQI_MODULE_ID index)
{
     return SQI_ConBufWordsAvailable_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsConBufAvailable(SQI_MODULE_ID index)
{
     return SQI_ExistsConBufAvailable_Default(index);
}

PLIB_INLINE_API uint8_t PLIB_SQI_CommandStatusGet(SQI_MODULE_ID index)
{
     return SQI_CommandStatusGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsCommandStatus(SQI_MODULE_ID index)
{
     return SQI_ExistsCommandStatus_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_DataLineStatus(SQI_MODULE_ID index, uint8_t dataPin)
{
     return SQI_DataLineStatus_Default(index, dataPin);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDataPinStatus(SQI_MODULE_ID index)
{
     return SQI_ExistsDataPinStatus_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ReceiveBufferIsUnderrun(SQI_MODULE_ID index)
{
     return SQI_ReceiveBufferIsUnderrun_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsRxUnderRun(SQI_MODULE_ID index)
{
     return SQI_ExistsRxUnderRun_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_TransmitBufferHasOverflowed(SQI_MODULE_ID index)
{
     return SQI_TransmitBufferHasOverflowed_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTxOverFlow(SQI_MODULE_ID index)
{
     return SQI_ExistsTxOverFlow_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_DMAEnable(SQI_MODULE_ID index)
{
     SQI_DMAEnable_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_DMADisable(SQI_MODULE_ID index)
{
     SQI_DMADisable_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_DMAIsEnabled(SQI_MODULE_ID index)
{
     return SQI_DMAIsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDmaEnable(SQI_MODULE_ID index)
{
     return SQI_ExistsDmaEnable_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_DMABDPollEnable(SQI_MODULE_ID index)
{
     SQI_DMABDPollEnable_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_DMABDPollDisable(SQI_MODULE_ID index)
{
     SQI_DMABDPollDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_DMABDPollIsEnabled(SQI_MODULE_ID index)
{
     return SQI_DMABDPollIsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDPollingEnable(SQI_MODULE_ID index)
{
     return SQI_ExistsBDPollingEnable_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_DMABDFetchStart(SQI_MODULE_ID index)
{
     SQI_DMABDFetchStart_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_DMABDFetchStop(SQI_MODULE_ID index)
{
     SQI_DMABDFetchStop_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDMABDFetch(SQI_MODULE_ID index)
{
     return SQI_ExistsDMABDFetch_Default(index);
}

PLIB_INLINE_API void* PLIB_SQI_DMABDCurrentAddressGet(SQI_MODULE_ID index)
{
     return SQI_DMABDCurrentAddressGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDCurrentAddress(SQI_MODULE_ID index)
{
     return SQI_ExistsBDCurrentAddress_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_DMABDBaseAddressSet(SQI_MODULE_ID index, void* baseBDAddress)
{
     SQI_DMABDBaseAddressSet_Default(index, baseBDAddress);
}

PLIB_INLINE_API void* PLIB_SQI_DMABDBaseAddressGet(SQI_MODULE_ID index)
{
     return SQI_DMABDBaseAddressGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDBaseAddress(SQI_MODULE_ID index)
{
     return SQI_ExistsBDBaseAddress_Default(index);
}

PLIB_INLINE_API SQI_BD_STATE PLIB_SQI_DMABDStateGet(SQI_MODULE_ID index)
{
     return SQI_DMABDStateGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDProcessState(SQI_MODULE_ID index)
{
     return SQI_ExistsBDProcessState_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_DMAHasStarted(SQI_MODULE_ID index)
{
     return SQI_DMAHasStarted_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDMAProcessInProgress(SQI_MODULE_ID index)
{
     return SQI_ExistsDMAProcessInProgress_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_DMABDIsBusy(SQI_MODULE_ID index)
{
     return SQI_DMABDIsBusy_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDMAEngineBusy(SQI_MODULE_ID index)
{
     return SQI_ExistsDMAEngineBusy_Default(index);
}

PLIB_INLINE_API uint16_t PLIB_SQI_DMABDControlWordGet(SQI_MODULE_ID index)
{
     return SQI_DMABDControlWordGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDControlWord(SQI_MODULE_ID index)
{
     return SQI_ExistsBDControlWord_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_DMABDPollCounterSet(SQI_MODULE_ID index, uint16_t pollCount)
{
     SQI_DMABDPollCounterSet_Default(index, pollCount);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDPollCount(SQI_MODULE_ID index)
{
     return SQI_ExistsBDPollCount_Default(index);
}

PLIB_INLINE_API SQI_BD_STATE PLIB_SQI_DMABDTransmitStateGet(SQI_MODULE_ID index)
{
     return SQI_DMABDTransmitStateGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDTxState(SQI_MODULE_ID index)
{
     return SQI_ExistsBDTxState_Default(index);
}

PLIB_INLINE_API uint8_t PLIB_SQI_DMABDTransmitBufferCountGet(SQI_MODULE_ID index)
{
     return SQI_DMABDTransmitBufferCountGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDTxBufCount(SQI_MODULE_ID index)
{
     return SQI_ExistsBDTxBufCount_Default(index);
}

PLIB_INLINE_API uint8_t PLIB_SQI_DMABDTransmitBufferLengthGet(SQI_MODULE_ID index)
{
     return SQI_DMABDTransmitBufferLengthGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDTxLength(SQI_MODULE_ID index)
{
     return SQI_ExistsBDTxLength_Default(index);
}

PLIB_INLINE_API SQI_BD_STATE PLIB_SQI_DMABDReceiveStateGet(SQI_MODULE_ID index)
{
     return SQI_DMABDReceiveStateGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDRxState(SQI_MODULE_ID index)
{
     return SQI_ExistsBDRxState_Default(index);
}

PLIB_INLINE_API uint8_t PLIB_SQI_DMABDReceiveBufferCountGet(SQI_MODULE_ID index)
{
     return SQI_DMABDReceiveBufferCountGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDRxBufCount(SQI_MODULE_ID index)
{
     return SQI_ExistsBDRxBufCount_Default(index);
}

PLIB_INLINE_API uint8_t PLIB_SQI_DMABDReceiveBufferLengthGet(SQI_MODULE_ID index)
{
     return SQI_DMABDReceiveBufferLengthGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDRxLength(SQI_MODULE_ID index)
{
     return SQI_ExistsBDRxLength_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_ControlBufferThresholdSet(SQI_MODULE_ID index, uint8_t threshold)
{
     SQI_ControlBufferThresholdSet_Default(index, threshold);
}

PLIB_INLINE_API uint8_t PLIB_SQI_ControlBufferThresholdGet(SQI_MODULE_ID index)
{
     return SQI_ControlBufferThresholdGet_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsConBufThreshold(SQI_MODULE_ID index)
{
     return SQI_ExistsConBufThreshold_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_InterruptSignalEnable(SQI_MODULE_ID index, SQI_INTERRUPTS interruptFlag)
{
     SQI_InterruptSignalEnable_Default(index, interruptFlag);
}

PLIB_INLINE_API void PLIB_SQI_InterruptSignalDisable(SQI_MODULE_ID index, SQI_INTERRUPTS interruptFlag)
{
     SQI_InterruptSignalDisable_Default(index, interruptFlag);
}

PLIB_INLINE_API void PLIB_SQI_InterruptSignalDisableAll(SQI_MODULE_ID index)
{
     SQI_InterruptSignalDisableAll_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_InterruptSignalIsEnabled(SQI_MODULE_ID index, SQI_INTERRUPTS interruptFlag)
{
     return SQI_InterruptSignalIsEnabled_Default(index, interruptFlag);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsInterruptSignalControl(SQI_MODULE_ID index)
{
     return SQI_ExistsInterruptSignalControl_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_TapDelaySet(SQI_MODULE_ID index, uint8_t sdrClkInDly, uint8_t dataOutDly, uint8_t clkOutDly)
{
     SQI_TapDelaySet_Default(index, sdrClkInDly, dataOutDly, clkOutDly);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTapDelay(SQI_MODULE_ID index)
{
     return SQI_ExistsTapDelay_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_XIPControlWord3Set(SQI_MODULE_ID index, bool initStatCheck, uint8_t initCmdCount, SQI_LANE_MODE initCmdType, uint8_t initCmd3, uint8_t initCmd2, uint8_t initCmd1)
{
     SQI_XIPControlWord3Set_Default(index, initStatCheck, initCmdCount, initCmdType, initCmd3, initCmd2, initCmd1);
}

PLIB_INLINE_API uint32_t PLIB_SQI_XIPControlWord3Get(SQI_MODULE_ID index)
{
     return SQI_XIPControlWord3Get_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPControlWord3(SQI_MODULE_ID index)
{
     return SQI_ExistsXIPControlWord3_Default(index);
}

PLIB_INLINE_API void PLIB_SQI_XIPControlWord4Set(SQI_MODULE_ID index, bool initStatCheck, uint8_t initCmdCount, SQI_LANE_MODE initCmdType, uint8_t initCmd3, uint8_t initCmd2, uint8_t initCmd1)
{
     SQI_XIPControlWord4Set_Default(index, initStatCheck, initCmdCount, initCmdType, initCmd3, initCmd2, initCmd1);
}

PLIB_INLINE_API uint32_t PLIB_SQI_XIPControlWord4Get(SQI_MODULE_ID index)
{
     return SQI_XIPControlWord4Get_Default(index);
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPControlWord4(SQI_MODULE_ID index)
{
     return SQI_ExistsXIPControlWord4_Default(index);
}

#endif
