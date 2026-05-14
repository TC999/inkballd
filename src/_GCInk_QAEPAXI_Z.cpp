#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
CInk* scalar_deleting_destructor_CInk(CInk* self, char a2)
{
    self->~CInk();
    if ((a2 & 1) != 0)
        operator delete(self);
    return self;
}
