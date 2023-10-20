#pragma once
#include <metadata/metadata_common.h>

class cGcHUDMarkerData
{
    static unsigned long long muNameHash = 0x73308053CF12ECFF;
    static unsigned long long muTemplateHash = 0xA4159AB1AA0D170A;

    cTkFixedString<128,char> macIcon;
    cTkFixedString<128,char> macIconBehind;
    cTkFixedString<128,char> macDistance;
}
