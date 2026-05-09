#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CInk::Cleanup(CInk *this)
{
  uint8_t v1[16]; // [esp+10h] [ebp-14h] BYREF
  int v2; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "CInk::Cleanup", 0);
  v2 = 0;
  if ( g_pTabletManager )
    (*(void (__stdcall **)(struct ITabletManager *))(*(uint32_t *)g_pTabletManager + 8))(g_pTabletManager);
  g_pTabletManager = 0;
  CleanupTabletContexts();
  if ( g_pIInkObject )
    (*(void (__stdcall **)(struct IInkObject *))(*(uint32_t *)g_pIInkObject + 8))(g_pIInkObject);
  g_pIInkObject = 0;
  if ( g_pIInkCollect )
    (*(void (__stdcall **)(struct IInkCollect *))(*(uint32_t *)g_pIInkCollect + 8))(g_pIInkCollect);
  g_pIInkCollect = 0;
  if ( g_pIRenderInk )
    (*(void (__stdcall **)(struct IRenderInk *))(*(uint32_t *)g_pIRenderInk + 8))(g_pIRenderInk);
  g_pIRenderInk = 0;
  if ( g_pIRenderingContext )
    (*(void (__stdcall **)(struct IRenderingContext *))(*(uint32_t *)g_pIRenderingContext + 8))(g_pIRenderingContext);
  g_pIRenderingContext = 0;
  if ( g_pIInkManager )
    (*(void (__stdcall **)(LPVOID))(*(uint32_t *)g_pIInkManager + 8))(g_pIInkManager);
  g_pIInkManager = 0;
  FreeCursorStroke();
  v2 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v1);
}
