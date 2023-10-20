#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/behaviours/data/gccreatureiktype.meta.h>
#include <metadata/simulation/player/gcplayercharacterikoverridedata.meta.h>
#include <metadata/simulation/player/gcplayercharacterikstatedata.meta.h>

class cGcIKConstraint
{
    static unsigned long long muNameHash = 0x9A9B4993026AA411;
    static unsigned long long muTemplateHash = 0x6D52BE7161729552;

    TkID<128> mId;
    cTkFixedString<256,char> macJointName;
    cGcCreatureIkType Type;
    cGcPlayerCharacterIKOverrideData DefaultState;
    cTkDynamicArray<cGcPlayerCharacterIKStateData> maStates;
}
