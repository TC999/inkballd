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
    extern void operator delete(void* ptr);
}

struct BallPoints {
    void* data_ptr; // Pointer to allocated data

    // Scalar deleting destructor
    void** __thiscall BallPoints::scalar_deleting_destructor(void **this, char should_delete)
    {
        BallPoints::~BallPoints(this);
        if ((should_delete & 1) != 0)
            operator delete(this);
        return this;
    }
};
