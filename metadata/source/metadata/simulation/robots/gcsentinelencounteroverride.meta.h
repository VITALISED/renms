#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcSentinelEncounterOverride
{
    static unsigned long long muNameHash = 0x858F65761E6CEB71;
    static unsigned long long muTemplateHash = 0xDF0554595188CB5B;

    TkID<128> mId;
    float mfSummonRadius;
    TkID<128> mSpawnID;
    TkID<128> mExtremeSpawnID;
    bool mbSpawnsAreAggressive;
    bool mbEncounterBlocksWantedSpawns;
    bool mbEncounterClearsWantedOnDefeat;
    bool mbIgnoreBuildingCrimesOnDefeat;
    TkID<256> mOSDMessage;
    TkID<256> mOSDOnDefeat;
    TkID<256> mOSDOnWaveStart;
    cGcAudioWwiseEvents OSDOnWaveStartAudio;
    bool mbUseCustomOSDIcon;
    cGcRealityGameIcons CustomOSDIcon;
    TkID<128> mStatusMessage;
    bool mbUseEncounterTypeOverride;
    cGcEncounterType EncounterTypeOverride;
}
