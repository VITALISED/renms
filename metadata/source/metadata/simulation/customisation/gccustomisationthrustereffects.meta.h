#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/customisation/gccustomisationthrustereffect.meta.h>
#include <metadata/simulation/customisation/gccustomisationbackpackdata.meta.h>
#include <metadata/simulation/customisation/gccustomisationshiptrails.meta.h>
#include <metadata/simulation/customisation/gccustomisationfreighterengineeffect.meta.h>

class cGcCustomisationThrusterEffects
{
    static unsigned long long muNameHash = 0xFD3FA61F96564C04;
    static unsigned long long muTemplateHash = 0xB4ACBB424E77732B;

    cTkDynamicArray<cGcCustomisationThrusterEffect> maJetpackEffects;
    cTkDynamicArray<cGcCustomisationBackpackData> maBackpackData;
    cTkDynamicArray<cGcCustomisationShipTrails> maShipEffects;
    cTkDynamicArray<cGcCustomisationFreighterEngineEffect> maFreighterEngineEffects;
}
