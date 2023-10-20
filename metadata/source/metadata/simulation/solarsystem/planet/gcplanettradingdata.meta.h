#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/planet/gcwealthclass.meta.h>
#include <metadata/simulation/solarsystem/planet/gctradingclass.meta.h>

class cGcPlanetTradingData
{
    static unsigned long long muNameHash = 0x645C709EAB3A1F55;
    static unsigned long long muTemplateHash = 0x25595393127E4C91;

    cGcWealthClass WealthClass;
    cGcTradingClass TradingClass;
}
