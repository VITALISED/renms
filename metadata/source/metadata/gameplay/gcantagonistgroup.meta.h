#pragma once
#include <metadata/metadata_common.h>
enum eAntagonistGroup
{
    EAntagonistGroup_Player = 0,
    EAntagonistGroup_Fiends = 1,
    EAntagonistGroup_Creatures = 2,
    EAntagonistGroup_Sentinels = 3,
    EAntagonistGroup_Turrets = 4,
    EAntagonistGroup_Walls = 5,
}

class cGcAntagonistGroup
{
    static unsigned long long muNameHash = 0x39B4070AE5C76F6F;
    static unsigned long long muTemplateHash = 0x389DCB7F89EAC210;

    eAntagonistGroup AntagonistGroup;
}
