#pragma once

// Forward declarations
struct CTabletContextInfo;
struct IRenderingContext;

// Unified structure definitions to prevent duplication
namespace Helpers {
    struct CLogBlock {
        CLogBlock(void* p, const char* name, int line);
        ~CLogBlock();
    };
}

// Game object structures
class CMovingObject {
public:
    CMovingObject(CMovingObject* this_ptr);
};

class BallPoints {
public:
    BallPoints* BallPoints_func(BallPoints* this_ptr, int radius);
    uint32_t* data_array;
};

class CBall : public CMovingObject {
public:
    CBall(CBall* this_ptr, int rect_x, int rect_y, int should_add, int ball_radius);
};

class CSurface {
public:
    static struct IDirectDrawSurface7* GetDDrawSurface(void* surface);
};

class CBitmapRects {
public:
    static char* GetBitmapRect(void* bitmap_rects, int rect_id);
};

class CBallManager {
public:
    static int InitSurface(CBallManager* this_ptr);
};

class CBoardTile {
public:
    // Inherits from CBoardObject
};

class CBoardObject {
public:
    // Contains position, scale, size and other properties
};

class CGameBoard {
public:
    // Contains game board management and state
};