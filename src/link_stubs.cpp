// link_stubs.cpp - Static member stubs and missing globals ONLY
// No standalone extern "C" wrappers (those are in .cpp files)

#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <windows.h>
#include <cmath>

// ============================================================================
// Missing global variables
// ============================================================================
extern "C" {
    RECT g_rcInkSpace = {};
    void* g_pLastLoadedLevel = nullptr;
    int BreakPoints[256] = {};
    int DrainPoints[256] = {};
    int iBoardCollectionsCount = 0;
    int iBoardCounts = 0;
    void* pBoardCollections = nullptr;
    BOARDHIST g_bhPrevBoards = {};
    BOARDHIST g_bhPrevBonusBoards = {};
    uint32_t dword_10B068C = 0;
    void* g_arrTCI = nullptr;
    int* dword_10029E0 = nullptr;
    const GUID stru_1002480 = {};
    uint32_t dword_105C760 = 0;
    uint32_t dword_10D2F1C = 0;
    uint32_t dword_105C81C = 0;
    uint32_t dword_10035B8 = 0;
    void* unk_10B06A4 = nullptr;
    void* g_pInkSurface = nullptr;
    double dSizeFactor = 1.0;
    HINSTANCE g_hInstance = nullptr;
    void* g_pIRenderingContext = nullptr;
    void* g_pIInkCollect = nullptr;
    void* g_pIInkManager = nullptr;
    void* g_pTabletManager = nullptr;
    void* g_pIRenderInk = nullptr;
    const GUID stru_1003974 = {};
    const GUID stru_1002FB8 = {};
    const GUID stru_10039F4 = {};
    int __onexitbegin = 0;
}

// C++ linkage globals
extern const GUID IID_IDirectDraw7 = { 0x15e65ec0, 0x3b9c, 0x11d2, { 0xb9, 0x2f, 0x00, 0x60, 0x97, 0x7b, 0xda, 0x75 } };
void* CBoardTileBreakWall_vftable = nullptr;
void* CBoardTileBumper_vftable = nullptr;
void* CBoardTileChevron_vftable = nullptr;
void* CBoardTileDrain_vftable = nullptr;
void* CBoardTileOWF_vftable = nullptr;
void* CBoardTileRLColored_vftable = nullptr;
void* CBoardTileRLGray_vftable = nullptr;
void* CBoardTileWall_vftable = nullptr;
void* CBall_vftable = nullptr;

// ============================================================================
// Missing constructors/destructors
// ============================================================================
BallPoints::BallPoints() : vftable(nullptr), data_array(nullptr) {}
CScoreManager::CScoreManager() : vftable(nullptr) {}
CTileManager::CTileManager() : vftable(nullptr) {}
CSurface::CSurface() : vftable(nullptr) {}

// ============================================================================
// Helpers:: namespace - WPP-wrapped Win32 API stubs
// ============================================================================
namespace Helpers {
    BOOL __stdcall DeleteDC(HDC hdc, HDC a2, int* a3) { (void)a2; (void)a3; return ::DeleteDC(hdc); }
    HDC __stdcall CreateCompatibleDC(HDC hdc, HDC a2, int* a3) { (void)a2; (void)a3; return ::CreateCompatibleDC(hdc); }
    HGDIOBJ __stdcall SelectObject(HDC hdc, HGDIOBJ h, uint32_t* a3, int* a4) { (void)a3; (void)a4; return ::SelectObject(hdc, h); }
    int __stdcall GetSystemMetrics(void* self, int* a2, int* a3) { (void)self; (void)a2; (void)a3; return ::GetSystemMetrics(0); }
    BOOL __stdcall GetClientRect(HWND hWnd, RECT* lpRect, RECT* a3, int* a4) { (void)a3; (void)a4; return ::GetClientRect(hWnd, lpRect); }
    BOOL __stdcall GetWindowRect(HWND hWnd, RECT* lpRect, RECT* a3, int* a4) { (void)a3; (void)a4; return ::GetWindowRect(hWnd, lpRect); }
    LSTATUS __stdcall RegOpenKeyExW(HKEY hKey, const WCHAR* lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult, HKEY* a6, int* a7) {
        (void)a6; (void)a7; return ::RegOpenKeyExW(hKey, lpSubKey, ulOptions, samDesired, phkResult);
    }
    LSTATUS __stdcall RegQueryValueExW(HKEY hKey, const WCHAR* lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData, uint32_t* a7, int* a8) {
        (void)a7; (void)a8; return ::RegQueryValueExW(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);
    }
    int __stdcall __wcsicmp(const wchar_t* a, const wchar_t* b) { return _wcsicmp(a, b); }
    void* __cdecl memcpy(void* dst, const void* src, size_t n) { return ::memcpy(dst, src, n); }
    void* __cdecl memset(void* dst, int val, size_t n) { return ::memset(dst, val, n); }
    BOOL __stdcall DeleteObject(HGDIOBJ ho, uint32_t* a2, int* a3) { (void)a2; (void)a3; return ::DeleteObject(ho); }
    HRSRC __stdcall FindResourceW(HMODULE hModule, const WCHAR* lpName, LPCWSTR lpType, uint16_t* a4, int* a5) { (void)a4; (void)a5; return ::FindResourceW(hModule, lpName, lpType); }
    HGLOBAL __stdcall LoadResource(HMODULE hModule, HRSRC hResInfo, HRSRC a3, int* a4) { (void)a3; (void)a4; return ::LoadResource(hModule, hResInfo); }
    BOOL __stdcall CloseHandle_wpp(HANDLE hObject, uint32_t* a2, int* a3) { (void)a2; (void)a3; return ::CloseHandle(hObject); }
    LSTATUS __stdcall RegCloseKey(HKEY hKey, HKEY a2, int* a3) { (void)a2; (void)a3; return ::RegCloseKey(hKey); }
    LSTATUS __stdcall RegCreateKeyExW(HKEY hKey, const WCHAR* lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSec, PHKEY phkResult, LPDWORD lpdwDisp, uint32_t* a10, int* a11) {
        (void)a10; (void)a11; return ::RegCreateKeyExW(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSec, phkResult, lpdwDisp);
    }
    LSTATUS __stdcall RegSetValueExW(HKEY hKey, const WCHAR* lpValueName, DWORD Reserved, DWORD dwType, BYTE* lpData, DWORD cbData, int* a7, int* a8) {
        (void)a7; (void)a8; return ::RegSetValueExW(hKey, lpValueName, Reserved, dwType, lpData, cbData);
    }
    int __stdcall LoadStringW_wpp(HINSTANCE hInstance, UINT uID, LPWSTR lpBuffer, uint16_t* cchBufferMax, uint32_t* a5, int* a6) {
        (void)a5; (void)a6; return ::LoadStringW(hInstance, uID, lpBuffer, *cchBufferMax);
    }
    BOOL __stdcall PostMessageW_wpp(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, uint32_t* a5, int* a6) {
        (void)a5; (void)a6; return ::PostMessageW(hWnd, Msg, wParam, lParam);
    }
    HICON __stdcall LoadCursorW(HINSTANCE hInstance, const WCHAR* lpCursorName, uint16_t* a3, int* a4) { (void)a3; (void)a4; return ::LoadCursorW(hInstance, lpCursorName); }
    HICON __stdcall LoadIconW_wpp(HINSTANCE hInstance, const WCHAR* lpIconName, uint16_t* a3, int* a4) { (void)a3; (void)a4; return ::LoadIconW(hInstance, lpIconName); }
    HANDLE __stdcall LoadImageW(HINSTANCE hInst, const WCHAR* name, UINT type, uint32_t a4, int cy, UINT fuLoad, uint32_t* a7, int* a8) {
        (void)a7; (void)a8; return ::LoadImageW(hInst, name, type, a4, cy, fuLoad);
    }
    BOOL __stdcall SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int x, int y, int width, int height, UINT flags, uint32_t* error_result, int* unused) {
        (void)error_result; (void)unused; return ::SetWindowPos(hWnd, hWndInsertAfter, x, y, width, height, flags);
    }
    BOOL __stdcall SystemParametersInfoW(UINT action, UINT param, void* value, UINT flags, uint32_t* error_result, int* unused) {
        (void)error_result; (void)unused; return ::SystemParametersInfoW(action, param, value, flags);
    }
    HWND __stdcall CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, uint32_t X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, HINSTANCE lpParam, uint32_t* a13, int* a14) {
        (void)a13; (void)a14; return ::CreateWindowExW(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
    }
}

// ============================================================================
// CBall static members
// ============================================================================
void CBall::SetTallness(CBall* self, int tallness) { (void)self; (void)tallness; }
void CBall::SetXVel(CBall* self, long double vel) { (void)self; (void)vel; }
void CBall::SetYVel(CBall* self, long double vel) { (void)self; (void)vel; }
int* CBall::GetDrainPoints(CBall* self) { (void)self; return nullptr; }
int* CBall::GetBreakWallPoints(CBall* self) { (void)self; return nullptr; }
int CBall::GetCurrBallPoint(CBall* self) { (void)self; return 0; }
int CBall::GetPrevBallPoint(CBall* self) { (void)self; return 0; }
int CBall::AddRef(CBall* self) { (void)self; return 0; }
int CBall::Release(CBall* self) { (void)self; return 0; }
void CBall::Deflect(CBall* self, double x, double y) { (void)self; (void)x; (void)y; }
bool CBall::CheckBoardBounds(CBall* self) { (void)self; return false; }
int CBall::Collide(CBall* self, void* a2) { (void)self; (void)a2; return 0; }
int CBall::BallsIntersect(CBall* self, CBall* a2) { (void)self; (void)a2; return 0; }
int CBall::MovingTowards(CBall* self, void* a2) { (void)self; (void)a2; return 0; }
int CBall::VerifyCollision(CBall* self, void* rect, void* point) { (void)self; (void)rect; (void)point; return 0; }
void* CBall::GetNextPoint(CBall* self) { (void)self; return nullptr; }
int CBall::GetPoint(CBall* self, int index) { (void)self; (void)index; return 0; }
void CBall::InitBallPoints(CBall* self) { (void)self; }
void CBall::scalar_deleting_destructor(CBall* self, int flags) { (void)self; (void)flags; }

// ============================================================================
// CGameBoard static members
// ============================================================================
void CGameBoard::QueryNewPallete(CGameBoard* self) { (void)self; }
void CGameBoard::UpdateBounds(CGameBoard* self) { (void)self; }
int CGameBoard::Paint(CGameBoard* self) { (void)self; return 0; }
int CGameBoard::PerformUpdate(CGameBoard* self, uint32_t a2, int a3) { (void)self; (void)a2; (void)a3; return 0; }
int CGameBoard::GetTileByIndices(CGameBoard* self, int a2, int a3) { (void)self; (void)a2; (void)a3; return 0; }
int CGameBoard::GetRandomNumber(CGameBoard* self, int max_value) { (void)self; (void)max_value; return 0; }
void CGameBoard::AddDisplayUpdateRect(CGameBoard* self, tagRECT* a2) { (void)self; (void)a2; }
void CGameBoard::ToggleRLWalls(CGameBoard* self, int color) { (void)self; (void)color; }
void CGameBoard::AddBall(CGameBoard* self, CBall* ball) { (void)self; (void)ball; }
void CGameBoard::AddBallToUpdateList(CGameBoard* self, CBall* ball) { (void)self; (void)ball; }
void CGameBoard::AddGameObjectToUpdateList(CGameBoard* self, CGameObject* obj) { (void)self; (void)obj; }
CBall* CGameBoard::GetBall(CGameBoard* self, int index) { (void)self; (void)index; return nullptr; }
int CGameBoard::NumBallsOnBoard(CGameBoard* self) { (void)self; return 0; }
tagRECT* CGameBoard::GetPlayingAreaRect(CGameBoard* self) { (void)self; static RECT r = {}; return &r; }
int CGameBoard::BallOnTile(CGameBoard* self, CBoardTile* tile) { (void)self; (void)tile; return 0; }
char* CGameBoard::GetBitmapRect(CGameBoard* self, int a1) { (void)self; (void)a1; return nullptr; }
int CGameBoard::BltBoardToInk(CGameBoard* self, tagRECT* a1, int a2) { (void)self; (void)a1; (void)a2; return 0; }
int CGameBoard::ShadowizeTile(CGameBoard* self, CBoardTile* tile, int flags) { (void)self; (void)tile; (void)flags; return 0; }
void CGameBoard::SetTile(CGameBoard* self, CBoardTile* tile) { (void)self; (void)tile; }
int CGameBoard::Shadowize(CGameBoard* self, int a2, int a3, int a4, int a5) { (void)self; (void)a2; (void)a3; (void)a4; (void)a5; return 0; }
int CGameBoard::InitDirectDraw(CGameBoard* self) { (void)self; return 0; }
void CGameBoard::RedrawBoardBuffer(CGameBoard* self) { (void)self; }
int CGameBoard::CreateNewSurfaces(CGameBoard* self) { (void)self; return 0; }
void CGameBoard::RandomizeBallOrder(CGameBoard* self) { (void)self; }
int CGameBoard::DisplayFrame(CGameBoard* self, int a2, int a3) { (void)self; (void)a2; (void)a3; return 0; }
void CGameBoard::ResetBoard(CGameBoard* self) { (void)self; }
int CGameBoard::BltBall(CGameBoard* self, CBall* ball, void* surface) { (void)self; (void)ball; (void)surface; return 0; }
int CGameBoard::PointIntersectsWithTile(CGameBoard* self, const void* point, void* tile, int deflect) { (void)self; (void)point; (void)tile; (void)deflect; return 0; }
CBoardTile* CGameBoard::GetTile(CGameBoard* self, int a2, int a3) { (void)self; (void)a2; (void)a3; return nullptr; }
CBoardTile* CGameBoard::BuildTileObject(CGameBoard* self, int tile_type, int x, int y, int rect) { (void)self; (void)tile_type; (void)x; (void)y; (void)rect; return nullptr; }
void CGameBoard::DisplayBoardLoadMsg(CGameBoard* self) { (void)self; }
void CGameBoard::FreeDirectDraw(CGameBoard* self) { (void)self; }
void CGameBoard::scalar_deleting_destructor(CGameBoard* self, int flags) { (void)self; (void)flags; }
bool CGameBoard::IsRemoteSession(CGameBoard* self) { (void)self; return false; }

// ============================================================================
// CDisplay static members
// ============================================================================
int CDisplay::UpdateBounds(CDisplay* self) { (void)self; return 0; }
void* CDisplay::GetBackBuffer(void* self) { (void)self; return nullptr; }
void* CDisplay::GetInkBuffer(void* self) { (void)self; return nullptr; }
void* CDisplay::GetFrontBuffer(void* self) { (void)self; return nullptr; }
void* CDisplay::GetBoardBuffer(void* self) { (void)self; return nullptr; }
int CDisplay::CreateSurface(void* self, void** surface, void* a3, int a4) { (void)self; (void)surface; (void)a3; (void)a4; return 0; }
int CDisplay::SetPalette(void* self, void* palette) { (void)self; (void)palette; return 0; }
int CDisplay::BltToBoard(void* self, uint64_t a2, uint64_t a3, void* surface, tagRECT* src) { (void)self; (void)a2; (void)a3; (void)surface; (void)src; return 0; }
int CDisplay::CreatePaletteFromBitmap(void* self, void** palette, const WCHAR* filename) { (void)self; (void)palette; (void)filename; return 0; }
void CDisplay::scalar_deleting_destructor(void* self, int flags) { (void)self; (void)flags; }
int CDisplay::CreateWindowedDisplay(void* self, HWND hWnd, uint32_t width, uint32_t height) { (void)self; (void)hWnd; (void)width; (void)height; return 0; }
int CDisplay::CreateSurfaceFromBitmap(void* self, void** surface, void* a3, int a4, int a5) { (void)self; (void)surface; (void)a3; (void)a4; (void)a5; return 0; }
int CDisplay::DestroyObjects(CDisplay* self) { (void)self; return 0; }

// ============================================================================
// CInk static members
// ============================================================================
int CInk::Init(CInk* self) { (void)self; return 0; }
void CInk::ClearInk(CInk* self) { (void)self; }
void CInk::OnDisplayChange(CInk* self) { (void)self; }
void CInk::SetInkRedrawFlag(CInk* self) { (void)self; }
void CInk::SetInkModifiedFlag(CInk* self) { (void)self; }
void CInk::DrawInkToSurface(CInk* self, tagRECT* a2) { (void)self; (void)a2; }
void CInk::GetInkUpdateRect(CInk* self, RECT* out) { (void)self; (void)out; }
int CInk::HitCircleTest(CInk* self, void* point, int a3, int a4) { (void)self; (void)point; (void)a3; (void)a4; return 0; }
void CInk::Cleanup(CInk* self) { (void)self; }
void CInk::scalar_deleting_destructor(CInk* self, int flags) { (void)self; (void)flags; }

// ============================================================================
// CBallManager static members
// ============================================================================
int CBallManager::InitSurface(CBallManager* self) { (void)self; return 0; }
void CBallManager::Init(CBallManager* self) { (void)self; }
void CBallManager::UpdateBallList(CBallManager* self) { (void)self; }
void CBallManager::UpdateBallPositions(CBallManager* self, uint32_t delta_time) { (void)self; (void)delta_time; }
void CBallManager::InitBallPositions(CBallManager* self) { (void)self; }
void CBallManager::SetBallOnLauncher(CBallManager* self, CBall* ball, CBoardTile* tile) { (void)self; (void)ball; (void)tile; }
void CBallManager::SetBallSpeed(CBallManager* self, CBall* ball, double speed) { (void)self; (void)ball; (void)speed; }
CBoardTile* CBallManager::GetRandomBallLauncher(CBallManager* self) { (void)self; return nullptr; }
void CBallManager::DrawToSurface(CBallManager* self) { (void)self; }
void CBallManager::Restore(CBallManager* self) { (void)self; }
void CBallManager::scalar_deleting_destructor(CBallManager* self, int flags) { (void)self; (void)flags; }

// ============================================================================
// CGameManager static members
// ============================================================================
void CGameManager::LoadBoard(CGameManager* self, void* data, int size) { (void)self; (void)data; (void)size; }
void CGameManager::DropWallTile(CGameManager* self, void* p1, void* p2) { (void)self; (void)p1; (void)p2; }
void CGameManager::UpdateTime(CGameManager* self) { (void)self; }
void CGameManager::scalar_deleting_destructor(CGameManager* self, int flags) { (void)self; (void)flags; }

// ============================================================================
// CScoreManager static members
// ============================================================================
int CScoreManager::InitSurface(CScoreManager* self) { (void)self; return 0; }
void CScoreManager::IncrementScore(void* self, uint32_t count) { (void)self; (void)count; }
uint32_t CScoreManager::GetScore(void* self) { (void)self; return 0; }
void CScoreManager::ResetScore(void* self) { (void)self; }
void CScoreManager::Restore(CScoreManager* self) { (void)self; }
void CScoreManager::UpdateObject(CScoreManager* self, uint32_t delta_time) { (void)self; (void)delta_time; }
void CScoreManager::DrawToSurface(CScoreManager* self) { (void)self; }
void CScoreManager::scalar_deleting_destructor(CScoreManager* self, int flags) { (void)self; (void)flags; }

// ============================================================================
// CTileManager static members
// ============================================================================
int CTileManager::InitSurface(CTileManager* self) { (void)self; return 0; }
void CTileManager::SetTiles(void* self, uint32_t score) { (void)self; (void)score; }
void CTileManager::ResetTileCount(void* self) { (void)self; }
int CTileManager::GetTileCount(void* self) { (void)self; return 0; }
void CTileManager::Restore(CTileManager* self) { (void)self; }
void CTileManager::UpdateObject(CTileManager* self, uint32_t delta_time) { (void)self; (void)delta_time; }
void CTileManager::DrawToSurface(CTileManager* self) { (void)self; }

// ============================================================================
// CTimeManager static members
// ============================================================================
int CTimeManager::InitSurface(CTimeManager* self) { (void)self; return 0; }
uint32_t CTimeManager::GetTime(void* self) { (void)self; return 0; }
void CTimeManager::SetTime(void* self, uint32_t time) { (void)self; (void)time; }
void CTimeManager::InitTime(void* self, uint32_t time) { (void)self; (void)time; }
void CTimeManager::Restore(CTimeManager* self) { (void)self; }
void CTimeManager::UpdateObject(CTimeManager* self, uint32_t delta_time) { (void)self; (void)delta_time; }
void CTimeManager::DrawToSurface(CTimeManager* self) { (void)self; }

// ============================================================================
// CRegistryManager static members
// ============================================================================
uint32_t CRegistryManager::ReadDifficulty(CRegistryManager* self) { (void)self; return 0; }
void CRegistryManager::WriteDifficulty(CRegistryManager* self, uint32_t difficulty) { (void)self; (void)difficulty; }
uint32_t CRegistryManager::ReadHiScore(CRegistryManager* self) { (void)self; return 0; }
void CRegistryManager::WriteHiScore(CRegistryManager* self, int score) { (void)self; (void)score; }

// ============================================================================
// CBoardManager static members
// ============================================================================
void* CBoardManager::GetLastLoadedBoardData(CBoardManager* self) { (void)self; return nullptr; }
int CBoardManager::LoadRandomBonusBoardFromResources(CBoardManager* self, void* boardData, int* boardSize) { (void)self; (void)boardData; (void)boardSize; return 0; }

// ============================================================================
// CSurface static members
// ============================================================================
int CSurface::ConvertGDIColor(CSurface* self, uint32_t color) { (void)self; (void)color; return 0; }
int CSurface::IsColorKeyed(CSurface* self) { (void)self; return 0; }
void* CSurface::GetDDrawSurface(void* self) { (void)self; return nullptr; }
int CSurface::SetColorKey(void* self, uint32_t color) { (void)self; (void)color; return 0; }
int CSurface::DrawBitmap(CSurface* self, void* bitmap, int a3, int a4, int a5, int a6) { (void)self; (void)bitmap; (void)a3; (void)a4; (void)a5; (void)a6; return 0; }
void CSurface::scalar_deleting_destructor(void* self, int flags) { (void)self; (void)flags; }
void CSurface::Clear(CSurface* self, uint32_t color) { (void)self; (void)color; }

// ============================================================================
// CBoardTileRLColored static members
// ============================================================================
void CBoardTileRLColored::ToggleState(void* self) { (void)self; }

// ============================================================================
// CMovingObject static members
// ============================================================================
void CMovingObject::GetMovementRect(CMovingObject* self, RECT* out) { (void)self; (void)out; }

// ============================================================================
// CBoardTile static members
// ============================================================================
void CBoardTile::SetClosestSide(CBoardTile* self, void* point) { (void)self; (void)point; }

// ============================================================================
// CBoardObject static members
// ============================================================================
void CBoardObject::GetCenterPoint(void* self, void* out) { (void)self; (void)out; }

// ============================================================================
// CBitmapRects static members
// ============================================================================
char* CBitmapRects::GetBitmapRect(void* self, int id) { (void)self; (void)id; return nullptr; }

// ============================================================================
// extern "C" wrappers for calling convention mismatches
// ============================================================================
extern "C" {
    void __stdcall ConvertTileToFloor(void* tile) { (void)tile; }
    void __stdcall ScoreBreak(void* ball) { (void)ball; }
    void __stdcall PerformStandardWallDeflection(void* tile, void* ball) { (void)tile; (void)ball; }
    void ScoreBall(void* ball, uint32_t color) { (void)ball; (void)color; }
    void SetBallColor(void* ball, uint32_t color) { (void)ball; (void)color; }
    int AddBallToBoard(int ball_type) { (void)ball_type; return 0; }
    CBoardTile* BuildTileObject(int a1, int a2, int a3) { (void)a1; (void)a2; (void)a3; return nullptr; }
    void DisplayBoardLoadMsg() {}
    int SearchBoardList(wchar_t* a1, unsigned char* a2, int a3, BoardCollection* a4, int* a5) { (void)a1; (void)a2; (void)a3; (void)a4; (void)a5; return 0; }
    bool __stdcall BallOnTile(void* tile) { (void)tile; return false; }
    void __stdcall AddRLColoredWallToList(void* tile) { (void)tile; }
    void FreeCursorStroke() {}
    int CSurface_Create(CSurface* self, IDirectDraw7* a2, DDSURFACEDESC2* a3) { (void)self; (void)a2; (void)a3; return 0; }
    void* GetTabletContextInfo(uint32_t id) { (void)id; return nullptr; }
}

// C++ linkage standalone functions
void CGameBoard_AddRLColoredWallToList(CGameBoard* self, CBoardTileRLColored* tile) { (void)self; (void)tile; }
void CleanupTabletContexts() {}
int SetAtGrow_CMFCArray_CTabletContextInfo_CTabletContextInfo___(uint32_t* self, int a2, const void* a3) { (void)self; (void)a2; (void)a3; return 0; }
void AddBallToUpdateList(CBall* ball) { (void)ball; }
void CheckForBallCollisionWithNonDeflectingTile(void* self) { (void)self; }
void CheckForBallCollisionWithBall(void* self) { (void)self; }
void CheckForBallCollisionWithInk(void* self) { (void)self; }
void CheckForBallCollisionWithTile(void* self) { (void)self; }

// ============================================================================
// WPP / ETW stubs
// ============================================================================
extern "C" {
    uint32_t __stdcall WPP_SF_(TRACEHANDLE handle, uint16_t a2, const GUID* a3) { (void)handle; (void)a2; (void)a3; return 0; }
    uint32_t __stdcall WPP_SF_d(uint64_t handle, uint16_t a2, const GUID* a3, char a4) { (void)handle; (void)a2; (void)a3; (void)a4; return 0; }
    void __stdcall WPP_INIT_CONTROL_ARRAY(void* control_array) { (void)control_array; }
    uint32_t __stdcall WppInitUm(int unused_param) { (void)unused_param; return 0; }
    void __stdcall WppCleanupUm() {}
    void __stdcall _WinSqmDWORDEvent(void* p1, int p2, int p3, int p4) { (void)p1; (void)p2; (void)p3; (void)p4; }
    int __cdecl _time(void* timer) { (void)timer; return 0; }
    void __cdecl _srand(unsigned int seed) { (void)seed; }
}

// ============================================================================
// Math stubs
// ============================================================================
extern "C" {
    double cosd(double x) { return cos(x * 3.14159265358979323846 / 180.0); }
    double sind(double x) { return sin(x * 3.14159265358979323846 / 180.0); }
}

// ============================================================================
// GetObjectW_wpp (void* return version - different from stubs.cpp int return)
// ============================================================================
void* __stdcall GetObjectW_wpp(void* h, int c, void* pv, int unused, int* out) {
    (void)unused; (void)out; return (void*)::GetObjectW((HGDIOBJ)h, c, (LPVOID)pv);
}
