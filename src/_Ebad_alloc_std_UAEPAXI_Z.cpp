#include <cstdint>
#include <windows.h>

extern "C" {
    extern void operator delete(void* ptr);
}

struct std::bad_alloc {
    void* vftable; // offset 0x0
    // ... other members
};

struct std::exception {
    // ... exception members
};

extern "C" void* std_bad_alloc_vftable; // Forward declaration of virtual table
extern "C" void std_exception_destructor(std::exception*); // Forward declaration

std::bad_alloc* __thiscall std::bad_alloc::vector_deleting_destructor(std::bad_alloc *this, char should_delete)
{
    this->vftable = &std_bad_alloc_vftable;
    std_exception_destructor(reinterpret_cast<std::exception*>(this));
    if ((should_delete & 1) != 0)
        operator delete(this);
    return this;
}
