#include <cstdint>

extern "C" {
    extern int _newmode;
    extern int _dowildcard;
    extern int unk_10D2F20;
    extern int unk_10D2F28;
    extern int unk_10D2F24;
    extern int dword_10D2F34;
    extern int dword_10D2F30;

    int pre_cpp_init()
    {
      int return_result; // eax

      dword_10D2F34 = _newmode;
      return_result = ___wgetmainargs(&unk_10D2F20, &unk_10D2F28, &unk_10D2F24, _dowildcard, &dword_10D2F34);
      dword_10D2F30 = return_result;
      return return_result;
    }
}
