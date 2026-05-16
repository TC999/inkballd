//----- (01004E41) --------------------------------------------------------
void __thiscall CBallManager::UpdateBallList(CBallManager *this)
{
  int v2; // edi
  _DWORD *v3; // edx
  int v4; // ecx
  bool v5; // zf
  int v6; // ebx
  int *v7; // edi
  struct CBall *Ball; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  bool v12; // cc
  _BYTE v13[8]; // [esp+10h] [ebp-1Ch] BYREF
  int v14; // [esp+18h] [ebp-14h]
  int v15; // [esp+1Ch] [ebp-10h]
  int v16; // [esp+28h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v13, "CBallManager::UpdateBallList", 0);
  v16 = 0;
  v15 = 0;
  v2 = *((_DWORD *)this + 14);
  v3 = (_DWORD *)((char *)this + 56);
  v14 = 5;
  do
  {
    v4 = v3[1];
    *v3 = v4;
    *(_DWORD *)(v4 + 156) = 0;
    v5 = v14-- == 1;
    ++v3;
  }
  while ( !v5 );
  *((_DWORD *)this + 19) = v2;
  *(_DWORD *)(v2 + 156) = 0;
  v6 = *((_DWORD *)this + 9);
  if ( v6 < v6 + *((_DWORD *)this + 10) )
  {
    v7 = (int *)((char *)this + 56);
    do
    {
      Ball = GetBall(v6);
      v9 = *v7;
      v10 = *((_DWORD *)Ball + 11);
      ++v15;
      *(_DWORD *)(v9 + 44) = v10;
      v11 = *v7++;
      v12 = v15 <= 5;
      *(_DWORD *)(v11 + 156) = 1;
      if ( !v12 )
        break;
      ++v6;
    }
    while ( v6 < *((_DWORD *)this + 10) + *((_DWORD *)this + 9) );
  }
  v16 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v13);
}
