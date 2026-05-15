#include "global_types.h"
#include <new>
#include <cstdint>
#include <windows.h>

extern void* CBall_vftable;

void CBall_destructor(CBall* self)
{
    uint8_t log_buffer[16];

    *reinterpret_cast<void**>(self) = &CBall_vftable;
    new (log_buffer) Helpers::CLogBlock(log_buffer, "CBall::~CBall", 0);
    auto layout = reinterpret_cast<CBallLayout*>(self);
    if (layout->field_120)
    {
        operator delete(reinterpret_cast<void*>(layout->field_120));
        layout->field_120 = 0;
    }
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}

CBall::~CBall()
{
    CBall_destructor(this);
}
