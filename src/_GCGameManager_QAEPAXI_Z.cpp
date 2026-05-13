#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

CGameManager* CGameManager::scalar_deleting_destructor(char a2)
{
    CGameManager::~CGameManager();
    if ((a2 & 1) != 0)
        operator delete(this);
    return this;
}
