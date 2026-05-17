//----- (0100866F) --------------------------------------------------------
int CGameBoard::BallOnTile(CGameBoard *self, struct CBoardTile *a2)
{
  int v3; // ebx
  CBoardObject **v4; // edi
  int v5; // esi
  struct tagRECT v7; // [esp+10h] [ebp-34h] BYREF
  struct tagRECT v8; // [esp+20h] [ebp-24h] BYREF
  _BYTE v9[16]; // [esp+30h] [ebp-14h] BYREF
  int v10; // [esp+40h] [ebp-4h]

  v3 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CGameBoard::BallOnTile", 0);
  v10 = 0;
  CBoardObject::GetBoundingRect(a2, &v8);
  if ( *((int *)self + 656) <= 0 )
  {
LABEL_6:
    v5 = 0;
  }
  else
  {
    v4 = (CBoardObject **)((char *)self + 2628);
    while ( 1 )
    {
      if ( *((_DWORD *)*v4 + 39) )
      {
        CBoardObject::GetBoundingRect(*v4, &v7);
        if ( RectIntersectsRect(&v7, &v8) )
          break;
      }
      ++v3;
      ++v4;
      if ( v3 >= *((_DWORD *)self + 656) )
        goto LABEL_6;
    }
    v5 = 1;
  }
  v10 = -1;
  ((Helpers::CLogBlock *)v9)->~CLogBlock();
  return v5;
}
