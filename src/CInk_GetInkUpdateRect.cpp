//----- (0100BB3B) --------------------------------------------------------
int __thiscall CInk::GetInkUpdateRect(CInk *this, struct tagRECT *a2)
{
  int v3; // edi
  bool v4; // zf
  tagXFORM v6; // [esp+10h] [ebp-30h] BYREF
  _BYTE v7[8]; // [esp+28h] [ebp-18h] BYREF
  int v8[3]; // [esp+30h] [ebp-10h] BYREF
  int v9; // [esp+3Ch] [ebp-4h]

  v3 = 0;
  v8[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CInk::GetInkUpdateRect", v8);
  v4 = *((_DWORD *)this + 3) == 0;
  v9 = 0;
  if ( !v4 )
  {
    *((_DWORD *)this + 3) = 0;
    CInk::DrawInkToSurface(this, 0);
  }
  if ( *((_DWORD *)this + 2) )
  {
    *((_DWORD *)this + 2) = 0;
    v8[0] = (*(int (__stdcall **)(struct IRenderingContext *, tagXFORM *))(*(_DWORD *)g_pIRenderingContext + 20))(
              g_pIRenderingContext,
              &v6);
    if ( v8[0] >= 0 )
    {
      if ( g_pIStroke )
      {
        v8[0] = (*(int (__stdcall **)(struct IInkStroke *, _DWORD, struct tagRECT *))(*(_DWORD *)g_pIStroke + 16))(
                  g_pIStroke,
                  0,
                  a2);
        if ( v8[0] >= 0 )
        {
          ExpandRect(a2, 200);
          ConvertInkRectToDisplayRect(a2, &v6);
          v3 = 1;
        }
      }
    }
  }
  v9 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
  return v3;
}
