#include <cstdint>

std::bad_alloc* std::bad_alloc::bad_alloc(std::bad_alloc* this_ptr)
{
    struct BadAllocLayout {
        uint32_t vftable_ptr;
        uint32_t field_4;
        uint32_t field_8;
        char* field_C;
    };
    
    bool is_empty; // zf

    exception::exception(this_ptr);
    auto layout = reinterpret_cast<BadAllocLayout*>(this_ptr);
    is_empty = layout->field_4 == 0;
    layout->vftable_ptr = reinterpret_cast<uint32_t>(&std::bad_alloc::`vftable');
    if (is_empty && !layout->field_8)
        layout->field_C = off_101704C[0];
    return this_ptr;
}
