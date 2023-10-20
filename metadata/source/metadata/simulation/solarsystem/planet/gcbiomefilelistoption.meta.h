#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/planet/gcbiomesubtype.meta.h>

class cGcBiomeFileListOption
{
    static unsigned long long muNameHash = 0xA1666CAA6E88F270;
    static unsigned long long muTemplateHash = 0x70DC795EA39D0AA1;

    cGcBiomeSubType SubType;
    cTkFixedString<128,char> macFilename;
    float mfWeight;
}
