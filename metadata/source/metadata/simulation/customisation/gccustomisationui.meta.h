#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/customisation/gccustomisationcameradata.meta.h>
#include <metadata/simulation/customisation/gccustomisationrace.meta.h>
#include <metadata/simulation/customisation/gccustomisationgroups.meta.h>

class cGcCustomisationUI
{
    static unsigned long long muNameHash = 0x9391BB23A2DA934;
    static unsigned long long muTemplateHash = 0x37661AA774E72C52;

    cGcCustomisationCameraData RacesCameraData;
    cTkDynamicArray<cGcCustomisationRace> maRaces;
    cGcCustomisationGroups Common;
}
