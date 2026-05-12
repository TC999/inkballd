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

    // Menu / UI state globals
    int g_fMouseInside = 0;
    int iLastChecked = 0;
    int g_fLastPauseFromMenu = 0;
    RECT Rect = {};

    // GUIDs
    const GUID _GUID_8cec58e7_07a1_11d9_b15e_000d56bfe6ee = {};
    const GUID _GUID_8cec5884_07a1_11d9_b15e_000d56bfe6ee = {};
}

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
    void __stdcall KillPlayer(int a1) { (void)a1; }
    void __stdcall LoadNextLevel() { }
    char* __stdcall GetBitmapRect(int a1) { (void)a1; return nullptr; }
    DWORD __stdcall timeGetTime() { return 0; }
}

// ============================================================================
// CGameBoard static method stubs
// ============================================================================
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
uint32_t CTimeManager::GetTime(void* self) {
    (void)self;
    return 0;
}
void CTimeManager::SetTime(void* self, uint32_t time) {
    (void)self; (void)time;
}

// ============================================================================
// CScoreManager static method stubs
// ============================================================================
void CScoreManager::IncrementScore(void* self, uint32_t count) {
    (void)self; (void)count;
}
uint32_t CScoreManager::GetScore(void* self) {
    (void)self;
    return 0;
}

// ============================================================================
// CTileManager static method stubs
// ============================================================================
void CTileManager::SetTiles(void* self, uint32_t score) {
    (void)self; (void)score;
}

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
