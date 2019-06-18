/* Created by plibgen $Revision: 1.31 $ */

#ifndef _CTMU_P32MZ2048EFM064_H
#define _CTMU_P32MZ2048EFM064_H

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

    CTMU_NUMBER_OF_MODULES = 0

} CTMU_MODULE_ID;

typedef enum {

    CTMU_EDGE_SELECT_NONE

} CTMU_EDGE_SELECT;

typedef enum {

    CTMU_EDGE_SENSITIVITY_NONE

} CTMU_EDGE_SENSITIVITY;

typedef enum {

    CTMU_EDGE_POLARITY_NONE

} CTMU_EDGE_POLARITY;

typedef enum {

    CTMU_TRIGGER_SOURCES_NONE

} CTMU_TRIGGER_SOURCES;

typedef enum {

    CTMU_CURRENT_RANGE_NONE

} CTMU_CURRENT_RANGE;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_EdgeSensitivitySet(CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber, CTMU_EDGE_SENSITIVITY edgeSense)
{
     
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsEdgeSensitivity(CTMU_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_EdgePolaritySet(CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber, CTMU_EDGE_POLARITY edgePolarity)
{
     
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsEdgePolarity(CTMU_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_EdgeTriggerSourceSelect(CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber, CTMU_TRIGGER_SOURCES triggerSource)
{
     
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsEdgeTriggerSource(CTMU_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_CTMU_EdgeIsSet(CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_EdgeSet(CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber)
{
     
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsEdgeStatus(CTMU_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_Disable(CTMU_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_Enable(CTMU_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsModuleEnable(CTMU_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_StopInIdleDisable(CTMU_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_StopInIdleEnable(CTMU_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsStopInIdle(CTMU_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_TimePulseGenerationDisable(CTMU_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_TimePulseGenerationEnable(CTMU_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsTimePulseGeneration(CTMU_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_EdgeDisable(CTMU_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_EdgeEnable(CTMU_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsEdgeEnable(CTMU_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_EdgeSequenceDisable(CTMU_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_EdgeSequenceEnable(CTMU_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsEdgeSequencing(CTMU_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_CurrentDischargeEnable(CTMU_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_CurrentDischargeDisable(CTMU_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsCurrentDischarge(CTMU_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_AutomaticADCTriggerDisable(CTMU_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_AutomaticADCTriggerEnable(CTMU_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsAutomaticADCTrigger(CTMU_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_CurrentTrimSet(CTMU_MODULE_ID index, int16_t currentTrim)
{
     
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsCurrentTrim(CTMU_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CTMU_CurrentRangeSet(CTMU_MODULE_ID index, CTMU_CURRENT_RANGE currentRange)
{
     
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsCurrentRange(CTMU_MODULE_ID index)
{
     return (bool)0;
}

#endif
