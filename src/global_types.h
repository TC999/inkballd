#pragma once

#include <cstdint>
#include <windows.h>
#include "defs.h"

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
    static int GetTileByIndices(CGameBoard* self, int a2, int a3);
    static void RestoreSurfaces(CScoreManager** self);
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
};
CGameBoard* CGameBoard_Ctor(CGameBoard* this_ptr, HWND hWnd, void* param);
void CGameBoard_Dtor(CGameBoard* self, int flags);
int CGameBoard_Init(CGameBoard* self);
struct BallPoints {
    void* vftable;
    uint32_t* data_array;
    BallPoints();
    ~BallPoints();
};

struct CBall {
    void* vftable;
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
    ~CInk();
    static void ClearInk(CInk* self);
    static void OnDisplayChange(CInk* self);
    static void Cleanup(CInk* self);
};
struct CSink;
struct CGameObject;
struct CMovingObject;
struct CUIBarObject;
struct CBoardTile;
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
struct CBallManager;
struct BallPoints;
struct CBoardObject;

// ============================================================================
// Game struct definitions with static method declarations
// ============================================================================
struct CTimeManager {
    void* vftable;
    static uint32_t GetTime(void* self);
    static void SetTime(void* self, uint32_t time);
    static void InitTime(void* self, uint32_t time);
    static int InitSurface(CTimeManager* self);
};

struct CScoreManager {
    void* vftable;
    CScoreManager();
    ~CScoreManager();
    static void IncrementScore(void* self, uint32_t count);
    static uint32_t GetScore(void* self);
    static void ResetScore(void* self);
};

struct CTileManager {
    void* vftable;
    static void SetTiles(void* self, uint32_t score);
    static void ResetTileCount(void* self);
    static int GetTileCount(void* self);
};

struct CBoardTile {
    void* vftable;
    CBoardTile();
    CBoardTile(int tile_type, int x, int y, int rect_param);
};
extern "C" { extern void* CBoardTile_vftable; }

struct CSurface {
    void* vftable;
    CSurface();
    ~CSurface();
    static int IsColorKeyed(CSurface* self);
    static void* GetDDrawSurface(CSurface* self);
};

struct CBoardTileRLColored {
    void* vftable;
    static void ToggleState(void* self);
};

struct CUIBarObject {
    void* vftable;
    static void GetBoundingRect(void* self, RECT* out);
};

struct CBoardObject {
    void* vftable;
    CBoardObject();
    static void GetBoundingRect(uint32_t self, RECT* out);
};

struct CMovingObject : public CBoardObject {
    CMovingObject();
};

struct CDisplay {
    void* vftable;
    CDisplay();
    ~CDisplay();
    static void Blt(void* self, int x, int y, void* surface, RECT* src);
    static int Present(void* self, RECT* rect);
    static void BltInk(void* self, RECT* rect);
    static int DestroyObjects(CDisplay* self);
};

struct CBallManager {
    void* vftable;
    CBallManager();
    ~CBallManager();
    static int InitSurface(CBallManager* self);
};

// ============================================================================
// COM interfaces and external types
// ============================================================================
struct IUnknown;
struct IInkStroke;
struct IInkObject;
struct IRenderingContext;
struct IDirectDrawSurface7;
struct IDirectDraw7;
struct IDirectDrawPalette;
struct IDirectDrawSurface7Vtbl;
struct CTabletContextInfo;

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
    static void WriteDifficulty(CRegistryManager*, uint32_t);
    static uint32_t ReadHiScore(CRegistryManager*);
    static void WriteHiScore(CRegistryManager*, int);
};

struct CBoardManager {
    void* vftable;
    CBoardManager();
    ~CBoardManager();
    static int LoadBoardFromResources(CBoardManager* manager, const wchar_t* name, void* boardData, int* boardSize);
    static int LoadRandomBoardFromResources(CBoardManager* manager, void* boardData, int* boardSize);
    static void SetDifficulty(CBoardManager* manager, uint32_t difficulty);
    static void* GetLastLoadedBoardData(CBoardManager*);
    static int LoadRandomBonusBoardFromResources(CBoardManager*, void*, int*);
};

struct CBitmapRects {
    void* vftable;
    static char* GetBitmapRect(CBitmapRects* self, int id);
};

extern "C" { extern void* SQM_INCREMENT_DWORD; }

// ============================================================================
// External data references
// ============================================================================
extern "C" {
    extern uint64_t WPP_GLOBAL_Control;
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
}

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
