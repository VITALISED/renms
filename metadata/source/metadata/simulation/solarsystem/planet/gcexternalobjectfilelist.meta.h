#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/planet/gcbiometype.meta.h>
#include <metadata/simulation/environment/gcexternalobjectlistoptions.meta.h>

class cGcExternalObjectFileList
{
    static unsigned long long muNameHash = 0x76D3572C2A9662D2;
    static unsigned long long muTemplateHash = 0x333FC04513700C76;

    TkID<128> mId;
    bool mbOnlyOnExtremeWeather;
    bool mbOnlyOnExtremeSentinels;
    bool mbOnlyOnDeepWater;
    bool mbNotOnExtremePlanets;
    bool mbNotOnStartPlanets;
    bool mbNotOnWeirdPlanets;
    bool mbNotOnDeadPlanets;
    bool mbForceOnSeasonStart;
    cGcBiomeType OnlyOnBiome;
    float mfProbabilityOfBeingActive;
    int miMinFilesToChoose;
    int miMaxFilesToChoose;
    cTkDynamicArray<cGcExternalObjectListOptions> maExternalObjectFiles;
}
