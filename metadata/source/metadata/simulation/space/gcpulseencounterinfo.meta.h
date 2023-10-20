#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcPulseEncounterInfo
{
    static unsigned long long muNameHash = 0x657592AF71342449;
    static unsigned long long muTemplateHash = 0x6AF8B9AA06A1B81B;

    TkID<128> mId;
    TkID<256> mMarkerLabel;
    TkID<256> mChatMessageName;
    cTkTextureResource MarkerIcon;
    TkID<256> mCustomNotify;
    TkID<256> mCustomNotifyTitle;
    TkID<256> mCustomNotifyOSD;
    bool mbUseMarkerIconInOSD;
    cGcPulseEncounterSpawnConditions SpawnConditions;
    float mfSpawnChance;
    float mfSpawnDistance;
    cGcAudioWwiseEvents AudioEvent;
    bool mbSilent;
    cTkClassPointer mEncounter;
}
