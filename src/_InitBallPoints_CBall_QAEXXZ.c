void __thiscall CBall::InitBallPoints(CBall *this)
{
  int v2; // eax
  int v3; // edx
  int v4; // edi
  int *v5; // ecx
  _BYTE v6[8]; // [esp+8h] [ebp-10h] BYREF
  float v7; // [esp+10h] [ebp-8h]
  float v8; // [esp+14h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CBall::InitBallPoints", 0);
  v2 = *((_DWORD *)this + 30);
  v3 = 0;
  v4 = 1;
  v5 = (int *)(*(_DWORD *)v2 + 8);
  v7 = (double)*(int *)(*(_DWORD *)v2 + 4) * *((double *)this + 9) + (double)**(int **)v2 * *((double *)this + 8);
  do
  {
    v8 = (double)v5[1] * *((double *)this + 9) + (double)*v5 * *((double *)this + 8);
    if ( v8 > (double)v7 )
    {
      v3 = v4;
      v7 = v8;
    }
    ++v4;
    v5 += 2;
  }
  while ( v4 < 32 );
  *((_DWORD *)this + 31) = v3 - 8;
  if ( v3 - 8 < 0 )
    *((_DWORD *)this + 31) = v3 - 8 + 32;
  *((_DWORD *)this + 32) = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
}
