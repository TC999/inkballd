#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void GetBoundingRect_CUIBarObject(CUIBarObject* self, struct tagRECT* a2)
{
    uint8_t v3[8];

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v3), "CUIBarObject::GetBoundingRect", 0);
    *a2 = *(struct tagRECT*)(reinterpret_cast<char*>(self) + 20);
    reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
}
