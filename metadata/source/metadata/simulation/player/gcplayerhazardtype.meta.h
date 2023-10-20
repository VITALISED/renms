#pragma once
#include <metadata/metadata_common.h>
enum eHazard
{
    EHazard_None = 0,
    EHazard_NoOxygen = 1,
    EHazard_ExtremeHeat = 2,
    EHazard_ExtremeCold = 3,
    EHazard_ToxicGas = 4,
    EHazard_Radiation = 5,
}

class cGcPlayerHazardType
{
    static unsigned long long muNameHash = 0x9699B119759C861B;
    static unsigned long long muTemplateHash = 0xF8CE0E13EB01EA06;

    eHazard Hazard;
}
