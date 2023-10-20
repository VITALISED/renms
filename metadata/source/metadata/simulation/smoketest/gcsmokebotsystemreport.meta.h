#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcSmokeBotSystemReport
{
    static unsigned long long muNameHash = 0xFB50309B36475BDE;
    static unsigned long long muTemplateHash = 0x96998FEC48744CE6;

    unsigned long long mui64UA;
    cGcSmokeBotStats SystemStats;
    cGcSmokeBotStats SpaceStats;
    cTkDynamicArray<cGcSmokeBotPlanetReport> maPlanetReports;
}
