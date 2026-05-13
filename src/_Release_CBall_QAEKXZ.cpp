#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

int Release_CBall(CBall *self)
{
    bool is_last_reference;
    uint32_t new_reference_count;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(&log_buffer), "CBall::Release", 0);
    flag = 0;
    is_last_reference = (--self->reference_count) == 1;
    new_reference_count = self->reference_count;
    if (is_last_reference)
        CBall::scalar_deleting_destructor(self, 1);
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
    return new_reference_count;
}
