#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

};

extern "C" void* CInk_vftable; // Forward declaration of virtual table

CMovingObject* __thiscall CMovingObject::CMovingObject(CMovingObject *this)
{
    uint8_t log_buffer[8];

    CBoardObject::CBoardObject(this);
    this->vftable = &CInk_vftable;
    Helpers::CLogBlock::CLogBlock(&log_buffer, "CMovingObject::CMovingObject", 0);
    this->velocity_x = 0.0;
    this->velocity_y = 0.0;
    this->acceleration_x = 0.0;
    this->acceleration_y = 0.0;
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
    return this;
}

#endif
