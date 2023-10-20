#pragma once
#include <metadata/metadata_common.h>
enum eMechMeshPart
{
    EMechMeshPart_Scanner = 0,
    EMechMeshPart_Body = 1,
    EMechMeshPart_Legs = 2,
    EMechMeshPart_LeftArm = 3,
    EMechMeshPart_RightArm = 4,
}

class cGcMechMeshPart
{
    static unsigned long long muNameHash = 0x78242DA1B96F48FC;
    static unsigned long long muTemplateHash = 0x9DE40488BE597ACC;

    eMechMeshPart MechMeshPart;
}
