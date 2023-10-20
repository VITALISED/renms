#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureHarvestSubstanceList
{
    static unsigned long long muNameHash = 0xC8FD5EE28A99CF03;
    static unsigned long long muTemplateHash = 0xE886E62858AFB688;

    TkID<128> mCreatureType;
    TkID<128> mItem;
    cTkFixedString<128,char> macDesc;
    int miMinBlobs;
}
