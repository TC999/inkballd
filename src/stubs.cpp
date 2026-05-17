// stubs.cpp - Global variables and unique stub implementations
// All duplicate definitions with .cpp files have been removed.

#include "global_types.h"
#include <cstdint>
#include <windows.h>

// ============================================================================
// Global variable definitions
// ============================================================================
extern "C" {
    void* g_pCGameManager = nullptr;
    void* g_CBoardManager = nullptr;
    void* g_CRegistryManager = nullptr;
    CGameBoard* g_pCGameBoard;
    void* SQM_INCREMENT_DWORD = nullptr;
    void* BoardData = nullptr;
    int iBoardSizeBytes = 0;
    void* g_pDisplay = nullptr;
    void* g_pGamePiecesSurface = nullptr;
    HINSTANCE g_hInst = nullptr;
    uint32_t dword_10B2704 = 0;
    uint32_t dword_10D2F34 = 0;
    uint32_t dword_10D2F30 = 0;
    uint32_t dword_10B0640 = 0;
    uintptr_t dword_10B062C = 0;
    uintptr_t dword_10B0618 = 0;
    uint32_t dword_10B0600 = 0;
    uint32_t dword_10B0604 = 0;
    RECT stru_10B0630 = {};
    RECT stru_10B061C = {};
    RECT stru_10B0608 = {};
    void* g_pTimeManagerSurface = nullptr;
    void* g_pScoreManagerSurface = nullptr;
    void* g_pTileManagerSurface = nullptr;
    void* g_pBallManagerSurface = nullptr;
    int g_fMouseInside = 0;
    int iLastChecked = 0;
    int g_fLastPauseFromMenu = 0;
    RECT Rect = {};
    const GUID _GUID_8cec58e7_07a1_11d9_b15e_000d56bfe6ee = {};
    const GUID _GUID_8cec5884_07a1_11d9_b15e_000d56bfe6ee = {};
    uint32_t dword_10B0664 = 0;
    uint32_t dword_10B0668 = 0;
    uint32_t dword_10B0674 = 0;
    uint32_t dword_10B0678 = 0;
    uint32_t dword_10B0670 = 0;
    IInkObject* g_pIInkObject = nullptr;
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
    void* CBoardTile_vftable = nullptr;
    int _newmode = 0;
    int _dowildcard = 0;
    int unk_10D2F20 = 0;
    int unk_10D2F28 = 0;
    int unk_10D2F24 = 0;
    GUID unk_105C840 = {};
}

RECT g_rcClient = {};
RECT g_rcTabletInInk = {};
const GUID IID_ITabletEventSink = {};
const GUID IID_IUnknown = {};
void* CSink_vftable = nullptr;
uint32_t dwTimeDigitWidth = 0;
uint32_t dwTopDrawLoc = 0;
uint32_t dwLeftDrawDif = 0;
uint32_t g_tcid = 0;
uint32_t g_cid = 0;
wchar_t g_szAppName[256] = L"InkBall";

// WPP / ETW globals
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

// Board count globals
int iBoardListCount = 0;
int iBonusBoardListCount = 0;
void* paBoardList = nullptr;
void* paBonusBoardList = nullptr;
int iBeginnerBoardsCount = 0, iBeginnerBonusBoardsCount = 0;
void* g_aBeginnerBoards = nullptr;
void* g_aBeginnerBonusBoards = nullptr;
int iNoviceBoardsCount = 0, iNoviceBonusBoardsCount = 0;
void* g_aNoviceBoards = nullptr;
void* g_aNoviceBonusBoards = nullptr;
int iIntermediateBoardsCount = 0, iIntermediateBonusBoardsCount = 0;
void* g_aIntermediateBoards = nullptr;
void* g_aIntermediateBonusBoards = nullptr;
int iAdvancedBoardsCount = 0, iAdvancedBonusBoardsCount = 0;
void* g_aAdvancedBoards = nullptr;
void* g_aAdvancedBonusBoards = nullptr;
int iExpertBoardsCount = 0, iExpertBonusBoardsCount = 0;
void* g_aExpertBoards = nullptr;
void* g_aExpertBonusBoards = nullptr;

// ============================================================================
// extern "C" function stubs (unique to self file)
// ============================================================================
extern "C" {
    int __stdcall WinSqmIsOptedIn() { return 0; }
    int __stdcall EnableClassicWispWithPtr(LPVOID* ppv) { (void)ppv; return 0; }
    void* __cdecl new_oom_handler(unsigned int size) { (void)size; return nullptr; }
    void __stdcall ExitBadCommandLine(HWND hWnd) { (void)hWnd; }
    void __stdcall SetMenuChecks(HWND hWnd) { (void)hWnd; }
    DWORD __stdcall timeGetTime() { return 0; }
    void* CBall_func(int a1, int a2, int a3, int a4, int a5) { (void)a1; (void)a2; (void)a3; (void)a4; (void)a5; return nullptr; }
}

// ============================================================================
// Static member stubs (unique to self file, not in .cpp files)
// ============================================================================
void CUIBarObject::GetBoundingRect(void* self, RECT* out) { (void)self; (void)out; }
void CBoardObject::GetBoundingRect(void* self, RECT* out) { (void)self; (void)out; }
void CMovingObject::PrepareToMove(CMovingObject* self) { (void)self; }

int CDisplay::Blt(void* self, int x, int y, void* surface, RECT* src, uint32_t colorkey) {
    (void)self; (void)x; (void)y; (void)surface; (void)src; (void)colorkey; return 0;
}
int CDisplay::Present(void* self, RECT* rect) { (void)self; (void)rect; return 0; }
int CDisplay::BltInk(void* self, RECT* rect) { (void)self; (void)rect; return 0; }
int CDisplay::ConvertGDIColor(void* self, uint32_t color) { (void)self; (void)color; return 0; }
void* CDisplay::GetDirectDraw(void* self) { (void)self; return nullptr; }
void CDisplay::Clear(void* self, uint32_t color) { (void)self; (void)color; }
void CDisplay::ClearInk(void* self, RECT* rect, int color) { (void)self; (void)rect; (void)color; }

// CBoardManager member functions implemented in separate .cpp files

// CBoardTile constructors
CBoardTile::CBoardTile() {}
CBoardTile::CBoardTile(int tile_type, int x, int y, int rect_param) { (void)tile_type; (void)x; (void)y; (void)rect_param; }
CBoardTileDrain::CBoardTileDrain(int tile_type, int x, int y, int rect_param, int color) { (void)tile_type; (void)x; (void)y; (void)rect_param; (void)color; }
CBoardTileWall::CBoardTileWall(int x, int y, int rect_param, int color) { (void)x; (void)y; (void)rect_param; (void)color; }
CBoardTileBreakWall::CBoardTileBreakWall(int x, int y, int rect_param, int color) { (void)x; (void)y; (void)rect_param; (void)color; }
CBoardTileOWF::CBoardTileOWF(int x, int y, int rect_param, int color, int direction) { (void)x; (void)y; (void)rect_param; (void)color; (void)direction; }
CBoardTileRLGray::CBoardTileRLGray(int x, int y, int rect_param, int color, int tile_sub_type, int min_ms, int max_ms) { (void)x; (void)y; (void)rect_param; (void)color; (void)tile_sub_type; (void)min_ms; (void)max_ms; }
CBoardTileRLColored::CBoardTileRLColored(int x, int y, int rect_param, int color, int tile_sub_type) { (void)x; (void)y; (void)rect_param; (void)color; (void)tile_sub_type; }
CBoardTileChevron::CBoardTileChevron(int x, int y, int rect_param, int direction) { (void)x; (void)y; (void)rect_param; (void)direction; }
CBoardTileBumper::CBoardTileBumper(int x, int y, int rect_param, int color, int direction) { (void)x; (void)y; (void)rect_param; (void)color; (void)direction; }

// BallPoints
BallPoints::BallPoints(int count, int flags) { (void)count; (void)flags; }
// void BallPoints::scalar_deleting_destructor(BallPoints* self, int flags) { (void)self; (void)flags; }

// CGameBoard standalone helpers
// DECOMPILE TODO: now implemented in CGameBoard_CGameBoard.cpp / CGameBoard_~CGameBoard.cpp
// CGameBoard* CGameBoard_Ctor(CGameBoard* self, HWND hWnd, void* param) { (void)self; (void)hWnd; (void)param; return self; }
// void CGameBoard_Dtor(CGameBoard* self, int flags) { (void)self; (void)flags; }
int CGameBoard_Init(CGameBoard* self) { (void)self; return 0; }

// CGameManager standalone stubs
extern "C" {
    void* CGameManager_ctor(void* self, HWND hWnd) { (void)self; (void)hWnd; return self; }
    void CGameManager_dtor(void* self) { (void)self; }
    int CGameManager_Init(void* self) { (void)self; return 0; }
    void CGameManager_LoadBoard(void* self, void* boardData, int boardSize) { (void)self; (void)boardData; (void)boardSize; }
    void CGameManager_PerformGameUpdate(void* self) { (void)self; }
}

// CRegistryManager member stubs
uint32_t ReadDifficulty_CRegistryManager(CRegistryManager* self) { (void)self; return 0; }
void WriteDifficulty_CRegistryManager(CRegistryManager* self, uint32_t d) { (void)self; (void)d; }
uint32_t ReadHiScore_CRegistryManager(CRegistryManager* self) { (void)self; return 0; }
void WriteHiScore_CRegistryManager(CRegistryManager* self, int s) { (void)self; (void)s; }

// TabUtils
namespace TabUtils {
    uint32_t __stdcall GenerateLastErrorHR(uint32_t fallback, int unused) { (void)unused; return fallback; }
}

// Helpers namespace
namespace Helpers {
    void UpdateWindow(HWND hWnd, int unused, int* param) { (void)unused; (void)param; ::UpdateWindow(hWnd); }
    void CloseHandle(HANDLE h, int unused, int* param) { (void)unused; (void)param; ::CloseHandle(h); }
    void LoadStringW(HINSTANCE h1, HINSTANCE h2, WCHAR* buf, uint16_t* p, int unused, int* out) {
        (void)h1; (void)h2; (void)buf; (void)p; (void)unused; (void)out;
    }
    HICON LoadIconW(HINSTANCE h1, HINSTANCE h2, int unused, int* out) { (void)h1; (void)h2; (void)unused; (void)out; return nullptr; }
    void PostMessageW(HWND h1, HWND h2, int msg, int p1, int p2, int* out) { (void)h1; (void)h2; (void)msg; (void)p1; (void)p2; (void)out; }
    int __stdcall GetObjectW_wpp(HGDIOBJ h, int c, LPVOID pv, int unused, int* out) {
        (void)unused; (void)out; return ::GetObjectW(h, c, pv);
    }
}

// ETW stubs
ULONG __stdcall RegisterTraceGuidsW(WMIDPREQUEST callback, void* context, const GUID* guid, ULONG count, TRACE_GUID_REGISTRATION* reg, ...) {
    (void)callback; (void)context; (void)guid; (void)count; (void)reg; return 0;
}

// WinSQM stubs
struct EVENT_DESCRIPTOR {
    unsigned short Id; unsigned char Version; unsigned char Channel;
    unsigned char Level; unsigned char Opcode; unsigned short Task; unsigned long long Keyword;
};
extern "C" {
    BOOL __stdcall WinSqmEventEnabled(const EVENT_DESCRIPTOR* e, const GUID* g) { (void)e; (void)g; return FALSE; }
    HRESULT __stdcall WinSqmEventWrite(const EVENT_DESCRIPTOR* e, unsigned short c, uint64_t* d) { (void)e; (void)c; (void)d; return E_NOTIMPL; }
}

// CRT helper stubs
extern "C" int __cdecl ___wgetmainargs(int* argc, int* argv, int* envp, int dowildcard, int* newmode) {
    (void)dowildcard; *argc = 1; *argv = 0; *envp = 0; *newmode = 0; return 0;
}

// MainWndProc
LRESULT __stdcall MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    return DefWindowProcW(hWnd, msg, wParam, lParam);
}

// extern "C" CleanupTabletContexts (different from C++ version in link_stubs.cpp)
extern "C" void CleanupTabletContexts() {}

// extern "C" cdecl PerformStandardWallDeflection (different from stdcall version in link_stubs.cpp)
extern "C" void PerformStandardWallDeflection(void* tile, void* ball) { (void)tile; (void)ball; }

// Helpers::CLogBlock
namespace Helpers {
    CLogBlock::CLogBlock(void* self, const char* name, int line) : line(line), name(name) { (void)self; }
    CLogBlock::CLogBlock(void* self, const char* name, int* context) : line(0), name(name) { (void)self; (void)context; }
    CLogBlock::~CLogBlock() {}
}
