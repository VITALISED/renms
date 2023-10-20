#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cTkNoiseFlattenPoint
{
    static unsigned long long muNameHash = 0xCE87D0159308C03A;
    static unsigned long long muTemplateHash = 0xCD402697FFDFC91B;

    float mfDensity;
    float mfFlattenRadius;
    float mfTurbulenceFrequency;
    float mfTurbulenceAmplitude;
    int miTurbulenceOctaves;
    cTkNoiseFlattenOptions FlattenType;
    int miClassification;
    int miPlacement;
    bool mbAddWaypoint;
    bool mbAddShelter;
    bool mbAddLandingPad;
}
