#include <cstdint>
#include <new>
#include <exception>

extern "C" {
    std::bad_alloc* bad_alloc_func(std::bad_alloc* this_ptr, const std::bad_alloc* other)
    {
        new (this_ptr) std::bad_alloc(*other);
        *reinterpret_cast<uint32_t*>(this_ptr) = 0;
        return this_ptr;
    }
}