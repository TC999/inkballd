#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    extern void operator delete(void* ptr);
}

CSurface* CSurface::scalar_deleting_destructor(char should_delete)
{
    CSurface::~CSurface();
    if ((should_delete & 1) != 0)
        operator delete(this);
    return this;
}
