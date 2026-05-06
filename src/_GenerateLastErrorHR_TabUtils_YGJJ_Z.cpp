TabUtils *__stdcall TabUtils::GenerateLastErrorHR(TabUtils *this, int a2)
{
  TabUtils *result; // eax
  bool v3; // sf

  result = (TabUtils *)GetLastError();
  v3 = (int)result < 0;
  if ( (int)result > 0 )
  {
    result = (TabUtils *)((unsigned __int16)result | 0x80070000);
    v3 = (int)result < 0;
  }
  if ( !v3 )
    return this;
  return result;
}
