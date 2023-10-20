#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cTkButtonPathMapping
{
    static unsigned long long muNameHash = 0xBC97B5A50FBB25EA;
    static unsigned long long muTemplateHash = 0x8365A040716E781C;

    cTkInputEnum Id;
    TkID<256> mName;
    cTkFixedString<128,char> macSolidIcon;
    cTkFixedString<128,char> macOverlayIcon;
    cTkFixedString<128,char> macSpecialIcon;
    cTkInputHandEnum Hand;
    cTkFixedString<32,char> macOpenVROriginNames;
}
