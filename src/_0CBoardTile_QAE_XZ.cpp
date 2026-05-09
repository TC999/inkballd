#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    namespace Helpers {
        class CLogBlock {
        public:
            CLogBlock(void* buffer, const char* message, int);
            ~CLogBlock();
        };
    }
}

};

extern "C" void* CBoardTile_vftable; // Forward declaration of virtual table

CBoardTile* __thiscall CBoardTile::CBoardTile(CBoardTile *this)
{
    uint8_t log_buffer[8];

    CBoardObject::CBoardObject(this);
    this->vftable = &CBoardTile_vftable;
    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardTile::CBoardTile", 0);
    this->tile_type = 0;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return this;
}
