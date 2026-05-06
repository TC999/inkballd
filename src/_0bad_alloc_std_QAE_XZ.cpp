std::bad_alloc *__thiscall std::bad_alloc::bad_alloc(std::bad_alloc *this)
{
  bool v2; // zf

  exception::exception(this);
  v2 = *((_DWORD *)this + 1) == 0;
  *(_DWORD *)this = &std::bad_alloc::`vftable';
  if ( v2 && !*((_DWORD *)this + 2) )
    *((char **)this + 1) = off_101704C[0];
  return this;
}
