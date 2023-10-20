#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/customisation/gccharactercustomisationcolourdata.meta.h>
#include <metadata/gamestate/customisation/gccharactercustomisationtextureoptiondata.meta.h>
#include <metadata/gamestate/customisation/gccharactercustomisationbonescaledata.meta.h>

class cGcCharacterCustomisationData
{
    static unsigned long long muNameHash = 0xBF5911FBC471448F;
    static unsigned long long muTemplateHash = 0xE5C56396D3246AA4;

    cTkDynamicArray<TkID<128>> maDescriptorGroups;
    cTkDynamicArray<cGcCharacterCustomisationColourData> maColours;
    cTkDynamicArray<cGcCharacterCustomisationTextureOptionData> maTextureOptions;
    cTkDynamicArray<cGcCharacterCustomisationBoneScaleData> maBoneScales;
    float mfScale;
}
