#pragma once
#include <metadata/metadata_common.h>
#include <metadata/audio/gcbytebeattemplate.meta.h>
#include <metadata/audio/gcbytebeatdrum.meta.h>
#include <metadata/audio/gcbytebeatsong.meta.h>

class cGcByteBeatTemplates
{
    static unsigned long long muNameHash = 0xBBB68492659143C4;
    static unsigned long long muTemplateHash = 0x34F44B119AE0F661;

    cTkDynamicArray<cTkFixedString<64,char>> maInitialTrees;
    cTkDynamicArray<cGcByteBeatTemplate> maTemplates;
    cTkFixedArray<float> maCombinerWeights;
    cTkDynamicArray<cGcByteBeatDrum> maKickDrums;
    cTkDynamicArray<cGcByteBeatDrum> maSnareDrums;
    cTkDynamicArray<cGcByteBeatDrum> maHiHats;
    float mfOperatorPermuteChance;
    float mfTemplateCombineChanceAtRoot;
    float mfTemplateCombineChance;
    cTkDynamicArray<cGcByteBeatSong> maSongs;
}
