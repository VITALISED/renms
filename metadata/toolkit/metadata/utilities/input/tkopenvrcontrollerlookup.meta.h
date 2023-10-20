#pragma once
#include <metadata/metadata_common.h>

class cTkOpenVRControllerLookup
{
    static unsigned long long muNameHash = 0x5AFD5621E9999DDA;
    static unsigned long long muTemplateHash = 0x865DC7F91B663645;

    cTkFixedString<32,char> macDeviceKeywords;
    cTkFixedString<128,char> macDeviceSpec;
    TkID<128> mResetVRViewLayerName;
}
