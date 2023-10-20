#pragma once
#include <metadata/metadata_common.h>
enum eBuildMenuOption
{
    EBuildMenuOption_Place = 0,
    EBuildMenuOption_ChangeColour = 1,
    EBuildMenuOption_FreeRotate = 2,
    EBuildMenuOption_Scale = 3,
    EBuildMenuOption_SnapRotate = 4,
    EBuildMenuOption_Move = 5,
    EBuildMenuOption_Duplicate = 6,
    EBuildMenuOption_Delete = 7,
    EBuildMenuOption_ToggleBuildCam = 8,
    EBuildMenuOption_ToggleSnappingAndCollision = 9,
    EBuildMenuOption_ToggleSelectionMode = 10,
    EBuildMenuOption_ToggleWiringMode = 11,
    EBuildMenuOption_ViewRelatives = 12,
    EBuildMenuOption_CyclePart = 13,
    EBuildMenuOption_PlaceWire = 14,
    EBuildMenuOption_CycleRotateMode = 15,
}

class cGcBuildMenuOption
{
    static unsigned long long muNameHash = 0xCF846F604521AD4F;
    static unsigned long long muTemplateHash = 0x655CD9EAB6B8C9B5;

    eBuildMenuOption BuildMenuOption;
}
