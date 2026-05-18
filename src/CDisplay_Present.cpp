//----- (0100E2F6) --------------------------------------------------------
int CDisplay::Present(void* self, struct tagRECT *lprcSrc)
{
  const RECT* _self = (const RECT*)_self;
  bool v3; // zf
  int v4; // esi
  int v6; // eax
  LONG top; // edi
  LONG bottom; // [esp-10h] [ebp-68h]
  LONG v9; // [esp-10h] [ebp-68h]
  RECT rcSrc; // [esp+10h] [ebp-48h] BYREF
  tagRECT rcDst; // [esp+20h] [ebp-38h] BYREF
  LONG left; // [esp+30h] [ebp-28h] BYREF
  LONG v13; // [esp+34h] [ebp-24h]
  int v14; // [esp+38h] [ebp-20h]
  int v15; // [esp+3Ch] [ebp-1Ch]
  _BYTE v16[8]; // [esp+40h] [ebp-18h] BYREF
  int v17[3]; // [esp+48h] [ebp-10h] BYREF
  int v18; // [esp+54h] [ebp-4h]
  RECT *lprcSrca; // [esp+60h] [ebp+8h]

  v17[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "CDisplay::Present", v17);
  v3 = _self->right == 0;
  v18 = 0;
  if ( v3 || !_self->bottom )
  {
    v4 = -2147467261;
    goto LABEL_6;
  }
  if ( lprcSrc )
  {
    if ( !_self[3].left )
    {
      v4 = -2147467263;
LABEL_6:
      v17[0] = v4;
      goto LABEL_7;
    }
    CopyRect(&rcDst, lprcSrc);
    OffsetRect(&rcDst, _self[2].left, _self[2].top);
    IntersectRect(&rcSrc, &rcDst, _self + 2);
    CopyRect(&rcDst, &rcSrc);
    OffsetRect(&rcDst, -_self[2].left, -_self[2].top);
    left = _self[2].left + (unsigned __int64)((double)rcDst.left / dSizeFactor);
    v13 = _self[2].top + (unsigned __int64)((double)rcDst.top / dSizeFactor);
    v14 = left + (unsigned __int64)((double)(rcSrc.right - rcSrc.left) / dSizeFactor);
    bottom = _self->bottom;
    v15 = v13 + (unsigned __int64)((double)(rcSrc.bottom - rcSrc.top) / dSizeFactor);
    v6 = (*(int (__stdcall **)(LONG, LONG *, LONG, tagRECT *, int, _DWORD))(*(_DWORD *)_self->right + 20))(
           _self->right,
           &left,
           bottom,
           &rcDst,
           0x1000000,
           0);
    v17[0] = v6;
LABEL_9:
    v4 = v6;
  }
  else
  {
    while ( 1 )
    {
      if ( _self[3].left )
      {
        lprcSrca = (RECT *)(_self[2].right - _self[2].left);
        top = _self[2].top;
        left = _self[2].left;
        v13 = top;
        v14 = _self[2].left + (unsigned __int64)((double)(int)lprcSrca / dSizeFactor);
        v9 = _self->bottom;
        v15 = top + (unsigned __int64)((double)(_self[2].bottom - top) / dSizeFactor);
        v6 = (*(int (__stdcall **)(LONG, LONG *, LONG, _DWORD, int, _DWORD))(*(_DWORD *)_self->right + 20))(
               _self->right,
               &left,
               v9,
               0,
               0x1000000,
               0);
      }
      else
      {
        v6 = (*(int (__stdcall **)(LONG, _DWORD, _DWORD))(*(_DWORD *)_self->right + 44))(_self->right, 0, 0);
      }
      v17[0] = v6;
      if ( v6 == -2005532222 )
        break;
      if ( v6 != -2005532132 )
        goto LABEL_9;
    }
    v4 = -2005532222;
  }
LABEL_7:
  v18 = -1;
  ((Helpers::CLogBlock *)v16)->~CLogBlock();
  return v4;
}
