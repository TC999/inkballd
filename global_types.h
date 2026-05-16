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
    int GetRandomNumber(int max_value);
};

// Additional forward declarations for completeness
struct CGameManager;
struct CDisplay;
struct CScoreManager;
struct CTileManager;
struct CTimeManager;
struct CInk;
struct CSink;
struct CGameObject;
struct CUIBarObject;
struct CBoardTileWall;
struct CBoardTileBreakWall;
struct CBoardTileBumper;
struct CBoardTileChevron;
struct CBoardTileDrain;
struct CBoardTileOWF;
struct CBoardTileRLColored;
struct CBoardTileRLGray;
struct CRegistryManager;
struct CTabLicense;

// External function declarations
extern "C" int __stdcall AddBallToBoard(int ball_type);
extern CBoardTile* __stdcall BuildTileObject(int a1, int a2, int a3);
void __stdcall DisplayBoardLoadMsg();

// COM interfaces
struct IUnknown;
struct IInkStroke;
struct IDirectDrawSurface7;
struct IDirectDraw7;
struct IDirectDrawPalette;