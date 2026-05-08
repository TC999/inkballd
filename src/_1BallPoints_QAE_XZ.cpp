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
    extern void operator delete[](void* ptr);
}

struct BallPoints {
    void* data_ptr; // Pointer to allocated data

    ~BallPoints() {
        void* data_to_free;
        uint8_t log_buffer[16];
        int flag;

        Helpers::CLogBlock::CLogBlock(&log_buffer, "BallPoints::~BallPoints", 0);
        data_to_free = this->data_ptr;
        flag = 0;
        if (data_to_free) {
            operator delete[](data_to_free);
            this->data_ptr = nullptr;
        }
        flag = -1;
        Helpers::CLogBlock::~CLogBlock(&log_buffer);
    }
};
