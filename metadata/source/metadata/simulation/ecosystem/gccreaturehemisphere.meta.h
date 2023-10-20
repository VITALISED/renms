#pragma once
#include <metadata/metadata_common.h>
enum eCreatureHemiSphere
{
    ECreatureHemiSphere_Any = 0,
    ECreatureHemiSphere_Northern = 1,
    ECreatureHemiSphere_Southern = 2,
}

class cGcCreatureHemiSphere
{
    static unsigned long long muNameHash = 0x1BE056BC4F556CAA;
    static unsigned long long muTemplateHash = 0xB74FEC78503E10A1;

    eCreatureHemiSphere CreatureHemiSphere;
}
