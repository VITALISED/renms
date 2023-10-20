#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cTkAnimDetailSettings
{
    static unsigned long long muNameHash = 0x2FAF173AC809FC4C;
    static unsigned long long muTemplateHash = 0xED9F600E1FD8040;

    float mfMaxVisibleAngle;
    cTkDynamicArray<cTkAnimDetailSettingsData> maAnimDistanceSettings;
    cTkFixedArray<float> maAnimLODDistances;
}
