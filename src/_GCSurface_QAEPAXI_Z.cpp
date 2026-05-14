#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern void operator delete(void* ptr);
CSurface* scalar_deleting_destructor_CSurface(CSurface* self, char should_delete)
{
    self->~CSurface();
    if ((should_delete & 1) != 0)
        operator delete(self);
    return self;
}
