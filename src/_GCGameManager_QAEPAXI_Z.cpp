#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
CGameManager* scalar_deleting_destructor_CGameManager(CGameManager* self, char a2)
{
    self->~CGameManager();
    if ((a2 & 1) != 0)
        operator delete(self);
    return self;
}
