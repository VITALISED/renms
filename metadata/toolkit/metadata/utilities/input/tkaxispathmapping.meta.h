#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cTkAxisPathMapping
{
    static unsigned long long muNameHash = 0x19C4AA7DA3B42958;
    static unsigned long long muTemplateHash = 0x60587FED618E0B51;

    cTkInputAxisEnum Id;
    TkID<256> mName;
    cTkFixedString<128,char> macSolidIcon;
    cTkFixedString<128,char> macOverlayIcon;
    cTkFixedString<128,char> macSpecialIcon;
    cTkInputHandEnum Hand;
    cTkFixedString<32,char> macOpenVROriginNames;
}
