#pragma once
#include <metadata/metadata_common.h>

class cGcBoidData
{
    static unsigned long long muNameHash = 0xC455782DFAD32032;
    static unsigned long long muTemplateHash = 0x7F779F4D2F6BD0FD;

    float mfCoherence;
    float mfAlignment;
    float mfSeparation;
    float mfSpacing;
    float mfFollow;
    float mfDirectionBrake;
    float mfMaxSpeed;
    float mfInitTime;
    float mfInitOffset;
    float mfInitFacingOffset;
    float mfLeadTime;
}
