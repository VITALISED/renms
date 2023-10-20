#pragma once
#include <metadata/metadata_common.h>
enum eCreatureGroup
{
    ECreatureGroup_Solo = 0,
    ECreatureGroup_Couple = 1,
    ECreatureGroup_Group = 2,
    ECreatureGroup_Herd = 3,
}

class cGcCreatureGroups
{
    static unsigned long long muNameHash = 0xDC6AC60910C16B2D;
    static unsigned long long muTemplateHash = 0xA69F70739493EEEE;

    eCreatureGroup CreatureGroup;
}
