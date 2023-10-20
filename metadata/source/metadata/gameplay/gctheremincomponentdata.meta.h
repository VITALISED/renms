#pragma once
#include <metadata/metadata_common.h>

class cGcThereminComponentData
{
    static unsigned long long muNameHash = 0xD0E5A023C215AB4A;
    static unsigned long long muTemplateHash = 0x9E9E8E9F0A88323;

    cTkFixedString<32,char> macVolumeBBName;
    float mfVolumeMinDist;
    float mfVolumeMaxDist;
    float mfMinVolume;
    float mfMaxVolume;
    cTkFixedString<32,char> macPitchStartLocator;
    cTkFixedString<32,char> macPitchEndLocator;
    float mfPitchMinDist;
    float mfPitchMaxDist;
    float mfMinPitch;
    float mfMaxPitch;
    float mfIgnorePlayerDistance;
}
