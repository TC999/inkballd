#include <cstdint>
#include <exception>

class exception {
public:
    exception(exception* this_ptr, const exception* other);
};

extern "C" {
    std::bad_alloc* bad_alloc_func(std::bad_alloc* this_ptr, const std::bad_alloc* other)
    {
        new (this_ptr) exception(reinterpret_cast<exception*>(this_ptr), reinterpret_cast<const exception*>(other));
        *reinterpret_cast<uint32_t*>(this_ptr) = 0;
        return this_ptr;
    }
}