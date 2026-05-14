#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

extern "C" void ConstructElements_CTabletContextInfo(CTabletContextInfo* pElements, int nCount);

int __cdecl SetSize_CMFCArray_CTabletContextInfo_CTabletContextInfo___(void* self, int unused, signed int a2, int a3)
{
  uint32_t *v6; // ecx
  uint32_t *v7; // eax
  signed int v8; // ebx
  int v9; // eax
  int v10; // eax
  void*v11; // ebx
  int v12; // [esp+Ch] [ebp-4h]
  int v13; // [esp+18h] [ebp+8h]
  uint32_t* _this = (uint32_t*)self;

  v12 = 0;
  if ( a2 < 0 || a3 < -1 )
    return -2147024809;
  if ( a3 != -1 )
    _this[3] = a3;
  if ( !a2 )
  {
    if ( _this[0] )
    {
      operator delete[]((void*)_this[0]);
      _this[0] = 0;
    }
    _this[2] = 0;
    _this[1] = 0;
    return v12;
  }
  v6 = (uint32_t*)_this[0];
  if ( _this[0] )
  {
    v8 = _this[2];
    if ( a2 <= (signed int)v8 )
    {
      v9 = _this[1];
      if ( a2 > v9 )
        ConstructElements_CTabletContextInfo((CTabletContextInfo*)(&v6[6 * v9]), a2 - v9);
      goto LABEL_16;
    }
    v10 = _this[3];
    if ( !v10 )
    {
      v10 = _this[1] / 8;
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
    if ( v13 >= (signed int)_this[1] )
    {
      v11 = operator new[](24 * v13);
      if ( v11 )
      {
        memcpy(v11, *(const void**)self, 24 * _this[1]);
        ConstructElements_CTabletContextInfo((CTabletContextInfo*)((uint32_t*)v11 + 6 * _this[1]), a2 - _this[1]);
        operator delete[]((void*)_this[0]);
        _this[0] = (uint32_t)v11;
        _this[1] = a2;
        _this[2] = v13;
        return v12;
      }
    }
    return -2147024882;
  }
  v7 = (uint32_t*)operator new[](24 * a2);
  if ( !v7 )
    return -2147024882;
  _this[0] = (uint32_t)v7;
  ConstructElements_CTabletContextInfo((CTabletContextInfo*)v7, a2);
  _this[2] = a2;
LABEL_16:
  _this[1] = a2;
  return v12;
}
