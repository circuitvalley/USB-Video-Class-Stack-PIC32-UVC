/* Created by plibgen $Revision: 1.31 $ */

#ifndef _BMX_P32MZ2048EFM064_H
#define _BMX_P32MZ2048EFM064_H

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

    BMX_NUMBER_OF_MODULES = 0

} BMX_MODULE_ID;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API bool PLIB_BMX_ExistsArbitrationMode(BMX_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_ArbitrationModeSet(BMX_MODULE_ID index, PLIB_BMX_ARB_MODE mode)
{

}

PLIB_INLINE_API PLIB_BMX_ARB_MODE _PLIB_UNSUPPORTED PLIB_BMX_ArbitrationModeGet(BMX_MODULE_ID index)
{
     return (PLIB_BMX_ARB_MODE)0;
}

PLIB_INLINE_API bool PLIB_BMX_ExistsDataRamWaitState(BMX_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_DataRamWaitStateSet(BMX_MODULE_ID index, PLIB_BMX_DATA_RAM_WAIT_STATES wait)
{

}

PLIB_INLINE_API PLIB_BMX_DATA_RAM_WAIT_STATES _PLIB_UNSUPPORTED PLIB_BMX_DataRamWaitStateGet(BMX_MODULE_ID index)
{
     return (PLIB_BMX_DATA_RAM_WAIT_STATES)0;
}

PLIB_INLINE_API bool PLIB_BMX_ExistsProgramFlashMemoryCacheDma(BMX_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_ProgramFlashMemoryCacheDmaEnable(BMX_MODULE_ID index)
{

}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_ProgramFlashMemoryCacheDmaDisable(BMX_MODULE_ID index)
{

}

PLIB_INLINE_API bool PLIB_BMX_ExistsBusExceptionIXI(BMX_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_BusExceptionIXIEnable(BMX_MODULE_ID index)
{

}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_BusExceptionIXIDisable(BMX_MODULE_ID index)
{

}

PLIB_INLINE_API bool PLIB_BMX_ExistsBusExceptionICD(BMX_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_BusExceptionICDEnable(BMX_MODULE_ID index)
{

}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_BusExceptionICDDisable(BMX_MODULE_ID index)
{

}

PLIB_INLINE_API bool PLIB_BMX_ExistsBusExceptionDMA(BMX_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_BusExceptionDMAEnable(BMX_MODULE_ID index)
{

}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_BusExceptionDMADisable(BMX_MODULE_ID index)
{

}

PLIB_INLINE_API bool PLIB_BMX_ExistsBusExceptionData(BMX_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_BusExceptionDataEnable(BMX_MODULE_ID index)
{

}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_BusExceptionDataDisable(BMX_MODULE_ID index)
{

}

PLIB_INLINE_API bool PLIB_BMX_ExistsBusExceptionInstruction(BMX_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_BusExceptionInstructionEnable(BMX_MODULE_ID index)
{

}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_BusExceptionInstructionDisable(BMX_MODULE_ID index)
{

}

PLIB_INLINE_API bool PLIB_BMX_ExistsProgramFlashPartition(BMX_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API size_t _PLIB_UNSUPPORTED PLIB_BMX_ProgramFlashPartitionGet(BMX_MODULE_ID index)
{
     return (size_t)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_ProgramFlashPartitionSet(BMX_MODULE_ID index, size_t user_size)
{

}

PLIB_INLINE_API bool PLIB_BMX_ExistsDataRAMPartition(BMX_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_BMX_DataRAMPartitionSet(BMX_MODULE_ID index, size_t kernProgOffset, size_t userDataOffset, size_t userProgOffset)
{

}

PLIB_INLINE_API size_t _PLIB_UNSUPPORTED PLIB_BMX_DataRAMKernelProgramOffsetGet(BMX_MODULE_ID index)
{
     return (size_t)0;
}

PLIB_INLINE_API size_t _PLIB_UNSUPPORTED PLIB_BMX_DataRAMUserDataOffsetGet(BMX_MODULE_ID index)
{
     return (size_t)0;
}

PLIB_INLINE_API size_t _PLIB_UNSUPPORTED PLIB_BMX_DataRAMUserProgramOffsetGet(BMX_MODULE_ID index)
{
     return (size_t)0;
}

PLIB_INLINE_API bool PLIB_BMX_ExistsProgramFlashMemorySize(BMX_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API size_t _PLIB_UNSUPPORTED PLIB_BMX_ProgramFlashMemorySizeGet(BMX_MODULE_ID index)
{
     return (size_t)0;
}

PLIB_INLINE_API bool PLIB_BMX_ExistsDataRAMSize(BMX_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API size_t _PLIB_UNSUPPORTED PLIB_BMX_DataRAMSizeGet(BMX_MODULE_ID index)
{
     return (size_t)0;
}

PLIB_INLINE_API bool PLIB_BMX_ExistsProgramFlashBootSize(BMX_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API size_t _PLIB_UNSUPPORTED PLIB_BMX_ProgramFlashBootSizeGet(BMX_MODULE_ID index)
{
     return (size_t)0;
}

#endif
