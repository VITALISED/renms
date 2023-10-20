#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcmultispecificitementry.meta.h>

class cGcRewardMultiSpecificItems
{
    static unsigned long long muNameHash = 0x26C3924987148B0B;
    static unsigned long long muTemplateHash = 0x9EB41FB07B0B9AE3;

    bool mbSilent;
    cTkDynamicArray<cGcMultiSpecificItemEntry> maItems;
}
