#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/character/gccharacterjetpackeffect.meta.h>
#include <metadata/simulation/character/gcplayercontrolmodeentry.meta.h>

class cGcPlayerCharacterComponentData
{
    static unsigned long long muNameHash = 0xE8C3B2237C130170;
    static unsigned long long muTemplateHash = 0x60495EA305E0B504;

    cTkDynamicArray<cGcCharacterJetpackEffect> maJetpackEffects;
    TkID<128> mIntialPlayerControlMode;
    cTkDynamicArray<cGcPlayerControlModeEntry> maPlayerControlModes;
}
