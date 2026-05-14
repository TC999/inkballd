#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern void _CxxThrowException(void* exception_object, void* throw_info);
extern "C" void* _TI2_AVbad_alloc_std__;

void std_bad_alloc_Doraise(std::bad_alloc* self)
{
    uint8_t exception_object[12];

    std::bad_alloc::bad_alloc(reinterpret_cast<std::bad_alloc*>(exception_object), "bad_alloc");
    _CxxThrowException(exception_object, &_TI2_AVbad_alloc_std__);
}
