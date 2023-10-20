#pragma once
#include <metadata/metadata_common.h>

class cGcAntagonistFriend
{
    static unsigned long long muNameHash = 0xFA881469CD77285D;
    static unsigned long long muTemplateHash = 0x489F643D466C0D63;

    float mfArticulationFactor;
    cTkDynamicArray<TkID<128>> maPerceptions;
}
