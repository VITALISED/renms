#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcbasebuildingpartaudiolocationentry.meta.h>

class cGcBaseBuildingPartAudioLocationTable
{
    static unsigned long long muNameHash = 0x6E17046D2670AB02;
    static unsigned long long muTemplateHash = 0xF51F2B3B7EA6080C;

    cTkDynamicArray<cGcBaseBuildingPartAudioLocationEntry> maAudioLocations;
}
