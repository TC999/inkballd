//----- (01004C37) --------------------------------------------------------
void CBall::UpdateObject(CBall* self, unsigned int a2)
{
  bool v3; // zf
  double v4; // st7
  _BYTE v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CBall::UpdateObject", 0);
  v3 = *((_DWORD *)self + 39) == 0;
  v6 = 0;
  if ( !v3 )
  {
    v4 = (double)a2 / 1000.0;
    *((double *)self + 12) = *((double *)self + 1);
    *((double *)self + 13) = *((double *)self + 2);
    *((double *)self + 1) = *((double *)self + 8) * v4 + *((double *)self + 1);
    *((double *)self + 2) = v4 * *((double *)self + 9) + *((double *)self + 2);
    if ( !CBall::CheckBoardBounds(self) )
    {
      CBall::AddRef(self);
      CheckForBallCollisionWithNonDeflectingTile(self);
      if ( (int)*((double *)self + 1) != (int)*((double *)self + 12)
        || (int)*((double *)self + 2) != (int)*((double *)self + 13) )
      {
        CheckForBallCollisionWithBall(self);
        CheckForBallCollisionWithInk(self);
        CheckForBallCollisionWithTile(self);
      }
      CBall::Release(self);
    }
  }
  v6 = -1;
  ((Helpers::CLogBlock *)v5)->~CLogBlock();
}
