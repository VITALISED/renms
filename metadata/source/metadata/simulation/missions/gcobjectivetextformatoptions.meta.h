#pragma once
#include <metadata/metadata_common.h>

class cGcObjectiveTextFormatOptions
{
    static unsigned long long muNameHash = 0x2B3787F904F75390;
    static unsigned long long muTemplateHash = 0x49DC6D819EDE244D;

    bool mbObjectivesCanBeFormattedBySequences;
    TkID<256> mFormattableObjective;
    TkID<256> mFormattableObjectiveTip;
}
