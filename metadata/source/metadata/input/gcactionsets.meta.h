#pragma once
#include <metadata/metadata_common.h>
#include <metadata/input/gcactionset.meta.h>

class cGcActionSets
{
    static unsigned long long muNameHash = 0x7D347F979E52A1C1;
    static unsigned long long muTemplateHash = 0xDCDDFCAC4A838CF7;

    cTkDynamicArray<cGcActionSet> maActionSets;
}
