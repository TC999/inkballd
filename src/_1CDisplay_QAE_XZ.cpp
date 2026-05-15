#include "global_types.h"
#include <cstdint>

CDisplay::~CDisplay()
{
    int destroy_result;
    uint8_t log_buffer[8];
    int error_code;
    int cleanup_flag;

    error_code = 0;
    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CDisplay::~CDisplay", error_code);
    cleanup_flag = 0;
    destroy_result = CDisplay::DestroyObjects(self);
    cleanup_flag = -1;
    error_code = destroy_result;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
