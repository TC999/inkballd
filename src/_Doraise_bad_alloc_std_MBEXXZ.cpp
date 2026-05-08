#include <cstdint>
#include <windows.h>

extern "C" {
    extern void _CxxThrowException(void* exception_object, void* throw_info);
}

struct std::bad_alloc {
    // ... exception members
};

extern "C" void* _TI2_AVbad_alloc_std__; // Forward declaration of throw info

[[noreturn]] void __thiscall std::bad_alloc::_Doraise(std::bad_alloc *this)
{
    uint8_t exception_object[12];

    std::bad_alloc::bad_alloc(reinterpret_cast<std::bad_alloc*>(exception_object), this);
    _CxxThrowException(exception_object, &_TI2_AVbad_alloc_std__);
}
