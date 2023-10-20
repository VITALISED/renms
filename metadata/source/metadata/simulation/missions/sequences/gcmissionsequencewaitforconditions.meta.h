#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcMissionSequenceWaitForConditions
{
    static unsigned long long muNameHash = 0x677779252EE27773;
    static unsigned long long muTemplateHash = 0xBA4ADED1901B82DD;

    cTkFixedString<128,char> macMessage;
    cGcMissionConditionTest ConditionTest;
    cTkDynamicArray<cTkClassPointer> maConditions;
    bool mbAllowedToFormatObjectives;
    bool mbForceAllowMissionRestart;
    TkID<256> mForceAllowMissionRestartEvent;
    cTkFixedString<128,char> macDebugText;
    cGcStatusMessageMissionMarkup StatusMessageMissionMarkup;
}
