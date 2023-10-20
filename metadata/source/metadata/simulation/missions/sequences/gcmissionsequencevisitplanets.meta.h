#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/planet/gcbiometype.meta.h>

class cGcMissionSequenceVisitPlanets
{
    static unsigned long long muNameHash = 0xA6EC06362FCAD424;
    static unsigned long long muTemplateHash = 0xFD0F5CEB9C4534CA;

    cTkFixedString<128,char> macMessage;
    cTkDynamicArray<cGcBiomeType> maPlanetTypesToWatch;
    bool mbMustAlsoDiscover;
    int miNumberOfEachToDiscover;
    bool mbTakeNumberFromSeasonalData;
    cTkFixedString<128,char> macDebugText;
}
