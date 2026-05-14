#pragma once

#include <cstdint>
#include <windows.h>
#include <new>
#include "defs.h"

#define SRRF_RT_REG_DWORD 0x00000010
typedef wchar_t* STRSAFE_LPWSTR;

// ============================================================================
// Forward declarations for helper classes
// ============================================================================
namespace Helpers {
    // CLogBlock is 8 bytes: offset 0=line(int), offset 4=name(const char*)
    // Constructor called via explicit static dispatch (placement-new pattern):
    //   CLogBlock::CLogBlock((CLogBlock*)buffer, "func_name", 0)
    // The first void* parameter is the 'this' pointer (decompiler artifact)
    struct CLogBlock {
        int line;
        const char* name;
        CLogBlock(void* self, const char* name, int line);
        CLogBlock(void* self, const char* name, int* context);
        ~CLogBlock();
    };

    // ============================================================
    // [OLD STUBS] — used by existing active callers (WinMain, MainWndProc)
    // These will be replaced by the WPP-wrapped versions below
    // ============================================================
    void UpdateWindow(HWND hWnd, int unused, int* param);
    void CloseHandle(HANDLE h, int unused, int* param);
    void LoadStringW(HINSTANCE h1, HINSTANCE h2, WCHAR* buf, uint16_t* p, int unused, int* out);
    HICON LoadIconW(HINSTANCE h1, HINSTANCE h2, int unused, int* out);
    void PostMessageW(HWND h1, HWND h2, int msg, int p1, int p2, int* out);

    // ============================================================
    // [WPP-WRAPPED] — full decompiled implementations with WPP logging
    // ============================================================
    BOOL __stdcall CloseHandle_wpp(HANDLE hObject, uint32_t* a2, int* a3);
    BOOL __stdcall DeleteDC(HDC hdc, HDC a2, int* a3);
    BOOL __stdcall DeleteObject(HGDIOBJ ho, uint32_t* a2, int* a3);
    int __stdcall GetSystemMetrics(void* self, int* a2, int* a3);
    BOOL __stdcall GetClientRect(HWND hWnd, RECT* lpRect, RECT* a3, int* a4);
    BOOL __stdcall GetWindowRect(HWND hWnd, RECT* lpRect, RECT* a3, int* a4);
    HDC __stdcall CreateCompatibleDC(HDC hdc, HDC a2, int* a3);
    HGDIOBJ __stdcall SelectObject(HDC hdc, HGDIOBJ h, uint32_t* a3, int* a4);
    HRSRC __stdcall FindResourceW(HMODULE hModule, const WCHAR* lpName, LPCWSTR lpType, uint16_t* a4, int* a5);
    HGLOBAL __stdcall LoadResource(HMODULE hModule, HRSRC hResInfo, HRSRC a3, int* a4);
    int __stdcall LoadStringW_wpp(HINSTANCE hInstance, UINT uID, LPWSTR lpBuffer, uint16_t* cchBufferMax, uint32_t* a5, int* a6);
    BOOL __stdcall PostMessageW_wpp(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, uint32_t* a5, int* a6);
    HICON __stdcall LoadCursorW(HINSTANCE hInstance, const WCHAR* lpCursorName, uint16_t* a3, int* a4);
    HICON __stdcall LoadIconW_wpp(HINSTANCE hInstance, const WCHAR* lpIconName, uint16_t* a3, int* a4);
    HANDLE __stdcall LoadImageW(HINSTANCE hInst, const WCHAR* name, UINT type, uint32_t a4, int cy, UINT fuLoad, uint32_t* a7, int* a8);
    BOOL __stdcall SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int x, int y, int width, int height, UINT flags, uint32_t* error_result, int* unused);
    BOOL __stdcall SystemParametersInfoW(UINT action, UINT param, void* value, UINT flags, uint32_t* error_result, int* unused);
    HWND __stdcall CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, uint32_t X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, HINSTANCE lpParam, uint32_t* a13, int* a14);
    LSTATUS __stdcall RegCloseKey(HKEY hKey, HKEY a2, int* a3);
    LSTATUS __stdcall RegCreateKeyExW(HKEY hKey, const WCHAR* lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition, uint32_t* a10, int* a11);
    LSTATUS __stdcall RegOpenKeyExW(HKEY hKey, const WCHAR* lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult, HKEY* a6, int* a7);
    LSTATUS __stdcall RegQueryValueExW(HKEY hKey, const WCHAR* lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData, uint32_t* a7, int* a8);
    LSTATUS __stdcall RegSetValueExW(HKEY hKey, const WCHAR* lpValueName, DWORD Reserved, DWORD dwType, BYTE* lpData, DWORD cbData, int* a7, int* a8);
    int __stdcall __wcsicmp(const wchar_t* a, const wchar_t* b);
    void* __cdecl memcpy(void* dst, const void* src, size_t n);
    void* __cdecl memset(void* dst, int val, size_t n);
}

// [TODO] TabUtils namespace — verify full definition
namespace TabUtils {
    uint32_t __stdcall GenerateLastErrorHR(uint32_t fallback, int unused);
}

// ============================================================================
// Game object structures - Forward declarations
// ============================================================================
struct CBall;
struct CGameObject;
struct CBoardTile;
struct CBitmapRects;
struct CScoreManager;
struct CGameBoard {
    void* vftable;
    uint32_t field_4;
    uint32_t field_8;
    uint32_t field_C;
    uint32_t field_10;
    uint32_t field_14;
    uint32_t field_18;
    uint32_t field_1C;
    static void QueryNewPallete(CGameBoard* self);
    static void UpdateBounds(CGameBoard* self);
    static int Paint(CGameBoard* self);
    static int PerformUpdate(CGameBoard* self, uint32_t a2, int a3);
    static CBoardTile* GetTile(CGameBoard* self, int a2, int a3);
    static int GetTileByIndices(CGameBoard* self, int a2, int a3);
    static void RestoreSurfaces(CGameBoard* self);
    static int GetRandomNumber(CGameBoard* self, int max_value);
    static void AddDisplayUpdateRect(CGameBoard* self, struct tagRECT* a2);
    static void ToggleRLWalls(CGameBoard* self, int color);
    static void AddBall(CGameBoard* self, CBall* ball);
    static void AddBallToUpdateList(CGameBoard* self, CBall* ball);
    static void AddGameObjectToUpdateList(CGameBoard* self, CGameObject* obj);
    static CBall* GetBall(CGameBoard* self, int index);
    static int NumBallsOnBoard(CGameBoard* self);
    static struct tagRECT* GetPlayingAreaRect(CGameBoard* self);
    static int BallOnTile(CGameBoard* self, CBoardTile* tile);
    static char* GetBitmapRect(CGameBoard* self, int a1);
    static void BltBoardToInk(CGameBoard* self, struct tagRECT* a1, int a2);
    static int ShadowizeTile(CGameBoard* self, CBoardTile* tile, int flags);
    static void SetTile(CGameBoard* self, CBoardTile* tile);
    static int Shadowize(CGameBoard* self, int a2, int a3, int a4, int a5);
    static int InitDirectDraw(CGameBoard* self);
    static void RedrawBoardBuffer(CGameBoard* self);
    static void CreateNewSurfaces(CGameBoard* self);
    static void RandomizeBallOrder(CGameBoard* self);
    static void DisplayFrame(CGameBoard* self, int a2, int a3);
    static void ResetBoard(CGameBoard* self);
    static void PerformGameUpdate(CGameBoard* self);
    static void scalar_deleting_destructor(CGameBoard* self, int flags);
    static void FreeDirectDraw(CGameBoard* self);
    static int BltBall(CGameBoard* self, CBall* ball, void* surface);
    static bool IsRemoteSession(CGameBoard* self);
    static int PointIntersectsWithTile(CGameBoard* self, void* point, CBoardTile* tile);
    static CBoardTile* BuildTileObject(CGameBoard* self, int tile_type, int x, int y, int rect);
    static void DisplayBoardLoadMsg(CGameBoard* self);
};
CGameBoard* CGameBoard_Ctor(CGameBoard* this_ptr, HWND hWnd, void* param);
void CGameBoard_Dtor(CGameBoard* self, int flags);
int CGameBoard_Init(CGameBoard* self);
struct BallPoints {
    void* vftable;
    uint32_t* data_array;
    BallPoints();
    BallPoints(int count, int flags);
    ~BallPoints();
    static void scalar_deleting_destructor(BallPoints* self, int flags);
};

struct CBall {
    void* vftable;
    uint32_t unk[32];
    double velocity_x;
    double velocity_y;
    double position_x;
    double position_y;
    double old_position_x;
    double old_position_y;
    uint32_t update_flags;
    uint32_t best_point_index;
    uint32_t current_point_index;
    uint32_t reference_count;
    uint32_t width;
    uint32_t height;
    uint32_t radius;
    uint32_t hidden_flag;
    uint32_t break_point_index;
    uint32_t drain_point_index;
    uint32_t collision_flags;
    double accumulator_x;
    double accumulator_y;
    double mass;
    void* ball_points_data;
    void* ball_points_ptr;
    int tile_type;
    ~CBall();
    static int* GetDrainPoints(CBall* self);
    static int* GetBreakWallPoints(CBall* self);
    static int GetCurrBallPoint(CBall* self);
    static int GetPrevBallPoint(CBall* self);
    static int AddRef(CBall* self);
    static int Release(CBall* self);
    static void SetXVel(CBall* self, long double vel);
    static void SetYVel(CBall* self, long double vel);
    static void Deflect(CBall* self, double x, double y);
    static void SetTallness(CBall* self, int tallness);
    static void UpdateObject(CBall* self, uint32_t delta_time);
    static bool CheckBoardBounds(CBall* self);
    static int Collide(CBall* self, void* a2);
    static int BallsIntersect(CBall* self, CBall* a2);
    static int VerifyCollision(CBall* self, void* rect, void* point);
    static void scalar_deleting_destructor(CBall* self, int flags);
    static int GetNextPoint(CBall* self);
    static int GetPoint(CBall* self, int index);
    static void InitBallPoints(CBall* self);
    static int MovingTowards(CBall* self, void* a2);
};

struct CMovingObject;

struct CGameManager {
    void* vftable;
    uint32_t field_4;
    uint32_t field_8;
    uint32_t field_C;
    uint32_t field_10;
    uint32_t field_14;
    uint32_t field_18;
    uint32_t field_1C;
    static void UpdateTime(CGameManager* self);
    static void DropWallTile(CGameManager* self, void* p1, void* p2);
    static void LoadBoard(CGameManager* self, void* data, int size);
    static void scalar_deleting_destructor(CGameManager* self, int flags);
};
struct CDisplay;
struct CSurface;
struct CScoreManager;
struct CTileManager;
struct CTimeManager;
struct CInk {
    void* vftable;
    uint32_t field_4;
    CInk();
    CInk(HWND hWnd);
    ~CInk();
    static void ClearInk(CInk* self);
    static void OnDisplayChange(CInk* self);
    static void Cleanup(CInk* self);
    static void SetInkRedrawFlag(CInk* self);
    static void SetInkModifiedFlag(CInk* self);
    static int HitCircleTest(CInk* self, void* point, int a3, int a4);
    static int Init(CInk* self);
    static void scalar_deleting_destructor(CInk* self, int flags);
    static void DrawInkToSurface(CInk* self, struct tagRECT* a2 = 0);
    static void GetInkUpdateRect(CInk* self, RECT* out);
};
struct CSink {
    void* vftable;
    uint32_t unk[64];
};
struct CGameObject;
struct CMovingObject;
struct CUIBarObject;
struct CBoardTile;
struct CBoardTileWall {
    void* vftable;
    uint32_t unk[30];
    static void DeflectBall(void* self, void* ball);
    static void CareAboutCollisions(void* self);
};
struct CBoardTileBreakWall {
    void* vftable;
    uint32_t unk[30];
    int tile_type;
    static void DeflectBall(void* self, void* ball);
    static void CareAboutCollisions(void* self);
};
struct CBoardTileBumper {
    void* vftable;
    uint32_t unk[30];
    static void DeflectBall(void* self, void* ball);
    static void CareAboutCollisions(void* self);
};
struct CBoardTileChevron {
    void* vftable;
    uint32_t unk[30];
    int chevron_direction;
    static void DeflectBall(void* self, void* ball);
    static void CareAboutCollisions(void* self);
};
struct CBoardTileDrain {
    void* vftable;
    uint32_t unk[30];
    static void DeflectBall(void* self, void* ball);
    static void CareAboutCollisions(void* self);
};
struct CBoardTileOWF {
    void* vftable;
    uint32_t unk[30];
    static void DeflectBall(void* self, void* ball);
    static void CareAboutCollisions(void* self);
};
struct CBoardTileRLColored;
struct CBoardTileRLGray {
    void* vftable;
    uint32_t unk[30];
    uint32_t tile_type;
    uint32_t animation_state;
    uint32_t animation_timer;
    uint32_t state_timer;
    uint32_t color_index;
    uint32_t min_time;
    uint32_t max_time;
    char* bitmap_rect;
    static void DeflectBall(void* self, void* ball);
    static void CareAboutCollisions(void* self);
};
struct CRegistryManager;
struct CTabLicense;
struct BallPoints;
struct CBoardObject;

struct BOARDHIST {
    uint32_t count;
    int history[10];
};

// ============================================================================
// Game struct definitions with static method declarations
// ============================================================================
struct CTimeManager {
    void* vftable;
    CTimeManager();
    static uint32_t GetTime(void* self);
    static void SetTime(void* self, uint32_t time);
    static void InitTime(void* self, uint32_t time);
    static int InitSurface(CTimeManager* self);
    static void Restore(CTimeManager* self);
    static void UpdateObject(CTimeManager* self, uint32_t delta_time);
    static void DrawToSurface(CTimeManager* self);
};

struct CScoreManager {
    void* vftable;
    CScoreManager();
    ~CScoreManager();
    static void IncrementScore(void* self, uint32_t count);
    static uint32_t GetScore(void* self);
    static void ResetScore(void* self);
    static int InitSurface(CScoreManager* self);
    static void Restore(CScoreManager* self);
    static void UpdateObject(CScoreManager* self, uint32_t delta_time);
    static void DrawToSurface(CScoreManager* self);
    static void scalar_deleting_destructor(CScoreManager* self, int flags);
};

struct CTileManager {
    void* vftable;
    CTileManager();
    static void SetTiles(void* self, uint32_t score);
    static void ResetTileCount(void* self);
    static int GetTileCount(void* self);
    static int InitSurface(CTileManager* self);
    static void Restore(CTileManager* self);
    static void UpdateObject(CTileManager* self, uint32_t delta_time);
    static void DrawToSurface(CTileManager* self);
};

struct CBoardTile {
    void* vftable;
    uint32_t tile_type;
    CBoardTile();
    CBoardTile(int tile_type, int x, int y, int rect_param);
    static void SetClosestSide(CBoardTile* self, void* point);
    static void DeflectBall(CBoardTile* self, void* ball);
    static void CareAboutCollisions(CBoardTile* self);
    static void UpdateObject(CBoardTile* self, uint32_t delta_time);
};
extern "C" { extern void* CBoardTile_vftable; }

struct CSurface {
    void* vftable;
    CSurface();
    ~CSurface();
    static int IsColorKeyed(CSurface* self);
    static void* GetDDrawSurface(void* self);
    static void Clear(CSurface* self, uint32_t color);
    static int SetColorKey(void* self, uint32_t color);
    static void scalar_deleting_destructor(void* self, int flags);
    static void* GetDirectDraw(CSurface* self);
    static int DrawBitmap(CSurface* self, void* bitmap, int a3, int a4, int a5, int a6);
    static int GetSurfaceDesc(CSurface* self, void* desc);
    static int ConvertGDIColor(CSurface* self, uint32_t color);
};

struct CBoardTileRLColored {
    void* vftable;
    uint32_t unk[20];
    uint32_t tile_type;
    uint32_t animation_timer;
    uint32_t animation_state;
    uint32_t color_index;
    char* bitmap_rect;
    static void ToggleState(void* self);
};


struct CUIBarObject {
    void* vftable;
    static void GetBoundingRect(void* self, RECT* out);
};

struct CBoardObject {
    void* vftable;
    uint32_t unk[44];
    uint32_t update_flags;
    uint32_t best_point_index;
    uint32_t current_point_index;
    uint32_t reference_count;
    uint32_t tile_type;
    int position_x;
    int position_y;
    int width;
    int height;
    CBoardObject();
    static void GetBoundingRect(void* self, RECT* out);
    static void GetCenterPoint(void* self, void* out);
};

struct CMovingObject : public CBoardObject {
    CMovingObject();
    static void GetMovementRect(CMovingObject* self, RECT* out);
    static void PrepareToMove(CMovingObject* self);
};

struct CDisplay {
    void* vftable;
    CDisplay();
    ~CDisplay();
    static int Blt(void* self, int x, int y, void* surface, RECT* src);
    static int Present(void* self, RECT* rect);
    static int BltInk(void* self, RECT* rect);
    static int DestroyObjects(CDisplay* self);
    static int UpdateBounds(CDisplay* self);
    static int SetPalette(void* self, void* palette);
    static int BltToBoard(void* self, uint64_t a2, uint64_t a3, void* surface, RECT* src);
    static void* GetBoardBuffer(void* self);
    static void* GetInkBuffer(void* self);
    static void* GetBackBuffer(void* self);
    static void* GetFrontBuffer(void* self);
    static int CreateSurfaceFromBitmap(void* self, void** surface, int a3, int a4, int a5);
    static int CreateSurface(void* self, void** surface, int a3, int a4);
    static int CreateWindowedDisplay(void* self, HWND hWnd, uint32_t width, uint32_t height);
    static int CreatePaletteFromBitmap(void* self, void** palette, const WCHAR* filename);
    static void scalar_deleting_destructor(void* self, int flags);
    static int ConvertGDIColor(void* self, uint32_t color);
    static void* GetDirectDraw(void* self);
    static void Clear(CDisplay* self);
    static void ClearInk(CDisplay* self);
};

struct CBallManager {
    void* vftable;
    uint32_t active_ball_count;
    uint32_t ball_start_index;
    uint32_t ball_count;
    uint32_t next_ball_timer;
    uint32_t spawn_timer;
    uint32_t spawn_delay;
    uint32_t timer_started;
    uint32_t generator_count;
    void* generators;
    uint32_t ball_points_data_offset;
    void* ball_indices;
    uint32_t unk_flags;
    uint32_t hidden_flag;
    uint32_t update_flags;
    void* update_function;
    uint32_t surface_size;
    void* surface_data;
    void* restore_function;
    double max_speed;
    double min_speed;
    CBallManager();
    ~CBallManager();
    static int InitSurface(CBallManager* self);
    static void AddBallGenerator(CBallManager* self, CBoardTile* tile);
    static void UpdateObject(CBallManager* self, uint32_t delta_time);
    static void UpdateBallList(CBallManager* self);
    static void UpdateBallPositions(CBallManager* self, uint32_t delta_time);
    static void InitBallPositions(CBallManager* self);
    static void SetBallOnLauncher(CBallManager* self, CBall* ball, CBoardTile* tile);
    static void SetBallSpeed(CBallManager* self, CBall* ball, double speed);
    static CBoardTile* GetRandomBallLauncher(CBallManager* self);
    static void DrawToSurface(CBallManager* self);
    static void Restore(CBallManager* self);
    static void scalar_deleting_destructor(CBallManager* self, int flags);
    static void Init(CBallManager* self);
    static void AddBallToBoard(CBallManager* self, CBall* ball);
};

// ============================================================================
// COM interfaces and external types
// ============================================================================
struct IUnknown;
struct IInkStroke;
struct IInkObject;
struct IRenderingContext;
struct IInkManager;
struct IInkCollect;
struct IRenderInk;
struct ITabletManager;
#ifndef __IDirectDraw7_FWD_DEFINED
#define __IDirectDraw7_FWD_DEFINED
#if !defined(DIRECTDRAW_VERSION) && !defined(__DDRAW_INCLUDED__)
struct IDirectDraw7;
struct IDirectDraw7Vtbl {
    int (__stdcall *RestoreAllSurfaces)(IDirectDraw7*);
    int (__stdcall *TestCooperativeLevel)(IDirectDraw7*);
    void* dummy[19];
};
struct IDirectDraw7 {
    IDirectDraw7Vtbl* lpVtbl;
};
#endif
#endif
#ifndef __IDirectDrawPalette_FWD_DEFINED
#define __IDirectDrawPalette_FWD_DEFINED
#if !defined(DIRECTDRAW_VERSION) && !defined(__DDRAW_INCLUDED__)
struct IDirectDrawPalette {
    void* vftable;
};
#endif
#endif
typedef IDirectDrawPalette* LPDIRECTDRAWPALETTE;
struct CTabletContextInfo {
    uint32_t unk[6];
};
struct tagSYSTEM_EVENT_DATA {
    uint32_t unk[8];
};
#ifndef __IDirectDrawSurface7_FWD_DEFINED
#define __IDirectDrawSurface7_FWD_DEFINED
#if !defined(DIRECTDRAW_VERSION) && !defined(__DDRAW_INCLUDED__)
struct IDirectDrawSurface7;
struct IDirectDrawSurface7Vtbl {
    void* dummy[10];
    int (__stdcall *BltFast)(IDirectDrawSurface7*, int, int, IDirectDrawSurface7*, RECT*, uint32_t);
    int (__stdcall *Blt)(IDirectDrawSurface7*, RECT*, IDirectDrawSurface7*, RECT*, uint32_t, uint32_t);
    int (__stdcall *GetPalette)(IDirectDrawSurface7*, LPDIRECTDRAWPALETTE*);
    int (__stdcall *SetPalette)(IDirectDrawSurface7*, IDirectDrawPalette*);
    int (__stdcall *Restore)(IDirectDrawSurface7*);
    int (__stdcall *SetColorKey)(IDirectDrawSurface7*, uint32_t, void*);
};
struct IDirectDrawSurface7 {
    IDirectDrawSurface7Vtbl* lpVtbl;
};
#endif
#endif
typedef IDirectDrawSurface7* LPDIRECTDRAWSURFACE7;
struct BoardCollection {
    const wchar_t* board_name;
    uint32_t board_data_offset;
    uint32_t unk[127];
};

// ============================================================================
// Windows API type definitions
// ============================================================================
struct HICON__;
typedef HICON__* HICON;
struct HMENU__;
typedef HMENU__* HMENU;
struct HKEY__;
typedef HKEY__* HKEY;
struct HRSRC__;
typedef HRSRC__* HRSRC;
struct _SECURITY_ATTRIBUTES;

// ============================================================================
// Enums
// ============================================================================
enum BOARD_COLOR : uint32_t {
    BOARD_COLOR_NONE = 0,
    BOARD_COLOR_RED = 1,
    BOARD_COLOR_BLUE = 2,
    BOARD_COLOR_GREEN = 3,
    BOARD_COLOR_YELLOW = 4
};

enum BOARD_SIZE : uint32_t {
    BOARD_SIZE_SMALL = 0,
    BOARD_SIZE_MEDIUM = 1,
    BOARD_SIZE_LARGE = 2
};

enum BOARD_DIFFICULTY : uint32_t {
    BOARD_DIFFICULTY_EASY = 0,
    BOARD_DIFFICULTY_MEDIUM = 1,
    BOARD_DIFFICULTY_HARD = 2
};

enum BITMAP_RECT : uint32_t {
    BITMAP_RECT_DEFAULT = 0
};

enum TILE_CARE_COLLIDE : uint32_t {
    TILE_CARE_COLLIDE_NONE = 0,
    TILE_CARE_COLLIDE_YES = 1
};

enum TILE_TYPE : uint32_t {
    TILE_TYPE_EMPTY = 0,
    TILE_TYPE_WALL = 6,
    TILE_TYPE_DRAIN = 7,
    TILE_TYPE_BREAK_WALL = 9,
    TILE_TYPE_OWF = 10,
    TILE_TYPE_BUMPER = 11
};

enum TILE_DIRECTION : uint32_t {
    TILE_DIRECTION_UP = 0,
    TILE_DIRECTION_DOWN = 1,
    TILE_DIRECTION_LEFT = 2,
    TILE_DIRECTION_RIGHT = 3
};

enum DEATH_REASON : uint32_t {
    DEATH_REASON_NONE = 0
};

// ============================================================================
// Global variables (extern declarations)
// ============================================================================
extern "C" {
    extern void* g_pDisplay;
    extern void* g_pGamePiecesSurface;
    extern void* g_pBallManagerSurface;
    extern void* g_CBitmapRects;
    extern void* g_BoardData;
    extern void* g_pIRenderingContext;
    extern void* g_pCGameManager;
    extern CGameBoard* g_pCGameBoard;
    extern void* g_CRegistryManager;
    extern void* g_CBoardManager;
    extern void* BoardData;
    extern int iBoardSizeBytes;
    extern void* g_pIInkObject;
    extern void* g_pIStroke;
    extern HWND g_hWnd;
    extern RECT g_rcClient;
    extern HINSTANCE g_hInst;
    extern HINSTANCE g_hInstance;
    extern double dSizeFactor;
    extern uint32_t dword_10B0664;
    extern uint32_t dword_10B0668;
    extern uint32_t dword_10B0640;
    extern uint32_t dword_10B062C;
    extern uint32_t dword_10B0618;
    extern uint32_t dword_10B0600;
    extern uint32_t dword_10B0604;
    extern RECT stru_10B0630;
    extern RECT stru_10B061C;
    extern RECT stru_10B0608;
    extern void* g_pTimeManagerSurface;
    extern void* g_pScoreManagerSurface;
    extern void* g_pTileManagerSurface;
    extern int g_fMouseInside;
    extern int iLastChecked;
    extern int g_fLastPauseFromMenu;
    extern RECT Rect;
    extern uint32_t dword_10B0674;
    extern uint32_t dword_10B0678;
    extern uint32_t dword_10B0670;
    extern void* g_tcid;
    extern void* g_cid;
    extern uint32_t dword_10B068C;
    extern void* g_arrTCI;
    extern uint32_t dword_105C81C;
    extern uint32_t dword_10D2F1C;
    extern uint32_t dword_10035B8;
    extern int* dword_10029E0;
    extern const GUID stru_1003974;
    extern const GUID stru_1002480;
    extern const GUID stru_1002FB8;
    extern const GUID stru_10039F4;
    extern void* unk_10B06A4;
    extern void* g_pLastLoadedLevel;
    extern BOARDHIST g_bhPrevBoards;
    extern BOARDHIST g_bhPrevBonusBoards;
    extern void* g_pInkSurface;
    extern uint32_t dwTimeDigitWidth;
    extern uint32_t dwTopDrawLoc;
    extern uint32_t dwLeftDrawDif;
    extern void* g_pIInkCollect;
    extern void* g_pIInkManager;
    extern void* g_pTabletManager;
    extern void* g_pIRenderInk;
    extern RECT g_rcInkSpace;
    extern RECT g_rcTabletInInk;
    extern const GUID IID_ITabletEventSink;
    extern const GUID IID_IUnknown;
    extern void* CSink_vftable;
}

// ============================================================================
// Layout structures for object memory layouts
// ============================================================================

// Low-level memory layout for CBall — used for raw byte-offset access
struct CBallLayout {
    uint32_t vftable_ptr;
    uint32_t field_24;
    uint32_t field_28;
    uint32_t field_32;
    uint32_t field_44;
    uint32_t field_30;   // offset 0x30 (DWORD 12) — bitmap rect pointer [TODO] verify type
    uint32_t field_56;
    uint32_t field_112;
    uint32_t field_116;
    uint32_t field_120;
    uint32_t field_124;
    uint32_t field_128;
    uint32_t field_132;
    uint32_t field_136;
    uint32_t field_140;
    uint32_t field_144;
    uint32_t field_152;
    uint32_t field_156;
    uint32_t field_160;
    uint32_t ball_points_array[64];
};

// BadAlloc memory layout
struct BadAllocLayout {
    uint32_t vftable_ptr;
    uint32_t field_4;
    uint32_t field_8;
    void* field_C;
};

// ============================================================================
// WPP / ETW tracing types
// ============================================================================
typedef uint64_t TRACEHANDLE;
typedef ULONG WMIDPREQUESTCODE;
typedef ULONG(__stdcall* WMIDPREQUEST)(WMIDPREQUESTCODE, void*, void*, void*);

struct TRACE_GUID_REGISTRATION {
    uint64_t RegHandle;
    const GUID* Guid;
};

struct WppControl {
    uint32_t unknown1;
    uint32_t vtable;
    uint32_t flags1;
    uint32_t flags2;
    uint32_t reserved1;
    uint32_t unknown2;
    uint32_t padding1;
    uint32_t unknown3;
    uint32_t flags3;
    uint32_t flags4;
    uint32_t reserved2;
    uint32_t unknown4;
};

#define WMI_ENABLE_EVENTS   1
#define WMI_DISABLE_EVENTS  0

// ============================================================================
// CRegistryManager struct definition
// ============================================================================
struct CRegistryManager {
    void* vftable;
    const wchar_t* SubKey;
    const wchar_t* ValueName;
    static uint32_t ReadDifficulty(CRegistryManager* self);
    static void WriteDifficulty(CRegistryManager* self, uint32_t difficulty);
    static uint32_t ReadHiScore(CRegistryManager* self);
    static void WriteHiScore(CRegistryManager* self, int score);
};

struct CBoardManager {
    void* vftable;
    uint32_t difficulty_level;
    CBoardManager();
    ~CBoardManager();
    static int LoadBoardFromResources(CBoardManager* manager, const wchar_t* name, void* boardData, int* boardSize);
    static int LoadRandomBoardFromResources(CBoardManager* manager, void* boardData, int* boardSize);
    static void SetDifficulty(CBoardManager* manager, uint32_t difficulty);
    static void* GetLastLoadedBoardData(CBoardManager* manager);
    static int LoadRandomBonusBoardFromResources(CBoardManager* manager, void* boardData, int* boardSize);
};

struct CBitmapRects {
    void* vftable;
    static char* GetBitmapRect(void* self, int id);
};

extern "C" { extern void* SQM_INCREMENT_DWORD; }
extern int __onexitbegin;

// ============================================================================
// External data references
// ============================================================================
extern "C" {
    extern void* WPP_GLOBAL_Control;
    extern struct WppControl WPP_MAIN_CB;
    extern const GUID* WPP_ThisDir_CTLGUID_ControlGuid;
    extern const GUID* WPP_ThisDir_CTLGUID_MobTabPerfTraceProvider;
    extern const GUID* WPP_REGISTRATION_GUIDS;
    extern uint32_t unk_10B26E0;
    extern const wchar_t* stru_1002CD8;
    extern const wchar_t* SubKey;
    extern const wchar_t* ValueName;
    extern const GUID stru_10036F8;
    extern const GUID stru_1003520;
    extern const GUID _GUID_8cec58e7_07a1_11d9_b15e_000d56bfe6ee;
    extern const GUID _GUID_8cec5884_07a1_11d9_b15e_000d56bfe6ee;
    extern wchar_t g_szAppName[];
    extern LRESULT __stdcall MainWndProc(HWND, UINT, WPARAM, LPARAM);
}

// ============================================================================
// WPP / ETW function declarations
// ============================================================================
extern "C" {
    ULONG __stdcall TraceMessage(TRACEHANDLE, ULONG, const GUID*, USHORT, ...);
    TRACEHANDLE __stdcall GetTraceLoggerHandle(void* buffer);
    uint8_t __stdcall GetTraceEnableLevel(TRACEHANDLE handle);
    ULONG __stdcall GetTraceEnableFlags(TRACEHANDLE handle);
    ULONG __stdcall RegisterTraceGuidsW(WMIDPREQUEST, void*, const GUID*, ULONG, TRACE_GUID_REGISTRATION*, ...);
    ULONG __stdcall UnregisterTraceGuids(TRACEHANDLE);
    uint32_t __stdcall WPP_SF_d(TRACEHANDLE, uint16_t, const GUID*, char);
    uint32_t __stdcall WPP_SF_s(TRACEHANDLE, uint16_t, const GUID*, const char*);
    uint32_t __stdcall WPP_SF_sL(TRACEHANDLE, uint16_t, const GUID*, const char*, char);
    uint32_t __stdcall WPP_SF_(TRACEHANDLE, uint16_t, const GUID*);
}

// ============================================================================
// Registry helper function declarations
// ============================================================================
extern "C" {
    BOOL __stdcall WriteRegValueDWORD(HKEY key, const wchar_t* sub_key, const wchar_t* value_name, uint8_t data);
    int __cdecl CreateInkballKey();
}

// ============================================================================
// CRT helper function declarations
// ============================================================================
extern "C" {
    int __cdecl ___wgetmainargs(int*, int*, int*, int, int*);
}

// ============================================================================
// CGameManager standalone function declarations (replacing invalid static ctor/dtor)
// ============================================================================
extern "C" {
    void* CGameManager_ctor(void* self, HWND hWnd);
    void CGameManager_dtor(void* self);
    int CGameManager_Init(void* self);
    void CGameManager_LoadBoard(void* self, void* boardData, int boardSize);
    void CGameManager_PerformGameUpdate(void* self);
}

// ============================================================================
// Additional standalone function declarations
// ============================================================================
extern "C" {
    void __stdcall DispError(HWND hWnd, HINSTANCE h1, HINSTANCE h2);
    int __stdcall BltBoardToInk(struct tagRECT *a1);
    void __stdcall KillPlayer(int a1);
    void __stdcall LoadNextLevel();
    char* __stdcall GetBitmapRect(int a1);
    int __stdcall GetGoldVersionOfTile(int a1);
    DWORD __stdcall timeGetTime();
    // Decompiled standalone functions
    void CheckForBallCollisionWithNonDeflectingTile(void* self);
    void CheckForBallCollisionWithBall(void* self);
    void CheckForBallCollisionWithInk(void* self);
    void CheckForBallCollisionWithTile(void* self);
     bool __stdcall BallOnTile(void* tile);
    CBall* __stdcall GetBall(int index);
    void StartTimer();
    void __stdcall AddDisplayUpdateRect(void* rect);
    void __stdcall AddGameObjectToUpdateList(void* game_object);
    void __stdcall AddBallToUpdateList(void* ball);
    void __stdcall AddRLColoredWallToList(void* wall_tile);
    void __stdcall ConvertTileToFloor(void* tile);
    void* GetTabletContextInfo(uint32_t id);
    void ShadowizeTile(CBoardTile* tile);
    void UpdateBoardTile(void* tile);
    int __stdcall fPortraitMode();
    bool fPrevSeen(void* board_hist, int index);
    void ScoreBall(void* ball, uint32_t color);
    void __stdcall ScoreBreak(void* ball);
    void SetBoardActiveState(int state);
    void ToggleRLWalls(uint32_t color);
    int __stdcall canRunInkball(int* param);
    int __stdcall AcceptInkInput();
    uint32_t CalcUnsqrtDistance(void* point1, void* point2);
    HWND GetMainWindowHwnd();
    void __stdcall SetCursorAttributes(uint32_t cursor_id);
    void __stdcall SetCursorStroke(uint32_t cursor_id, void* stroke);
    void GetInkBufferHDC(HDC* hdc);
    void __stdcall ReleaseInkBufferHDC(HDC hdc);
    // CRT helpers
    int __cdecl _time(void* timer);
    void __cdecl _srand(unsigned int seed);
    // Win32 helpers
    int __cdecl _vsnwprintf(wchar_t* buf, size_t count, const wchar_t* fmt, va_list args);
    // String helpers
    void StringExHandleOtherFlagsW(void* flags, size_t* dest, uint32_t f, void* d, void* temp, uint32_t err);
}
// Helpers functions declared inside namespace above

// ============================================================================
// Sub function declarations (extern "C" for C linkage)
// ============================================================================
/*
extern "C" {
    int __cdecl sub_4098B0(int a1);
    int __cdecl sub_40B520(int a1);
    int __cdecl sub_416510(int a1);
    int __cdecl sub_417990(int a1);
    int __cdecl sub_417A50(int a1);
    int __cdecl sub_425220(int a1, int a2);
    int __cdecl sub_425570(int a1);
    int __cdecl sub_425610(int a1);
    int __cdecl sub_425730(int a1);
    int __cdecl sub_425780(int a1);
    int __cdecl sub_425990(int a1);
    int __cdecl sub_425A10(int a1);
    int __cdecl sub_426000(int a1);
    int __cdecl sub_426070(int a1);
    int __cdecl sub_426180(int a1);
    int __cdecl sub_426360(int a1);
    int __cdecl sub_426420(int a1);
    int __cdecl sub_426510(int a1);
    int __cdecl sub_426650(int a1, int a2, int a3);
    int __cdecl sub_426760(int a1);
    int __cdecl sub_426820(int a1);
    int __cdecl sub_4268E0(int a1);
    int __cdecl sub_4269A0(int a1);
    int __cdecl sub_426B70(int a1);
    int __cdecl sub_426D50(int a1);
    int __cdecl sub_426E00(int a1);
    int __cdecl sub_426F00(int a1);
    int __cdecl sub_427020(int a1);
    int __cdecl sub_427130(int a1);
    int __cdecl sub_4271F0(int a1);
    int __cdecl sub_427320(int a1);
    int __cdecl sub_427430(int a1);
    int __cdecl sub_427A10(int a1);
    int __cdecl sub_427B80(int a1);
    int __cdecl sub_427D20(int a1);
    int __cdecl sub_427DC0(int a1);
    int __cdecl sub_427ED0(int a1);
    int __cdecl sub_427F70(int a1);
    int __cdecl sub_428000(int a1);
    int __cdecl sub_428180(int a1);
    int __cdecl sub_428230(int a1);
    int __cdecl sub_4282D0(int a1);
    int __cdecl sub_4284B0(int a1);
    int __cdecl sub_4285D0(int a1);
    int __cdecl sub_4286E0(int a1);
    int __cdecl sub_428800(int a1);
    int __cdecl sub_428880(int a1);
    int __cdecl sub_428900(int a1);
    int __cdecl sub_428A20(int a1);
    int __cdecl sub_428B00(int a1);
    int __cdecl sub_428C20(int a1);
    int __cdecl sub_428D10(int a1);
    int __cdecl sub_428E00(int a1);
    int __cdecl sub_428F00(int a1);
    int __cdecl sub_429020(int a1);
    int __cdecl sub_429180(int a1);
    int __cdecl sub_429320(int a1);
    int __cdecl sub_429410(int a1);
    int __cdecl sub_429540(int a1);
    int __cdecl sub_429580(int a1);
    int __cdecl sub_4295F0(int a1);
    int __cdecl sub_4296A0(int a1);
    int __cdecl sub_429780(int a1);
    int __cdecl sub_429840(int a1, int a2, int a3);
    int __cdecl sub_4298E0(int a1);
    int __cdecl sub_429900(int a1, int a2);
    int __cdecl sub_4299A0(int a1);
    int __cdecl sub_429A40(int a1);
    int __cdecl sub_429A70(int a1);
    int __cdecl sub_429B10(int a1);
    int __cdecl sub_429B40(int a1);
    int __cdecl sub_429C50(int a1);
    int __cdecl sub_429D80(int a1);
    int __cdecl sub_429E50(int a1);
    int __cdecl sub_429F50(int a1);
    int __cdecl sub_42A080(int a1);
    int __cdecl sub_42A140(int a1);
    int __cdecl sub_42A200(int a1);
    int __cdecl sub_42A260(int a1);
    int __cdecl sub_42A340(int a1);
    int __cdecl sub_42A3A0(int a1);
    int __cdecl sub_42A410(int a1);
    int __cdecl sub_42A470(int a1);
    int __cdecl sub_42A520(int a1);
    int __cdecl sub_42A600(int a1);
    int __cdecl sub_42A6A0(int a1);
    int __cdecl sub_42A720(int a1);
    int __cdecl sub_42A7A0(int a1);
    int __cdecl sub_42A860(int a1);
    int __cdecl sub_42A8F0(int a1);
    int __cdecl sub_42A990(int a1);
    int __cdecl sub_42AA10(int a1);
    int __cdecl sub_42AA90(int a1);
    int __cdecl sub_42AB70(int a1);
    int __cdecl sub_42AC30(int a1);
    int __cdecl sub_42AD10(int a1);
    int __cdecl sub_42ADD0(int a1);
    int __cdecl sub_42AE50(int a1);
    int __cdecl sub_42AF50(int a1);
    int __cdecl sub_42AFE0(int a1);
}
*/
