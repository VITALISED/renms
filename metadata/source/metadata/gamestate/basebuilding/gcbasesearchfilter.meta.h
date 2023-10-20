#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcBaseSearchFilter
{
    static unsigned long long muNameHash = 0x53636362EAB448BF;
    static unsigned long long muTemplateHash = 0xB3DC3F536A016394;

    bool mbOnCurrentPlanet;
    bool mbInCurrentSystem;
    bool mbIsOverlapping;
    bool mbIsBuildable;
    unsigned long long mui64OnSpecificPlanet;
    unsigned long long mui64InSpecificSystem;
    TkID<256> mOnSpecificPlanetScanEvent;
    cTkDynamicArray<cGcPersistentBaseTypes> maMatchingTypes;
    cGcBasePartSearchFilter BasePartFilter;
    int miContainsMinParts;
    int miContainsMaxParts;
}
