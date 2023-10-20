#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcDifficultySettingCommonData
{
    static unsigned long long muNameHash = 0xA98FDB01046545AD;
    static unsigned long long muTemplateHash = 0xBDEDB2FA76A38658;

    cGcDifficultySettingType SettingType;
    bool mbIsAscendingDifficulty;
    cGcDifficultySettingEditability EditabilityInOptionsMenu;
    TkID<256> mTitleLocID;
    TkID<256> mDescriptionLocID;
    TkID<256> mToggleEnabledLocID;
    TkID<256> mToggleDisabledLocID;
}
