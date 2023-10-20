#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tktextureresource.meta.h>

class cGcVehicleScanTableEntry
{
    static unsigned long long muNameHash = 0xBAC942D350F478B1;
    static unsigned long long muTemplateHash = 0x757E6C85353294DA;

    cTkDynamicArray<TkID<256>> maScanList;
    TkID<256> mName;
    TkID<128> mRequiredTech;
    cTkTextureResource Icon;
}
