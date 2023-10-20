#pragma once
#include <metadata/metadata_common.h>

class cGcCustomisationDescriptorGroup
{
    static unsigned long long muNameHash = 0x80953B08573D31B6;
    static unsigned long long muTemplateHash = 0x8E931346CFC5A9A5;

    TkID<128> mGroupID;
    TkID<256> mTitle;
    cTkFixedString<128,char> macImage;
    cTkDynamicArray<cTkFixedString<32,char>> maDescriptors;
    cTkDynamicArray<cTkFixedString<32,char>> maSuffixInclusionList;
    TkID<128> mLinkedSpecialID;
    TkID<256> mTip;
    bool mbHiddenInCustomiser;
}
