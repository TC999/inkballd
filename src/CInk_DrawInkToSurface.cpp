//----- (0100BA9A) --------------------------------------------------------
void __thiscall CInk::DrawInkToSurface(CInk *this, struct tagRECT *a2)
{
  int v2; // ecx
  int v3; // eax
  _DWORD v4[4]; // [esp+10h] [ebp-2Ch] BYREF
  _BYTE v5[8]; // [esp+20h] [ebp-1Ch] BYREF
  HDC v6; // [esp+28h] [ebp-14h] BYREF
  int v7[3]; // [esp+2Ch] [ebp-10h] BYREF
  int v8; // [esp+38h] [ebp-4h]

  v7[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CInk::DrawInkToSurface", v7);
  v8 = 0;
  if ( a2 )
  {
    v4[0] = 10 * a2->left;
    v4[2] = 10 * a2->right;
    v4[1] = 10 * a2->top;
    v4[3] = 10 * a2->bottom;
  }
  GetInkBufferHDC(&v6);
  v2 = *(_DWORD *)g_pIRenderInk;
  if ( a2 )
    v3 = (*(int (__stdcall **)(struct IRenderInk *, HDC, _DWORD *, struct tagRECT *, _DWORD))(v2 + 16))(
           g_pIRenderInk,
           v6,
           v4,
           a2,
           0);
  else
    v3 = (*(int (__stdcall **)(struct IRenderInk *, HDC, void *, struct HWND__ *, _DWORD))(v2 + 16))(
           g_pIRenderInk,
           v6,
           &g_rcInkSpace,
           &g_rcClient,
           0);
  v7[0] = v3;
  ReleaseInkBufferHDC(v6);
  v8 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
