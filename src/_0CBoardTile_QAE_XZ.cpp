#include "global_types.h"
#include <new>
#include <cstdint>
#include <windows.h>

extern void* CBoardTile_vftable;
CBoardTile* CBoardTile_CBoardTile(CBoardTile* self, CBoardTile* self)
{
    uint8_t log_buffer[8];

    CBoardObject::CBoardObject(self);
    self->vftable = &CBoardTile_vftable;
    new (log_buffer) Helpers::CLogBlock(log_buffer, "CBoardTile::CBoardTile", 0);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 68) = 0;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return self;
}
