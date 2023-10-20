#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcbaseplacementrule.meta.h>

class cGcBasePlacementComponentData
{
    static unsigned long long muNameHash = 0xBA4C53DBACF34B41;
    static unsigned long long muTemplateHash = 0xD68A203BCCFB141F;

    cTkDynamicArray<cGcBasePlacementRule> maRules;
}
