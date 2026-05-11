// stubs.cpp - Stub implementations for missing symbols
// This file provides definitions for extern symbols referenced in the codebase

#include "global_types.h"
#include <cstdint>
#include <windows.h>

// ============================================================================
// Global variable definitions
// ============================================================================
extern "C" {
    // Game object pointers
    void* g_pCGameBoard = nullptr;
    void* g_pDisplay = nullptr;
    void* g_pGamePiecesSurface = nullptr;
    void* g_pIInkObject = nullptr;
    void* g_CBitmapRects = nullptr;
    void* g_pCGameManager = nullptr;
    void* g_pTimeManagerSurface = nullptr;
    void* g_pScoreManagerSurface = nullptr;
    void* g_pBallManagerSurface = nullptr;
    void* g_pIInkCollect = nullptr;
    void* g_CBoardManager = nullptr;
    void* g_pIRenderingContext = nullptr;
    void* g_pTileManagerSurface = nullptr;
    void* g_pIInkManager = nullptr;
    void* g_pIStroke = nullptr;
    void* g_pTabletManager = nullptr;
    void* g_pIRenderInk = nullptr;
    void* g_BoardData = nullptr;
    void* BoardData = nullptr;
    void* SQM_INCREMENT_DWORD = nullptr;
    int iBoardSizeBytes = 0;
    void* g_pLastLoadedLevel = nullptr;
    void* g_CRegistryManager = nullptr;
    void* g_ptr = nullptr;
    
    // Global handles
    HWND g_hWnd = nullptr;
    HINSTANCE g_hInst = nullptr;
    HINSTANCE g_hInstance = nullptr;
    RECT g_rcClient = {0};
    
    // Global DWORD variables
    uint32_t dword_10B062C = 0;
    uint32_t dword_10B0618 = 0;
    uint32_t dword_10B0600 = 0;
    uint32_t dword_10B068C = 0;
    uint32_t dword_10B0604 = 0;
    uint32_t dword_105C81C = 0;
    uint32_t dword_10D2F34 = 0;
    uint32_t dword_10B0640 = 0;
    uint32_t dword_10D2F30 = 0;
    uint32_t dword_105C760 = 0;
    uint32_t dword_10B2704 = 0;
    uint32_t dword_10B0678 = 0;
    uint32_t dword_10035B8 = 0;
    uint32_t dword_10AF594 = 0;
    uint32_t dword_10AF598 = 0;
    uint32_t dword_10AF59C = 0;
    uint32_t dword_10AF5A0 = 0;
    uint32_t dword_10AF5A4 = 0;
    uint32_t dword_10D2F1C = 0;
    uint32_t dword_10AF5A8 = 0;
    uint32_t dword_10AF5B0 = 0;
    uint32_t dword_10AF5B4 = 0;
    uint32_t dword_10B0664 = 0;
    uint32_t dword_10B0668 = 0;
    uint32_t dword_10B0670 = 0;
    uint32_t dword_10B0674 = 0;
    uint32_t dword_10AF5AC = 0;
    uint32_t dword_10029E0 = 0;
    
    // Double size factor
    double dSizeFactor = 1.0;
}

// ============================================================================
// Virtual table placeholders (these are referenced but not defined)
// ============================================================================
extern "C" {
    void* CInk_vftable = nullptr;
    void* CBoardTile_vftable = nullptr;
    void* CBoardTileWall_vftable = nullptr;
    void* CBoardTileBreakWall_vftable = nullptr;
    void* CBoardTileBumper_vftable = nullptr;
    void* CBoardTileChevron_vftable = nullptr;
    void* CBoardTileDrain_vftable = nullptr;
    void* CBoardTileOWF_vftable = nullptr;
    void* CBoardTileRLColored_vftable = nullptr;
    void* CBoardTileRLGray_vftable = nullptr;
    void* CBoardObject_vftable = nullptr;
    void* CDisplay_vftable = nullptr;
    void* CSurface_vftable = nullptr;
    void* CBall_vftable = nullptr;
    void* CBallManager_vftable = nullptr;
    void* CGameBoard_vftable = nullptr;
    void* CGameManager_vftable = nullptr;
    void* CScoreManager_vftable = nullptr;
    void* CTileManager_vftable = nullptr;
    void* CTimeManager_vftable = nullptr;
    void* CInk_vftable_ptr = nullptr;
    void* CSink_vftable = nullptr;
    void* CGameObject_vftable = nullptr;
    void* CMovingObject_vftable = nullptr;
    void* CBitmapRects_vftable = nullptr;
    void* CBoardManager_vftable = nullptr;
}

// ============================================================================
// Stub implementations for sub_xxx functions
// These are auto-generated stubs - real implementations should be added
// ============================================================================
extern "C" {
    // Math utility stubs
    long double __cdecl cosd(double degrees) { return 0.0; }
    long double __cdecl sind(double degrees) { return 0.0; }
    
    // Helper function stubs
    int __cdecl AddBallToUpdateList(CBall* ball) { return 0; }
    int __cdecl AddGameObjectToUpdateList(void* game_object) { return 0; }
    int __cdecl AddRLColoredWallToList(void* wall_tile) { return 0; }
    
    // System function stubs
    // _CxxThrowException is provided by the compiler - cannot be redefined with extern "C"
    int __cdecl _time(int* timer) { return 0; }
    void __cdecl _srand(unsigned int seed) { }
    
    // Sub function stubs (only most commonly referenced ones)
    int __cdecl sub_4098B0(int a1) { return 0; }
    int __cdecl sub_40B520(int a1) { return 0; }
    int __cdecl sub_416510(int a1) { return 0; }
    int __cdecl sub_417990(int a1) { return 0; }
    int __cdecl sub_417A50(int a1) { return 0; }
    int __cdecl sub_425220(int a1, int a2) { return 0; }
    int __cdecl sub_425570(int a1) { return 0; }
    int __cdecl sub_425610(int a1) { return 0; }
    int __cdecl sub_425730(int a1) { return 0; }
    int __cdecl sub_425780(int a1) { return 0; }
    int __cdecl sub_425990(int a1) { return 0; }
    int __cdecl sub_425A10(int a1) { return 0; }
    int __cdecl sub_426000(int a1) { return 0; }
    int __cdecl sub_426070(int a1) { return 0; }
    int __cdecl sub_426180(int a1) { return 0; }
    int __cdecl sub_426360(int a1) { return 0; }
    int __cdecl sub_426420(int a1) { return 0; }
    int __cdecl sub_426510(int a1) { return 0; }
    int __cdecl sub_426650(int a1, int a2, int a3) { return 0; }
    int __cdecl sub_426760(int a1) { return 0; }
    int __cdecl sub_426820(int a1) { return 0; }
    int __cdecl sub_4268E0(int a1) { return 0; }
    int __cdecl sub_4269A0(int a1) { return 0; }
    int __cdecl sub_426B70(int a1) { return 0; }
    int __cdecl sub_426D50(int a1) { return 0; }
    int __cdecl sub_426E00(int a1) { return 0; }
    int __cdecl sub_426F00(int a1) { return 0; }
    int __cdecl sub_427020(int a1) { return 0; }
    int __cdecl sub_427130(int a1) { return 0; }
    int __cdecl sub_4271F0(int a1) { return 0; }
    int __cdecl sub_427320(int a1) { return 0; }
    int __cdecl sub_427430(int a1) { return 0; }
    int __cdecl sub_427A10(int a1) { return 0; }
    int __cdecl sub_427B80(int a1) { return 0; }
    int __cdecl sub_427D20(int a1) { return 0; }
    int __cdecl sub_427DC0(int a1) { return 0; }
    int __cdecl sub_427ED0(int a1) { return 0; }
    int __cdecl sub_427F70(int a1) { return 0; }
    int __cdecl sub_428000(int a1) { return 0; }
    int __cdecl sub_428180(int a1) { return 0; }
    int __cdecl sub_428230(int a1) { return 0; }
    int __cdecl sub_4282D0(int a1) { return 0; }
    int __cdecl sub_4284B0(int a1) { return 0; }
    int __cdecl sub_4285D0(int a1) { return 0; }
    int __cdecl sub_4286E0(int a1) { return 0; }
    int __cdecl sub_428800(int a1) { return 0; }
    int __cdecl sub_428880(int a1) { return 0; }
    int __cdecl sub_428900(int a1) { return 0; }
    int __cdecl sub_428A20(int a1) { return 0; }
    int __cdecl sub_428B00(int a1) { return 0; }
    int __cdecl sub_428C20(int a1) { return 0; }
    int __cdecl sub_428D10(int a1) { return 0; }
    int __cdecl sub_428E00(int a1) { return 0; }
    int __cdecl sub_428F00(int a1) { return 0; }
    int __cdecl sub_429020(int a1) { return 0; }
    int __cdecl sub_429180(int a1) { return 0; }
    int __cdecl sub_429320(int a1) { return 0; }
    int __cdecl sub_429410(int a1) { return 0; }
    int __cdecl sub_429540(int a1) { return 0; }
    int __cdecl sub_429580(int a1) { return 0; }
    int __cdecl sub_4295F0(int a1) { return 0; }
    int __cdecl sub_4296A0(int a1) { return 0; }
    int __cdecl sub_429780(int a1) { return 0; }
    int __cdecl sub_429840(int a1, int a2, int a3) { return 0; }
    int __cdecl sub_4298E0(int a1) { return 0; }
    int __cdecl sub_429900(int a1, int a2) { return 0; }
    int __cdecl sub_4299A0(int a1) { return 0; }
    int __cdecl sub_429A40(int a1) { return 0; }
    int __cdecl sub_429A70(int a1) { return 0; }
    int __cdecl sub_429B10(int a1) { return 0; }
    int __cdecl sub_429B40(int a1) { return 0; }
    int __cdecl sub_429C50(int a1) { return 0; }
    int __cdecl sub_429D80(int a1) { return 0; }
    int __cdecl sub_429E50(int a1) { return 0; }
    int __cdecl sub_429F50(int a1) { return 0; }
    int __cdecl sub_42A080(int a1) { return 0; }
    int __cdecl sub_42A140(int a1) { return 0; }
    int __cdecl sub_42A200(int a1) { return 0; }
    int __cdecl sub_42A260(int a1) { return 0; }
    int __cdecl sub_42A340(int a1) { return 0; }
    int __cdecl sub_42A3A0(int a1) { return 0; }
    int __cdecl sub_42A410(int a1) { return 0; }
    int __cdecl sub_42A470(int a1) { return 0; }
    int __cdecl sub_42A520(int a1) { return 0; }
    int __cdecl sub_42A600(int a1) { return 0; }
    int __cdecl sub_42A6A0(int a1) { return 0; }
    int __cdecl sub_42A720(int a1) { return 0; }
    int __cdecl sub_42A7A0(int a1) { return 0; }
    int __cdecl sub_42A860(int a1) { return 0; }
    int __cdecl sub_42A8F0(int a1) { return 0; }
    int __cdecl sub_42A990(int a1) { return 0; }
    int __cdecl sub_42AA10(int a1) { return 0; }
    int __cdecl sub_42AA90(int a1) { return 0; }
    int __cdecl sub_42AB70(int a1) { return 0; }
    int __cdecl sub_42AC30(int a1) { return 0; }
    int __cdecl sub_42AD10(int a1) { return 0; }
    int __cdecl sub_42ADD0(int a1) { return 0; }
    int __cdecl sub_42AE50(int a1) { return 0; }
    int __cdecl sub_42AF50(int a1) { return 0; }
    int __cdecl sub_42AFE0(int a1) { return 0; }
}

// ============================================================================
// Missing function stubs (from ifdef'd-out _*.cpp files)
// ============================================================================
extern "C" {
    int __stdcall CanRunInkball(int* a1) { (void)a1; return 1; }
    void __stdcall DispError(HWND hWnd, HINSTANCE uID, HINSTANCE a3) { (void)hWnd; (void)uID; (void)a3; }
    int __stdcall WinSqmIsOptedIn() { return 0; }
    int __stdcall EnableClassicWispWithPtr(LPVOID* ppv) { (void)ppv; return 0; }
    void* __cdecl new_oom_handler(unsigned int size) { (void)size; return 0; }
    void __stdcall ExitBadCommandLine(HWND hWnd) { (void)hWnd; }
    void __stdcall SetMenuChecks(HWND hWnd) { (void)hWnd; }
}

// ============================================================================
// CBoardManager static method stubs
// ============================================================================
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
// CGameManager standalone functions (replacing invalid static ctor/dtor)
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
// CRegistryManager member stubs
// ============================================================================
uint32_t CRegistryManager::ReadDifficulty(CRegistryManager* self) {
    (void)self;
    return 0;
}

// ============================================================================
// Helper implementations
// ============================================================================
namespace Helpers {
    CLogBlock::CLogBlock(void* p, const char* name, int line) {
        // Stub implementation
        (void)p; (void)name; (void)line;
    }
    
    CLogBlock::~CLogBlock() {
        // Stub implementation
    }

    void UpdateWindow(HWND hWnd, int unused, int* param) {
        (void)unused; (void)param;
        ::UpdateWindow(hWnd);
    }

    void CloseHandle(HANDLE h, int unused, int* param) {
        (void)unused; (void)param;
        ::CloseHandle(h);
    }
}

// ============================================================================
// Linker symbol stubs - extern variables and functions that need definitions
// ============================================================================

// WPP / ETW externs
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

// Win32 globals
wchar_t g_szAppName[256] = L"InkBall";
LRESULT __stdcall MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    return DefWindowProcW(hWnd, msg, wParam, lParam);
}

// CRT externs
extern "C" {
    int _newmode = 0;
    int _dowildcard = 0;
    int unk_10D2F20 = 0;
    int unk_10D2F28 = 0;
    int unk_10D2F24 = 0;
}

// ETW stubs
ULONG __stdcall RegisterTraceGuidsW(WMIDPREQUEST callback, void* context, const GUID* guid, ULONG count, TRACE_GUID_REGISTRATION* reg, ...) {
    return 0;
}

// Registry helper stubs
int __cdecl CreateInkballKey() { return 0; }

// CRT helper stubs
extern "C" int __cdecl ___wgetmainargs(int* argc, int* argv, int* envp, int dowildcard, int* newmode) {
    *argc = 1;
    *argv = 0;
    *envp = 0;
    *newmode = 0;
    return 0;
}
