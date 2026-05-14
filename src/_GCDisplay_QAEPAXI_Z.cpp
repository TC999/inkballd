#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
CDisplay* scalar_deleting_destructor_CDisplay(CDisplay* self, char a2)
{
    self->~CDisplay();
    if ((a2 & 1) != 0)
        operator delete(self);
    return self;
}
