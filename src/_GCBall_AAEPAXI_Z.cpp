#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    extern void operator delete(void* ptr);
}
CBall* scalar_deleting_destructor_CBall(CBall* self, char should_delete)
{
    CBall::~CBall();
    if ((should_delete & 1) != 0)
        operator delete(self);
    return self;
}
