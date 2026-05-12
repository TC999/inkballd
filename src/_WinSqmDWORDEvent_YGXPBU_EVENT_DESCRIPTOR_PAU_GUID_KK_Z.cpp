#include "global_types.h"
#include <cstdint>
#include <windows.h>

// [TODO] Minimal EVENT_DESCRIPTOR definition - verify layout matches Windows SDK evntprov.h
struct EVENT_DESCRIPTOR {
    unsigned short Id;
    unsigned char  Version;
    unsigned char  Channel;
    unsigned char  Level;
    unsigned char  Opcode;
    unsigned short Task;
    unsigned long long Keyword;
};

// [TODO] Stub WinSQM functions - these are never called due to WinSqmIsOptedIn() returning 0
extern "C" {
    BOOL __stdcall WinSqmEventEnabled(const EVENT_DESCRIPTOR* event_desc, const GUID* guid);
    HRESULT __stdcall WinSqmEventWrite(const EVENT_DESCRIPTOR* event_desc, unsigned short dataCount, uint64_t* data);
    extern GUID unk_105C840;
}

extern "C" {
    void __stdcall _WinSqmDWORDEvent(const EVENT_DESCRIPTOR* event_desc, GUID* guid, char param1, char param2)
    {
      GUID* target_guid; // eax
      uint64_t data_buffer[6]; // [esp+8h] [ebp-30h] BYREF

      memset(data_buffer, 0, sizeof(data_buffer));
      if (WinSqmEventEnabled(event_desc, guid))
      {
        target_guid = guid;
        if (!guid)
          target_guid = (GUID*)&unk_105C840;
        data_buffer[0] = (uint64_t)(uintptr_t)target_guid;
        data_buffer[2] = (uint64_t)(uintptr_t)&param1;
        data_buffer[4] = (uint64_t)(uintptr_t)&param2;
        data_buffer[1] = 16;
        data_buffer[3] = 4;
        data_buffer[5] = 4;
        WinSqmEventWrite(event_desc, 3, data_buffer);
      }
    }
}
