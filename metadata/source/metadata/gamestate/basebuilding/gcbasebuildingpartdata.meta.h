#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcBaseBuildingPartData
{
    static unsigned long long muNameHash = 0x4F6F7504AD1EBFFC;
    static unsigned long long muTemplateHash = 0x7744F71486CD147D;

    TkID<256> mPartID;
    cGcBaseBuildingPartStyle Style;
    cTkMagicModelData MagicData;
    unsigned int muiNodesCost;
    unsigned int muiTimeCost;
    unsigned int muiPhysicsCost;
    unsigned int muiMeshesCost;
    unsigned int muiInstanceNodesCost;
    unsigned int muiInstanceTimeCost;
    unsigned int muiInstanceMeshesCost;
    unsigned long long mui64LastProfiledTimestamp;
    unsigned long long mui64InstanceLastProfiledTimestamp;
}
