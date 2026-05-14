#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern void operator delete(void* ptr);
extern "C" void* std_bad_alloc_vftable;
extern "C" void std_exception_destructor(std::exception*);

std::bad_alloc* std_bad_alloc_vector_deleting_destructor(std::bad_alloc* self, unsigned int flags)
{
    *(uint32_t*)self = (uint32_t)&std_bad_alloc_vftable;
    std_exception_destructor(reinterpret_cast<std::exception*>(self));
    if ((flags & 1) != 0)
        operator delete(self);
    return self;
}
