#pragma once
#include <metadata/metadata_common.h>
enum eBasePartAudioLocation
{
    EBasePartAudioLocation_None = 0,
    EBasePartAudioLocation_Freighter_SpaceWalk = 1,
    EBasePartAudioLocation_Freighter_BioRoom = 2,
    EBasePartAudioLocation_Freighter_TechRoom = 3,
    EBasePartAudioLocation_Freighter_IndustrialRoom = 4,
}

class cGcBasePartAudioLocation
{
    static unsigned long long muNameHash = 0x832159F5794C47D5;
    static unsigned long long muTemplateHash = 0x2E789F51CF31C9D9;

    eBasePartAudioLocation BasePartAudioLocation;
}
