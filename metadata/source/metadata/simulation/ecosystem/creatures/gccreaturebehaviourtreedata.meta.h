#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureBehaviourTreeData
{
    static unsigned long long muNameHash = 0xC0220D51AA0E426;
    static unsigned long long muTemplateHash = 0x65FDAF58354B649A;

    TkID<128> mId;
    cTkDynamicArray<cTkClassPointer> maNodes;
}
