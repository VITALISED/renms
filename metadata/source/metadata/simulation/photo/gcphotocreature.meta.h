#pragma once
#include <metadata/metadata_common.h>
enum ePhotoCreatureType
{
    EPhotoCreatureType_Ground = 0,
    EPhotoCreatureType_Water = 1,
    EPhotoCreatureType_Air = 2,
}

class cGcPhotoCreature
{
    static unsigned long long muNameHash = 0xA08BAAFBA2B1F0C1;
    static unsigned long long muTemplateHash = 0xDFD13BEA7BB1992F;

    ePhotoCreatureType PhotoCreatureType;
}
