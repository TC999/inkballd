#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
CGameBoard* scalar_deleting_destructor_CGameBoard(CGameBoard* self, char a2)
{
    self->~CGameBoard();
    if ((a2 & 1) != 0)
        operator delete(self);
    return self;
}
