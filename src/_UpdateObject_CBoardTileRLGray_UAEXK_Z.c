void __thiscall CBoardTileRLGray::UpdateObject(CBoardTileRLGray *this, unsigned int a2)
{
  int v3; // eax
  int v4; // ecx
  unsigned int v5; // edx
  unsigned int v6; // ebx
  int v7; // ecx
  int v8; // eax
  _BYTE v9[8]; // [esp+10h] [ebp-18h] BYREF
  int v10; // [esp+18h] [ebp-10h]
  int v11; // [esp+24h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CBoardTileRLGray::UpdateObject", 0);
  *((_DWORD *)this + 22) += a2;
  *((_DWORD *)this + 23) += a2;
  v3 = *((_DWORD *)this + 24);
  v4 = *((_DWORD *)this + 18);
  v5 = *((_DWORD *)this + 22);
  v6 = *((_DWORD *)this + 23);
  v11 = 0;
  v10 = v4;
  if ( !v3 )
  {
    if ( v5 < *((_DWORD *)this + 26) )
    {
      if ( v4 > 0 && v6 > 0x32 )
      {
        v7 = v4 - 1;
LABEL_6:
        *((_DWORD *)this + 18) = v7;
LABEL_20:
        *((_DWORD *)this + 23) = 0;
        goto LABEL_21;
      }
      goto LABEL_21;
    }
    *((_DWORD *)this + 24) = 1;
LABEL_8:
    *((_DWORD *)this + 22) = 0;
    goto LABEL_21;
  }
  if ( v3 == 1 )
  {
    if ( v5 > *((_DWORD *)this + 25) )
    {
      *((_DWORD *)this + 24) = 0;
      goto LABEL_8;
    }
    if ( BallOnTile(this) )
      goto LABEL_21;
    *((_DWORD *)this + 24) = 2;
LABEL_19:
    *((_DWORD *)this + 22) = 0;
    goto LABEL_20;
  }
  if ( v5 >= *((_DWORD *)this + 25) )
  {
    *((_DWORD *)this + 24) = 0;
    goto LABEL_19;
  }
  if ( v4 < 4 && v6 > 0x32 )
  {
    v7 = v4 + 1;
    goto LABEL_6;
  }
LABEL_21:
  v8 = *((_DWORD *)this + 18);
  if ( v8 != v10 )
  {
    *((_DWORD *)this + 8) = GetBitmapRect(5 * v8 + 77);
    UpdateBoardTile(this);
    ShadowizeTile(this);
  }
  v11 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
}
