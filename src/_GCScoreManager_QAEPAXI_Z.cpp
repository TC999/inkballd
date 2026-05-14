#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
CScoreManager* scalar_deleting_destructor_CScoreManager(CScoreManager* self, char a2)
{
    self->~CScoreManager();
    if ((a2 & 1) != 0)
        operator delete(self);
    return self;
}
