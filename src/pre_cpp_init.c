int pre_cpp_init()
{
  int result; // eax

  dword_10D2F34 = _newmode;
  result = ___wgetmainargs(&unk_10D2F20, &unk_10D2F28, &unk_10D2F24, _dowildcard, &dword_10D2F34);
  dword_10D2F30 = result;
  return result;
}
