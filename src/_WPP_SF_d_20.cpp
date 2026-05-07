#include <cstdint>

extern "C" {
    uint32_t __stdcall WPP_SF_d(TRACEHANDLE logger_handle, uint16_t message_number, const GUID* message_guid, char data)
    {
      return TraceMessage(logger_handle, 0x2Bu, message_guid, message_number, &data, 4, 0);
    }
}
