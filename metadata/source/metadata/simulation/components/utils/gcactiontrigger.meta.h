#pragma once
#include <metadata/metadata_common.h>

class cGcActionTrigger
{
    static unsigned long long muNameHash = 0x269AA19701CADAB8;
    static unsigned long long muTemplateHash = 0x5329ACC91E367434;

    cTkClassPointer mEvent;
    cTkDynamicArray<cTkClassPointer> maAction;
}
