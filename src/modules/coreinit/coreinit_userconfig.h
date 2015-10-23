#pragma once
#include "coreinit_ios.h"
#include "utils/structsize.h"

#pragma pack(push, 1)

namespace UCDataType
{
enum DataType : uint32_t
{
   Uint8 = 1,
   Uint32 = 3,
};
}

struct UCSysConfig
{
   char name[32];
   UNKNOWN(32);
   be_val<uint32_t> unk1; // access rights? 0x777
   be_val<uint32_t> dataType;
   be_val<uint32_t> unk3; // usually 0x00?
   be_val<uint32_t> dataSize;
   be_ptr<void> data;
};
CHECK_SIZE(UCSysConfig, 0x54);

#pragma pack(pop)

IOHandle
UCOpen();

void
UCClose(IOHandle handle);

IOError
UCReadSysConfig(IOHandle handle, uint32_t count, UCSysConfig *settings);
