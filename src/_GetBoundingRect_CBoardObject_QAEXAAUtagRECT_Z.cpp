#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

};

void __thiscall CBoardObject::GetBoundingRect(CBoardObject *this, RECT* bounding_rect)
{
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardObject::GetBoundingRect", 0);
    bounding_rect->left = static_cast<int>(this->position_x);
    bounding_rect->right = static_cast<int>(static_cast<double>(this->width) + this->position_x);
    bounding_rect->top = static_cast<int>(this->position_y);
    bounding_rect->bottom = static_cast<int>(static_cast<double>(this->height) + this->position_y);
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
}

#endif
