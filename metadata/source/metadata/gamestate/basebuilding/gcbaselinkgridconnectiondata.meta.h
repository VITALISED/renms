#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gclinknetworktypes.meta.h>

class cGcBaseLinkGridConnectionData
{
    static unsigned long long muNameHash = 0xD8133C6FC444E667;
    static unsigned long long muTemplateHash = 0xB473568C6A036D67;

    cGcLinkNetworkTypes Network;
    int miNetworkSubGroup;
    int miNetworkMask;
    float mfConnectionDistance;
    bool mbUseMinDistance;
    cTkDynamicArray<cTkVector3> maLinkSocketPositions;
    cTkDynamicArray<int> maLinkSocketSubGroups;
}
