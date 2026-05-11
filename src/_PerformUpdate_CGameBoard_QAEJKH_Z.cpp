#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CGameBoard::PerformUpdate(CGameBoard *this, uint32_t a2, int a3)
{
  int v4; // ebx
  uint32_t *v5; // edi
  bool v6; // cc
  CMovingObject **v7; // edi
  uint32_t *v8; // edi
  uint32_t Score; // eax
  int NewSurfaces; // eax
  uint8_t v13[8]; // [esp+10h] [ebp-20h] BYREF
  int v14; // [esp+18h] [ebp-18h]
  int v15; // [esp+1Ch] [ebp-14h] BYREF
  uint32_t v16; // [esp+20h] [ebp-10h]
  int v17; // [esp+2Ch] [ebp-4h]
  uint32_t v18; // [esp+38h] [ebp+8h]

  v4 = 0;
  v15 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v13, "CGameBoard::PerformUpdate", &v15);
  v17 = 0;
  v16 = a2;
  if ( dword_105C760 )
  {
    (*(void (__thiscall **)(uint32_t))(**((uint32_t **)this + 2477) + 4))(*((uint32_t *)this + 2477));
    (*(void (__thiscall **)(uint32_t))(**((uint32_t **)this + 2478) + 4))(*((uint32_t *)this + 2478));
    (*(void (__thiscall **)(uint32_t))(**((uint32_t **)this + 2479) + 4))(*((uint32_t *)this + 2479));
    dword_105C760 = 0;
  }
  if ( *(int*)this > 0 )
  {
    v5 = (uint32_t *)(reinterpret_cast<char*>(this) + 4);
    do
    {
      (**(void (__thiscall ***)(uint32_t, uint32_t))*v5)(*v5, a2);
      ++v4;
      ++v5;
    }
    while ( v4 < *(uint32_t *)this );
    v4 = 0;
  }
  v6 = *((uint32_t *)this + 301) <= 0;
  v14 = 0;
  if ( !v6 )
  {
    v7 = (CMovingObject **)(reinterpret_cast<char*>(this) + 1208);
    do
    {
      CMovingObject::PrepareToMove(*v7);
      ++v14;
      ++v7;
    }
    while ( v14 < *((uint32_t *)this + 301) );
  }
  if ( a2 )
  {
    do
    {
      v18 = 4;
      if ( v16 <= 4 )
        v18 = v16;
      if ( *((int*)this + 301) > 0 )
      {
        v8 = (uint32_t *)(reinterpret_cast<char*>(this) + 1208);
        do
        {
          (**(void (__thiscall ***)(uint32_t, uint32_t))*v8)(*v8, v18);
          ++v4;
          ++v8;
        }
        while ( v4 < *((uint32_t *)this + 301) );
        v4 = 0;
      }
      if ( v16 <= 4 )
        v16 = 0;
      else
        v16 -= 4;
    }
    while ( v16 );
  }
  Score = CScoreManager::GetScore(*((CScoreManager **)this + 2477));
  CTileManager::SetTiles(*((CTileManager **)this + 2478), Score);
  DirectDraw = CDisplay::GetDirectDraw(g_pDisplay);
  NewSurfaces = DirectDraw->lpVtbl->TestCooperativeLevel(DirectDraw);
  v15 = NewSurfaces;
  if ( NewSurfaces >= 0 )
  {
    NewSurfaces = CGameBoard::DisplayFrame(this, a3, 0);
    v15 = NewSurfaces;
    if ( NewSurfaces < 0 )
    {
      if ( NewSurfaces != -2005532222 )
        goto LABEL_27;
      CGameBoard::RestoreSurfaces((CScoreManager **)this);
      CGameBoard::DisplayFrame(this, 1, 1);
    }
    *((uint32_t *)this + 1018) = 0;
    *((uint32_t *)this + 2175) = 0;
    v15 = 0;
    goto LABEL_28;
  }
  if ( NewSurfaces == -2005532091 )
  {
    Sleep(0xAu);
    NewSurfaces = 0;
    goto LABEL_26;
  }
  if ( NewSurfaces == -2005532085 )
  {
    NewSurfaces = CGameBoard::CreateNewSurfaces(this);
LABEL_26:
    v15 = NewSurfaces;
  }
LABEL_27:
  v4 = NewSurfaces;
LABEL_28:
  v17 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v13)->~CLogBlock();
  return v4;
}

#endif
