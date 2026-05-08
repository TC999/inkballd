#include <cstdint>
#include <windows.h>

extern "C" {
    extern void operator delete(void* ptr);
}

struct CBall {
    // ... members
};

CBall* __thiscall CBall::scalar_deleting_destructor(CBall *this, char should_delete)
{
    CBall::~CBall(this);
    if ((should_delete & 1) != 0)
        operator delete(this);
    return this;
}
