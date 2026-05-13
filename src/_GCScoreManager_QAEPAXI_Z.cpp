#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

CScoreManager* CScoreManager::scalar_deleting_destructor(char a2)
{
    CScoreManager::~CScoreManager();
    if ((a2 & 1) != 0)
        operator delete(this);
    return this;
}
