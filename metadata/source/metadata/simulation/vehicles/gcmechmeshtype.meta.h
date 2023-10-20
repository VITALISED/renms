#pragma once
#include <metadata/metadata_common.h>
enum eMechMeshType
{
    EMechMeshType_Exocraft = 0,
    EMechMeshType_Sentinel = 1,
}

class cGcMechMeshType
{
    static unsigned long long muNameHash = 0x86E6B8042A598341;
    static unsigned long long muTemplateHash = 0x6DD48563EABDB3FD;

    eMechMeshType MechMeshType;
}
