#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcHazardAction
{
    static unsigned long long muNameHash = 0x2FCEFF0AE05742C0;
    static unsigned long long muTemplateHash = 0xF973957877E0F6AF;

    cGcPlayerHazardType Hazard;
    float mfStrength;
    float mfRadius;
    bool mbRadiusBasedStrength;
}
