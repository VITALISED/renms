#pragma once
#include <metadata/metadata_common.h>

class cTkSceneNodeAttributeData
{
    static unsigned long long muNameHash = 0x502F1C3425CDC8EC;
    static unsigned long long muTemplateHash = 0x3584805A4D182B6F;

    TkID<128> mName;
    TkID<256> mAltID;
    cTkFixedString<256,char> macValue;
}
