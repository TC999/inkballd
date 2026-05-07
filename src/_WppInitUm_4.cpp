#include <cstdint>
#include <windows.h>

extern "C" {
    uint32_t __stdcall WppInitUm(int unused_param)
    {
      uint64_t* control_ptr; // esi
      const GUID** guid_ptr; // edi
      const GUID* current_guid; // eax
      uint32_t result; // eax
      TRACE_GUID_REGISTRATION trace_guid_reg; // [esp+8h] [ebp-8h] BYREF

      control_ptr = reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control);
      guid_ptr = reinterpret_cast<const GUID**>(&WPP_REGISTRATION_GUIDS);
      while (control_ptr)
      {
        current_guid = *guid_ptr;
        trace_guid_reg.RegHandle = 0;
        ++guid_ptr;
        trace_guid_reg.Guid = current_guid;
        result = RegisterTraceGuidsW(reinterpret_cast<WMIDPREQUEST>(WppControlCallback), control_ptr, current_guid, 1u, &trace_guid_reg, 0, 0, control_ptr + 1);
        control_ptr = *reinterpret_cast<uint64_t**>(control_ptr);
      }
      return result;
    }
}
