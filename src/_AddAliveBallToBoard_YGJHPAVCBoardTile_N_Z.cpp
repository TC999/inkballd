#include <cstdint>
#include <new>
#include <windows.h>

class Helpers {
public:
    class CLogBlock {
    public:
        CLogBlock(void* buffer, const char* message, int* error_code);
        ~CLogBlock();
    };
};

class CBoardTile;
class CBoardObject;
class CBall;
class CBallManager;
class CGameBoard;

struct CBallLayout {
    uint32_t vftable_ptr;
    uint32_t field_4;
    uint32_t field_8;
    double field_C;
    double field_10;
    uint32_t field_14;
    uint32_t field_18;
    uint32_t field_1C;
    uint32_t field_20;
    double field_24;
    double field_28;
    uint32_t field_2C;
    uint32_t field_30;
    uint32_t field_34;
    uint32_t field_38;
    uint32_t field_3C;
    uint32_t field_40;
    uint32_t field_44;
    uint32_t field_48;
    uint32_t field_4C;
    uint32_t field_50;
    uint32_t field_54;
    uint32_t field_58;
    uint32_t field_5C;
    uint32_t field_60;
    uint32_t field_64;
    uint32_t field_68;
    uint32_t field_6C;
    uint32_t field_70;
    uint32_t field_74;
    uint32_t field_78;
    uint32_t field_7C;
    uint32_t field_80;
    uint32_t field_84;
    uint32_t field_88;
    uint32_t field_8C;
    uint32_t field_90;
    uint32_t field_94;
    uint32_t field_98;
    uint32_t field_9C;
    uint32_t field_A0;
    uint32_t field_A4;
    uint32_t field_A8;
    uint32_t field_AC;
    uint32_t field_B0;
    uint32_t field_B4;
    uint32_t field_B8;
    uint32_t field_BC;
    uint32_t field_C0;
    uint32_t field_C4;
    uint32_t field_C8;
    uint32_t field_CC;
    uint32_t field_D0;
    uint32_t field_D4;
    uint32_t field_D8;
    uint32_t field_DC;
    uint32_t field_E0;
    uint32_t field_E4;
    uint32_t field_E8;
    uint32_t field_EC;
    uint32_t field_F0;
    uint32_t field_F4;
    uint32_t field_F8;
    uint32_t field_FC;
    uint32_t field_100;
    uint32_t field_104;
    uint32_t field_108;
    uint32_t field_10C;
    uint32_t field_110;
    uint32_t field_114;
    uint32_t field_118;
    uint32_t field_11C;
    uint32_t field_120;
    uint32_t field_124;
    uint32_t field_128;
    uint32_t field_12C;
    uint32_t field_130;
    uint32_t field_134;
    uint32_t field_138;
    uint32_t field_13C;
    uint32_t field_140;
    uint32_t field_144;
    uint32_t field_148;
    uint32_t field_14C;
    uint32_t field_150;
    uint32_t field_154;
    uint32_t field_158;
    uint32_t field_15C;
};

extern "C" {
    extern void* g_pCGameBoard;
    
    int __stdcall AddAliveBallToBoard(int ball_type, CBoardTile* tile, double speed)
    {
        char* bitmap_rect;
        int ball_result;
        POINT center_point;
        uint8_t log_buffer[8];
        int error_code[4] = {0};
        int init_step = 0;
        CBoardObject* ball_object = nullptr;

        Helpers::CLogBlock log_block(log_buffer, "AddAliveBallToBoard", error_code);
        
        if (CGameBoard::NumBallsOnBoard(g_pCGameBoard) >= 64) {
            DisplayBoardLoadMsg();
        }
        
        CBoardObject::GetCenterPoint(tile, &center_point);
        init_step = 1;
        
        ball_object = reinterpret_cast<CBoardObject*>(operator new(0x1A8u));
        init_step = 2;
        
        if (ball_object)
        {
            bitmap_rect = CGameBoard::GetBitmapRect(ball_type + 2);
            ball_result = CBall::CBall(reinterpret_cast<int>(ball_object), 
                                     reinterpret_cast<int>(bitmap_rect), 
                                     ball_type, 1, 
                                     *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(g_pCGameBoard) + 2471));
        }
        else
        {
            ball_result = 0;
        }
        
        init_step = 0;
        if (ball_result)
        {
            CBall::AddRef(reinterpret_cast<CBall*>(ball_result));
            
            auto ball_layout = reinterpret_cast<CBallLayout*>(ball_result);
            ball_layout->field_24 = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(g_pCGameBoard) + 2471);
            ball_layout->field_28 = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(g_pCGameBoard) + 2471);
            ball_layout->field_C = static_cast<double>(center_point.x) - static_cast<double>(*reinterpret_cast<int*>(reinterpret_cast<char*>(g_pCGameBoard) + 2471)) * 0.5;
            ball_layout->field_10 = static_cast<double>(center_point.y) - 0.5 * static_cast<double>(*reinterpret_cast<int*>(reinterpret_cast<char*>(g_pCGameBoard) + 2471));
            
            CBallManager::SetBallSpeed(*reinterpret_cast<CBallManager**>(reinterpret_cast<char*>(g_pCGameBoard) + 2476), 
                                     reinterpret_cast<CBall*>(ball_result), 
                                     speed);
            
            ball_layout->field_154 = 1;
            ball_layout->field_158 = 1;
            
            CGameBoard::AddBall(g_pCGameBoard, reinterpret_cast<CBall*>(ball_result));
            
            init_step = -1;
            error_code[0] = 0;
            return 0;
        }
        else
        {
            init_step = -1;
            error_code[0] = -2147024882; // E_OUTOFMEMORY
            return -2147024882;
        }
    }
}
