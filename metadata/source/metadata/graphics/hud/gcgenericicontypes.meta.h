#pragma once
#include <metadata/metadata_common.h>
enum eGenericIconType
{
    EGenericIconType_None = 0,
    EGenericIconType_Interaction = 1,
    EGenericIconType_SpaceStation = 2,
    EGenericIconType_SpaceAnomaly = 3,
    EGenericIconType_SpaceAtlas = 4,
    EGenericIconType_Nexus = 5,
}

class cGcGenericIconTypes
{
    static unsigned long long muNameHash = 0xA4091406380F5113;
    static unsigned long long muTemplateHash = 0xC364E4B5E5B16679;

    eGenericIconType GenericIconType;
}
