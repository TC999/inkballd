struct BallPoint *__thiscall CBall::GetNextPoint(CBall *this)
{
  int v2; // eax
  int v3; // esi
  int v5; // ecx
  _BYTE v6[16]; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CBall::GetNextPoint", 0);
  v2 = *((_DWORD *)this + 32);
  if ( v2 <= 16 )
  {
    v5 = **((_DWORD **)this + 30) + 8 * ((v2 + *((_DWORD *)this + 31)) % 32);
    *((_DWORD *)this + 32) = v2 + 1;
    v3 = v5;
  }
  else
  {
    *((_DWORD *)this + 32) = 0;
    v3 = 0;
  }
  v7 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
  return (struct BallPoint *)v3;
}
