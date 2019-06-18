/* Created by plibgen $Revision: 1.31 $ */

#ifndef _ADC_P32MZ2048EFM064_H
#define _ADC_P32MZ2048EFM064_H

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

    ADC_NUMBER_OF_MODULES = 0

} ADC_MODULE_ID;

typedef enum {

    ADC_MUX_NONE

} ADC_MUX;

typedef enum {

    ADC_RESULT_BUF_STATUS_NONE

} ADC_RESULT_BUF_STATUS;

typedef enum {

    ADC_VOLTAGE_REFERENCE_NONE

} ADC_VOLTAGE_REFERENCE;

typedef enum {

    ADC_SAMPLING_MODE_NONE

} ADC_SAMPLING_MODE;

typedef enum {

    ADC_SAMPLES_PER_INTERRUPT_NONE

} ADC_SAMPLES_PER_INTERRUPT;

typedef enum {

    ADC_INPUTS_POSITIVE_NONE

} ADC_INPUTS_POSITIVE;

typedef enum {

    ADC_INPUTS_SCAN_NONE

} ADC_INPUTS_SCAN;

typedef enum {

    ADC_INPUTS_SCAN_EXTENDED_NONE

} ADC_INPUTS_SCAN_EXTENDED;

typedef enum {

    ADC_INPUTS_NEGATIVE_NONE

} ADC_INPUTS_NEGATIVE;

typedef enum {

    ADC_CLOCK_SOURCE_NONE

} ADC_CLOCK_SOURCE;

typedef enum {

    ADC_CONVERSION_TRIGGER_SOURCE_NONE

} ADC_CONVERSION_TRIGGER_SOURCE;

typedef enum {

    ADC_RESULT_FORMAT_NONE

} ADC_RESULT_FORMAT;

typedef enum {

    ADC_BUFFER_MODE_NONE

} ADC_BUFFER_MODE;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_Enable(ADC_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_Disable(ADC_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsEnableControl(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_StopInIdleEnable(ADC_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_StopInIdleDisable(ADC_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsStopInIdleControl(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_CalibrationEnable(ADC_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_CalibrationDisable(ADC_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsCalibrationControl(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_InputScanMaskAdd(ADC_MODULE_ID index, ADC_INPUTS_SCAN scanInputs)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_InputScanMaskRemove(ADC_MODULE_ID index, ADC_INPUTS_SCAN scanInputs)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsMuxInputScanSelect(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_InputScanMaskAddExtended(ADC_MODULE_ID index, ADC_INPUTS_SCAN_EXTENDED scanInputs)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_InputScanMaskRemoveExtended(ADC_MODULE_ID index, ADC_INPUTS_SCAN_EXTENDED scanInputs)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsMuxInputScanSelectExtended(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_VoltageReferenceSelect(ADC_MODULE_ID index, ADC_VOLTAGE_REFERENCE configValue)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsVoltageReference(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_MuxChannel0InputPositiveSelect(ADC_MODULE_ID index, ADC_MUX muxType, ADC_INPUTS_POSITIVE input)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsMuxChannel0PositiveInput(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_MuxChannel0InputNegativeSelect(ADC_MODULE_ID index, ADC_MUX muxType, ADC_INPUTS_NEGATIVE input)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsMuxChannel0NegativeInput(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_MuxAInputScanEnable(ADC_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_MuxAInputScanDisable(ADC_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsMuxInputScanControl(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_SamplingModeSelect(ADC_MODULE_ID index, ADC_SAMPLING_MODE mode)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsSamplingModeControl(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_SamplesPerInterruptSelect(ADC_MODULE_ID index, ADC_SAMPLES_PER_INTERRUPT value)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsSamplesPerInterruptSelect(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_SampleAutoStartEnable(ADC_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_SampleAutoStartDisable(ADC_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsSamplingAutoStart(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_SamplingStart(ADC_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_SamplingStop(ADC_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsSamplingControl(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_SampleAcquisitionTimeSet(ADC_MODULE_ID index, ADC_ACQUISITION_TIME acqTime)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsSamplingAcquisitionTime(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADC_SamplingIsActive(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_ADC_ExistsSamplingStatus(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_ConversionStart(ADC_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsConversionControl(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_ConversionClockSet(ADC_MODULE_ID index, uint32_t baseFrequency, ADC_CONVERSION_CLOCK value)
{
     
}

PLIB_INLINE_API ADC_CONVERSION_CLOCK _PLIB_UNSUPPORTED PLIB_ADC_ConversionClockGet(ADC_MODULE_ID index, uint32_t baseFrequency)
{
     return (ADC_CONVERSION_CLOCK)0;
}

PLIB_INLINE_API bool PLIB_ADC_ExistsConversionClock(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_ConversionClockSourceSelect(ADC_MODULE_ID index, ADC_CLOCK_SOURCE source)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsConversionClockSource(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_ConversionTriggerSourceSelect(ADC_MODULE_ID index, ADC_CONVERSION_TRIGGER_SOURCE source)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsConversionTriggerSource(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_ConversionStopSequenceEnable(ADC_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_ConversionStopSequenceDisable(ADC_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsConversionStopSequenceControl(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADC_ConversionHasCompleted(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_ADC_ExistsConversionStatus(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_ResultFormatSelect(ADC_MODULE_ID index, ADC_RESULT_FORMAT resultFormat)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsResultFormat(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_ResultBufferModeSelect(ADC_MODULE_ID index, ADC_BUFFER_MODE mode)
{
     
}

PLIB_INLINE_API bool PLIB_ADC_ExistsResultBufferMode(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API ADC_RESULT_BUF_STATUS _PLIB_UNSUPPORTED PLIB_ADC_ResultBufferStatusGet(ADC_MODULE_ID index)
{
     return (ADC_RESULT_BUF_STATUS)0;
}

PLIB_INLINE_API bool PLIB_ADC_ExistsResultBufferFillStatus(ADC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API ADC_SAMPLE _PLIB_UNSUPPORTED PLIB_ADC_ResultGetByIndex(ADC_MODULE_ID index, uint8_t bufferIndex)
{
     return (ADC_SAMPLE)0;
}

PLIB_INLINE_API bool PLIB_ADC_ExistsResultGetByIndex(ADC_MODULE_ID index)
{
     return (bool)0;
}

#endif
