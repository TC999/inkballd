#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void __thiscall CBallManager::SetBallOnLauncher(CBallManager *this, CBall*a2, CBoardTile*a3)
{
  int v4; // eax
  uint8_t v5[8]; // [esp+10h] [ebp-1Ch] BYREF
  int v7; // [esp+28h] [ebp-4h]
  CBoardObject *v8; // [esp+38h] [ebp+Ch]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CBallManager::SetBallOnLauncher", 0);
  v7 = 0;
  if ( *((uint32_t *)this + 20) )
  {
    CBoardObject::GetCenterPoint(a3, &v6);
    v4 = *((uint32_t *)a2 + 6) / 2;
    v8 = (CBoardObject *)(v6.y - v4);
    *((double *)a2 + 1) = (double)(v6.x - v4);
    *((double *)a2 + 2) = (double)(int)v8;
  }
  v7 = -1;
  ((Helpers::CLogBlock *)v5)->~CLogBlock();
}
