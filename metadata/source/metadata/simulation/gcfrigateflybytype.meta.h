#pragma once
#include <metadata/metadata_common.h>
enum eFrigateFlybyType
{
    EFrigateFlybyType_SingleShip = 0,
    EFrigateFlybyType_AmbientGroup = 1,
    EFrigateFlybyType_ScriptedGroup = 2,
    EFrigateFlybyType_DeepSpace = 3,
    EFrigateFlybyType_DeepSpaceCommon = 4,
}

class cGcFrigateFlybyType
{
    static unsigned long long muNameHash = 0x20BC4D823F8443DB;
    static unsigned long long muTemplateHash = 0x73ED7A3684434697;

    eFrigateFlybyType FrigateFlybyType;
}
