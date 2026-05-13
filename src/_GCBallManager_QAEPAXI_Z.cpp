#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

CBallManager* CBallManager::scalar_deleting_destructor(char a2)
{
    CBallManager::~CBallManager();
    if ((a2 & 1) != 0)
        operator delete(this);
    return this;
}
