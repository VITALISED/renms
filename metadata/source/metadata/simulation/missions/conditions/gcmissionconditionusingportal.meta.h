#pragma once
#include <metadata/metadata_common.h>
enum ePortalType
{
    EPortalType_Any = 0,
    EPortalType_Story = 1,
    EPortalType_NotStory = 2,
}

class cGcMissionConditionUsingPortal
{
    static unsigned long long muNameHash = 0x93D7C024B58A671;
    static unsigned long long muTemplateHash = 0xC578ECEEBCAAE131;

    ePortalType PortalType;
}
