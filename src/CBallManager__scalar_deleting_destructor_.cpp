//----- (0100806D) --------------------------------------------------------
void CBallManager::scalar_deleting_destructor(CBallManager *self, int flags)
{
  self->~CBallManager();
  if ( (flags & 1) != 0 )
    operator delete(self);
}
