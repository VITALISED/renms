#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcbasebuildingentrycosts.meta.h>

class cGcBaseBuildingCostsTable
{
    static unsigned long long muNameHash = 0xEE25A96466342A98;
    static unsigned long long muTemplateHash = 0x9533C3CCA56FDC13;

    cTkDynamicArray<cGcBaseBuildingEntryCosts> maObjectCosts;
}
