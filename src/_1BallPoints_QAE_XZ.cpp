#include "global_types.h"
#include <cstdint>
#include <windows.h>

void operator delete[](void* ptr);

void BallPoints_dtor(BallPoints* self)
{
    if (self->data_array)
    {
        operator delete[](self->data_array);
        self->data_array = nullptr;
    }
}
