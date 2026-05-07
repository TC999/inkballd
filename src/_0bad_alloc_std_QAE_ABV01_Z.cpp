#include <cstdint>

std::bad_alloc* std::bad_alloc::bad_alloc(std::bad_alloc* this_ptr, const std::bad_alloc* other)
{
    exception::exception(this_ptr, other);
    *reinterpret_cast<uint32_t*>(this_ptr) = reinterpret_cast<uint32_t>(&std::bad_alloc::`vftable');
    return this_ptr;
}
