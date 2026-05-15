//----- (0100C739) --------------------------------------------------------
extern "C" void CleanupTabletContexts();
extern "C" void FreeCursorStroke();
void __thiscall CInk::Cleanup(CInk *self)
{
  _BYTE v1[16]; // [esp+10h] [ebp-14h] BYREF
  int v2; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "CInk::Cleanup", 0);
  v2 = 0;
  if ( g_pTabletManager )
    (*(void (__stdcall **)(struct ITabletManager *))(*(_DWORD *)g_pTabletManager + 8))(g_pTabletManager);
  g_pTabletManager = 0;
  CleanupTabletContexts();
  if ( g_pIInkObject )
    (*(void (__stdcall **)(struct IInkObject *))(*(_DWORD *)g_pIInkObject + 8))(g_pIInkObject);
  g_pIInkObject = 0;
  if ( g_pIInkCollect )
    (*(void (__stdcall **)(struct IInkCollect *))(*(_DWORD *)g_pIInkCollect + 8))(g_pIInkCollect);
  g_pIInkCollect = 0;
  if ( g_pIRenderInk )
    (*(void (__stdcall **)(struct IRenderInk *))(*(_DWORD *)g_pIRenderInk + 8))(g_pIRenderInk);
  g_pIRenderInk = 0;
  if ( g_pIRenderingContext )
    (*(void (__stdcall **)(struct IRenderingContext *))(*(_DWORD *)g_pIRenderingContext + 8))(g_pIRenderingContext);
  g_pIRenderingContext = 0;
  if ( g_pIInkManager )
    (*(void (__stdcall **)(LPVOID))(*(_DWORD *)g_pIInkManager + 8))(g_pIInkManager);
  g_pIInkManager = 0;
  FreeCursorStroke();
  v2 = -1;
  ((Helpers::CLogBlock *)v1)->~CLogBlock();
}
