#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

TabUtils* __stdcall GenerateLastErrorHR_TabUtils(TabUtils *self, int a2)
{
    TabUtils* result;
    bool v3;

    result = (TabUtils*)GetLastError();
    v3 = (int)result < 0;
    if ((int)result > 0)
    {
        result = (TabUtils*)((uint16_t)result | 0x80070000);
        v3 = (int)result < 0;
    }
    if (!v3)
        return self;
    return result;
}
