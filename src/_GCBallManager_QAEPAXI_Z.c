CBallManager *__thiscall CBallManager::`scalar deleting destructor'(CBallManager *this, char a2)
{
  CBallManager::~CBallManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
