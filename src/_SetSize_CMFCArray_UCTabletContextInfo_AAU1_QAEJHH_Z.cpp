#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CMFCArray<CTabletContextInfo,CTabletContextInfo &>::SetSize(int this, signed int a2, int a3)
{
  uint32_t *v6; // ecx
  uint32_t *v7; // eax
  signed int v8; // ebx
  int v9; // eax
  int v10; // eax
  void*v11; // ebx
  int v12; // [esp+Ch] [ebp-4h]
  int v13; // [esp+18h] [ebp+8h]

  v12 = 0;
  if ( a2 < 0 || a3 < -1 )
    return -2147024809;
  if ( a3 != -1 )
    *(uint32_t *)(this + 12) = a3;
  if ( !a2 )
  {
    if ( *(uint32_t *)this )
    {
      operator delete[](*(void**)this);
      *(uint32_t *)this = 0;
    }
    *(uint32_t *)(this + 8) = 0;
    *(uint32_t *)(this + 4) = 0;
    return v12;
  }
  v6 = *(uint32_t **)this;
  if ( *(uint32_t *)this )
  {
    v8 = *(uint32_t *)(this + 8);
    if ( a2 <= v8 )
    {
      v9 = *(uint32_t *)(this + 4);
      if ( a2 > v9 )
        ConstructElements<CTabletContextInfo>(&v6[6 * v9], a2 - v9);
      goto LABEL_16;
    }
    v10 = *(uint32_t *)(this + 12);
    if ( !v10 )
    {
      v10 = *(uint32_t *)(this + 4) / 8;
      if ( v10 >= 4 )
      {
        if ( v10 > 1024 )
          v10 = 1024;
      }
      else
      {
        v10 = 4;
      }
    }
    v13 = v8 + v10;
    if ( a2 >= v8 + v10 )
      v13 = a2;
    if ( v13 >= *(uint32_t *)(this + 4) )
    {
      v11 = operator new[](24 * v13);
      if ( v11 )
      {
        memcpy(v11, *(const void**)this, 24 * *(uint32_t *)(this + 4));
        ConstructElements<CTabletContextInfo>((uint32_t *)v11 + 6 * *(uint32_t *)(this + 4), a2 - *(uint32_t *)(this + 4));
        operator delete[](*(void**)this);
        *(uint32_t *)this = v11;
        *(uint32_t *)(this + 4) = a2;
        *(uint32_t *)(this + 8) = v13;
        return v12;
      }
    }
    return -2147024882;
  }
  v7 = operator new[](24 * a2);
  if ( !v7 )
    return -2147024882;
  *(uint32_t *)this = v7;
  ConstructElements<CTabletContextInfo>(v7, a2);
  *(uint32_t *)(this + 8) = a2;
LABEL_16:
  *(uint32_t *)(this + 4) = a2;
  return v12;
}
