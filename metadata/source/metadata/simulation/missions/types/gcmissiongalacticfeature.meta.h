#pragma once
#include <metadata/metadata_common.h>
enum eGalacticFeature
{
    EGalacticFeature_Anomaly = 0,
    EGalacticFeature_Atlas = 1,
    EGalacticFeature_BlackHole = 2,
}

class cGcMissionGalacticFeature
{
    static unsigned long long muNameHash = 0x60EEF97D074917CD;
    static unsigned long long muTemplateHash = 0xC98E74091146C414;

    eGalacticFeature GalacticFeature;
}
