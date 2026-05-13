#include "global_types.h"
#include <cstdint>
#include <new>
#include <exception>

std::bad_alloc* bad_alloc_func(std::bad_alloc* this_ptr)
{
    new (this_ptr) std::bad_alloc();
    auto layout = reinterpret_cast<BadAllocLayout*>(this_ptr);
    layout->vftable_ptr = 0;
    if (layout->field_4 == 0 && !layout->field_8)
        layout->field_C = nullptr;
    return this_ptr;
}
