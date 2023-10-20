#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/data/tkinputenum.meta.h>

class cTkChordPathMapping
{
    static unsigned long long muNameHash = 0xA012CD9DA9418E41;
    static unsigned long long muTemplateHash = 0xBF2A55B37578B2B0;

    cTkDynamicArray<cTkInputEnum> maButtonIds;
    TkID<256> mName;
    TkID<128> mTextTag;
    cTkFixedString<128,char> macSolidIcon;
    cTkFixedString<128,char> macOverlayIcon;
    cTkFixedString<128,char> macSpecialIcon;
}
