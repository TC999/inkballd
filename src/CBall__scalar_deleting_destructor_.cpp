//----- (01004BC2) --------------------------------------------------------
void CBall::scalar_deleting_destructor(CBall* self, int flags)
{
  self->~CBall();
  if ( (flags & 1) != 0 )
    operator delete(self);
}
