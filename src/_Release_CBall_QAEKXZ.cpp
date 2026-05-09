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

int __thiscall CBall::Release(CBall *this)
{
    bool is_last_reference;
    uint32_t new_reference_count;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::Release", 0);
    flag = 0;
    is_last_reference = (--this->reference_count) == 1;
    new_reference_count = this->reference_count;
    if (is_last_reference)
        CBall::scalar_deleting_destructor(this, 1);
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return new_reference_count;
}
