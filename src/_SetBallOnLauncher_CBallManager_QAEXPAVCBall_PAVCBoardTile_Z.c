void __thiscall CBallManager::SetBallOnLauncher(CBallManager *this, struct CBall *a2, struct CBoardTile *a3)
{
  int v4; // eax
  _BYTE v5[8]; // [esp+10h] [ebp-1Ch] BYREF
  struct tagPOINT v6; // [esp+18h] [ebp-14h] BYREF
  int v7; // [esp+28h] [ebp-4h]
  CBoardObject *v8; // [esp+38h] [ebp+Ch]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CBallManager::SetBallOnLauncher", 0);
  v7 = 0;
  if ( *((_DWORD *)this + 20) )
  {
    CBoardObject::GetCenterPoint(a3, &v6);
    v4 = *((_DWORD *)a2 + 6) / 2;
    v8 = (CBoardObject *)(v6.y - v4);
    *((double *)a2 + 1) = (double)(v6.x - v4);
    *((double *)a2 + 2) = (double)(int)v8;
  }
  v7 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
