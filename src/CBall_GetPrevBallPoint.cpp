//----- (01003F73) --------------------------------------------------------
int __thiscall CBall::GetPrevBallPoint(CBall *this)
{
  int v2; // esi
  _BYTE v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBall::GetPrevBallPoint", 0);
  v5 = 0;
  if ( CBall::GetCurrBallPoint(this) )
    v2 = CBall::GetCurrBallPoint(this) - 1;
  else
    v2 = 31;
  v5 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
