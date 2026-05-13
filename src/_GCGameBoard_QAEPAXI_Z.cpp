#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

CGameBoard* CGameBoard::scalar_deleting_destructor(char a2)
{
    CGameBoard::~CGameBoard();
    if ((a2 & 1) != 0)
        operator delete(this);
    return this;
}
