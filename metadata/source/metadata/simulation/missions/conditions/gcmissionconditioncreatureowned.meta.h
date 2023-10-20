#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tkequalityenum.meta.h>

class cGcMissionConditionCreatureOwned
{
    static unsigned long long muNameHash = 0x1518FAA28FFA87F7;
    static unsigned long long muTemplateHash = 0x32BC54A99584B86E;

    int miAmount;
    cTkEqualityEnum Test;
    TkID<128> mSpecificCreatureID;
    bool mbAnyPredator;
}
