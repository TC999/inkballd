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
    extern void* operator new(size_t size);
}

struct BallPoints {
    void* data_ptr;
    // ... other members
};

struct CBall {
    double position_x; // offset 0x10 (1 * 8)
    double position_y; // offset 0x18 (2 * 8)
    uint32_t width; // offset 0x40 (6 * 4)
    uint32_t height; // offset 0x44 (7 * 4)
    void* ball_points_data; // offset 0x88 (35 * 4)
    void* ball_points_ptr; // offset 0x8C (30 * 4)
    // ... other members
};

void __thiscall CBall::SetTallness(CBall *this, void* new_tallness)
{
    bool is_same_tallness;
    int size_difference;
    double offset_adjustment;
    int double_size_difference;
    double original_position_x;
    double original_position_y;
    BallPoints* new_ball_points;
    BallPoints* created_points;
    void** old_ball_points;
    uint8_t log_buffer[20];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::SetTallness", 0);
    size_difference = reinterpret_cast<int>(new_tallness) - reinterpret_cast<int>(this->ball_points_data);
    is_same_tallness = new_tallness == this->ball_points_data;
    flag = 0;
    
    if (!is_same_tallness)
    {
        offset_adjustment = static_cast<double>(size_difference);
        double_size_difference = 2 * size_difference;
        original_position_x = this->position_x;
        this->width += double_size_difference;
        this->height += double_size_difference;
        this->position_x = original_position_x - offset_adjustment;
        this->position_y = this->position_y - offset_adjustment;
        CBall::CheckBoardBounds(this);
        this->ball_points_data = new_tallness;
        
        flag = 1;
        new_ball_points = reinterpret_cast<BallPoints*>(operator new(4));
        flag = 2;
        if (new_ball_points)
            created_points = BallPoints::BallPoints(new_ball_points, this->width);
        else
            created_points = nullptr;
            
        old_ball_points = reinterpret_cast<void**>(this->ball_points_ptr);
        flag = 1;
        if (old_ball_points)
        {
            BallPoints::scalar_deleting_destructor(old_ball_points, 1);
            this->ball_points_ptr = nullptr;
        }
        this->ball_points_ptr = created_points;
    }
    
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
}
