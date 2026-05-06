void __thiscall CBall::UpdateObject(CBall *this, unsigned int a2)
{
  bool v3; // zf
  double v4; // st7
  _BYTE v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CBall::UpdateObject", 0);
  v3 = *((_DWORD *)this + 39) == 0;
  v6 = 0;
  if ( !v3 )
  {
    v4 = (double)a2 / 1000.0;
    *((double *)this + 12) = *((double *)this + 1);
    *((double *)this + 13) = *((double *)this + 2);
    *((double *)this + 1) = *((double *)this + 8) * v4 + *((double *)this + 1);
    *((double *)this + 2) = v4 * *((double *)this + 9) + *((double *)this + 2);
    if ( !CBall::CheckBoardBounds(this) )
    {
      CBall::AddRef(this);
      CheckForBallCollisionWithNonDeflectingTile(this);
      if ( (int)*((double *)this + 1) != (int)*((double *)this + 12)
        || (int)*((double *)this + 2) != (int)*((double *)this + 13) )
      {
        CheckForBallCollisionWithBall(this);
        CheckForBallCollisionWithInk(this);
        CheckForBallCollisionWithTile(this);
      }
      CBall::Release(this);
    }
  }
  v6 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
