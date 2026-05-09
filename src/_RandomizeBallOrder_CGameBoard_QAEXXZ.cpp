#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CGameBoard::RandomizeBallOrder(CGameBoard *this)
{
  int v2; // ebx
  int v3; // eax
  int*v4; // edi
  int RandomNumber; // eax
  int v6; // ecx
  int*v7; // eax
  int v8; // eax
  char*v9; // ecx
  uint8_t v10[16]; // [esp+10h] [ebp-14h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  v2 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CGameBoard::RandomizeBallOrder", 0);
  v3 = *((uint32_t *)this + 656);
  v11 = 0;
  if ( v3 > 0 )
  {
    v4 = (int*)(reinterpret_cast<char*>(this) + 2628);
    do
    {
      RandomNumber = CGameBoard::GetRandomNumber(this, v3);
      v6 = *v4;
      v7 = (int*)(reinterpret_cast<char*>(this) + 4 * RandomNumber + 2628);
      *v4 = *v7;
      *v7 = v6;
      v3 = *((uint32_t *)this + 656);
      ++v2;
      ++v4;
    }
    while ( v2 < v3 );
  }
  v8 = 0;
  if ( *((int*)this + 656) > 0 )
  {
    v9 = reinterpret_cast<char*>(this) + 2628;
    do
    {
      *(uint32_t *)(*(uint32_t *)v9 + 164) = v8++;
      v9 += 4;
    }
    while ( v8 < *((uint32_t *)this + 656) );
  }
  v11 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
}
