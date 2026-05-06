void __thiscall CBoardTileRLColored::UpdateObject(CBoardTileRLColored *this, unsigned int a2)
{
  int v3; // ecx
  int v4; // eax
  unsigned int v5; // edx
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  _BYTE v9[16]; // [esp+10h] [ebp-14h] BYREF
  int v10; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CBoardTileRLColored::UpdateObject", 0);
  *((_DWORD *)this + 22) += a2;
  v3 = *((_DWORD *)this + 23);
  v4 = *((_DWORD *)this + 18);
  v5 = *((_DWORD *)this + 22);
  v10 = 0;
  v6 = v4;
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      if ( BallOnTile(this) )
        goto LABEL_13;
      *((_DWORD *)this + 23) = 2;
      goto LABEL_12;
    }
    if ( v4 < 4 && v5 > 0x32 )
    {
      v7 = v4 + 1;
      goto LABEL_11;
    }
  }
  else if ( v4 > 0 && v5 > 0x32 )
  {
    v7 = v4 - 1;
LABEL_11:
    *((_DWORD *)this + 18) = v7;
LABEL_12:
    *((_DWORD *)this + 22) = 0;
  }
LABEL_13:
  v8 = *((_DWORD *)this + 18);
  if ( v8 != v6 )
  {
    *((_DWORD *)this + 8) = GetBitmapRect(5 * v8 + *((_DWORD *)this + 11) + 77);
    UpdateBoardTile(this);
    ShadowizeTile(this);
  }
  v10 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
}
