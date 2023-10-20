#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/npcs/gcnpcinteractiveobjecttype.meta.h>
#include <metadata/simulation/npcs/gcnpcinteractiveobjectstate.meta.h>

class cGcNPCInteractiveObjectComponentData
{
    static unsigned long long muNameHash = 0x6EB308F16DDC755C;
    static unsigned long long muTemplateHash = 0xD5ECDD0A3503E78F;

    cGcNPCInteractiveObjectType InteractiveObjectType;
    int miMaxCapacity;
    float mfDurationMin;
    float mfDurationMax;
    cTkDynamicArray<cGcNPCInteractiveObjectState> maStates;
}
