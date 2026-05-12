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

    // Global handles
    HINSTANCE g_hInst = nullptr;

    // Global DWORD variables
    uint32_t dword_10B2704 = 0;
    uint32_t dword_10D2F34 = 0;
    uint32_t dword_10D2F30 = 0;
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

CGameBoard* CGameBoard_Ctor(CGameBoard* self, HWND hWnd, void* param) {
    (void)self; (void)hWnd; (void)param;
    return self;
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
// Helper implementations
// ============================================================================
namespace Helpers {
    CLogBlock::CLogBlock(void* p, const char* name, int line) {
        (void)p; (void)name; (void)line;
    }

    CLogBlock::~CLogBlock() {
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
