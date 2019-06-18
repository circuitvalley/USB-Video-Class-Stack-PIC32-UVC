/* Created by plibgen $Revision: 1.31 $ */

#ifndef _ADCHS_P32MZ2048EFM064_H
#define _ADCHS_P32MZ2048EFM064_H

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

    ADCHS_ID_0 = _ADCHS_BASE_ADDRESS,
    ADCHS_NUMBER_OF_MODULES = 1

} ADCHS_MODULE_ID;

typedef enum {

    ADCHS_AN0 = 0,
    ADCHS_AN1 = 1,
    ADCHS_AN2 = 2,
    ADCHS_AN3 = 3,
    ADCHS_AN4 = 4,
    ADCHS_AN5 = 5,
    ADCHS_AN6 = 6,
    ADCHS_AN7 = 7,
    ADCHS_AN8 = 8,
    ADCHS_AN9 = 9,
    ADCHS_AN10 = 10,
    ADCHS_AN11 = 11,
    ADCHS_AN12 = 12,
    ADCHS_AN13 = 13,
    ADCHS_AN14 = 14,
    ADCHS_AN15 = 15,
    ADCHS_AN16 = 16,
    ADCHS_AN17 = 17,
    ADCHS_AN18 = 18,
    ADCHS_AN43 = 43,
    ADCHS_AN44 = 44

} ADCHS_AN_INPUT_ID;

typedef enum {

    ADCHS_CLASS12_AN0 = 0,
    ADCHS_CLASS12_AN1 = 1,
    ADCHS_CLASS12_AN2 = 2,
    ADCHS_CLASS12_AN3 = 3,
    ADCHS_CLASS12_AN4 = 4,
    ADCHS_CLASS12_AN5 = 5,
    ADCHS_CLASS12_AN6 = 6,
    ADCHS_CLASS12_AN7 = 7,
    ADCHS_CLASS12_AN8 = 8,
    ADCHS_CLASS12_AN9 = 9,
    ADCHS_CLASS12_AN10 = 10,
    ADCHS_CLASS12_AN11 = 11

} ADCHS_CLASS12_AN_INPUT_ID;

typedef enum {

    ADCHS_CLASS2_AN5 = 5,
    ADCHS_CLASS2_AN6 = 6,
    ADCHS_CLASS2_AN7 = 7,
    ADCHS_CLASS2_AN8 = 8,
    ADCHS_CLASS2_AN9 = 9,
    ADCHS_CLASS2_AN10 = 10,
    ADCHS_CLASS2_AN11 = 11

} ADCHS_CLASS2_AN_INPUT_ID;

typedef enum {

    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_0_BITS = 0,
    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_1_BITS = 1,
    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_2_BITS = 2,
    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_3_BITS = 3,
    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_4_BITS = 4,
    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_5_BITS = 5,
    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_6_BITS = 6,
    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_7_BITS = 7

} ADCHS_INTERRUPT_BIT_SHIFT_LEFT;

typedef enum {

    ADCHS_DATA_RESOLUTION_6BIT = 0,
    ADCHS_DATA_RESOLUTION_8BIT = 1,
    ADCHS_DATA_RESOLUTION_10BIT = 2,
    ADCHS_DATA_RESOLUTION_12BIT = 3

} ADCHS_DATA_RESOLUTION;

typedef enum {

    ADCHS_SCAN_TRIGGER_SOURCE_NONE = 0,
    ADCHS_SCAN_TRIGGER_SOURCE_GLOBAL_SOFTWARE_EDGE = 1,
    ADCHS_SCAN_TRIGGER_SOURCE_SOFTWARE_LEVEL = 2,
    ADCHS_SCAN_TRIGGER_SOURCE_INT0 = 4,
    ADCHS_SCAN_TRIGGER_SOURCE_TMR1_MATCH = 5,
    ADCHS_SCAN_TRIGGER_SOURCE_TMR3_MATCH = 6,
    ADCHS_SCAN_TRIGGER_SOURCE_TMR5_MATCH = 7,
    ADCHS_SCAN_TRIGGER_SOURCE_OC1 = 8,
    ADCHS_SCAN_TRIGGER_SOURCE_OC3 = 9,
    ADCHS_SCAN_TRIGGER_SOURCE_OC5 = 10,
    ADCHS_SCAN_TRIGGER_SOURCE_COUT1 = 11,
    ADCHS_SCAN_TRIGGER_SOURCE_COUT2 = 12

} ADCHS_SCAN_TRIGGER_SOURCE;

typedef enum {

    ADCHS_CHARGEPUMP_DISABLE = 0,
    ADCHS_CHARGEPUMP_ENABLE = 1

} ADCHS_CHARGEPUMP_MODE;

typedef enum {

    ADCHS_FAST_SYNC_SYSTEM_CLOCK_DISABLE = 0,
    ADCHS_FAST_SYNC_SYSTEM_CLOCK_ENABLE = 1

} ADCHS_FAST_SYNC_SYSTEM_CLOCK;

typedef enum {

    ADCHS_FAST_SYNC_PERIPHERAL_CLOCK_DISABLE = 0,
    ADCHS_FAST_SYNC_PERIPHERAL_CLOCK_ENABLE = 1

} ADCHS_FAST_SYNC_PERIPHERAL_CLOCK;

typedef enum {

    ADCHS_OUTPUT_DATA_FORMAT_INTEGER = 0,
    ADCHS_OUTPUT_DATA_FORMAT_FRACTIONAL = 1

} ADCHS_OUTPUT_DATA_FORMAT;

typedef enum {

    ADCHS_DMA_BUFFER_LENGTH_NONE

} ADCHS_DMA_BUFFER_LENGTH;

typedef enum {

    ADCHS_DMA_GLOBAL_NONE

} ADCHS_DMA_GLOBAL;

typedef enum {

    ADCHS_DMA_BUFFER_FULL_INTERRUPT_NONE

} ADCHS_DMA_BUFFER_FULL_INTERRUPT;

typedef enum {

    ADCHS_DMA_COUNT_NONE

} ADCHS_DMA_COUNT;

typedef enum {

    ADCHS_CVD_CAPACITOR_0PF = 0,
    ADCHS_CVD_CAPACITOR_2_5PF = 1,
    ADCHS_CVD_CAPACITOR_5PF = 2,
    ADCHS_CVD_CAPACITOR_7_5PF = 3,
    ADCHS_CVD_CAPACITOR_10PF = 4,
    ADCHS_CVD_CAPACITOR_12_5PF = 5,
    ADCHS_CVD_CAPACITOR_15PF = 6,
    ADCHS_CVD_CAPACITOR_17_5PF = 7

} ADCHS_CVD_CAPACITOR;

typedef enum {

    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_1 = 0,
    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_2 = 1,
    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_3 = 2,
    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_4 = 3,
    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_5 = 4,
    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_6 = 5,
    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_7 = 6,
    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_8 = 7

} ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK;

typedef enum {

    ADCHS_CLOCK_SOURCE_PBCLK = 0,
    ADCHS_CLOCK_SOURCE_FRC = 1,
    ADCHS_CLOCK_SOURCE_RFCLK3 = 2,
    ADCHS_CLOCK_SOURCE_SYSCLK = 3

} ADCHS_CLOCK_SOURCE;

typedef enum {

    ADCHS_VREF_AVDD_AVSS = 0,
    ADCHS_VREF_EXTVREFP_AVSS = 1,
    ADCHS_VREF_AVDD_EXTVREFN = 2,
    ADCHS_VREF_EXTVREFP_EXTVREFN = 3

} ADCHS_VREF_SOURCE;

typedef enum {

    ADCHS_CHANNEL_0 = 0,
    ADCHS_CHANNEL_1 = 1,
    ADCHS_CHANNEL_2 = 2,
    ADCHS_CHANNEL_3 = 3,
    ADCHS_CHANNEL_4 = 4,
    ADCHS_CHANNEL_7 = 7

} ADCHS_CHANNEL_ID;

typedef enum {

    ADCHS_CHANNEL_0_DEFAULT_INP_AN0 = 0,
    ADCHS_CHANNEL_1_DEFAULT_INP_AN1 = 4,
    ADCHS_CHANNEL_2_DEFAULT_INP_AN2 = 8,
    ADCHS_CHANNEL_3_DEFAULT_INP_AN3 = 12,
    ADCHS_CHANNEL_4_DEFAULT_INP_AN4 = 16,
    ADCHS_CHANNEL_0_ALTERNATE_INP_AN45 = 1,
    ADCHS_CHANNEL_1_ALTERNATE_INP_AN46 = 5,
    ADCHS_CHANNEL_2_ALTERNATE_INP_AN47 = 9,
    ADCHS_CHANNEL_3_ALTERNATE_INP_AN48 = 13,
    ADCHS_CHANNEL_4_ALTERNATE_INP_AN49 = 17

} ADCHS_CHANNEL_INP_SEL;

typedef enum {

    ADCHS_DEFAULT_CLASS1_AN0 = 0,
    ADCHS_ALTERNATE_CLASS1_AN45 = 1

} ADCHS_CHANNEL_0_INP_SEL;

typedef enum {

    ADCHS_DEFAULT_CLASS1_AN1 = 4,
    ADCHS_ALTERNATE_CLASS1_AN46 = 5

} ADCHS_CHANNEL_1_INP_SEL;

typedef enum {

    ADCHS_DEFAULT_CLASS1_AN2 = 8,
    ADCHS_ALTERNATE_CLASS1_AN47 = 9

} ADCHS_CHANNEL_2_INP_SEL;

typedef enum {

    ADCHS_DEFAULT_CLASS1_AN3 = 12,
    ADCHS_ALTERNATE_CLASS1_AN48 = 13

} ADCHS_CHANNEL_3_INP_SEL;

typedef enum {

    ADCHS_DEFAULT_CLASS1_AN4 = 16,
    ADCHS_ALTERNATE_CLASS1_AN49 = 17

} ADCHS_CHANNEL_4_INP_SEL;

typedef enum {

    ADCHS_CHANNEL_5_INP_SEL_NONE

} ADCHS_CHANNEL_5_INP_SEL;

typedef enum {

    ADCHS_CHANNEL_UNSYNC_TRIGGER_UNSYNC_SAMPLING = 0,
    ADCHS_CHANNEL_SYNC_SAMPLING = 1,
    ADCHS_CHANNEL_SYNC_TRIGGER_UNSYNC_SAMPLING = 2

} ADCHS_CHANNEL_TRIGGER_SAMPLING_SEL;

typedef enum {

    ADCHS_INPUT_MODE_SINGLE_ENDED_UNIPOLAR = 0,
    ADCHS_INPUT_MODE_SINGLE_ENDED_TWOS_COMP = 1,
    ADCHS_INPUT_MODE_DIFFERENTIAL_UNIPOLAR = 2,
    ADCHS_INPUT_MODE_DIFFERENTIAL_TWOS_COMP = 3

} ADCHS_INPUT_MODE;

typedef enum {

    ADCHS_DIGITAL_COMPARATOR_1 = 0,
    ADCHS_DIGITAL_COMPARATOR_2 = 1,
    ADCHS_DIGITAL_COMPARATOR_3 = 2,
    ADCHS_DIGITAL_COMPARATOR_4 = 3,
    ADCHS_DIGITAL_COMPARATOR_5 = 4,
    ADCHS_DIGITAL_COMPARATOR_6 = 5

} ADCHS_DIGITAL_COMPARATOR_ID;

typedef enum {

    ADCHS_DIGITAL_FILTER_1 = 0,
    ADCHS_DIGITAL_FILTER_2 = 1,
    ADCHS_DIGITAL_FILTER_3 = 2,
    ADCHS_DIGITAL_FILTER_4 = 3,
    ADCHS_DIGITAL_FILTER_5 = 4,
    ADCHS_DIGITAL_FILTER_6 = 5

} ADCHS_DIGITAL_FILTER_ID;

typedef enum {

    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_2X = 4,
    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_4X = 0,
    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_8X = 5,
    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_16X = 1,
    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_32X = 6,
    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_64X = 2,
    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_128X = 7,
    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_256X = 3

} ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO;

typedef enum {

    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_2 = 0,
    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_4 = 1,
    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_8 = 2,
    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_16 = 3,
    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_32 = 4,
    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_64 = 5,
    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_128 = 6,
    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_256 = 7

} ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT;

typedef enum {

    ADCHS_DIGITAL_FILTER_SIGNIFICANT_FIRST_12BITS = 0,
    ADCHS_DIGITAL_FILTER_SIGNIFICANT_ALL_16BITS = 1

} ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS;

typedef enum {

    ADCHS_SCAN_TRIGGER_SENSITIVE_EDGE = 0,
    ADCHS_SCAN_TRIGGER_SENSITIVE_LEVEL = 1

} ADCHS_SCAN_TRIGGER_SENSITIVE;

typedef enum {

    ADCHS_WARMUP_CLOCK_16 = 0,
    ADCHS_WARMUP_CLOCK_32 = 5,
    ADCHS_WARMUP_CLOCK_64 = 6,
    ADCHS_WARMUP_CLOCK_128 = 7,
    ADCHS_WARMUP_CLOCK_256 = 8,
    ADCHS_WARMUP_CLOCK_512 = 9,
    ADCHS_WARMUP_CLOCK_1024 = 10,
    ADCHS_WARMUP_CLOCK_2048 = 11,
    ADCHS_WARMUP_CLOCK_4096 = 12,
    ADCHS_WARMUP_CLOCK_8192 = 13,
    ADCHS_WARMUP_CLOCK_16384 = 14,
    ADCHS_WARMUP_CLOCK_32768 = 15

} ADCHS_WARMUP_CLOCK;

typedef enum {

    ADCHS_TRIGGER_SOURCE_NONE = 0,
    ADCHS_TRIGGER_SOURCE_GLOBAL_SOFTWARE_EDGE = 1,
    ADCHS_TRIGGER_SOURCE_SOFTWARE_LEVEL = 2,
    ADCHS_TRIGGER_SOURCE_SCAN = 3,
    ADCHS_TRIGGER_SOURCE_INT0 = 4,
    ADCHS_TRIGGER_SOURCE_TMR1_MATCH = 5,
    ADCHS_TRIGGER_SOURCE_TMR3_MATCH = 6,
    ADCHS_TRIGGER_SOURCE_TMR5_MATCH = 7,
    ADCHS_TRIGGER_SOURCE_OC1 = 8,
    ADCHS_TRIGGER_SOURCE_OC3 = 9,
    ADCHS_TRIGGER_SOURCE_OC5 = 10,
    ADCHS_TRIGGER_SOURCE_COUT1 = 11,
    ADCHS_TRIGGER_SOURCE_COUT2 = 12

} ADCHS_TRIGGER_SOURCE;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/adchs_Registers_PIC32MZ_EF.h"
#include "../templates/adchs_EnableControl_Default.h"
#include "../templates/adchs_TurboMode_Default.h"
#include "../templates/adchs_DigitalComparator_Default.h"
#include "../templates/adchs_DigitalFilter_Default.h"
#include "../templates/adchs_FIFO_Default.h"
#include "../templates/adchs_DMA_Unsupported.h"
#include "../templates/adchs_CVD_Default.h"
#include "../templates/adchs_VREFControl_Default.h"
#include "../templates/adchs_AnalogInputScan_Default.h"
#include "../templates/adchs_AnalogFeatureControl_Default.h"
#include "../templates/adchs_DigitalFeatureControl_Default.h"
#include "../templates/adchs_AnalogInputModeControl_Default.h"
#include "../templates/adchs_TriggerControl_Default.h"
#include "../templates/adchs_ChannelTriggerSampleControl_Default.h"
#include "../templates/adchs_EarlyInterruptControl_Default.h"
#include "../templates/adchs_ManualControl_Default.h"
#include "../templates/adchs_UpdateReadyControl_Default.h"
#include "../templates/adchs_InputControl_Default.h"
#include "../templates/adchs_ExternalConversionRequest_Unsupported.h"
#include "../templates/adchs_Setup_Default.h"
#include "../templates/adchs_AnalogInputCheck_Default.h"
#include "../templates/adchs_ChannelConfiguration_Default.h"
#include "../templates/adchs_ConversionResult_Default.h"
#include "../templates/adchs_ScanEnable_Unsupported.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API bool PLIB_ADCHS_ExistsRegisters(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsRegisters_PIC32MZ_EF(index);
}

PLIB_INLINE_API void PLIB_ADCHS_Enable(ADCHS_MODULE_ID index)
{
     ADCHS_Enable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_Disable(ADCHS_MODULE_ID index)
{
     ADCHS_Disable_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsEnableControl(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsEnableControl_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_TurboModeEnable(ADCHS_MODULE_ID index)
{
     ADCHS_TurboModeEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_TurboModeDisable(ADCHS_MODULE_ID index)
{
     ADCHS_TurboModeDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_TurboModeErrorHasOccurred(ADCHS_MODULE_ID index)
{
     return ADCHS_TurboModeErrorHasOccurred_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_TurboModeChannelSelect(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID masterChannelID, ADCHS_CHANNEL_ID slaveChannelID)
{
     return ADCHS_TurboModeChannelSelect_Default(index, masterChannelID, slaveChannelID);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsTurboMode(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsTurboMode_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalComparatorAnalogInputSelect(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator, ADCHS_AN_INPUT_ID analogInput)
{
     ADCHS_DigitalComparatorAnalogInputSelect_Default(index, digComparator, analogInput);
}

PLIB_INLINE_API ADCHS_AN_INPUT_ID PLIB_ADCHS_DigitalComparatorAnalogInputGet(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator)
{
     return ADCHS_DigitalComparatorAnalogInputGet_Default(index, digComparator);
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalComparatorEnable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator)
{
     ADCHS_DigitalComparatorEnable_Default(index, digComparator);
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalComparatorDisable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator)
{
     ADCHS_DigitalComparatorDisable_Default(index, digComparator);
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalComparatorInterruptEnable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator)
{
     ADCHS_DigitalComparatorInterruptEnable_Default(index, digComparator);
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalComparatorInterruptDisable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator)
{
     ADCHS_DigitalComparatorInterruptDisable_Default(index, digComparator);
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalComparatorSetup(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID id, bool intEnable, bool inBetweenOrEqual, bool greaterEqualHi, bool lessThanHi, bool greaterEqualLo, bool lessThanLo, ADCHS_AN_INPUT_ID analogInput, int16_t hiLimit, int16_t loLimit)
{
     ADCHS_DigitalComparatorSetup_Default(index, id, intEnable, inBetweenOrEqual, greaterEqualHi, lessThanHi, greaterEqualLo, lessThanLo, analogInput, hiLimit, loLimit);
}

PLIB_INLINE_API bool PLIB_ADCHS_DigitalComparatorEventHasOccurred(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID id)
{
     return ADCHS_DigitalComparatorEventHasOccurred_Default(index, id);
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalComparatorLimitSet(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID id, int16_t hiLimit, int16_t loLimit)
{
     ADCHS_DigitalComparatorLimitSet_Default(index, id, hiLimit, loLimit);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsDigitalComparator(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsDigitalComparator_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterEnable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id)
{
     ADCHS_DigitalFilterEnable_Default(index, id);
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterDisable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id)
{
     ADCHS_DigitalFilterDisable_Default(index, id);
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterOversamplingModeSetup(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id, ADCHS_AN_INPUT_ID analogInput, ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length, ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio, bool intEnable)
{
     ADCHS_DigitalFilterOversamplingModeSetup_Default(index, id, analogInput, length, ratio, intEnable);
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterAveragingModeSetup(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id, ADCHS_AN_INPUT_ID analogInput, ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length, ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count, bool intEnable)
{
     ADCHS_DigitalFilterAveragingModeSetup_Default(index, id, analogInput, length, count, intEnable);
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id, ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio)
{
     ADCHS_DigitalFilterOversamplingModeRatioSelect_Default(index, id, ratio);
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id, ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count)
{
     ADCHS_DigitalFilterAveragingModeSampleCountSelect_Default(index, id, count);
}

PLIB_INLINE_API bool PLIB_ADCHS_DigitalFilterDataIsReady(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id)
{
     return ADCHS_DigitalFilterDataIsReady_Default(index, id);
}

PLIB_INLINE_API int16_t PLIB_ADCHS_DigitalFilterDataGet(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID dfltrID)
{
     return ADCHS_DigitalFilterDataGet_Default(index, dfltrID);
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID digFilter)
{
     ADCHS_DigitalFilterDataReadyInterruptEnable_Default(index, digFilter);
}

PLIB_INLINE_API void PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID digFilter)
{
     ADCHS_DigitalFilterDataReadyInterruptDisable_Default(index, digFilter);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsDigitalFilter(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsDigitalFilter_Default(index);
}

PLIB_INLINE_API int32_t PLIB_ADCHS_FIFORead(ADCHS_MODULE_ID index)
{
     return ADCHS_FIFORead_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_FIFODataIsAvailable(ADCHS_MODULE_ID index)
{
     return ADCHS_FIFODataIsAvailable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_FIFODataReadyInterruptEnable(ADCHS_MODULE_ID index)
{
     ADCHS_FIFODataReadyInterruptEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_FIFODataReadyInterruptDisable(ADCHS_MODULE_ID index)
{
     ADCHS_FIFODataReadyInterruptDisable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_FIFOEnable(ADCHS_MODULE_ID index)
{
     ADCHS_FIFOEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_FIFODisable(ADCHS_MODULE_ID index)
{
     ADCHS_FIFODisable_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_FIFOSourceSelect(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return ADCHS_FIFOSourceSelect_Default(index, channelID);
}

PLIB_INLINE_API uint8_t PLIB_ADCHS_FIFODataCountGet(ADCHS_MODULE_ID index)
{
     return ADCHS_FIFODataCountGet_Default(index);
}

PLIB_INLINE_API ADCHS_CHANNEL_ID PLIB_ADCHS_FIFOSourceGet(ADCHS_MODULE_ID index)
{
     return ADCHS_FIFOSourceGet_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_FIFOErrorHasOccurred(ADCHS_MODULE_ID index)
{
     return ADCHS_FIFOErrorHasOccurred_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_FIFODataIsNegative(ADCHS_MODULE_ID index)
{
     return ADCHS_FIFODataIsNegative_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsFIFO(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsFIFO_Default(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DMAEnable(ADCHS_MODULE_ID index)
{
     ADCHS_DMAEnable_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DMADisable(ADCHS_MODULE_ID index)
{
     ADCHS_DMADisable_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DMASetup(ADCHS_MODULE_ID index, ADCHS_DMA_BUFFER_LENGTH bufferLengthBytes, uint32_t baseAddress, ADCHS_DMA_COUNT countMode, uint32_t countBaseAddress)
{
     ADCHS_DMASetup_Unsupported(index, bufferLengthBytes, baseAddress, countMode, countBaseAddress);
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMASourceEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return ADCHS_DMASourceEnable_Unsupported(index, channelID);
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMASourceDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return ADCHS_DMASourceDisable_Unsupported(index, channelID);
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_A_InterruptEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return ADCHS_DMABuffer_A_InterruptEnable_Unsupported(index, channelID);
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_A_InterruptDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return ADCHS_DMABuffer_A_InterruptDisable_Unsupported(index, channelID);
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_B_InterruptEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return ADCHS_DMABuffer_B_InterruptEnable_Unsupported(index, channelID);
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_B_InterruptDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return ADCHS_DMABuffer_B_InterruptDisable_Unsupported(index, channelID);
}

PLIB_INLINE_API int8_t _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_A_IsFull(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return ADCHS_DMABuffer_A_IsFull_Unsupported(index, channelID);
}

PLIB_INLINE_API int8_t _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_B_IsFull(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return ADCHS_DMABuffer_B_IsFull_Unsupported(index, channelID);
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMAOverflowErrorHasOccurred(ADCHS_MODULE_ID index)
{
     return ADCHS_DMAOverflowErrorHasOccurred_Unsupported(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsDMA(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsDMA_Unsupported(index);
}

PLIB_INLINE_API void PLIB_ADCHS_CVDEnable(ADCHS_MODULE_ID index)
{
     ADCHS_CVDEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_CVDDisable(ADCHS_MODULE_ID index)
{
     ADCHS_CVDDisable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_CVDSetup(ADCHS_MODULE_ID index, ADCHS_CVD_CAPACITOR capSel, bool inBetweenOrEqual, bool greaterEqualHi, bool lessThanHi, bool greaterEqualLo, bool lessThanLo, ADCHS_AN_INPUT_ID inputEnable, int16_t hiLimit, int16_t loLimit)
{
     ADCHS_CVDSetup_Default(index, capSel, inBetweenOrEqual, greaterEqualHi, lessThanHi, greaterEqualLo, lessThanLo, inputEnable, hiLimit, loLimit);
}

PLIB_INLINE_API int16_t PLIB_ADCHS_CVDResultGet(ADCHS_MODULE_ID index)
{
     return ADCHS_CVDResultGet_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsCVD(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsCVD_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_VREFIsReady(ADCHS_MODULE_ID index)
{
     return ADCHS_VREFIsReady_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_VREFFaultHasOccurred(ADCHS_MODULE_ID index)
{
     return ADCHS_VREFFaultHasOccurred_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_VREFReadyInterruptEnable(ADCHS_MODULE_ID index)
{
     ADCHS_VREFReadyInterruptEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_VREFReadyInterruptDisable(ADCHS_MODULE_ID index)
{
     ADCHS_VREFReadyInterruptDisable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_VREFFaultInterruptEnable(ADCHS_MODULE_ID index)
{
     ADCHS_VREFFaultInterruptEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_VREFFaultInterruptDisable(ADCHS_MODULE_ID index)
{
     ADCHS_VREFFaultInterruptDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsVREFControl(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsVREFControl_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_AnalogInputScanIsComplete(ADCHS_MODULE_ID index)
{
     return ADCHS_AnalogInputScanIsComplete_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputScanSelect(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     ADCHS_AnalogInputScanSelect_Default(index, analogInput);
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputScanRemove(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     ADCHS_AnalogInputScanRemove_Default(index, analogInput);
}

PLIB_INLINE_API bool PLIB_ADCHS_AnalogInputScanIsSelected(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     return ADCHS_AnalogInputScanIsSelected_Default(index, analogInput);
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputScanSetup(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput, ADCHS_SCAN_TRIGGER_SENSITIVE trgSensitive, ADCHS_SCAN_TRIGGER_SOURCE triggerSource)
{
     ADCHS_AnalogInputScanSetup_Default(index, analogInput, trgSensitive, triggerSource);
}

PLIB_INLINE_API void PLIB_ADCHS_ScanCompleteInterruptEnable(ADCHS_MODULE_ID index)
{
     ADCHS_ScanCompleteInterruptEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_ScanCompleteInterruptDisable(ADCHS_MODULE_ID index)
{
     ADCHS_ScanCompleteInterruptDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsAnalogInputScan(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsAnalogInputScan_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelAnalogFeatureEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     ADCHS_ChannelAnalogFeatureEnable_Default(index, channelID);
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelAnalogFeatureDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     ADCHS_ChannelAnalogFeatureDisable_Default(index, channelID);
}

PLIB_INLINE_API bool PLIB_ADCHS_ChannelIsReady(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return ADCHS_ChannelIsReady_Default(index, channelID);
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelIsReadyInterruptEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     ADCHS_ChannelIsReadyInterruptEnable_Default(index, channelID);
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelIsReadyInterruptDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     ADCHS_ChannelIsReadyInterruptDisable_Default(index, channelID);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsChannelAnalogControl(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsChannelAnalogControl_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelDigitalFeatureEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     ADCHS_ChannelDigitalFeatureEnable_Default(index, channelID);
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelDigitalFeatureDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     ADCHS_ChannelDigitalFeatureDisable_Default(index, channelID);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsChannelDigitalControl(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsChannelDigitalControl_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputModeSelect(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput, ADCHS_INPUT_MODE mode)
{
     ADCHS_AnalogInputModeSelect_Default(index, analogInput, mode);
}

PLIB_INLINE_API ADCHS_INPUT_MODE PLIB_ADCHS_AnalogInputModeGet(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     return ADCHS_AnalogInputModeGet_Default(index, analogInput);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsAnalogInputModeControl(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsAnalogInputModeControl_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputLevelTriggerSet(ADCHS_MODULE_ID index, ADCHS_CLASS12_AN_INPUT_ID analogInput)
{
     ADCHS_AnalogInputLevelTriggerSet_Default(index, analogInput);
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputEdgeTriggerSet(ADCHS_MODULE_ID index, ADCHS_CLASS12_AN_INPUT_ID analogInput)
{
     ADCHS_AnalogInputEdgeTriggerSet_Default(index, analogInput);
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputTriggerSourceSelect(ADCHS_MODULE_ID index, ADCHS_CLASS12_AN_INPUT_ID inputId, ADCHS_TRIGGER_SOURCE triggerSource)
{
     ADCHS_AnalogInputTriggerSourceSelect_Default(index, inputId, triggerSource);
}

PLIB_INLINE_API void PLIB_ADCHS_GlobalSoftwareTriggerEnable(ADCHS_MODULE_ID index)
{
     ADCHS_GlobalSoftwareTriggerEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_GlobalLevelSoftwareTriggerEnable(ADCHS_MODULE_ID index)
{
     ADCHS_GlobalLevelSoftwareTriggerEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_GlobalLevelSoftwareTriggerDisable(ADCHS_MODULE_ID index)
{
     ADCHS_GlobalLevelSoftwareTriggerDisable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_TriggerSuspendEnable(ADCHS_MODULE_ID index)
{
     ADCHS_TriggerSuspendEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_TriggerSuspendDisable(ADCHS_MODULE_ID index)
{
     ADCHS_TriggerSuspendDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsTriggerControl(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsTriggerControl_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_ChannelTriggerSampleSelect(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID, ADCHS_CHANNEL_TRIGGER_SAMPLING_SEL sampSel)
{
     return ADCHS_ChannelTriggerSampleSelect_Default(index, channelID, sampSel);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsTriggerSampleControl(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsTriggerSampleControl_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_EarlyInterruptEnable(ADCHS_MODULE_ID index)
{
     ADCHS_EarlyInterruptEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_EarlyInterruptDisable(ADCHS_MODULE_ID index)
{
     ADCHS_EarlyInterruptDisable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputEarlyInterruptEnable(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     ADCHS_AnalogInputEarlyInterruptEnable_Default(index, analogInput);
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputEarlyInterruptDisable(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     ADCHS_AnalogInputEarlyInterruptDisable_Default(index, analogInput);
}

PLIB_INLINE_API bool PLIB_ADCHS_AnalogInputEarlyInterruptIsReady(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     return ADCHS_AnalogInputEarlyInterruptIsReady_Default(index, analogInput);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsEarlyInterruptControl(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsEarlyInterruptControl_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_SoftwareSamplingStart(ADCHS_MODULE_ID index)
{
     ADCHS_SoftwareSamplingStart_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_SoftwareSamplingStop(ADCHS_MODULE_ID index)
{
     ADCHS_SoftwareSamplingStop_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_SoftwareConversionStart(ADCHS_MODULE_ID index)
{
     ADCHS_SoftwareConversionStart_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_SoftwareConversionInputSelect(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID anInput)
{
     ADCHS_SoftwareConversionInputSelect_Default(index, anInput);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsManualControl(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsManualControl_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_ControlRegistersCanBeUpdatedInterruptEnable(ADCHS_MODULE_ID index)
{
     ADCHS_ControlRegistersCanBeUpdatedInterruptEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_ControlRegistersCanBeUpdatedInterruptDisable(ADCHS_MODULE_ID index)
{
     ADCHS_ControlRegistersCanBeUpdatedInterruptDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_ControlRegistersCanBeUpdated(ADCHS_MODULE_ID index)
{
     return ADCHS_ControlRegistersCanBeUpdated_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsUpdateReadyControl(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsUpdateReadyControl_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_ChannelInputSelect(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID, ADCHS_CHANNEL_INP_SEL sel)
{
     return ADCHS_ChannelInputSelect_Default(index, channelID, sel);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsChannelInputSelectControl(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsChannelInputSelectControl_Default(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ExternalConversionRequestEnable(ADCHS_MODULE_ID index)
{
     ADCHS_ExternalConversionRequestEnable_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ExternalConversionRequestDisable(ADCHS_MODULE_ID index)
{
     ADCHS_ExternalConversionRequestDisable_Unsupported(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsExternalConversionRequestControl(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsExternalConversionRequestControl_Unsupported(index);
}

PLIB_INLINE_API void PLIB_ADCHS_Setup(ADCHS_MODULE_ID index, ADCHS_VREF_SOURCE voltageRefSelect, ADCHS_CHARGEPUMP_MODE chargePump, ADCHS_OUTPUT_DATA_FORMAT outputFormat, bool stopInIdle, ADCHS_FAST_SYNC_SYSTEM_CLOCK sysClk, ADCHS_FAST_SYNC_PERIPHERAL_CLOCK periClk, ADCHS_INTERRUPT_BIT_SHIFT_LEFT intVectorShift, uint16_t intVectorBase, ADCHS_CLOCK_SOURCE adcClockSource, int8_t adcClockDivider, ADCHS_WARMUP_CLOCK warmUpClock)
{
     ADCHS_Setup_Default(index, voltageRefSelect, chargePump, outputFormat, stopInIdle, sysClk, periClk, intVectorShift, intVectorBase, adcClockSource, adcClockDivider, warmUpClock);
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelSetup(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID, ADCHS_DATA_RESOLUTION res, uint8_t channelClockDivider, uint16_t sampleTimeCount, ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK earlyInterruptClk)
{
     ADCHS_ChannelSetup_Default(index, channelID, res, channelClockDivider, sampleTimeCount, earlyInterruptClk);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsConfiguration(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsConfiguration_Default(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_AnalogInputIsAvailable(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     return ADCHS_AnalogInputIsAvailable_Default(index, analogInput);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsAnalogInputCheck(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsAnalogInputCheck_Default(index);
}

PLIB_INLINE_API uint32_t PLIB_ADCHS_ChannelConfigurationGet(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return ADCHS_ChannelConfigurationGet_Default(index, channelID);
}

PLIB_INLINE_API void PLIB_ADCHS_ChannelConfigurationSet(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID, uint32_t config)
{
     ADCHS_ChannelConfigurationSet_Default(index, channelID, config);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsChannelConfiguration(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsChannelConfiguration_Default(index);
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputDataReadyInterruptEnable(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     ADCHS_AnalogInputDataReadyInterruptEnable_Default(index, analogInput);
}

PLIB_INLINE_API void PLIB_ADCHS_AnalogInputDataReadyInterruptDisable(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     ADCHS_AnalogInputDataReadyInterruptDisable_Default(index, analogInput);
}

PLIB_INLINE_API bool PLIB_ADCHS_AnalogInputDataIsReady(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     return ADCHS_AnalogInputDataIsReady_Default(index, analogInput);
}

PLIB_INLINE_API uint32_t PLIB_ADCHS_AnalogInputResultGet(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     return ADCHS_AnalogInputResultGet_Default(index, analogInput);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsConversionResults(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsConversionResults_Default(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelScanEnable(ADCHS_MODULE_ID index)
{
     ADCHS_ChannelScanEnable_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelScanAbort(ADCHS_MODULE_ID index)
{
     ADCHS_ChannelScanAbort_Unsupported(index);
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsScanEnable(ADCHS_MODULE_ID index)
{
     return ADCHS_ExistsScanEnable_Unsupported(index);
}

#endif
