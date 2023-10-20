#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eInputActionInfoFlags
{
    EInputActionInfoFlags_HideInControlsPage = 1,
    EInputActionInfoFlags_HideInMenusMenu = 2,
    EInputActionInfoFlags_OnlyVR = 4,
    EInputActionInfoFlags_OnlyNonVR = 8,
    EInputActionInfoFlags_None = 0,
}

class cGcInputActionInfo
{
    static unsigned long long muNameHash = 0x793BE7AABA010DFF;
    static unsigned long long muTemplateHash = 0xE47ED0B56D1E65A0;

    bool mbAnalogue;
    cGcInputActions Pairing;
    cTkFixedString<128,char> macTextTag;
    TkID<256> mLocTag;
    TkID<256> mConsoleLocTag;
    cTkFixedString<128,char> macSolidIcon;
    cTkFixedString<128,char> macOverlayIcon;
    cTkFixedString<128,char> macSpecialIcon;
    cTkFixedString<32,char> macExternalId;
    cTkFixedString<32,char> macExternalLoc;
    cTkFixedString<32,char> macExternalDigitalAliasId;
    eInputActionInfoFlags InputActionInfoFlags;
}
