#include "global_types.h"
#include <cstdint>
#include <new>
#include <exception>

extern "C" {
    std::bad_alloc* bad_alloc_func(std::bad_alloc* this_ptr)
    {
        bool is_empty; // zf

        new (this_ptr) std::bad_alloc();
        auto layout = reinterpret_cast<BadAllocLayout*>(this_ptr);
        is_empty = layout->field_4 == 0;
        layout->vftable_ptr = 0;
        if (is_empty && !layout->field_8)
            layout->field_C = nullptr;
        return this_ptr;
    }
}