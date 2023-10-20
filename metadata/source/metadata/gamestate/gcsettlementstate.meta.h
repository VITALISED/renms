#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcSettlementState
{
    static unsigned long long muNameHash = 0x92FAA41D8355CBAE;
    static unsigned long long muTemplateHash = 0xCAB79D64D31E12D5;

    cTkFixedString<64,char> macUniqueId;
    unsigned long long mui64UniverseAddress;
    cTkVector3 mPosition;
    unsigned long long mui64SeedValue;
    cTkFixedArray<int> maBuildingStates;
    cTkFixedArray<unsigned long long> maLastBuildingUpgradesTimestamps;
    cTkFixedString<64,char> macName;
    cGcDiscoveryOwner Owner;
    cGcSettlementJudgementType PendingJudgementType;
    TkID<128> mPendingCustomJudgementID;
    cTkFixedArray<int> maStats;
    cTkDynamicArray<TkID<128>> maPerks;
    unsigned long long mui64LastJudgementTime;
    unsigned long long mui64LastUpkeepDebtCheckTime;
    unsigned long long mui64LastDebtChangeTime;
    unsigned long long mui64LastAlertChangeTime;
    cTkFixedString<64,char> macDbResourceId;
    unsigned long long mui64DbTimestamp;
    int miDbVersion;
    cTkFixedArray<cGcSettlementProductionSlotData> maProductionState;
    bool mbIsReported;
    int miNextBuildingUpgradeIndex;
    cGcBuildingClassification NextBuildingUpgradeClass;
    unsigned long long mui64NextBuildingUpgradeSeedValue;
}
