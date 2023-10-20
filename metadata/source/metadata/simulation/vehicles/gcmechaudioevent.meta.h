#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcMechAudioEvent
{
    static unsigned long long muNameHash = 0x58C0C35FA839BA96;
    static unsigned long long muTemplateHash = 0xA9ECBC396833D80B;

    cGcAudioWwiseEvents DefaultEvent;
    cTkDynamicArray<cGcMechPartAudioEventOverride> maMeshPartOverrides;
}
