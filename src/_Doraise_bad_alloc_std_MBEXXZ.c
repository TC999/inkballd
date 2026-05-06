void __thiscall __noreturn std::bad_alloc::_Doraise(std::bad_alloc *this)
{
  _BYTE pExceptionObject[12]; // [esp+0h] [ebp-Ch] BYREF

  std::bad_alloc::bad_alloc((std::bad_alloc *)pExceptionObject, this);
  _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
}
