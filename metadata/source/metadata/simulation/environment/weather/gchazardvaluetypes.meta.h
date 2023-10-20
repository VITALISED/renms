#pragma once
#include <metadata/metadata_common.h>
enum eHazardValue
{
    EHazardValue_Ambient = 0,
    EHazardValue_Water = 1,
    EHazardValue_Cave = 2,
    EHazardValue_Storm = 3,
    EHazardValue_Night = 4,
}

class cGcHazardValueTypes
{
    static unsigned long long muNameHash = 0x34F3A56DC1D3CE80;
    static unsigned long long muTemplateHash = 0xDBE375351057547B;

    eHazardValue HazardValue;
}
