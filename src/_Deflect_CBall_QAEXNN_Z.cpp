#include "global_types.h"
#include <cstdint>
#include <windows.h>

void Deflect_CBall(CBall *self, double impulse_x, double impulse_y)
{
    double dot_product; // st5
    uint8_t log_buffer[16]; // [esp+4h] [ebp-8h] BYREF

    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)log_buffer, "CBall::Deflect", 0);
    dot_product = impulse_x * self->velocity_x + impulse_y * self->velocity_y;
    self->velocity_x = self->velocity_x - impulse_x * ((dot_product + dot_product) / (impulse_x * impulse_x + impulse_y * impulse_y));
    self->velocity_y = self->velocity_y - (dot_product + dot_product) / (impulse_x * impulse_x + impulse_y * impulse_y) * impulse_y;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
