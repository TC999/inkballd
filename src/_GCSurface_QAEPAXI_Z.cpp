#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    extern void operator delete(void* ptr);
}

};

CSurface* __thiscall CSurface::scalar_deleting_destructor(CSurface *this, char should_delete)
{
    CSurface::~CSurface(this);
    if ((should_delete & 1) != 0)
        operator delete(this);
    return this;
}

#endif
