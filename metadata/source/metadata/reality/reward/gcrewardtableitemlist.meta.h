#pragma once
#include <metadata/metadata_common.h>
enum eRewardChoice
{
    ERewardChoice_GiveAll = 0,
    ERewardChoice_Select = 1,
    ERewardChoice_SelectAlways = 2,
    ERewardChoice_TryEach = 3,
    ERewardChoice_SelectSilent = 4,
    ERewardChoice_GiveAllSilent = 5,
    ERewardChoice_TryFirst_ThenSelectAlways = 6,
    ERewardChoice_SelectFromSuccess = 7,
    ERewardChoice_SelectAlwaysSilent = 8,
    ERewardChoice_SelectFromSuccessSilent = 9,
}
#include <?>

class cGcRewardTableItemList
{
    static unsigned long long muNameHash = 0xF97DB1C704357E47;
    static unsigned long long muTemplateHash = 0xECD3D5DCA792D16;

    eRewardChoice RewardChoice;
    bool mbOverrideZeroSeed;
    bool mbUseInventoryChoiceOverride;
    cTkDynamicArray<cGcRewardTableItem> maList;
}
