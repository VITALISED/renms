#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/stats/gcstatdefinition.meta.h>

class cGcStatDefinitionTable
{
    static unsigned long long muNameHash = 0x2BFE1835E7B1EFEC;
    static unsigned long long muTemplateHash = 0x400CB6B30153EC0;

    cTkDynamicArray<cGcStatDefinition> maStatDefinitionTable;
}
