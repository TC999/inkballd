#include <windows.h>
#include <cstdio>

int __stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd);

int main()
{
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONOUT$", "w", stderr);
    freopen_s(&fp, "CONIN$", "r", stdin);

    HINSTANCE hInstance = GetModuleHandleW(NULL);
    LPWSTR lpCmdLine = GetCommandLineW();

    return wWinMain(hInstance, NULL, lpCmdLine, SW_SHOWDEFAULT);
}
