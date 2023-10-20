#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/gcfrigateflybytype.meta.h>
#include <metadata/simulation/gcfrigateflybyoption.meta.h>

class cGcFrigateFlybyLayout
{
    static unsigned long long muNameHash = 0xB1B9570C76B5EA49;
    static unsigned long long muTemplateHash = 0xD44EF10C0EADCEC5;

    cGcFrigateFlybyType FlybyType;
    float mfInitialSpeed;
    float mfTargetSpeed;
    float mfInterestTime;
    float mfInterestDistance;
    cTkDynamicArray<cGcFrigateFlybyOption> maFrigates;
}
