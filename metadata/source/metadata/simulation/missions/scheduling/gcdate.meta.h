#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/scheduling/gcmonth.meta.h>

class cGcDate
{
    static unsigned long long muNameHash = 0x806D452BB139AB67;
    static unsigned long long muTemplateHash = 0xADA440911976CE1D;

    int miMinute;
    int miHour;
    int miDay;
    cGcMonth Month;
    int miYear;
}
