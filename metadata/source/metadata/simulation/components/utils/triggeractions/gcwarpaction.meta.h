#pragma once
#include <metadata/metadata_common.h>
enum eWarpType
{
    EWarpType_BlackHole = 0,
    EWarpType_SpacePOI = 1,
}

class cGcWarpAction
{
    static unsigned long long muNameHash = 0x424B3146F5B3FC26;
    static unsigned long long muTemplateHash = 0xD317F3DAC107BDAA;

    eWarpType WarpType;
}
