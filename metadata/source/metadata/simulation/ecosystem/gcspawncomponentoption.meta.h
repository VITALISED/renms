#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/data/gcresourceelement.meta.h>

class cGcSpawnComponentOption
{
    static unsigned long long muNameHash = 0xA7EE5AECC28F3591;
    static unsigned long long muTemplateHash = 0x4A7AB9CCAC08262;

    TkID<128> mName;
    cTkSeed mSeed;
    cGcResourceElement SpecificModel;
}
