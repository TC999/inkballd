#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

CInk* CInk::scalar_deleting_destructor(char a2)
{
    CInk::~CInk();
    if ((a2 & 1) != 0)
        operator delete(this);
    return this;
}
