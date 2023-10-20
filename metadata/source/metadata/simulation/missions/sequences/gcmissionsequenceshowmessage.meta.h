#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
enum eOSDMessageStyle
{
    EOSDMessageStyle_Standard = 0,
    EOSDMessageStyle_Fancy = 1,
    EOSDMessageStyle_Stats = 2,
    EOSDMessageStyle_Settlement = 3,
}

class cGcMissionSequenceShowMessage
{
    static unsigned long long muNameHash = 0xECE8B28E154961E9;
    static unsigned long long muTemplateHash = 0x3CEFDBC5D500634;

    cGcMissionCategory Category;
    float mfTime;
    cTkFixedString<128,char> macMessage;
    cGcAudioWwiseEvents AudioEvent;
    float mfOSDTime;
    cTkFixedString<128,char> macOSDMessage;
    cTkFixedString<128,char> macOSDMessageSubtitle;
    cTkColour mOSDMessageColour;
    eOSDMessageStyle OSDMessageStyle;
    bool mbOSDUseMissionIcon;
    bool mbDisableIcon;
    bool mbDisableTitlePrefix;
    cTkDynamicArray<cTkClassPointer> maUseConditionsForTextFormatting;
    cTkFixedString<128,char> macDebugText;
}
