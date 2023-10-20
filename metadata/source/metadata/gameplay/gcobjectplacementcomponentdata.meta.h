#pragma once
#include <metadata/metadata_common.h>
enum eActivationType
{
    EActivationType_GroupNode = 0,
    EActivationType_Locator = 1,
}

class cGcObjectPlacementComponentData
{
    static unsigned long long muNameHash = 0x6520972F5B89CD77;
    static unsigned long long muTemplateHash = 0x44119D1A01247A34;

    cTkFixedString<32,char> macGroupNodeName;
    eActivationType ActivationType;
    float mfFractionOfNodesActive;
    int miMaxNodesActivated;
    int miMaxGroupsActivated;
    bool mbUseRaycast;
    bool mbUseNodeParent;
}
