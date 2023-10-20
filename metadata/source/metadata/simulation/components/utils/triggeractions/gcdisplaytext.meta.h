#pragma once
#include <metadata/metadata_common.h>
enum eHUDTextDisplayType
{
    EHUDTextDisplayType_Full = 0,
    EHUDTextDisplayType_Compact = 1,
    EHUDTextDisplayType_EyeLevel = 2,
    EHUDTextDisplayType_Prompt = 3,
    EHUDTextDisplayType_Tooltip = 4,
}
#include <?>

class cGcDisplayText
{
    static unsigned long long muNameHash = 0x39E3C3DE16466069;
    static unsigned long long muTemplateHash = 0xD668510B347FF09D;

    eHUDTextDisplayType HUDTextDisplayType;
    cTkFixedString<256,char> macTitle;
    cTkFixedString<256,char> macSubtitle1;
    cTkFixedString<256,char> macSubtitle2;
    cGcAlienRace UseAlienLanguage;
    cTkDynamicArray<TkID<256>> maChooseRandomTextOptions;
}
