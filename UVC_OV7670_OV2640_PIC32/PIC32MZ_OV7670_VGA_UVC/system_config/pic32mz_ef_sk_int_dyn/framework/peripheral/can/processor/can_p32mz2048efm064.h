/* Created by plibgen $Revision: 1.31 $ */

#ifndef _CAN_P32MZ2048EFM064_H
#define _CAN_P32MZ2048EFM064_H

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

    CAN_ID_1 = _CAN1_BASE_ADDRESS,
    CAN_ID_2 = _CAN2_BASE_ADDRESS,
    CAN_NUMBER_OF_MODULES = 2

} CAN_MODULE_ID;

typedef enum {

    CAN_CHANNEL0 = 0x00,
    CAN_CHANNEL1 = 0x01,
    CAN_CHANNEL2 = 0x02,
    CAN_CHANNEL3 = 0x03,
    CAN_CHANNEL4 = 0x04,
    CAN_CHANNEL5 = 0x05,
    CAN_CHANNEL6 = 0x06,
    CAN_CHANNEL7 = 0x07,
    CAN_CHANNEL8 = 0x08,
    CAN_CHANNEL9 = 0x09,
    CAN_CHANNEL10 = 0x0A,
    CAN_CHANNEL11 = 0x0B,
    CAN_CHANNEL12 = 0x0C,
    CAN_CHANNEL13 = 0x0D,
    CAN_CHANNEL14 = 0x0E,
    CAN_CHANNEL15 = 0x0F,
    CAN_CHANNEL16 = 0x10,
    CAN_CHANNEL17 = 0x11,
    CAN_CHANNEL18 = 0x12,
    CAN_CHANNEL19 = 0x13,
    CAN_CHANNEL20 = 0x14,
    CAN_CHANNEL21 = 0x15,
    CAN_CHANNEL22 = 0x16,
    CAN_CHANNEL23 = 0x17,
    CAN_CHANNEL24 = 0x18,
    CAN_CHANNEL25 = 0x19,
    CAN_CHANNEL26 = 0x1A,
    CAN_CHANNEL27 = 0x1B,
    CAN_CHANNEL28 = 0x1C,
    CAN_CHANNEL29 = 0x1D,
    CAN_CHANNEL30 = 0x1E,
    CAN_CHANNEL31 = 0x1F,
    CAN_TOTAL_CHANNELS = 0x20

} CAN_CHANNEL;

typedef enum {

    CAN_NORMAL_MODE = 0x00,
    CAN_DISABLE_MODE = 0x01,
    CAN_LOOPBACK_MODE = 0x02,
    CAN_LISTEN_ONLY_MODE = 0x03,
    CAN_CONFIGURATION_MODE = 0x04,
    CAN_LISTEN_ALL_MESSAGES_MODE = 0x07

} CAN_OPERATION_MODES;

typedef enum {

    CAN_RX_CHANNEL_NOT_EMPTY = 0x01,
    CAN_RX_CHANNEL_HALF_FULL = 0x02,
    CAN_RX_CHANNEL_FULL = 0x04,
    CAN_RX_CHANNEL_OVERFLOW = 0x08,
    CAN_RX_CHANNEL_ANY_EVENT = 0x0F,
    CAN_TX_CHANNEL_EMPTY = 0x100,
    CAN_TX_CHANNEL_HALF_EMPTY = 0x200,
    CAN_TX_CHANNEL_NOT_FULL = 0x400,
    CAN_TX_CHANNEL_ANY_EVENT = 0x700

} CAN_CHANNEL_EVENT;

typedef enum {

    CAN_BAUD_RATE_PRESCALE_1 = 0,
    CAN_BAUD_RATE_PRESCALE_2 = 1,
    CAN_BAUD_RATE_PRESCALE_3 = 2,
    CAN_BAUD_RATE_PRESCALE_4 = 3,
    CAN_BAUD_RATE_PRESCALE_5 = 4,
    CAN_BAUD_RATE_PRESCALE_6 = 5,
    CAN_BAUD_RATE_PRESCALE_7 = 6,
    CAN_BAUD_RATE_PRESCALE_8 = 7,
    CAN_BAUD_RATE_PRESCALE_9 = 8,
    CAN_BAUD_RATE_PRESCALE_10 = 9,
    CAN_BAUD_RATE_PRESCALE_11 = 10,
    CAN_BAUD_RATE_PRESCALE_12 = 11,
    CAN_BAUD_RATE_PRESCALE_13 = 12,
    CAN_BAUD_RATE_PRESCALE_14 = 13,
    CAN_BAUD_RATE_PRESCALE_15 = 14,
    CAN_BAUD_RATE_PRESCALE_16 = 15,
    CAN_BAUD_RATE_PRESCALE_17 = 16,
    CAN_BAUD_RATE_PRESCALE_18 = 17,
    CAN_BAUD_RATE_PRESCALE_19 = 18,
    CAN_BAUD_RATE_PRESCALE_20 = 19,
    CAN_BAUD_RATE_PRESCALE_21 = 20,
    CAN_BAUD_RATE_PRESCALE_22 = 21,
    CAN_BAUD_RATE_PRESCALE_23 = 22,
    CAN_BAUD_RATE_PRESCALE_24 = 23,
    CAN_BAUD_RATE_PRESCALE_25 = 24,
    CAN_BAUD_RATE_PRESCALE_26 = 25,
    CAN_BAUD_RATE_PRESCALE_27 = 26,
    CAN_BAUD_RATE_PRESCALE_28 = 27,
    CAN_BAUD_RATE_PRESCALE_29 = 28,
    CAN_BAUD_RATE_PRESCALE_30 = 29,
    CAN_BAUD_RATE_PRESCALE_31 = 30,
    CAN_BAUD_RATE_PRESCALE_32 = 31,
    CAN_BAUD_RATE_PRESCALE_33 = 32,
    CAN_BAUD_RATE_PRESCALE_34 = 33,
    CAN_BAUD_RATE_PRESCALE_35 = 34,
    CAN_BAUD_RATE_PRESCALE_36 = 35,
    CAN_BAUD_RATE_PRESCALE_37 = 36,
    CAN_BAUD_RATE_PRESCALE_38 = 37,
    CAN_BAUD_RATE_PRESCALE_39 = 38,
    CAN_BAUD_RATE_PRESCALE_40 = 39,
    CAN_BAUD_RATE_PRESCALE_41 = 40,
    CAN_BAUD_RATE_PRESCALE_42 = 41,
    CAN_BAUD_RATE_PRESCALE_43 = 42,
    CAN_BAUD_RATE_PRESCALE_44 = 43,
    CAN_BAUD_RATE_PRESCALE_45 = 44,
    CAN_BAUD_RATE_PRESCALE_46 = 45,
    CAN_BAUD_RATE_PRESCALE_47 = 46,
    CAN_BAUD_RATE_PRESCALE_48 = 47,
    CAN_BAUD_RATE_PRESCALE_49 = 48,
    CAN_BAUD_RATE_PRESCALE_50 = 49,
    CAN_BAUD_RATE_PRESCALE_51 = 50,
    CAN_BAUD_RATE_PRESCALE_52 = 51,
    CAN_BAUD_RATE_PRESCALE_53 = 52,
    CAN_BAUD_RATE_PRESCALE_54 = 53,
    CAN_BAUD_RATE_PRESCALE_55 = 54,
    CAN_BAUD_RATE_PRESCALE_56 = 55,
    CAN_BAUD_RATE_PRESCALE_57 = 56,
    CAN_BAUD_RATE_PRESCALE_58 = 57,
    CAN_BAUD_RATE_PRESCALE_59 = 58,
    CAN_BAUD_RATE_PRESCALE_60 = 59,
    CAN_BAUD_RATE_PRESCALE_61 = 60,
    CAN_BAUD_RATE_PRESCALE_62 = 61,
    CAN_BAUD_RATE_PRESCALE_63 = 62,
    CAN_BAUD_RATE_PRESCALE_64 = 63

} CAN_BAUD_RATE_PRESCALE;

typedef enum {

    CAN_TIME_SEGMENT_LEN_1TQ = 0x00,
    CAN_TIME_SEGMENT_LEN_2TQ = 0x01,
    CAN_TIME_SEGMENT_LEN_3TQ = 0x02,
    CAN_TIME_SEGMENT_LEN_4TQ = 0x03,
    CAN_TIME_SEGMENT_LEN_5TQ = 0x04,
    CAN_TIME_SEGMENT_LEN_6TQ = 0x05,
    CAN_TIME_SEGMENT_LEN_7TQ = 0x06,
    CAN_TIME_SEGMENT_LEN_8TQ = 0x07

} CAN_TIME_SEGMENT_LENGTH;

typedef enum {

    CAN_CHANNEL0_EVENT = 0x00,
    CAN_CHANNEL1_EVENT = 0x01,
    CAN_CHANNEL2_EVENT = 0x02,
    CAN_CHANNEL3_EVENT = 0x03,
    CAN_CHANNEL4_EVENT = 0x04,
    CAN_CHANNEL5_EVENT = 0x05,
    CAN_CHANNEL6_EVENT = 0x06,
    CAN_CHANNEL7_EVENT = 0x07,
    CAN_CHANNEL8_EVENT = 0x08,
    CAN_CHANNEL9_EVENT = 0x09,
    CAN_CHANNEL10_EVENT = 0x0A,
    CAN_CHANNEL11_EVENT = 0x0B,
    CAN_CHANNEL12_EVENT = 0x0C,
    CAN_CHANNEL13_EVENT = 0x0D,
    CAN_CHANNEL14_EVENT = 0x0E,
    CAN_CHANNEL15_EVENT = 0x0F,
    CAN_CHANNEL16_EVENT = 0x10,
    CAN_CHANNEL17_EVENT = 0x11,
    CAN_CHANNEL18_EVENT = 0x12,
    CAN_CHANNEL19_EVENT = 0x13,
    CAN_CHANNEL20_EVENT = 0x14,
    CAN_CHANNEL21_EVENT = 0x15,
    CAN_CHANNEL22_EVENT = 0x16,
    CAN_CHANNEL23_EVENT = 0x17,
    CAN_CHANNEL24_EVENT = 0x18,
    CAN_CHANNEL25_EVENT = 0x19,
    CAN_CHANNEL26_EVENT = 0x1A,
    CAN_CHANNEL27_EVENT = 0x1B,
    CAN_CHANNEL28_EVENT = 0x1C,
    CAN_CHANNEL29_EVENT = 0x1D,
    CAN_CHANNEL30_EVENT = 0x1E,
    CAN_CHANNEL31_EVENT = 0x1F,
    CAN_NO_EVENT = 0x40,
    CAN_ERROR_EVENT = 0x41,
    CAN_WAKEUP_EVENT = 0x42,
    CAN_RX_CHANNEL_OVERFLOW_EVENT = 0x43,
    CAN_ADDRESS_ERROR_EVENT = 0x44,
    CAN_BUS_BANDWIDTH_ERROR = 0x45,
    CAN_TIMESTAMP_TIMER_EVENT = 0x46,
    CAN_MODE_CHANGE_EVENT = 0x47,
    CAN_INVALID_MESSAGE_RECEIVED_EVENT = 0x48

} CAN_EVENT_CODE;

typedef enum {

    CAN_FILTER0 = 0x00,
    CAN_FILTER1 = 0x01,
    CAN_FILTER2 = 0x02,
    CAN_FILTER3 = 0x03,
    CAN_FILTER4 = 0x04,
    CAN_FILTER5 = 0x05,
    CAN_FILTER6 = 0x06,
    CAN_FILTER7 = 0x07,
    CAN_FILTER8 = 0x08,
    CAN_FILTER9 = 0x09,
    CAN_FILTER10 = 0x0A,
    CAN_FILTER11 = 0x0B,
    CAN_FILTER12 = 0x0C,
    CAN_FILTER13 = 0x0D,
    CAN_FILTER14 = 0x0E,
    CAN_FILTER15 = 0x0F,
    CAN_FILTER16 = 0x10,
    CAN_FILTER17 = 0x11,
    CAN_FILTER18 = 0x12,
    CAN_FILTER19 = 0x13,
    CAN_FILTER20 = 0x14,
    CAN_FILTER21 = 0x15,
    CAN_FILTER22 = 0x16,
    CAN_FILTER23 = 0x17,
    CAN_FILTER24 = 0x18,
    CAN_FILTER25 = 0x19,
    CAN_FILTER26 = 0x1A,
    CAN_FILTER27 = 0x1B,
    CAN_FILTER28 = 0x1C,
    CAN_FILTER29 = 0x1D,
    CAN_FILTER30 = 0x1E,
    CAN_FILTER31 = 0x1F,
    CAN_TOTAL_FILTERS = 0x20

} CAN_FILTER;

typedef enum {

    CAN_FILTER_MASK0 = 0x00,
    CAN_FILTER_MASK1 = 0x01,
    CAN_FILTER_MASK2 = 0x02,
    CAN_FILTER_MASK3 = 0x03,
    CAN_NUMBER_OF_FILTER_MASKS = 0x04

} CAN_FILTER_MASK;

typedef enum {

    CAN_TX_RTR_ENABLED = 0x01,
    CAN_TX_RTR_DISABLED = 0x00

} CAN_TX_RTR;

typedef enum {

    CAN_RX_DATA_ONLY = 0x00,
    CAN_RX_FULL_RECEIVE = 0x01

} CAN_RX_DATA_MODE;

typedef enum {

    CAN_FILTER_MASK_IDE_TYPE = 0x00,
    CAN_FILTER_MASK_ANY_TYPE = 0x01

} CAN_FILTER_MASK_TYPE;

typedef enum {

    CAN_LOWEST_PRIORITY = 0x00,
    CAN_LOW_MEDIUM_PRIORITY = 0x01,
    CAN_HIGH_MEDIUM_PRIORITY = 0x02,
    CAN_HIGHEST_PRIORITY = 0x03

} CAN_TXCHANNEL_PRIORITY;

typedef enum {

    CAN_DNET_FILTER_SIZE_18_BIT = 0x12,
    CAN_DNET_FILTER_SIZE_17_BIT = 0x11,
    CAN_DNET_FILTER_SIZE_16_BIT = 0x10,
    CAN_DNET_FILTER_SIZE_15_BIT = 0x0F,
    CAN_DNET_FILTER_SIZE_14_BIT = 0x0E,
    CAN_DNET_FILTER_SIZE_13_BIT = 0x0D,
    CAN_DNET_FILTER_SIZE_12_BIT = 0x0C,
    CAN_DNET_FILTER_SIZE_11_BIT = 0x0B,
    CAN_DNET_FILTER_SIZE_10_BIT = 0x0A,
    CAN_DNET_FILTER_SIZE_9_BIT = 0x09,
    CAN_DNET_FILTER_SIZE_8_BIT = 0x08,
    CAN_DNET_FILTER_SIZE_7_BIT = 0x07,
    CAN_DNET_FILTER_SIZE_6_BIT = 0x06,
    CAN_DNET_FILTER_SIZE_5_BIT = 0x05,
    CAN_DNET_FILTER_SIZE_4_BIT = 0x04,
    CAN_DNET_FILTER_SIZE_3_BIT = 0x03,
    CAN_DNET_FILTER_SIZE_2_BIT = 0x02,
    CAN_DNET_FILTER_SIZE_1_BIT = 0x01,
    CAN_DNET_FILTER_DISABLE = 0x00

} CAN_DNET_FILTER_SIZE;

typedef enum {

    CAN_TX_EVENT = 0x01,
    CAN_RX_EVENT = 0x02,
    CAN_TIMESTAMP_TIMER_OVERFLOW_EVENT = 0x04,
    CAN_OPERATION_MODE_CHANGE_EVENT = 0x08,
    CAN_RX_OVERFLOW_EVENT = 0x800,
    CAN_SYSTEM_ERROR_EVENT = 0x1000,
    CAN_BUS_ERROR_EVENT = 0x2000,
    CAN_BUS_ACTIVITY_WAKEUP_EVENT = 0x4000,
    CAN_INVALID_RX_MESSAGE_EVENT = 0x8000,
    CAN_All_EVENTS = 0xF80F

} CAN_MODULE_EVENT;

typedef enum {

    CAN_TX_RX_WARNING_STATE = 0x10000,
    CAN_RX_WARNING_STATE = 0x20000,
    CAN_TX_WARNING_STATE = 0x40000,
    CAN_RX_BUS_PASSIVE_STATE = 0x80000,
    CAN_TX_BUS_PASSIVE_STATE = 0x100000,
    CAN_TX_BUS_OFF_STATE = 0x200000

} CAN_ERROR_STATE;

typedef enum {

    CAN_EID = 0x00,
    CAN_SID = 0x01

} CAN_ID_TYPE;

typedef enum {

    CAN_CHANNEL0_MASK = 0x00000001,
    CAN_CHANNEL1_MASK = 0x00000002,
    CAN_CHANNEL2_MASK = 0x00000004,
    CAN_CHANNEL3_MASK = 0x00000008,
    CAN_CHANNEL4_MASK = 0x00000010,
    CAN_CHANNEL5_MASK = 0x00000020,
    CAN_CHANNEL6_MASK = 0x00000040,
    CAN_CHANNEL7_MASK = 0x00000080,
    CAN_CHANNEL8_MASK = 0x00000100,
    CAN_CHANNEL9_MASK = 0x00000200,
    CAN_CHANNEL10_MASK = 0x00000400,
    CAN_CHANNEL11_MASK = 0x00000800,
    CAN_CHANNEL12_MASK = 0x00001000,
    CAN_CHANNEL13_MASK = 0x00002000,
    CAN_CHANNEL14_MASK = 0x00004000,
    CAN_CHANNEL15_MASK = 0x00008000,
    CAN_CHANNEL16_MASK = 0x00010000,
    CAN_CHANNEL17_MASK = 0x00020000,
    CAN_CHANNEL18_MASK = 0x00040000,
    CAN_CHANNEL19_MASK = 0x00080000,
    CAN_CHANNEL20_MASK = 0x00100000,
    CAN_CHANNEL21_MASK = 0x00200000,
    CAN_CHANNEL22_MASK = 0x00400000,
    CAN_CHANNEL23_MASK = 0x00800000,
    CAN_CHANNEL24_MASK = 0x01000000,
    CAN_CHANNEL25_MASK = 0x02000000,
    CAN_CHANNEL26_MASK = 0x04000000,
    CAN_CHANNEL27_MASK = 0x08000000,
    CAN_CHANNEL28_MASK = 0x10000000,
    CAN_CHANNEL29_MASK = 0x20000000,
    CAN_CHANNEL30_MASK = 0x40000000,
    CAN_CHANNEL31_MASK = 0x80000000,
    CAN_ANYCHANNEL_MASK = 0xFFFFFFFF

} CAN_CHANNEL_MASK;

typedef enum {

    CAN_TX_CHANNEL_TRANSMITTING = 0x01,
    CAN_TX_CHANNEL_ERROR = 0x02,
    CAN_TX_CHANNEL_ARBITRATION_LOST = 0x04

} CAN_TX_CHANNEL_STATUS;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/can_DeviceNet_Default.h"
#include "../templates/can_ActiveStatus_Default.h"
#include "../templates/can_StopInIdle_Default.h"
#include "../templates/can_EnableControl_Default.h"
#include "../templates/can_TimeStampEnable_Default.h"
#include "../templates/can_TimeStampValue_Default.h"
#include "../templates/can_BusActivityWakeup_Default.h"
#include "../templates/can_MemoryBufferAssign_Default.h"
#include "../templates/can_OperationModeRead_Default.h"
#include "../templates/can_OperationModeSet_Default.h"
#include "../templates/can_TimeStampPrescaler_Default.h"
#include "../templates/can_PhaseSegment2Length_Default.h"
#include "../templates/can_PhaseSegment1Length_Default.h"
#include "../templates/can_PhaseSegment2LengthFreelyProgrammable_Default.h"
#include "../templates/can_BusLine3TimesSampling_Default.h"
#include "../templates/can_PropagationTimeSegment_Default.h"
#include "../templates/can_SyncJumpWidth_Default.h"
#include "../templates/can_BaudRatePrescale_Default.h"
#include "../templates/can_BusSpeed_Default.h"
#include "../templates/can_ChannelReset_pic32.h"
#include "../templates/can_ChannelUpdate_pic32.h"
#include "../templates/can_ModuleEventEnable_Default.h"
#include "../templates/can_ModuleEvents_Default.h"
#include "../templates/can_ChannelEventEnable_pic32.h"
#include "../templates/can_PendingEventsGet_Default.h"
#include "../templates/can_AllChannelEvents_Default.h"
#include "../templates/can_AllChannelOverflow_Default.h"
#include "../templates/can_ChannelEventGet_Default.h"
#include "../templates/can_ChannelForTransmitSet_pic32.h"
#include "../templates/can_PendingTransmissionsAbort_Default.h"
#include "../templates/can_TransmitChannelFlush_pic32.h"
#include "../templates/can_TransmitChannelStatus_pic32.h"
#include "../templates/can_TransmitBufferGet_pic32.h"
#include "../templates/can_TransmissionAbortStatus_pic32.h"
#include "../templates/can_ReceivedMessageGet_pic32.h"
#include "../templates/can_ChannelForReceiveSet_pic32.h"
#include "../templates/can_FilterMaskConfigure_pic32.h"
#include "../templates/can_FilterConfigure_pic32.h"
#include "../templates/can_FilterEnable_pic32.h"
#include "../templates/can_LatestFilterMatchGet_pic32.h"
#include "../templates/can_FilterToChannelLink_pic32.h"
#include "../templates/can_ReceiveErrorCount_Default.h"
#include "../templates/can_TransmitErrorCountGet_Default.h"
#include "../templates/can_ErrorStateGet_Default.h"
#include "../templates/can_ModuleInformation_Default.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void PLIB_CAN_DeviceNetConfigure(CAN_MODULE_ID index, CAN_DNET_FILTER_SIZE dncnt)
{
     CAN_DeviceNetConfigure_Default(index, dncnt);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsDeviceNet(CAN_MODULE_ID index)
{
     return CAN_ExistsDeviceNet_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_IsActive(CAN_MODULE_ID index)
{
     return CAN_IsActive_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsActiveStatus(CAN_MODULE_ID index)
{
     return CAN_ExistsActiveStatus_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_StopInIdleEnable(CAN_MODULE_ID index)
{
     CAN_StopInIdleEnable_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_StopInIdleDisable(CAN_MODULE_ID index)
{
     CAN_StopInIdleDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsStopInIdle(CAN_MODULE_ID index)
{
     return CAN_ExistsStopInIdle_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_Enable(CAN_MODULE_ID index)
{
     CAN_Enable_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_Disable(CAN_MODULE_ID index)
{
     CAN_Disable_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsEnableControl(CAN_MODULE_ID index)
{
     return CAN_ExistsEnableControl_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_TimeStampEnable(CAN_MODULE_ID index)
{
     CAN_TimeStampEnable_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_TimeStampDisable(CAN_MODULE_ID index)
{
     CAN_TimeStampDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTimeStampEnable(CAN_MODULE_ID index)
{
     return CAN_ExistsTimeStampEnable_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_TimeStampValueSet(CAN_MODULE_ID index, unsigned value)
{
     CAN_TimeStampValueSet_Default(index, value);
}

PLIB_INLINE_API unsigned PLIB_CAN_TimeStampValueGet(CAN_MODULE_ID index)
{
     return CAN_TimeStampValueGet_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTimeStampValue(CAN_MODULE_ID index)
{
     return CAN_ExistsTimeStampValue_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_BusActivityWakeupEnable(CAN_MODULE_ID index)
{
     CAN_BusActivityWakeupEnable_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_BusActivityWakeupDisable(CAN_MODULE_ID index)
{
     CAN_BusActivityWakeupDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsBusActivityWakeup(CAN_MODULE_ID index)
{
     return CAN_ExistsBusActivityWakeup_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_MemoryBufferAssign(CAN_MODULE_ID index, void* buffer)
{
     CAN_MemoryBufferAssign_Default(index, buffer);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsMemoryBufferAssign(CAN_MODULE_ID index)
{
     return CAN_ExistsMemoryBufferAssign_Default(index);
}

PLIB_INLINE_API CAN_OPERATION_MODES PLIB_CAN_OperationModeGet(CAN_MODULE_ID index)
{
     return CAN_OperationModeGet_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsOperationModeRead(CAN_MODULE_ID index)
{
     return CAN_ExistsOperationModeRead_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_OperationModeSelect(CAN_MODULE_ID index, CAN_OPERATION_MODES opMode)
{
     CAN_OperationModeSelect_Default(index, opMode);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsOperationModeWrite(CAN_MODULE_ID index)
{
     return CAN_ExistsOperationModeWrite_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_TimeStampPrescalerSet(CAN_MODULE_ID index, unsigned preScaler)
{
     CAN_TimeStampPrescalerSet_Default(index, preScaler);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTimeStampPrescaler(CAN_MODULE_ID index)
{
     return CAN_ExistsTimeStampPrescaler_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_PhaseSegment2LengthSet(CAN_MODULE_ID index, CAN_TIME_SEGMENT_LENGTH length)
{
     CAN_PhaseSegment2LengthSet_Default(index, length);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsPhaseSegment2Length(CAN_MODULE_ID index)
{
     return CAN_ExistsPhaseSegment2Length_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_PhaseSegment1LengthSet(CAN_MODULE_ID index, CAN_TIME_SEGMENT_LENGTH length)
{
     CAN_PhaseSegment1LengthSet_Default(index, length);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsPhaseSegment1Length(CAN_MODULE_ID index)
{
     return CAN_ExistsPhaseSegment1Length_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_PhaseSegment2LengthFreelyProgrammableEnable(CAN_MODULE_ID index)
{
     CAN_PhaseSegment2LengthFreelyProgrammableEnable_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_PhaseSegment2LengthFreelyProgrammableDisable(CAN_MODULE_ID index)
{
     CAN_PhaseSegment2LengthFreelyProgrammableDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsPhaseSegment2LengthFreelyProgrammable(CAN_MODULE_ID index)
{
     return CAN_ExistsPhaseSegment2LengthFreelyProgrammable_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_BusLine3TimesSamplingEnable(CAN_MODULE_ID index)
{
     CAN_BusLine3TimesSamplingEnable_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_BusLine3TimesSamplingDisable(CAN_MODULE_ID index)
{
     CAN_BusLine3TimesSamplingDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsBusLine3TimesSampling(CAN_MODULE_ID index)
{
     return CAN_ExistsBusLine3TimesSampling_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_PropagationTimeSegmentSet(CAN_MODULE_ID index, CAN_TIME_SEGMENT_LENGTH length)
{
     CAN_PropagationTimeSegmentSet_Default(index, length);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsPropagationTimeSegment(CAN_MODULE_ID index)
{
     return CAN_ExistsPropagationTimeSegment_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_SyncJumpWidthSet(CAN_MODULE_ID index, CAN_TIME_SEGMENT_LENGTH length)
{
     CAN_SyncJumpWidthSet_Default(index, length);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsSyncJumpWidthSet(CAN_MODULE_ID index)
{
     return CAN_ExistsSyncJumpWidthSet_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_BaudRatePrescaleSet(CAN_MODULE_ID index, CAN_BAUD_RATE_PRESCALE prescale)
{
     CAN_BaudRatePrescaleSet_Default(index, prescale);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsBaudRatePrescale(CAN_MODULE_ID index)
{
     return CAN_ExistsBaudRatePrescale_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_PrecalculatedBitRateSetup(CAN_MODULE_ID index, uint8_t prescale, uint8_t syncjumpWidth, uint8_t propagation, uint8_t segment1, uint8_t segment2)
{
     return CAN_PrecalculatedBitRateSetup_Default(index, prescale, syncjumpWidth, propagation, segment1, segment2);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsPrecalculatedBitRateSetup(CAN_MODULE_ID index)
{
     return CAN_ExistsPrecalculatedBitRateSetup_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_BitSamplePhaseSet(CAN_MODULE_ID index, uint8_t syncJumpWidth, uint8_t propagation, uint8_t segment1, uint8_t segment2)
{
     return CAN_BitSamplePhaseSet_Default(index, syncJumpWidth, propagation, segment1, segment2);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsBitSamplePhaseSet(CAN_MODULE_ID index)
{
     return CAN_ExistsBitSamplePhaseSet_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_BaudRatePrescaleSetup(CAN_MODULE_ID index, uint16_t prescale)
{
     return CAN_BaudRatePrescaleSetup_Default(index, prescale);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsBaudRatePrescaleSetup(CAN_MODULE_ID index)
{
     return CAN_ExistsBaudRatePrescaleSetup_Default(index);
}

PLIB_INLINE_API uint32_t PLIB_CAN_BaudRateGet(CAN_MODULE_ID index, uint32_t sysclock)
{
     return CAN_BaudRateGet_Default(index, sysclock);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsBaudRateGet(CAN_MODULE_ID index)
{
     return CAN_ExistsBaudRateGet_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_ChannelReset(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     CAN_ChannelReset_pic32(index, channel);
}

PLIB_INLINE_API bool PLIB_CAN_ChannelResetIsComplete(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     return CAN_ChannelResetIsComplete_pic32(index, channel);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsChannelReset(CAN_MODULE_ID index)
{
     return CAN_ExistsChannelReset_pic32(index);
}

PLIB_INLINE_API void PLIB_CAN_ChannelUpdate(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     CAN_ChannelUpdate_pic32(index, channel);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsChannelUpdate(CAN_MODULE_ID index)
{
     return CAN_ExistsChannelUpdate_pic32(index);
}

PLIB_INLINE_API void PLIB_CAN_ModuleEventEnable(CAN_MODULE_ID index, CAN_MODULE_EVENT flags)
{
     CAN_ModuleEventEnable_Default(index, flags);
}

PLIB_INLINE_API void PLIB_CAN_ModuleEventDisable(CAN_MODULE_ID index, CAN_MODULE_EVENT flags)
{
     CAN_ModuleEventDisable_Default(index, flags);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsModuleEventEnable(CAN_MODULE_ID index)
{
     return CAN_ExistsModuleEventEnable_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_ModuleEventClear(CAN_MODULE_ID index, CAN_MODULE_EVENT flags)
{
     CAN_ModuleEventClear_Default(index, flags);
}

PLIB_INLINE_API CAN_MODULE_EVENT PLIB_CAN_ModuleEventGet(CAN_MODULE_ID index)
{
     return CAN_ModuleEventGet_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsModuleEventClear(CAN_MODULE_ID index)
{
     return CAN_ExistsModuleEventClear_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_ChannelEventEnable(CAN_MODULE_ID index, CAN_CHANNEL channel, CAN_CHANNEL_EVENT flags)
{
     CAN_ChannelEventEnable_pic32(index, channel, flags);
}

PLIB_INLINE_API void PLIB_CAN_ChannelEventDisable(CAN_MODULE_ID index, CAN_CHANNEL channel, CAN_CHANNEL_EVENT flags)
{
     CAN_ChannelEventDisable_pic32(index, channel, flags);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsChannelEventEnable(CAN_MODULE_ID index)
{
     return CAN_ExistsChannelEventEnable_pic32(index);
}

PLIB_INLINE_API CAN_EVENT_CODE PLIB_CAN_PendingEventsGet(CAN_MODULE_ID index)
{
     return CAN_PendingEventsGet_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsPendingEventsGet(CAN_MODULE_ID index)
{
     return CAN_ExistsPendingEventsGet_Default(index);
}

PLIB_INLINE_API CAN_CHANNEL_MASK PLIB_CAN_AllChannelEventsGet(CAN_MODULE_ID index)
{
     return CAN_AllChannelEventsGet_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsAllChannelEvents(CAN_MODULE_ID index)
{
     return CAN_ExistsAllChannelEvents_Default(index);
}

PLIB_INLINE_API CAN_CHANNEL_MASK PLIB_CAN_AllChannelOverflowStatusGet(CAN_MODULE_ID index)
{
     return CAN_AllChannelOverflowStatusGet_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsAllChannelOverflow(CAN_MODULE_ID index)
{
     return CAN_ExistsAllChannelOverflow_Default(index);
}

PLIB_INLINE_API CAN_CHANNEL_EVENT PLIB_CAN_ChannelEventGet(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     return CAN_ChannelEventGet_Default(index, channel);
}

PLIB_INLINE_API void PLIB_CAN_ChannelEventClear(CAN_MODULE_ID index, CAN_CHANNEL channel, CAN_CHANNEL_EVENT events)
{
     CAN_ChannelEventClear_Default(index, channel, events);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsChannelEvent(CAN_MODULE_ID index)
{
     return CAN_ExistsChannelEvent_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_ChannelForTransmitSet(CAN_MODULE_ID index, CAN_CHANNEL channel, uint8_t channelSize, CAN_TX_RTR rtren, CAN_TXCHANNEL_PRIORITY priority)
{
     CAN_ChannelForTransmitSet_pic32(index, channel, channelSize, rtren, priority);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsChannelForTransmitSet(CAN_MODULE_ID index)
{
     return CAN_ExistsChannelForTransmitSet_pic32(index);
}

PLIB_INLINE_API void PLIB_CAN_PendingTransmissionsAbort(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     CAN_PendingTransmissionsAbort_Default(index, channel);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsPendingTransmissionsAbort(CAN_MODULE_ID index)
{
     return CAN_ExistsPendingTransmissionsAbort_Default(index);
}

PLIB_INLINE_API void PLIB_CAN_TransmitChannelFlush(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     CAN_TransmitChannelFlush_pic32(index, channel);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTransmitChannelFlush(CAN_MODULE_ID index)
{
     return CAN_ExistsTransmitChannelFlush_pic32(index);
}

PLIB_INLINE_API CAN_TX_CHANNEL_STATUS PLIB_CAN_TransmitChannelStatusGet(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     return CAN_TransmitChannelStatusGet_pic32(index, channel);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTransmitChannelStatus(CAN_MODULE_ID index)
{
     return CAN_ExistsTransmitChannelStatus_pic32(index);
}

PLIB_INLINE_API CAN_TX_MSG_BUFFER* PLIB_CAN_TransmitBufferGet(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     return CAN_TransmitBufferGet_pic32(index, channel);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTransmitBufferGet(CAN_MODULE_ID index)
{
     return CAN_ExistsTransmitBufferGet_pic32(index);
}

PLIB_INLINE_API bool PLIB_CAN_TransmissionIsAborted(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     return CAN_TransmissionIsAborted_pic32(index, channel);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTransmissionIsAborted(CAN_MODULE_ID index)
{
     return CAN_ExistsTransmissionIsAborted_pic32(index);
}

PLIB_INLINE_API CAN_RX_MSG_BUFFER* PLIB_CAN_ReceivedMessageGet(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     return CAN_ReceivedMessageGet_pic32(index, channel);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsReceivedMessageGet(CAN_MODULE_ID index)
{
     return CAN_ExistsReceivedMessageGet_pic32(index);
}

PLIB_INLINE_API void PLIB_CAN_ChannelForReceiveSet(CAN_MODULE_ID index, CAN_CHANNEL channel, uint32_t channelSize, CAN_RX_DATA_MODE dataOnly)
{
     CAN_ChannelForReceiveSet_pic32(index, channel, channelSize, dataOnly);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsChannelForReceiveSet(CAN_MODULE_ID index)
{
     return CAN_ExistsChannelForReceiveSet_pic32(index);
}

PLIB_INLINE_API void PLIB_CAN_FilterMaskConfigure(CAN_MODULE_ID index, CAN_FILTER_MASK mask, uint32_t maskBits, CAN_ID_TYPE idType, CAN_FILTER_MASK_TYPE mide)
{
     CAN_FilterMaskConfigure_pic32(index, mask, maskBits, idType, mide);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsFilterMaskConfigure(CAN_MODULE_ID index)
{
     return CAN_ExistsFilterMaskConfigure_pic32(index);
}

PLIB_INLINE_API void PLIB_CAN_FilterConfigure(CAN_MODULE_ID index, CAN_FILTER filter, uint32_t id, CAN_ID_TYPE filterType)
{
     CAN_FilterConfigure_pic32(index, filter, id, filterType);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsFilterConfigure(CAN_MODULE_ID index)
{
     return CAN_ExistsFilterConfigure_pic32(index);
}

PLIB_INLINE_API void PLIB_CAN_FilterEnable(CAN_MODULE_ID index, CAN_FILTER filter)
{
     CAN_FilterEnable_pic32(index, filter);
}

PLIB_INLINE_API void PLIB_CAN_FilterDisable(CAN_MODULE_ID index, CAN_FILTER filter)
{
     CAN_FilterDisable_pic32(index, filter);
}

PLIB_INLINE_API bool PLIB_CAN_FilterIsDisabled(CAN_MODULE_ID index, CAN_FILTER filter)
{
     return CAN_FilterIsDisabled_pic32(index, filter);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsFilterEnable(CAN_MODULE_ID index)
{
     return CAN_ExistsFilterEnable_pic32(index);
}

PLIB_INLINE_API CAN_FILTER PLIB_CAN_LatestFilterMatchGet(CAN_MODULE_ID index)
{
     return CAN_LatestFilterMatchGet_pic32(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsLatestFilterMatchGet(CAN_MODULE_ID index)
{
     return CAN_ExistsLatestFilterMatchGet_pic32(index);
}

PLIB_INLINE_API void PLIB_CAN_FilterToChannelLink(CAN_MODULE_ID index, CAN_FILTER filter, CAN_FILTER_MASK mask, CAN_CHANNEL channel)
{
     CAN_FilterToChannelLink_pic32(index, filter, mask, channel);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsFilterToChannelLink(CAN_MODULE_ID index)
{
     return CAN_ExistsFilterToChannelLink_pic32(index);
}

PLIB_INLINE_API int PLIB_CAN_ReceiveErrorCountGet(CAN_MODULE_ID index)
{
     return CAN_ReceiveErrorCountGet_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsReceiveErrorCount(CAN_MODULE_ID index)
{
     return CAN_ExistsReceiveErrorCount_Default(index);
}

PLIB_INLINE_API int PLIB_CAN_TransmitErrorCountGet(CAN_MODULE_ID index)
{
     return CAN_TransmitErrorCountGet_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTransmitErrorCountGet(CAN_MODULE_ID index)
{
     return CAN_ExistsTransmitErrorCountGet_Default(index);
}

PLIB_INLINE_API CAN_ERROR_STATE PLIB_CAN_ErrorStateGet(CAN_MODULE_ID index)
{
     return CAN_ErrorStateGet_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsErrorState(CAN_MODULE_ID index)
{
     return CAN_ExistsErrorState_Default(index);
}

PLIB_INLINE_API char PLIB_CAN_TotalChannelsGet(CAN_MODULE_ID index)
{
     return CAN_TotalChannelsGet_Default(index);
}

PLIB_INLINE_API char PLIB_CAN_TotalFiltersGet(CAN_MODULE_ID index)
{
     return CAN_TotalFiltersGet_Default(index);
}

PLIB_INLINE_API char PLIB_CAN_TotalMasksGet(CAN_MODULE_ID index)
{
     return CAN_TotalMasksGet_Default(index);
}

PLIB_INLINE_API bool PLIB_CAN_ExistsModuleInfo(CAN_MODULE_ID index)
{
     return CAN_ExistsModuleInfo_Default(index);
}

#endif
