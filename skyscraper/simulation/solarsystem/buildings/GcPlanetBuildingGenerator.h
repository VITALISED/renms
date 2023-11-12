#pragma once

#include <skyscraper.h>

#include <simulation/environment/gcbuildingdefinitiontable.meta.h>
#include <simulation/environment/wfcbuildings/gcsettlementcolourtable.meta.h>

SKYSCRAPER_BEGIN

class cGcPlanetBuildingGenerator
{
    cGcBuildingDefinitionTable *mpBuildingTable;
    cGcSettlementColourTable *mpSettlementColourTable;
    bool mabUsedInCluster[52];
};

SKYSCRAPER_END