#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcbaselinkgridconnectiondata.meta.h>
enum eDependentEffect
{
    EDependentEffect_None = 0,
    EDependentEffect_EnablesRate = 1,
    EDependentEffect_DisablesRate = 2,
    EDependentEffect_EnablesConnection = 3,
    EDependentEffect_DisablesConnection = 4,
}

class cGcBaseLinkGridConnectionDependency
{
    static unsigned long long muNameHash = 0xB9BE8F8A6900C12E;
    static unsigned long long muTemplateHash = 0x3527C363F9E61B1F;

    cGcBaseLinkGridConnectionData Connection;
    int miDependentRate;
    eDependentEffect DependentEffect;
    bool mbDisableWhenOffline;
    bool mbTransfersConnections;
}
