#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

CDisplay* CDisplay::scalar_deleting_destructor(char a2)
{
    CDisplay::~CDisplay();
    if ((a2 & 1) != 0)
        operator delete(this);
    return this;
}
