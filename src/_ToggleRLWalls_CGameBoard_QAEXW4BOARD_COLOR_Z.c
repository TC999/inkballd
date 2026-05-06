void __thiscall CGameBoard::ToggleRLWalls(CBoardTileRLColored **this, int a2)
{
  int v3; // ebx
  bool v4; // cc
  CBoardTileRLColored **v5; // edi
  _BYTE v6[16]; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CGameBoard::ToggleRLWalls", 0);
  v3 = 0;
  v4 = (int)this[366] <= 0;
  v7 = 0;
  if ( !v4 )
  {
    v5 = this + 367;
    do
    {
      if ( *((_DWORD *)*v5 + 11) == a2 )
        CBoardTileRLColored::ToggleState(*v5);
      ++v3;
      ++v5;
    }
    while ( v3 < (int)this[366] );
  }
  v7 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
}
