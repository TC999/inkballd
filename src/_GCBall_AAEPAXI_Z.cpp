#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    extern void operator delete(void* ptr);
}

CBall* CBall::scalar_deleting_destructor(char should_delete)
{
    CBall::~CBall();
    if ((should_delete & 1) != 0)
        operator delete(this);
    return this;
}
