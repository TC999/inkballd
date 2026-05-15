#include "global_types.h"
#include <cstdint>
#include <windows.h>
void GetBoundingRect_CBoardObject(CBoardObject* self, RECT* bounding_rect)
{
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBoardObject::GetBoundingRect", 0);
    bounding_rect->left = static_cast<int>(self->position_x);
    bounding_rect->right = static_cast<int>(static_cast<double>(self->width) + self->position_x);
    bounding_rect->top = static_cast<int>(self->position_y);
    bounding_rect->bottom = static_cast<int>(static_cast<double>(self->height) + self->position_y);
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
