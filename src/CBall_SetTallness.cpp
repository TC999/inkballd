//----- (01004A99) --------------------------------------------------------
void CBall::SetTallness(CBall* self, int tallness)
{
  char* a2 = (char*)tallness;
  bool v3; // zf
  int v4; // eax
  double v5; // st7
  int v6; // eax
  double v7; // st6
  BallPoints *v8; // ecx
  BallPoints *v9; // edi
  void **v10; // ecx
  const char *v11[5]; // [esp+10h] [ebp-18h] BYREF
  int v12; // [esp+24h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CBall::SetTallness", 0);
  v4 = (int)&a2[-*((_DWORD *)self + 35)];
  v3 = a2 == *((char **)self + 35);
  v12 = 0;
  if ( !v3 )
  {
    v5 = (double)v4;
    v6 = 2 * v4;
    v7 = *((double *)self + 1);
    *((_DWORD *)self + 6) += v6;
    *((_DWORD *)self + 7) += v6;
    *((double *)self + 1) = v7 - v5;
    *((double *)self + 2) = *((double *)self + 2) - v5;
    CBall::CheckBoardBounds(self);
    *((_DWORD *)self + 35) = (uint32_t)(uintptr_t)a2;
    LOBYTE(v12) = 1;
    v8 = (BallPoints *)operator new(4u);
    LOBYTE(v12) = 2;
  if ( v8 )
    new (v8) BallPoints();
  v9 = v8;
    v10 = (void **)*((_DWORD *)self + 30);
    LOBYTE(v12) = 1;
    if ( v10 )
    {
      BallPoints::scalar_deleting_destructor((BallPoints*)v10, 1);
      *((_DWORD *)self + 30) = 0;
    }
    *((_DWORD *)self + 30) = (uint32_t)(uintptr_t)v9;
  }
  v12 = -1;
  ((Helpers::CLogBlock *)v11)->~CLogBlock();
}
