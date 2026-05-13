#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
CBallManager* scalar_deleting_destructor_CBallManager(CBallManager* self, char a2)
{
    CBallManager::~CBallManager();
    if ((a2 & 1) != 0)
        operator delete(self);
    return self;
}
