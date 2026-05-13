#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int CDisplay::Present(const RECT *this, struct tagRECT *lprcSrc)
{
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
  uint8_t v16[8]; // [esp+40h] [ebp-18h] BYREF
  int v17[3]; // [esp+48h] [ebp-10h] BYREF
  int v18; // [esp+54h] [ebp-4h]
  RECT *lprcSrca; // [esp+60h] [ebp+8h]

  v17[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)v16, "CDisplay::Present", v17);
  v3 = this->right == 0;
  v18 = 0;
  if ( v3 || !this->bottom )
  {
    v4 = -2147467261;
    goto LABEL_6;
  }
  if ( lprcSrc )
  {
    if ( !this[3].left )
    {
      v4 = -2147467263;
LABEL_6:
      v17[0] = v4;
      goto LABEL_7;
    }
    CopyRect(&rcDst, lprcSrc);
    OffsetRect(&rcDst, this[2].left, this[2].top);
    IntersectRect(&rcSrc, &rcDst, this + 2);
    CopyRect(&rcDst, &rcSrc);
    OffsetRect(&rcDst, -this[2].left, -this[2].top);
    left = this[2].left + (unsigned int64_t)((double)rcDst.left / dSizeFactor);
    v13 = this[2].top + (unsigned int64_t)((double)rcDst.top / dSizeFactor);
    v14 = left + (unsigned int64_t)((double)(rcSrc.right - rcSrc.left) / dSizeFactor);
    bottom = this->bottom;
    v15 = v13 + (unsigned int64_t)((double)(rcSrc.bottom - rcSrc.top) / dSizeFactor);
    v6 = (*(int (__stdcall **)(LONG, long*, LONG, tagRECT *, int, uint32_t))(*(uint32_t *)this->right + 20))(
           this->right,
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
      if ( this[3].left )
      {
        lprcSrca = (RECT *)(this[2].right - this[2].left);
        top = this[2].top;
        left = this[2].left;
        v13 = top;
        v14 = this[2].left + (unsigned int64_t)((double)(int)lprcSrca / dSizeFactor);
        v9 = this->bottom;
        v15 = top + (unsigned int64_t)((double)(this[2].bottom - top) / dSizeFactor);
        v6 = (*(int (__stdcall **)(LONG, long*, LONG, uint32_t, int, uint32_t))(*(uint32_t *)this->right + 20))(
               this->right,
               &left,
               v9,
               0,
               0x1000000,
               0);
      }
      else
      {
        v6 = (*(int (__stdcall **)(LONG, uint32_t, uint32_t))(*(uint32_t *)this->right + 44))(this->right, 0, 0);
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
  ((Helpers::CLogBlock*)v16)->~CLogBlock();
  return v4;
}

