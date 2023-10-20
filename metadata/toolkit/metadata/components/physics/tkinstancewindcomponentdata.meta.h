#pragma once
#include <metadata/metadata_common.h>

class cTkInstanceWindComponentData
{
    static unsigned long long muNameHash = 0xE02A1CA9048E3A96;
    static unsigned long long muTemplateHash = 0x8E9D85406F8942E4;

    bool mbEnableLdsWind;
    float mfBaseMass;
    float mfMassReduction;
    float mfBaseSpring;
    float mfSpringReduction;
    float mfLinearDamping;
    float mfSpringNonDirFactor;
    float mfSpringLengthFactor;
}
