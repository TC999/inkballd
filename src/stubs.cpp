// stubs.cpp - Stub implementations for missing symbols
// This file provides definitions for extern symbols referenced in the compiled codebase

#include "global_types.h"
#include <cstdint>
#include <windows.h>

// ============================================================================
// Global variable definitions (only those referenced from compiled code)
// ============================================================================
extern "C" {
    // Game object pointers
    void* g_pCGameManager = nullptr;
    void* g_CBoardManager = nullptr;
    void* g_CRegistryManager = nullptr;
    CGameBoard* g_pCGameBoard = nullptr;
    void* SQM_INCREMENT_DWORD = nullptr;
    void* BoardData = nullptr;
    int iBoardSizeBytes = 0;
    void* g_pDisplay = nullptr;
    void* g_pGamePiecesSurface = nullptr;

    // Global handles
    HINSTANCE g_hInst = nullptr;

    // Global DWORD variables
    uint32_t dword_10B2704 = 0;
    uint32_t dword_10D2F34 = 0;
    uint32_t dword_10D2F30 = 0;
    uint32_t dword_10B0640 = 0;
    uint32_t dword_10B062C = 0;
    uint32_t dword_10B0618 = 0;
    uint32_t dword_10B0600 = 0;
    uint32_t dword_10B0604 = 0;

    // Global RECT variables
    RECT stru_10B0630 = {};
    RECT stru_10B061C = {};
    RECT stru_10B0608 = {};

    // Global surface pointers
    void* g_pTimeManagerSurface = nullptr;
    void* g_pScoreManagerSurface = nullptr;
    void* g_pTileManagerSurface = nullptr;
    void* g_pBallManagerSurface = nullptr;

    // Menu / UI state globals
    int g_fMouseInside = 0;
    int iLastChecked = 0;
    int g_fLastPauseFromMenu = 0;
    RECT Rect = {};

    // GUIDs
    const GUID _GUID_8cec58e7_07a1_11d9_b15e_000d56bfe6ee = {};
    const GUID _GUID_8cec5884_07a1_11d9_b15e_000d56bfe6ee = {};

    // Additional globals required by unblocked files
    uint32_t dword_10B0664 = 0;
    uint32_t dword_10B0668 = 0;
    uint32_t dword_10B0674 = 0;
    uint32_t dword_10B0678 = 0;
    uint32_t dword_10B0670 = 0;
    void* g_pIInkObject = nullptr;
    void* g_pIStroke = nullptr;
    void* g_BoardData = nullptr;
    void* g_CBitmapRects = nullptr;
    HWND g_hWnd = nullptr;
    void* CBallManager_vftable = nullptr;
    void* CDisplay_vftable = nullptr;
    void* CScoreManager_vftable = nullptr;
    void* CInk_vftable = nullptr;
    void* CTimeManager_vftable = nullptr;
    void* CTileManager_vftable = nullptr;
}

// C++ linkage globals
RECT g_rcClient = {};
uint32_t dwTimeDigitWidth = 0;
uint32_t dwTopDrawLoc = 0;
uint32_t dwLeftDrawDif = 0;

// ============================================================================
// Missing function stubs
// ============================================================================
extern "C" {
    void __stdcall DispError(HWND hWnd, HINSTANCE uID, HINSTANCE a3) { (void)hWnd; (void)uID; (void)a3; }
    int __stdcall WinSqmIsOptedIn() { return 0; }
    int __stdcall EnableClassicWispWithPtr(LPVOID* ppv) { (void)ppv; return 0; }
    void* __cdecl new_oom_handler(unsigned int size) { (void)size; return nullptr; }
    void __stdcall ExitBadCommandLine(HWND hWnd) { (void)hWnd; }
    void __stdcall SetMenuChecks(HWND hWnd) { (void)hWnd; }
    int __stdcall BltBoardToInk(struct tagRECT *a1) { (void)a1; return 0; }
    char* __stdcall GetBitmapRect(int a1) { (void)a1; return nullptr; }
    DWORD __stdcall timeGetTime() { return 0; }
}

// ============================================================================
// CBall static method stubs
// ============================================================================
int* CBall::GetDrainPoints(CBall* self) {
    (void)self;
    return nullptr;
}
int* CBall::GetBreakWallPoints(CBall* self) {
    (void)self;
    return nullptr;
}
int CBall::GetCurrBallPoint(CBall* self) {
    (void)self;
    return 0;
}
int CBall::GetPrevBallPoint(CBall* self) {
    (void)self;
    return 0;
}
int CBall::AddRef(CBall* self) {
    (void)self;
    return 0;
}
int CBall::Release(CBall* self) {
    (void)self;
    return 0;
}
void CBall::SetXVel(CBall* self, long double vel) {
    (void)self; (void)vel;
}
void CBall::SetYVel(CBall* self, long double vel) {
    (void)self; (void)vel;
}
void CBall::Deflect(CBall* self, double x, double y) {
    (void)self; (void)x; (void)y;
}
void CBall::SetTallness(CBall* self, int tallness) {
    (void)self; (void)tallness;
}
int CGameBoard::PerformUpdate(CGameBoard* self, uint32_t a2, int a3) {
    (void)self; (void)a2; (void)a3; return 0;
}
int CGameBoard::GetTileByIndices(CGameBoard* self, int a2, int a3) {
    (void)self; (void)a2; (void)a3; return 0;
}
void CGameBoard::RestoreSurfaces(CScoreManager** self) {
    (void)self;
}
void CGameBoard::QueryNewPallete(CGameBoard* self) {
    (void)self;
}
void CGameBoard::UpdateBounds(CGameBoard* self) {
    (void)self;
}
int CGameBoard::Paint(CGameBoard* self) {
    (void)self; return 0;
}
// [TODOne] AddDisplayUpdateRect
// [TODOne] ToggleRLWalls
// [TODOne] AddBall
// [TODOne] AddBallToUpdateList
// [TODOne] AddGameObjectToUpdateList
// [TODOne] GetBall
// [TODOne] NumBallsOnBoard
// [TODOne] GetPlayingAreaRect
int CGameBoard::BallOnTile(CGameBoard* self, CBoardTile* tile) {
    (void)self; (void)tile; return 0;
}
char* CGameBoard::GetBitmapRect(CGameBoard* self, int a1) {
    (void)self; (void)a1; return nullptr;
}
void CGameBoard::ToggleRLWalls(CGameBoard* self, int color) {
    (void)self; (void)color;
}
void CGameBoard::BltBoardToInk(CGameBoard* self, struct tagRECT* a1, int a2) {
    (void)self; (void)a1; (void)a2;
}

// ============================================================================
// CGameManager static method stubs
// ============================================================================
void CGameManager::DropWallTile(CGameManager* self, void* p1, void* p2) {
    (void)self; (void)p1; (void)p2;
}
void CGameManager::LoadBoard(CGameManager* self, void* data, int size) {
    (void)self; (void)data; (void)size;
}

// ============================================================================
// CInk static method stubs
// ============================================================================
void CInk::ClearInk(CInk* self) {
    (void)self;
}
void CInk::OnDisplayChange(CInk* self) {
    (void)self;
}
void CInk::Cleanup(CInk* self) {
    (void)self;
}
// [TODOne] CInk::CInk
// [TODOne] CInk::~CInk
int CBoardManager::LoadBoardFromResources(CBoardManager* manager, const wchar_t* name, void* boardData, int* boardSize) {
    (void)manager; (void)name; (void)boardData; (void)boardSize;
    return 0;
}
int CBoardManager::LoadRandomBoardFromResources(CBoardManager* manager, void* boardData, int* boardSize) {
    (void)manager; (void)boardData; (void)boardSize;
    return 0;
}
void CBoardManager::SetDifficulty(CBoardManager* manager, uint32_t difficulty) {
    (void)manager; (void)difficulty;
}

// ============================================================================
// CGameManager standalone function stubs
// ============================================================================
extern "C" {
    void* CGameManager_ctor(void* self, HWND hWnd) {
        (void)self; (void)hWnd;
        return self;
    }
    void CGameManager_dtor(void* self) {
        (void)self;
    }
    int CGameManager_Init(void* self) {
        (void)self;
        return 0;
    }
    void CGameManager_LoadBoard(void* self, void* boardData, int boardSize) {
        (void)self; (void)boardData; (void)boardSize;
    }
    void CGameManager_PerformGameUpdate(void* self) {
        (void)self;
    }
}

// ============================================================================
// CTimeManager static method stubs
// ============================================================================
// [TODOne] GetTime
// [TODOne] SetTime
// [TODOne] InitTime

// ============================================================================
// CScoreManager static method stubs
// ============================================================================
// [TODOne] IncrementScore
// [TODOne] GetScore
// [TODOne] ResetScore
// [TODOne] CScoreManager::CScoreManager
// [TODOne] CScoreManager::~CScoreManager

// ============================================================================
// CTileManager static method stubs
// ============================================================================
// [TODOne] SetTiles
// [TODOne] ResetTileCount
// [TODOne] GetTileCount

// ============================================================================
// CUIBarObject static method stubs
// ============================================================================
void CUIBarObject::GetBoundingRect(void* self, RECT* out) {
    (void)self; (void)out;
}

// ============================================================================
// CBoardObject static method stubs
// ============================================================================
void CBoardObject::GetBoundingRect(uint32_t self, RECT* out) {
    (void)self; (void)out;
}
// [TODOne] CBoardObject::CBoardObject

// ============================================================================
// CMovingObject constructor stub
// ============================================================================
// [TODOne] CMovingObject::CMovingObject

// ============================================================================
// CDisplay static method stubs
// ============================================================================
void CDisplay::Blt(void* self, int x, int y, void* surface, RECT* src) {
    (void)self; (void)x; (void)y; (void)surface; (void)src;
}
int CDisplay::Present(void* self, RECT* rect) {
    (void)self; (void)rect;
    return 0;
}
void CDisplay::BltInk(void* self, RECT* rect) {
    (void)self; (void)rect;
}
int CDisplay::DestroyObjects(CDisplay* self) {
    (void)self;
    return 0;
}
// [TODOne] CDisplay::CDisplay
// [TODOne] CDisplay::~CDisplay

CGameBoard* CGameBoard_Ctor(CGameBoard* self, HWND hWnd, void* param) {
    (void)self; (void)hWnd; (void)param;
    return self;
}

void CGameBoard_Dtor(CGameBoard* self, int flags) {
    (void)self; (void)flags;
}

int CGameBoard_Init(CGameBoard* self) {
    (void)self;
    return 0;
}

void CGameManager::UpdateTime(CGameManager* self) {
    (void)self;
}

// ============================================================================
// CRegistryManager member stubs
// ============================================================================
uint32_t CRegistryManager::ReadDifficulty(CRegistryManager* self) {
    (void)self;
    return 0;
}
void CRegistryManager::WriteDifficulty(CRegistryManager* self, uint32_t difficulty) {
    (void)self; (void)difficulty;
}
uint32_t CRegistryManager::ReadHiScore(CRegistryManager* self) {
    (void)self;
    return 0;
}
void CRegistryManager::WriteHiScore(CRegistryManager* self, int score) {
    (void)self; (void)score;
}

// ============================================================================
// TabUtils stubs
// ============================================================================
namespace TabUtils {
    uint32_t __stdcall GenerateLastErrorHR(uint32_t fallback, int unused) {
        (void)unused;
        return fallback;
    }
}

// ============================================================================
// Helper implementations
// ============================================================================
namespace Helpers {
    void UpdateWindow(HWND hWnd, int unused, int* param) {
        (void)unused; (void)param;
        ::UpdateWindow(hWnd);
    }

    void CloseHandle(HANDLE h, int unused, int* param) {
        (void)unused; (void)param;
        ::CloseHandle(h);
    }

    void LoadStringW(HINSTANCE h1, HINSTANCE h2, WCHAR* buf, uint16_t* p, int unused, int* out) {
        (void)h1; (void)h2; (void)buf; (void)p; (void)unused; (void)out;
    }

    HICON LoadIconW(HINSTANCE h1, HINSTANCE h2, int unused, int* out) {
        (void)h1; (void)h2; (void)unused; (void)out;
        return nullptr;
    }

    void PostMessageW(HWND h1, HWND h2, int msg, int p1, int p2, int* out) {
        (void)h1; (void)h2; (void)msg; (void)p1; (void)p2; (void)out;
    }
}

// ============================================================================
// WPP / ETW externs
// ============================================================================
uint64_t WPP_GLOBAL_Control = 0;
const GUID* WPP_REGISTRATION_GUIDS = nullptr;
WppControl WPP_MAIN_CB = {};
const GUID* WPP_ThisDir_CTLGUID_ControlGuid = nullptr;
const GUID* WPP_ThisDir_CTLGUID_MobTabPerfTraceProvider = nullptr;
const GUID stru_10036F8 = {};
const GUID stru_1003520 = {};
uint32_t unk_10B26E0 = 0;
const wchar_t* stru_1002CD8 = L"";
const wchar_t* SubKey = L"";
const wchar_t* ValueName = L"";

// ============================================================================
// CBallManager static method stubs
// ============================================================================
int CBallManager::InitSurface(CBallManager* self) {
    (void)self;
    return 0;
}
// [TODOne] CBallManager::CBallManager
// [TODOne] CBallManager::~CBallManager

// ============================================================================
// CBoardManager constructor/destructor and additional method stubs
// ============================================================================
// [TODOne] CBoardManager::CBoardManager
// [TODOne] CBoardManager::~CBoardManager
void* CBoardManager::GetLastLoadedBoardData(CBoardManager* self) {
    (void)self;
    return nullptr;
}
int CBoardManager::LoadRandomBonusBoardFromResources(CBoardManager* self, void* boardData, int* boardSize) {
    (void)self; (void)boardData; (void)boardSize;
    return 0;
}

// ============================================================================
// CSurface static method stubs
// ============================================================================
// [TODOne] IsColorKeyed
// [TODOne] GetDDrawSurface
// [TODOne] CSurface::CSurface
// [TODOne] CSurface::~CSurface

// ============================================================================
// CBitmapRects static method stubs
// ============================================================================
char* CBitmapRects::GetBitmapRect(CBitmapRects* self, int id) {
    (void)self; (void)id;
    return nullptr;
}

// ============================================================================
// CBoardTileRLColored static method stubs
// ============================================================================
// [TODOne] ToggleState — now provided by _ToggleState_CBoardTileRLColored_QAEXXZ.cpp

// ============================================================================
// BallPoints constructor/destructor stubs
// ============================================================================
// [TODOne] BallPoints::BallPoints
// [TODOne] BallPoints::~BallPoints

// ============================================================================
// CBoardTile constructor stubs
// ============================================================================
// [TODOne] CBoardTile::CBoardTile
// [TODOne] CBoardTile::CBoardTile

// ============================================================================
// CBoardTile vftable extern
// ============================================================================
extern "C" {
    void* CBoardTile_vftable = nullptr;
}

// ============================================================================
// Win32 globals
// ============================================================================
wchar_t g_szAppName[256] = L"InkBall";
LRESULT __stdcall MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    return DefWindowProcW(hWnd, msg, wParam, lParam);
}

// ============================================================================
// CRT externs
// ============================================================================
extern "C" {
    int _newmode = 0;
    int _dowildcard = 0;
    int unk_10D2F20 = 0;
    int unk_10D2F28 = 0;
    int unk_10D2F24 = 0;
}

// ============================================================================
// ETW stubs
// ============================================================================
ULONG __stdcall RegisterTraceGuidsW(WMIDPREQUEST callback, void* context, const GUID* guid, ULONG count, TRACE_GUID_REGISTRATION* reg, ...) {
    (void)callback; (void)context; (void)guid; (void)count; (void)reg;
    return 0;
}

// ============================================================================
// Registry helper stubs
// ============================================================================
int __cdecl CreateInkballKey() { return 0; }

// ============================================================================
// WinSQM stubs (never called - WinSqmIsOptedIn returns 0)
// ============================================================================
// [TODO] Minimal EVENT_DESCRIPTOR - verify layout
struct EVENT_DESCRIPTOR {
    unsigned short Id;
    unsigned char  Version;
    unsigned char  Channel;
    unsigned char  Level;
    unsigned char  Opcode;
    unsigned short Task;
    unsigned long long Keyword;
};

extern "C" {
    BOOL __stdcall WinSqmEventEnabled(const EVENT_DESCRIPTOR* event_desc, const GUID* guid) {
        (void)event_desc; (void)guid;
        return FALSE;
    }
    HRESULT __stdcall WinSqmEventWrite(const EVENT_DESCRIPTOR* event_desc, unsigned short dataCount, uint64_t* data) {
        (void)event_desc; (void)dataCount; (void)data;
        return E_NOTIMPL;
    }
    GUID unk_105C840 = {};
}

// ============================================================================
// CRT helper stubs
// ============================================================================
extern "C" int __cdecl ___wgetmainargs(int* argc, int* argv, int* envp, int dowildcard, int* newmode) {
    (void)dowildcard;
    *argc = 1;
    *argv = 0;
    *envp = 0;
    *newmode = 0;
    return 0;
}

// ============================================================================
// Additional stubs for unblocked files
// ============================================================================
int CScoreManager::InitSurface(CScoreManager* self) { (void)self; return 0; }
int CTileManager::InitSurface(CTileManager* self) { (void)self; return 0; }
int CTimeManager::InitSurface(CTimeManager* self) { (void)self; return 0; }
void CSurface::Clear(CSurface* self, uint32_t color) { (void)self; (void)color; }

extern "C" void* CBall_func(int a1, int a2, int a3, int a4, int a5) { (void)a1; (void)a2; (void)a3; (void)a4; (void)a5; return nullptr; }
