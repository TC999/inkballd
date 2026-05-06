void __thiscall CBallManager::AddBallGenerator(CBallManager *this, struct CBoardTile *a2)
{
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBallManager::AddBallGenerator", 0);
  *((_DWORD *)this + (*((_DWORD *)this + 20))++ + 21) = a2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
