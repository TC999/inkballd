void __thiscall CBallManager::~CBallManager(CBallManager *this)
{
  CBall **v2; // esi
  int v3; // ebx
  _BYTE v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  *(_DWORD *)this = &CBallManager::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBallManager::~CBallManager", 0);
  v5 = 0;
  v2 = (CBall **)((char *)this + 56);
  v3 = 6;
  do
  {
    if ( *v2 )
    {
      CBall::Release(*v2);
      *v2 = 0;
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  v5 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
